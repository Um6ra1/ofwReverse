#include <pspkernel.h>
#include <pspuser.h>
#include <pspsdk.h>
#include <pspthreadman.h>
#include <pspmodulemgr.h>
#include <psptypes.h>
#include <pspusbbus.h>
#include "Api.h"

PSP_MODULE_INFO("sceUSB_Acc_Driver", 0x0103, 1, 2);

int RecvCtrl(int arg1, int arg2, struct DeviceRequest *lpDevReq);
int Attach(int speed, void *arg2, void *arg3);
int Detach(int arg1, int arg2, int arg3);
int DriverStart(int size, void *args);
int DriverStop(int size, void *args);
void UsbDevReqComplete(struct UsbdDeviceReq *lpReq);

struct StringDescriptor	strDesc =
{
	0x1C, 0x03,
	{ 'U', 'S', 'B', ' ', 'A', 'c', 'c', 'e', 's', 's', 'o', 'r', 'y', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// UsbData.exdp[2~3] is not used?
struct UsbData *sub_00000670(int speed, struct DeviceDescriptor *lpDevDesc, struct Config *lpUsbConf, struct ConfDesc *lpConfDesc);

struct UsbEndpoint	g_usbEndps[2];	// 0x00000 + 128	

struct UsbEndpoint	g_endp;	// 0x00000 + 140
struct UsbInterface	g_itrfc[2];	// 0x00000 + 152
struct UsbDriver g_driver =	// 0x00000 + 164
{
	"USBAccBaseDriver",
	2,
	g_usbEndps,	// 128
	g_itrfc,	// 152
	NULL,
	NULL,	// confp_hi
	NULL,
	NULL,	// confp
	&strDesc,	// strp
	RecvCtrl,	//0x01DC
	NULL,
	Attach,	//0x060C
	Detach,	//0x062C
	0,
	DriverStart,	//0x0340
	DriverStop,	//0x057C
	NULL
};

u64	g_info;	// 0x00000 + 240 + 0
struct DeviceRequest g_devReq;	// 0x00000 + 248 = 0x00000 + 240 + 8
struct UsbdDeviceReq	g_usbDevReq;	// 0x00000 + 256 = 0x00000 + 240 + 16
u8	*g_lpData;	// 0x00000 + 240 + 56
int g_hFPL;	// 0x00000 + 240 + 60
u16	g_type;	// 0x00000 + 240 + 64
s8	g_bStarted;	// 0x00000 + 240 + 66
u8	g_bAttached;	// 0x00000 + 240 + 67

#define SPEED_FULL	1
#define SPEED_HIGH	2

// OK
int sceUsbAccGetAuthStat() // at 0x00000000 
{
	int curIntCtrlState = sceKernelCpuSuspendIntr();
	int ret = 0x80243007;
	if (g_bAttached)
	{
		ret = sceUsbBus_driver_8A3EB5D2() ? 0 : 0x80243701;
	}

	sceKernelCpuResumeIntr(curIntCtrlState);
	return (ret);
}

//OK
int sceUsbAccGetInfo(u64 *lpDst) // at 0x00000068 
{
	int ret = 0;
	int curIntCtrlState = sceKernelCpuSuspendIntr();
	if (!g_bAttached)
	{
		sceKernelCpuResumeIntr(curIntCtrlState);
		return (0x80243007);
	}
	if (sceUsbBus_driver_8A3EB5D2() == 0)
	{
		sceKernelCpuResumeIntr(curIntCtrlState);
		return (0x80243701);
	}

	if (lpDst)
	{
		if (((((u32)lpDst + 8) | (u32)lpDst) & (pspSdkGetK1() << 11)) >= 0)
		{
			*lpDst = g_info;
		}
	}
	else
	{
		ret = 0x80243002;
	}

	sceKernelCpuResumeIntr(curIntCtrlState);
	return (ret);
}

// OK
int sceUsbAcc_internal_2A100C1F(struct UsbdDeviceReq *lpReq) // at 0x00000154 
{
	u8 *lpData = lpReq->data;

	if (!g_bAttached)
	{
		return (0x80243007);
	}
	if ((lpData[3] < 61) == 0)
	{
		return (0x80243002);
	}
	sceKernelDcacheWritebackRange(lpData, lpReq->size);
	lpReq->endp = &g_endp;
	lpReq->size= lpData[3] + 4;
	return (sceUsbbdReqSend(lpReq));
}

// OK
int RecvCtrl(int arg1, int arg2, struct DeviceRequest *lpDevReq)	// 0x1DC
{
	/*s0 = a2;
	s1 = &g_usbDevReq;
	asm("lwl        $v0, 3($s0)");
	asm("lwr        $v0, 0($s0)");
	asm("lwl        $v1, 7($s0)");
	asm("lwr        $v1, 4($s0)");

	asm("swl        $v0, -5($s1)");
	asm("swr        $v0, -8($s1)");
	asm("swl        $v1, -1($s1)");
	asm("swr        $v1, -4($s1)");*/
	g_devReq = *lpDevReq;

	if (arg2 < 0)
	{
		return (-1);
	}

	static struct DeviceRequest devReq[] = // 0x00000 + 3084, 0x0C0C
	{
		{ 0xC1, 0x01, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0x01, 0x0000, 0x0000, 0x0000 },
	};

	int i;
	for (i = 0; i < 2; i++)
	{
		if (lpDevReq->bmRequestType == devReq[i].bmRequestType)
		{
			if (lpDevReq->bRequest == devReq[i].bRequest)
			{
				break;
			}
		}
	}
	if (i == 2)
	{
		return (-1);
	}
	if (lpDevReq->bmRequestType < 0)
	{
		if (lpDevReq->bRequest != 1)
		{
			return (-1);
		}
		if (sceUsbBus_driver_48CCE3C1())
		{
			if (g_type == (g_type & lpDevReq->wValue))
			{
				*(s8*)(g_usbDevReq.data +0) = 0;
				sceUsbBus_driver_FBA2072B();
			}
		}
		else
		{
			*(s8*)(g_usbDevReq.data + 0) = lpDevReq->bRequest;
		}
		g_usbDevReq.size	= 1;
		sceKernelDcacheWritebackRange(g_usbDevReq.data, 1);
		sceUsbbdReqSend(&g_usbDevReq);
		return (0);
	}
	if (lpDevReq->bRequest != 1)
	{
		return (-1);
	}
	sceKernelDcacheInvalidateRange(g_usbDevReq.data, 64);
	g_usbDevReq.size = 64;
	sceUsbbdReqRecv(&g_usbDevReq);
	return (0);
}

// OK
int DriverStart(int size, void *args)
{
	void	*lpData;
	SceUID hFPL = sceKernelCreateFpl("SceUsbAcc", 1, 256, 368, 1, NULL);	// 368 = 2*184=2*sizeof(UsbData)
	g_hFPL = hFPL;
	if (hFPL< 0)
	{
		return (-1);
	}
	if (sceKernelTryAllocateFpl(hFPL, &lpData) < 0)
	{
		sceKernelDeleteFpl(g_hFPL);
		return (-1);
	}

	g_lpData = lpData;
	
	struct UsbData	*lpUsbData = (struct UsbData	*)((int)lpData + 64);
	
	g_driver.devp_hi = lpUsbData->devdesc;	// UsbData[0]
	g_driver.confp_hi = &lpUsbData->config;
	lpData = &lpUsbData->confdesc;
	lpUsbData = sub_00000670(SPEED_HIGH, lpUsbData->devdesc, &lpUsbData->config, &lpUsbData->confdesc);
	
	g_driver.devp = lpUsbData->devdesc;	// UsbData[1]
	g_driver.confp = &lpUsbData->config;
	lpData = &lpUsbData->confdesc;
	lpData = sub_00000670(SPEED_FULL, lpUsbData->devdesc, &lpUsbData->config, &lpUsbData->confdesc);

	g_info = 0;
	g_bAttached = 0;

	int i;
	for (i = 0; i < 2; i++)
	{
		g_usbEndps[i].unk3 = 0;
	}

	g_usbDevReq.endp = g_usbEndps;
	g_usbDevReq.data = g_lpData;
	g_usbDevReq.size = 64;
	g_usbDevReq.unkc	= 1;
	g_usbDevReq.func = UsbDevReqComplete;
	g_usbDevReq.recvsize = 0;
	g_usbDevReq.retcode = 0;
	g_usbDevReq.unk1c = 0;
	g_usbDevReq.arg = 0;
	sceUsbBus_driver_90B82F55();
	g_bStarted = 1;
	return (0);
}

int sceUsbAccRegisterType(int a0) // at 0x000004AC 
{
	int v0 = 0x80243001;

	if ((g_type & a0) == 0)
	{
		g_type = g_type | a0;
		v0 = 0;
	}
	return (v0);
}

int sceUsbAccUnregisterType(int a0) // at 0x000004E0 
{
	int v0 = 0x80243005;

	if (g_type & a0)
	{
		g_type = g_type & ~(0 | a0);
		v0 = 0;
	}
	return (v0);
}

int module_start(int argc, void *lpArg)
{
	if (sceUsbbdRegister(&g_driver) >= 0)
	{
		g_type = 0;
		g_bStarted = 0;
		return (0);
	}
	return (1);
}

int module_stop() // at 0x00000558 
{
	return (sceUsbbdUnregister(&g_driver) < 0);
}

int DriverStop(int size, void *args)	// 0x57C
{
	sceUsbBus_driver_7B87815D();
	sceKernelDeleteFpl(g_hFPL);
	g_bStarted = 0;
	return (0);
}

void UsbDevReqComplete(struct UsbdDeviceReq *lpReq)	// 0x5B4
{
	if ((lpReq->retcode == 0) && (g_devReq.bmRequestType >= 0))
	{
		if (g_devReq.bRequest == 1)
		{
			g_info = *(u64*)(lpReq->data);
		}
	}
}

// OK
int Attach(int speed, void *arg2, void *arg3)	// 0x60C
{
	int bAttached = g_bAttached;
	if (!bAttached)
	{
		g_bAttached = 1;
	}
	return (bAttached);
}

int Detach(int arg1, int arg2, int arg3)	// 0x62C
{
	if (g_bAttached)
	{
		g_bAttached = 0;
		g_info = 0;

		int i;
		for (i = 0; i < 2; i++)
		{
			g_usbEndps[i].unk3 = 0;
		}
	}
	return (0);
}

// OK?
struct UsbData *sub_00000670(int speed, struct DeviceDescriptor *lpDevDesc, struct Config *lpUsbConf, struct ConfDesc *lpConfDesc) // at 0x00000670 
{
	lpUsbConf->pconfdesc = lpConfDesc;	// UsbData::ConfDesc
	lpUsbConf->pinterfaces = (u8*)lpConfDesc + 24;	// UsbData::Interfaces
	lpUsbConf->pinterdesc = (u8*)lpConfDesc + 24 + 12;	// UsbData::InterDesc
	lpUsbConf->pendp = (u8*)lpConfDesc + 24 + 12 + 48;	// UsbData::Endp

	//u32 devDesc[] =	// 0x00000 + 2948;	0xB84
	//{ 0x02000112, 0x00000000, 0x00000000, 0x00000100, 0x00000100 };
	static struct DeviceDescriptor devDesc =	// 0x00000 + 2948;	0xB84
	{
		0x12, 0x01, 0x0200,
		0x00, 0x00, 0x00, 0x00,
		0x0000, 0x0000,
		0x0100, 0x00, 0x00,
		0x00, 0x01
	};
	*((struct DeviceDescriptor *)lpDevDesc) = devDesc;

	/*a1 = 0x00000 + 2968;
	int dw_B98[] =
	{
		0x00190209, 0xC0000101, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	};*/
	static struct ConfDesc	confDesc=	// 0x00000 + 2968;	0x98
	//{	{ 0x00190209, 0xC0000101, 0x00000000 }, 0x00000000	};
	{
		{
			0x09, 0x02, 0x19, 0x00,
			0x01, 0x01, 0x00, 0xC0,
			0x00, 0x00, 0x00, 0x00
		},
		0x00000000
	};
	//*(s32*)(a3 + 16) = *(s32*)(a1 + 16);	// UsbData.pad1[0]=0;
	//*(s32*)(a3 + 20) = *(s32*)(a1 + 20);	// UsbData.pad1[1]=0;
	//*(s32*)(a3 + 12) = lpUsbConf->pinterfaces;
	*lpConfDesc = confDesc;
	lpConfDesc->pinterfaces = lpUsbConf->pinterfaces;

	struct UsbInterfaces *lpItrfcs = lpUsbConf->pinterfaces;

	static struct UsbInterfaces usbItrfc =	// 0x00000 + 2992,	0xBB0
	{
		{ 0x00000000, 0x00000000 }, 0x00000001,
	};
	*lpItrfcs = usbItrfc;

	static struct InterDesc itrfcDesc =	// 0x00000 + 3004, 0x0BBC
	{
		//0x00000409, 0x0000FF01, 0x00000001,
		{
			0x09, 0x04, 0x00, 0x00,
			0x01, 0xFF, 0x00, 0x00,
			0x01, 0x00, 0x00, 0x00
		},
		0x00000000,
		{0}
	};

	struct InterDesc *lpItrfcDesc = lpUsbConf->pinterdesc;
	*lpItrfcDesc = itrfcDesc;

	static struct EndpointDescriptor	endpDescs[] =	// 0x00000 + 3052;
	{
		{ 0x07, 0x05, 0x81, 0x03, 0x0000, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x0000, 0x00 },
	};
	struct EndpointDescriptor	*t6 = (struct EndpointDescriptor *)((u8*)lpConfDesc + 24 + 12 + 48);
	t6[0] = endpDescs[0];
	t6[1] = endpDescs[1];
	t6[2] = endpDescs[2];
	t6[3] = endpDescs[3];

	lpItrfcs->infp[0] = lpUsbConf->pinterfaces;
	lpItrfcDesc->pendp = t6;
	lpDevDesc->bMaxPacketSize = 64;//lpUsbData->devdesc[7] = 64;
	t6[0].wMaxPacketSize = 64;
	t6[0].bInterval = (speed != SPEED_HIGH) ? 8 : 7;
	return((struct UsbData *)((u8*)lpConfDesc + 24 + 12 + 48 + 32));	// &UsbData.endp[2]
}
