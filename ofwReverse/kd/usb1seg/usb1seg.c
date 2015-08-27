
/*
IMPORT_FUNC "ThreadManForUser",0x6B30100F,sceKernelUnlockMutex
IMPORT_FUNC "ThreadManForUser",0xB011B11F,sceKernelLockMutex
IMPORT_FUNC "SysclibForKernel",0x10F3BB61,memset
IMPORT_FUNC "SysclibForKernel",0xAB7592FF,memcpy
PSP_EXPORT_FUNC_NID(sceClockgenSetSpectrumSpreading, 0xC9AF3102)
*/
#include <pspkernel.h>
#include <pspuser.h>
#include <pspsdk.h>
#include <pspthreadman.h>
#include <pspmodulemgr.h>
#include <pspusbbus.h>
#include <string.h>
#include "sceUsb1Seg.h"

SCE_MODULE_INFO
(
	"sceUSB1Seg_Driver",
	0x1006,	// SCE_MODULE_KERNEL | SCE_MODULE_ATTR_EXCLUSIVE_LOAD | SCE_MODULE_ATTR_EXCLUSIVE_START
	1, 2
);

typedef struct _ONESEG_PARAM
{
	u8	size;
	u8	unk1;
	u8	unk2;
	u8	unk3;
	u32	unk4;
	u8	unk8;
	u8	unk9;
	u8	unk10;
	u8	unk11;
	u32	unk12;
	u8	unk16;
} ONESEG_PARAM __attribute__((packed));	// 17 bytes

typedef struct _PACKET_BUF
{
	_PACKET_BUF	*lpNext;
	u32	unk4;
	s64	qwSysTime;
	u8	buf[192];
} PACKET_BUF __attribute__((packed));	// 208 bytes

/*================================*/
int sub_00001A74();	// OK?
int sub_00001AF8();	// OK?
int sub_00001B7C(u8 chNum);	// OK
sub_00001C80_ScanCh(s8 *a0);	// OK?
int sub_00001DD0_GetModule(u8 *a0);	// OK
int sub_00001E94(ONESEG_PARAM *lpParam);	// OK
int sub_00001FF0(u8 *a0);	// OK?
int sub_000020B4_GetDebug(int *lpDst, int size);	// OK?
int sub_00002184_SetDebug(int *lpSrc, int size);
int sub_000022A4_SetPwm(u8 *a0);
int sub_000023A8_GetReg(s8 a0, u8 *a1, u8 *a2, int a3, int t0);	// OK
int sub_00002518_SetReg(int a0, int *lpSrc, int size);
int sub_0000263C_EEPROMUpdate(s16 a0, int a1, int a2, u8 *a3);
int sub_0000276C_EEPROMParamWrite();
int sub_00002838(u8 *a0, int a1);
int sub_00002934(s8 a0, s8 a1, s8 a2);
int sub_00002A58(u16 a0, u8 *lpDst, u8 size);
int sub_00002BB8(u16 a0, u8 *a1, int a2);
int sub_00002CEC_GetErrorCode(u16 *lpUnk);	// OK

void BulkinReqDone(UsbdDeviceReq *lpDevReq);
int BulkoutReqDone(UsbdDeviceReq *lpDevReq);	// OK
int AsyncReqDone(UsbdDeviceReq *lpDevReq);

int *sub_00003400(int a0, int *a1, int *a2, int *a3);
int sub_00003664_GetData(int *lpDst, int size);	// OK
int sub_00003708();
int sub_000037D4_SetAntenna(int ch);
int sub_000038D8_SetBPER(int ch);
int sub_00003AB8();	// OK
int sub_00003B70();	// OK?
sub_00003C38();
int sub_00003F74();
int sub_000042EC();
/*================================*/

// a function comes from a syscall, $k1 = 0x100000 by interruptmgr
// 0+224+228 : threadEntry

struct UsbEndpoint	g_bulkinEndpoint;	// 0x00000 + 128 + 0
struct UsbEndpoint	g_usbEndpoint;	// 0x00000 + 128 + 12

//UsbDriver g_driver	// 0x00000 + 164	// 68bytes

int	g_bStarted;	// 0x00000 + 244 + 0
int	g_bAttached;	// 0x00000 + 244 + 4
int	g_alternateSetting;	// 0x00000 + 244 + 8
int	g_onesegState;	// 0x00000 + 244 + 12
int	g_errorCode16;	// 0x00000 + 244 + 16
s8	g_chNum;	// 0x00000 + 244 + 20
ONESEG_PARAM	g_onesegParam;	// 0x00000 + 244 + 21

struct UsbdDeviceReq	g_deviceReq;	// 0x00000 + 244 + 40
u8	*g_lpData;	// 0x00000 + 244 + 80
u8	*g_cmdResult;	// 0x00000 + 244 + 85
/* Static bulkin request structure */
struct UsbdDeviceReq	g_bulkinReq2;	// 0x00000 + 244 + 88
struct UsbdDeviceReq	g_bulkinReq;	// 0x00000 + 244 + 92,	0x00000 + 336
/* Static bulkout request structure */
//static UsbdDeviceReq g_bulkoutReq;	// 0x00000 + 244 + 132
u8	*g_lpBulkinData;	// 0x00000 + 244 + 132
struct UsbdDeviceReq	g_usbReq;	// 0x00000 + 244 + 136
/* Async request */
//static UsbdDeviceReq g_asyncReq;	// 0x00000 + 244 + 172
u8	*g_lpUsbData;	// 0x00000 + 244 + 176
int g_index180;	// 0x00000 + 244 + 180
int	g_index;	// 0x00000 + 244 + 184
struct PACKET_BUF	*g_lpPcktBufs[2];	// 0x00000 + 244 + 188

int g_cb1Arg2;	// 0x00000 + 244 + 196
int	g_num200;	// 0x00000 + 244 + 200
int	g_num204;	// 0x00000 + 244 + 204	// packet_num?

struct PACKET_BUF	*g_lpPcktBuf1;	// 0x00000 + 244 + 208
struct PACKET_BUF	*g_lpPcktBuf2;	// 0x00000 + 244 + 212
struct PACKET_BUF	*g_lpBuf;	// 0x00000 + 244 + 216
struct PACKET_BUF	*g_lpBufTmp;	// 0x00000 + 244 + 220

int	g_threadID;	// 0x00000 + 244 + 228
int	g_eventFlag;	// 0x00000 + 244 + 232
int g_poolUID;	// 0x00000 + 244 + 236
int	g_mutexID;	// 0x00000 + 244 + 240

SceUID	g_cbUID1;	// 0x00000 + 244 + 244
SceUID	g_cbUID2;	// 0x00000 + 244 + 248

#define ERR_1	0x80244501
#define ERR_2	0x80244502	// Not started
#define ERR_3	0x80244503	// Not attached
#define ERR_4	0x80244504
#define ERR_5	0x80244505
#define ERR_6	0x80244506
#define ERR_7	0x80244507
#define ERR_8	0x80244508
#define ERR_9	0x80244509
#define ERR_C	0x8024450C
#define ERR_D	0x8024450D

#define K1PtrOk(p)	(( (int)(p) & pspSdkGetK1() ) >= 0)
#define K1StaBufOk(p, size)		( (( ((int)(p) + size) | (int)(p) ) & pspSdkGetK1() ) >= 0)
#define K1DynBufOk(p, size)	( (( ((int)(p) + size) | (int)(p) | size ) & pspSdkGetK1() ) >= 0)

// values
int sceUsb1SegConstruct(s8 chNum, ONESEG_PARAM *lpParam, SceUID *uid1, SceUID uid2) // at 0x00000000 - Aliases: sceUsb1Seg_driver_4B8C03AA
{
	if (!g_bStarted)
	{
		g_cbUID1 = 0;
		g_cbUID2 = 0;
		return (0x80244502);
	}
	if (!g_bAttached)
	{
		g_cbUID1 = 0;
		g_cbUID2 = 0;
		return (0x80244503);
	}
	if ((chNum - 13) < 50 == 0)
	{
		g_cbUID1 = 0;
		g_cbUID2 = 0;
		return (0x80244505);
	}

	int ret;
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((s32)(((a1 + 17) | a1) & (k1 << 11)) < 0)	// If user mode
	if (!K1StaBufOk(lpParam, 17))
	{
		g_cbUID1 = 0;
		g_cbUID2 = 0;
		pspSdkSetK1(k1);
		return (0x80244507);
	}
	if ((lpParam.size < 64) == 0)
	{
		g_cbUID1 = 0;
		g_cbUID2 = 0;
		pspSdkSetK1(k1);
		return (0x80244505);
	}
	if ((s32)uid1 <= 0 || sceKernelGetThreadmanIdType(uid1) == 8)
	{
		if (uid2 > 0)
		{
			if (sceKernelGetThreadmanIdType(uid2) != 8)
			{
				g_cbUID1 = 0;
				g_cbUID2 = 0;
				pspSdkSetK1(k1);
				return (0x80244504);
			}
		}
		int curIntrState = sceKernelCpuSuspendIntr();
		g_chNum = chNum;
		g_cbUID1 = uid1;
		g_cbUID2 = uid2;

		g_onesegParam = *lpParam;

		g_cb1Arg2 = 0;
		g_num200 = 0;
		g_num204 = 0;
		g_lpPcktBuf1 = 0;
		g_lpPcktBuf2 = 0;
		g_lpBuf = 0;
		g_lpBufTmp = 0;
		*(s32*)(0x00000 + 244 + 224) = 0;
		sceKernelCpuResumeIntr(curIntrState);
		g_onesegState = 1;
		g_errorCode16 = 0;

		int bits;
		sceKernelClearEventFlag(g_eventFlag, -28961);
		sceKernelSetEventFlag(g_eventFlag, 16);
		ret = sceKernelWaitEventFlag(g_eventFlag, 261, 1, &bits, 0);
		if (ret >= 0)
		{
			pspSdkSetK1(k1);
			return ((bits & 0x1) ? 0x80244503 : ((bits & 0x4) ? 0x80244509 : g_errorCode16));
		}
	}
	else
	{
		ret = 0x80244504;
	}
	g_cbUID1 = 0;
	g_cbUID2 = 0;
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegDestruct() // at 0x00000218 - Aliases: sceUsb1Seg_driver_C7AA1922
{
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int ret = 0x80244506;
	if (g_onesegState == 2)
	{
		int bits;
		int curIntrState = sceKernelCpuSuspendIntr();

		g_onesegState = 3;
		sceKernelSetEventFlag(g_eventFlag, 16386, 3);
		sceKernelCpuResumeIntr(curIntrState);
		ret = sceKernelWaitEventFlag(g_eventFlag, 513, 1, &bits, 0);
		if (!ret)
		{
			if ((bits & 0x1) == 0)
			{
				sceKernelClearEventFlag(g_eventFlag, -513);
			}
			else
			{
				ret = 0x80244503;
			}
		}
	}
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegPutPacketBuffer(PACKET_BUF *lpPcktBuf) // at 0x000002E4 - Aliases: sceUsb1Seg_driver_56B86184
{
	if (!g_bStarted)
	{
		return(0x80244502);
	}
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	if (lpPcktBuf == 0)
	{
		return(0x80244507);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int curIntrState = sceKernelCpuSuspendIntr();
	PACKET_BUF *v1 = lpPcktBuf;
	PACKET_BUF *s1 = NULL;
	do
	{
		//if ((((v1 + 208) | v1) & (k1<<11))< 0)
		if (!K1StaBufOk(v1, 208))
		{
			if (v1 == 0)
			{
				break;
			}
			sceKernelCpuResumeIntr(curIntrState);
			pspSdkSetK1(k1);
			return(0x80244507);
		}
		PACKET_BUF *t0 = v1->lpNext;
		if (t0 == 0)
		{
			s1 = v1;
		}
		v1 = t0;
	} while (t0);
	if (g_lpPcktBuf1)
	{
		g_lpPcktBuf2->lpNext= lpPcktBuf;
		v1 = lpPcktBuf;
		if (lpPcktBuf->lpNext)
		{
			PACKET_BUF *a1 = lpPcktBuf->lpNext;
			do
			{
				v1 = a1;
			} while (a1 = a1->lpNext);
		}
		g_lpPcktBuf2 = v1;
	}
	else
	{
		g_lpPcktBuf2 = s1;
		g_lpPcktBuf1 = lpPcktBuf;
	}
	sceKernelCpuResumeIntr(curIntrState);
	pspSdkSetK1(k1);
	return (0);
}

// 216, 220, 196
int sceUsb1SegGetPacketBuffer(PACKET_BUF *lplpBuf[]) // at 0x00000414 - Aliases: sceUsb1Seg_driver_669FC183
{
	if (!g_bStarted)
	{
		return(0x80244502);
	}
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if (((k1 << 11) & a0) < 0)
	if (!K1PtrOk(lplpBuf))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	curIntrState = sceKernelCpuSuspendIntr();
	if (v0 = g_lpBuf)
	{
		*lplpBuf = v0;
		g_lpBufTmp = 0;
		g_lpBuf = 0;
	}
	else
	{
		*lplpBuf = 0;
	}
	int ret = g_cb1Arg2;
	g_cb1Arg2 = 0;
	sceKernelClearEventFlag(g_eventFlag, -9);
	sceKernelCpuResumeIntr(curIntrState);

	pspSdkSetK1(k1);
	return (ret);
}

// 196, 216, 12
int sceUsb1SegGetPacketBufferBlocking(PACKET_BUF *lplpBuf[]) // at 0x000004F4 - Aliases: sceUsb1Seg_driver_F565757F
{
	if (!g_bStarted)
	{
		return (0x80244502);
	}
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	if (((g_onesegState - 1) < 2) == 0)
	{
		return (0x80244506);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if (((k1 << 11) & a0) < 0)
	if (!K1PtrOk(lplpBuf))
	{
		pspSdkSetK1(k1);
		return (0x80244507);
	}

	int bits;

	sceKernelClearEventFlag(g_eventFlag, -8193);
	int ret = sceKernelWaitEventFlag(g_eventFlag, 8233, 1, &bits, 0);
	if (ret < 0)
	{
		pspSdkSetK1(k1);
		return (ret);
	}
	if (bits & 0x1)
	{
		pspSdkSetK1(k1);
		return (0x80244503);
	}
	if (bits & 0x8024450C)
	{
		pspSdkSetK1(k1);
		return (0x8024450C);
	}
	if (bits & 0x20)
	{
		pspSdkSetK1(k1);
		return (0x80244506);
	}
	int curIntrState = sceKernelCpuSuspendIntr();

	if (g_lpBuf != 0)
	{
		*lplpBuf = g_lpBuf;
		g_lpBufTmp = 0;
		g_lpBuf = 0;
	}
	else
	{
		*lplpBuf = 0;
	}

	ret = g_cb1Arg2;
	g_cb1Arg2 = 0;
	sceKernelClearEventFlag(g_eventFlag, -9);
	sceKernelCpuResumeIntr(curIntrState);

	pspSdkSetK1(k1);
	return (ret);
}

// OK ?
//405:sceUsb1Seg_8BEBA10E
sceUsb1Seg_FF784FF5(PACKET_BUF *lplpBuf[], int num) // at 0x00000654 - Aliases: sceUsb1Seg_driver_FF784FF5
{
	//s5 = lplpBuf;
	//s3 = num;
	if (!g_bStarted)
	{
		return (0x80244502);
	}
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	if (((g_onesegState - 1) < 2) == 0)
	{
		return (0x80244506);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((k1 & s5) < 0)
	if (!K1PtrOk(lplpBuf))
	{
		pspSdkSetK1(k1);
		return (0x80244507);
	}
	uint bits;
	int curIntrState = sceKernelCpuSuspendIntr();
	g_num200 = num;
	sceKernelCpuResumeIntr(curIntrState);
	sceKernelClearEventFlag(g_eventFlag, -8193);
	s0 = sceKernelWaitEventFlagCB(g_eventFlag, 12321, 1, &bits, 0);
	if (s0 < 0)
	{
		pspSdkSetK1(k1);
		return (s0);
	}
	if (bits & 0x1)
	{
		pspSdkSetK1(k1);
		return (0x80244503);
	}
	if (bits & 0x2000)
	{
		pspSdkSetK1(k1);
		return (0x8024450C);
	}
	if (bits & 0x20 || (bits & 0x1000) == 0 || g_onesegState != 2)
	{
		pspSdkSetK1(k1);
		return (0x80244506);
	}
	PACKET_BUF	*s7 = g_lpBuf;
	int s0 = 0;
	curIntrState = sceKernelCpuSuspendIntr();
	if (num)
	{
		do
		{
			v1 = s7->lpNext;	//*(s32*)(s7 + 0);
			if (v1 == 0){ break; }
			s7 = v1;
		} while (++s0 < num);
	}
	//s1 = 0x00000 + 244;
	s0 ++;
	*lplpBuf = g_lpBuf;
	s2 = s7->lpNext;
	g_num204 -= s0;
	g_lpBuf = s2;
	if (s2 == 0)
	{
		g_lpBufTmp = 0;
		sceKernelClearEventFlag(g_eventFlag, -9);
	}
	s7->lpNext = 0;
	sceKernelClearEventFlag(g_eventFlag, -4097);
	sceKernelCpuResumeIntr(curIntrState);
	pspSdkSetK1(k1);
	return (s0);
}

//405:sceUsb1Seg_1FA7839B
int sceUsb1Seg_10621E6B() // at 0x00000840 - Aliases: sceUsb1Seg_driver_10621E6B
{
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	
	int	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	sceKernelSetEventFlag(g_eventFlag, 8192);
	pspSdkSetK1(k1);

	return (0);
}

// vakues
//405:sceUsb1Seg_97551142
sceUsb1Seg_09F9D06D(u8 *lpArg, int num) // at 0x000008A4 - Aliases: sceUsb1Seg_driver_09F9D06D
{
	v1 = 0x00000 + 244;
	if (!g_bStarted)
	{
		return(0x80244502);
	}
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	if (!((g_onesegState - 1) < 2))
	{
		return(0x80244506);
	}
	if (*(s32*)(0x00000 + 244 + 224))
	{
		return(0x8024450D);
	}
	
	int	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if (((k1 << 11) & lpArg) < 0)
	if (!K1PtrOk(lpArg))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = 0;
	int curIntrState = sceKernelCpuSuspendIntr();
	
	if (num == 0)
	{
		if ((0 < num) == 0)
			goto loc_000009BC;
		goto loc_000009DC;
	}

	int a1 = lpArg;
	int a2 = 0;
	do
	{
		v0 = *(s32*)(a1 + 20);	// ptr
		t9 = *(s32*)(a1 + 16);	// size
		a1 += 24;
		//if ((s32)((k1 << 11) & (((v0 + t9) | v0) | t9)) < 0)
		if (!K1DynBufOk(v0, t9))
		{
			ret = 0x80244507;
			if (((u32)a2 < num) == 0)
			{
				break;
			}
			sceKernelCpuResumeIntr(curIntrState);
			pspSdkSetK1(k1);
			return (ret);
		}
	} while (++a2 < num);

loc_000009BC:
	sceKernelSetEventFlag(g_eventFlag, 16384);
	g_num200 = num;
	*(s32*)(0x00000 + 244 + 224) = lpArg;
	g_num204 = 0;

loc_000009DC:
	sceKernelCpuResumeIntr(curIntrState);
	pspSdkSetK1(k1);
	return (ret);
}

//405:sceUsb1Seg_25D5563F
int sceUsb1Seg_49FAA242() // at 0x00000A10 - Aliases: sceUsb1Seg_driver_49FAA242
{
	int ret = 0x80244502;
	int	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	
	if (g_bStarted)
	{
		ret = 0x80244503;
		if (g_bAttached)
		{
			ret = 0x80244506;
			if ((u32)(g_onesegState - 1) < 2)
			{
				int bits;

				ret = sceKernelWaitEventFlagCB(g_eventFlag, 12321, 1, &bits, 0);
				if (ret >= 0)
				{
					if (bits & 0x1)
					{
						ret = 0x80244503;
					}
					else if (bits & 0x2000)
					{
						ret = 0x8024450C;
					}
					else if (bits & 0x20)
					{
						ret = 0x80244506;
					}
					else if (bits & 0x1000)
					{
						sceKernelClearEventFlag(g_eventFlag, -4097);
						ret = g_num204;
					}
				}
			}
		}
	}
	pspSdkSetK1(k1);
	return (ret);
}

// value
//405:sceUsb1Seg_406AE298
int sceUsb1Seg_AA2BE2BD() // at 0x00000B04 - Aliases: sceUsb1Seg_driver_AA2BE2BD
{
	if (!g_bStarted)
	{
		return(0x80244502);
	}
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	if (!((g_onesegState - 1) < 2))
	{
		return(0x80244506);
	}

	int	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	sceKernelSetEventFlag(g_eventFlag, 8192);

	pspSdkSetK1(k1);
	return (0);
}

// OK
int sceUsb1SegScanCh(u8 *lpArg) // at 0x00000B98 - Aliases: sceUsb1Seg_driver_160E316E
{
	u8	sp[8];	// Interim

	if (!g_bAttached)
	{
		return(0x80244503);
	}

	int	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((((lpArg + 8) | lpArg) & (k1 << 11)) < 0)
	if (!K1StaBufOk(lpArg, 8))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_00001C80_ScanCh(sp);
	if (ret == 0)
	{
		*(s32*)(lpArg + 0) = *(s32*)(sp + 0);
		*(s32*)(lpArg + 4) = *(s32*)(sp + 4);
	}
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegGetModule(u8 *lpArg) // at 0x00000C24 - Aliases: sceUsb1Seg_driver_7E86A44C
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	
	//if ((((lpArg + 1) | lpArg) & (k1 << 11)) < 0)
	if (!K1StaBufOk(lpArg, 1))
	{
		return(0x80244507);
	}
	int ret = sub_00001DD0_GetModule(lpArg);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegSetEncKey(ONESEG_PARAM *lpParam) // at 0x00000C8C - Aliases: sceUsb1Seg_driver_F3B241E5
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	//if ((((lpParam + 17) | lpParam) & (k1 << 11)) < 0)
	if (!K1StaBufOk(lpParam, 17))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}
	int ret = sub_00001E94(lpParam);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
// Called after GetModule
//405:sceUsb1Seg_D799104F
int sceUsb1Seg_6B12C11E(u8 *lpArg) // at 0x00000CF4 - Aliases: sceUsb1Seg_driver_6B12C11E
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	//if ((s32)(((lpArg + 2) | lpArg) & (k1 << 11)) < 0)
	if (!K1StaBufOk(lpArg, 2))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}
	int ret = sub_00001FF0(lpArg);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegGetDebug(u8 *lpArg, int size) // at 0x00000D5C - Aliases: sceUsb1Seg_driver_504E176E
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((s32)((((lpArg + size) | lpArg) | size) & (k1 << 11)) < 0)
	if (!K1DynBufOk(lpArg, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_000020B4_GetDebug(lpArg, size);
	pspSdkSetK1(k1);
	return (ret);
}

// size < 61
// OK
int sceUsb1SegSetDebug(u8 *lpArg, int size)	// at 0x00000DC8 - Aliases: sceUsb1Seg_driver_7A19BF9A
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((s32)((((lpArg + size) | lpArg) | size) & (k1 << 11)) < 0)
	if (!K1DynBufOk(lpArg, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_00002184_SetDebug(lpArg, size);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegSetPwm(u8 *lpArg) // at 0x00000E34 - Aliases: sceUsb1Seg_driver_2BDB98AE
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	//if ((s32)(((lpArg + 2) | lpArg) & (k1 << 11)) < 0)
	if (!K1StaBufOk(lpArg, 2))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}
	int ret = sub_000022A4_SetPwm(lpArg);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegGetReg(u8 a0, u8 *a1, u8 *a2, int a3, int t0) // at 0x00000E9C - Aliases: sceUsb1Seg_driver_AF3E6BDE
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((s32)((((a1 + a3) | a1) | a3) & (k1 << 11)) < 0 || (s32)((((a2 + t0) | a2) | t0) & (k1 << 11)) < 0)
	if (!K1DynBufOk(a1, a3) || !K1DynBufOk(a2, t0))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_000023A8_GetReg(a0, a1, a2, a3, t0);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegSetReg(u8 *lpArg, u8 *a1, int size) // at 0x00000F24 - Aliases: sceUsb1Seg_driver_09201C1C
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if (((k1 << 11) & (((a1 + size) | a1) | size)) < 0)
	if (!K1StaBufOk(a1, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_00002518_SetReg(lpArg, a1, size);
	pspSdkSetK1(k1);
	return (ret);
}

// OK?
int sceUsb1SegEEPROMUpdate(s16 a0, int size, int a2, u8 *a3)
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((s32)(k1 & (((a3 + size) | a3) | size)) < 0)
	if (!K1StaBufOk(a3, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_0000263C_EEPROMUpdate(a0, size, a2, a3);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegEEPROMParamChange(int a0, int a1, int a2) // at 0x00000FFC - Aliases: sceUsb1Seg_driver_FF2F5FA7
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}

	if ((a0 < 256) == 0 || (a1 < 256) == 0 || !(a2 < 256))
	{
		return(0x80244505);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int ret = sub_00002934(a0, a1, a2);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegEEPROMParamWrite() // at 0x0000107C - Aliases: sceUsb1Seg_driver_FB44E917
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int ret = sub_0000276C_EEPROMParamWrite();
	pspSdkSetK1(k1);
	return (ret);
}

// OK?
int sceUsb1SegEEPROMParamRead(u8 *a0, int size)
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((int)((k1 << 11) & ((a0 + size) | a0 | size)) < 0)
	if (!K1DynBufOk(a0, size))
	{
		return(0x80244507);
	}

	int ret = sub_00002838(a0, size);
	pspSdkSetK1(k1);

	return (ret);
}

// OK
//405:sceUsb1Seg_CA800628
int sceUsb1Seg_D3ED2AFE(u16 a0, u8 *a1, int size) // at 0x00001134 - Aliases: sceUsb1Seg_driver_D3ED2AFE
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	if ((size < 61) == 0)
	{
		return(0x80244588);
	}
	
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((k1 << 11) & (((a1 + size) | a1) | size) < 0)
	if (!K1DynBufOk(a1, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_00002A58(a0, a1, size);
	pspSdkSetK1(k1);
	return (ret);
}

// OK?
//405:sceUsb1Seg_C9A04D0D
int sceUsb1Seg_57475AF7(u16 a0, u8 *a1, int size) // at 0x000011B4 - Aliases: sceUsb1Seg_driver_57475AF7
{
	if (!g_bAttached)
	{
		return(0x80244503);
	}
	if ((size < 61) == 0)
	{
		return(0x80244588);
	}

	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	//if ((k1 << 11) & (((a1 + size) | a1) | size) < 0)
	if (!K1DynBufOk(a1, size))
	{
		pspSdkSetK1(k1);
		return(0x80244507);
	}

	int ret = sub_00002BB8(a0, a1, size);
	pspSdkSetK1(k1);
	return (ret);
}

// OK?
// int (*changeSetting)(int itrfcNum, int alternateSetting);	
void Func28(int itrfcNum, int alternateSetting)
{
	if (itrfcNum != 0)
	{
		return;
	}
	if (alternateSetting == 0)
	{
		sceKernelClearEventFlag(g_eventFlag, -75);
		sceKernelSetEventFlag(g_eventFlag, 32);
	}
	else
	{
		g_index = 0;
		g_index180 = 0;
		int i;
		for (i = 0; i < 2; i++)
		{
			g_lpPcktBufs[i]->lpNext = 0;
			memset(g_lpPcktBufs[i].buf, 0, 192);
		}

		g_onesegState = 2;
		sceKernelClearEventFlag(g_eventFlag, -33);
		sceKernelSetEventFlag(g_eventFlag, 64);
		sceKernelDcacheInvalidateRange(g_lpUsbData, 384);
		int v0 = sceUsbbdReqRecv(&g_usbReq);

		if ((s32)v0 < 0)
		{
			Kprintf("%serror - ReqRecv() : 0x%08x\n", "SceUsb1Seg:", v0);
		}
	}
	g_alternateSetting = alternateSetting;
	return;
}

// OK
int RecvCtrl(int arg1, int arg2, struct DeviceRequest *lpDevReq)
{
	s0 = &g_bulkinReq;
	if (arg2 < 0)
	{
		return(-1);
	}

	/*asm("lwl        $v0, 3($a2)");
	asm("lwr        $v0, 0($a2)");
	asm("lwl        $v1, 7($a2)");
	asm("lwr        $v1, 4($a2)");
	asm("swl        $v0, -5($s0)");
	asm("swr        $v0, -8($s0)");
	asm("swl        $v1, -1($s0)");
	asm("swr        $v1, -4($s0)");*/
	g_bulkinReq2 = *lpDevReq;

	static DeviceRequest off_4F98[] =
	{
		{ 0x41, 0x05, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0x03, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0x04, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0x08, 0x0000, 0x0000, 0x0000 },

		{ 0x41, 0x09, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0x0A, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xFF, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xFE, 0x0000, 0x0000, 0x0000 },

		{ 0x41, 0xFD, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xFC, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xFB, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xFA, 0x0000, 0x0000, 0x0000 },

		{ 0x41, 0xF9, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF7, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF6, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF5, 0x0000, 0x0000, 0x0000 },

		{ 0xC1, 0xF8, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF8, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF3, 0x0000, 0x0000, 0x0000 },
		{ 0x41, 0xF4, 0x0000, 0x0000, 0x0000 },
	};
	int i;
	for (i = 0; i < 20; i++)
	{
		if (lpDevReq->bmRequestType == off_4F98[i].bmRequestType &&
			lpDevReq->bRequest == off_4F98[i].bRequest)
		{
			break;
		}
	}

	if (i == 20)
	{
		Kprintf("%sUnknown device request: bmRequestType = 0x%02x,bRequest = 0x%02x, wLength = %d\n", "SceUsb1Seg:", lpDevReq->bmRequestType, lpDevReq->bRequest, lpDevReq->wLength);
		return(-1);
	}
	if (lpDevReq->bmRequestType < 0)
	{
		if (lpDevReq->bRequest != 248 || lpDevReq->wLength == 0)
		{
			return(0);
		}
		t8 = *(s32*)(0x00000 + 244 + 268);
		t7 = *(s32*)(0x00000 + 244 + 256);	// eeprom ptr *a3
		*(s32*)(0x00000 + 244 + 268) = t8 + lpDevReq->wLength;
		g_bulkinReq.data = t7 + t8;
		g_bulkinReq.size = lpDevReq->wLength;
		sceKernelDcacheWritebackRange(t7 + t8, lpDevReq->wLength);
		v0 = sceUsbbdReqSend(&g_bulkinReq);
		if ((s32)v0 >= 0)
		{
			return (0);
		}
		Kprintf("%sint %s: Cannot issue send request: 0x%08x\n", "SceUsb1Seg:", "DevReqHdlr", v0);
		return(0);
	}
	v1 = lpDevReq->bRequest;
	//v1 = v1 & 0xFF;
	//a0 = (v1 & 0xFF) - 243;
	//a3 = (s32)v1 < (s32)11;
	//v0 = (u32)a0 < (u32)13;
	//a3 = (s32)v1 < 11;
	v0 = (v1 - 243) < 13;
	if ((v1 < 11) == 0)
		goto loc_000013F0;

	//t4 = v1 - 3;
	//t3 = (s32)v1 < (s32)8;
	v0 = (v1 - 3) < (u32)3;
	if ((v1 < 8) == 0)
		goto loc_000013F8;

loc_000013F0:
	if (v0 == 0)
	{
		Kprintf("%sRecv Unknown Req in Devreq\n", "SceUsb1Seg:");
		return(-1);
	}

loc_000013F8:
	g_bulkinReq.data = g_lpBulkinData;	// 0x00000 + 244 + 132
	g_bulkinReq.size = lpDevReq->wLength;
	sceKernelDcacheInvalidateRange(g_lpBulkinData, 128);
	if (sceUsbbdReqRecv(&g_bulkinReq) < 0)
	{
		Kprintf("%sint %s: Cannot issue recv request: 0x%08x\n", "SceUsb1Seg:", "DevReqHdlr", v0);
	}
	return (0);
}

int DriverStart(int size, void *lpArgs)	// 0x1514 ~ 0x1900
{
	//*(s32*)(sp + 0) = 0;
	u8	*lpData=0;

	g_mutexID = -1;
	g_threadID = -1;
	g_poolUID = -1;
	g_eventFlag = -1;

	g_poolUID = sceKernelCreateFpl("SceUsb1Seg", PSP_MEMORY_PARTITION_KERNEL, 256, 1328, 1, 0);
	if (g_poolUID < 0)
	{
		Kprintf("%serror - cannot create FPL\n", "SceUsb1Seg:");
		goto loc_000017B4;
	}
	if (sceKernelTryAllocateFpl(g_poolUID, &lpData) < 0)
	{
		Kprintf("%serror - cannot allocate memmory\n", "SceUsb1Seg:");
		goto loc_000017B4;
	}
	a1 = lpData;
	//s1 = 0x00000 + 244;
	//a0 = a1 + 384;
	//t0 = a1 + 448;
	//a3 = a1 + 576;
	g_lpData = lpData + 384;	//64 bytes
	g_lpBulkinData = lpData + 448;	//64 bytes
	g_lpUsbData = lpData;	// 192*2 bytes
	lpData = a1 + 576;

	v1 = a1 + 576;
	int i;
	for (i = 0; i < 2; i++)
	{
		g_lpPcktBufs[i] = v1;
		v1 += 256;
	}

	/*(s32*)(0x00000 + 164 + 16) = 0;
	*(s32*)(0x00000 + 164 + 20) = 0;
	*(s32*)(0x00000 + 164 + 24) = v1;
	*(s32*)(0x00000 + 164 + 28) = v1 + 20;*/
	g_driver.devp_hi = 0;
	g_driver.confp_hi=0;
	g_driver.devp = v1;
	g_driver.confp = v1 + 20;

	lpData = v1 + 36;
	lpData = sub_00003400(1, v1, v1 + 20, v1 + 36);	// 1, UsbData::devdesc, UsbData::Config, UsbData::ConfDesc

	g_threadID = sceKernelCreateThread("SceUsb1Seg", UsbThread, 16, 1024, 0x100001, 0);
	if (g_threadID < 0)
	{
		Kprintf("%serror - cannot create thread\n", "SceUsb1Seg:");
		goto loc_000017B4;
	}
	g_eventFlag = sceKernelCreateEventFlag("SceUsb1Seg", 513, 161, 0);
	if (g_eventFlag < 0)
	{
		Kprintf("%serror - cannot create event flag\n", "SceUsb1Seg:");
		goto loc_000017B4;
	}
	g_mutexID = sceKernelCreateMutex("SceUsb1SegCmdLock", 1, 0, 0);
	if (g_mutexID < 0)
	{
		Kprintf("%serror - cannot create mutex\n", "SceUsb1Seg:");
	}

	//a1 = &g_bulkinReq;
	//t4 = g_lpBulkinData;
	//t7 = g_lpUsbData;
	//s2 = g_lpData;
	//t5 = 0x00000;
	//t1 = 0x00000 + 128;
	//t9 = 0x00000;
	//s0 = 0x00000;
	//t0 = 0x00000;
	//a2 = 0x00000 + 244 + 40;
	//t6 = 0x00000 + 244 + 136;
	//a0 = 64;
	//t3 = 0x00000 + 128 + 12;
	//t8 = sub_2F2C;//t9 + 12076;
	//t2 = 0x00000 + 12628;
	//v0 = 192;
	//v1 = sub_315C;//t0 + 12636;
	g_bulkinReq.endp = &g_bulkinEndpoint;
	g_bulkinReq.data = g_lpBulkinData;
	g_bulkinReq.size	= 64;
	g_bulkinReq.unkc	= 1;
	g_bulkinReq.func = sub_2F2C;//t9 + 12076;
	g_bulkinReq.recvsize = 0;
	g_bulkinReq.retcode = 0;
	g_bulkinReq.unk1c = 0;
	g_bulkinReq.arg = 0;

	g_deviceReq.endp = 0;
	g_deviceReq.data = g_lpData;
	g_deviceReq.size = 64;
	g_deviceReq.unkc	= 0;
	g_deviceReq.func = BulkoutReqDone;//0x3154;
	g_deviceReq.recvsize = 0;
	g_deviceReq.retcode	= 0;
	g_deviceReq.unk1c = 0;
	g_deviceReq.arg = 0;

	g_usbReq.endp = &g_usbEndpoint;
	g_usbReq.data = g_lpUsbData;
	g_usbReq.size = 192;
	g_usbReq.unkc = 0;
	g_usbReq.func = AsyncReqDone;	// sub_315C;
	g_usbReq.recvsize = 0;
	g_usbReq.retcode = 0;
	g_usbReq.unk1c = 0;
	g_usbReq.arg = 0;

	g_bAttached = 0;
	g_alternateSetting = 0;
	g_onesegState = 0;
	g_chNum = 0;

	t5 = &g_bulkinEndpoint.unk3;//0x00000 + 128 + 8;
	t4 = 1;
	do
	{
		*(s32*)(t5 + 0) = 0;
		t5 += 12;
	} while (--t4 >= 0);

	g_lpData[0] = 8;
	if (sceUsbAccRegisterType(8) < 0)
		goto loc_000017B4;
	sceKernelStartThread(g_threadID, 0, 0);
	g_bStarted = 1;
	return (0);

loc_000017B4:	// Destructor
	if (g_mutexID > 0)
	{
		if (sceKernelDeleteMutex(g_mutexID) < 0)
		{
			Kprintf("%serror - cannot delete mutex\n", "SceUsb1Seg:");
		}
		g_mutexID = -1;
	}
	if (g_eventFlag > 0)
	{
		if (sceKernelDeleteEventFlag(g_eventFlag) < 0)
		{
			Kprintf("%serror - cannot delete event flag\n", "SceUsb1Seg:");
		}
		g_eventFlag = -1;	// Set invalid value
	}
	if (g_threadID > 0)
	{
		if (sceKernelDeleteThread(g_threadID) < 0)
		{
			Kprintf("%serror - cannot delete thread\n", "SceUsb1Seg:");
		}
		g_threadID = -1;	// Set invalid value
	}
	if (g_poolUID > 0)
	{
		if (sceKernelDeleteFpl(g_poolUID) < 0)
		{
			Kprintf("%serror - cannot delete FPL\n", "SceUsb1Seg:");
		}
		g_poolUID = -1;	// Set invalid value
	}
	return(-1);
}

int DriverStop(int size, void *args)
{
	sceUsbAcc_internal_18B04C82(8);
	int curIntCtrlState = sceKernelCpuSuspendIntr();
	g_onesegState = 4;
	sceKernelSetEventFlag(g_eventFlag, 4);
	sceKernelCpuResumeIntr(curIntCtrlState);
	sceKernelWaitThreadEnd(g_threadID, 0);

	if (g_mutexID > 0)
	{
		if (sceKernelDeleteMutex(g_mutexID) < 0)
		{
			Kprintf("%serror - cannot delete mutex\n", "SceUsb1Seg:");
		}
		g_mutexID = -1;
	}
	if (g_threadID > 0)
	{
		if (sceKernelDeleteThread(g_threadID) < 0)
		{
			Kprintf("%serror - cannot delete thread\n", "SceUsb1Seg:");
		}
		g_threadID = -1;
	}
	if (g_eventFlag > 0)
	{
		if (sceKernelDeleteEventFlag(g_eventFlag) < 0)
		{
			Kprintf("%serror - cannot delete event flag\n", "SceUsb1Seg:");
		}
		g_eventFlag = -1;
	}
	if (g_poolUID > 0)
	{
		if (sceKernelDeleteFpl(g_poolUID) < 0)
		{
			Kprintf("%serror - cannot delete FPL\n", "SceUsb1Seg:");
		}
		g_poolUID = -1;
	}
	g_bStarted = 0;
	return (0);
}

int sub_00001A74() // at 0x00001A74 
{
	int ret;

	sceKernelLockMutex(g_mutexID, 1, 0);
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 1;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		ret = 0x80243006;
	}
	return (ret);
}

int sub_00001AF8() // at 0x00001AF8 
{
	int ret;

	sceKernelLockMutex(g_mutexID, 1, 0);
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 2;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		ret = 0x80243006;
	}
	return (ret);
}

// OK
int sub_00001B7C(u8 chNum) // at 0x00001B7C 
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	u8	sp[8];
	int ret = 0x80243006;

	*(s8*)(sp + 0) = chNum;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 3;
		g_lpData[3] = 1;
		memcpy(g_lpData + 4, sp, 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);

		if (!ret)
		{
			ret = sub_00003664_GetData(sp + 2, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(sp + 2);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

typedef struct
{
	char	unk[8];
} SCANCH_INFO;

// from ScanCh
int sub_00001C80_ScanCh(s8 *a0) // at 0x00001C80 
{
	int ret;
	u8	sp[32];

	sceKernelLockMutex(g_mutexID, 1, 0);

	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 4;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		ret = 0x80243006;
	}

	*(s8*)(a0 + 0) = 0;
	*(s8*)(a0 + 1) = 0;
	*(s8*)(a0 + 2) = 0;
	*(s8*)(a0 + 3) = 0;
	*(s8*)(a0 + 4) = 0;
	*(s8*)(a0 + 5) = 0;
	*(s8*)(a0 + 6) = 0;
	*(s8*)(a0 + 7) = 0;
	if (ret == 0)
	{
		ret = sub_00003664_GetData(sp, 10);
		if (!ret)
		{
			if ( *(s16*)(sp + 16) = *(u16*)(sp + 0) )
			{
				ret = sub_00002CEC_GetErrorCode(sp + 16);
			}
			else
			{
				*(s8*)(a0 + 0) = *(u8*)(sp + 5);
				*(s8*)(a0 + 1) = *(u8*)(sp + 4);
				*(s8*)(a0 + 2) = *(u8*)(sp + 3);
				*(s8*)(a0 + 3) = *(u8*)(sp + 2);
				*(s8*)(a0 + 4) = *(u8*)(sp + 9);
				*(s8*)(a0 + 5) = *(u8*)(sp + 8);
				*(s8*)(a0 + 6) = *(u8*)(sp + 7);
				*(s8*)(a0 + 7) = *(u8*)(sp + 6);
			}
		}
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

// OK
// GetModule
int sub_00001DD0_GetModule(u8 *a0) // at 0x00001DD0 
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	int ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 8;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(a0,1);
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

// SetEncKey, 3B70
// OK
int sub_00001E94(ONESEG_PARAM *lpParam) // at 0x00001E94 
{
	ONESEG_PARAM param;

	if ((lpParam.size < 64) == 0)
	{
		return (0x80244504);
	}
	param = *lpParam;
	sceKernelLockMutex(g_mutexID, 1, 0);

	int s0 = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 9;
		g_lpData[3] = 17;
		memcpy(g_lpData + 4, &param, 17);
		s0 = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!s0)
		{
			int unk;
			s0 = sub_00003664_GetData(&unk, 2);
			if (!s0)
			{
				s0 = sub_00002CEC_GetErrorCode(&unk);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

// OK?
int sub_00001FF0(u8 *a0) // at 0x00001FF0 
{
	sceKernelLockMutex(g_mutexID, 1, 0);
	
	int ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 10;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(a0, 2);
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

// OK?
// GetDbg
int sub_000020B4_GetDebug(int *lpDst, int size) // at 0x000020B4
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	int ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 255;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(lpDst, size);
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_00002184_SetDebug(int *lpSrc, int size) // at 0x00002184 
{
	int ret = 0x80244588;
	if (size < 61)
	{
		ret = 0x80243006;
		sceKernelLockMutex(g_mutexID, 1, 0);

		if (g_deviceReq.retcode <= 0)
		{
			g_lpData[2] = 249;
			g_lpData[3] = size;
			if (lpSrc)
			{
				memcpy(g_lpData + 4, lpSrc, size);
			}
			ret = sceUsbAcc_internal_2A100C1F(s4);
			if (!ret)
			{
				u8 sp[16];
				ret = sub_00003664_GetData(sp, 2);
				if (!ret)
				{
					ret = sub_00002CEC_GetErrorCode(sp);
				}
			}
		}
		else
		{
			Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		}

		sceKernelUnlockMutex(g_mutexID, 1);
	}
	return (ret);
}

// Pwm
int sub_000022A4_SetPwm(u8 *lpSrc) // at 0x000022A4 
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	int ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 254;
		g_lpData[3] = 2;
		if (lpSrc)
		{
			memcpy(g_lpData + 4, lpSrc, 2);
		}
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(sp, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(sp);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

// OK
int sub_000023A8_GetReg(s8 a0, u8 *a1, u8 *a2, int a3, int t0) // at 0x000023A8 
{
	if ((a3 < 60) == 0 || (t0 < 59) == 0)
	{
		return (0x80244588);
	}

	int ret;
	u8	sp[128];

	sceKernelLockMutex(g_mutexID, 1, 0);
	*(s8*)(sp + 0) = a0;
	memcpy(sp + 1, a1, a3);

	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 250;
		g_lpData[3] = a3 + 1;
		memcpy(g_lpData + 4, sp, a3 + 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(sp, 60);
			if (!ret)
			{
				if (*(s16*)(sp + 64) = *(u16*)(sp + 0))
				{
					ret = sub_00002CEC_GetErrorCode(sp + 64);
				}
				else
				{
					memcpy(a2, sp + 2, t0);
				}
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		ret = 0x80243006;
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_00002518_SetReg(u8 a0, int *lpSrc, int size) // at 0x00002518 
{
	int ret = 0x80244588;
	u8 sp[128];

	if (size < 60)
	{
		ret = 0x80243006;
		*(s8*)(sp + 0) = a0;
		memcpy(sp + 1, lpSrc, size);
		sceKernelLockMutex(g_mutexID, 1, 0);

		if (g_deviceReq.retcode <= 0)
		{
			g_lpData[2] = 251;
			g_lpData[3] = size + 1;
			memcpy(g_lpData + 4, sp, size + 1);
			ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
			if (!ret)
			{
				ret = sub_00003664_GetData(sp + 64, 2);
				if (!ret)
				{
					ret = sub_00002CEC_GetErrorCode(sp + 64);
				}
			}
		}
		else
		{
			Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		}
		sceKernelUnlockMutex(g_mutexID, 1);
	}
	return (ret);
}

// from: EEPROM update
int sub_0000263C_EEPROMUpdate(s16 a0, int a1, int a2, u8 *a3) // at 0x0000263C 
{
	sceKernelLockMutex(g_mutexID, 1, 0);
	int curIntCtrlState = sceKernelCpuSuspendIntr();
	g_onesegState = 5;
	*(s32*)(0x00000 + 244 + 252) = 0;
	*(s32*)(0x00000 + 244 + 256) = a3;
	*(s32*)(0x00000 + 244 + 260) = a1;
	*(s32*)(0x00000 + 244 + 264) = a2;
	*(s16*)(0x00000 + 244 + 252) = a0;
	*(s32*)(0x00000 + 244 + 268) = 0;
	sceKernelSetEventFlag(g_eventFlag, 16);
	sceKernelCpuResumeIntr(curIntCtrlState);

	int bits;
	int ret = sceKernelWaitEventFlag(g_eventFlag, 1025, 1, &bits, 0);
	if (!ret)
	{
		ret = 0x80244503;
		if (bits & 0x1 == 0)
		{	ret = 0;	}
		if (bits & 0x400)
		{
			u8 sp[16];
			*(s16*)(sp + 0) = g_lpData[4] | (g_lpData[5] << 8);
			ret = sub_00002CEC_GetErrorCode(sp);
			sceKernelClearEventFlag(g_eventFlag, -1025);
		}
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_0000276C_EEPROMParamWrite() // at 0x0000276C 
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	int ret = 0x80243006;
	u8	sp[128];

	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 246;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(sp, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(sp);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

//from EEPROMParamRead
int sub_00002838(u8 *a0, int a1) // at 0x00002838 
{
	sceKernelLockMutex(g_mutexID, 1, 0);
	int ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 245;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(a0, a1);
			if (!ret)
			{
				u8 sp[16];
				*(s8*)(sp + 0) = *(s8*)(a0 + 0);
				*(s8*)(sp + 1) = *(s8*)(a0 + 1);
				if (*(u16*)(sp + 0))
				{
					ret = sub_00002CEC_GetErrorCode(sp);
				}
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_00002934(s8 a0, s8 a1, s8 a2) // at 0x00002934 
{
	sceKernelLockMutex(g_mutexID, 1, 0);

	int ret = 0x80243006;
	u8 sp[128];

	*(s8*)(sp + 0) = a0;
	*(s8*)(sp + 1) = a1;
	*(s8*)(sp + 2) = a2;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 247;
		g_lpData[3] = 3;
		memcpy(g_lpData + 4, sp, 3);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(sp + 16, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(sp + 16);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_00002A58(u16 a0, u8 *lpDst, u8 size)
{
	sceKernelLockMutex(g_mutexID, 1, NULL);	// (mutexID, count, *timeOut)
	u8	sp[128];

	*(s8*)(sp + 1) = (a0 & 0xFFFF) >> 8;
	*(s8*)(sp + 0) = a0 & 0xFFFF;
	*(s8*)(sp + 2) = size;

	int ret;
	u8 sp[128];

	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 243;
		g_lpData[3] = 3;
		memcpy(g_lpData + 4, sp, 3);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		ret = 0x80243006;
	}
	memset(lpDst, 0, size);
	if (ret == 0)
	{
		ret = sub_00003664_GetData(sp, 60);
		if (!ret)
		{
			if (*(s16*)(sp + 64) = *(u16*)(sp + 0))
			{
				ret = sub_00002CEC_GetErrorCode(sp + 64);
			}
			else
			{
				memcpy(lpDst, sp + 2, a2);
			}
		}
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_00002BB8(u16 a0, u8 *a1, u8 size)
{
	sceKernelLockMutex(g_mutexID, 1, NULL);
	int ret = 0x80243006;
	u8 sp[128];
	*(s8*)(sp + 1) = (a0 & 0xFFFF) >> 8;
	*(s8*)(sp + 0) = a0 & 0xFFFF;
	*(s8*)(sp + 2) = size;
	memcpy(sp + 3, &g_deviceReq, size + 3);

	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 244;
		g_lpData[3] = size + 3;
		memcpy(g_lpData + 4, sp, size + 3);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(sp + 64, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(sp + 64);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

typedef struct _ERROR_CODE
{
	int	code;
	int	unk;
} ERROR_CODE;

struct ERROR_CODE g_errorCodes[10] =
{
	{0x00000000,	0x0000},	// at 0x00005038
	{0x80244508,	0x0081},
	{0x80244581,	0x0181},
	{0x80244582,	0x0182},
	{0x80244583,	0x0282},
	{0x80244584,	0x0482},
	{0x80244585,	0x0882},
	{0x80244586,	0x1082},
	{0x80244587,	0x2082},
	{0x80244588,	0x0085},
};

// OK
int sub_00002CEC_GetErrorCode(u16 *lpUnk) // from TunerInit/sub
{
	u16 unk = *lpUnk;

	for (int i = 0; i < 10; i++)
	{
		if (g_errorCodes[i].unk == unk)
		{
			return(g_errorCodes[i].cpde);
		}
	}
	return (0x80244501);
}

// OK?
//405:sceUsb1Seg_5F62E0B5
int sceUsb1SegChangeCh(u8 chNum)
{
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	int ret = sub_00001B7C(chNum);
	pspSdkSetK1(k1);
	return (ret);	
}

// OK?
//405:sceUsb1Seg_557E6B41
int sceUsb1SegInitTuner()
{
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	int ret = sub_00003708(g_bAttached);
	pspSdkSetK1(k1);
	return (ret);
}

// OK?
//405:sceUsb1Seg_19AF6734
int sceUsb1Seg_00CC60F7(int mode) // at 0x00002DC4 - Aliases: sceUsb1Seg_driver_00CC60F7
{
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	int ret = sceClockgenSetSpectrumSpreading(mode);
	pspSdkSetK1(k1);

	return (ret);
}

// OK
int sceUsb1SegSetAntenna(u8 *a0) // at 0x00002DF0 - Aliases: sceUsb1Seg_driver_A9498C6C
{
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int	ret = sub_000037D4_SetAntenna(a0);
	pspSdkSetK1(k1);
	return (ret);
}

// OK
int sceUsb1SegSetBPER(u8 *a0) // at 0x00002E3C - Aliases: sceUsb1Seg_driver_795EBEB0
{
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	int k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	int	ret = sub_000038D8_SetBPER(a0);

	pspSdkSetK1(k1);
	return (ret);
}

/*
struct UsbInterface
{
	int expect_interface;
	int unk8;
	int num_interface;
};
struct UsbEndpoint
{
	int endpnum;
	int unk2;
	int unk3;
};
struct StringDescriptor
{
	unsigned char bLength;
	unsigned char bDescriptorType;
	short bString[32];
} __attribute__((packed));

struct UsbDriver
{
	const char *name; 
	int endpoints;
	struct UsbEndpoint *endp; 
	struct UsbInterface *intp;        
	struct DeviceDescriptor *desc_hi;  
	struct UsbConfiguration *conf_hi; 
	struct DeviceDescriptor *desc;  
	struct UsbConfiguration *conf; 
	struct StringDescriptor *stringDescs; 
	int (*recvctl)(int recipient, int endpNumOfItrfcNum, struct DeviceRequest *req);
	int (*changeSetting)(int itrfcNum, int alternateSetting);		// func28
	int (*attach)(int usbVer); 
	int (*detach)();
	int (*configure)(int usbVer, int descCount, struct InterfaceSettings *lpSettings);
	int (*start_func)(int size, void *args);
	int (*stop_func)(int size, void *args);  
	struct UsbDriver *link;
};	// 68[B]
*/

// at 0x00005150
struct UsbDriver	g_driver =	// 0x00000 + 164
{
	"USB1SegDriver",	// 0x4B2C	////0x4960
	2,
	0x80,
	0x98,	// intp
	NULL,
	NULL,	// confp_hi
	NULL,
	NULL,	// confp
	NULL,
	RecvCtrl,	//0x1340,
	Func28,	//0x1234,
	Attach,	//0x3344,
	Detach,	//0x3388,
	NULL,
	DriverStart,	//0x1514,
	DriverStop,	//0x1900,
	NULL
};

int module_start(int argc, void *lpArg)
{
	// param: USB driver struct
	// return: 0 on success, < 0 on error
	int ret = sceUsbbdRegister(&g_driver);

	if (ret < 0)
	{
		Kprintf("%serror - cannot register : 0x%08x\n", "SceUsb1Seg:", ret);
		ret = 1;	// on error
	}
	else
	{
		g_bStarted = 0;	//finelize
		ret = 0;
	}
	return (ret);
}

int module_stop(int args, void *lpArgs) // at 0x00002EDC 
{
	int ret = sceUsbbdUnregister(&g_driver);
	if (ret < 0)
	{
		Kprintf("%serror - cannot unregister : 0x%08x\n", "SceUsb1Seg:", ret);
		return(1);
	}
	return(0);
}

void BulkinReqDone(UsbdDeviceReq *lpDevReq)	// 2F2C~3154
{
	if (lpDevReq->retcode != 0 || (s32)*(s8*)(0x00000 + 244 + 84) < 0)
	{
		return;
	}
	if (g_cmdResult == 245)
	{
		if (g_cmdResult == g_lpData[2])
		{
			memcpy(g_lpData + 4, lpDevReq->data, *(u16*)(0x00000 + 244 + 90));
			sceKernelSetEventFlag(g_eventFlag, 1024);
		}
		return;
	}
	if ((g_cmdResult < 246) == 0)
	{
		if (g_cmdResult == 249)
			goto loc_00002FD0;
		if ((g_cmdResult < 250) == 0)
		{
			//t0 = 255;
			if ((g_cmdResult < 255) == 0)
			{
				//t9 = 0x00000 + 244;
				if (g_cmdResult != 255)
					goto loc_00002FA8;
			}
			else
			{
				//a3 = *(u8*)(0x00000 + 244 + 85) < (s32)251;
				//a2 = 0x00000 + 244;
				if ((g_cmdResult < 251) == 0)
					goto loc_00002FD0;
			}
			if (g_cmdResult == g_lpData[2])
			{
				memcpy(g_lpData + 4, lpDevReq->data, *(u16*)(0x00000 + 244 + 90));
				sceKernelSetEventFlag(g_eventFlag, 1024);
			}
			return;
		}
		//t8 = (s32)v1 < (s32)248;
		//a2 = 0x00000 + 244;
		if (g_cmdResult < 248)
			goto loc_00002FD0;
		if (g_cmdResult == g_lpData[2])
		{
			memcpy(g_lpData + 4, lpDevReq->data, *(u16*)(0x00000 + 244 + 90));
			sceKernelSetEventFlag(g_eventFlag, 2048);
		}
		return;
	}
	if (g_cmdResult == 8)
	{
		if (g_lpData[2] == g_cmdResult)
		{
			t5 = lpDevReq->data;
			g_lpData[4] = *(u8*)(t5 + 0);
			sceKernelSetEventFlag(g_eventFlag, 1024);
		}
		return;
	}
	if ((g_cmdResult< 9) == 0)
	{
		if (g_cmdResult == 243)
		{
			if (g_cmdResult == g_lpData[2])
			{
				memcpy(g_lpData + 4, lpDevReq->data, *(u16*)(0x00000 + 244 + 90));
				sceKernelSetEventFlag(g_eventFlag, 1024);
			}
			return;
		}
		//a2 = 0x00000 + 244;
		if ((g_cmdResult< 244) == 0)
			goto loc_00002FD0;
		//t6 = (s32)v1 < (s32)11;
		//t9 = 0x00000 + 244;
		if ((g_cmdResult < 11) == 0)
			goto loc_00002FA8;
		//a3 = g_lpData;
		goto loc_00002FD0;
	}
	if (g_cmdResult == 4)
	{
		a3 = g_lpData;
		if (g_lpData[2] != g_cmdResult)
		{
			return;
		}
		t3 = lpDevReq->data;
		asm("lwl        $v1, 3($t3)");
		asm("lwr        $v1, 0($t3)");
		asm("lwl        $a0, 7($t3)");
		asm("lwr        $a0, 4($t3)");

		asm("swl        $v1, 7($a3)");
		asm("swr        $v1, 4($a3)");
		asm("swl        $a0, 11($a3)");
		asm("swr        $a0, 8($a3)");
		g_lpData[12] = *(s8*)(t3 + 8);
		g_lpData[13] = *(s8*)(t3 + 9);
		sceKernelSetEventFlag(g_eventFlag,1024);
		return;
	}

	v0 = (g_cmdResult< 5) ? 3 : 5;

	if (g_cmdResult == v0)
		goto loc_00002FD0;

loc_00002FA8:
	Kprintf("%serror - Unknown Command Result. 0x%02x\n", "SceUsb1Seg:", g_cmdResult);
	return;

loc_00002FD0:
	if (g_cmdResult != g_lpData[2])
	{
		return;
	}
	t2 = lpDevReq->data;
	g_lpData[4] = *(s8*)(t2 + 0);
	g_lpData[5] = *(s8*)(t2 + 1);
	sceKernelSetEventFlag(g_eventFlag,1024);
	return;
}

int BulkoutReqDone(UsbdDeviceReq *lpDevReq)	// 3154
{
	return (v0);
}

// loop?
int AsyncReqDone(UsbdDeviceReq *lpDevReq)	// sub_315C
{
	if (lpDevReq->retcode < 0)
	{
		return;
	}
	if (lpDevReq->recvsize == 192)
	{
		a2 = (g_index << 2) + (0x00000 + 244);
		v1 = *(s32*)(a2 + 188);
		a1 = *(s32*)(v1 + 0);
		if (a1 != 0)
		{
			*(s32*)(0x00000 + 240)++;
		}
		else
		{
			a3 = v1 + 16;
			t0 = a2 + 188 + 4;// a2 + 192;
			if (((lpDevReq->data | (v1 + 16)) & 0x3) == 0)
			{
				do
				{
					*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
					*(s32*)(a3 + 4) = *(s32*)(a2 + 4);
					*(s32*)(a3 + 8) = *(s32*)(a2 + 8);
					*(s32*)(a3 + 12) = *(s32*)(a2 + 12);
					a2 = a2 + 16;
					a3 = a3 + 16;
				} while (a2 != t0);
			}
			else
			{
				v0 = t0;
				do{
					asm("lwl        $v1, 3($a2)");
					asm("lwr        $v1, 0($a2)");
					asm("lwl        $a0, 7($a2)");
					asm("lwr        $a0, 4($a2)");
					asm("lwl        $a1, 11($a2)");
					asm("lwr        $a1, 8($a2)");
					asm("lwl        $t0, 15($a2)");
					asm("lwr        $t0, 12($a2)");
					asm("swl        $v1, 3($a3)");
					asm("swr        $v1, 0($a3)");
					asm("swl        $a0, 7($a3)");
					asm("swr        $a0, 4($a3)");
					asm("swl        $a1, 11($a3)");
					asm("swr        $a1, 8($a3)");
					asm("swl        $t0, 15($a3)");
					asm("swr        $t0, 12($a3)");
					a2 = a2 + 16;
					a3 = a3 + 16;
				} while (a2 != v0);
			}
			//t0 = (g_index << 2) + (0x00000 + 244 + 188);
			//s1 = *(s32*)(t0);
			s1 = g_lpPcktBufs[g_index];
			//*(s64*)(s1 + 8) = sceKernelGetSystemTimeWide();
			s1->qwSysTime = sceKernelGetSystemTimeWide();

			//a1 = (g_index << 2) + (0x00000 + 244 + 188);
			//t9 = *(s32*)(a1);
			t9 = g_lpPcktBufs[g_index];

			*(s32*)(t9 + 0) = 1;
			*(s32*)(0x00000 + 240) = 0;
			g_index ^= 0x1;
		}
		sceKernelSetEventFlag(g_eventFlag, 2);
	}
	if (g_onesegState == 2)
	{
		sceKernelDcacheInvalidateRange(lpDevReq->data, 192 * 2);
		v0 = sceUsbbdReqRecv(lpDevReq);
		if ((s32)v0 < 0)
		{
			Kprintf("%serror - ReqRecv() : 0x%08x\n", "SceUsb1Seg:",v0);
			return;
		}
		sceKernelClearEventFlag(g_eventFlag, -129);
		return;
	}
	sceKernelSetEventFlag(g_eventFlag, 128);
	return;
}

int Attach(int speed, void *arg2, void *arg3)
{
	int	ret	= 0;

	if (g_bAttached == 0)
	{
		g_bAttached = 1;
		g_onesegState = 0;
		ret = sceKernelClearEventFlag(g_eventFlag, - 2, 1);
	}
	return (ret);
}

// OK
int Detach(int arg1, void *arg2, void *arg3)
{
	if (!g_bAttached)
	{
		return;
	}
	g_onesegState = 0;
	g_bAttached = 0;
	g_alternateSetting = 0;

	v0 = &g_bulkinEndpoint.unk3;	//0x00000 + 128 + 8;
	int i = 1;
	do
	{
		*(s32*)(v0 + 0) = 0;
		v0 += 12;
	} while (--i >= 0);

	sceKernelClearEventFlag(g_eventFlag, 0);
	sceKernelSetEventFlag(g_eventFlag, 161);
	return;
}
// 1, UsbData::devdesc, UsbData::Config, UsbData::ConfDesc
int *sub_00003400(int a0, DeviceDescriptor *devp, UsbConfiguration *lpConfig, ConfigDescriptor *a3) // at 0x00003400 
{
	t9 = a3;
	/*(s32*)(lpConfig + 0) = a3;
	*(s32*)(lpConfig + 4) = a3 + 24;
	*(s32*)(lpConfig + 8) = a3 + 24 + 12;
	*(s32*)(lpConfig + 12) = a3 + 24 + 12 + 72;*/
	lpConfig->confp = a3;
	lpConfig->infs = a3 + 24;	// Interfaces
	lpConfig->infp = a3 + 24 + 12;	// InterDesc
	lpConfig->endp = a3 + 24 + 12 + 72;
	/*s0 = *(s32*)(lpConfig + 4);
	s1 = *(s32*)(lpConfig + 8);*/
	struct UsbInterfaces *s0 = lpConfig->infs;
	struct InterfaceDescriptor *s1 = lpConfig->infp;

	struct EndpointDescriptor *t7 = a3 + 24 + 12 + 72;

	static struct DeviceDescriptor devDescs[] =	// 0x4EF8
	{
		{
			0x12, 0x01, 0x0200, 0x00, 0x00, 0x00, 0x00,
			0x0000, 0x0000, 0x0100, 0x00, 0x00, 0x00, 0x00,
		}
	};
	
	int i;
	for (i = 0; i < 1; i++)
	{
		devp[i] = devDescs[i];
	}

	int dword_4F0C[] =	// 24 bytes
	{
		0x00220209, 0xC0000101, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	};
	/*struct ConfigDescriptor confDescs[] =	// 24 bytes
	{
		{ 0x09, 0x02, 0x0022, 0x01, 0x01, 0x00, 0xC0, 0x00 },
		{ 0x00, 0x00, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00 },
	};*/
	t9[0] = dword_4F0C[0];
	t9[1] = dword_4F0C[1];
	t9[2] = dword_4F0C[2];
	t9[3] = dword_4F0C[3];
	t9[4] = dword_4F0C[4];
	t9[5] = dword_4F0C[5];

	static struct UsbInterfaces usbInterface =	// 0x4F24
	{ NULL, NULL, 2 };
	*s0 = usbInterface;

	int dword_4F30[] =	// 72 bytes
	{
		0x00000409, 0x0000FF00, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x01000409, 0x0000FF01,
		0x00000000, 0x00000000, 0x00000000, 0x00000000,

		0x00000000, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000,
	};
	struct InterfaceDescriptor interfaceDescs[] =	// 0x4F30
	{
		{ 0x09, 0x04, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		{ 0x09, 0x04, 0x00, 0x01, 0x01, 0xFF, 0x00, 0x00, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
		{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	};
	int *t5 = s1;
	int *a2 = dword_4F30 + 16;
	int *t6 = dword_4F30;
	do
	{
		t5[0] = t6[0];
		t5[1] = t6[1];
		t5[2] = t6[2];
		t5[3] = t6[3];
		t5 += 4;
		t6 += 4;
	} while (t6 != a2);
	//t5[0] = t6[0];
	//t5[1] = t6[1];

	static struct EndpointDescriptor endpDescs[] =	// 0x4F78
	{
		{ 7, 5, 1, 5, 0x0000, 0 }, { 0, 0, 0, 0, 0x0000, 0 }, { 0, 0, 0, 0, 0x0000, 0 }, { 0, 0, 0, 0, 0x0000, 0 },
	};
	t7[0] = endpDescs[0];
	t7[1] = endpDescs[1];
	t7[2] = endpDescs[2];
	t7[3] = endpDescs[3];
	t7[0].wMaxPacketSize = 192;

	t9[3] = s0;
	s0->infp[0] = s1;	//*(s32*)(s0 + 0) = s1;
	*(s32*)(s1 + 36) = t7;
	devp[0].bMaxPacketSize = 64;
	t7[0].bInterval = (a0 == 2) ? 4 : 2;
	return (a3 + 24 + 12 + 72 + 32);
}

// from InitTuner
// ScanCh, GetModule/sub
int sub_00003664_GetData(int *lpDst, int size)
{
	int	ret;	
	uint bits;

	ret = sceKernelWaitEventFlag(g_eventFlag, 1025, 1, &bits, NULL);

	if (!ret)
	{
		if (bits & 0x1 == 0)
		{
			memcpy(lpDst, g_lpData + 4, size);
			ret = sceKernelClearEventFlag(g_eventFlag, -1025);
		}
		else
		{
			ret = 0x80244503;
		}
	}
	return (ret);
}

// from InitTuner
int sub_00003708() // at 0x00003708 
{
	int ret = 0x80243006;

	sceKernelLockMutex(g_mutexID, 1, 0);
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 5;
		g_lpData[3] = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			int x;

			ret = sub_00003664_GetData(&x, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(&x);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_000037D4_SetAntenna(int ch)
{
	int	ret;
	u8	x, y, z;

	x = ch;
	sceKernelLockMutex(g_mutexID, 1, NULL);
	
	ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 253;
		g_lpData[3] = 1;
		memcpy(g_lpData + 4, &x, 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664_GetData(&z, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(&z);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int sub_000038D8_SetBPER(int ch) // at 0x000038D8 
{
	int	ret;
	u8	x, y, z;

	x = ch;
	sceKernelLockMutex(g_mutexID, 1, 0);

	ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		g_lpData[2] = 252;
		g_lpData[3] = 1;
		memcpy(g_lpData + 4, &x, 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);

		if (!ret)
		{
			ret = sub_00003664_GetData(&z, 2);
			if (!ret)
			{
				ret = sub_00002CEC_GetErrorCode(&z);
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

int UsbThread(void *lpArg)	// 0x39DC
{
	if (g_onesegState != 4)
	{
		do
		{
			if (g_onesegState >= 6)
			{
				sub_00003AB8();
			}
			else
			{
				switch (g_onesegState)
				{
					case 0:
						sub_00003AB8();
						break;
					case 1:
						sub_00003B70();
						break;
					case 2:
						if (g_cbUID1 < 0)
						{	sub_00003C38();	}
						else
						{	sub_00003F74();	}
						break;
					case 3:
						sub_000042EC();
						break;
					case 4:
						break;
					case 5:
						UpdateStatProc();
						break;
				}
			}
		} while (g_onesegState != 4);
	}
	return (0);
}

// OK
int sub_00003AB8() // at 0x00003AB8 
{
	int bits;
	int ret = sceKernelWaitEventFlag(g_eventFlag, 20, 1, &bits, 0);

	if ((s32)ret < 0)
	{
		return (ret);
	}
	if (bits & 0x10)
	{
		sceKernelClearEventFlag(g_eventFlag, -17);
		if (bits & 0x1)
		{
			g_onesegState = 0;
		}
		return (ret);
	}
	if ((bits & 0x4) == 0 || g_onesegState == 4)
	{
		return (ret);
	}
	Kprintf("%serror - Driver status is not END, but END flag is set in event flag\n", "SceUsb1Seg:");
	g_onesegState = 4;
	return (ret);
}

int sub_00003B70() // at 0x00003B70 
{
	int ret = sub_00001E94(&g_onesegParam);

	if ((s32)ret >= 0)
	{
		ret = sub_00001B7C(g_chNum);
		if ((s32)ret >= 0)
		{
			ret = sub_00001A74();
			if (ret == 0)
			{
				ret = sceKernelWaitEventFlag(g_eventFlag, 65, 1, sp, NULL);
			}
		}
	}
	g_errorCode16 = ret;
	sceKernelSetEventFlag(g_eventFlag, 256);
	sceKernelUnlockMutex(g_mutexID, 1);
	
	if ((s32)ret < 0)
	{
		Kprintf("%sFailed to start stream\n", "SceUsb1Seg:");
		g_onesegState = 0;
	}

	return (ret);
}

int sub_00003C38() // at 0x00003C38 
{
	if (g_onesegState != 2)
	{
		return(0);
	}
	s5 = 0;
	s3 = 1;
	uint bits;

	do
	{
		if (!sceKernelWaitEventFlag(g_eventFlag, 16421, 1, &bits, 0))
		{
			if (bits & 0x4000)
			{
				s0 = sceKernelWaitEventFlag(g_eventFlag, 39, 1, &bits, 0);
				if (s0 != 0)
				{
					Kprintf("%serror - at waiting for event at line %d): ret = 0x%08x pattern = %08x\n", "SceUsb1Seg:", 1696, s0, bits);
					return (s0);
				}
				//v1 = *(s32*)(sp + 0);
				if ((bits & 0x2) == 0)
					goto loc_00003CE0;
				int curIntrState = sceKernelCpuSuspendIntr();
				t0 = (g_index180 << 2) + (0x00000 + 244);
				a3 = *(s32*)(t0 + 188);
				if (*(s32*)(a3 + 0))
				{
					do
					{
						a1 = *(s32*)(0x00000 + 244 + 224);
						if (a1 == 0)
						{
							if (s3 == 0)
							{
								s5 = 1;
							}
							break;
						}
						t9 = g_num204;
						s0 = (g_index180 << 2) + (0x00000 + 244);
						t7 = (t9 << 1) + t9;
						t6 = *(s32*)(s0 + 188);
						t0 = a1 + (t7 << 3);
						*(s32*)(t0 + 0) = 0;
						*(s32*)(t0 + 8) = *(s32*)(t6 + 8);
						*(s32*)(t0 + 12) = *(s32*)(t6 + 12);
						v1 = *(s32*)(t0 + 20);
						if (v1 >= 0)
						{
							a3 = v1;
							a2 = (g_index180 << 2) + (0x00000 + 244);
							t1 = *(s32*)(a2 + 188) + 208;
							if (((*(s32*)(a2 + 188) + 16) | v1) & 0x3 == 0)
							{
								do
								{
									*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
									*(s32*)(a3 + 4) = *(s32*)(a2 + 4);
									*(s32*)(a3 + 8) = *(s32*)(a2 + 8);
									*(s32*)(a3 + 12) = *(s32*)(a2 + 12);
									a3 = a3 + 16;
									a2 = a2 + 16;
								} while (a2 != t1);
							}
							else
							{
								v0 = t1;
								do
								{
									asm("lwl        $v1, 3($a2)");
									asm("lwr        $v1, 0($a2)");
									asm("lwl        $a0, 7($a2)");
									asm("lwr        $a0, 4($a2)");
									asm("lwl        $a1, 11($a2)");
									asm("lwr        $a1, 8($a2)");
									asm("lwl        $t1, 15($a2)");
									asm("lwr        $t1, 12($a2)");
									asm("swl        $v1, 3($a3)");
									asm("swr        $v1, 0($a3)");
									asm("swl        $a0, 7($a3)");
									asm("swr        $a0, 4($a3)");
									asm("swl        $a1, 11($a3)");
									asm("swr        $a1, 8($a3)");
									asm("swl        $t1, 15($a3)");
									asm("swr        $t1, 12($a3)");
									a2 = a2 + 16;
									a3 = a3 + 16;
								} while (a2 != v0);
							}
						}
						g_num204++;
						if (s3 == 0 && s5)
						{
							s5 = 0;
							*(s32*)(t0 + 0) |= 0x1;
						}
						s3 = 0;
						v1 = g_num200;
						if (v1 && (g_num204 < v1) == 0)
						{
							*(s32*)(0x00000 + 244 + 224) = 0;
							sceKernelClearEventFlag(g_eventFlag, -16385);
							sceKernelSetEventFlag(g_eventFlag, 4096);
						}
						t4 = (g_index180 << 2) + (0x00000 + 244);
						v1 = *(s32*)(t4 + 188);
						*(s32*)(v1 + 0) = 0;
						t2 = ((g_index180 ^ 0x1) << 2) + (0x00000 + 244);
						g_index180 ^= 0x1;
						a1 = *(s32*)(t2 + 188);
					} while (*(s32*)(a1 + 0));
				}
				sceKernelClearEventFlag(g_eventFlag , -3);
				sceKernelCpuResumeIntr(curIntrState);
			}
		loc_00003CE0:

			if (bits & 0x1)
			{
				sceKernelSetEventFlag(g_eventFlag, 4096);
				g_onesegState = 3;
				sceKernelSetEventFlag(g_eventFlag, 32);
			}
		}
	}while (g_onesegState == 2);
	return (0);
}

// values
// UsbThread
int sub_00003F74() // at 0x00003F74 
{
	//a1 = 2;
	fp = 0;
	int s6 = 1;
	if (g_onesegState != 2){ return(0); }

	int ret;
	uint bits;
	do
	{
		ret = sceKernelWaitEventFlag(g_eventFlag, 39, 1, &bits, 0);
		if (ret < 0)
		{
			Kprintf("%serror - at waiting for event at line %d): ret = 0x%08x pattern = 0x%08x\n", "SceUsb1Seg:", 1746, ret,bits);
			return (ret);
		}
		int curIntrState = sceKernelCpuSuspendIntr();
		if (g_onesegState == 2)
		{
			if (bits & 0x2) == 0)
				goto loc_00004034;
			//t2 = (g_index180 << 2) + (0x00000 + 244 + 188);
			//t1 = *(s32*)(t2);
			t1 = g_lpPcktBufs[g_index180];
			if (*(s32*)(t1 + 0) == 0)
			{
				sceKernelClearEventFlag(g_eventFlag, -3);
				goto loc_00004034;
			}
			do
			{
				t0 = g_lpPcktBuf1;
				if (t0 == 0)
				{
					if (s6 == 0)
					{
						fp = 1;
					}
					break;
				}
				g_lpPcktBuf1 = g_lpPcktBuf1->lpNext;//*(s32*)(t0 + 0);
				if (g_lpPcktBuf1->lpNext)
				{
					g_lpPcktBuf1->lpNext = 0;
				}
				else
				{
					g_lpPcktBuf2 = 0;
				}
				*(s32*)(t0 + 4) = 0;
				a3 = t0 + 16;

				//v0 = (g_index180 << 2) + (0x00000 + 244 + 188);
				//a1 = *(s32*)(v0);
				a1 = g_lpPcktBufs[g_index180];

				//v1 = (g_index180 << 2) + (0x00000 + 244 + 188);
				a2 = g_lpPcktBufs[g_index180] + 16;
				*(s32*)(t0 + 8) = *(s32*)(a1 + 8);
				*(s32*)(t0 + 12) = *(s32*)(a1 + 12);
				t1 = g_lpPcktBufs[g_index180] + 208;
				if ((((g_lpPcktBufs[g_index180] + 16) | (t0 + 16)) & 0x3) == 0)
				{
					do
					{
						*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
						*(s32*)(a3 + 4) = *(s32*)(a2 + 4);
						*(s32*)(a3 + 8) = *(s32*)(a2 + 8);
						*(s32*)(a3 + 12) = *(s32*)(a2 + 12);
						a2 = a2 + 16;
						a3 = a3 + 16;
					} while (a2 != t1);
				}
				else
				{
					v0 = t1;
					do
					{
						asm("lwl        $v1, 3($a2)");
						asm("lwr        $v1, 0($a2)");
						asm("lwl        $a0, 7($a2)");
						asm("lwr        $a0, 4($a2)");
						asm("lwl        $a1, 11($a2)");
						asm("lwr        $a1, 8($a2)");
						asm("lwl        $t1, 15($a2)");
						asm("lwr        $t1, 12($a2)");
						asm("swl        $v1, 3($a3)");
						asm("swr        $v1, 0($a3)");
						asm("swl        $a0, 7($a3)");
						asm("swr        $a0, 4($a3)");
						asm("swl        $a1, 11($a3)");
						asm("swr        $a1, 8($a3)");
						asm("swl        $t1, 15($a3)");
						asm("swr        $t1, 12($a3)");
						a2 += 16;
						a3 += 16;
					} while (a2 != v0);
				}
				if (s6 == 0 && fp)
				{
					fp = 0;
					*(s32*)(t0 + 4) |= 0x1;
				}
				s6 = 0;
				if (g_lpBuf == 0)
				{
					g_lpBuf = g_lpPcktBuf1;
				}
				if (g_lpBufTmp)
				{
					g_lpBufTmp->lpNext = g_lpPcktBuf1;
					t0 = g_lpBufTmp->lpNext;
				}
				g_lpBufTmp = t0;
				g_cb1Arg2++;
				g_num204++;
				sceKernelSetEventFlag(g_eventFlag, 8);
				if (g_num200)
				{
					if ((g_num204< g_num200) == 0)
					{
						sceKernelSetEventFlag(g_eventFlag, 4096);
					}
				}
				if (g_cbUID1 > 0)
				{
					sceKernelNotifyCallback(g_cbUID1, g_cb1Arg2);
				}
				s0 = (g_index180 << 2) + (0x00000 + 244);
				a3 = *(s32*)(s0 + 188);
				*(s32*)(a3 + 0) = 0;
				t4 = ((g_index180 ^ 0x1) << 2) + (0x00000 + 244);
				g_index180 ^= 0x1;
				t3 = *(s32*)(t4 + 188);
			} while (*(s32*)(t3 + 0) != 0);
			sceKernelClearEventFlag(g_eventFlag, -3);
		}
	loc_00004034:
		sceKernelCpuResumeIntr(curIntrState);
		if (bits& 0x1)
		{
			if (g_cbUID1 > 0)
			{
				sceKernelNotifyCallback(g_cbUID1, g_cb1Arg2);
			}
			g_onesegState = 3;
			sceKernelSetEventFlag(g_eventFlag, 32);
		}
	} while (g_onesegState == 2);
	return (ret);
}

// OK
// UsbThread
int sub_000042EC() // at 0x000042EC 
{
	uint bits = 0;
	int ret;

	sceKernelWaitEventFlag(g_eventFlag, 129, 1, &bits, 0);
	if (!(bits & 0x1))
	{
		ret = sub_00001AF8();
		if ((s32)ret < 0)
		{
			sceKernelUnlockMutex(g_mutexID, 1);
			g_onesegState = 0;
			return (ret);
		}
		sceKernelSetEventFlag(g_eventFlag, 512);
	}
	int curIntrState = sceKernelCpuSuspendIntr();
	g_cbUID1 = 0;
	g_cbUID2 = 0;
	g_lpPcktBuf1 = 0;
	g_lpPcktBuf2 = 0;
	g_lpBuf = 0;
	g_lpBufTmp = 0;
	g_cb1Arg2 = 0;

	// 0x00000 + 244 + 136 + 24 = 244 + 160
	if (g_usbReq.retcode > 0)
	{
		sceUsbbdReqCancel(&g_usbReq);
	}
	sceKernelCpuResumeIntr(curIntrState);
	ret = sceKernelWaitEventFlag(g_eventFlag, 37, 1, &bits, 0);
	sceKernelUnlockMutex(g_mutexID, 1);
	g_onesegState = 0;
	return (ret);
}

int UpdateStatProc() // 43F4
{
	Kprintf("%sUpdateStatProc\n", "SceUsb1Seg:");
	int ret = 0x80243006;
	u8	sp[128];

	if (g_deviceReq.retcode <= 0)
	{
		//ret = 0x80243006;
		*(s16*)(sp + 0) = *(u16*)(0x00000 + 244 + 252);
		*(s16*)(sp + 2) = *(u16*)(0x00000 + 244 + 260);
		*(s8*)(sp + 4) = *(u8*)(0x00000 + 244 + 264);
		//*(s8*)(g_lpData + 2) = 248;
		//*(s8*)(g_lpData + 3) = 5;	// size?
		g_lpData[2] = 248;
		g_lpData[3] = 5;
		memcpy(g_lpData + 4, sp, 5);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		
		if (!ret)
		{
			uint bits;
			ret = sceKernelWaitEventFlag(g_eventFlag, 2049, 1, &bits, NULL);
			if (!ret)
			{
				if (bits & 0x800)
				{
					sceKernelClearEventFlag(g_eventFlag, -2049);
					sceKernelSetEventFlag(g_eventFlag, 1024);
				}
				else
				{
					g_onesegState = 0;
				}
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}
	return (ret);
}
