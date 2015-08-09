
/*
IMPORT_FUNC "ThreadManForUser",0x6B30100F,sceKernelUnlockMutex
IMPORT_FUNC "ThreadManForUser",0xB011B11F,sceKernelLockMutex
IMPORT_FUNC "SysclibForKernel",0x10F3BB61,memset
IMPORT_FUNC "SysclibForKernel",0xAB7592FF,memcpy
PSP_EXPORT_FUNC_NID(sceClockgenSetSpectrumSpreading, 0xC9AF3102)
*/

UINT32 sceUsb1SegConstruct(UINT8 a0, int *a1, int fp, int a3);
UINT32 sceUsb1SegDestruct();
UINT32 sceUsb1SegPutPacketBuffer(int a0);
UINT32 sceUsb1SegGetPacketBuffer(int a0);
UINT32 sceUsb1SegScanCh(int *a0);
UINT32 sceUsb1SegGetModule(int a0);
UINT32 sceUsb1SegSetEncKey(int a0);
UINT32 sceUsb1SegGetDebug(int *a0, int a1);
UINT32 sceUsb1SegSetDebug(int a0, int a1);
UINT32 sceUsb1SegSetPwm(int a0);
UINT32 sceUsb1SegGetReg(int a0, int a1, int a2, int a3);
UINT32 sceUsb1SegSetReg(int a0, int a1, int a2);

int sub_00002CEC_geterrcode(int *a0);	// GetError?

// a function comes from a syscall, $k1 = 0x100000 by interruptmgr
// 0+224+228 : threadEntry

typedef struct ps_packet_{
	uint8_t scr[6];
	uint8_t mux_rate[3];
	uint8_t stuff_length;
	uint8_t *data;
	uint8_t sheader_llength[2];
	int sheader_length;
	uint8_t rate_bound[3];
	uint8_t audio_bound;
	uint8_t video_bound;
	uint8_t reserved;
	int npes;
} ps_packet;	// 30 bytes

int	g_bStarted;	// 0x00000 + 244 + 0
int	g_bAttached;	// 0x00000 + 244 + 4

static UsbdDeviceReq g_deviceReq;	// 0 + 244 + 40
void	*g_lpData;	// 0 + 244 + 80
/* Static bulkin request structure */
static UsbdDeviceReq g_bulkinReq;	// 0 + 244 + 92
/* Static bulkout request structure */
static UsbdDeviceReq g_bulkoutReq;	// 0 + 244 + 132
// 0 + 244 + 136
/* Async request */
static UsbdDeviceReq g_asyncReq;	// 0 + 244 + 172

int	g_eventFlag;	// 0x00000 + 244 + 232
int g_poolUID;	// 0x00000 + 244 + 236
int	g_mutexID;	// 0x00000 + 244 + 240
int	g_threadID;	// 0x00000 + 244 + 228

SceUID	g_cbUID;	// 0x00000 + 244 + 244

UINT32 sceUsb1SegConstruct(s8 a0, int *a1, int *a2, int a3)//(num, *kp, uid1, uid2)
{
	v1 = 0x00000 + 244;

	k1	= pspSdkGetK1();
	pspSdkSetK1(k1 << 11);	// 0x100000 -> 0x80000000

	t0 = 0x80244502;
	if (g_bStarted == 0)
		goto loc_000000C4;
	t0 = 0x80244503;
	if (g_bAttached == 0)
		goto loc_000000C4;
	t0 = 0x80244505;
	if (a0 - 13 >= 50)
		goto loc_000000C4;
	t0 = 0x80244507;
	if (((a1 + 17) | a1) & (k1 << 11) < 0)	// filter out unauthorised address(user mode addr), pspK1StaBufOk(a1, 17)
		goto loc_000000C4;
	t0 = 0x80244505;
	if ((*(u8*)(a1 + 0) >= 64) )
		goto loc_000000C4;

	if (a2 > 0)
	{
		SceKernelIdListType type = sceKernelGetThreadmanIdType(a2);
		t0 = 0x80244504;
		if (type != 8)	// 8 == SCE_KERNEL_TMID_Callback
		{
			goto loc_000000C4;
		}
	}

	if (a3 > 0)
	{
		// Get Threadman UID type
		v0 = sceKernelGetThreadmanIdType(a3);	// uid
		t0 = 0x80244504;
		if (v0 != 8)
			goto loc_000000C4;
	}

//loc_00000120:
	s6 = 0x00000 + 244;
	curIntCtrlState = sceKernelCpuSuspendIntr();
	*(s8*)(s6 + 20) = a0;
	g_cbUID = a2;	// cb
	*(s32*)(s6 + 248) = a3;
	s1 = a1;

	asm("lwl        $v0, 3($s1)");
	asm("lwr        $v0, 0($s1)");	// base
	asm("lwl        $v1, 7($s1)");
	asm("lwr        $v1, 4($s1)");
	asm("lwl        $a1, 11($s1)");
	asm("lwr        $a1, 8($s1)");
	asm("lwl        $a2, 15($s1)");
	asm("lwr        $a2, 12($s1)");

	asm("swl        $v0, 24($s6)");	// s1[0]
	asm("swr        $v0, 21($s6)");
	asm("swl        $v1, 28($s6)");	// s1[1]
	asm("swr        $v1, 25($s6)");
	asm("swl        $a1, 32($s6)");	// s1[2]
	asm("swr        $a1, 29($s6)");
	asm("swl        $a2, 36($s6)");	// s1[3]
	asm("swr        $a2, 33($s6)");

	*(s8*)(s6 + 37) = *(s8*)(a1 + 16);
	*(s32*)(s6 + 196) = 0;
	*(s32*)(s6 + 200) = 0;
	*(s32*)(s6 + 204) = 0;
	*(s32*)(s6 + 208) = 0;
	*(s32*)(s6 + 212) = 0;
	*(s32*)(s6 + 216) = 0;
	*(s32*)(s6 + 220) = 0;
	*(s32*)(s6 + 224) = 0;
	sceKernelCpuResumeIntr(curIntCtrlState);
	*(s32*)(s6 + 12) = 1;
	*(s32*)(s6 + 16) = 0;

	int bits;
	sceKernelClearEventFlag(g_eventFlag, -28961);	// (evID, bits)
	sceKernelSetEventFlag(g_eventFlag, 0x10);	// (evID, bits)
	t0 = sceKernelWaitEventFlag(g_eventFlag, 261, PSP_EVENT_WAITOR, &bits, 0);	// (evID, bits, wait, outBits, timeOut)

	if (t0 < 0)	// on error
		goto loc_000000C4;
	t0 = 0x80244503;
	if (!(bits & 0x1))
	{
		t0 = 0x80244509;
		if (!(bits & 0x4))
		{	t0 = *(s32*)(s6 + 16);	}
	}
	pspSdkSetK1(k1);
	return(t0);

loc_000000C4:	// on error exit
	a0 = 0x00000 + 244;
	*(s32*)(a0 + 248) = 0;
	pspSdkSetK1(k1);
	g_cbUID = 0;	//cbUID
	return (t0);
}

UINT32 sceUsb1SegDestruct()
{
	UINT32	k1;
	int bits;

	s2 = 0x00000 + 244;
	s0 = 0x80244506;

	v0 = *(s32*)(s2 + 12);
	if (v0 == 2)
	{
		k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);

		curIntCtrlState = sceKernelCpuSuspendIntr();
		*(s32*)(s2 + 12) = 3;
		sceKernelSetEventFlag(g_eventFlag, 0x4002);
		sceKernelCpuResumeIntr(curIntCtrlState);
		v0 = sceKernelWaitEventFlag(g_eventFlag, 0x201, 1, &bits, 0);

		if (!v0)
		{
			if (((bits & 0x1) == 0))
			{
				v0 = sceKernelClearEventFlag(g_eventFlag, -513);
			}
			else
			{
				v0 = 0x80244503;
			}
		}
		pspSdkSetK1(k1);
	}

	return (v0);
}

typedef struct _PACKET_BUF
{
	_PACKET_BUF	*lpNext;
	UINT32	unk[51];	// 208 / 4 - 1
} PACKET_BUF;

UINT32 sceUsb1SegPutPacketBuffer(int *a0)	// (*_PACKET_BUF)
{
	v1 = 0x00000 + 244;
	s1 = 0;
	s0 = 0;

	if (!g_bStarted)
	{
		return (0x80244502);
	}
	if (!g_bAttached)
	{
		return (0x80244503);
	}
	if (a0 == NULL)
	{
		return (0x80244507);
	}

	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	curIntCtrlState = sceKernelCpuSuspendIntr();
	v1 = a0;
	do
	{
		a1 = ((v1 + 208) | v1) & (k1 << 11);	// pspK1StaBufOk(v1, 208)
		if ((s32)a1 < 0)	// Above is not 
		{
			if (v1 == 0)
			{	break;	}
			sceKernelCpuResumeIntr(curIntCtrlState);
			pspSdkSetK1(k1);
			return (0x80244507);
		}
		t0 = *(s32*)(v1 + 0);
		if (t0 == 0)	{	s1 = v1;	}
		v1 = t0;
	} while (t0);

	if (*(s32*)(0x00000 + 244 + 208))
	{
		*(s32*)(*(s32*)(0x00000 + 244 + 212) + 0) = a0;
		v0 = *(s32*)(a0 + 0);
		v1 = a0;
		if (v0)
		{
			for (a1 = v0; *(s32*)(a1 + 0); a1 = t3);
			v1 = a1;
		}
		*(s32*)(0x00000 + 244 + 212) = v1;
	}
	else
	{
		*(s32*)(0x00000 + 244 + 212) = s1;
		*(s32*)(0x00000 + 244 + 208) = a0;
	}

	sceKernelCpuResumeIntr(curIntCtrlState);
	pspSdkSetK1(k1);
	return (s0);
}

UINT32 sceUsb1SegGetPacketBuffer(int *a0)
{
	s3 = 0x00000 + 244;
	v0 = 0x80244502;
	if (g_bStarted)
	{
		k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);

		v1 = (k1 << 11) & a0;	// pspK1PtrOk(a0)
		v0 = 0x80244503;
		if (g_bAttached)
		{
			v0 = 0x80244507;

			if (v1 >= 0)	// pspK1PtrOk(a0)
			{
				curIntCtrlState = sceKernelCpuSuspendIntr();
				if (v0 = *(s32*)(s3 + 216))
				{
					*(s32*)(a0 + 0) = v0;
					*(s32*)(s3 + 220) = 0;
					*(s32*)(s3 + 216) = 0;
				}
				else
				{	*(s32*)(a0 + 0) = 0;	}

				*(s32*)(s3 + 196) = 0;
				sceKernelClearEventFlag(g_eventFlag, -9);
				sceKernelCpuResumeIntr(curIntCtrlState);
				v0 = *(s32*)(v1 + 196);	// correct?
			}
		}
		pspSdkSetK1(k1);
	}
	return (v0);
}

UINT32 sceUsb1Seg_F565757F(int a0) // at 0x000004F4 - Aliases: sceUsb1SegGetPacketBufferBlocking
{
	UINT	bits;
	s2 = 0x00000;

	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	s1 = s2 + 244;

	s0 = 0x80244502;
	if (g_bStarted == 0)
		goto loc_00000570;
	s0 = 0x80244503;
	if (g_bAttached == 0)
		goto loc_00000570;
	s0 = 0x80244506;
	if (*(s32*)(s1 + 12) - 1 >= 2)
		goto loc_00000570;
	s0 = 0x80244507;
	if ((s32)((k1 << 11) & a0) < 0)
		goto loc_00000570;

	sceKernelClearEventFlag(g_eventFlag, -8193);
	s0 = sceKernelWaitEventFlag(g_eventFlag, 8233, 1, &bits, NULL);
	if ((s32)v0 >= 0)
	{
		s0 = 0x80244503;
		if (bits & 0x1 == 0)
		{
			s0 = 0x8024450C;
			if (bits & 0x8024450C == 0)	// 1000:0000:0010:0100::0100:0101:0000:1100
			{
				s0 = 0x80244506;
				if (bits & 0x20 == 0)
				{
					curIntCtrlState = sceKernelCpuSuspendIntr();
					if (v0 = *(s32*)(s1 + 216))
					{
						*(s32*)(a0 + 0) = v0;
						*(s32*)(s1 + 220) = 0;
						*(s32*)(s1 + 216) = 0;
					}
					else
					{	*(s32*)(a0 + 0) = 0;	}

					s1 = s2 + 244;
					s0 = *(s32*)(s1 + 196);
					*(s32*)(s1 + 196) = 0;
					sceKernelClearEventFlag(g_eventFlag, -9);
					sceKernelCpuResumeIntr(curIntCtrlState);
				}
			}
		}
	}
loc_00000570:
	pspSdkSetK1(k1);
	return (s0);
}

//405:sceUsb1Seg_8BEBA10E
UINT32 sceUsb1Seg_FF784FF5(int a0, int a1) // (*ptr, count) - Aliases: sceUsb1Seg_driver_FF784FF5
{
	s4 = k1;
	k1 = k1 << 11;
	s2 = 0x00000;
	s1 = 0x00000 + 244;

	s0 = 0x80244502;
	if (g_bStarted == 0)
		goto loc_000006DC;
	s0 = 0x80244503;
	if (g_bAttached == 0)
		goto loc_000006DC;
	s0 = 0x80244506;
	if (((s1 + 12) - 1) >= 2)
		goto loc_000006DC;
	s0 = 0x80244507;
	if ((k1 & a0) < 0)
		goto loc_000006DC;

	curIntCtrlState = sceKernelCpuSuspendIntr();
	*(s32*)(s1 + 200) = a1;
	sceKernelCpuResumeIntr(curIntCtrlState);
	sceKernelClearEventFlag(g_eventFlag, -8193);
	s0 = sceKernelWaitEventFlagCB(g_eventFlag, 12321, 1, sp, 0);
	if ((s32)s0 < 0)
		goto loc_000006DC;
	v1 = *(s32*)(sp + 0);
	
	if (v1 & 0x1)
	{
		s0 = 0x80244503;
		goto loc_000006DC;
	}
	if (v1 & 0x2000)
	{
		s0 = 0x8024450C;
		goto loc_000006DC;
	}
	if (v1 & 0x20)
	{
		s0 = 0x80244506;
		goto loc_000006DC;
	}
	if (v1 & 0x1000 == 0)
		goto loc_000006DC;

//	t9 = *(s32*)(s1 + 12);
	s7 = *(s32*)(s1 + 216);
	s0 = 0x80244506;
	if (*(s32*)(s1 + 12) == 2)
	{
		curIntCtrlState = sceKernelCpuSuspendIntr();
		s0 = 0;
		if (a1)//else
		{
			do
			{
				v1 = *(s32*)(s7 + 0);
				if (v1 == 0)	{	break;	}
				s0 = ++;
				s7 = v1;
			} while ((u32)s0 < a1);
		}
		s1 = 0x00000 + 244;
		*(s32*)(a0 + 0) = *(s32*)(s1 + 216);
		s2 = *(s32*)(s7 + 0);
		s0 ++;
		*(s32*)(s1 + 204) = *(s32*)(s1 + 204) - s0;
		*(s32*)(s1 + 216) = s2;
		if (s2 == 0)
		{
			*(s32*)(s1 + 220) = 0;
			sceKernelClearEventFlag(g_eventFlag, -9);
		}
		*(s32*)(s7 + 0) = 0;
		sceKernelClearEventFlag(g_eventFlag, -4097);
		sceKernelCpuResumeIntr(curIntCtrlState);
	}
loc_000006DC:
	k1 = s4;
	return (s0);
}

//405:sceUsb1Seg_1FA7839B
UINT32 sceUsb1Seg_10621E6B() // at 0x00000840 - Aliases: sceUsb1Seg_driver_10621E6B
{
	UINT32	ret = 0;

	v0 = 0x00000 + 244;
	if (*(s32*)(v0 + 4))
	{
		UINT32	k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);
		sceKernelSetEventFlag(g_eventFlag, 8192);
		pspSdkSetK1(k1);
	}
	else
	{
		ret = 0x80244503;
	}

	return (ret);
}

//405:sceUsb1Seg_97551142
UINT32 sceUsb1Seg_09F9D06D(int a0, int a1) // (*ptr, count) - Aliases: sceUsb1Seg_driver_09F9D06D
{
	s4 = k1;
	k1 = k1 << 11;
	s1 = 0;
	a2 = g_bStarted;
	v1 = 0x00000 + 244;

	if (!a2)
	{
		s1 = 0x80244502;
		goto loc_000008F0;
	}
	if (g_bAttached)
	{
		if (*(s32*)(v1 + 12) - 1 < 2)
		{
			if (*(s32*)(v1 + 224))
			{
				s1 = 0x8024450D;
				goto loc_000008F0;
			}
			if ((s32)(k1 & a0) >= 0)
			{
				curIntCtrlState = sceKernelCpuSuspendIntr();
				
				//if (a1 == 0 && 0 >= a1)
				//{	goto loc_000009BC;	}
				if (a1 > 0)
				{
					int	*p = a0;
					for (int i = 0; i < a1; i++)
					{
						v0 = p[20/4];
						t9 = p[16/4];
						t7 = ((v0 + t9) | v0) | t9;
						if ((s32)(k1 & t7) < 0)
						{
							s1 = 0x80244507;
							if (i >= a1)
							{
								break;
							}
						}
						p += 24/4;
						v0 = p[20/4];
					}
				}
			//loc_000009BC:
				s0 = 0x00000 + 244;
				v0 = sceKernelSetEventFlag(g_eventFlag, 16384);
				*(s32*)(s0 + 200) = a1;
				*(s32*)(s0 + 224) = a0;
				*(s32*)(s0 + 204) = 0;

				sceKernelCpuResumeIntr(s5);
			}
			s1 = 0x80244507;
		}
		s1 = 0x80244506;
	}
	else
	{
		s1 = 0x80244503;
	}

loc_000008F0:
	k1 = s4;
	return (s1);
}

//405:sceUsb1Seg_25D5563F
UINT32 sceUsb1Seg_49FAA242() // at 0x00000A10 - Aliases: sceUsb1Seg_driver_49FAA242
{
	s1 = 0x00000 + 244;
	a0 = 0x80244502;

	s0 = k1;
	k1 = k1 << 11;
	
	if (g_bStarted)
	{
		a0 = 0x80244503;
		if (g_bAttached)
		{
			a0 = 0x80244506;
			if ((u32)(*(s32*)(s1 + 12) - 1) < 2)
			{
				int bits;

				a0 = sceKernelWaitEventFlagCB(g_eventFlag, 12321, 1, &bits, 0);
				if ((s32)a0 >= 0)
				{
					if (bits & 0x1)
					{
						a0 = 0x80244503;
					}
					else if (bits & 0x2000)
					{
						a0 = 0x8024450C;
					}
					else if (bits & 0x20)
					{
						a0 = 0x80244506;
					}
					else if (bits & 0x1000)
					{
						sceKernelClearEventFlag(g_eventFlag, -4097);
						a0 = *(s32*)(s1 + 204);
					}
				}
			}
		}
	}

	k1 = s0;
	return (a0);
}

//405:sceUsb1Seg_406AE298
UINT32 sceUsb1Seg_AA2BE2BD() // at 0x00000B04 - Aliases: sceUsb1Seg_driver_AA2BE2BD
{
	a0 = 0x00000 + 244;

	s1 = k1;
	k1 = k1 << 11;

	s0 = 0;
	if (g_bStarted)
	{
		if (g_bAttached)
		{
			if (a2 != 0)
			{
				t0 = *(s32*)(a0 + 12);
				a3 = t0 - 1;
				sceKernelSetEventFlag(g_eventFlag, 8192, a3 < 2, a3, t0);
			}
			else
			{
				s0 = 0x80244506;
			}
		}
		else
		{
			s0 = 0x80244503;
		}
	}
	else
	{
		s0 = 0x80244502;
	}
	
	k1 = s1;
	return (s0);
}

UINT32 sceUsb1SegScanCh(int *a0)	// 8bytes struct?
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	v0 = (a0 | (a0 + 8)) & k1;
	UINT32	ret = 0x80244503;
	if (g_bAttached)
	{
		ret = 0x80244507;
		if ((s32)v0 >= 0)
		{
			ret = sub_00001C80(sp);
			if (ret == 0)
			{
				*(s32*)(a0 + 0) = *(s32*)(sp + 0);
				*(s32*)(a0 + 4) = *(s32*)(sp + 4);
			}
		}
	}
	pspSdkSetK1(k1);
	return (ret);
}

UINT32 sceUsb1SegGetModule(int a0)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	int ret = 0x80244503;
	if (g_bAttached)
	{
		ret = 0x80244507;
		if ((s32)(((a0 + 1) | a0) & (k1 << 11)) >= 0)
		{
			ret = sub_00001DD0(a0);
		}
	}	
	pspSdkSetK1(k1);
	return (ret);
}

UINT32 sceUsb1SegSetEncKey(int a0)
{
	k1	= pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	
	a2 = 0x80244503;
	if (g_bAttached)
	{
		if ((s32)(((a0 + 17) | a0) & (k1 << 11)) >= 0)
		{
			a2 = sub_00001E94(a0);
		}
		else{ a2 = 0x80244507; }
	}
	pspSdkSetK1(k1);
	return (a2);
}


//405:sceUsb1Seg_D799104F
UINT32 sceUsb1Seg_6B12C11E(int *a0) // at 0x00000CF4 - Aliases: sceUsb1Seg_driver_6B12C11E
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	a2 = 0x80244503;
	if (g_bAttached)
	{
		a2 = 0x80244507;
		if ((s32)(((a0 + 2) | a0) & (k1 << 11);) >= 0)
		{
			a2 = sub_00001FF0(a0);
		}
	}
	pspSdkSetK1(k1);
	return (a2);	
}

UINT32 sceUsb1SegGetDebug(int *a0, int a1)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	t0 = 0x80244503;
	if (g_bAttached)
	{
		t0 = 0x80244507;
		if ((s32)((k1 << 11) & (((a0 + a1) | a0) | a1;);) >= 0)
		{
			t0 = sub_000020B4(a0, a1);
		}
	}
	pspSdkSetK1(k1);
	return (t0);
}

UINT32 sceUsb1SegSetDebug(int a0, int a1)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	t0 = 0x80244503;
	if (g_bAttached)
	{
		t0 = 0x80244507;
		if ((s32)((k1 << 11) & (((a0 + a1) | a0) | a1)) >= 0)
		{
			t0 = sub_00002184(a0, a1);
		}
	}

	pspSdkSetK1(k1);
	return (t0);
}

UINT32 sceUsb1SegSetPwm(int *a0)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	a2 = 0x80244503;
	if (g_bAttached)
	{
		a2 = 0x80244507;
		if ((s32)(((a0 + 2) | a0) & (k1 << 11)) >= 0)
		{
			a2 = sub_000022A4(a0);
		}
	}

	pspSdkSetK1(k1);
	return (a2);
}

UINT32 sceUsb1SegGetReg(int *a0, int *a1, int a2, int a3)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	t3 = 0x80244503;
	if (g_bAttached)
	{
		t3 = 0x80244507;
		if ((int)((k1 << 11) & (((a1 + a3) | a1) | a3)) >= 0)
		{
			t3 = 0x80244507;
			if ((s32)((k1 << 11) & (((a2 + t0) | a2) | t0)) >= 0)
			{
				t3 = sub_000023A8(a0, a1, a2, a3);
			}
		}
	}
	pspSdkSetK1(k1);
	return (t3);
}

UINT32 sceUsb1SegSetReg(int *a0, int *a1, int size)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	t1 = 0x80244503;
	if (g_bAttached)
	{
		t1 = 0x80244507;
		if ((s32)((k1 << 11) & (a1 | size | (a1 + size))) >= 0)
		{
			t1 = sub_00002518(a0, a1, size);
		}
	}
	pspSdkSetK1(k1);
	return (t1);
}

sceUsb1SegEEPROMUpdate(int a0, int a1, int a2, int a3)
{
	s0 = k1;
	k1 = k1 << 11;

	t2 = 0x80244503;
	if (g_bAttached)
	{
		t2 = 0x80244507;
		if ((s32)(k1 & (((a3 + a1) | a3) | a1);) >= 0)
		{
			t2 = sub_0000263C(a0, a1, a2, a3);
		}
	}
	k1 = s0;
	return (t2);
}

sceUsb1SegEEPROMParamChange(int a0, int a1, int a2)
{
	s0 = k1;
	k1 = k1 << 11;

	a3 = 0x80244503;
	if (g_bAttached)
	{
		if ((u32)a0 >= 256)
		{
			a3 = 0x80244505;
		}
		else if ((u32)a1 >= 256;)
		{
			a3 = 0x80244505;
		}
		else if ((u32)a2 < 256;)
		{
			a3 = sub_00002934(a0, a1, a2);
		}
		else
		{
			a3 = 0x80244505;
		}
	}

	k1 = s0;
	return (a3);
}

sceUsb1SegEEPROMParamWrite()
{
	s0 = k1;
	k1 = k1 << 11;

	v0 = 0x80244503;

	if (g_bAttached)
	{
		v0 = sub_0000276C();
	}
	k1 = s0;

loc_000010A8:
	return (v0);
}

sceUsb1SegEEPROMParamRead(int *a0, int size)
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);

	v1 = (a0 + a1) | a0 | a1;

	t0 = 0x80244503;
	if (g_bAttached)
	{
		t0 = 0x80244507;
		if ((s32)((k1 << 11) & v1) >= 0)
		{
			t0 = sub_00002838(a0, a1);
		}
	}
	pspSdkSetK1(k1);
	return (t0);	
}

//405:sceUsb1Seg_CA800628
UINT32 sceUsb1Seg_D3ED2AFE(int a0, int a1, int a2) // at 0x00001134 - Aliases: sceUsb1Seg_driver_D3ED2AFE
{
	s0 = k1;
	k1 = k1 << 11;

	t0 = 0x80244503;
	if (g_bAttached)
	{
		t0 = 0x80244588;
		if ((u32)a2 < 61)
		{
			t0 = 0x80244507;
			t1 = ((a1 + a2) | a1) | a2;
			if ((s32)(k1 & t1) >= 0)
			{
				t0 = sub_00002A58(a0 & 0xFFFF, a1, a2);
			}
		}
	}
	k1 = s0;
	return (t0);
}

//405:sceUsb1Seg_C9A04D0D
UINT32 sceUsb1Seg_57475AF7(int a0, int a1, int a2) // at 0x000011B4 - Aliases: sceUsb1Seg_driver_57475AF7
{
	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	
	UINT32 ret = 0x80244503;
	if (g_bAttached)
	{
		ret = 0x80244588;
		if (a2 < 61)
		{
			ret = 0x80244507;
			t1 = ((a1 + a2) | a1) | a2;
			if ((s32)((k1 << 11) & t1) >= 0)
			{
				ret = sub_00002BB8(a0 & 0xFFFF, a1, a2);
			}
		}
	}
	pspSdkSetK1(k1);
	return (ret);
}

int Func28(int arg1, int arg2, int arg3)
{
	if (arg1 == 0)
	{
		if (arg2 == 0)
		{
			s1 = 0x00000 + 244;
			sceKernelClearEventFlag(g_eventFlag, -75);
			v0 = sceKernelSetEventFlag(g_eventFlag, 32);
		}
		else
		{
			v1 = 0x00000 + 244;
			g_asyncReq.unkc = 0;
			g_asyncReq.size = 0;

			int *p = v1 + 188/4;
			for (int i = 1; i >= 0; i--)
			{
				v0 = p[0];
				*(s32*)(v0 + 0) = 0;
				memset(v0 + 16, 0, 192);	// what is this size?
				p ++;
			}

			*(s32*)(v1 + 12) = 2;
			sceKernelClearEventFlag(g_eventFlag, -33);
			sceKernelSetEventFlag(g_eventFlag, 64);
			sceKernelDcacheInvalidateRange(g_asyncReq.data, 384);	// (ptr, size)
			v0 = sceUsbbdReqRecv(g_bulkoutReq.data);
	
			if ((s32)v0 < 0)
			{
				//a0 = 0x00000 + 19260;
				//	a1 = 0x00000 + 19292;
				Kprintf("%serror - ReqRecv() : 0x%08x", "SceUsb1Seg:", v0);
			}
		}
		a0 = 0x00000 + 244;
		*(s32*)(a0 + 8) = arg2;
	}
	return(v0);
}

// lost v1
int RecvCtrl(int arg1, int arg2, struct DeviceRequest *lpDevReq)
{
	t2 = lpDevReq;
	s0 = 0x00000 + 336;
	if (arg2 < 0)
	{ return(-1); }

	//v0 = lpDevReq->wValue;
	//v1 = lpDevReq->wIndex;
	asm("lwl        $v0, 3($a2)");
	asm("lwr        $v0, 0($a2)");
	asm("lwl        $v1, 7($a2)");
	asm("lwr        $v1, 4($a2)");
	asm("swl        $v0, -5($s0)");
	asm("swr        $v0, -8($s0)");
	asm("swl        $v1, -1($s0)");
	asm("swr        $v1, -4($s0)");
	
	t0 = lpDevReq->bmRequestType;//*(u8*)(a2 + 0) & 0xFF;
	t1 = lpDevReq->bRequest;//*(u8*)(t2 + 1) & 0xFF;

	a0 = 0x00000 + 20376;	// 0x4F98
	a1 = 0;

loc_0000139C:		
	a3 = *(u8*)(a0 + 0);
	if (t0 == a3)
	{
		t3 = *(u8*)(a0 + 1);
		if (t1 != t3)
		{
			a1 ++;
			goto loc_000013AC;
		}
		a0 = 20;
		goto loc_000013BC;
	}
	a1 ++;

loc_000013AC:
	a0 += 8;
	if ((u32)a1 < 20)
		goto loc_0000139C;
	a0 = 20;

loc_000013BC:		
	t0 = (s8)a2;
	if (a1 == a0)
	{
		//a1 = 0x00000;
		//a0 = a1 + 19444;
		//v0 = 0x00000;
		//a1 = v0 + 19292;
		Kprintf("%sUnknown device request: bmRequestType = 0x%02x, bRequest = 0x%02x, wLength = %d\n", "SceUsb1Seg:", a2 & 0xFF, v1 & 0xFF, lpDevReq->wLength);		//a2=bmRequestType, v1=bRequest, *(t2+6)=wLength
		return(-1);
	}
	if ((s32)t0 < 0)
	{
		if (v1 & 0xFF != 248)
		{	return(0);	}
		if (lpDevReq->wLength == 0)
		{	return(0);	}
		t5 = 0x00000 + 244;
		t8 = *(s32*)(t5 + 268);
		*(s32*)(t5 + 268) = t8 + lpDevReq->wLength;
		*(s32*)(s0 + 4) = t8 + *(s32*)(t5 + 256);
		*(s32*)(s0 + 8) = lpDevReq->wLength;
		sceKernelDcacheWritebackRange(lpDevReq, lpDevReq->wLength);	// data, size
		v0 = sceUsbbdReqSend(s0);
		//a0 = 0x00000 + 19396;
		if ((s32)v0 >= 0)
		{	return(0);	}
		goto loc_00001444;
	}
	v1 &= 0xFF;
	a0 = v1 - 243;
	v0 = (u32)a0 < 13;

	if ((s32)v1 < 11;)
	{
		t3 = (s32)v1 < 8;
		v0 = (u32)(v1 - 3) < 3;
		if (t3 == 0)
			goto loc_000013F8;
	}
	if (v0 == 0)
//	if ((u32)a0 >= 13)
	{
		//a0 = 0x00000 + 19304;	//(0x4B68)
		//a1 = 0x00000 + 19292;
		Kprintf("%sRecv Unknown Req in Devreq\n", "SceUsb1Seg:");
		return(-1);
	}
	goto loc_000013F8;

loc_000013F8:
	*(s32*)(s0 + 4) = *(s32*)(0x00000 + 376);
	*(s32*)(s0 + 8) = lpDevReq->wLength;
	sceKernelDcacheInvalidateRange(t0, 128);
	v0 = sceUsbbdReqRecv(s0);
	if ((s32)v0 >= 0)
	{	return (0);	}

loc_00001444:
	//a0 = 0x00000 + 19336;
	//a1 = 0x00000 + 19292;
	//a2 = 0x00000 + 19384;
	Kprintf("%sint %s: Cannot isuue recv request: 0x%08x\n", "SceUsb1Seg:", "DevReqHdlr", v0);
	return(0);
}

int DriverStart(int size, void *args)	// 0x1514
{
	int	*lpData = NULL;

	s0 = 0x00000 + 244;
	//a0 = 0x00000 + 19528;
	//*(s32*)(s0 + 240) = -1;
	g_mutexID = -1;
	g_threadID = -1;
	g_poolUID = -1;
	g_eventFlag = -1;
	g_poolUID = sceKernelCreateFpl("SceUsb1Seg", 1, 256, 1328, 1, NULL);	// UID=f(name, part, attr, size, blocks, opt)
	if (g_poolUID < 0)	// on error
	{
		a0 = 0x00000 + 19828;	// 4d74
		goto loc_000018E0;
	}
	v0 = sceKernelTryAllocateFpl(g_poolUID, &lpData);	// f(poolUID, ptr)
	a0 = 0x00000 + 19540;	// 4c54
	if ((s32)v0 < 0)	// on error
		goto loc_000018E0;
	a1 = *(s32*)(&lpData + 0);
	s1 = 0x00000 + 244;
	
	g_lpData = a1 + 384;
	g_bulkoutReq.endp = a1 + 448;	//*(s32*)(s0 + 132) = a1 + 448;
	g_asyncReq.data = a1;
	*(s32*)(&lpData + 0) = a1 + 576;

	int *p = s0 + 188/4;
	int v1 = a3;
	for (int i = 1, i >= 0; i --)
	{
		*(p ++) = v1;
		v1 += 256;
	}
	//a2 = p;
	//t3 = 0x00000 + 164;	// g_driver

	t4 = v1 + 20;
	t2 = v1 + 36;
	s2 = s2 + 19528;
	//*(s32*)(t3 + 28) = t4;
	//*(s32*)(t3 + 16) = 0;
	//*(s32*)(t3 + 20) = 0;
	//*(s32*)(t3 + 24) = v1;
	g_driver.confp = t4;
	g_driver.devp_hi = 0;
	g_driver.confp_hi = 0;
	g_driver.devp = v1;
	*(s32*)(&lpData + 0) = t2;
	v0 = sub_00003400(1, v1, t4, t2);

	//a1 = 0x00000 + 14812;	// UsbThread(0x39DC)
	*(s32*)(&lpData + 0) = v0;

	v0 = sceKernelCreateThread(s2, UsbThread, 16, 1024, 0x100001, 0);
	g_threadID = v0;
	if ((s32)v0 < 0)
	{
		Kprintf("%serror - cannot create thread\n", "SceUsb1Seg:");	// 0x4C78, 19292
		s0 = s3 + 244;
		goto loc_000017B8;
	}
	v0 = sceKernelCreateEventFlag(s2, 0x201, 161, 0);	// name, attr, bits, opt
	g_eventFlag = v0;
	if ((s32)v0 < 0)
	{
		Kprintf("%serror - cannot create event flag\n", "SceUsb1Seg:");
		s0 = s3 + 244;
		goto loc_000017B8;
	}
	v0 = sceKernelCreateMutex("SceUsb1SegCmdLock", 1, 0, 0);
	g_mutexID = v0;
	if ((s32)v0 < 0)
	{
		Kprintf("%serror - cannot create mutex\n", "SceUsb1Seg:");
	}
	
	t1 = 0x00000 + 128;
	a2 = &g_deviceReq;
	t6 = g_bulkoutReq.data;

	g_bulkinReq.data = g_bulkoutReq.endp;//*(s32*)(s1 + 132);
	g_bulkinReq.size = 64;
	g_bulkinReq.unkc = 1;
	g_bulkinReq.func = BulkinReqDone;
	g_bulkinReq.recvsize = 0;
	g_bulkinReq.retcode =0;
	g_bulkinReq.unk1c = 0;
	g_bulkinReq.arg = 0;

	g_bulkoutReq.data = g_lpData;
	g_bulkoutReq.size = 64;
	g_bulkoutReq.unkc = 0;
	g_bulkoutReq.func = BulkoutReqDone;
	g_bulkoutReq.recvsize = 0;
	g_bulkoutReq.retcode = 0;
	g_bulkoutReq.unk1c = 0;
	g_bulkoutReq.arg = 0;

	g_asyncReq.data = g_asyncReq.data;	//ng
	g_asyncReq.size = 192;
	g_asyncReq.unkc = 0;
	g_asyncReq.func = AsyncReqDone;
	g_asyncReq.recvsize = 0;
	g_asyncReq.retcode = 0;
	g_asyncReq.unk1c = 0;
	g_asyncReq.arg = 0;

	s1 = 0x00000 + 244;
	g_bAttached = 0;
	*(s32*)(s1 + 8) = 0;
	*(s32*)(s1 + 12) = 0;
	*(s8*)(s1 + 20) = 0;
	g_deviceReq.endp = 0;
	g_bulkinReq.endp = t1;
	g_bulkoutReq.data = t1 + 12;

	t4 = 1;
	t5 = t1 + 8;
	do
	{
		t4 --;
		*(s32*)(t5 + 0) = 0;
		t5 += 12;
	}while ((s32)t4 >= 0);
	s0 = 0x00000 + 244;
	s1 = g_lpData;
	*(s16*)(s1 + 0) = 8;
	//a1 = 0x00000 + 244 + 92;
	v0 = sceUsbAcc_internal_2E251404(8, g_bulkinReq, a2, 8);

	if (v0 >= 0)
	{
		sceKernelStartThread(g_threadID, 0, 0);	// thID, argc=0, argv=0
		g_bStarted = 1;	// 1ST-INIT!!
		return(0);
	}
	s0 = 0x00000 + 244;

loc_000017B8:		
	a0 = g_mutexID
	if ((s32)a0 > 0)
	{
		if (sceKernelDeleteMutex(a0) < 0)
		{
			Kprintf("%serror - cannot delete mutex\n", "SceUsb1Seg");	// 19628, 19292
		}
		g_mutexID = -1;

		if (sceKernelDeleteEventFlag(g_eventFlag) < 0)
		{
			Kprintf("%serror - cannot delete event flag\n", "SceUsb1Seg:");	// 19660, 19292
		}
		g_eventFlag = -1;

		if (sceKernelDeleteThread(g_threadID) < 0)
		{
			Kprintf("%serror - cannot delete thread\n", "SceUsb1Seg:");	// 19696, 19292
		}
		g_threadID = -1;

		if (sceKernelDeleteFpl(g_poolUID) < 0)
		{
			Kprintf("%serror - cannot delete FPL\n", "SceUsb1Seg:");	// 19728, 19292
		}
		g_poolUID = -1;
	}
	return (-1);
}

int DriverStop(int size, void *args)
{
	s1 = 0x00000 + 244;

	sceUsbAcc_internal_18B04C82(8);
	curIntCtrlState = sceKernelCpuSuspendIntr();
	*(s32*)(s1 + 12) = 4;
	sceKernelSetEventFlag(g_eventFlag, 4);
	sceKernelCpuResumeIntr(curIntCtrlState);
	sceKernelWaitThreadEnd(g_threadID, 0);
	a0 = g_mutexID;
	s0 = 0x00000 + 244;
	if ((s32)a0 > 0)
	{
		v0 = sceKernelDeleteMutex(a0);
	
		if ((s32)v0 < 0)
		{
			//a0 = 0x00000 + 19628;
			//a1 = 0x00000 + 19292;
			Kprintf("%serror - cannot delete mutex\n", "SceUsb1Seg:");
		}
		g_mutexID = -1;
	}
	a0 = g_threadID
	if ((s32)a0 > 0)
	{
		v0 = sceKernelDeleteThread(a0);
		
		if ((s32)v0 < 0)
		{
			//a1 = 0x00000;
			//a0 = a1 + 19696;
			//a2 = 0x00000;
			//a1 = a2 + 19292;
			Kprintf("%serror - cannot delete thread\n", "SceUsb1Seg:");
		}
		g_threadID = -1;
	}
	a0 = g_eventFlag;
	if ((s32)a0 > 0)
	{
		v0 = sceKernelDeleteEventFlag(a0);
		
		if ((s32)v0 < 0)
		{
			//t1 = 0x00000;
			//a0 = t1 + 19660;
			//t0 = 0x00000;
			//a1 = t0 + 19292;
			Kprintf("%serror - cannot delete event flag\n", "SceUsb1Seg:");
		}
		g_eventFlag = -1;
	}
	a0 = g_poolUID;
	if ((s32)a0 <= 0)
	{
		g_bStarted = 0;	// FINALIZE!!
	}
	else
	{
		v0 = sceKernelDeleteFpl(a0);
		if ((s32)v0 < 0)
		{
			//a0 = 0x00000 + 19728;
			//a1 = 0x00000 + 19292;
			v0, v1 = Kprintf("%serror - cannot delete FPL\n", "SceUsb1Seg:");
		}
		g_poolUID = -1;
		g_bStarted = 0;
	}
	//v0 = 0;
	return (0);
}

sub_00001A74() // at 0x00001A74 
{
	v1 = 0x00000;
	s0 = v1 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);
	v1 = &g_deviceReq;
	a2 = g_deviceReq.retcode;//*(s32*)(v1 + 24);

	if ((s32)a2 <= 0)
	{
		*(s8*)(a3 + 2) = 1;
		*(s8*)(a2 + 3) = 0;
		v0 = sceUsbAcc_internal_2A100C1F(v1, "SceUsb1Seg:", g_lpData);	// toomany!!
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		v0 = 0x80243006;
	}
	return (v0);
}

sub_00001AF8() // at 0x00001AF8 
{
	s0 = 0x00000 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);
	
	v1 = &g_deviceReq;
	a2 = g_deviceReq.retcode;
	if ((s32)a2 <= 0)
	{
		g_lpData[2] = 2;
		g_lpData[3] = 0;
		v0 = sceUsbAcc_internal_2A100C1F(v1);
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		v0 = 0x80243006;
	}

	return (v0);
}

sub_00001B7C(u8 a0)
{
	s2 = 0x00000 + 244;
	s0 = a0;
	s3 = &g_deviceReq;
	sceKernelLockMutex(g_mutexID, 1, 0);

	v0 = g_deviceReq.retcode;
	a2 = 1;
	a1 = sp;
	s1 = 0x80243006;
	*(s8*)(sp + 0) = s0;

	if (v0 <= 0)
	{
		t2 = g_lpData;
		*(s8*)(t2 + 2) = 3;
		s0 = sp + 2;
		*(s8*)(a0 + 3) = 1;
		memcpy(g_lpData + 4);
		s1 = sceUsbAcc_internal_2A100C1F(s3);
		if (v0 != 0)
			goto loc_00001BE8;
		s1 = sub_00003664(s0, 2);
		if (v0 != 0)
			goto loc_00001BE8;
		s1 = sub_00002CEC_geterrcode(s0);
	}
	else
	{
		v0 = Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}
loc_00001BE8:
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s1);
}

typedef struct
{
	char	unk[8];
} SCANCH_INFO;

// from ScanCh
sub_00001C80(int *a0) // at 0x00001C80 
{
	s1 = 0x00000 + 244;
	s0 = a0;
	sceKernelLockMutex(g_mutexID, 1, 0);
	v1 = &g_deviceReq;
	a2 = g_deviceReq.retcode;

	if ((s32)a2 <= 0)
	{
		g_lpData[2] = 4;
		g_lpData[3] = 0;
		s1 = sceUsbAcc_internal_2A100C1F(v1);
	}
	else{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		s1 = 0x80243006;
	}

	*(s8*)(s0 + 0) = 0;
	*(s8*)(s0 + 1) = 0;
	*(s8*)(s0 + 2) = 0;
	*(s8*)(s0 + 3) = 0;
	*(s8*)(s0 + 4) = 0;
	*(s8*)(s0 + 5) = 0;
	*(s8*)(s0 + 6) = 0;
	*(s8*)(s0 + 7) = 0;
	if (s1 == 0)
	{
		s1 = sub_00003664(sp, 10);
		if (!s1)
		{
			if ( *(s16*)(sp + 16) = *(u16*)(sp + 0) )
			{
				s1 = sub_00002CEC_geterrcode(sp + 16);
			}
			else
			{
				*(s8*)(s0 + 0) = *(u8*)(sp + 5);
				*(s8*)(s0 + 1) = *(u8*)(sp + 4);
				*(s8*)(s0 + 2) = *(u8*)(sp + 3);
				*(s8*)(s0 + 3) = *(u8*)(sp + 2);
				*(s8*)(s0 + 4) = *(u8*)(sp + 9);
				*(s8*)(s0 + 5) = *(u8*)(sp + 8);
				*(s8*)(s0 + 6) = *(u8*)(sp + 7);
				*(s8*)(s0 + 7) = *(u8*)(sp + 6);
			}
		}
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (s1);
}

// GetModule
sub_00001DD0(int *lpDst) // at 0x00001DD0 
{
	s1 = 0x00000 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);
	a0 = &g_deviceReq;
	v1 = g_deviceReq.retcode;
	
	s0 = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		g_lpData[2] = 8;
		g_lpData[3] = 0;
		s0 = sceUsbAcc_internal_2A100C1F(a0);
		if (!s0)
		{
			s0 = sub_00003664(lpDst, 1);
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

// SetEncKey, 3B70
sub_00001E94(int a0) // at 0x00001E94 
{
	t0 = a0;
	s1 = 0x00000 + 244;
	s2 = &g_deviceReq;
	a3 = *(u8*)(a0 + 0);
	s0 = 0x80244504;
	if ((u32)a3 < 64)
	{
		*(s8*)(sp + 0) = a3;

		s0 = 0x80243006;
		asm("lwl        $v0, 4($t0)");
		asm("lwr        $v0, 1($t0)");
		asm("lwl        $v1, 8($t0)");
		asm("lwr        $v1, 5($t0)");
		asm("lwl        $a3, 12($t0)");
		asm("lwr        $a3, 9($t0)");
		asm("lwl        $t1, 16($t0)");
		asm("lwr        $t1, 13($t0)");
		asm("swl        $v0, 4($sp)");
		asm("swr        $v0, 1($sp)");
		asm("swl        $v1, 8($sp)");
		asm("swr        $v1, 5($sp)");
		asm("swl        $a3, 12($sp)");
		asm("swr        $a3, 9($sp)");
		asm("swl        $t1, 16($sp)");
		asm("swr        $t1, 13($sp)");
		sceKernelLockMutex(g_mutexID, 1, 0);

		if (*(s32*)(s2 + 24) <= 0)
		{
			s4 = sp + 32;
			g_lpData[2] = 9;
			g_lpData[3] = 17;
			memcpy(g_lpData + 4, sp, 17);
			s0 = sceUsbAcc_internal_2A100C1F(s2);

			if (!s0)
			{
				s0 = sub_00003664(s4, 2);
				if (!s0)
				{
					s0 = sub_00002CEC_geterrcode(s4);
				}
			}
		}
		else
		{
			//a0 = 0x00000 + 19860;
			//a1 = 0x00000 + 19292;
			Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		}

		sceKernelUnlockMutex(g_mutexID, 1);
	}
	return (s0);
}

UINT32 sub_00001FF0(int a0) // at 0x00001FF0 
{
	s1 = 0x00000 + 244;
	s2 = a0;
	sceKernelLockMutex(g_mutexID, 1, 0);
	
	s0 = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		g_lpData[2] = 10;
		g_lpData[3] = 0;
		s0 = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!s0)
		{
			s0 = sub_00003664(s2, 2);
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

// GetDbg
UINT32 sub_000020B4(int *a0, int a1) // at 0x000020B4 
{
	s1 = 0x00000 + 244;
	s3 = a0;
	s2 = a1;
	sceKernelLockMutex(g_mutexID, 1, 0);

	s0 = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		g_lpData[2] = 255;
		g_lpData[3] = 0;
		s0 = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!s0)
		{
			s0 = sub_00003664(s3, s2);
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

UINT32 sub_00002184(int a0, int a1) // at 0x00002184 
{
	s0 = a1;
	s2 = 0x00000 + 244;
	s4 = &g_deviceReq;
	s3 = a0;
	s1 = 0x80244588;
	if ((u32)s0 < 61)
	{
		s1 = 0x80243006;
		sceKernelLockMutex(g_mutexID, 1, 0);
		a2 = g_deviceReq.retcode;

		if ((s32)a2 <= 0)
		{
			g_lpData[2] = 249;
			g_lpData[3] = s0;
			if (s3)
			{
				memcpy(g_lpData + 4, s3, s0);
			}
			s1 = sceUsbAcc_internal_2A100C1F(s4);
			if (!s1)
			{
				s1 = sub_00003664(sp, 2);
				if (!s1)
				{
					s1 = sub_00002CEC_geterrcode(sp);
				}
			}
		}
		else
		{
			//a0 = 0x00000 + 19860;
			//a1 = 0x00000 + 19292;
			Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		}

		sceKernelUnlockMutex(g_mutexID, 1);
	}
	return (s1);
}

// Pwm
UINT32 sub_000022A4(int *a0) // at 0x000022A4 
{
	s1 = 0x00000 + 244;
	s2 = a0;
	s3 = &g_deviceReq;
	sceKernelLockMutex(g_mutexID, 1, 0);

	s0 = 0x80243006;
	if (*(s32*)(s3 + 24) <= 0)
	{
		g_lpData[2] = 254;
		g_lpData[3] = 2;
		if (s2)
		{
			memcpy(g_lpData + 4, s2, 2);
		}
		s0 = sceUsbAcc_internal_2A100C1F(s3);	//UsbdDeviceReq*
	
		if (!s0)
		{
			s0 = sub_00003664(sp, 2);
			if (!s0)
			{
				s0 = sub_00002CEC_geterrcode(sp);
			}
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}

	t2 = 0x00000 + 244;
	v0, v1 = sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

UINT32 sub_000023A8(int a0, int a1, int *lpDst, int size1, int size2) // at 0x000023A8 
{
//	s0 = a3;
	v1 = 0x80244588;
	s5 = a2;
	s4 = t0;
	s3 = a0;
	s2 = a1;
	if ((u32)a3 < 60)
	{
		v1 = 0x80244588;
		if ((u32)t0 < 59)
		{
			s1 = 0x00000 + 244;
			sceKernelLockMutex(g_mutexID, 1, 0);
			*(s8*)(sp + 0) = s3;
			memcpy(sp + 1, &g_deviceReq, a3);
			v1 = g_deviceReq.retcode;
			a3 = a3 + 1;
			if ((s32)v1 <= 0)
			{
				g_lpData[2] = 250;
				g_lpData[3] = a3;
				memcpy(g_lpData + 4, sp, a3);
				s0 = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
				if (!s0)
				{
					s0 = sub_00003664(sp, 60);
					if (!s0)
					{
						if (*(s16*)(sp + 64) = *(u16*)(sp + 0))
						{
							s0 = sub_00002CEC_geterrcode(sp + 64);
						}
						else
						{
							memcpy(s5, sp + 2, s4);
						}
					}
				}
			}
			else
			{
				//a0 = 0x00000 + 19860;
				//a1 = 0x00000 + 19292;
				Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
				s0 = 0x80243006;
			}
			t5 = s6 + 244;
			sceKernelUnlockMutex(g_mutexID, 1);
			v1 = s0;
		}
	}
	return (v1);
}

UINT32 sub_00002518(int a0, int *lpSrc, int size) // at 0x00002518 
{
	s2 = 0x00000 + 244;
	a3 = a0;
	s3 = &g_deviceReq;
	s0 = 0x80244588;

	if (size < 60)
	{
		*(s8*)(sp + 0) = a3;
		s0 = 0x80243006;
		memcpy(sp + 1, lpSrc, size);
		sceKernelLockMutex(g_mutexID, 1, 0);

		a3 = size + 1;
		if (*(s32*)(s3 + 24) <= 0)
		{
			g_lpData[2] = 251;
			g_lpData[3] = a3;
			memcpy(g_lpData + 4, sp, a3);
			s0 = sceUsbAcc_internal_2A100C1F(s3);
			if (!s0)
			{
				s0 = sub_00003664(sp + 64, 2);
				if (!s0)
				{
					s0 = sub_00002CEC_geterrcode(s1);
				}
			}
		}
		else
		{
			//a0 = 0x00000 + 19860;
			//a1 = 0x00000 + 19292;
			Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
		}
		t4 = 0x00000 + 244;
		sceKernelUnlockMutex(g_mutexID, 1);
	}
	return (s0);
}

// from: EEPROM update
UINT32 sub_0000263C(int a0, int a1, int a2, int a3) // at 0x0000263C 
{
	s5 = 0x00000 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);
	curIntCtrlState = sceKernelCpuSuspendIntr();
	*(s32*)(s5 + 12) = 5;
	*(s32*)(s5 + 256) = a3;
	*(s32*)(s5 + 252) = 0;
	*(s32*)(s5 + 260) = a1;
	*(s32*)(s5 + 264) = a2;
	*(s16*)(s5 + 252) = a0;
	*(s32*)(s5 + 268) = 0;
	sceKernelSetEventFlag(g_eventFlag, 16);
	sceKernelCpuResumeIntr(curIntCtrlState);
	s0 = sceKernelWaitEventFlag(g_eventFlag, 1025, 1, sp + 4, 0);
	if (!s0)
	{
		v1 = *(s32*)(sp + 4);

		s0 = 0x80244503;
		if (v1 & 0x1 == 0)
		{	s0 = 0;	}
		if (v1 & 0x400)
		{
			t0 = g_lpData;
			*(s16*)(sp + 0) = *(u16*)(t0 + 4);
			s0 = sub_00002CEC_geterrcode(sp);
			sceKernelClearEventFlag(g_eventFlag, -1025);
		}
	}
	t1 = 0x00000 + 244;
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

UINT32 sub_0000276C() // at 0x0000276C 
{
	s1 = 0x00000 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);
	a0 = &g_deviceReq;

	s0 = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		g_lpData[2] = 246;
		g_lpData[3] = 0;
		s0 = sceUsbAcc_internal_2A100C1F(a0);
		if (!s0)
		{
			s0 = sub_00003664(sp, 2);
			if (!s0)
			{
				s0 = sub_00002CEC_geterrcode(sp);
			}
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

//from EEPROMParamRead
UINT32 sub_00002838(int a0, int a1) // at 0x00002838 
{
	s1 = 0x00000 + 244;
	s3 = a0;
	s2 = a1;
	v0, v1 = sceKernelLockMutex(g_mutexID, 1, 0);
	a0 = &g_deviceReq;
	s0 = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		g_lpData[2] = 245;
		g_lpData[3] = 0;
		s0 = sceUsbAcc_internal_2A100C1F(a0);
		if (!s0)
		{
			s0 = sub_00003664(s3, s2);
			if (!v0)
			{
				*(s8*)(sp + 0) = *(s8*)(s3 + 0);
				*(s8*)(sp + 1) = *(s8*)(s3 + 1);
				if (*(u16*)(sp + 0))
				{
					s0 = sub_00002CEC_geterrcode(sp);
				}
			}
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}

loc_0000289C:		
	t2 = 0x00000 + 244;
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

UINT32 sub_00002934(int a0, int a1, int a2) // at 0x00002934 
{
	s4 = 0x00000 + 244;
	s5 = &g_deviceReq;
	sceKernelLockMutex(g_mutexID, 1, 0);

	s3 = 0x80243006;
	*(s8*)(sp + 0) = a0;
	*(s8*)(sp + 1) = a1;
	*(s8*)(sp + 2) = a2;
	if ((s32)*(s32*)(s5 + 24) <= 0)
	{
		s0 = sp + 16;
		g_lpData[2] = 247;
		g_lpData[3] = 3;
		memcpy(g_lpData + 4, sp, 3);
		s3 = sceUsbAcc_internal_2A100C1F(s5);
		if (!s3)
		{
			s3 = sub_00003664(s0, 2);
			if (!s3)
			{
				s3 = sub_00002CEC_geterrcode(s0);
			}
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg");
	}

	a2 = 0x00000 + 244;
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s3);
}

UINT32 sub_00002A58(int a0, int a1, int a2)
{
	s5 = 0x00000;

	a3 = a0;
	s2 = 0x00000 + 244;
	s4 = &g_deviceReq;
	s0 = a3 & 0xFFFF;	// ret is UINT16 ?
	v0, v1 = sceKernelLockMutex(g_mutexID, 1, NULL);	// (mutexID, count, *timeOut)
	
	a3 = *(s32*)(s4 + 24);
	*(s8*)(sp + 1) = (u32)s0 >> 8;
	*(s8*)(sp + 0) = s0;
	*(s8*)(sp + 2) = a2;

	if ((s32)a3 <= 0)
	{
		g_lpData[2] = 243;
		g_lpData[3] = 3;
		memcpy(g_lpData + 4, sp, 3);
		s0 = sceUsbAcc_internal_2A100C1F(s4);
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
		s0 = 0x80243006;
	}
	memset(a1, 0, a2);
	
	if (s0 == 0)
	{
		v0 = sub_00003664(sp, 60);
		s0 = v0;

		if (!v0)
		{
			*(s16*)(sp + 64) = *(u16*)(sp + 0);
			if (t5 != 0)
			{
				s0 = sub_00002CEC_geterrcode(sp + 64);
			}
			else
			{
				memcpy(a1, sp + 2, a2);
			}
		}
	}

	a2 = 0x00000 + 244;
	sceKernelUnlockMutex(g_mutexID, 1);
	return (s0);
}

UINT32 sub_00002BB8(int a0, int a1, int a2)
{
	s3 = 0x00000 + 244;
	//s4 = a1;
	s1 = a2;
	s0 = a0 & 0xFFFF;

	sceKernelLockMutex(g_mutexID, 1, NULL);
	s2 = 0x80243006;
	*(s8*)(sp + 2) = s1;
	*(s8*)(sp + 1) = (u32)s0 >> 8;
	*(s8*)(sp + 0) = s0;
	s1 += 3;
	s4 = &g_deviceReq;
	memcpy(sp + 3, &g_deviceReq, s1);

	v1 = *(s32*)(s4 + 24);

	if ((s32)v1 <= 0)
	{
		s0 = sp + 64;
		g_lpData[2] = 244;
		g_lpData[3] = s1;
		memcpy(g_lpData + 4, sp, s1);
		s2 = sceUsbAcc_internal_2A100C1F(s4);

		if (!s2)
		{
			s2 = sub_00003664(s0, 2);
			if (!s2)
			{
				s2 = sub_00002CEC_geterrcode(s0);
			}
		}
	}
	else
	{
	//	a0 = 0x00000 + 19860;
	//	a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (s2);
}

typedef struct _ERROR_CODE
{
	UINT32	code;
	UINT32	unk;
} ERROR_COD;

ERROR_CODE errors[10] =
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

UINT32 sub_00002CEC_geterrcode(UINT16 *a0) // from TunerInit/sub
{
	a2 = *(u16*)(a0 + 0);
	a1 = 0x00000 + 20536;	// (0x5038) Error code table?

	for(int i = 0; i < 10; i ++)
	{
		if (*(u16*)(a1 + 4) == a2)	// errors[i].unk == a2
		{
			return (*(s32*)(a1 + 0));
		}
		a1 += 8;
	}

	return (0x80244501);
}

//405:sceUsb1Seg_5F62E0B5
UINT32 sceUsb1SegChangeCh()
{
	v0 = 0x80244503;

	if (g_bAttached)
	{
		pspSdkGetK1();
		pspSdkSetK1(k1 << 11);
		v0 = sub_00001B7C(g_bAttached);
		pspSdkSetK1(k1);
	}
	return (v0);	
}

//405:sceUsb1Seg_557E6B41
UINT32 sceUsb1SegInitTuner()
{
	UINT32 ret = 0x80244503;

	if (g_bAttached)
	{
		k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);
		ret = sub_00003708(g_bAttached);
		pspSdkSetK1(k1);
	}
	return (ret);
}

//405:sceUsb1Seg_19AF6734
UINT32 sceUsb1Seg_00CC60F7(int mode) // at 0x00002DC4 - Aliases: sceUsb1Seg_driver_00CC60F7
{
	UINT32	k1;
	UINT32	ret;

	k1 = pspSdkGetK1();
	pspSdkSetK1(k1 << 11);
	ret = sceClockgenSetSpectrumSpreading(mode);
	pspSdkSetK1(k1);

	return (ret);
}

UINT32 sceUsb1SegSetAntenna(int a0)
{
	UINT32	k1;
	UINT32	ret;

	ret = 0x80244503;
	if (g_bAttached)
	{
		k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);
		ret = sub_000037D4(a0, g_bAttached);
		pspSdkSetK1(k1);
	}

	return (ret);
}

UINT32 sceUsb1SegSetBPER(int a0)
{
	UINT32	k1;
	UINT32	ret;

	ret = 0x80244503;
	if (g_bAttached)
	{
		k1 = pspSdkGetK1();
		pspSdkSetK1(k1 << 11);
		ret = sub_000038D8(a0);
		pspSdkSetK1(k1);
	}

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
struct UsbDriver	g_driver =
{
	"USB1SegDriver",	// 0x4960
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

int module_start(int argc, LPVOID lpArg)
{
	int	ret = 0x00000;

	// param: USB driver struct
	// return: 0 on success, < 0 on error
	//v0 = sceUsbbdRegister(0x00000 + 164);
	ret = sceUsbbdRegister(&g_driver);

	if ((s32)ret < 0)
	{
		//	a0 = 0x00000 + 19900;
		//	a1 = 0x00000 + 19292;
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

int module_stop(int args, void *lpArgs)
{
	int	ret;

	if ((ret = sceUsbbdUnregister(&g_driver) < 0)
	{
		//	a0 = 0x00000 + 19936;
		//	a1 = 0x00000 + 19292;
		Kprintf("%serror - cannot register : 0x%08x\n", "SceUsb1Seg:", ret);
		return (true);
	}
	else
	{
		return (false);
	}
}

int BulkinReqDone(UsbdDeviceReq *lpDevReq)
{
	v1 = lpDevReq->retcode;//*(s32*)(a0 + 24);
	if (v1)	{	return (v0);	}
	a1 = 0x00000;
	a2 = 0x00000 + 244;
	v1 = *(s8*)(a2 + 84);
	if ((s32)v1 < 0)	{ return (v0); }
	v1 = *(u8*)(a2 + 85);
	if (v1 == 245)
		goto loc_00003080;
	if (v1 >= 246)
	{
		if (v1 == 249)
			goto loc_00002FD0;
		if (v1 >= 250)
		{
			if (v1 >= 255)
			{
				if (v1 != 255)
				{	goto loc_00002FA8;	}
			}
			else if (v1 >= 251)
			{	goto loc_00002FD0;	}

			goto loc_00003080;
		}
		if ((s32)v1 < 248)
			goto loc_00002FD0;
		s0 = a1 + 244;
		a3 = g_lpData;
		if (*(u8*)(s0 + 85) != g_lpData[2])
		{
			return (v0);
		}
		memcpy(a3 + 4, lpDevReq->data, *(u16*)(s0 + 90));
		a0 = g_eventFlag;
		a1 = 2048;

		goto loc_00003004;
	}
	if (v1 == 8)
	{
		a3 = g_lpData;
		if (*(u8*)(a3 + 2) != v1)
		{
			return (v0);
		}
		//t5 = lpDevReq->data;
		*(s8*)(a3 + 4) = *(u8*)(lpDevReq->data);

		a1 = 1024;
		a0 = g_eventFlag;
		goto loc_00003004;
	}
	if (v1 >= 9)
	{
		if (v1 == 243)
			goto loc_00003080;
		if (v1 >= 244)
			goto loc_00002FD0;
		if (v1 >= 11)
			goto loc_00002FA8;
		a3 = g_lpData;
		goto loc_00002FD8;
	}
	if (v1 == 4)
	{
		a3 = g_lpData;
		if (*(u8*)(a3 + 2) != v1)
		{
			return (v0);
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
		*(s8*)(a3 + 12) = *(s8*)(t3 + 8);
		*(s8*)(a3 + 13) = *(s8*)(t3 + 9);

		a1 = 1024;
		a0 = g_eventFlag;
		goto loc_00003004;
	}

	if ((s32)v1 < 5)
	{
		if (v1 == 3)
			goto loc_00002FD0;
	}
	else{v0 = 5;}

loc_00002FA8:
	t9 = a1 + 244;
	Kprintf("%serror - Unknown Command Result. 0x%02x\n", "SceUsb1Seg:", *(u8*)(t9 + 85));	// 19976, 19292

loc_00002FC0:
	return (v0);

loc_00002FD0:		
	a2 = a1 + 244;
	a3 = g_lpData;

loc_00002FD8:		
	v0 = *(u8*)(a2 + 85);
	if (v0 != *(u8*)(a3 + 2))
	{
		return (v0);
	}
	t2 = *(s32*)(a0 + 4);
	*(s8*)(a3 + 4) = *(s8*)(t2 + 0);
	*(s8*)(a3 + 5) = *(s8*)(t2 + 1);

	a1 = 1024;
	a0 = g_eventFlag;

loc_00003004:
	v0 = sceKernelSetEventFlag(a0, a1);
	return (v0);

loc_00003080:		
	s0 = a1 + 244;
	a3 = g_lpData;
	t6 = *(u8*)(s0 + 85);
	a2 = *(u8*)(a3 + 2);
	if (t6 != a2)
	{
		return (v0);
	}
	memcpy(a3 + 4, *(s32*)(a0 + 4), *(u16*)(s0 + 90));
	a0 = g_eventFlag;
	a1 = 1024;
	goto loc_00003004;
}

int BulkoutReqDone(UsbdDeviceReq *lpDevReq)
{
	return (v0);
}

int AsyncReqDone(UsbdDeviceReq *lpDevReq)
{
	if (lpDevReq->retcode >= 0)
	{
		if (lpDevReq->recvsize == 192)
		{
			t0 = 0x00000 + 244;
			t1 = *(s32*)(t0 + 184);
			a3 = t1 << 2;
			a2 = a3 + t0;
			v1 = *(s32*)(a2 + 188);
			a1 = *(s32*)(v1 + 0);
			s0 = 0x00000;
			if (a1 != 0)
			{
				g_mutexID++;
				t4 = 0x00000 + 244;
				sceKernelSetEventFlag(g_eventFlag, 2);
			}
			else
			{
				a2 = lpDevReq->data;
				t0 = a2 + 192;
				if ((a2 | (v1 + 16)) & 0x3 == 0)
				{
					do
					{
						*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
						a3 += 16;
						*(s32*)(a3 - 12) = *(s32*)(a2 + 4);
						*(s32*)(a3 - 8) = *(s32*)(a2 + 8);
						*(s32*)(a3 - 4) = *(s32*)(a2 + 12);
						a2 += 16;
					} while (a2 != t0);
				}
				else
				{
					do
					{
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
						a2 += 16;
						a3 += 16;
					} while (a2 != t0);
				}
				s0 = 0x00000 + 244;
				t0 = (*(s32*)(s0 + 184) << 2) + s0;
				s1 = *(s32*)(t0 + 188);
				UINT64 ret = sceKernelGetSystemTimeWide();
				//a3 = *(s32*)(s0 + 184);
				*(s32*)(s1 + 8) = v0;	// ret.LO
				*(s32*)(s1 + 12) = v1;	// ret.HI
				a1 = (*(s32*)(s0 + 184) << 2) + s0;
				*(s32*)(*(s32*)(a1 + 188) + 0) = 1;
				*(s32*)(0x00000 + 240) = 0;
				*(s32*)(s0 + 184) = *(s32*)(s0 + 184) ^ 0x1;
				t4 = 0x00000 + 244;
				sceKernelSetEventFlag(g_eventFlag, 2);
			}
		}
		if (*(s32*)(s0 + 12) == 2)
		{
			sceKernelDcacheInvalidateRange(lpDevReq->data, 384);
			v0 = sceUsbbdReqRecv(lpDevReq);
			if ((s32)v0 < 0)
			{
				//a0 = 0x00000 + 19260;
				//a1 = 0x00000 + 19292;
				Kprintf("%serror - ReqRecv() : 0x%08x\n", "SceUsb1Seg:", v0);
			}
			else
			{
				v0 = sceKernelClearEventFlag(g_eventFlag, -129);
			}
		}
		else
		{
			v0 = sceKernelSetEventFlag(g_eventFlag, 128);
		}
	}
	return (v0);
}

int Attach(int speed, void *arg2, void *arg3)
{
	int	ret	= 0;

	a2 = 0x00000 + 244;
	if (g_bAttached == 0)
	{
		g_bAttached = 1;	// init 248
		*(s32*)(a2 + 12) = 0;
		ret = sceKernelClearEventFlag(g_eventFlag, - 2, 1);
	}
	return (ret);
}

int Detach(int arg1, void *arg2, void *arg3)
{
	int	ret	= 0;

	a0 = 0x00000 + 244;
	if (g_bAttached)
	{
		*(s32*)(a0 + 12) = 0;
		g_bAttached = 0;
		*(s32*)(a0 + 8) = 0;

		int *p = (int *)((0x00000 + 128) + 8);
		for (int i = 1; i >= 0; i--)
		{
			*p = 0;
			p += 12/4;
		}
		sceKernelClearEventFlag(g_eventFlag, 0);
		ret = sceKernelSetEventFlag(g_eventFlag, 161);
	}
	return (ret);
}

int sub_00003400(int  a0, int a1, int a2, int a3)
{
	t0 = a3 + 24;
	v0 = t0 + 12;
	t9 = a3;
	s3 = a0;
	s2 = a1;
	a1 = v0 + 72;
	*(s32*)(a2 + 4) = t0;
	t0 = 0x00000 + 20216;	// (0x4EF8)
	t2 = s2 | t0;
	t1 = t0 + 16;
	v1 = t2 & 0x3;
	t7 = a1;
	t8 = a1 + 32;
	*(s32*)(a2 + 8) = v0;
	*(s32*)(a2 + 0) = a3;
	a3 = t1;
	*(s32*)(a2 + 12) = a1;
	s0 = *(s32*)(a2 + 4);
	s1 = *(s32*)(a2 + 8);
	a2 = s2;
	if (v1 == 0)
	{
		while (true)
		{
			*(s32*)(a2 + 0) = *(s32*)(t0 + 0);
			a2 += 16;
			*(s32*)(a2 - 12) = *(s32*)(t0 + 4);
			*(s32*)(a2 - 8) = *(s32*)(t0 + 8);
			*(s32*)(a2 - 4) = *(s32*)(t0 + 12);
			t0 = t1;
			if (t1 == a3)
			{
				*(s32*)(a2 + 0) = *(s32*)(t1 + 0);
				goto loc_000034D8;
			}
			t1 += 16;
		}
	}
	v0 = t1;

loc_00003478:		
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
	if (t0 != v0)
		goto loc_00003478;
	asm("lwl        $t4, 3($t0)");
	asm("lwr        $t4, 0($t0)");
	asm("swl        $t4, 3($a2)");
	asm("swr        $t4, 0($a2)");

loc_000034D8:
	a1 = 0x00000 + 20236;	// (0x4F0C)
	t5 = 0x00000 + 20260;	// (0x4F24)
	*(s32*)(t9 + 0) = *(s32*)(a1 + 0);	// 0x220209
	*(s32*)(t9 + 4) = *(s32*)(a1 + 4);	// 0x101
	*(s32*)(t9 + 8) = *(s32*)(a1 + 8);	// 0x00
	*(s32*)(t9 + 12) = *(s32*)(a1 + 12);	// 0x00
	*(s32*)(t9 + 16) = *(s32*)(a1 + 16);	// 0x00
	*(s32*)(t9 + 20) = *(s32*)(a1 + 20);	// 0x00
	*(s32*)(s0 + 0) = *(s32*)(t5 + 0);	// 0
	*(s32*)(s0 + 4) = *(s32*)(t5 + 4);	// 0
	*(s32*)(s0 + 8) = *(s32*)(t5 + 8);	// 2
	t5 = s1;
	t6 = 0x00000 + 20272;
	a2 = t6 + 64;

loc_0000353C:
	*(s32*)(t5 + 0) = *(s32*)(t6 + 0);
	t5 += 16;
	*(s32*)(t5 - 12) = *(s32*)(t6 + 4);
	*(s32*)(t5 - 8) = *(s32*)(t6 + 8);
	*(s32*)(t5 - 4) = *(s32*)(t6 + 12);
	t6 += 16;

	if (t6 != a2)
		goto loc_0000353C;

	t3 = 0x00000 + 20344;	// (0x4F78)

	*(s32*)(t5 + 0) = *(s32*)(t6 + 0);
	*(s32*)(t5 + 4) = *(s32*)(t6 + 4);
	*(s32*)(t7 + 28) = *(s32*)(t3 + 28);	// 0
	*(s32*)(t7 + 4) = *(s32*)(t3 + 4);	// 0
	*(s32*)(t7 + 0) = *(s32*)(t3 + 0);	// 0x05010507
	*(s32*)(t7 + 8) = *(s32*)(t3 + 8);	// 0
	*(s32*)(t7 + 12) = *(s32*)(t3 + 12);	// 0
	*(s32*)(t7 + 16) = *(s32*)(t3 + 16);	// 0
	*(s32*)(t7 + 20) = *(s32*)(t3 + 20);	// 0
	*(s32*)(t7 + 24) = *(s32*)(t3 + 24);	// 0
	*(s16*)(t7 + 4) = 192;
	*(s32*)(t9 + 12) = s0;
	*(s32*)(s0 + 0) = s1;
	*(s32*)(s1 + 36) = t7;
	
	if (s3 == 2)
	{
		*(s8*)(s2 + 7) = 64;
		*(s8*)(t7 + 6) = 4;
	}
	else
	{
		*(s8*)(s2 + 7) = 64;
		*(s8*)(t7 + 6) = t3;
	}
loc_000035E8:
	return (t8);
}

// from InitTuner
// ScanCh, GetModule/sub
int sub_00003664(int *lpDst, int size)
{
	UINT32	ret;	
	int bits;

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

UINT32 sub_00003708(int a0) // from InitTuner 
{
	int	x;
	UINT32	ret;

	s1 = 0x00000 + 244;
	sceKernelLockMutex(g_mutexID, 1, 0);

	ret = 0x80243006;
	if (*(s32*)(a0 + 24) <= 0)
	{
		*(s8*)(g_lpData + 2) = 5;
		*(s8*)(g_lpData + 3) = 0;
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664(&x, 2);
			if (!ret)
			{
				ret = sub_00002CEC_geterrcode(&x);
			}
		}
	}
	else
	{
		//a0 = 0x00000 + 19860;
		//a1 = 0x00000 + 19292;
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}

	sceKernelUnlockMutex(g_mutexID, 1);
	return (ret);
}

// SetAnt
UINT32 sub_000037D4(int ch)
{
	UINT32	ret;
	BYTE	x, y, z;

	x = ch;
	sceKernelLockMutex(g_mutexID, 1, NULL);
	
	ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		*(s8*)(g_lpData + 2) = 253;
		*(s8*)(g_lpData + 3) = 1;
		memcpy(g_lpData + 4, &x, 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);
		if (!ret)
		{
			ret = sub_00003664(&z, 2);
			if (!ret)
			{
				ret = sub_00002CEC_geterrcode(&z);
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

UINT32 sub_000038D8(int ch) // at 0x000038D8 
{
	UINT32	ret;
	BYTE	x, y, z;

	x = ch;
	sceKernelLockMutex(g_mutexID, 1, 0);

	ret = 0x80243006;
	if (g_deviceReq.retcode <= 0)
	{
		*(s8*)(g_lpData + 2) = 252;
		*(s8*)(g_lpData + 3) = 1;
		memcpy(g_lpData + 4, &x, 1);
		ret = sceUsbAcc_internal_2A100C1F(&g_deviceReq);

		if (!ret)
		{
			ret = sub_00003664(&z, 2);
			if (!ret)
			{
				ret = sub_00002CEC_geterrcode(&z);
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

/*LPVOID	g_jmpTbl5088[] =
{
	0x3A58,
	0x3A28,
	0x3A68,
	0x3A98,
	0x3A30,
	0x3AA8,
};*/

int UsbThread(LPVOID lpArg)	// 0x39DC
{
	a0 = 0x00000 + 244;
	if (*(s32*)(a0 + 12) != 4)
	{
		do
		{
			v1 = *(s32*)(a0 + 12);
			//a0 = (u32)v1 < (u32)6;
			//if (a0 == 0)
			if (v1 >= 6)
			{
				sub_00003AB8();
				t5 = 0x00000 + 244;
			}
			else
			{
				switch (v1)
				{
					case 0:
						sub_00003AB8();
						break;
					case 1:
						sub_00003B70();
						t5 = 0x00000 + 244;
						break;
					case 2:
						t2 = 0x00000 + 244;
						t1 = g_cbUID;	//cbUID
						if (t1 < 0)
						{
							v0 = sub_00003C38();
							t5 = 0x00000 + 244;
						}
						else
						{
							sub_00003F74();
						}
						break;
					case 3:
						sub_000042EC();
						break;
					case 4:
						t5 = 0x00000 + 244;
						break;
					case 5:
						UpdateStatProc();
						break;
				}
			}
			a0 = t5;
		} while (*(s32*)(t5 + 12) != 4);
	}
	return (0);
}

sub_00003AB8()
{
	int bits;
	int	ret;

	s1 = 0x00000 + 244;
	ret = sceKernelWaitEventFlag(g_eventFlag, 20, 1, &bits, NULL);
	if (ret >= 0)
	{
		if (bits & 0x10)
		{
			sceKernelClearEventFlag(g_eventFlag, -17);
			if (bits & 0x1)
			{
				*(s32*)(s1 + 12) = 0;
			}
		}
		else if (bits & 0x4)
		{
			if (*(s32*)(s1 + 12) != 4)
			{
				//a0 = 0x00000 + 20020;
				//a1 = 0x00000 + 19292;
				Kprintf("%serror - Driver status is not END, but END flag is set in event flag\n", "SceUsb1Seg:");
				*(s32*)(s1 + 12) = s2;
			}
		}
	}
	return (ret);
}

sub_00003B70() // at 0x00003B70 
{
	s0 = sub_00001E94(0x00000 + 265);

	if ((s32)s0 >= 0)
	{
		s0 = sub_00001B7C(*(u8*)(0x00000 + 244 + 20));
		if ((s32)s0 >= 0)
		{
			s0 = sub_00001A74();
			if (s0 == 0)
			{
				s0 = sceKernelWaitEventFlag(g_eventFlag, 65, 1, sp, NULL);
			}
		}
	}
	*(s32*)(0x00000 + 244 + 16) = s0;
	sceKernelSetEventFlag(g_eventFlag, 256);
	sceKernelUnlockMutex(g_mutexID, 1);
	
	if ((s32)s0 < 0)
	{
		Kprintf("%sFailed to start stream\n", "SceUsb1Seg:");
		*(s32*)(0x00000 + 244 + 12) = 0;
	}

	return (s0);
}

sub_00003C38() // at 0x00003C38 
{
	s5 = 0;
	a0 = 0x00000 + 244;
	s3 = 1;
	if (*(s32*)(a0 + 12) == 2)
	{
		s1 = a0;
		s2 = a0;
		goto loc_00003CAC;
	}
	v0 = 0;

loc_00003C7C:
	return (v0);

loc_00003CAC:		
	v0 = sceKernelWaitEventFlag(g_eventFlag, 16421, 1, sp, NULL);
	if (v0 != 0)
	{
		goto loc_00003CEC;
	}
	if (*(s32*)(sp + 0) & 0x4000)
	{
		goto loc_00003D24;
	}

loc_00003CDC:
	if (v1 & 0x1)
	{
		v0, v1 = sceKernelSetEventFlag(g_eventFlag, 4096);
		*(s32*)(s2 + 12) = 3;
		v0 = sceKernelSetEventFlag(g_eventFlag, 32);
	}
	
loc_00003CEC:
	s0 = *(s32*)(s2 + 12);		
	a3 = 2;
	s1 = s2;
	if (s0 == a3)
		goto loc_00003CAC;
	v0 = 0;
	goto loc_00003C7C;

loc_00003D24:
	v0 = sceKernelWaitEventFlag(g_eventFlag, 39, 1, sp, NULL);
	s0 = v0;
	if (v0 != 0)
	{
		a0 = 0x00000 + 20120;
		a1 = 0x00000 + 19292;
		Kprintf("%serror - at waiting for event at line %d): ret = 0x%08x pattern = %08x\n", "SceUsb1Seg:", 1696, v0, *(s32*)(sp + 0));
		v0 = s0;
		goto loc_00003C7C;
	}
	v1 = *(s32*)(sp + 0);
	if (v1 & 0x2 == 0)
		goto loc_00003CDC;
	v0 = sceKernelCpuSuspendIntr();
	t2 = g_asyncReq.size;
	t1 = t2 << 2;
	t0 = t1 + s1;
	a3 = *(s32*)(t0 + 188);
	a2 = *(s32*)(a3 + 0);
	s6 = v0;
	if (a2 == 0)
		goto loc_00003EB0;
	s1 = 0x00000 + 244;
	a1 = *(s32*)(s1 + 224);

loc_00003D80:		
	if (a1 == 0)
	{
		if (s3 == 0)
		{
			s5 = 1;
		}
		goto loc_00003EB0;
	}
	a0 = g_asyncReq.size;
	t9 = *(s32*)(s1 + 204);
	v0 = a0 << 2;
	s0 = v0 + s1;
	t8 = t9 << 1;
	t7 = t8 + t9;
	t6 = g_asyncReq.func;	//oncomplete
	t5 = t7 << 3;
	t0 = a1 + t5;
	v1 = *(s32*)(t0 + 20);
	*(s32*)(t0 + 0) = 0;
	*(s32*)(t0 + 8) = *(s32*)(t6 + 8);
	*(s32*)(t0 + 12) = *(s32*)(t6 + 12);

	if ((s32)v1 < 0)
	{
		s0 = *(s32*)(s1 + 204);
	}
	else
	{
		t3 = g_asyncReq.size;
		a3 = v1;
		t2 = *(s32*)((t3 << 2) + s1 + 188);
		a2 = t2 + 16;
		v1 = a2 | v1;
		a1 = v1 & 0x3;
		t1 = t2 + 208;
		if (a1 == 0)
		{
			do
			{
				t5 = *(s32*)(a2 + 4);
				t6 = *(s32*)(a2 + 8);
				t4 = *(s32*)(a2 + 12);
				*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
				a2 += 16:
				a3 += 16;
				*(s32*)(a3 - 12) = t5;
				*(s32*)(a3 - 8) = t6;
				*(s32*)(a3 - 4) = t4;
			} while (a2 != t1);
			s0 = *(s32*)(s1 + 204);
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
			s0 = *(s32*)(s1 + 204);
		}
	}	
	a3 = s0 + 1;
	*(s32*)(s1 + 204) = a3;
	if (s3 == 0)
	{
		s0 = s4 + 244;
		if (s5)
		{
			s5 = 0;
			*(s32*)(t0 + 0) = *(s32*)(t0 + 0) | 0x1;
		}
	}
	else
	{
		s3 = 0;
		s0 = s4 + 244;
	}

	if (*(s32*)(s0 + 200) == 0)
	{
		t5 = g_asyncReq.size;
	}
	else if (*(s32*)(s0 + 204) >= (u32)v1)
	{
		*(s32*)(s0 + 224) = 0;
		sceKernelClearEventFlag(g_eventFlag, -16385);
		v0, v1 = sceKernelSetEventFlag(g_eventFlag, 4096);
		t5 = g_asyncReq.size;
	}
	else
	{
		t5 = g_asyncReq.size;
	}
	
	t6 = t5 << 2;
	t4 = t6 + s1;
	v1 = *(s32*)(t4 + 188);
	*(s32*)(v1 + 0) = 0;
	t3 = g_asyncReq.size
	a2 = t3 ^ 0x1;
	t1 = a2 << 2;
	t2 = t1 + s1;
	g_asyncReq.size = a2;
	a1 = *(s32*)(t2 + 188);
	v0 = *(s32*)(a1 + 0);
	if (v0 != 0)
	{
		a1 = *(s32*)(s1 + 224);
		goto loc_00003D80;
	}

loc_00003EB0:		
	sceKernelClearEventFlag(g_eventFlag, -3);
	v0 = sceKernelCpuResumeIntr(s6);
	v1 = *(s32*)(sp + 0);
	goto loc_00003CDC;
}

sub_00003F74() // 
{
	a1 = 2;
	fp = 0;
	s6 = 1;
	a0 = 0x00000 + 244;
	v0 = *(s32*)(a0 + 12);
	if (v0 != a1)
	{
		return (0);
	}

	v1 = a0;
	s2 = a0;
	s7 = 2;

loc_00004000:
	v0 = sceKernelWaitEventFlag(g_eventFlag, 39, 1, sp, 0);
	s3 = v0;
	if ((s32)v0 < 0)
	{
		//a0 = 0x00000 + 20120;	// (4E98)
		//a1 = 0x00000 + 19292;

		Kprintf("%serror - at waiting for event at line %d): ret = 0x%08x pattern = 0x%08x\n", "SceUsb1Seg:", 1746, v0, *(s32*)(sp + 0));
		return (s3);
	}
	curIntCtrlState = sceKernelCpuSuspendIntr();
	a0 = *(s32*)(s2 + 12);
	//	s5 = v0;
	if (a0 != s7)
	{
	loc_00004034:
		v0, v1 = sceKernelCpuResumeIntr(curIntCtrlState);
		s5 = *(s32*)(sp + 0);
		s1 = s5 & 0x1;
		if (s1 == 0)
		{
			t9 = *(s32*)(s2 + 12);
		}
		else
		{
			s0 = 0x00000 + 244;
			if (a0 > 0)
			{
				v0 = sceKernelNotifyCallback(g_cbUID, *(s32*)(s0 + 196));
			}
			*(s32*)(s0 + 12) = 3;
			v0 = sceKernelSetEventFlag(g_eventFlag, 32, );
			t9 = *(s32*)(s2 + 12);
		}
		v1 = s2;
		if (t9 == s7)
			goto loc_00004000;
		return (s3);
	}
loc_0000408C:
	a3 = *(s32*)(sp + 0);
	a2 = a3 & 0x2;
	if (a2 == 0)
		goto loc_00004034;
	t4 = g_asyncReq.size;
	t3 = t4 << 2;
	t2 = t3 + s2;
	t1 = *(s32*)(t2 + 188);
	t0 = *(s32*)(t1 + 0);
	t5 = 0x00000;
	if (t0 == 0)
	{
		a0 = g_eventFlag;
		goto loc_00004244;
	}
	s1 = t5 + 244;

	t0 = *(s32*)(s1 + 208);
loc_000040C0:
	if (t0 == 0)
		//	goto loc_000042B4;
	{
		if (s6 == 0)
		{
			fp = 1;
			a0 = g_eventFlag;
			goto loc_00004244;
		}
		a0 = g_eventFlag;
		goto loc_00004244;
	}
	t7 = *(s32*)(t0 + 0);
	*(s32*)(s1 + 208) = t7;
	t6 = *(s32*)(t0 + 0);
	if (t6)
	{
		*(s32*)(t0 + 0) = 0;
	}
	else
	{
		*(s32*)(s1 + 212) = 0;
	}

	t3 = g_asyncReq.size;
	*(s32*)(t0 + 4) = 0;
	a3 = t0 + 16;
	t1 = t3 << 2;
	a2 = g_asyncReq.size;
	v0 = t1 + s1;
	a1 = *(s32*)(v0 + 188);
	a0 = a2 << 2;
	v1 = a0 + s1;
	t8 = *(s32*)(v1 + 188);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	a2 = t8 + 16;
	t9 = a2 | a3;
	s0 = t9 & 0x3;
	*(s32*)(t0 + 8) = t2;
	*(s32*)(t0 + 12) = t3;
	t1 = t8 + 208;
	if (s0 == 0)
	{
		do
		{
			t7 = *(s32*)(a2 + 0);
			t6 = *(s32*)(a2 + 4);
			t5 = *(s32*)(a2 + 8);
			t4 = *(s32*)(a2 + 12);
			*(s32*)(a3 + 0) = t7;
			a2 = a2 + 16;
			a3 = a3 + 16;
			*(s32*)(a3 - 12) = t6;
			*(s32*)(a3 - 8) = t5;
			*(s32*)(a3 - 4) = t4;
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
	a0 = 0x00000 + 244;
	if (s6 == 0)
	{
		if (fp)
		{
			s0 = *(s32*)(t0 + 4);
			fp = 0;
			a3 = s0 | 0x1;
			*(s32*)(t0 + 4) = a3;
		}
	}
	else
	{
		s6 = 0;
	}

	t8 = *(s32*)(a0 + 216);
	if (t8 == 0)
	{
		*(s32*)(a0 + 216) = t0;
	}

	v0 = *(s32*)(a0 + 220);
	if (v0 == 0)
	{
		*(s32*)(a0 + 220) = t0;
	}
	else
	{
		*(s32*)(v0 + 0) = t0;
		t2 = *(s32*)(a0 + 220);
		t0 = *(s32*)(t2 + 0);
		*(s32*)(a0 + 220) = t0;
	}
	s0 = 0x00000 + 244;
	v1 = *(s32*)(s0 + 196);
	a1 = *(s32*)(s0 + 204);
	a0 = g_eventFlag;
	a2 = v1 + 1;
	t9 = a1 + 1;
	*(s32*)(s0 + 196) = a2;
	a1 = 8;
	*(s32*)(s0 + 204) = t9;
	v0, v1 = sceKernelSetEventFlag(...);
	v1 = *(s32*)(s0 + 200);
	v0 = 0x00000 + 244;
	if (v1)
	{
		t1 = *(s32*)(s0 + 204);
		a0 = (u32)t1 < (u32)v1;
		if (a0 == 0)
		{
			sceKernelSetEventFlag(g_eventFlag, 4096);
			v0 = 0x00000 + 244;
		}
	}
	if ((s32)a0 <= 0)
	{
		t0 = g_asyncReq.size;
	}
	else
	{
		v0, v1 = sceKernelNotifyCallback(g_cbUID, *(s32*)(v0 + 196));
		t0 = g_asyncReq.size;
	}
	t8 = t0 << 2;
	s0 = t8 + s1;
	a3 = *(s32*)(s0 + 188);
	*(s32*)(a3 + 0) = 0;
	t7 = g_asyncReq.size;
	t5 = t7 ^ 0x1;
	t6 = t5 << 2;
	t4 = t6 + s1;
	g_asyncReq.size = t5;
	t3 = *(s32*)(t4 + 188);
	v0 = *(s32*)(t3 + 0);
	if (v0 != 0)
	{
		t0 = *(s32*)(s1 + 208);
		goto loc_000040C0;
	}
	
	a0 = g_eventFlag;
	goto loc_00004244;

loc_00004244:
	v0 = sceKernelClearEventFlag(a0, -3);
	goto loc_00004034;
}

sub_000042EC() // 
{
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelWaitEventFlag(g_eventFlag, 129, 1, sp, NULL);
	a0 = *(s32*)(sp + 0);
	v1 = a0 & 0x1;

	if (!v1)
	{
		s0 = sub_00001AF8(a0);
		if ((s32)s0 < 0)
			goto loc_000043EC;
		v0 = sceKernelSetEventFlag(g_eventFlag, 512);
	}
	curIntCtrlState = sceKernelCpuSuspendIntr();

	v1 = *(s32*)(0x00000 + 244 + 160);
	*(s32*)(0x00000 + 244 + 196) = 0;
	*(s32*)(0x00000 + 244 + 208) = 0;
	*(s32*)(0x00000 + 244 + 212) = 0;
	*(s32*)(0x00000 + 244 + 216) = 0;
	*(s32*)(0x00000 + 244 + 220) = 0;
	g_cbUID = 0;	//cbUID
	*(s32*)(0x00000 + 244 + 248) = 0;

	if (v1 > 0)
	{
		sceUsbbdReqCancel(g_bulkoutReq.data);	//0x00000 + 244 + 136
	}
	sceKernelCpuResumeIntr(curIntCtrlState);
	s0 = sceKernelWaitEventFlag(g_eventFlag, 37, 1, sp, NULL);

	sceKernelUnlockMutex(g_mutexID, 1);
	*(s32*)(0x00000 + 244 + 12) = 0;
	return (s0);
}

UpdateStatProc() // 43F4
{
	Kprintf("%sUpdateStatProc\n", "SceUsb1Seg:");
	s1 = 0x00000 + 244;
	s3 = &g_deviceReq;
	s0 = 0x80243006;

	if (*(s32*)(s3 + 24) <= 0)
	{
		//s0 = 0x80243006;
		*(s16*)(sp + 0) = *(u16*)(s1 + 252);
		*(s16*)(sp + 2) = *(u16*)(s1 + 260);
		*(s8*)(sp + 4) = *(u8*)(s1 + 264);
		*(s8*)(g_lpData + 2) = 248;
		*(s8*)(g_lpData + 3) = 5;	// size?

		memcpy(g_lpData + 4, sp, 5);
		s0 = sceUsbAcc_internal_2A100C1F(s3);
		
		if (!v0)
		{
			s0 = sceKernelWaitEventFlag(g_eventFlag, 2049, 1, sp + 16, NULL);
			if (!s0)
			{
				if (*(s32*)(sp + 16) & 0x800)
				{
					sceKernelClearEventFlag(g_eventFlag, -2049);
					sceKernelSetEventFlag(g_eventFlag, 1024);
				}
				else
				{
					*(s32*)(s1 + 12) = 0;
				}
			}
		}
	}
	else
	{
		Kprintf("%serror - Intr IN cmd is inprogress\n", "SceUsb1Seg:");
	}

	return (s0);
}
