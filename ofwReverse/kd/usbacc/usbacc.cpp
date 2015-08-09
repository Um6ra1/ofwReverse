
int g_createdPoolUID;	// 0x00000 + 240 + 60
UsbDriver g_driver =	// 0x00000 + 164
{
	"USBAccBaseDriver",
	2,
	0x80,
	0x98,	// intp
	NULL,
	NULL,	// confp_hi
	NULL,
	NULL,	// confp
	NULL,
	RecvCtrl,	//0x1340,
	NULL,	//0x1234,
	Attach,	//0x3344,
	Detach,	//0x3388,
	NULL,
	DriverStart,	//0x1514,
	DriverStop,	//0x1900,
	NULL
};

DeviceRequest	g_devReq;	// 8[B]
UsbdDeviceReq	g_usbDevReq;	// 0x00000 + 256
UsbConfiguration g_usbConf[];	// 0x00000 + 2948

UINT32 sceUsbAccGetAuthStat()
{
	curIntCtrlState = sceKernelCpuSuspendIntr();

	a0 = *(u8*)(0x00000 + 307);
	s0 = 0x80243007;
	if (a0 != 0)
	{
		s0 = 0;
		if (sceUsbBus_driver_8A3EB5D2(a0) == 0)
		{	s0 = 0x80243701;	}
	}
	sceKernelCpuResumeIntr(curIntCtrlState);
	return (s0);
}

UINT32 sceUsbAccGetInfo(int *lpBuff) // at 0x00000068 
{
	s2 = 0;
	s0 = lpBuff;
	curIntCtrlState = sceKernelCpuSuspendIntr();
	v1 = 0x00000 + 240;
	if (*(u8*)(v1 + 67) == 0)
	{
		sceKernelCpuResumeIntr(curIntCtrlState);
		return (0x80243007);
	}
	if (sceUsbBus_driver_8A3EB5D2(curIntCtrlState) == 0)
	{
		sceKernelCpuResumeIntr(curIntCtrlState);
		return (0x80243701);
	}
	if (lpBuff)
	{
		t0 = lpBuff + 8/4;
		v0 = (t0 | lpBuff) & (k1 << 11);
		if ((s32)v0 >= 0)
		{
			t1 = 0x00000 + 240;	//DeviceRequest?
			asm("lwl        $v0, 3($t1)");
			asm("lwr        $v0, 0($t1)");
			asm("lwl        $v1, 7($t1)");
			asm("lwr        $v1, 4($t1)");
			asm("swl        $v0, 3($s0)");
			asm("swr        $v0, 0($s0)");
			asm("swl        $v1, 7($s0)");
			asm("swr        $v1, 4($s0)");
		}
	}
	else
	{
		s2 = 0x80243002;
	}
	sceKernelCpuResumeIntr(curIntCtrlState);
	return (s2);
}

sceUsbAcc_internal_2A100C1F(struct UsbdDeviceReq *lpReq)
{
	a2 = *(u8*)(0x00000 + 307);	// 0x00000 + 240 + 67
	a1 = 0x80243007;
	if (a2)
	{
		BYTE *lpData = lpReq.data;

		a1 = 0x80243002;
		if (lpData[3] < 61)
		{
			sceKernelDcacheWritebackRange(lpData, lpReq.size);
			lpReq.endp = 0x00000 + 140;
			lpReq.size = lpData[3] + 4;
			a1 = sceUsbbdReqSend(lpReq);
		}
	}
loc_000001C4:
	return (a1);
}

int RecvCtrl(int arg1, int arg2, struct DeviceRequest *lpDevReq)
{
	static DeviceRequest devReq[] = // 0x00000 + 3084, 0x0C0C
	{
		{0xC1, 0x01, 0x0000, 0x0000, 0x0000},
		{0x41, 0x01, 0x0000, 0x0000, 0x0000},
	};

	g_devReq = *lpDevReq;
	a0 = -1;
	if (arg2 >= 0)
	{
		int i;
		a2 = lpDevReq[0].bmRequestType;
		for (i = 0; i < 2; i ++)
		{
			if (a2 == devReq[i].bmRequestType)
			{
				if (lpDevReq->bRequest == devReq[i].bRequest)
				{
					break;
				}
			}
		}
		if (i != 2)
		{
			if ((int)lpDevReq->bmRequestType < 0)
			{
				s2 = lpDevReq->bRequest;
				if (s2 == 1)
				{
					t6 = *(u16*)(0x00000 + 304);	// 0x00000 + 240 + 64
					if (sceUsbBus_driver_48CCE3C1() == 0)
					{
						s0 = g_usbDevReq.data;
						*(s8*)(s0 + 0) = s2;
					}
					else if (t6 == (t6 & lpDevReq->wValue))
					{
						t7 = g_usbDevReq.data;
						*(s8*)(t7 + 0) = 0;
						sceUsbBus_driver_FBA2072B();
					}
					else
					{
						s0 = g_usbDevReq.data;
						*(s8*)(s0 + 0) = s2;
					}

					g_usbDevReq.size = 1;
					sceKernelDcacheWritebackRange(g_usbDevReq.data, 1);
					sceUsbbdReqSend(&g_usbDevReq);
					a0 = 0;
				}
			}
			else if (lpDevReq.bRequest == 1)
			{
				sceKernelDcacheInvalidateRange(g_usbDevReq.data, 64);
				g_usbDevReq.size = 64;
				v0 = sceUsbbdReqRecv(&g_usbDevReq);
				a0 = 0;
			}
		}
	}
	return (a0);
}

int DriverStart(int size, void *args)
{
	int *lpData;
	UsbData	*lpUsbData;

	// a0 = 0x00000 + 2936
	// (LPCSTR name, int part, int attr, unsigned int size, unsigned int blocks, struct SceKernelFplOptParam *opt)
	int fpl = sceKernelCreateFpl("SceUsbAcc", 1, 256, 368, 1, NULL);	// 368 = 2*184=2*sizeof(UsbData)
	g_createdPoolUID = fpl;
	if (fpl < 0)
	{
		return (-1);
	}
	if (sceKernelTryAllocateFpl(fpl, &lpData) < 0)
	{
		sceKernelDeleteFpl(g_createdPoolUID);
		return(-1);
	}
	lpUsbData = lpData;
	s0 = &g_driver;
	s1 = 0x00000 + 240;
	*(s32*)(s1 + 56) = lpData;
	t2 = lpData + 100/4;
	t4 = lpData + 64/4;//lpUsbData->interfaces.pinterdesc[1];
	t3 = lpData + 84/4;//lpUsbData->interdesc.pendp;
	g_driver.devp_hi = t4;
	g_driver.confp_hi = t3;
	//*(s32*)(s0 + 16) = t4;
	//*(s32*)(s0 + 20) = t3;
	*(s32*)(sp + 0) = t2;
	v0 = sub_00000670(2, t4, t3, t2);	// size, lpDevpHi, lpConfpHi, lpBuff
	t0 = v0 + 20;
	t1 = v0 + 36;
	g_driver.devp = v0;
	g_driver.confp = t0;
	//*(s32*)(s0 + 28) = t0;
	//*(s32*)(s0 + 24) = v0;
	*(s32*)(sp + 0) = t1;
	*(s32*)(sp + 0) = sub_00000670(1, v0, t0, t1);
	*(s32*)(s1 + 0) = 0;
	*(s32*)(s1 + 4) = 0;
	*(s8*)(s1 + 67) = 0;

	a1 = 0x00000 + 128;
	v1 = a1 + 8;
	// EndPoints?
	for (int i = 1; i >= 0; i--)
	{
		*(s32*)(v1 + 0) = 0;
		v1 += 12;
	}

	s2 = 0x00000 + 240;
	g_usbDevReq.endp = a1;
	g_usbDevReq.data = *(s32*)(s2 + 56);
	g_usbDevReq.size = 64;
	g_usbDevReq.func = UsbDevReqComplete;
	g_usbDevReq.retcode = 0;
	g_usbDevReq.unkc = 1;
	g_usbDevReq .unk1c = 0;
	g_usbDevReq.arg = 0;
	g_usbDevReq.recvsize = 0;
	*(s8*)(s2 + 66) = 1;
	sceUsbBus_driver_90B82F55(UsbDevReqComplete);

	return (0);
}

sceUsbAccRegisterType(int a0) // at 0x000004AC 
{
	a2 = 0x00000 + 240;

	v0 = 0x80243001;
	a3 = *(u16*)(a2 + 64);
	if (a3 & a0 == 0)
	{
		*(s16*)(a2 + 64) = a3 | a0;
		v0 = 0;
	}
	return (v0);
}

sceUsbAccUnregisterType(int a0) // at 0x000004E0 
{
	a2 = 0x00000 + 240;

	v0 = 0x80243005;
	a3 = *(u16*)(a2 + 64);
	if (a3 & a0)
	{
		*(s16*)(a2 + 64) = a3 & ~(0 | a0);
		v0 = 0;
	}

	return (v0);
}

int module_start(int argc, LPVOID lpArg)
{
	v0 = sceUsbbdRegister(&g_driver);	// UsbDriver g_driver;
	v1 = 0x00000 + 240;
	a0 = true;
	if (v0 >= 0)
	{
		*(s16*)(v1 + 64) = 0;	
		*(s8*)(v1 + 66) = 0;
		a0 = false;
	}
	return (a0);
}

int module_stop() // at 0x00000558 
{
	return (sceUsbbdUnregister(&g_driver) < 0);
}

int DriverStop(int size, void *args)
{
	sceUsbBus_driver_7B87815D();
	s0 = 0x00000 + 240;
	sceKernelDeleteFpl(g_createdPoolUID);
	*(s8*)(s0 + 66) = 0;
	return (0);
}

int UsbDevReqComplete(int a0)
{
	v1 = 0x00000 + 240;

	if ((*(s32*)(a0 + 24) == 0) && (*(s8*)(v1 + 8) >= 0))
	{
		v0 = *(u8*)(v1 + 9);
		if (v0 == 1)
		{
			t1 = *(s32*)(a0 + 4);
			t0 = 0x00000 + 240;
			asm("lwl        $v1, 3($t1)");
			asm("lwr        $v1, 0($t1)");
			asm("lwl        $a0, 7($t1)");
			asm("lwr        $a0, 4($t1)");
			asm("swl        $v1, 3($t0)");
			asm("swr        $v1, 0($t0)");
			asm("swl        $a0, 7($t0)");
			asm("swr        $a0, 4($t0)");
		}
	}
loc_000005DC:		
	return (v0);
}

int Attach(int speed, void *arg2, void *arg3)
{
	a0 = 0x00000 + 240;
	v0 = *(u8*)(a0 + 67);
	if (!v0)
	{
		*(s8*)(a0 + 67) = 1;
	}
	return (v0);
}

int Detach(int arg1, int arg2, int arg3)
{
	a0 = 0x00000 + 240;
	if (*(u8*)(a0 + 67))
	{
		*(s32*)(a0 + 4) = 0;
		*(s8*)(a0 + 67) = 0;
		*(s32*)(a0 + 0) = 0;

		v1 = 0x00000 + 128;
		v0 = v1 + 8;
		for (int i = 1; i >= 0; i--)
		{
			*(s32*)(v0 + 0) = 0;
			v0 += 12;
		}
	}
	return (v0);
}

//sub_00000670(int a0, int a1, int a2, int a3) // at 0x00000670 
int *GetFullSpeedDevDesc(int size, UsbConfiguration *lpUsbConfDst, UsbConfiguration *lpUSBConf, LPVOID lpBuff)
{
	t0 = a3 + 24;
	v0 = t0 + 12;
	//s3 = a0;
	s2 = a1;
	lpUSBConf->infs = t0;
	
	a1 = v0 + 48;
	t6 = a1;
	t7 = a1 + 32;
	lpUSBConf->infp = v0;
	lpUSBConf->confp = a3;
	lpUSBConf->endp = a1;
	s0 = lpUSBConf->infs;
	s1 = lpUSBConf->infp;

	if (((s2 | t0) & 0x3) == 0)	// Checking alignment?
	{
		for (int i = 0; &g_usbConf[i] != &g_usbConf[1]; i++)
		{
			lpUsbConfDst[i] = g_usbConf[i];
		}
		lpUsbConfDst[i].confp = g_usbConf[i].confp;
	}
	else
	{
		t0 = &g_usbConf[0];
		t1 = &g_usbConf[1];
		a2 = lpUsbConfDst;
		do{
			asm("lwl        $v1, 3($t0)");
			asm("lwr        $v1, 0($t0)");
			asm("lwl        $a0, 7($t0)");
			asm("lwr        $a0, 4($t0)");
			asm("lwl        $a1, 11($t0)");
			asm("lwr        $a1, 8($t0)");
			asm("lwl        $a3, 15($t0)");
			asm("lwr        $a3, 12($t0)");

			asm("swl        $v1, 3($a2)");
			asm("swr        $v1, 0($a2)");
			asm("swl        $a0, 7($a2)");
			asm("swr        $a0, 4($a2)");
			asm("swl        $a1, 11($a2)");
			asm("swr        $a1, 8($a2)");
			asm("swl        $a3, 15($a2)");
			asm("swr        $a3, 12($a2)");
			t0 += 16;
			a2 += 16;
		} while (t0 != t1);

		asm("lwl        $v0, 3($t0)");
		asm("lwr        $v0, 0($t0)");
		asm("swl        $v0, 3($a2)");
		asm("swr        $v0, 0($a2)");
	}

	t8 = a3;
	a1 = 0x00000 + 2968;	// b98
	*(s32*)(t8 + 0) = *(s32*)(a1 + 0);
	*(s32*)(t8 + 4) = *(s32*)(a1 + 4);
	*(s32*)(t8 + 8) = *(s32*)(a1 + 8);
	*(s32*)(t8 + 12) = *(s32*)(a1 + 12);
	*(s32*)(t8 + 16) = *(s32*)(a1 + 16);
	*(s32*)(t8 + 20) = *(s32*)(a1 + 20);

	a2 = 0x00000 + 2992;	// bb0
	*(s32*)(s0 + 0) = *(s32*)(a2 + 0);
	*(s32*)(s0 + 4) = *(s32*)(a2 + 4);
	*(s32*)(s0 + 8) = *(s32*)(a2 + 8);

	UsbConfiguration usbConfigs[] =	// 0x00000 + 3004, 0x0BBC
	{
		{ 0x00000409, 0x0000FF01, 0x00000001, 0x00000000 },
		{ 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
		{ 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
	};

	t9 = t5 + 48;
	UsbConfiguration	*lpUsbConfigs = lpUSBConf->infp;

	for (int i = 0; i < 3; i++)
	{
		lpUsbConfigs[i] = usbConfigs[i];	// struct size :4x4
	}

	t0 = 0x00000 + 3052;	//bec
	*(s32*)(t6 + 0) = *(s32*)(t0 + 0);	// 0x03810507, other is 0
	*(s32*)(t6 + 4) = *(s32*)(t0 + 4);
	*(s32*)(t6 + 8) = *(s32*)(t0 + 8);
	*(s32*)(t6 + 12) = *(s32*)(t0 + 12);
	*(s32*)(t6 + 16) = *(s32*)(t0 + 16);
	*(s32*)(t6 + 20) = *(s32*)(t0 + 20);
	*(s32*)(t6 + 24) = *(s32*)(t0 + 24);
	*(s32*)(t6 + 28) = *(s32*)(t0 + 28);

	*(s32*)(t8 + 12) = s0;
	*(s32*)(s0 + 0) = s1;
	*(s32*)(s1 + 12) = t6;
	*(s8*)(s2 + 7) = 64;
	*(s16*)(t6 + 4) = 64;

	*(s8*)(t6 + 6) = (size == 2) ? 7 : 8;
	return (t7);
}

