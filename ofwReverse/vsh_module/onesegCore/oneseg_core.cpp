sub_00000000(...) // at 0x00000000 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	v0 = sub_000000B8(...);
	v0 = sub_000033B4(...);
	ra = *(s32*)(sp + 20);
	sp = sp + 32;
	return (v0);
}

sub_00000030(...) // at 0x00000030 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	v0 = *(u8*)(s1 + 1568);
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	if (v0 != 0)
		goto loc_000000A4;
	s0 = 0x00000;
	v0 = *(s32*)(s0 + 4);
	v1 = *(s32*)(v0 + 0);
	v0 = 0x00000;
	if (v1 == 0)
		goto loc_00000084;
	v0 = *(s32*)(s0 + 4);
	v0 = v0 + 4;

loc_00000068:		
	*(s32*)(s0 + 4) = v0;
	v0 = $v1(...);
	v0 = *(s32*)(s0 + 4);
	v1 = *(s32*)(v0 + 0);
	v0 = v0 + 4;
	if (v1 != 0)
		goto loc_00000068;
	v0 = 0x00000;

loc_00000084:		
	v0 = v0 + 0;
	cond = (v0 == 0);
	v0 = 1;
	if (cond)
		goto loc_000000A0;
	a0 = 0x20000;
	a0 = a0 - 15420;
	v0 = sub_00000000(...);
	v0 = 1;

loc_000000A0:		
	*(s8*)(s1 + 1568) = v0;

loc_000000A4:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000000B8(...) // at 0x000000B8 
{
	v0 = 0x00000;
	sp = sp - 16;
	a0 = 0x20000;
	a1 = 0x00000;
	v0 = v0 + 0;
	*(s32*)(sp + 0) = ra;
	a0 = a0 - 15420;
	a1 = a1 + 1572;
	if (v0 == 0)
		goto loc_000000E4;
	v0 = sub_00000000(...);

loc_000000E4:		
	v0 = 0x20000;
	v1 = *(s32*)(v0 - 15424);
	a0 = v0 - 15424;
	if (v1 == 0)
		goto loc_0000010C;
	v0 = 0x00000;
	v0 = v0 + 0;
}

sub_00000100(...) // at 0x00000100 
{
	ra = *(s32*)(sp + 0);
	if (v0 == 0)
		goto loc_00000110;
	v0 = sub_00000000(...);

loc_0000010C:		
	ra = *(s32*)(sp + 0);

loc_00000110:		
	sp = sp + 16;
	return (v0);
}

sub_00000118(...) // at 0x00000118 
{
	s3 = 0x00000;
	v1 = s3 + 1596;

	v0 = 2604;
	do
	{
		v0--;
		*(s8*)(v1 + 0) = 0;
		v1++;
	} while (v0 != 0);

	v0 = sceKernelGetSystemTimeLow();
	s2 = loc_67C;
	v0 = sub_00019A54(s2, v0);
	v0 = sceUsb1Seg_00CC60F7(0);
	*(s32*)(s2 - 64) = 0;
	v0 = sceKernelCreateFpl("SceOneSegManPool", 2, 0, 6656, 1, 0);
	s1 = v0;
	s0 = s2 - 64;
	if ((s32)v0 < 0)
	{
		*(s32*)(s0 + 28) = 0;
		goto loc_00000260;
	}
	*(s32*)(s0 + 28) = v0;
	v0 = sceKernelAllocateFpl(v0, sp, 0);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00000260;
	t0 = *(s32*)(sp + 0);
	s2 = "SceOneSegMan";
	*(s32*)(s0 + 40) = t0;
	v0 = sceKernelCreateEventFlag("SceOneSegMan", 512, 0, 0);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00000260;
	*(s32*)(s0 + 24) = v0;

	v0 = sceKernelCreateSema("SceOneSegManScanCh", 0, 0, 1, 0);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00000260;
	*(s32*)(s0 + 32) = v0;
	v0 = sceKernelCreateThread(s2, loc_10B8, 19, 2048, 0x200000, 0);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00000260;
	v0 = 0;
	*(s32*)(s0 + 20) = s1;

loc_00000244:
	return (v0);

loc_00000260:		
	s0 = s3 + 1596;
	a0 = *(s32*)(s0 + 24);
	if ((s32)a0 <= 0)
	{
		a1 = *(s32*)(s0 + 40);
		goto loc_00000280;
	}
	v0 = sceKernelDeleteEventFlag(...);
	*(s32*)(s0 + 24) = 0;
	a1 = *(s32*)(s0 + 40);

loc_00000280:		
	if (a1 != 0)
	{
		a0 = *(s32*)(s0 + 28);
		v0 = sceKernelFreeFpl(...);
		*(s32*)(s0 + 40) = 0;
	}

loc_00000288:		
	a0 = *(s32*)(s0 + 28);
	if ((s32)a0 <= 0)
	{
		v0 = s1;
		goto loc_00000244;
	}
	v0 = sceKernelDeleteFpl(...);
	*(s32*)(s0 + 28) = 0;

loc_000002A0:		
	v0 = s1;
	goto loc_00000244;
}

sub_000002C0(...) // at 0x000002C0 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v1 + 1596;
	a0 = *(s32*)(s0 + 20);
	*(s32*)(sp + 4) = ra;
	if ((s32)a0 <= 0)
		goto loc_000002F0;
	a1 = 0;
	v0 = sceKernelWaitThreadEnd(...);
	a0 = *(s32*)(s0 + 20);
	v0 = sceKernelDeleteThread(...);
	*(s32*)(s0 + 20) = 0;

loc_000002F0:		
	a0 = *(s32*)(s0 + 32);
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 24);
		goto loc_0000030C;
	}
	v0 = sceKernelDeleteSema(...);
	*(s32*)(s0 + 32) = 0;
	a0 = *(s32*)(s0 + 24);

loc_0000030C:		
	if ((s32)a0 <= 0)
	{
		a1 = *(s32*)(s0 + 40);
		goto loc_00000324;
	}
	v0 = sceKernelDeleteEventFlag(...);
	*(s32*)(s0 + 24) = 0;
	a1 = *(s32*)(s0 + 40);

loc_00000324:		
	if (a1 != 0)
	{
		a0 = *(s32*)(s0 + 28);
		v0 = sceKernelFreeFpl(...);
		*(s32*)(s0 + 40) = 0;
		goto loc_0000032C;
	}

loc_0000032C:		
	a0 = *(s32*)(s0 + 28);
	if ((s32)a0 <= 0)
	{
		v0 = sceUsb1Seg_00CC60F7(-1);	//sceUsb1Seg_19AF6734
		return (0);
	}
	v0 = sceKernelDeleteFpl(...);
}

int sub_00000370(...) // at 0x00000370 
{
	s6 = 0x00000;
	v1 = s6 + 1596;
	s5 = a2;
	s4 = a1;
	s3 = a0;
	s2 = a3;
	t0 = *(s32*)(v1 + 4);
	a0 = t0;
	if ((s32)t0 < 0)
		goto loc_00000520;
	v0 = 0x80240000;
	a1 = (u32)a1 < (u32)65;
	a0 = v0 | 0x4504;
	if (a1 == 0)
		goto loc_00000520;
	a0 = s3 - 13;
	a2 = (u32)a0 < (u32)50;
	a3 = 0x80240000;
	a0 = a3 | 0x4505;
	if (a2 == 0)
		goto loc_00000520;
	t3 = 0x00000;
	if (s2 == 0)
		goto loc_00000400;
	a0 = s2;
	v0 = sceKernelGetThreadmanIdType(...);
	t1 = 0x80240000;
	t0 = 8;
	a0 = t1 | 0x4504;
	if (v0 != t0)
		goto loc_00000520;
	t3 = 0x00000;

loc_00000400:
	s1 = t3 + 4188;
	v0 = sceUsb1SegGetModule(s1);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00000520;
	v0 = sceUsb1Seg_6B12C11E(s1 + 2);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00000520;
	t7 = 0x410000;
	a1 = t7 | 0x8937;
	a0 = s1 - 2592;
	t6 = 1;
	t5 = (u32)a1 < (u32)s5;
	*(s32*)(a0 + 12) = t6;
	*(s8*)(a0 + 2590) = s4;
	*(s8*)(a0 + 2591) = s3;	// constract param 1
	*(s32*)(a0 + 36) = s2;
	*(s32*)(a0 + 16) = 0;
	if (t5 == 0)
	{
		s1 = 1000;
		asm("mult       $s5, $s1");
		asm("mflo       $s0");
		*(s32*)(a0 + 2568) = s0;
		goto loc_00000454;
	}
	*(s32*)(a0 + 2568) = a1;

loc_00000454:
	s0 = s6 + 1596;
	a0 = *(s32*)(s0 + 24);
	if ((s32)a0 <= 0)
		goto loc_0000046C;
	a1 = 0;
	v0 = sceKernelClearEventFlag(...);

loc_0000046C:
	v0 = sceKernelCpuSuspendIntr(...);
	a3 = *(s32*)(s0 + 40);
	a0 = v0;
	v1 = 6656;
	v0 = a3;

	do
	{
		v1--;
		*(s8*)(v0 + 0) = 0;
		v0++;
	} while (v1 != 0);
	a1 = a3;

	for (int i = 0; i < 32; i++)
	{
		s3 = a1 + 208;
		*(s32*)(a1 + 0) = s3;
		a1 = s3;
	}

	s1 = s6 + 1596;
	*(s32*)(a3 + 6448) = 0;
	*(s32*)(s1 + 44) = a3;
	v0 = sceKernelCpuResumeIntr(...);
	*(s32*)(s1 + 2600) = 0;
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelStartThread(*(s32*)(s1 + 20), 4, sp);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000055C;

	v0 = sceKernelWaitEventFlag(*(s32*)(s1 + 24), 96, 1, sp + 4, 0);
	s0 = v0;
	if (v0 != 0)
		goto loc_0000051C;
	v1 = *(s32*)(sp + 4);
	s4 = v1 & 0x20;
	s6 = v1 & 0x40;
	if (s4 == 0)
	{
		if (s6 != 0)
		{
			s0 = *(s32*)(s1 + 8);
			goto loc_0000051C;
		}
		a0 = s0;
		goto loc_00000520;
	}
	s5 = 0x80240000;
	s0 = s5 | 0x4503;

loc_0000051C:		
	a0 = s0;

loc_00000520:
	return (a0);


loc_0000055C:		
	s1 = s6 + 1596;
	a0 = *(s32*)(s1 + 20);
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s1 + 24);
		goto loc_00000578;
	}
	v0 = sceKernelDeleteThread(...);
	a0 = *(s32*)(s1 + 24);

loc_00000578:		
	if ((s32)a0 <= 0)
	{
		v0 = s1;
		goto loc_0000058C;
	}
	v0 = sceKernelDeleteEventFlag(...);
	v0 = s1;

loc_0000058C:		
	v1 = 2604;

loc_00000590:		
	v1 = v1 - 1;
	*(s8*)(v0 + 0) = 0;
	v0 = v0 + 1;
	if (v1 != 0)
		goto loc_00000590;
	a0 = s0;
	goto loc_00000520;
}

sub_000005BC(...) // at 0x000005BC 
{
	sp = sp - 2528;
	*(s32*)(sp + 2516) = s1;
	s1 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 2512) = s0;
	s0 = s1 + 1596;
	*(s32*)(sp + 2520) = ra;
	a0 = *(s32*)(s0 + 24);
	v0 = sceKernelSetEventFlag(...);
	t0 = *(s32*)(s0 + 20);
	a0 = t0;
	if ((s32)t0 <= 0)
		goto loc_000005F8;
	a1 = 0;
	v0 = sceKernelWaitThreadEnd(...);
	t0 = *(s32*)(s0 + 20);

loc_000005F8:		
	t2 = *(s32*)(s0 + 28);
	t3 = *(s32*)(s0 + 24);
	t4 = *(s32*)(s0 + 32);
	t1 = s0 + 2560;
	a3 = sp;
	a2 = s0 + 64;

loc_00000610:		
	v1 = *(s32*)(a2 + 0);
	a0 = *(s32*)(a2 + 4);
	a1 = *(s32*)(a2 + 8);
	t5 = *(s32*)(a2 + 12);
	*(s32*)(a3 + 0) = v1;
	a2 = a2 + 16;
	a3 = a3 + 16;
	*(s32*)(a3 - 12) = a0;
	*(s32*)(a3 - 8) = a1;
	*(s32*)(a3 - 4) = t5;
	if (a2 != t1)
		goto loc_00000610;
	t5 = s1 + 1596;
	v1 = *(s32*)(a2 + 0);
	*(s32*)(a3 + 0) = v1;
	a0 = t5;
	v1 = 2604;
	t1 = *(s32*)(t5 + 40);

loc_00000654:		
	v1 = v1 - 1;
	*(s8*)(a0 + 0) = 0;
	a0 = a0 + 1;
	if (v1 != 0)
		goto loc_00000654;
	t6 = s1 + 1596;
	*(s32*)(t6 + 28) = t2;
	a3 = t6 + 64;
	a2 = sp;
	*(s32*)(t6 + 24) = t3;
	*(s32*)(t6 + 32) = t4;
	*(s32*)(t6 + 20) = t0;
	t0 = sp + 2496;

loc_00000684:		
	t7 = *(s32*)(a2 + 0);
	t4 = *(s32*)(a2 + 4);
	t3 = *(s32*)(a2 + 8);
	t2 = *(s32*)(a2 + 12);
	*(s32*)(a3 + 0) = t7;
	a2 = a2 + 16;
	a3 = a3 + 16;
	*(s32*)(a3 - 12) = t4;
	*(s32*)(a3 - 8) = t3;
	*(s32*)(a3 - 4) = t2;
	if (a2 != t0)
		goto loc_00000684;
	s0 = s1 + 1596;
	v0 = *(s32*)(a2 + 0);
	*(s32*)(a3 + 0) = v0;
	v0 = 0;
	*(s32*)(s0 + 40) = t1;
	ra = *(s32*)(sp + 2520);
	s1 = *(s32*)(sp + 2516);
	s0 = *(s32*)(sp + 2512);
	sp = sp + 2528;
	return (v0);
}

sub_000006D8(...) // at 0x000006D8 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = 0x00000;
	v0 = 0x80240000;
	*(s32*)(sp + 4) = s1;
	s1 = s2 + 1596;
	v1 = v0 | 0x4503;
	a1 = *(s32*)(s1 + 12);
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 12) = ra;
	if (a1 == 0)
		goto loc_00000764;
	a0 = *(s32*)(s1 + 8);
	v1 = a0;
	if ((s32)a0 < 0)
		goto loc_00000764;
	v0 = sceKernelCpuSuspendIntr(...);
	a1 = v0;
	v0 = *(s32*)(s1 + 52);
	if (v0 != 0)
	{
		*(s32*)(v0 + 208) = s0;
		goto loc_00000780;
	}
	*(s32*)(s1 + 48) = s0;
	v0 = *(s32*)(s0 + 208);
	a0 = s0;
	if (v0 == 0)
		goto loc_00000750;
	v1 = v0;

loc_00000740:		
	a2 = *(s32*)(v1 + 208);
	a0 = v1;
	v1 = a2;
	if (a2 != 0)
		goto loc_00000740;

loc_00000750:		
	v1 = s2 + 1596;

loc_00000754:		
	*(s32*)(v1 + 52) = a0;
	a0 = a1;
	v0 = sceKernelCpuResumeIntr(...);
	v1 = 0;

loc_00000764:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00000780:		
	v0 = *(s32*)(s0 + 208);
	a0 = s0;
	if (v0 == 0)
		goto loc_00000750;
	v1 = v0;

loc_00000790:		
	a3 = *(s32*)(v1 + 208);
	a0 = v1;
	v1 = a3;
	if (a3 != 0)
		goto loc_00000790;
	v1 = s2 + 1596;
	goto loc_00000754;
	sp = sp - 16;
	a1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a1 + 1596;
	v1 = 0x80240000;
	v0 = *(s32*)(s0 + 12);
	*(s32*)(sp + 4) = s1;
	a1 = v1 | 0x4503;
	s1 = a0;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 8) = s2;
	if (v0 == 0)
		goto loc_0000080C;
	a0 = *(s32*)(s0 + 8);
	a1 = a0;
	if ((s32)a0 < 0)
		goto loc_0000080C;
	v0 = sceKernelCpuSuspendIntr(...);
	s2 = v0;
	v0 = *(s32*)(s0 + 56);
	a1 = -9;
	if (v0 != 0)
		goto loc_00000828;
	*(s32*)(s1 + 0) = 0;

loc_00000800:		
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	a1 = 0;

loc_0000080C:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a1;
	sp = sp + 16;
	return (v0);

loc_00000828:		
	*(s32*)(s1 + 0) = v0;
	a0 = *(s32*)(s0 + 24);
	*(s32*)(s0 + 56) = 0;
	*(s32*)(s0 + 60) = 0;
	v0 = sceKernelClearEventFlag(...);
	goto loc_00000800;
}

sub_00000844(...) // at 0x00000844 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	a3 = 0x00000;
	a2 = a3 + 1596;
	*(s32*)(sp + 24) = s2;
	v0 = 0x80240000;
	s3 = a0;
	*(s32*)(sp + 40) = ra;
	s2 = a1;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	t0 = *(s32*)(a2 + 12);
	v1 = v0 | 0x4503;
	if (t0 == 0)
		goto loc_000008F8;
	a0 = *(s32*)(a2 + 8);
	v1 = a0;
	if ((s32)a0 < 0)
		goto loc_000008F8;
	s5 = 0;
	if (a1 == 0)
		goto loc_000008A4;
	v1 = *(s32*)(a1 + 0);
	s5 = sp;
	*(s32*)(sp + 0) = v1;

loc_000008A4:		
	s4 = a3 + 1596;
	a0 = *(s32*)(s4 + 24);
	a1 = 41;
	a2 = 1;
	a3 = sp + 4;
	t0 = s5;
	v0 = sceKernelWaitEventFlag(...);
	s1 = v0;
	if (v0 != 0)
		goto loc_00000958;
	v1 = *(s32*)(sp + 4);
	a1 = v1 & 0x8;
	a3 = v1 & 0x20;
	if (a1 != 0)
		goto loc_00000920;
	*(s32*)(s3 + 0) = 0;
	if (a3 == 0)
		goto loc_000008E8;
	t0 = 0x80240000;
	s1 = t0 | 0x4503;

loc_000008E8:		
	v1 = s1;
	if (s2 == 0)
		goto loc_000008F8;
	t1 = *(s32*)(s5 + 0);
	*(s32*)(s2 + 0) = t1;

loc_000008F8:		
	ra = *(s32*)(sp + 40);

loc_000008FC:		
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00000920:		
	v0 = sceKernelCpuSuspendIntr(...);
	a2 = *(s32*)(s4 + 56);
	a0 = *(s32*)(s4 + 24);
	s0 = v0;
	*(s32*)(s3 + 0) = a2;
	a1 = -9;
	*(s32*)(s4 + 56) = 0;
	*(s32*)(s4 + 60) = 0;
	v0 = sceKernelClearEventFlag(...);
	a0 = s0;
	v0 = sceKernelCpuResumeIntr(...);
	goto loc_000008E8;

loc_00000958:		
	t3 = 0x80020000;
	t2 = t3 | 0x1A8;
	v1 = s1;
	if (v0 != t2)
		goto loc_000008F8;
	if (s2 != 0)
	{
		*(s32*)(s2 + 0) = 0;
		goto loc_000008F8;
	}
	ra = *(s32*)(sp + 40);
	goto loc_000008FC;
}

sub_00000978(...) // at 0x00000978 
{
	a2 = 0x00000;
	v1 = *(s32*)(a2 + 1596);
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	a1 = 0x80240000;
	s2 = 1;
	*(s32*)(sp + 20) = s1;
	a3 = a1 | 0x450B;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = a2 + 1596;
	*(s32*)(sp + 28) = ra;
	if (v1 == s2)
		goto loc_00000A14;
	v0 = 0x80240000;
	a0 = 2;
	a3 = v0 | 0x450A;
	if (v1 == a0)
		goto loc_00000A14;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = v0;
	*(s32*)(s0 + 2596) = s1;
	*(s32*)(s0 + 8) = 0;
	v0 = sceKernelCpuResumeIntr(...);
	a1 = 4;
	a0 = *(s32*)(s0 + 20);
	a2 = sp;
	*(s32*)(sp + 0) = s2;
	v0 = sceKernelStartThread(...);
	a3 = v0;
	a1 = 1;
	a2 = 0;
	if ((s32)v0 < 0)
		goto loc_00000A30;
	a0 = *(s32*)(s0 + 32);
	v0 = sceKernelWaitSema(...);
	t1 = *(s32*)(s0 + 8);
	*(s32*)(s0 + 2596) = 0;
	a3 = t1;
	v1 = (s32)t1 < (s32)0;
	if (v1 == 0)
		a3 = v0;

loc_00000A14:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a3;
	sp = sp + 32;
	return (v0);

loc_00000A30:		
	*(s32*)(s0 + 2596) = 0;
	goto loc_00000A14;
}

sub_00000A38(...) // at 0x00000A38 
{
	sp = sp - 64;
	*(s32*)(sp + 52) = s1;
	a1 = 0x00000;
	v1 = 0x80240000;
	*(s32*)(sp + 48) = s0;
	s0 = a1 + 1596;
	s1 = a0;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 56) = s2;
	v0 = *(s32*)(s0 + 12);
	a1 = v1 | 0x4503;
	if (v0 == 0)
		goto loc_00000B7C;
	a0 = *(s32*)(s0 + 2564);
	v0 = 0x80240000;
	a1 = v0 | 0x4505;
	if ((s32)a0 < 0)
		goto loc_00000B7C;
	v0 = sceKernelCpuSuspendIntr(...);
	t9 = s0 + 2572;
	t5 = *(u16*)(t9 + 16);
	t8 = *(s32*)(s0 + 2572);
	s2 = *(s32*)(t9 + 4);
	t7 = *(s32*)(t9 + 8);
	t6 = *(s32*)(t9 + 12);
	a0 = v0;
	*(s32*)(sp + 0) = t8;
	*(s32*)(sp + 4) = s2;
	*(s32*)(sp + 8) = t7;
	*(s32*)(sp + 12) = t6;
	*(s16*)(sp + 16) = t5;
	v0 = sceKernelCpuResumeIntr(...);
	*(s32*)(s1 + 12) = 0;
	t4 = *(u8*)(s0 + 2577);
	NONE;
	*(s32*)(s1 + 12) = t0;
	t3 = *(u8*)(s0 + 2577);
	t2 = t3 & 0x1E;
	t1 = t2 << 1;
	v1 = t0 | t1;
	*(s32*)(s1 + 12) = v1;
	a3 = *(u8*)(s0 + 2577);
	a2 = a3 & 0x1;
	if (a2 == 0)
	{
		v1 = *(u8*)(s0 + 2578);
		goto loc_00000AF4;
	}
	a1 = v1 | 0x40;
	*(s32*)(s1 + 12) = a1;
	v1 = *(u8*)(s0 + 2578);

loc_00000AF4:		
	a0 = (s8)v1;
	if ((s32)a0 < 0)
	{
		a2 = *(s32*)(s1 + 12);
		goto loc_00000F14;
	}

loc_00000B00:		
	a1 = *(s32*)(s1 + 12);
	t1 = v1 & 0x70;
	a0 = t1 << 4;
	v1 = a1 | a0;
	*(s32*)(s1 + 12) = v1;
	a1 = 1;
	v0 = 2;
	t0 = *(u8*)(s0 + 2578);
	a3 = t0 & 0xE;
	a2 = a3 << 10;
	t3 = v1 | a2;
	*(s32*)(s1 + 12) = t3;
	t9 = *(u8*)(s0 + 2578);
	t8 = *(u8*)(s0 + 2579);
	s2 = t9 & 0x1;
	t7 = t8 & 0xC0;
	t5 = s2 << 16;
	t6 = t7 << 8;
	t4 = t5 | t6;
	t2 = t3 | t4;
	*(s32*)(s1 + 12) = t2;
	t1 = *(s32*)(s0 + 2564);
	a0 = *(u8*)(s0 + 2592);
	t0 = t1 << 1;
	a3 = t0 + 6;
	s2 = a1 << a3;
	if (a0 == v0)
		goto loc_00000D84;
	t3 = 3;
	v0 = *(u8*)(sp + 3);
	if (a0 == t3)
		goto loc_00000B98;

loc_00000B78:		
	a1 = 0;

loc_00000B7C:		
	ra = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v0 = a1;
	sp = sp + 64;
	return (v0);

loc_00000B98:		
	*(s32*)(s1 + 0) = v0;
	t5 = *(s32*)(s0 + 2600);
	t4 = (u32)t5 < (u32)21;
	if (t4 == 0)
	{
		*(s32*)(s1 + 0) = 0;
		goto loc_00000BAC;
	}

loc_00000BAC:		
	t8 = *(s32*)(s1 + 0);
	t7 = t8 - 8;
	t6 = (u32)t7 < (u32)2;
	if (t6 != 0)
	{
		*(s32*)(s1 + 20) = a1;
		goto loc_00000BC8;
	}

loc_00000BC0:		
	*(s32*)(s1 + 20) = 0;
	goto loc_00000B78;

loc_00000BC8:		
	a2 = sp + 32;
	a3 = sp + 34;
	a0 = sp;
	a1 = sp + 36;
	v0 = sub_00000F24(...);
	a2 = *(s32*)(s1 + 0);
	t9 = 9;
	cond = (a2 == t9);
	t9 = 0x70000;
	if (cond)
		goto loc_00000CA8;

loc_00000BEC:		
	asm("lwc1       $fpr02, -16728($t9)");
	asm("swc1       $fpr02, 8($s1)");
	asm("swc1       $fpr02, 4($s1)");
}

loc_00000BF8(...) // at 0x00000BF8 
{

loc_00000BF8:		
	a2 = *(u16*)(sp + 34);
	v1 = 0x20000;
	a0 = v1 - 14512;
	a1 = 0;

loc_00000C08:		
	t0 = *(u16*)(a0 + 0);
	a3 = (u32)t0 < (u32)a2;
	if (a3 != 0)
		goto loc_00000C44;
	a1 = a1 + 1;
	s2 = (u32)a1 < (u32)41;
	a0 = a0 + 2;
	if (s2 != 0)
		goto loc_00000C08;

loc_00000C28:		
	a2 = 41;
	cond = (a1 != a2);
	a1 = 0;
	if (cond)
		goto loc_00000B7C;
	a1 = 0x70000;
	asm("lwc1       $fpr00, -16704($a1)");

loc_00000C3C:		
	asm("swc1       $fpr00, 16($s1)");
	goto loc_00000B78;

loc_00000C44:		
	if (a1 == 0)
	{
		*(s32*)(s1 + 16) = 0;
		goto loc_00000C28;
	}
	v0 = a1 - 1;
	t2 = (u32)v0 >> 1;
	if ((s32)v0 < 0)
		goto loc_00000C90;
	asm("mtc1       $v0, $fcr3");
	asm("cvt.s.w    $fpr04, $fpr03");

loc_00000C60:		
	t5 = *(u16*)(a0 + 0);
	t3 = *(u16*)(a0 - 2);
	t4 = t3 - t5;
	a0 = t3 - a2;
	asm("mtc1       $t4, $fcr9");
	asm("mtc1       $a0, $fcr10");
	asm("cvt.s.w    $fpr00, $fpr09");
	asm("cvt.s.w    $fpr08, $fpr10");
	asm("div.s      $fpr07, $fpr08, $fpr00");
	asm("add.s      $fpr06, $fpr04, $fpr07");
	asm("swc1       $fpr06, 16($s1)");
	goto loc_00000C28;

loc_00000C90:		
	s0 = v0 & 0x1;
	t1 = s0 | t2;
	asm("mtc1       $t1, $fcr4");
	asm("cvt.s.w    $fpr05, $fpr04");
	asm("add.s      $fpr04, $fpr05, $fpr05");
	goto loc_00000C60;

loc_00000CA8:		
	a1 = *(s32*)(sp + 36);
	a3 = 0xFF0000;
	v1 = a3 | 0xFFFF;
	a0 = *(u16*)(sp + 32);
	if (a1 == v1)
		goto loc_00000D6C;
	s0 = a0 & 0xFFFF;

loc_00000CC0:		
	asm("mtc1       $s0, $fcr6");
	cond = ((s32)s2 < 0);
	asm("cvt.s.w    $fpr01, $fpr06");
	if (cond)
		goto loc_00000D50;
	asm("mtc1       $s2, $fcr7");
	asm("cvt.s.w    $fpr00, $fpr07");

loc_00000CD4:		
	asm("div.s      $fpr09, $fpr01, $fpr00");
	cond = ((s32)a1 < 0);
	asm("swc1       $fpr09, 4($s1)");
	if (cond)
		goto loc_00000D34;
	asm("mtc1       $a1, $fcr10");
	asm("cvt.s.w    $fpr00, $fpr10");

loc_00000CE8:		
	v0 = (u32)s2 >> 1;
	if ((s32)s2 < 0)
		goto loc_00000D1C;
	asm("mtc1       $s2, $fcr12");
	asm("cvt.s.w    $fpr01, $fpr12");

loc_00000CF8:		
	asm("div.s      $fpr18, $fpr00, $fpr01");
	t8 = 0x70000;
	asm("lwc1       $fpr19, -16724($t8)");
	t7 = 0x70000;
	asm("lwc1       $fpr17, -16720($t7)");
	asm("div.s      $fpr16, $fpr18, $fpr19");
	asm("mul.s      $fpr15, $fpr16, $fpr17");
	asm("swc1       $fpr15, 8($s1)");
	goto loc_00000BF8;

loc_00000D1C:		
	t6 = s2 & 0x1;
	s2 = t6 | v0;
	asm("mtc1       $s2, $fcr14");
	asm("cvt.s.w    $fpr13, $fpr14");
	asm("add.s      $fpr01, $fpr13, $fpr13");
	goto loc_00000CF8;

loc_00000D34:		
	t5 = (u32)a1 >> 1;
	t4 = a1 & 0x1;
	a1 = t4 | t5;
	asm("mtc1       $a1, $fcr11");
	asm("cvt.s.w    $fpr01, $fpr11");
	asm("add.s      $fpr00, $fpr01, $fpr01");
	goto loc_00000CE8;

loc_00000D50:		
	t2 = s2 & 0x1;
	t3 = (u32)s2 >> 1;
	a0 = t2 | t3;
	asm("mtc1       $a0, $fcr0");
	asm("cvt.s.w    $fpr08, $fpr00");
	asm("add.s      $fpr00, $fpr08, $fpr08");
	goto loc_00000CD4;

loc_00000D6C:		
	t0 = 0xFFFF;
	t1 = a0 & 0xFFFF;
	s0 = a0 & 0xFFFF;
	if (t1 != t0)
		goto loc_00000CC0;
	t9 = 0x70000;
	goto loc_00000BEC;

loc_00000D84:		
	v0 = *(u8*)(sp + 3);
	s0 = 10;
	*(s32*)(s1 + 0) = v0;
	if (v0 != s0)
		goto loc_00000BC0;
	*(s32*)(s1 + 20) = a1;
	a0 = sp;
	a2 = sp + 32;
	a3 = sp + 34;
	a1 = sp + 36;
	v0 = sub_00000F24(...);
	a0 = *(u16*)(sp + 32);
	t2 = a0 & 0xFFFF;
	asm("mtc1       $t2, $fcr2");
	cond = ((s32)s2 < 0);
	asm("cvt.s.w    $fpr01, $fpr02");
	if (cond)
		goto loc_00000EF8;
	asm("mtc1       $s2, $fcr3");
	asm("cvt.s.w    $fpr00, $fpr03");

loc_00000DC8:		
	asm("div.s      $fpr05, $fpr01, $fpr00");
	a1 = 0x70000;
	asm("lwc1       $fpr01, -16728($a1)");
	asm("c.lt.s     $fpr01, $fpr05");
	cond = (asm("bc1f       loc_00000DE8"));
	asm("swc1       $fpr05, 4($s1)");
	if (cond)
		goto ;
	asm("swc1       $fpr01, 4($s1)");

loc_00000DE8:		
	t7 = a0 & 0xFFFF;
	t6 = (u32)t7 < (u32)s2;
	if (t6 == 0)
	{
		asm("swc1       $fpr01, 8($s1)");
		goto loc_00000E44;
	}
	v0 = *(s32*)(sp + 36);
	a2 = (u32)v0 >> 1;
	if ((s32)v0 < 0)
		goto loc_00000EE0;
	asm("mtc1       $v0, $fcr6");
	asm("cvt.s.w    $fpr01, $fpr06");

loc_00000E0C:		
	v1 = a0 & 0xFFFF;
	v0 = s2 - v1;
	t0 = (u32)v0 >> 1;
	if ((s32)v0 < 0)
		goto loc_00000EC8;
	asm("mtc1       $v0, $fcr8");
	asm("cvt.s.w    $fpr00, $fpr08");

loc_00000E24:		
	asm("div.s      $fpr13, $fpr01, $fpr00");
	t1 = 0x70000;
	asm("lwc1       $fpr14, -16724($t1)");
	a0 = 0x70000;
	asm("lwc1       $fpr12, -16720($a0)");
	asm("div.s      $fpr11, $fpr13, $fpr14");
	asm("mul.s      $fpr01, $fpr11, $fpr12");
	asm("swc1       $fpr01, 8($s1)");

loc_00000E44:		
	asm("lwc1       $fpr01, -16728($a1)");
	asm("lwc1       $fpr15, 8($s1)");
	asm("c.lt.s     $fpr01, $fpr15");
	if (asm("bc1tl      loc_00000E5C"))
	{
		asm("swc1       $fpr01, 8($s1)");
		goto ;
	}

loc_00000E5C:		
	v0 = *(u16*)(sp + 34);
	if (v0 == 0)
	{
		*(s32*)(s1 + 16) = 0;
		goto loc_00000B78;
	}
	asm("mtc1       $v0, $fcr19");
	a1 = 0x70000;
	asm("lwc1       $fpr18, -16716($a1)");
	asm("cvt.s.w    $fpr17, $fpr19");
	asm("mtc1       $zr, $fcr2");
	asm("sub.s      $fpr16, $fpr18, $fpr17");
	asm("div.s      $fpr00, $fpr16, $fpr17");
	asm("c.lt.s     $fpr00, $fpr02");
	v0 = 10;
	if (asm("bc1f       loc_00000E9C"))
		goto ;
	asm("swc1       $fpr02, 16($s1)");
	goto loc_00000B78;

loc_00000E9C:		
	v0 = v0 - 1;
	cond = ((s32)v0 >= 0);
	asm("sqrt.s     $fpr00, $fpr00");
	if (cond)
		goto loc_00000E9C;
	t2 = 0x70000;
	asm("lwc1       $fpr05, -16712($t2)");
	s0 = 0x70000;
	asm("lwc1       $fpr03, -16708($s0)");
	asm("mul.s      $fpr04, $fpr00, $fpr05");
	asm("sub.s      $fpr02, $fpr04, $fpr05");
	asm("mul.s      $fpr00, $fpr02, $fpr03");
	goto loc_00000C3C;

loc_00000EC8:		
	a3 = v0 & 0x1;
	s2 = a3 | t0;
	asm("mtc1       $s2, $fcr10");
	asm("cvt.s.w    $fpr09, $fpr10");
	asm("add.s      $fpr00, $fpr09, $fpr09");
	goto loc_00000E24;

loc_00000EE0:		
	t9 = v0 & 0x1;
	t8 = t9 | a2;
	asm("mtc1       $t8, $fcr1");
	asm("cvt.s.w    $fpr07, $fpr01");
	asm("add.s      $fpr01, $fpr07, $fpr07");
	goto loc_00000E0C;

loc_00000EF8:		
	t4 = s2 & 0x1;
	t5 = (u32)s2 >> 1;
	t3 = t4 | t5;
	asm("mtc1       $t3, $fcr0");
	asm("cvt.s.w    $fpr04, $fpr00");
	asm("add.s      $fpr00, $fpr04, $fpr04");
	goto loc_00000DC8;

loc_00000F14:		
	v1 = a2 | 0x80;
	*(s32*)(s1 + 12) = v1;
	v1 = *(u8*)(s0 + 2578);
	goto loc_00000B00;
}

sub_00000F24(...) // at 0x00000F24 
{
	*(s8*)(a1 + 3) = 0;
	t2 = *(u8*)(a0 + 8);
	*(s8*)(a1 + 2) = t2;
	t1 = *(u8*)(a0 + 9);
	*(s8*)(a1 + 1) = t1;
	t0 = *(u8*)(a0 + 10);
	*(s8*)(a1 + 0) = t0;
	a1 = *(u8*)(a0 + 11);
	*(s8*)(a2 + 1) = a1;
	v0 = *(u8*)(a0 + 12);
	*(s8*)(a2 + 0) = v0;
	v1 = *(u8*)(a0 + 13);
	*(s8*)(a3 + 1) = v1;
	v0 = *(u8*)(a0 + 14);
	*(s8*)(a3 + 0) = v0;
	return (v0);
}

SceOneSegManNotify()	// F64
{
	s0 = 0x00000 + 1640;	//0x668
	v0 = sceUsb1SegGetPacketBuffer(s0);

	if ((s32)v0 <= 0)
	{
		a1 = 32;
		if (v0 != 0x80244503)
		{
			return (0);
		}
	}
	
	sceKernelSetEventFlag(*(s32*)(s0 - 20), 2);
	return (0);
}

sub_00000FBC(*a0) // at 0x00000FBC 
{
	a1 = *(u8*)(a0 + 188);
	v1 = -1;
	if (a1 != 0)
		goto loc_00001014;
	a1 = *(u8*)(a0 + 189);
	if (a1 != 0)
		goto loc_00001014;
	a2 = *(u8*)(a0 + 190);
	if (a2 != 0)
		goto loc_00001014;
	v0 = *(u8*)(a0 + 191);
	v1 = -3;
	a1 = v0 & 0x1;
	if (v0 == 0)
		goto loc_0000101C;
	a2 = v0 & 0x2;
	v1 = -2;
	if (a1 != 0)
		goto loc_00001014;
	a0 = v0 & 0x4;
	v1 = -4;
	if (a2 != 0)
		goto loc_00001014;
	v1 = -5;
	a3 = -1;
	if (a0 == 0)
		v1 = a3;

loc_00001014:
	v0 = v1;
	return (v0);

loc_0000101C:
	t0 = *(u8*)(a0 + 0);
	a0 = t0 ^ 0x47;
	if (a0 == 0)
		v1 = 0;
	goto loc_00001014;
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 1620);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 8;
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

Func()	//0x00001050
{
	sceUsb1SegInitTuner();//v0 = sceUsb1Seg_CE74BB4B(...);
	return (v0);
}

sub_0000106C(...) // at 0x0000106C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	v1 = a0 + 1596;
	a0 = *(s32*)(v1 + 32);
	s0 = v0;
	a1 = 0;
	a2 = 0;
	*(s32*)(v1 + 2596) = 0;
	v0 = sceKernelCancelSema(...);
	a0 = s0;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_10B8()
{
	if (*(s32*)(a1 + 0))
	{
		v0 = sub_000019B8(...);
	}
	else
	{
		v0 = sub_000010F8(...);
	}

	*(s32*)(0x00000 + 1596) = 0;
	return (0);
}

sub_000010F8(...) // at 0x000010F8 
{
	*(s32*)(sp + 1096) = 0;
	*(s32*)(sp + 1104) = 0;
	*(s32*)(sp + 1100) = 1;

	v1 = sp + 32;
	for (int i = 0; i < 972; i++)
	{
		*(s8*)(v1 ++) = 0;
	}

	v0 = sceKernelCreateCallback("SceOneSegManNotify", SceOneSegManNotify, 0);
	s1 = v0;
	v0 = 0;
	if ((s32)s1 < 0)
	{
		return (0);
	}
	a1 = 0x00000;
	s2 = 0x00000 + 1596;	//63c
	a0 = *(s32*)(s2 + 2568);
	fp = s1;
	if (a0 != 0)
	{
		v0 = sceKernelCreateVTimer("SceOneSegMan", 0);
		s1 = v0;
		if (v0 > 0)
		{
			*(s32*)(s2 + 2564) = 2;
			s3 = sp + 1056;
			v0 = sceKernelUSec2SysClock(*(s32*)(s2 + 2568), s3);
			*(s32*)(sp + 1096) = s1;
			v0 = sceKernelSetVTimerHandler(s1, s3, 0x00000 + 6748, s2);
		}
	}
	else
	{
		*(s32*)(s2 + 2564) = -1;
	}
	a0 = 0x00000 + 1596;
	a1 = *(u8*)(a0 + 2590);
	t2 = 64;
	v1 = a1 & 0xFF;
	v0 = 1;
	if (v1 == t2)
	{
		*(s8*)(sp + 0) = v0;
	}
	else if (v1 == 0)
	{
		v0 = sub_00002840(a0 + 64);
		v0 = v0 & 0x3 + 1;
		*(s8*)(sp + 0) = v0;
	}
	else
	{
		*(s8*)(sp + 0) = a1;
	}

loc_000011B4:	

	s2 = 0;
	s0 = 0x00000;
	s3 = sp + 1008;
	do
	{
		*(s32*)(sp + 1088) = sub_00002840(0x00000 + 1660);
		t6 = s3 + s2;
		s2 += 4;
		asm("lwl        $a2, 1091($sp)");
		asm("lwr        $a2, 1088($sp)");
		asm("swl        $a2, 3($t6)");
		asm("swr        $a2, 0($t6)");
		s4 = *(u8*)(sp + 0);
	} while (s2 < 16);

	v0 = sub_000195E8(sp + 32, 128, 128, 0x00000 + 8 + s4 << 4);

	s2 = 0x00000 + 1596;	//63c
	v0 = sub_00001BA8(sp + 32, s3, sp + 1072);

	asm("lwl        $v1, 1075($sp)");
	asm("lwr        $v1, 1072($sp)");
	asm("lwl        $t0, 1079($sp)");
	asm("lwr        $t0, 1076($sp)");
	asm("lwl        $t1, 1083($sp)");
	asm("lwr        $t1, 1080($sp)");
	asm("lwl        $v0, 1087($sp)");
	asm("lwr        $v0, 1084($sp)");
	asm("swl        $v1, 4($sp)");
	asm("swr        $v1, 1($sp)");
	asm("swl        $t0, 8($sp)");
	asm("swr        $t0, 5($sp)");
	asm("swl        $t1, 12($sp)");
	asm("swr        $t1, 9($sp)");
	asm("swl        $v0, 16($sp)");
	asm("swr        $v0, 13($sp)");

	v0 = sceUsb1SegConstruct(*(u8*)(s2 + 2591), sp, fp, 0);	// dst, src, uid, uid
	s1 = v0;
	*(s32*)(s2 + 8) = v0;
	v0 = sceKernelSetEventFlag(*(s32*)(s2 + 24), 64);
	v1 = *(s32*)(sp + 1096);
	if ((s32)s1 < 0)
	{
		if (v1 > 0)
		{
			v0 = sceKernelDeleteVTimer(v1);
		}
		if (fp > 0)
		{
			v0 = sceKernelDeleteCallback(fp);
		}
		return (s1v0);
	}
	v0 = sceUsb1SegPutPacketBuffer(*(s32*)(s2 + 44));
	s1 = v0;
	if ((s32)v0 < 0)
	{
		v0 = sceUsb1SegDestruct();
		a0 = *(s32*)(sp + 1096);
		if ((s32)a0 <= 0)
		{
			if (fp > 0)
			{
				v0 = sceKernelDeleteCallback(fp);
			}
			*(s32*)(s2 + 8) = s1;
			return (s1);
		}
		v0 = sceKernelDeleteVTimer(...);
		v0 = sub_00002840(a0 + 64);
		//t4 = v0 & 0x3;
		v0 = v0 & 0x3 + 1;
		*(s8*)(sp + 0) = v0;
		goto loc_000011B4;
	}
	a0 = *(s32*)(s2 + 2564);
	if (a0 >= 0)
	{
		v0 = sceUsb1SegSetBPER(a0);
	}

	s7 = 0x00000;
	v0 = sceKernelCpuSuspendIntr(...);
	*(s32*)(s2 + 44) = 0;
	*(s32*)(0x00000 + 1596) = 1;
	v0 = sceKernelCpuResumeIntr(v0);
	a2 = *(s32*)(sp + 1096);
	if (a2 > 0)
	{
		v0 = sceKernelStartVTimer(a2);
	}

	v0 = sub_000195E8(sp + 32, 128, 128, s3);
	*(s32*)(sp + 1024) = *(s32*)(sp + 1008);
	*(s32*)(sp + 1028) = *(s32*)(sp + 1012);
	*(s32*)(sp + 1032) = *(s32*)(sp + 1016);
	*(s32*)(sp + 1036) = *(s32*)(sp + 1020);

loc_00001324:
	do
	{
		//s3 = 0x00000 + 1596;
		v0 = sceKernelWaitEventFlagCB(*(s32*)(0x00000 + 1596 +24), 51, 1, sp + 1092, 0);
	} while (v0 != 0);

	v1 = *(s32*)(sp + 1092);
	a3 = v1 & 0x2;
	s0 = v1 & 0x10;
	if (a3 == 0)
		goto loc_00001388;
	t3 = 0x00000;
	t2 = t3 + 1596;
	t1 = *(s32*)(t2 + 44);
	s2 = 0x00000;
	if (t1 != 0)
		goto loc_00001470;

loc_0000136C:

loc_00001370:
	v0 = sceKernelClearEventFlag(*(s32*)(0x00000 + 1596 + 24), -3);
	v1 = *(s32*)(sp + 1092);
	s0 = v1 & 0x10;

loc_00001388:		
	s5 = 0x00000;
	if (s0 != 0)
	{
		//s0 = 0x00000 + 1596;
		//s1 = 2;
		v0 = sceKernelClearEventFlag(*(s32*)(0x00000 + 1596 + 24), -17);
		v1 = *(u8*)(0x00000 + 1596 + 2592);
		//a0 = 0x00000 + 1596 + 2572;
		a1 = 15;
		if (v1 != 2)
		{
			if (v1 == 3)
			{
				a1 = 18;
			}
			else
			{
				v1 = *(s32*)(sp + 1092);
				goto loc_00001390;
			}
		}
		v0 = sceUsb1SegGetDebug(0x00000 + 1596 + 2572, a1);	// ptr, size?
		v1 = *(s32*)(sp + 1092);
	}

loc_00001390:		
	s7 = v1 & 0x20;
	s3 = v1 & 0x1;
	if (s7 != 0)
	{
		s5 = 0x00000 + 1596;
		*(s32*)(s5 + 12) = 0;
	}
	else
	{
		t0 = 0x00000;
		if (s3 == 0)
			goto loc_00001324;
	}

	t0 = *(s32*)(sp + 1096);
	if (t0 > 0)
	{
		v0 = sceKernelStopVTimer(t0);
	}
	v0 = sceUsb1SegDestruct();

	if (*(s32*)(sp + 1096) > 0)
	{
		v0 = sceKernelDeleteVTimer(t1);
	}
	if (fp > 0)
	{
		v0 = sceKernelDeleteCallback(fp);
	}
	return (0);

loc_00001470:		
	s0 = s2 + 1596;
	v0 = sceKernelCpuSuspendIntr(...);
	*(s32*)(s0 + 48) = 0;
	s4 = *(s32*)(s0 + 48);
	*(s32*)(s0 + 44) = 0;
	*(s32*)(sp + 1112) = 0;
	*(s32*)(sp + 1108) = *(s32*)(s0 + 44);
	v0 = sceKernelCpuResumeIntr(v0);
	t6 = 0x00000 + 1596;
	t5 = *(u8*)(t6 + 2590);
	t4 = 64;
	s5 = *(s32*)(sp + 1108);	// packet size?
	if (t5 == 64)
		goto loc_00001894;
	if (s5 == 0)
	{
		v0 = sceKernelCpuSuspendIntr(...);
		s0 = v0;
		v0 = 0x00000 + 1596;
		*(s32*)(v0 + 48) = s6;
		if (!s6)
		{
			*(s32*)(v0 + 52) = 0;
		}
		goto loc_0000167C;
	}

loc_000014BC:		
	v0 = *(s32*)(sp + 1100);
	if (s4 == 0)
		goto loc_00001848;
	*(s32*)(s4 + 0) = 0;
	s2 = 0;
	v0 = sub_00003A30(*(s32*)(s5 + 8), *(s32*)(s5 + 12), 1000, 0);
	*(s32*)(s4 + 4) = v0;

loc_000014E4:		
	s1 = sp + 1024;
	s0 = sp + 1040;
	s7 = 71;
	s3 = s5 + s2;

loc_000014F4:
	v0 = sub_00002148(sp + 32, s3 + 16, s0);
	t1 = s4 + s2;
	t0 = t1 + 16;
	a3 = 0;

loc_00001510:		
	t8 = s0 + a3;
	t7 = s1 + a3;
	t5 = *(u8*)(t8 + 0);
	t6 = *(u8*)(t7 + 0);
	t3 = t0 + a3;
	a3 = a3 + 1;
	asm("xor        $t4, $t5, $t6");
	t2 = (s32)a3 < (s32)16;
	*(s8*)(t3 + 0) = t4;
	if (t2 != 0)
		goto loc_00001510;

	if (s2 != 0)
	{
		s2 = s2 + 16;
		goto loc_00001550;
	}
	t9 = *(u8*)(s4 + 16);
	if (t9 == s7)
	{
		a1 = *(u8*)(s4 + 17);
		goto loc_000017C8;
	}
	s2 +=16;

loc_00001550:
	asm("lwl        $t1, 19($s3)");
	asm("lwr        $t1, 16($s3)");
	asm("lwl        $v1, 23($s3)");
	asm("lwr        $v1, 20($s3)");
	asm("lwl        $a0, 27($s3)");
	asm("lwr        $a0, 24($s3)");
	asm("lwl        $a1, 31($s3)");
	asm("lwr        $a1, 28($s3)");
	asm("swl        $t1, 1027($sp)");
	asm("swr        $t1, 1024($sp)");
	asm("swl        $v1, 1031($sp)");
	asm("swr        $v1, 1028($sp)");
	asm("swl        $a0, 1035($sp)");
	asm("swr        $a0, 1032($sp)");
	asm("swl        $a1, 1039($sp)");
	asm("swr        $a1, 1036($sp)");
//	a3 = (s32)s2 < (s32)192;
	s3 = s5 + s2;
	if (s2 < 192)
		goto loc_000014F4;

loc_0000159C:		
	a0 = s4 + 16;
	v0 = sub_00000FBC(...);
	t8 = 0x00000;
	if ((s32)v0 < 0)
	{
		t7 = -1;
		t0 = -2;
		if (v0 == t7)
		{
			a2 = *(s32*)(s4 + 0);
			v1 = 0x00000;
			t8 = v1 + 1596;
			a1 = a2 | 0x2;
			*(s32*)(s4 + 0) = a1;
			a0 = *(s32*)(t8 + 2600);
			t9 = a0 + 1;
			*(s32*)(t8 + 2600) = t9;
			goto loc_000015B4;
		}
		if (v0 == t0)
		{
			a3 = *(s32*)(s4 + 0);
			v0 = a3 | 0x20;
			goto loc_00001780;
		}
		s0 = -3;
		if (v0 == s0)
		{
			s1 = *(s32*)(s4 + 0);
			v0 = s1 | 0x10;
			goto loc_00001780;
		}
		s2 = -4;
		s3 = -5;
		if (v0 == s2)
		{
			s7 = *(s32*)(s4 + 0);
			v0 = s7 | 0x8;
			goto loc_00001780;
		}
		t4 = 0x00000;
		if (v0 == s3)
			goto loc_00001778;
		t6 = *(s32*)(s4 + 0);
		t2 = t4 + 1596;
		t5 = t6 | 0x2;
		*(s32*)(s4 + 0) = t5;
		t3 = *(s32*)(t2 + 2600);
		v0 = t3 + 1;
		*(s32*)(t2 + 2600) = v0;
		goto loc_000015B4;
	}
	t7 = t8 + 1596;
	*(s32*)(t7 + 2600) = 0;

loc_000015B4:		
	a1 = *(s32*)(sp + 1100);
	a0 = *(s32*)(s5 + 4);
	if (a1 != 0)
		a1 = 0;
	t9 = a0 & 0x1;
	*(s32*)(sp + 1100) = a1;
	if (t9 == 0)
		goto loc_000015D8;
	t0 = *(s32*)(s4 + 0);
	v1 = t0 | 0x1;
	*(s32*)(s4 + 0) = v1;

loc_000015D8:		
	a3 = *(s32*)(sp + 1104);

	if (a3)
	{
		s1 = *(s32*)(s4 + 0);
		*(s32*)(sp + 1104) = 0;
		s0 = s1 | 0x1;
		*(s32*)(s4 + 0) = s0;
	}
	*(s32*)(sp + 1112) = s4;

loc_000015F8:		
	s4 = *(s32*)(s4 + 208);

loc_000015FC:		
	s5 = *(s32*)(s5 + 0);
	if (s5 != 0)
		goto loc_000014BC;

loc_00001608:		
	s5 = *(s32*)(sp + 1112);
	if (s5 == 0)
	{
		v0 = sceKernelCpuSuspendIntr(...);
		t6 = 0x00000;
		s0 = v0;
		v0 = t6 + 1596;
		*(s32*)(v0 + 48) = s6;
		if (s6 != 0)
			goto loc_0000167C;
		*(s32*)(v0 + 52) = 0;
		goto loc_0000167C;

	}
	s7 = 0x00000;
	v0 = sceKernelCpuSuspendIntr(...);
	s3 = *(s32*)(sp + 1112);
	v1 = s7 + 1596;
	s2 = *(s32*)(s3 + 208);
	s0 = v0;
	*(s32*)(v1 + 48) = s2;
	if (s2 != 0)
		goto loc_00001638;
	*(s32*)(v1 + 52) = 0;

loc_00001638:		
	t1 = *(s32*)(sp + 1112);
	*(s32*)(t1 + 208) = 0;
	if (s4 == s6)
	{
		t5 = *(s32*)(sp + 1112);
		*(s32*)(v1 + 48) = t5;
		goto loc_0000167C;
	}
	s4 = *(s32*)(v1 + 56);
	if (s4 != 0)
	{
		t2 = *(s32*)(v1 + 60);
		*(s32*)(t2 + 208) = s6;
		s6 = *(s32*)(v1 + 60);
		a2 = *(s32*)(s6 + 208);
		v1 = *(s32*)(a2 + 208);
		if (v1 != 0)
		{
			a2 = v1;
			goto loc_00001658;
		}
		t4 = 0x00000;
		goto loc_00001668;
	}
	a2 = s6;
	*(s32*)(v1 + 56) = s6;

loc_00001658:		
	t3 = *(s32*)(a2 + 208);
	v1 = t3;
	if (t3 != 0)
	{
		a2 = v1;
		goto loc_00001658;
	}
	t4 = 0x00000;

loc_00001668:		
	v0 = t4 + 1596;
	a0 = *(s32*)(v0 + 24);
	*(s32*)(v0 + 60) = a2;
	a1 = 8;
	v0 = sceKernelSetEventFlag(...);

loc_0000167C:		
	a0 = s0;
	v0 = sceKernelCpuResumeIntr(...);
	if (a0 == 0)
		goto loc_00001370;
	v0 = sceUsb1SegPutPacketBuffer(*(s32*)(sp + 1108));
	t7 = 0x80244503;
	if (v0 != t7)
		goto loc_00001370;
	v1 = 0x00000;
	a2 = 0x00000 + 1596;
	a0 = *(s32*)(a2 + 24);
	a1 = 32;
	v0 = sceKernelSetEventFlag(...);
	a1 = *(s32*)(sp + 1092);
	a0 = a1 | 0x20;
	*(s32*)(sp + 1092) = a0;
	goto loc_0000136C;

loc_00001778:		
	t1 = *(s32*)(s4 + 0);
	v0 = t1 | 0x4;

loc_00001780:		
	*(s32*)(s4 + 0) = v0;
	goto loc_000015B4;

loc_000017C8:		
	v1 = 31;
	a0 = a1 & 0x1F;
	if (a0 != v1)
	{
		s2 = s2 + 16;
		goto loc_00001550;
	}
	t0 = *(u8*)(s4 + 18);
	a2 = 255;
	if (t0 != a2)
	{
		s2 = s2 + 16;
		goto loc_00001550;
	}
	s0 = (s32)s2 < (s32)192;
	if (s0 == 0)
		goto loc_0000159C;
	s2 = *(u8*)(s4 + 16);
	s1 = 71;

loc_00001800:		
	if (s2 != s1)
		goto loc_0000159C;
	t1 = *(u8*)(s4 + 17);
	s7 = 31;
	s3 = t1 & 0x1F;
	t2 = 255;
	if (s3 != s7)
		goto loc_0000159C;
	v0 = *(u8*)(s4 + 18);
	if (v0 != t2)
		goto loc_0000159C;
	t6 = *(s32*)(s5 + 192);
	*(s32*)(sp + 1024) = t6;
	t5 = *(s32*)(s5 + 196);
	*(s32*)(sp + 1028) = t5;
	t4 = *(s32*)(s5 + 200);
	*(s32*)(sp + 1032) = t4;
	t3 = *(s32*)(s5 + 204);
	*(s32*)(sp + 1036) = t3;
	goto loc_000015FC;

loc_00001848:		
	if (v0 != 0)
	{
		a1 = *(s32*)(s5 + 0);
		goto loc_00001868;
	}
	v1 = *(s32*)(s5 + 0);
	a0 = 1;
	*(s32*)(sp + 1104) = a0;
	if (v1 == 0)
		goto loc_00001870;

loc_00001860:		
	s5 = v1;
	a1 = *(s32*)(s5 + 0);

loc_00001868:		
	v1 = a1;
	if (a1 != 0)
		goto loc_00001860;

loc_00001870:		
	a3 = *(s32*)(s5 + 192);
	*(s32*)(sp + 1024) = a3;
	t0 = *(s32*)(s5 + 196);
	*(s32*)(sp + 1028) = t0;
	s3 = *(s32*)(s5 + 200);
	*(s32*)(sp + 1032) = s3;
	a2 = *(s32*)(s5 + 204);
	*(s32*)(sp + 1036) = a2;
	goto loc_00001608;

loc_00001894:		
	if (s5 == 0)
	{
		v0 = sceKernelCpuSuspendIntr(...);
		t6 = 0x00000;
		s0 = v0;
		v0 = t6 + 1596;
		*(s32*)(v0 + 48) = s6;
		if (s6 != 0)
			goto loc_0000167C;
		*(s32*)(v0 + 52) = 0;
		goto loc_0000167C;

	}

loc_0000189C:		
	a3 = s6 + 16;
	if (s6 == 0)
	{
		v0 = sceKernelCpuSuspendIntr(...);
		t6 = 0x00000;
		s0 = v0;
		v0 = t6 + 1596;
		*(s32*)(v0 + 48) = s6;
		if (s6 != 0)
			goto loc_0000167C;
		*(s32*)(v0 + 52) = 0;
		goto loc_0000167C;

	}
	a2 = s5 + 16;
	t0 = s5 + 208;

	do{
		v1 = *(s32*)(a2 + 0);
		t9 = *(s32*)(a2 + 4);
		t8 = *(s32*)(a2 + 8);
		s7 = *(s32*)(a2 + 12);
		*(s32*)(a3 + 0) = v1;
		a2 = a2 + 16;
		a3 = a3 + 16;
		*(s32*)(a3 - 12) = t9;
		*(s32*)(a3 - 8) = t8;
		*(s32*)(a3 - 4) = s7;
	} while (a2 != t0);
	s5 = *(s32*)(s5 + 0);
	if (s5 != 0)
		goto loc_0000189C;

	v0 = sceKernelCpuSuspendIntr(...);
	t6 = 0x00000;
	s0 = v0;
	v0 = t6 + 1596;
	*(s32*)(v0 + 48) = s6;
	if (s6 != 0)
		goto loc_0000167C;
	*(s32*)(v0 + 52) = 0;
	goto loc_0000167C;
}

// Channel-scan
sub_000019B8(...) // at 0x000019B8 
{
	*(s32*)(0x00000 + 1596) = 2;
	v0 = sceUsb1SegScanCh(sp);
	s0 = v0;

	v0 = sceKernelCpuSuspendIntr();
	s2 = v0;
	if (s0)
	{
		*(s32*)(v0 + 8) = s0;
	}
	else if (*(s32*)(v0 + 2596))
	{
		*(s32*)(a0 + 0) = *(s32*)(sp + 0);
		*(s32*)(a0 + 4) = *(s32*)(sp + 4);
	}
	if (*(s32*)(0x00000 + 1596 + 2596))
	{
		v0 = sceKernelSignalSema(*(s32*)(0x00000 + 1596 + 32), 1);
	}

	v0 = sceKernelCpuResumeIntr(s2);
	return (s0);
}

Func()
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	a1 = 16;
	*(s32*)(sp + 0) = s0;
	s0 = a3;
	a0 = *(s32*)(a3 + 24);
	v0 = sceKernelSetEventFlag(...);
	v0 = *(s32*)(s0 + 2568);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00001A8C(...) // at 0x00001A8C 
{
	v0 = 0x20000;
	NONE;
	NONE;
	t3 = *(u8*)(v0 - 14382);
	NONE;
	NONE;
	t2 = *(u8*)(v0 - 14382);
	NONE;
	NONE;
	t1 = *(u8*)(v0 - 14382);
	NONE;
	v0 = *(u8*)(v0 - 14382);
	NONE;
	NONE;
	NONE;
	return (v0);
}

sub_00001ACC(...) // at 0x00001ACC 
{
	v0 = 0x20000;
	t0 = a0 + v0;
	if (a0 != 0)
		a0 = a1;
	a1 = v0 + a1;
	if (a0 == 0)
		goto loc_00001AFC;
	t0 = *(u8*)(t0 - 12080);
	t1 = *(u8*)(a1 - 12080);
	t0 = t0 + t1;
	NONE;
	t0 = t0 + a0;
	v0 = v0 + 256;
	NONE;

loc_00001AFC:		
	v0 = *(u8*)(v0 - 12080);
	return (v0);
}

sub_00001B04(...) // at 0x00001B04 
{
	at = ra;
	a2 = a0;
	a3 = a1;
	NONE;
	NONE;
	v0 = sub_00001ACC(...);
	v1 = v0;
	NONE;
	NONE;
	v0 = sub_00001ACC(...);
	asm("xor        $v1, $v1, $v0");
	NONE;
	NONE;
	v0 = sub_00001ACC(...);
	asm("xor        $v1, $v1, $v0");
	NONE;
	NONE;
	v0 = sub_00001ACC(...);
	asm("xor        $v0, $v1, $v0");
	at;
}

sub_00001B54(...) // at 0x00001B54 
{
	t2 = ra;
	t3 = a0;
	t5 = 0xE090000;
	t5 = t5 | 0xD0B;
	asm("rotr       $a1, $t5, 0");
	a0 = t3;
	v0 = sub_00001B04(...);
	t4 = v0 << 24;
	asm("rotr       $a1, $t5, 8");
	a0 = t3;
	v0 = sub_00001B04(...);
	NONE;
	asm("rotr       $a1, $t5, 16");
	a0 = t3;
	v0 = sub_00001B04(...);
	NONE;
	asm("rotr       $a1, $t5, 24");
	a0 = t3;
	v0 = sub_00001B04(...);
	v0 = v0 | t4;
	t2;
}

sub_00001BA8(...) // at 0x00001BA8 
{
	sp = sp - 48;
	*(s32*)(sp + 0) = a0;
	*(s32*)(sp + 4) = a1;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 12) = a3;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 40) = s6;
	asm("mtlo       $s7");
	asm("mthi       $ra");
	t8 = 0x20000;
	t9 = a0 + 0;
	at = *(s32*)(a0 + 968);
	t1 = *(s32*)(a0 + 964);
	v1 = a2;
	at = at - 2;
	t0 = t1 ^ 0x4;
	cond = (t0 == 0);
	t0 = t1 ^ 0x6;
	if (cond)
		goto loc_00001E68;
	cond = (t0 == 0);
	t0 = t1 ^ 0x8;
	if (cond)
		goto loc_00001F8C;
	if (t0 != 0)
	{
		v0 = -1;
		goto loc_000024C0;
	}
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	t4 = *(s32*)(a1 + 16);
	t5 = *(s32*)(a1 + 20);
	t6 = *(s32*)(a1 + 24);
	t7 = *(s32*)(a1 + 28);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	s6 = *(s32*)(t9 + 24);
	s7 = *(s32*)(t9 + 28);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	asm("xor        $s6, $s6, $t6");
	asm("xor        $s7, $s7, $t7");

loc_00001C74:		
	t9 = t9 + 32;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t4, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t5, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t6, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t7, $a0, $a3");
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	s6 = *(s32*)(t9 + 24);
	s7 = *(s32*)(t9 + 28);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	asm("xor        $s6, $s6, $t6");
	asm("xor        $s7, $s7, $t7");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_00001C74;
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 36);
	v0 = sub_000027E0(...);
	asm("xor        $t1, $t1, $a0");
	NONE;

loc_00001DA0:		
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 40);
	v0 = sub_000027E0(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 44);
	v0 = sub_000027E0(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t4 = *(s32*)(t9 + 48);
	v0 = sub_000027E0(...);
	asm("xor        $t4, $t4, $a0");
	*(s32*)(v1 + 16) = t4;
	NONE;
	NONE;
	NONE;
	NONE;
	t5 = *(s32*)(t9 + 52);
	v0 = sub_000027E0(...);
	asm("xor        $t5, $t5, $a0");
	*(s32*)(v1 + 20) = t5;
	NONE;
	NONE;
	NONE;
	NONE;
	t6 = *(s32*)(t9 + 56);
	v0 = sub_000027E0(...);
	asm("xor        $t6, $t6, $a0");
	*(s32*)(v1 + 24) = t6;
	NONE;
	NONE;
	NONE;
	NONE;
	t7 = *(s32*)(t9 + 60);
	v0 = sub_000027E0(...);
	asm("xor        $t7, $t7, $a0");
	*(s32*)(v1 + 28) = t7;
	NONE;
	NONE;
	NONE;
	t0 = *(s32*)(t9 + 32);
	goto loc_00002410;

loc_00001E68:		
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");

loc_00001E98:		
	t9 = t9 + 16;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_00001E98;
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 20);
	v0 = sub_000027E0(...);
	asm("xor        $t1, $t1, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 24);
	v0 = sub_000027E0(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 28);
	v0 = sub_000027E0(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;

loc_00001F84:		
	t0 = *(s32*)(t9 + 16);
	goto loc_00002410;

loc_00001F8C:		
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	t4 = *(s32*)(a1 + 16);
	t5 = *(s32*)(a1 + 20);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");

loc_00001FD4:		
	t9 = t9 + 24;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t4, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t5, $a0, $a3");
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_00001FD4;
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 28);
	v0 = sub_000027E0(...);
	asm("xor        $t1, $t1, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 32);
	v0 = sub_000027E0(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 36);
	v0 = sub_000027E0(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t4 = *(s32*)(t9 + 40);
	v0 = sub_000027E0(...);
	asm("xor        $t4, $t4, $a0");
	*(s32*)(v1 + 16) = t4;
	NONE;
	NONE;
	NONE;
	NONE;
	t5 = *(s32*)(t9 + 44);
	v0 = sub_000027E0(...);
	asm("xor        $t5, $t5, $a0");
	*(s32*)(v1 + 20) = t5;
	NONE;
	NONE;
	NONE;
	t0 = *(s32*)(t9 + 24);
	goto loc_00002410;
}

sub_00002148(...) // at 0x00002148 
{
	sp = sp - 48;
	*(s32*)(sp + 0) = a0;
	*(s32*)(sp + 4) = a1;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 12) = a3;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 40) = s6;
	asm("mtlo       $s7");
	asm("mthi       $ra");
	t8 = 0x20000;
	t8 = t8 + 1024;
	v0 = t8 + 1024;
	t9 = a0 + 480;
	at = *(s32*)(a0 + 968);
	t1 = *(s32*)(a0 + 964);
	v1 = a2;
	at = at - 2;
	t0 = t1 ^ 0x4;
	cond = (t0 == 0);
	t0 = t1 ^ 0x6;
	if (cond)
		goto loc_000024C8;
	cond = (t0 == 0);
	t0 = t1 ^ 0x8;
	if (cond)
		goto loc_000025EC;
	if (t0 != 0)
	{
		v0 = -1;
		goto loc_000024C0;
	}
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	t4 = *(s32*)(a1 + 16);
	t5 = *(s32*)(a1 + 20);
	t6 = *(s32*)(a1 + 24);
	t7 = *(s32*)(a1 + 28);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	s6 = *(s32*)(t9 + 24);
	s7 = *(s32*)(t9 + 28);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	asm("xor        $s6, $s6, $t6");
	asm("xor        $s7, $s7, $t7");

loc_0000221C:		
	t9 = t9 + 32;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t4, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t5, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t6, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t7, $a0, $a3");
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	s6 = *(s32*)(t9 + 24);
	s7 = *(s32*)(t9 + 28);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	asm("xor        $s6, $s6, $t6");
	asm("xor        $s7, $s7, $t7");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_0000221C;
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 36);
	v0 = sub_0000280C(...);
	asm("xor        $t1, $t1, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 40);
	v0 = sub_0000280C(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 44);
	v0 = sub_0000280C(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t4 = *(s32*)(t9 + 48);
	v0 = sub_0000280C(...);
	asm("xor        $t4, $t4, $a0");
	*(s32*)(v1 + 16) = t4;
	NONE;
	NONE;
	NONE;
	NONE;
	t5 = *(s32*)(t9 + 52);
	v0 = sub_0000280C(...);
	asm("xor        $t5, $t5, $a0");
	*(s32*)(v1 + 20) = t5;
	NONE;
	NONE;
	NONE;
	NONE;
	t6 = *(s32*)(t9 + 56);
	v0 = sub_0000280C(...);
	asm("xor        $t6, $t6, $a0");
	*(s32*)(v1 + 24) = t6;
	NONE;
	NONE;
	NONE;
	NONE;
	t7 = *(s32*)(t9 + 60);
	v0 = sub_0000280C(...);
	asm("xor        $t7, $t7, $a0");
	*(s32*)(v1 + 28) = t7;
	NONE;
	NONE;
	NONE;
	t0 = *(s32*)(t9 + 32);
	goto loc_0000246C;

loc_00002410:		
	*(s32*)(v1 + 4) = t1;
	NONE;
	v0 = sub_000027E0(...);
	*(s32*)(v1 + 8) = t2;
	asm("xor        $t0, $t0, $a0");
	v0 = 0;
	*(s32*)(v1 + 12) = t3;
	asm("mflo       $s7");
	asm("mfhi       $ra");
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(sp + 8);
	a3 = *(s32*)(sp + 12);
	s0 = *(s32*)(sp + 16);
	s1 = *(s32*)(sp + 20);
	s2 = *(s32*)(sp + 24);
	s3 = *(s32*)(sp + 28);
	s4 = *(s32*)(sp + 32);
	s5 = *(s32*)(sp + 36);
	s6 = *(s32*)(sp + 40);
	*(s32*)(v1 + 0) = t0;
	sp = sp + 48;
	return (v0);

loc_0000246C:		
	*(s32*)(v1 + 4) = t1;
	NONE;
	v0 = sub_0000280C(...);
	*(s32*)(v1 + 8) = t2;
	asm("xor        $t0, $t0, $a0");
	v0 = 0;
	*(s32*)(v1 + 12) = t3;
	asm("mflo       $s7");
	asm("mfhi       $ra");
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(sp + 8);
	a3 = *(s32*)(sp + 12);
	s0 = *(s32*)(sp + 16);
	s1 = *(s32*)(sp + 20);
	s2 = *(s32*)(sp + 24);
	s3 = *(s32*)(sp + 28);

loc_000024B0:		
	s4 = *(s32*)(sp + 32);
	s5 = *(s32*)(sp + 36);
	s6 = *(s32*)(sp + 40);
	*(s32*)(v1 + 0) = t0;

loc_000024C0:		
	sp = sp + 48;
	return (v0);

loc_000024C8:		
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");

loc_000024F8:		
	t9 = t9 + 16;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");

loc_0000252C:		
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	s0 = *(s32*)(t9 + 0);

loc_00002560:		
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_000024F8;
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 20);
	v0 = sub_0000280C(...);
	asm("xor        $t1, $t1, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 24);
	v0 = sub_0000280C(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 28);
	v0 = sub_0000280C(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;
	t0 = *(s32*)(t9 + 16);
	goto loc_0000246C;

loc_000025EC:		
	t0 = *(s32*)(a1 + 0);
	t1 = *(s32*)(a1 + 4);
	t2 = *(s32*)(a1 + 8);
	t3 = *(s32*)(a1 + 12);
	t4 = *(s32*)(a1 + 16);
	t5 = *(s32*)(a1 + 20);
	s0 = *(s32*)(t9 + 0);
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");

loc_00002634:		
	t9 = t9 + 24;
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t0, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t1, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t2, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t3, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t4, $a0, $a3");
	NONE;
	NONE;
	NONE;
	NONE;
	v0 = sub_000027AC(...);
	asm("xor        $t5, $a0, $a3");
	s0 = *(s32*)(t9 + 0);

loc_000026CC:		
	s1 = *(s32*)(t9 + 4);
	s2 = *(s32*)(t9 + 8);
	s3 = *(s32*)(t9 + 12);
	s4 = *(s32*)(t9 + 16);
	s5 = *(s32*)(t9 + 20);
	asm("xor        $s0, $s0, $t0");
	asm("xor        $s1, $s1, $t1");
	asm("xor        $s2, $s2, $t2");
	asm("xor        $s3, $s3, $t3");
	asm("xor        $s4, $s4, $t4");
	asm("xor        $s5, $s5, $t5");
	asm("xor        $s5, $s5, $t5");
	cond = (at != 0);
	at = at - 1;
	if (cond)
		goto loc_00002634;

loc_00002704:		
	NONE;
	NONE;
	NONE;
	NONE;
	t1 = *(s32*)(t9 + 28);
	v0 = sub_0000280C(...);
	asm("xor        $t1, $t1, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t2 = *(s32*)(t9 + 32);
	v0 = sub_0000280C(...);
	asm("xor        $t2, $t2, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t3 = *(s32*)(t9 + 36);
	v0 = sub_0000280C(...);
	asm("xor        $t3, $t3, $a0");
	NONE;
	NONE;
	NONE;
	NONE;
	t4 = *(s32*)(t9 + 40);
	v0 = sub_0000280C(...);
	asm("xor        $t4, $t4, $a0");
	*(s32*)(v1 + 16) = t4;
	NONE;
	NONE;
	NONE;
	NONE;
	t5 = *(s32*)(t9 + 44);
	v0 = sub_0000280C(...);
	asm("xor        $t5, $t5, $a0");
	*(s32*)(v1 + 20) = t5;
	NONE;
	NONE;
	NONE;
	t0 = *(s32*)(t9 + 24);
	goto loc_0000246C;
}

sub_000027AC(...) // at 0x000027AC 
{
	a0 = *(s32*)(t8 - 14384);
	NONE;
	a1 = *(s32*)(t8 - 14384);
	NONE;
	a2 = *(s32*)(t8 - 14384);
	NONE;
	a3 = *(s32*)(t8 - 14384);
	asm("rotr       $a1, $a1, 24");
	asm("xor        $a0, $a0, $a1");
	asm("rotr       $a2, $a2, 16");
	asm("xor        $a0, $a0, $a2");
	asm("rotr       $a3, $a3, 8");
	return (v0);
}

sub_000027E0(...) // at 0x000027E0 
{
	a0 = *(u8*)(t8 - 14382);
	NONE;
	a1 = *(u8*)(t8 - 14382);
	NONE;
	a2 = *(u8*)(t8 - 14382);
	NONE;
	a3 = *(u8*)(t8 - 14382);
	NONE;
	NONE;
	NONE;
	return (v0);
}

sub_0000280C(...) // at 0x0000280C 
{
	a0 = *(u8*)(v0 - 14384);
	NONE;
	a1 = *(u8*)(v0 - 14384);

loc_00002818:		
	NONE;
	a2 = *(u8*)(v0 - 14384);
	NONE;
	a3 = *(u8*)(v0 - 14384);
	NONE;
	NONE;
	NONE;
	return (v0);
}

sub_00002840(...) // at 0x00002840 
{
	a1 = *(s32*)(a0 + 0);
	a3 = a0 + 4;
	t0 = a1 << 2;
	t4 = (u32)a1 < (u32)623;
	t0 = a3 + t0;
	t3 = (u32)a1 < (u32)227;
	t1 = *(s32*)(t0 + 0);
	if (t4 == 0)
		goto loc_000028E8;
	a1 = a1 + 1;
	t2 = *(s32*)(t0 + 4);
	t4 = 0x80000000;
	*(s32*)(a0 + 0) = a1;

loc_00002870:		
	t6 = (u32)t1 >> 11;
	t5 = ~(0 | t4);
	asm("xor        $v0, $t1, $t6");
	t1 = t1 & t4;
	t7 = 0x9D2C0000;
	t5 = t2 & t5;
	t7 = t7 | 0x5680;
	t6 = v0 << 7;
	t4 = 0x99080000;
	t6 = t6 & t7;
	t7 = 0xEFC60000;
	asm("xor        $v0, $v0, $t6");
	t1 = t1 | t5;
	t6 = v0 << 15;
	t4 = t4 | 0xB0DF;
	t6 = t6 & t7;
	t2 = t2 & 0x1;
	asm("xor        $v0, $v0, $t6");
	t1 = (u32)t1 >> 1;
	t5 = t0 - 908;
	t7 = t0 + 1588;
	asm("xor        $t4, $t1, $t4");
	if (t3 != 0)
		t5 = t7;
	if (t2 != 0)
		t1 = t4;
	t5 = *(s32*)(t5 + 0);
	t6 = (u32)v0 >> 18;
	asm("xor        $t1, $t1, $t5");
	asm("xor        $v0, $v0, $t6");
	*(s32*)(t0 + 0) = t1;
	return (v0);

loc_000028E8:		
	t2 = *(s32*)(a0 + 4);
	t4 = 0x80000000;
	*(s32*)(a0 + 0) = 0;
	if (asm("b          loc_00002870"))
		goto ;
}

sub_00002900(...) // at 0x00002900 
{
	sp = sp - 704;
	v1 = (u32)a0 < (u32)1;
	v0 = (u32)a2 < (u32)1;
	*(s32*)(sp + 676) = s1;
	v1 = v1 | v0;
	s1 = a0;
	a0 = 0x80100000;
	*(s32*)(sp + 684) = s3;
	a0 = a0 | 0x9000;
	s3 = a1;
	*(s32*)(sp + 680) = s2;
	s2 = a2;
	*(s32*)(sp + 688) = ra;
	*(s32*)(sp + 672) = s0;
	if (v1 != 0)
		goto loc_00002A50;
	a1 = s1;
	a2 = 512;
	a0 = sp;
	v0 = scePaf_706ABBFF(...);
	a0 = sp;
	a1 = 58;
	v0 = scePaf_C3B2D310(...);
	a0 = 0x80100000;
	a0 = a0 | 0x9000;
	if (v0 == 0)
		goto loc_00002A50;
	*(s8*)(v0 + 1) = 0;
	s0 = sp + 624;
	a0 = s0;
	a1 = 0;
	a2 = 20;
	v0 = scePaf_BB89C9EA_memset(...);
	a1 = 0x2420000;
	a0 = sp;
	a1 = a1 | 0x5818;
	a2 = sp + 656;
	a3 = 4;
	t0 = 0;
	t1 = 0;
	*(s32*)(sp + 656) = s0;
	v0 = sceIoDevctl(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002A50;
	*(s32*)(s2 + 0) = 0;
	a0 = s1;
	a1 = sp + 528;
	v0 = sceIoGetstat(...);
	v1 = v0;
	v0 = 0x80010000;
	v0 = v0 | 0x2;
	a0 = *(s32*)(sp + 640);
	if (v1 == v0)
		goto loc_00002A70;
	a0 = v1;
	if ((s32)v1 < 0)
		goto loc_00002A50;
	a1 = *(s32*)(sp + 640);
	a0 = *(s32*)(sp + 636);
	asm("mult       $a1, $a0");
	a0 = *(s32*)(sp + 536);
	a1 = *(s32*)(sp + 540);
	asm("mflo       $s0");
	v0 = s0 - 1;
	a0 = a0 + v0;
	v1 = (s32)v0 >> 31;
	t0 = (u32)a0 < (u32)v0;
	a1 = a1 + v1;
	a1 = a1 + t0;
	asm("mflo       $a2");
	a3 = (s32)s0 >> 31;
	v0 = sub_0000345C(...);
	a0 = s3 + s0;
	a0 = a0 + 63;
	asm("divu       $a0, $s0");
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00002A24;
	}

loc_00002A24:		
	a0 = *(s32*)(sp + 628);
	a0 = a0 + v0;
	asm("mflo       $a1");
	v0 = (u32)a0 < (u32)a1;
	if (v0 == 0)
	{
		a0 = 0;
		goto loc_00002A50;
	}
	v0 = a1 - a0;
	asm("mult       $v0, $s0");

loc_00002A44:		
	asm("mflo       $v0");
	*(s32*)(s2 + 0) = v0;
	a0 = 0;

loc_00002A50:		
	ra = *(s32*)(sp + 688);
	s3 = *(s32*)(sp + 684);
	s2 = *(s32*)(sp + 680);

loc_00002A5C:		
	s1 = *(s32*)(sp + 676);
	s0 = *(s32*)(sp + 672);
	v0 = a0;
	sp = sp + 704;
	return (v0);

loc_00002A70:		
	v1 = *(s32*)(sp + 636);
	asm("mult       $a0, $v1");
	asm("mflo       $a0");
	v0 = s3 + a0;
	v0 = v0 + 63;
	asm("divu       $v0, $a0");
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00002A90;
	}

loc_00002A90:		
	a1 = *(s32*)(sp + 628);
	asm("mflo       $v1");
	v0 = (u32)a1 < (u32)v1;
	if (v0 == 0)
	{
		a0 = 0;
		goto loc_00002A50;
	}
	v0 = v1 - a1;
	asm("mult       $v0, $a0");
	goto loc_00002A44;
}

sub_00002AB0(...) // at 0x00002AB0 
{
	sp = sp - 16;
	v1 = 0x80100000;
	*(s32*)(sp + 0) = ra;
	v1 = v1 | 0x9000;
	if (a0 == 0)
		goto loc_00002B0C;
	v0 = *(s32*)(a0 + 0);
	v1 = v0 & 0xF;
	if (v0 == 0)
		goto loc_00002B1C;
	v0 = 0xFFFF;
	if (v1 != 0)
		goto loc_00002B1C;
	v1 = *(s32*)(a0 + 4);
	v0 = (u32)v0 < (u32)v1;
	if (v0 == 0)
		goto loc_00002B1C;
	v0 = *(s32*)(a0 + 8);
	if (v0 == 0)
		goto loc_00002B1C;
	v0 = *(s32*)(a0 + 16);
	v1 = 0;
	if (v0 == 0)
		goto loc_00002B0C;
	v0 = *(s32*)(a0 + 12);
	if (v0 == 0)
		goto loc_00002B1C;

loc_00002B0C:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00002B1C:		
	v0 = sub_00002B30(...);
	v1 = 0x80100000;
	v1 = v1 | 0x9000;
	goto loc_00002B0C;
}

sub_00002B30(...) // at 0x00002B30 
{
	v0 = 0;
	return (v0);
}

sub_00002B38(...) // at 0x00002B38 
{
	s1 = a0;
	v0 = sub_00002AB0(...);
	ra = *(s32*)(sp + 352);
	if ((s32)v0 < 0)
		goto loc_00002D94;
	a0 = *(s32*)(s1 + 8);
	a1 = sp + 224;
	v0 = sceIoGetstat(...);
	ra = *(s32*)(sp + 352);
	if ((s32)v0 < 0)
		goto loc_00002D94;
	a2 = *(s32*)(sp + 236);
	if ((s32)a2 <= 0)
		goto loc_00002DFC;
	v0 = *(s32*)(s1 + 20);

loc_00002B94:		
	v1 = *(s32*)(s1 + 16);
	a1 = 0;
	v0 = v0 + v1;
	v0 = v0 + 64;
	a0 = v0;
	v0 = (s32)a2 < (s32)a1;
	cond = (v0 != 0);
	v0 = 0x80100000;
	if (cond)
		goto loc_00002DF4;
	v0 = *(s32*)(sp + 232);
	if (a2 == a1)
		goto loc_00002DE4;
	s4 = sp + 128;

loc_00002BC0:
	v0 = scePaf_BB89C9EA_memset(s4, 0, 64);
	v0 = sceIoOpen(*(s32*)(s1 + 8), 1, 292);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002D90;
	v0 = *(s32*)(s1 + 20);
	s3 = s0;
	if (v0 == 0)
		goto loc_00002C10;
	a2 = v0;
	a3 = 0;
	a0 = s0;
	t0 = 0;
	v0 = sceIoLseek(...);
	if ((s32)v1 < 0)
		goto loc_00002DD4;

loc_00002C10:		
	a0 = s0;
	a1 = s4;
	a2 = 64;
	v0 = sceIoRead(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	v0 = *(u8*)(sp + 160);
	s0 = 0x80100000;
	s0 = s0 | 0x9002;
	if (v0 != 0)
		goto loc_00002DD4;
	s2 = 0x20000;
	a1 = *(s32*)(s2 - 11544);
	s6 = sp + 32;
	a0 = s6;
	v0 = sceSdSetIndex(...);
	s0 = v0;
	v0 = s2 - 11544;
	if ((s32)s0 < 0)
		goto loc_00002DD4;
	a1 = *(s32*)(v0 + 4);
	s5 = sp + 80;
	a0 = s5;
	v0 = sceSdSetIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	a1 = *(s32*)(s2 - 11544);
	t0 = *(s32*)(s1 + 24);
	a3 = sp + 176;
	a0 = sp;
	a2 = 2;
	v0 = sceSdCreateList(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	s2 = sp + 160;
	a0 = s6;
	a1 = s2;
	a2 = 32;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	a1 = s2;
	a0 = s5;
	a2 = 32;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	t3 = *(s32*)(s1 + 4);
	t0 = *(s32*)(s1 + 12);
	t1 = *(s32*)(s1 + 16);
	t2 = *(s32*)(s1 + 0);
	NONE;
	a0 = s3;
	a1 = s5;
	a2 = s6;
	a3 = sp;
	v0 = sub_00002E1C(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DD4;
	a0 = s3;
	v0 = sceIoClose(...);
	a0 = sp;
	v0 = sceChnnlsv_21BE78B4(...);
	s7 = s0;
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DBC;
	a2 = *(s32*)(s1 + 24);
	s3 = sp + 208;
	a0 = s5;
	a1 = s3;
	v0 = sceSdGetLastIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DBC;
	a2 = *(s32*)(s1 + 24);
	s2 = sp + 192;
	a0 = s6;
	a1 = s2;
	v0 = sceSdGetLastIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002DBC;
	a0 = s2;
	a1 = s4;
	a2 = 16;
	s0 = 0x80100000;
	v0 = scePaf_B05D9677(...);
	s0 = s0 | 0x9001;
	if (v0 != 0)
		goto loc_00002DBC;
	*(s32*)(s1 + 32) = 0;

loc_00002D68:		
	a0 = s3;
	a1 = sp + 144;
	a2 = 16;
	v0 = scePaf_B05D9677(...);
	cond = (v0 == 0);
	v0 = 0;
	if (cond)
		goto loc_00002D8C;
	v0 = 1;
	*(s32*)(s1 + 32) = v0;
	v0 = 0;

loc_00002D8C:		
	*(s32*)(s1 + 28) = s7;

loc_00002D90:		
	ra = *(s32*)(sp + 352);

loc_00002D94:		
	s7 = *(s32*)(sp + 348);
	s6 = *(s32*)(sp + 344);
	s5 = *(s32*)(sp + 340);
	s4 = *(s32*)(sp + 336);
	s3 = *(s32*)(sp + 332);
	s2 = *(s32*)(sp + 328);
	s1 = *(s32*)(sp + 324);
	s0 = *(s32*)(sp + 320);
	sp = sp + 368;
	return (v0);

loc_00002DBC:		
	a2 = *(s32*)(s1 + 16);

loc_00002DC0:		
	a0 = *(s32*)(s1 + 12);
	a1 = 0;
	v0 = scePaf_BB89C9EA_memset(...);
	v0 = s0;
	goto loc_00002D90;

loc_00002DD4:		
	a0 = s3;
	v0 = sceIoClose(...);
	a2 = *(s32*)(s1 + 16);
	goto loc_00002DC0;

loc_00002DE4:		
	v0 = (u32)v0 < (u32)a0;
	s4 = sp + 128;
	if (v0 == 0)
		goto loc_00002BC0;
	v0 = 0x80100000;

loc_00002DF4:		
	v0 = v0 | 0x9001;
	goto loc_00002D90;

loc_00002DFC:		
	v0 = 0x80100000;
	if (a2 != 0)
		goto loc_00002DF4;
	v0 = *(s32*)(sp + 232);
	v0 = (u32)v0 < (u32)64;
	if (v0 != 0)
	{
		v0 = 0x80100000;
		goto loc_00002DF4;
	}
	v0 = *(s32*)(s1 + 20);
	goto loc_00002B94;
}

sub_00002E1C(...) // at 0x00002E1C 
{
	v1 = (u32)a0 >> 31;
	v0 = (u32)a2 < (u32)1;
	sp = sp - 64;
	v1 = v1 | v0;
	*(s32*)(sp + 48) = fp;
	fp = a3;
	*(s32*)(sp + 44) = s7;
	s7 = t3;
	*(s32*)(sp + 36) = s5;
	s5 = t1;
	*(s32*)(sp + 24) = s2;

loc_00002E48:		
	s2 = t2;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 0) = a0;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 4) = a1;
	*(s32*)(sp + 12) = t0;
	if (v1 != 0)
		goto loc_00002E94;
	v0 = (u32)a3 < (u32)1;
	v1 = (u32)t2 < (u32)1;
	v0 = v0 | v1;
	cond = (v0 != 0);
	v0 = 0x80100000;
	if (cond)
		goto loc_00002E98;
	s3 = t3;
	if (t3 != 0)
		goto loc_00002ECC;

loc_00002E94:		
	v0 = 0x80100000;

loc_00002E98:		
	v0 = v0 | 0x9000;

loc_00002E9C:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 64;
	return (v0);

loc_00002ECC:		
	v0 = (u32)t1 < (u32)t3;
	if (v0 != 0)
		s3 = t1;
	s6 = 0;
	if (t1 != 0)
		goto loc_00002EE4;
	v0 = s6;
	goto loc_00002E9C;

loc_00002EE4:		
	a0 = *(s32*)(sp + 0);
	a2 = s3;
	a1 = s2;
	v0 = sceIoRead(...);
	s4 = v0;
	s1 = s7;
	a2 = s7 - s3;
	a0 = s2 + s3;
	v0 = (u32)s3 < (u32)s7;
	a1 = 0;
	if ((s32)s4 < 0)
		goto loc_00002FC8;
	if (v0 != 0)
		goto loc_00002FB8;

loc_00002F18:		
	a0 = *(s32*)(sp + 8);
	a1 = s2;
	a2 = s1;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	a0 = *(s32*)(sp + 4);
	a1 = s2;
	a2 = s1;
	if ((s32)v0 < 0)
		goto loc_00002FA0;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	a0 = fp;
	a1 = s2;
	a2 = s1;
	if ((s32)v0 < 0)
		goto loc_00002FA0;
	v0 = sceSdSetMember(...);
	s0 = v0;
	v0 = *(s32*)(sp + 12);
	a1 = s2;
	a2 = s4;
	a0 = v0 + s6;
	if ((s32)s0 < 0)
		goto loc_00002FA0;
	s6 = s6 + s4;
	v0 = scePaf_9A418CCC(...);
	v1 = s6 + s3;
	v1 = (u32)s5 < (u32)v1;
	v0 = s5 - s6;
	a0 = (u32)s6 < (u32)s5;
	if (v1 != 0)
		s3 = v0;
	if (a0 != 0)
		goto loc_00002EE4;

loc_00002F9C:		
	v0 = s6;
	goto loc_00002E9C;

loc_00002FA0:		
	a0 = *(s32*)(sp + 12);
	a2 = s6 + s3;
	a1 = 0;
	v0 = scePaf_BB89C9EA_memset(...);
	v0 = s0;
	goto loc_00002E9C;

loc_00002FB8:		
	s1 = s3 + 15;
	v0 = scePaf_BB89C9EA_memset(...);
	NONE;
	goto loc_00002F18;

loc_00002FC8:		
	s0 = s4;
	goto loc_00002FA0;
}

sub_00002FD0(...) // at 0x00002FD0 
{
	sp = sp - 240;
	*(s32*)(sp + 200) = s2;
	s2 = a0;
	*(s32*)(sp + 224) = ra;
	*(s32*)(sp + 220) = s7;
	*(s32*)(sp + 216) = s6;
	*(s32*)(sp + 212) = s5;
	*(s32*)(sp + 208) = s4;
	*(s32*)(sp + 204) = s3;
	*(s32*)(sp + 196) = s1;
	*(s32*)(sp + 192) = s0;
	v0 = sub_00002AB0(...);
	s5 = sp + 128;
	if ((s32)v0 < 0)
		goto loc_000031D8;
	a0 = s5;
	a1 = 0;

loc_00003014:		
	a2 = 64;
	v0 = scePaf_BB89C9EA_memset(...);
	v0 = sceIoOpen(*(s32*)(s2 + 8), 1538, 438);
	a1 = s5;
	if ((s32)v0 < 0)
		goto loc_000031D8;
	a0 = v0;
	a2 = 16;
	s3 = v0;
	v0 = sceIoWrite(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	s7 = sp + 144;
	a0 = s3;
	a1 = s7;
	a2 = 16;
	v0 = sceIoWrite(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	s1 = 0x20000;
	a1 = *(s32*)(s1 - 11544);
	t0 = *(s32*)(s2 + 24);
	a3 = sp + 176;
	a0 = sp;
	a2 = 1;
	v0 = sceSdCreateList(...);
	s0 = v0;
	s4 = s1 - 11544;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a1 = *(s32*)(s1 - 11544);
	s6 = sp + 32;
	a0 = s6;
	*(s8*)(sp + 160) = 0;
	v0 = sceSdSetIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a1 = *(s32*)(s4 + 4);
	s4 = sp + 80;
	a0 = s4;
	v0 = sceSdSetIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	s1 = sp + 160;
	a0 = s6;
	a1 = s1;
	a2 = 32;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a0 = s4;
	a1 = s1;
	a2 = 32;
	v0 = sceSdRemoveValue(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a1 = s1;
	a0 = s3;
	a2 = 32;
	v0 = sceIoWrite(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	t3 = *(s32*)(s2 + 4);
	t0 = *(s32*)(s2 + 12);
	t1 = *(s32*)(s2 + 16);
	t2 = *(s32*)(s2 + 0);
	NONE;
	a0 = s3;
	a1 = s4;
	a2 = s6;
	a3 = sp;
	v0 = sub_00003214(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a0 = sp;
	s1 = v0;
	v0 = sceChnnlsv_21BE78B4(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a2 = *(s32*)(s2 + 24);
	a0 = s6;
	a1 = s5;
	v0 = sceSdGetLastIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a2 = *(s32*)(s2 + 24);
	a0 = s4;
	a1 = s7;
	v0 = sceSdGetLastIndex(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a0 = s3;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	v0 = sceIoLseek(...);
	a1 = s5;
	if ((s32)v1 < 0)
		goto loc_00003204;
	a0 = s3;
	a2 = 16;
	v0 = sceIoWrite(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a1 = s7;
	a0 = s3;
	a2 = 16;
	v0 = sceIoWrite(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003204;
	a0 = s3;
	v0 = sceIoClose(...);
	v0 = 0;
	*(s32*)(s2 + 28) = s1;

loc_000031D8:		
	ra = *(s32*)(sp + 224);
	s7 = *(s32*)(sp + 220);
	s6 = *(s32*)(sp + 216);
	s5 = *(s32*)(sp + 212);
	s4 = *(s32*)(sp + 208);
	s3 = *(s32*)(sp + 204);
	s2 = *(s32*)(sp + 200);
	s1 = *(s32*)(sp + 196);
	s0 = *(s32*)(sp + 192);
	sp = sp + 240;
	return (v0);

loc_00003204:		
	a0 = s3;
	v0 = sceIoClose(...);
	v0 = s0;
	goto loc_000031D8;
}

sub_00003214(...) // at 0x00003214 
{
	v1 = (u32)a0 >> 31;
	v0 = (u32)a2 < (u32)1;
	sp = sp - 64;
	v1 = v1 | v0;
	*(s32*)(sp + 48) = fp;
	fp = a0;
	*(s32*)(sp + 44) = s7;
	s7 = a2;
	*(s32*)(sp + 40) = s6;
	s6 = a3;
	*(s32*)(sp + 36) = s5;
	s5 = t3;
	*(s32*)(sp + 28) = s3;
	s3 = t1;
	*(s32*)(sp + 24) = s2;
	s2 = t2;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 0) = a1;
	*(s32*)(sp + 4) = t0;
	if (v1 != 0)
		goto loc_0000328C;
	v0 = (u32)a3 < (u32)1;
	v1 = (u32)t2 < (u32)1;
	v0 = v0 | v1;
	cond = (v0 != 0);
	v0 = 0x80100000;
	if (cond)
		goto loc_00003290;
	s1 = t3;
	if (t3 != 0)
		goto loc_000032C4;

loc_0000328C:		
	v0 = 0x80100000;

loc_00003290:		
	v0 = v0 | 0x9000;

loc_00003294:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 64;
	return (v0);

loc_000032C4:		
	v0 = (u32)t1 < (u32)t3;
	if (v0 != 0)
		s1 = t1;
	s4 = 0;
	if (t1 != 0)
		goto loc_000032E0;
	v1 = s4;

loc_000032D8:		
	v0 = v1;
	goto loc_00003294;

loc_000032E0:		
	v0 = *(s32*)(sp + 4);

loc_000032E4:		
	a0 = s2;
	a2 = s1;
	a1 = v0 + s4;
	v0 = scePaf_9A418CCC(...);
	v0 = (u32)s1 < (u32)s5;
	s0 = s5;
	a0 = s6;
	a1 = s2;
	if (v0 == 0)
		goto loc_00003310;
	s0 = s1 + 15;
	NONE;

loc_00003310:		
	a2 = s0;
	v0 = sceSdSetMember(...);
	v1 = v0;
	a0 = s2 + s1;
	a2 = s0 - s1;
	a1 = 0;
	if ((s32)v0 < 0)
		goto loc_000032D8;
	if (s0 == s1)
	{
		a0 = *(s32*)(sp + 0);
		goto loc_00003340;
	}
	v0 = scePaf_BB89C9EA_memset(...);
	a0 = *(s32*)(sp + 0);

loc_00003340:		
	a1 = s2;
	a2 = s0;
	v0 = sceSdRemoveValue(...);
	v1 = v0;
	a2 = s0;
	a0 = s7;
	a1 = s2;
	if ((s32)v0 < 0)
		goto loc_000032D8;
	v0 = sceSdRemoveValue(...);
	v1 = v0;
	a2 = s1;
	a0 = fp;
	a1 = s2;
	if ((s32)v0 < 0)
		goto loc_000032D8;
	v0 = sceIoWrite(...);
	s4 = s4 + v0;
	v1 = s4 + s1;
	v1 = (u32)s3 < (u32)v1;
	a0 = s3 - s4;
	if (v1 != 0)
		s1 = a0;
	a1 = (u32)s4 < (u32)s3;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_000032D8;
	if (a1 != 0)
	{
		v0 = *(s32*)(sp + 4);
		goto loc_000032E4;
	}
	v1 = s4;
	goto loc_000032D8;
}

sub_000033B4(a0, a1, a2) // at 0x000033B4 
{
	v0 = 0x20000 - 15448;
	a0 = *(s32*)(v0 - 4);
	s0 = v0 - 4;
	if (a0 != -1)
	{
		v1 = a0;

		do
		{
			s0 = s0 - 4;
			$v1(...);
			v0 = *(s32*)(s0 + 0);
			v1 = v0;
		} while (v0 != -1);
	}
	return (v0);
}

sub_0000340C(...) // at 0x0000340C 
{
	asm("mtc1       $zr, $fcr0");
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	asm("c.lt.s     $fpr12, $fpr00");
	cond = (asm("bc1f       loc_0000344C"));
	asm("neg.s      $fpr02, $fpr12");
	if (cond)
		goto ;
	asm("mov.s      $fpr12, $fpr02");
	v0 = sub_00004BC0(...);
	asm("negu       $v0, $v0");
	asm("negu       $v1, $v1");
	a0 = (u32)0 < (u32)v0;
	v1 = v1 - a0;
	ra = *(s32*)(sp + 0);

loc_00003444:		
	sp = sp + 16;
	return (v0);

loc_0000344C:		
	v0 = sub_00004BC0(...);
	ra = *(s32*)(sp + 0);
	goto loc_00003444;
}

sub_0000345C(...) // at 0x0000345C 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = 0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	if ((s32)a1 < 0)
		goto loc_00003A18;

loc_00003474:		
	if ((s32)a3 < 0)
		goto loc_00003A00;

loc_0000347C:		
	t0 = a3;
	t2 = a1;
	t1 = a2;
	t6 = a0;
	if (a3 != 0)
		goto loc_0000384C;
	v0 = (u32)a1 < (u32)a2;
	cond = (v0 == 0);
	v0 = 0xFFFF;
	if (cond)
		goto loc_0000360C;
	v1 = 8;
	a0 = (u32)a2 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)a2;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_000034D0;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)a2;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_000034D0:		
	v1 = 0x20000;
	v0 = (u32)a2 >> a1;
	v1 = v1 - 11512;
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	if (a3 == 0)
	{
		a3 = (u32)t1 >> 16;
		goto loc_00003514;
	}
	v0 = v0 - a3;
	v0 = (u32)t6 >> v0;
	v1 = t2 << a3;
	t2 = v1 | v0;
	t6 = t6 << a3;
	t1 = t1 << a3;
	a3 = (u32)t1 >> 16;

loc_00003514:		
	asm("divu       $t2, $a3");
	t4 = t1 & 0xFFFF;
	a0 = (u32)t6 >> 16;
	if (a3 == 0)
	{
		asm("break      0x7");
		goto loc_00003528;
	}

loc_00003528:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t3");
	asm("mult       $v1, $t4");
	v0 = v0 << 16;
	a2 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a2 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $t2, $a3");
	if (cond)
		goto loc_00003574;
	a2 = a2 + t1;
	v0 = (u32)a2 < (u32)t1;
	t3 = t3 - 1;
	if (v0 != 0)
		goto loc_00003574;
	v0 = (u32)a2 < (u32)a1;
	if (v0 == 0)
	{
		a2 = a2 - a1;
		goto loc_00003578;
	}
	t3 = t3 - 1;
	a2 = a2 + t1;

loc_00003574:		
	a2 = a2 - a1;

loc_00003578:		
	asm("divu       $a2, $a3");
	a0 = t6 & 0xFFFF;
	if (a3 == 0)
	{
		asm("break      0x7");
		goto loc_00003588;
	}

loc_00003588:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t0");
	asm("mult       $v1, $t4");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a0 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $a2, $a3");
	if (cond)
		goto loc_000035CC;
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	t0 = t0 - 1;
	if (v0 != 0)
		goto loc_000035CC;
	v0 = (u32)a0 < (u32)a1;
	v0 = (u32)0 < (u32)v0;
	t0 = t0 - v0;

loc_000035CC:		
	v0 = t3 << 16;
	a0 = v0 | t0;

loc_000035D4:		
	a2 = 0;

loc_000035D8:		
	a1 = a2;
	if (s2 == 0)
		goto loc_000035F0;
	asm("negu       $a0, $a0");
	asm("negu       $a1, $a1");
	v0 = (u32)0 < (u32)a0;
	a1 = a1 - v0;

loc_000035F0:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	v1 = a1;
	sp = sp + 16;
	return (v0);

loc_0000360C:		
	v1 = 8;
	if (a2 != 0)
		goto loc_00003630;
	v0 = 1;
	asm("divu       $v0, $a3");
	if (a2 == 0)
	{
		asm("break      0x7");
		goto loc_00003624;
	}

loc_00003624:		
	asm("mflo       $t1");
	v0 = 0xFFFF;
	v1 = 8;

loc_00003630:		
	a0 = (u32)t1 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)t1;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_00003660;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)t1;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_00003660:		
	v1 = 0x20000;
	v0 = (u32)t1 >> a1;

loc_00003668:		
	v1 = v1 - 11512;
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	a1 = v0 - a3;
	if (a3 != 0)
		goto loc_00003758;
	t2 = t2 - t1;
	a2 = 1;
	t0 = (u32)t1 >> 16;
	s0 = t1 & 0xFFFF;

loc_00003698:		
	asm("divu       $t2, $t0");
	a0 = (u32)t6 >> 16;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_000036A8;
	}

loc_000036A8:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t3");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a3 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a3 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $t2, $t0");
	if (cond)
		goto loc_000036F4;
	a3 = a3 + t1;
	v0 = (u32)a3 < (u32)t1;
	t3 = t3 - 1;
	if (v0 != 0)
		goto loc_000036F4;
	v0 = (u32)a3 < (u32)a1;
	if (v0 == 0)
	{
		a3 = a3 - a1;
		goto loc_000036F8;
	}
	t3 = t3 - 1;
	a3 = a3 + t1;

loc_000036F4:		
	a3 = a3 - a1;

loc_000036F8:		
	asm("divu       $a3, $t0");
	a0 = t6 & 0xFFFF;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_00003708;
	}

loc_00003708:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t2");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a0 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $a3, $t0");
	if (cond)
		goto loc_0000374C;
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	t2 = t2 - 1;
	if (v0 != 0)
		goto loc_0000374C;
	v0 = (u32)a0 < (u32)a1;
	v0 = (u32)0 < (u32)v0;
	t2 = t2 - v0;

loc_0000374C:		
	v0 = t3 << 16;
	a0 = v0 | t2;
	goto loc_000035D8;

loc_00003758:		
	t1 = t1 << a3;
	t0 = (u32)t1 >> 16;
	t4 = (u32)t2 >> a1;
	asm("divu       $t4, $t0");
	s0 = t1 & 0xFFFF;
	v1 = (u32)t6 >> a1;
	v0 = t2 << a3;
	t2 = v0 | v1;
	a1 = (u32)t2 >> 16;
	t6 = t6 << a3;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_00003788;
	}

loc_00003788:		
	t3 = t0;
	s1 = s0;
	asm("mflo       $a2");
	asm("mfhi       $a0");
	asm("mflo       $t7");
	asm("mult       $a2, $s0");
	a0 = a0 << 16;
	a3 = a0 | a1;
	asm("mflo       $t5");
	v0 = (u32)a3 < (u32)t5;
	cond = (v0 == 0);
	asm("divu       $t4, $t0");
	if (cond)
		goto loc_000037DC;
	a3 = a3 + t1;
	v0 = (u32)a3 < (u32)t1;
	t7 = a2 - 1;
	if (v0 != 0)
		goto loc_000037DC;
	v0 = (u32)a3 < (u32)t5;
	if (v0 == 0)
	{
		a3 = a3 - t5;
		goto loc_000037E0;
	}
	t7 = t7 - 1;
	a3 = a3 + t1;

loc_000037DC:		
	a3 = a3 - t5;

loc_000037E0:		
	asm("divu       $a3, $t3");
	a0 = t2 & 0xFFFF;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_000037F0;
	}

loc_000037F0:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $a2");
	asm("mult       $v1, $s1");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $t5");
	v1 = (u32)a0 < (u32)t5;
	cond = (v1 == 0);
	asm("divu       $a3, $t3");
	if (cond)
		goto loc_0000383C;
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	a2 = a2 - 1;
	if (v0 != 0)
		goto loc_0000383C;
	v0 = (u32)a0 < (u32)t5;
	cond = (v0 == 0);
	v0 = t7 << 16;
	if (cond)
		goto loc_00003840;
	a2 = a2 - 1;
	a0 = a0 + t1;

loc_0000383C:		
	v0 = t7 << 16;

loc_00003840:		
	a2 = v0 | a2;
	t2 = a0 - t5;
	goto loc_00003698;

loc_0000384C:		
	v0 = (u32)a1 < (u32)a3;
	a0 = 0;
	a2 = 0;
	if (v0 != 0)
		goto loc_000035D8;
	v0 = 0xFFFF;
	v1 = 8;
	a0 = (u32)a3 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)a3;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_00003894;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)a3;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_00003894:		
	v1 = 0x20000;
	v0 = (u32)t0 >> a1;
	v1 = v1 - 11512;
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	a1 = v0 - a3;
	if (a3 != 0)
		goto loc_000038D4;
	v0 = (u32)t6 < (u32)t1;
	v1 = (u32)t0 < (u32)t2;
	v0 = v0 ^ 0x1;
	v1 = v1 | v0;
	a0 = (u32)0 < (u32)v1;
	goto loc_000035D4;

loc_000038D4:		
	v0 = (u32)t1 >> a1;
	v1 = t0 << a3;
	t0 = v1 | v0;
	t3 = (u32)t0 >> 16;
	t4 = (u32)t2 >> a1;
	asm("divu       $t4, $t3");
	s0 = t0 & 0xFFFF;
	v1 = (u32)t6 >> a1;
	v0 = t2 << a3;
	t2 = v0 | v1;
	a1 = (u32)t2 >> 16;
	t6 = t6 << a3;
	t1 = t1 << a3;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_00003910;
	}

loc_00003910:		
	asm("mflo       $a2");
	asm("mfhi       $a0");
	asm("mflo       $t7");
	asm("mult       $a2, $s0");
	a0 = a0 << 16;
	a3 = a0 | a1;
	asm("mflo       $t5");
	v0 = (u32)a3 < (u32)t5;
	cond = (v0 == 0);
	asm("divu       $t4, $t3");
	if (cond)
		goto loc_0000395C;
	a3 = a3 + t0;
	v0 = (u32)a3 < (u32)t0;
	t7 = a2 - 1;
	if (v0 != 0)
		goto loc_0000395C;
	v0 = (u32)a3 < (u32)t5;
	if (v0 == 0)
	{
		a3 = a3 - t5;
		goto loc_00003960;
	}
	t7 = t7 - 1;
	a3 = a3 + t0;

loc_0000395C:		
	a3 = a3 - t5;

loc_00003960:		
	asm("divu       $a3, $t3");
	a0 = t2 & 0xFFFF;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_00003970;
	}

loc_00003970:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $a2");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a1 = v0 | a0;
	asm("mflo       $t5");
	v1 = (u32)a1 < (u32)t5;
	cond = (v1 == 0);
	asm("divu       $a3, $t3");
	if (cond)
		goto loc_000039BC;
	a1 = a1 + t0;
	v0 = (u32)a1 < (u32)t0;
	a2 = a2 - 1;
	if (v0 != 0)
		goto loc_000039BC;
	v0 = (u32)a1 < (u32)t5;
	cond = (v0 == 0);
	v0 = t7 << 16;
	if (cond)
		goto loc_000039C0;
	a1 = a1 + t0;
	a2 = a2 - 1;

loc_000039BC:		
	v0 = t7 << 16;

loc_000039C0:		
	a0 = v0 | a2;
	a1 = a1 - t5;
	asm("multu      $a0, $t1");
	asm("mfhi       $v1");
	v0 = (u32)a1 < (u32)v1;
	if (v0 != 0)
	{
		a0 = a0 - 1;
		goto loc_000035D4;
	}
	asm("xor        $v0, $v1, $a1");
	asm("mflo       $a1");
	v1 = (u32)t6 < (u32)a1;
	v0 = (u32)v0 < (u32)1;
	v0 = v0 & v1;
	a2 = 0;
	if (v0 == 0)
		goto loc_000035D8;
	a0 = a0 - 1;
	goto loc_000035D8;

loc_00003A00:		
	asm("negu       $a2, $a2");
	asm("negu       $a3, $a3");
	v0 = (u32)0 < (u32)a2;
	a3 = a3 - v0;
	s2 = ~(0 | s2);
	goto loc_0000347C;

loc_00003A18:		
	asm("negu       $a0, $a0");
	asm("negu       $a1, $a1");
	v0 = (u32)0 < (u32)a0;
	a1 = a1 - v0;
	s2 = -1;
	goto loc_00003474;
}

sub_00003A30(...) // at 0x00003A30 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	t0 = a3;
	t2 = a1;
	*(s32*)(sp + 0) = s0;
	t1 = a2;
	t6 = a0;
	if (a3 != 0)
		goto loc_00003DF0;
	v0 = (u32)a1 < (u32)a2;
	cond = (v0 == 0);
	v0 = 0xFFFF;
	if (cond)
		goto loc_00003BB0;
	v1 = 8;
	a0 = (u32)a2 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)a2;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_00003A90;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)a2;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_00003A90:		
	v1 = 0x20000;
	v0 = (u32)a2 >> a1;
	v1 = v1 - 11512;

loc_00003A9C:		
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	if (a3 == 0)
	{
		a3 = (u32)t1 >> 16;
		goto loc_00003AD4;
	}
	v0 = v0 - a3;
	v0 = (u32)t6 >> v0;
	v1 = t2 << a3;
	t2 = v1 | v0;
	t6 = t6 << a3;
	t1 = t1 << a3;
	a3 = (u32)t1 >> 16;

loc_00003AD4:		
	asm("divu       $t2, $a3");
	t4 = t1 & 0xFFFF;
	a0 = (u32)t6 >> 16;
	if (a3 == 0)
	{
		asm("break      0x7");
		goto loc_00003AE8;
	}

loc_00003AE8:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t3");
	asm("mult       $v1, $t4");

loc_00003AF8:		
	v0 = v0 << 16;
	a2 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a2 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $t2, $a3");
	if (cond)
		goto loc_00003B34;
	a2 = a2 + t1;
	v0 = (u32)a2 < (u32)t1;
	t3 = t3 - 1;
	if (v0 != 0)
		goto loc_00003B34;
	v0 = (u32)a2 < (u32)a1;
	if (v0 == 0)
	{
		a2 = a2 - a1;
		goto loc_00003B38;
	}
	t3 = t3 - 1;
	a2 = a2 + t1;

loc_00003B34:		
	a2 = a2 - a1;

loc_00003B38:		
	asm("divu       $a2, $a3");
	a0 = t6 & 0xFFFF;
	if (a3 == 0)
	{
		asm("break      0x7");
		goto loc_00003B48;
	}

loc_00003B48:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t0");
	asm("mult       $v1, $t4");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a0 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $a2, $a3");
	if (cond)
		goto loc_00003B8C;

loc_00003B70:		
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	t0 = t0 - 1;
	if (v0 != 0)
		goto loc_00003B8C;
	v0 = (u32)a0 < (u32)a1;
	v0 = (u32)0 < (u32)v0;
	t0 = t0 - v0;

loc_00003B8C:		
	v0 = t3 << 16;
	a0 = v0 | t0;

loc_00003B94:		
	a2 = 0;

loc_00003B98:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	v1 = a2;
	sp = sp + 16;
	return (v0);

loc_00003BB0:		
	v1 = 8;
	if (a2 != 0)
		goto loc_00003BD4;
	v0 = 1;
	asm("divu       $v0, $a3");
	if (a2 == 0)
	{
		asm("break      0x7");
		goto loc_00003BC8;
	}

loc_00003BC8:		
	asm("mflo       $t1");
	v0 = 0xFFFF;
	v1 = 8;

loc_00003BD4:		
	a0 = (u32)t1 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)t1;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_00003C04;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)t1;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_00003C04:		
	v1 = 0x20000;
	v0 = (u32)t1 >> a1;
	v1 = v1 - 11512;
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	a1 = v0 - a3;
	if (a3 != 0)
		goto loc_00003CFC;
	t2 = t2 - t1;
	a2 = 1;
	t0 = (u32)t1 >> 16;
	s0 = t1 & 0xFFFF;

loc_00003C3C:		
	asm("divu       $t2, $t0");
	a0 = (u32)t6 >> 16;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_00003C4C;
	}

loc_00003C4C:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t3");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a3 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a3 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $t2, $t0");
	if (cond)
		goto loc_00003C98;
	a3 = a3 + t1;
	v0 = (u32)a3 < (u32)t1;
	t3 = t3 - 1;
	if (v0 != 0)
		goto loc_00003C98;
	v0 = (u32)a3 < (u32)a1;
	if (v0 == 0)
	{
		a3 = a3 - a1;
		goto loc_00003C9C;
	}
	t3 = t3 - 1;
	a3 = a3 + t1;

loc_00003C98:		
	a3 = a3 - a1;

loc_00003C9C:		
	asm("divu       $a3, $t0");
	a0 = t6 & 0xFFFF;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_00003CAC;
	}

loc_00003CAC:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $t2");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $a1");
	v1 = (u32)a0 < (u32)a1;
	cond = (v1 == 0);
	asm("divu       $a3, $t0");
	if (cond)
		goto loc_00003CF0;
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	t2 = t2 - 1;
	if (v0 != 0)
		goto loc_00003CF0;
	v0 = (u32)a0 < (u32)a1;
	v0 = (u32)0 < (u32)v0;
	t2 = t2 - v0;

loc_00003CF0:		
	v0 = t3 << 16;
	a0 = v0 | t2;
	goto loc_00003B98;

loc_00003CFC:		
	t1 = t1 << a3;
	t0 = (u32)t1 >> 16;
	t4 = (u32)t2 >> a1;
	asm("divu       $t4, $t0");
	s0 = t1 & 0xFFFF;
	v1 = (u32)t6 >> a1;
	v0 = t2 << a3;
	t2 = v0 | v1;
	a1 = (u32)t2 >> 16;
	t6 = t6 << a3;
	if (t0 == 0)
	{
		asm("break      0x7");
		goto loc_00003D2C;
	}

loc_00003D2C:		
	t3 = t0;
	s1 = s0;
	asm("mflo       $a2");
	asm("mfhi       $a0");
	asm("mflo       $t7");
	asm("mult       $a2, $s0");
	a0 = a0 << 16;
	a3 = a0 | a1;
	asm("mflo       $t5");
	v0 = (u32)a3 < (u32)t5;
	cond = (v0 == 0);
	asm("divu       $t4, $t0");
	if (cond)
		goto loc_00003D80;
	a3 = a3 + t1;
	v0 = (u32)a3 < (u32)t1;
	t7 = a2 - 1;
	if (v0 != 0)
		goto loc_00003D80;
	v0 = (u32)a3 < (u32)t5;
	if (v0 == 0)
	{
		a3 = a3 - t5;
		goto loc_00003D84;
	}
	t7 = t7 - 1;
	a3 = a3 + t1;

loc_00003D80:		
	a3 = a3 - t5;

loc_00003D84:		
	asm("divu       $a3, $t3");
	a0 = t2 & 0xFFFF;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_00003D94;
	}

loc_00003D94:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $a2");
	asm("mult       $v1, $s1");
	v0 = v0 << 16;
	a0 = v0 | a0;
	asm("mflo       $t5");
	v1 = (u32)a0 < (u32)t5;
	cond = (v1 == 0);
	asm("divu       $a3, $t3");
	if (cond)
		goto loc_00003DE0;
	a0 = a0 + t1;
	v0 = (u32)a0 < (u32)t1;
	a2 = a2 - 1;
	if (v0 != 0)
		goto loc_00003DE0;
	v0 = (u32)a0 < (u32)t5;
	cond = (v0 == 0);
	v0 = t7 << 16;
	if (cond)
		goto loc_00003DE4;
	a2 = a2 - 1;
	a0 = a0 + t1;

loc_00003DE0:		
	v0 = t7 << 16;

loc_00003DE4:		
	a2 = v0 | a2;
	t2 = a0 - t5;
	goto loc_00003C3C;

loc_00003DF0:		
	v0 = (u32)a1 < (u32)a3;
	a0 = 0;
	a2 = 0;
	if (v0 != 0)
		goto loc_00003B98;
	v0 = 0xFFFF;
	v1 = 8;
	a0 = (u32)a3 < (u32)256;
	a1 = v1;
	v0 = (u32)v0 < (u32)a3;
	if (a0 != 0)
		a1 = 0;
	if (v0 == 0)
		goto loc_00003E38;
	v0 = 0xFF0000;
	v0 = v0 | 0xFFFF;
	v1 = 16;
	v0 = (u32)v0 < (u32)a3;
	a0 = 24;
	a1 = v1;
	if (v0 != 0)
		a1 = a0;

loc_00003E38:		
	v1 = 0x20000;
	v0 = (u32)t0 >> a1;
	v1 = v1 - 11512;
	v0 = v0 + v1;
	a0 = *(u8*)(v0 + 0);
	v0 = 32;
	a0 = a0 + a1;
	a3 = v0 - a0;
	a1 = v0 - a3;
	if (a3 != 0)
		goto loc_00003E78;
	v0 = (u32)t6 < (u32)t1;
	v1 = (u32)t0 < (u32)t2;
	v0 = v0 ^ 0x1;
	v1 = v1 | v0;
	a0 = (u32)0 < (u32)v1;
	goto loc_00003B94;

loc_00003E78:		
	v0 = (u32)t1 >> a1;
	v1 = t0 << a3;
	t0 = v1 | v0;
	t3 = (u32)t0 >> 16;
	t4 = (u32)t2 >> a1;
	asm("divu       $t4, $t3");
	s0 = t0 & 0xFFFF;
	v1 = (u32)t6 >> a1;
	v0 = t2 << a3;
	t2 = v0 | v1;
	a1 = (u32)t2 >> 16;
	t6 = t6 << a3;
	t1 = t1 << a3;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_00003EB4;
	}

loc_00003EB4:		
	asm("mflo       $a2");
	asm("mfhi       $a0");
	asm("mflo       $t7");
	asm("mult       $a2, $s0");
	a0 = a0 << 16;

loc_00003EC8:		
	a3 = a0 | a1;
	asm("mflo       $t5");
	v0 = (u32)a3 < (u32)t5;
	cond = (v0 == 0);
	asm("divu       $t4, $t3");
	if (cond)
		goto loc_00003F00;
	a3 = a3 + t0;
	v0 = (u32)a3 < (u32)t0;
	t7 = a2 - 1;
	if (v0 != 0)
		goto loc_00003F00;
	v0 = (u32)a3 < (u32)t5;
	if (v0 == 0)
	{
		a3 = a3 - t5;
		goto loc_00003F04;
	}
	t7 = t7 - 1;
	a3 = a3 + t0;

loc_00003F00:		
	a3 = a3 - t5;

loc_00003F04:		
	asm("divu       $a3, $t3");
	a0 = t2 & 0xFFFF;
	if (t3 == 0)
	{
		asm("break      0x7");
		goto loc_00003F14;
	}

loc_00003F14:		
	asm("mflo       $v1");
	asm("mfhi       $v0");
	asm("mflo       $a2");
	asm("mult       $v1, $s0");
	v0 = v0 << 16;
	a1 = v0 | a0;
	asm("mflo       $t5");
	v1 = (u32)a1 < (u32)t5;
	cond = (v1 == 0);
	asm("divu       $a3, $t3");
	if (cond)
		goto loc_00003F60;
	a1 = a1 + t0;
	v0 = (u32)a1 < (u32)t0;
	a2 = a2 - 1;
	if (v0 != 0)
		goto loc_00003F60;
	v0 = (u32)a1 < (u32)t5;
	cond = (v0 == 0);
	v0 = t7 << 16;
	if (cond)
		goto loc_00003F64;
	a1 = a1 + t0;
	a2 = a2 - 1;

loc_00003F60:		
	v0 = t7 << 16;

loc_00003F64:		
	a0 = v0 | a2;
	a1 = a1 - t5;
	asm("multu      $a0, $t1");
	asm("mfhi       $v1");
	v0 = (u32)a1 < (u32)v1;
	if (v0 != 0)
	{
		a0 = a0 - 1;
		goto loc_00003B94;
	}
	asm("xor        $v0, $v1, $a1");
	asm("mflo       $a1");
	v1 = (u32)t6 < (u32)a1;

loc_00003F8C:		
	v0 = (u32)v0 < (u32)1;
	v0 = v0 & v1;
	a2 = 0;
	if (v0 == 0)
		goto loc_00003B98;
	a0 = a0 - 1;
	goto loc_00003B98;
}

sub_00003FA4(...) // at 0x00003FA4 
{
	sp = sp - 48;
	a0 = sp + 16;
	a1 = sp;

loc_00003FB0:		
	*(s32*)(sp + 32) = ra;
	asm("swc1       $fpr12, 16($sp)");
	v0 = sub_00004D58(...);
	t1 = 0;
	t0 = *(s32*)(sp + 12);
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(sp + 8);
	v0 = (u32)t0 >> 2;
	t1 = t1 << 30;
	t1 = t1 | v0;
	t0 = t0 << 30;
	v0 = sub_00004B14(...);
	ra = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);
}

sub_00003FF0(...) // at 0x00003FF0 
{
	a3 = a0;
	a0 = *(s32*)(a0 + 0);
	t2 = a2;
	t0 = a1;
	v0 = (u32)a0 < (u32)2;
	a2 = a3;
	if (v0 != 0)
		goto loc_00004044;
	v1 = *(s32*)(a1 + 0);
	v0 = (u32)v1 < (u32)2;
	a2 = a1;
	if (v0 != 0)
		goto loc_00004044;
	v0 = a0 ^ 0x4;
	cond = (v0 != 0);
	v0 = v1 ^ 0x4;
	if (cond)
		goto loc_00004054;
	a2 = a3;
	if (v0 != 0)
		goto loc_00004044;
	a0 = *(s32*)(a1 + 4);
	v1 = *(s32*)(a3 + 4);
	v0 = 0x20000;
	a2 = v0 - 11536;
	if (v1 == a0)
		goto loc_0000404C;

loc_00004044:		
	v0 = a2;
	return (v0);

loc_0000404C:		
	a2 = a3;
	goto loc_00004044;

loc_00004054:		
	a2 = a1;
	if (v0 == 0)
		goto loc_00004044;
	v0 = v1 ^ 0x2;
	cond = (v0 != 0);
	v0 = a0 ^ 0x2;
	if (cond)
		goto loc_000040B4;
	a2 = a3;
	if (v0 != 0)
		goto loc_00004044;
	*(s32*)(t2 + 0) = a0;
	a2 = t2;
	v0 = *(s32*)(a3 + 4);
	*(s32*)(t2 + 4) = v0;
	v1 = *(s32*)(a3 + 8);
	*(s32*)(t2 + 8) = v1;
	v0 = *(s32*)(a3 + 12);
	*(s32*)(t2 + 12) = v0;
	v1 = *(s32*)(a3 + 16);
	*(s32*)(t2 + 16) = v1;
	a0 = *(s32*)(a3 + 20);
	*(s32*)(t2 + 20) = a0;
	v0 = *(s32*)(a3 + 4);
	v1 = *(s32*)(a1 + 4);
	v0 = v0 & v1;
	*(s32*)(t2 + 4) = v0;
	goto loc_00004044;

loc_000040B4:		
	a2 = a1;
	if (v0 == 0)
		goto loc_00004044;
	t3 = *(s32*)(a3 + 8);
	t1 = *(s32*)(a1 + 8);
	t4 = *(s32*)(a3 + 16);
	t5 = *(s32*)(a3 + 20);
	t6 = *(s32*)(a1 + 16);
	t7 = *(s32*)(a1 + 20);
	v0 = t3 - t1;
	asm("negu       $v1, $v0");
	asm("max        $v0, $v0, $v1");
	v0 = (s32)v0 < (s32)64;
	cond = (v0 == 0);
	v0 = (s32)t1 < (s32)t3;
	if (cond)
		goto loc_00004310;
	cond = (v0 == 0);
	v0 = (s32)t3 < (s32)t1;
	if (cond)
		goto loc_00004130;
	t9 = 0;
	t8 = 1;
	t1 = t3 - t1;

loc_00004100:		
	a0 = (u32)t6 >> 1;
	a2 = t7 << 31;
	a0 = a0 | a2;
	a1 = (u32)t7 >> 1;
	v0 = t6 & t8;
	v1 = t7 & t9;
	t1 = t1 - 1;
	t6 = v0 | a0;
	t7 = v1 | a1;
	if (t1 != 0)
		goto loc_00004100;
	t1 = t3;
	v0 = (s32)t3 < (s32)t1;

loc_00004130:		
	if (v0 == 0)
	{
		a2 = *(s32*)(a3 + 4);
		goto loc_00004174;
	}
	t9 = 0;
	t8 = 1;
	t3 = t1 - t3;

loc_00004144:		
	a0 = (u32)t4 >> 1;
	a2 = t5 << 31;
	a0 = a0 | a2;
	a1 = (u32)t5 >> 1;
	v0 = t4 & t8;
	v1 = t5 & t9;
	t3 = t3 - 1;
	t4 = v0 | a0;
	t5 = v1 | a1;
	if (t3 != 0)
		goto loc_00004144;
	t3 = t1;

loc_00004170:		
	a2 = *(s32*)(a3 + 4);

loc_00004174:		
	v0 = *(s32*)(t0 + 4);
	a1 = t7 - t5;
	if (a2 == v0)
		goto loc_000042E8;
	v0 = (u32)t6 < (u32)t4;
	a0 = t6 - t4;
	a1 = a1 - v0;
	if (a2 != 0)
		goto loc_000041A0;
	v0 = (u32)t4 < (u32)t6;
	a1 = t5 - t7;
	a0 = t4 - t6;
	a1 = a1 - v0;

loc_000041A0:		
	v0 = 1;
	if ((s32)a1 < 0)
		goto loc_000042C4;
	*(s32*)(t2 + 8) = t3;
	*(s32*)(t2 + 16) = a0;
	*(s32*)(t2 + 20) = a1;
	*(s32*)(t2 + 4) = 0;

loc_000041B8:		
	t0 = *(s32*)(t2 + 16);
	t1 = *(s32*)(t2 + 20);
	a2 = 0xFFF0000;
	a2 = a2 | 0xFFFF;
	a0 = t0 - 1;
	v1 = (u32)a0 < (u32)-1;
	a1 = t1 - 1;
	a1 = a1 + v1;
	v0 = (u32)a2 < (u32)a1;
	if (v0 != 0)
	{
		v0 = *(s32*)(t2 + 20);
		goto loc_00004250;
	}
	v0 = (u32)a0 < (u32)-1;
	if (a1 == a2)
		goto loc_000042B4;
	v1 = (u32)t0 >> 31;

loc_000041F0:		
	v0 = *(s32*)(t2 + 8);

loc_000041F4:		
	a3 = t1 << 1;
	a3 = a3 | v1;
	a2 = t0 << 1;
	t3 = 0xFFF0000;
	a0 = a2 - 1;
	v1 = (u32)a0 < (u32)-1;
	a1 = a3 - 1;
	a1 = a1 + v1;
	t3 = t3 | 0xFFFF;
	v0 = v0 - 1;
	v1 = (u32)t3 < (u32)a1;
	t4 = (u32)a0 < (u32)-1;
	*(s32*)(t2 + 8) = v0;
	t0 = a2;
	*(s32*)(t2 + 16) = a2;
	*(s32*)(t2 + 20) = a3;
	t1 = a3;
	if (v1 != 0)
		goto loc_0000424C;
	v1 = (u32)t0 >> 31;
	if (a1 != t3)
		goto loc_000041F0;
	if (t4 != 0)
	{
		v0 = *(s32*)(t2 + 8);
		goto loc_000041F4;
	}

loc_0000424C:		
	v0 = *(s32*)(t2 + 20);

loc_00004250:		
	v1 = 0x1FFF0000;
	v1 = v1 | 0xFFFF;
	a0 = 3;
	v1 = (u32)v1 < (u32)v0;
	*(s32*)(t2 + 0) = a0;
	if (v1 == 0)
		goto loc_000042AC;
	a0 = *(s32*)(t2 + 16);
	a1 = *(s32*)(t2 + 20);
	a2 = *(s32*)(t2 + 8);
	v1 = 0;
	v0 = 1;
	v0 = a0 & v0;
	a3 = a1 << 31;
	a0 = (u32)a0 >> 1;
	v1 = a1 & v1;
	a0 = a0 | a3;
	a1 = (u32)a1 >> 1;
	v0 = v0 | a0;
	v1 = v1 | a1;
	a2 = a2 + 1;
	*(s32*)(t2 + 16) = v0;
	*(s32*)(t2 + 20) = v1;
	*(s32*)(t2 + 8) = a2;

loc_000042AC:		
	a2 = t2;
	goto loc_00004044;

loc_000042B4:		
	v1 = (u32)t0 >> 31;
	if (v0 != 0)
		goto loc_000041F0;
	v0 = *(s32*)(t2 + 20);
	goto loc_00004250;

loc_000042C4:		
	asm("negu       $a0, $a0");
	asm("negu       $a1, $a1");
	v1 = (u32)0 < (u32)a0;
	a1 = a1 - v1;
	*(s32*)(t2 + 4) = v0;
	*(s32*)(t2 + 8) = t3;
	*(s32*)(t2 + 16) = a0;
	*(s32*)(t2 + 20) = a1;
	goto loc_000041B8;

loc_000042E8:		
	v0 = t4 + t6;
	a0 = (u32)v0 < (u32)t6;
	v1 = t5 + t7;
	v1 = v1 + a0;
	*(s32*)(t2 + 4) = a2;
	*(s32*)(t2 + 8) = t3;
	*(s32*)(t2 + 16) = v0;
	*(s32*)(t2 + 20) = v1;
	v0 = *(s32*)(t2 + 20);
	goto loc_00004250;

loc_00004310:		
	if (v0 == 0)
		goto loc_00004328;
	t6 = 0;
	t7 = 0;
	a2 = *(s32*)(a3 + 4);
	goto loc_00004174;

loc_00004328:		
	t4 = 0;
	t5 = 0;
	t3 = t1;
	goto loc_00004170;
}

sub_00004338(...) // at 0x00004338 
{
	sp = sp - 144;
	v1 = a1;
	v0 = a0;
	*(s32*)(sp + 128) = s0;
	a0 = sp + 96;
	s0 = sp + 32;
	*(s32*)(sp + 132) = ra;
	*(s32*)(sp + 112) = a2;
	*(s32*)(sp + 116) = a3;
	*(s32*)(sp + 96) = v0;
	*(s32*)(sp + 100) = v1;
	a1 = sp;
	v0 = sub_000050B4(...);
	a0 = sp + 112;
	a1 = s0;
	v0 = sub_000050B4(...);
	a1 = s0;
	a2 = sp + 64;
	a0 = sp;
	v0 = sub_00003FF0(...);
	a0 = v0;
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 132);
	s0 = *(s32*)(sp + 128);
	sp = sp + 144;
	return (v0);
}

sub_000043A0(...) // at 0x000043A0 
{
	sp = sp - 144;
	v1 = a1;
	v0 = a0;
	*(s32*)(sp + 128) = s0;
	a0 = sp + 96;
	s0 = sp + 32;
	*(s32*)(sp + 132) = ra;
	*(s32*)(sp + 96) = v0;
	*(s32*)(sp + 100) = v1;
	*(s32*)(sp + 112) = a2;
	*(s32*)(sp + 116) = a3;

loc_000043D0:		
	a1 = sp;
	v0 = sub_000050B4(...);
	a0 = sp + 112;
	a1 = s0;
	v0 = sub_000050B4(...);
	v0 = *(s32*)(sp + 36);
	a1 = s0;
	a2 = sp + 64;
	a0 = sp;
	v0 = v0 ^ 0x1;
	*(s32*)(sp + 36) = v0;
	v0 = sub_00003FF0(...);
	a0 = v0;
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 132);
	s0 = *(s32*)(sp + 128);
	sp = sp + 144;
	return (v0);
}

sub_00004414(...) // at 0x00004414 
{
	sp = sp - 160;
	v0 = a0;
	v1 = a1;
	*(s32*)(sp + 128) = s0;
	a0 = sp + 96;
	a1 = sp;
	s0 = sp + 32;
	*(s32*)(sp + 96) = v0;
	*(s32*)(sp + 100) = v1;
	*(s32*)(sp + 148) = ra;
	*(s32*)(sp + 112) = a2;
	*(s32*)(sp + 116) = a3;
	*(s32*)(sp + 144) = s5;
	*(s32*)(sp + 140) = s4;
	*(s32*)(sp + 136) = s3;
	*(s32*)(sp + 132) = s2;
	v0 = sub_000050B4(...);
	a0 = sp + 112;
	a1 = s0;
	v0 = sub_000050B4(...);
	v1 = *(s32*)(sp + 0);
	t5 = sp;
	v0 = (u32)v1 < (u32)2;
	t4 = sp + 64;
	if (v0 != 0)
		goto loc_000044A4;
	a0 = *(s32*)(sp + 32);
	v0 = (u32)a0 < (u32)2;
	if (v0 != 0)
	{
		v1 = *(s32*)(sp + 36);
		goto loc_00004500;
	}
	v0 = v1 ^ 0x4;
	cond = (v0 != 0);
	v0 = a0 ^ 0x4;
	if (cond)
		goto loc_000044E4;
	v1 = a0 ^ 0x2;
	v0 = 0x20000;
	a0 = v0 - 11536;
	if (v1 == 0)
		goto loc_000044BC;

loc_000044A4:		
	v0 = *(s32*)(sp + 4);

loc_000044A8:		
	v1 = *(s32*)(sp + 36);
	a0 = sp;
	asm("xor        $v0, $v0, $v1");
	v0 = (u32)0 < (u32)v0;
	*(s32*)(sp + 4) = v0;

loc_000044BC:		
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 148);
	s5 = *(s32*)(sp + 144);
	s4 = *(s32*)(sp + 140);
	s3 = *(s32*)(sp + 136);
	s2 = *(s32*)(sp + 132);
	s0 = *(s32*)(sp + 128);
	sp = sp + 160;
	return (v0);

loc_000044E4:		
	cond = (v0 != 0);
	v0 = v1 ^ 0x2;
	if (cond)
		goto loc_00004518;
	v0 = 0x20000;
	v1 = v1 ^ 0x2;
	a0 = v0 - 11536;
	if (v1 == 0)
		goto loc_000044BC;
	v1 = *(s32*)(sp + 36);

loc_00004500:		
	v0 = *(s32*)(sp + 4);
	a0 = s0;
	asm("xor        $v0, $v0, $v1");
	v0 = (u32)0 < (u32)v0;
	*(s32*)(sp + 36) = v0;
	goto loc_000044BC;

loc_00004518:		
	cond = (v0 == 0);
	v0 = *(s32*)(sp + 4);
	if (cond)
		goto loc_000044A8;
	v0 = a0 ^ 0x2;
	v1 = *(s32*)(sp + 36);
	if (v0 == 0)
		goto loc_00004500;
	a2 = *(s32*)(sp + 20);
	a3 = *(s32*)(sp + 48);
	t0 = *(s32*)(sp + 16);
	a1 = *(s32*)(sp + 52);
	asm("multu      $a3, $a2");
	s2 = 0;
	s3 = 0;
	asm("mfhi       $v1");
	asm("mflo       $v0");
	asm("multu      $a1, $t0");
	asm("mfhi       $t3");
	asm("mflo       $t2");
	asm("multu      $a1, $a2");
	t6 = t2 + v0;
	t1 = (u32)t6 < (u32)v0;
	t7 = t3 + v1;
	t7 = t7 + t1;
	asm("mfhi       $s5");
	asm("mflo       $s4");
	asm("multu      $a3, $t0");
	a0 = (u32)t7 < (u32)t3;
	asm("mfhi       $a3");
	cond = (a0 != 0);
	asm("mflo       $a2");
	if (cond)
		goto loc_0000477C;
	v0 = (u32)t6 < (u32)t2;
	if (t3 == t7)
		goto loc_00004774;
	t2 = 0;

loc_00004598:		
	t3 = t6 << 0;
	t8 = a2 + t2;
	a1 = (u32)t8 < (u32)t2;
	t9 = a3 + t3;
	t9 = t9 + a1;
	v0 = (u32)t9 < (u32)a3;
	if (v0 != 0)
	{
		s2 = s2 + 1;
		goto loc_00004768;
	}
	v0 = (u32)t8 < (u32)a2;
	if (a3 == t9)
		goto loc_0000475C;

loc_000045C0:		
	v0 = (u32)t7 >> 0;

loc_000045C4:		
	v0 = v0 + s4;
	v1 = 0;
	t0 = *(s32*)(s0 + 4);
	a2 = *(s32*)(t5 + 4);
	a0 = *(s32*)(t5 + 8);
	a3 = *(s32*)(s0 + 8);
	t1 = (u32)v0 < (u32)s4;
	v1 = v1 + s5;
	v1 = v1 + t1;
	t2 = s2 + v0;
	t1 = (u32)t2 < (u32)v0;
	a1 = 0x1FFF0000;
	t3 = s3 + v1;
	t3 = t3 + t1;
	asm("xor        $a2, $a2, $t0");
	a0 = a0 + a3;
	a1 = a1 | 0xFFFF;
	a0 = a0 + 4;
	a2 = (u32)0 < (u32)a2;
	a1 = (u32)a1 < (u32)t3;
	*(s32*)(t4 + 8) = a0;
	t0 = t8;
	t1 = t9;
	*(s32*)(t4 + 4) = a2;
	if (a1 == 0)
		goto loc_00004688;
	a2 = 0x1FFF0000;
	t7 = 0;
	t6 = 1;
	t8 = 0;
	t9 = 0x80000000;
	a2 = a2 | 0xFFFF;
	v0 = *(s32*)(t4 + 8);

loc_00004644:		
	v1 = t3 << 31;
	a0 = t2 & t6;
	t3 = (u32)t3 >> 1;
	t2 = (u32)t2 >> 1;
	v0 = v0 + 1;
	t2 = t2 | v1;
	*(s32*)(t4 + 8) = v0;
	v1 = (u32)a2 < (u32)t3;
	if (a0 == 0)
		goto loc_00004680;
	v0 = t1 << 31;
	t0 = (u32)t0 >> 1;
	t0 = t0 | v0;
	t1 = (u32)t1 >> 1;
	t0 = t0 | t8;
	t1 = t1 | t9;

loc_00004680:		
	if (v1 != 0)
	{
		v0 = *(s32*)(t4 + 8);
		goto loc_00004644;
	}

loc_00004688:		
	v0 = 0xFFF0000;
	v0 = v0 | 0xFFFF;
	v0 = (u32)v0 < (u32)t3;
	a0 = 0xFFF0000;
	if (v0 != 0)
		goto loc_000046E0;
	a3 = 0;
	a2 = 1;
	a0 = a0 | 0xFFFF;

loc_000046A8:		
	v0 = *(s32*)(t4 + 8);
	v1 = (u32)t2 >> 31;
	t3 = t3 << 1;
	v0 = v0 - 1;
	t3 = t3 | v1;
	t2 = t2 << 1;
	*(s32*)(t4 + 8) = v0;
	if ((s32)t1 < 0)
		goto loc_00004750;

loc_000046C8:		
	v1 = (u32)t0 >> 31;
	t1 = t1 << 1;
	v0 = (u32)a0 < (u32)t3;
	t1 = t1 | v1;
	t0 = t0 << 1;
	if (v0 == 0)
		goto loc_000046A8;

loc_000046E0:		
	v1 = 0;
	v0 = 255;
	v0 = t2 & v0;
	a0 = 128;
	v1 = t3 & v1;
	if (v0 == a0)
		goto loc_00004710;

loc_000046F8:		
	v0 = 3;

loc_000046FC:		
	*(s32*)(t4 + 16) = t2;
	*(s32*)(t4 + 20) = t3;
	a0 = t4;
	*(s32*)(t4 + 0) = v0;
	goto loc_000044BC;

loc_00004710:		
	v0 = 3;
	if (v1 != 0)
		goto loc_000046FC;
	v1 = 0;
	v0 = 256;
	v0 = t2 & v0;
	v1 = t3 & v1;
	v0 = v0 | v1;
	if (v0 != 0)
	{
		t2 = t2 + 128;
		goto loc_00004744;
	}
	v0 = t0 | t1;
	cond = (v0 == 0);
	v0 = 3;
	if (cond)
		goto loc_000046FC;
	t2 = t2 + 128;

loc_00004744:		
	v0 = (u32)t2 < (u32)128;
	t3 = t3 + v0;
	goto loc_000046F8;

loc_00004750:		
	t2 = t2 | a2;
	t3 = t3 | a3;
	goto loc_000046C8;

loc_0000475C:		
	cond = (v0 == 0);
	v0 = (u32)t7 >> 0;
	if (cond)
		goto loc_000045C4;
	s2 = s2 + 1;

loc_00004768:		
	v0 = (u32)s2 < (u32)1;
	s3 = s3 + v0;
	goto loc_000045C0;

loc_00004774:		
	if (v0 == 0)
	{
		t2 = 0;
		goto loc_00004598;
	}

loc_0000477C:		
	s2 = 0;
	s3 = 1;
	t2 = 0;
	goto loc_00004598;
}

sub_0000478C(...) // at 0x0000478C 
{
	sp = sp - 112;
	v0 = a0;
	v1 = a1;
	*(s32*)(sp + 96) = s0;
	a0 = sp + 64;
	a1 = sp;
	*(s32*)(sp + 64) = v0;
	*(s32*)(sp + 68) = v1;
	*(s32*)(sp + 100) = ra;
	*(s32*)(sp + 80) = a2;
	*(s32*)(sp + 84) = a3;
	s0 = sp + 32;
	v0 = sub_000050B4(...);
	a0 = sp + 80;
	a1 = s0;
	v0 = sub_000050B4(...);
	a1 = *(s32*)(sp + 0);
	t5 = sp;
	v0 = (u32)a1 < (u32)2;
	a0 = sp;
	if (v0 != 0)
		goto loc_00004824;
	a2 = *(s32*)(sp + 32);
	v0 = (u32)a2 < (u32)2;
	a0 = s0;
	if (v0 != 0)
		goto loc_00004824;
	v1 = *(s32*)(sp + 4);
}

sub_000047F4(...) // at 0x000047F4 
{
	a0 = *(s32*)(sp + 36);
	v0 = a1 ^ 0x4;
	asm("xor        $v1, $v1, $a0");
	*(s32*)(sp + 4) = v1;
	if (v0 == 0)
		goto loc_00004814;
	v0 = a1 ^ 0x2;
	cond = (v0 != 0);
	v0 = a2 ^ 0x4;
	if (cond)
		goto loc_0000483C;

loc_00004814:		
	v0 = 0x20000;
	a0 = v0 - 11536;
	if (a1 == a2)
		goto loc_00004824;
	a0 = sp;

loc_00004824:		
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	sp = sp + 112;
	return (v0);

loc_0000483C:		
	cond = (v0 != 0);
	v0 = a2 ^ 0x2;
	if (cond)
		goto loc_00004860;
	v0 = 0;
	v1 = 0;
	a0 = sp;
	*(s32*)(sp + 16) = v0;
	*(s32*)(sp + 20) = v1;
	*(s32*)(sp + 8) = 0;
	goto loc_00004824;

loc_00004860:		

loc_00004864:		
	v1 = *(s32*)(sp + 8);
	if (v0 != 0)
		goto loc_00004878;
	v0 = 4;
	a0 = sp;
	*(s32*)(sp + 0) = v0;
	goto loc_00004824;

loc_00004878:		
	a0 = *(s32*)(sp + 16);
	a1 = *(s32*)(sp + 20);
	t2 = *(s32*)(sp + 48);
	t3 = *(s32*)(sp + 52);
	v0 = *(s32*)(sp + 40);
	t4 = (u32)a1 < (u32)t3;
	v1 = v1 - v0;
	*(s32*)(sp + 8) = v1;
	if (t4 != 0)
		goto loc_00004990;
	v0 = (u32)a0 < (u32)t2;
	if (t3 == a1)
		goto loc_00004988;

loc_000048A4:		
	t0 = 0;
	t1 = 0x10000000;
	t6 = 0;
	t7 = 0;

loc_000048B4:		
	v0 = t1 << 31;
	if (t4 != 0)
		goto loc_000048E0;
	v0 = (u32)a0 < (u32)t2;
	if (t3 == a1)
		goto loc_00004978;
	v0 = (u32)a0 < (u32)t2;

loc_000048C8:		
	a1 = a1 - t3;
	a0 = a0 - t2;
	a1 = a1 - v0;
	t6 = t6 | t0;
	t7 = t7 | t1;
	v0 = t1 << 31;

loc_000048E0:		
	t0 = (u32)t0 >> 1;
	a3 = a1 << 1;
	v1 = (u32)a0 >> 31;
	t0 = t0 | v0;
	t1 = (u32)t1 >> 1;
	a3 = a3 | v1;
	a2 = a0 << 1;
	v0 = t0 | t1;
	a0 = a2;
	a1 = a3;
	t4 = (u32)a3 < (u32)t3;
	if (v0 != 0)
		goto loc_000048B4;
	v1 = 0;
	v0 = 255;
	v0 = t6 & v0;

loc_0000491C:		
	a0 = 128;
	v1 = t7 & v1;
	if (v0 == a0)
		goto loc_00004938;

loc_00004928:		
	*(s32*)(t5 + 16) = t6;
	*(s32*)(t5 + 20) = t7;
	a0 = t5;
	goto loc_00004824;

loc_00004938:		
	if (v1 != 0)
		goto loc_00004928;
	v1 = 0;
	v0 = 256;
	v0 = t6 & v0;
	v1 = t7 & v1;
	v0 = v0 | v1;
	if (v0 != 0)
	{
		t6 = t6 + 128;
		goto loc_0000496C;
	}
	v0 = a2 | a3;
	if (v0 == 0)
		goto loc_00004928;
	t6 = t6 + 128;

loc_0000496C:		
	v0 = (u32)t6 < (u32)128;
	t7 = t7 + v0;
	goto loc_00004928;

loc_00004978:		
	if (v0 != 0)
	{
		v0 = t1 << 31;
		goto loc_000048E0;
	}
	v0 = (u32)a0 < (u32)t2;
	goto loc_000048C8;

loc_00004988:		
	if (v0 == 0)
		goto loc_000048A4;

loc_00004990:		
	v0 = v1 - 1;
	a1 = a1 << 1;
	v1 = (u32)a0 >> 31;
	*(s32*)(sp + 8) = v0;
	a1 = a1 | v1;
	a0 = a0 << 1;
	t4 = (u32)a1 < (u32)t3;
	goto loc_000048A4;
}

sub_000049B0(...) // at 0x000049B0 
{
	sp = sp - 112;
	v0 = a0;
	v1 = a1;
	*(s32*)(sp + 96) = s0;
	a0 = sp + 64;
	a1 = sp;
	*(s32*)(sp + 64) = v0;
	*(s32*)(sp + 68) = v1;

loc_000049D0:		
	*(s32*)(sp + 100) = ra;
	*(s32*)(sp + 80) = a2;
	*(s32*)(sp + 84) = a3;
	s0 = sp + 32;
	v0 = sub_000050B4(...);
	a0 = sp + 80;
	a1 = s0;
	v0 = sub_000050B4(...);
	v0 = *(s32*)(sp + 0);
	v0 = (u32)v0 < (u32)2;

loc_000049FC:		
	v1 = -1;
	if (v0 != 0)
		goto loc_00004A14;
	v0 = *(s32*)(sp + 32);
	a1 = s0;
	v0 = (u32)v0 < (u32)2;
	a0 = sp;
	if (v0 == 0)
		goto loc_00004A28;

loc_00004A14:		
	ra = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	v0 = v1;

loc_00004A24:		
	sp = sp + 112;
	return (v0);

loc_00004A28:		
	v0 = sub_000051C8(...);
	v1 = v0;
	goto loc_00004A14;
}

sub_00004A38(...) // at 0x00004A38 
{
	sp = sp - 48;
	v1 = (u32)a0 >> 31;
	v0 = 3;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = v1;
	if (a0 != 0)
		goto loc_00004A70;
	v0 = 2;
	*(s32*)(sp + 0) = v0;

loc_00004A5C:		
	a0 = sp;
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 32);

loc_00004A68:		
	sp = sp + 48;
	return (v0);

loc_00004A70:		
	v0 = 60;
	*(s32*)(sp + 8) = v0;
	if (v1 == 0)
		goto loc_00004B08;
	v0 = 0x80000000;
	if (a0 == v0)
		goto loc_00004AF0;
	asm("negu       $v0, $a0");
	v1 = (s32)v0 >> 31;

loc_00004A90:		
	*(s32*)(sp + 16) = v0;
	*(s32*)(sp + 20) = v1;
	v0 = 0xFFF0000;
	v0 = v0 | 0xFFFF;
	v1 = *(s32*)(sp + 20);
	v0 = (u32)v0 < (u32)v1;
	a1 = *(s32*)(sp + 8);
	if (v0 != 0)
		goto loc_00004A5C;
	a2 = 0xFFF0000;
	a2 = a2 | 0xFFFF;

loc_00004AB8:		
	v0 = *(s32*)(sp + 16);
	v1 = *(s32*)(sp + 20);
	a0 = (u32)v0 >> 31;
	v1 = v1 << 1;
	v1 = v1 | a0;
	v0 = v0 << 1;
	*(s32*)(sp + 16) = v0;
	*(s32*)(sp + 20) = v1;
	a0 = *(s32*)(sp + 20);
	a0 = (u32)a2 < (u32)a0;
	a1 = a1 - 1;
	if (a0 == 0)
		goto loc_00004AB8;
	*(s32*)(sp + 8) = a1;
	goto loc_00004A5C;

loc_00004AF0:		
	v0 = 0x70000;
	v0 = *(s32*)(v0 - 16664);

loc_00004AF8:		
	v1 = 0x70000;
	v1 = *(s32*)(v1 - 16660);
	ra = *(s32*)(sp + 32);
	goto loc_00004A68;

loc_00004B08:		
	v0 = a0;
	v1 = (s32)a0 >> 31;
	goto loc_00004A90;
}

sub_00004B14(...) // at 0x00004B14 
{
	sp = sp - 48;
	v0 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = a1;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 16) = t0;
	*(s32*)(sp + 20) = t1;
	a0 = sp;
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);
}

sub_00004B48(...) // at 0x00004B48 
{
	sp = sp - 64;
	v0 = a0;
	v1 = a1;
	a0 = sp + 32;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 32) = v0;
	*(s32*)(sp + 36) = v1;
	a1 = sp;
	v0 = sub_000050B4(...);
	v1 = 0;
	v0 = 0x3FFF0000;
	v0 = v0 | 0xFFFF;
	t0 = *(s32*)(sp + 16);
	t1 = *(s32*)(sp + 20);
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	v1 = t1 & v1;
	v0 = t0 & v0;
	a2 = t1 << 2;
	v0 = v0 | v1;
	t0 = (u32)t0 >> 30;
	t0 = t0 | a2;
	v0 = (u32)0 < (u32)v0;
	a2 = *(s32*)(sp + 8);
	v0 = v0 | t0;
	a3 = v0;
	v0 = sub_00004E1C(...);
	ra = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

sub_00004BC0(...) // at 0x00004BC0 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v0 = sub_00003FA4(...);
	a0 = v0;
	a1 = v1;
	a2 = 0;
	a3 = 0;
	s2 = v0;
	s3 = v1;
	v0 = sub_0000532C(...);
	a0 = s2;
	a2 = 0;
	a3 = 0;
	a1 = s3;
	if ((s32)v0 < 0)
		goto loc_00004CE4;
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16656);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16652);
	s0 = 0;
	v0 = sub_00004414(...);
	a1 = v1;
	a0 = v0;
	v0 = sub_00005508(...);
	s1 = v0 << 0;
	a2 = 0;
	a3 = 0;
	a0 = s0;
	a1 = s1;
	v0 = sub_000053F8(...);
	a1 = 0;
	a0 = 1;
	a2 = (u32)s0 >> 1;
	v1 = s1 << 31;
	a0 = s0 & a0;
	a1 = s1 & a1;
	a2 = a2 | v1;
	a3 = (u32)s1 >> 1;
	a0 = a0 | a2;
	a1 = a1 | a3;
	if ((s32)v0 <= 0)
		goto loc_00004D34;
	a0 = s0;
	a1 = s1;
	v0 = sub_00005434(...);
	a0 = s2;

loc_00004C84:		
	a1 = s3;
	a2 = v0;
	a3 = v1;
	v0 = sub_000043A0(...);
	a0 = v0;
	a1 = v1;
	a2 = 0;
	a3 = 0;
	s2 = v0;
	s3 = v1;
	v0 = sub_0000532C(...);
	a0 = s2;
	a1 = s3;
	if ((s32)v0 < 0)
		goto loc_00004D08;
	a0 = s2;
	a1 = s3;
	v0 = sub_00005508(...);
	s0 = s0 + v0;
	v1 = 0;
	a0 = (u32)s0 < (u32)v0;
	s1 = s1 + v1;
	s1 = s1 + a0;

loc_00004CDC:		
	a2 = s0;
	a3 = s1;

loc_00004CE4:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	v1 = a3;
	sp = sp + 32;
	return (v0);

loc_00004D08:		
	v0 = sub_000053B4(...);
	a0 = v0;
	a1 = v1;
	v0 = sub_00005508(...);
	v1 = 0;
	a0 = (u32)s0 < (u32)v0;
	s1 = s1 - v1;
	s0 = s0 - v0;
	s1 = s1 - a0;
	goto loc_00004CDC;

loc_00004D34:		
	v0 = sub_00005434(...);
	a0 = v0;
	a1 = v1;
	a2 = v0;
	a3 = v1;
	v0 = sub_00004338(...);
	a0 = s2;
	goto loc_00004C84;
}

sub_00004D58(...) // at 0x00004D58 
{
	v0 = *(s32*)(a0 + 0);
	v1 = (u32)v0 >> 31;
	a2 = v0;
	NONE;
	*(s32*)(a1 + 4) = v1;
	NONE;
	if (a0 != 0)
		goto loc_00004DCC;
	v0 = 2;
	if (a2 == 0)
		goto loc_00004DC4;
	v0 = 0x3FFF0000;
	a2 = a2 << 7;
	v0 = v0 | 0xFFFF;
	v1 = -126;
	a0 = 3;
	v0 = (u32)v0 < (u32)a2;
	*(s32*)(a1 + 8) = v1;
	*(s32*)(a1 + 0) = a0;
	if (v0 != 0)
		goto loc_00004DBC;
	a0 = 0x3FFF0000;
	a0 = a0 | 0xFFFF;

loc_00004DA8:		
	a2 = a2 << 1;
	v0 = (u32)a0 < (u32)a2;
	v1 = v1 - 1;
	if (v0 == 0)
		goto loc_00004DA8;
	*(s32*)(a1 + 8) = v1;

loc_00004DBC:		
	*(s32*)(a1 + 12) = a2;
	return (v0);

loc_00004DC4:		
	*(s32*)(a1 + 0) = v0;
	return (v0);

loc_00004DCC:		
	v0 = 255;
	cond = (a0 == v0);
	v0 = a2 << 7;
	if (cond)
		goto loc_00004DF4;
	v1 = 0x40000000;
	v0 = v0 | v1;
	a0 = a0 - 127;
	*(s32*)(a1 + 12) = v0;
	v0 = 3;
	*(s32*)(a1 + 8) = a0;
	goto loc_00004DC4;

loc_00004DF4:		
	if (a2 != 0)
	{
		v0 = 0x100000;
		goto loc_00004E04;
	}
	v0 = 4;
	goto loc_00004DC4;

loc_00004E04:		
	v0 = a2 & v0;
	if (v0 == 0)
	{
		*(s32*)(a1 + 0) = 0;
		goto loc_00004DBC;
	}
	v0 = 1;
	*(s32*)(a1 + 0) = v0;
	goto loc_00004DBC;
}

sub_00004E1C(...) // at 0x00004E1C 
{
	sp = sp - 32;
	v0 = a0;
	a0 = sp;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = a1;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 12) = a3;
	v0 = sub_0000558C(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_00004E4C(...) // at 0x00004E4C 
{
	v1 = *(s32*)(a0 + 0);
	sp = sp - 16;
	t2 = *(s32*)(a0 + 16);
	t3 = *(s32*)(a0 + 20);
	v0 = (u32)v1 < (u32)2;
	t4 = *(s32*)(a0 + 4);
	t1 = 0;
	if (v0 == 0)
		goto loc_00004EA8;
	v0 = 0;
	v1 = 0x80000;
	t2 = t2 | v0;
	t3 = t3 | v1;
	t1 = 2047;

loc_00004E80:		
	v0 = *(s32*)(sp + 4);

loc_00004E84:		
	NONE;
	NONE;
	NONE;
	*(s32*)(sp + 4) = v0;
	*(s32*)(sp + 0) = t2;
	v0 = *(s32*)(sp + 0);
	v1 = *(s32*)(sp + 4);
	sp = sp + 16;
	return (v0);

loc_00004EA8:		
	v0 = v1 ^ 0x4;
	if (v0 == 0)
	{
		t1 = 2047;
		goto loc_00005014;
	}
	v0 = v1 ^ 0x2;
	if (v0 == 0)
		goto loc_00005014;
	v0 = t2 | t3;
	cond = (v0 == 0);
	v0 = *(s32*)(sp + 4);
	if (cond)
		goto loc_00004E84;
	a0 = *(s32*)(a0 + 8);
	v0 = (s32)a0 < (s32)-1022;
	cond = (v0 == 0);
	v0 = (s32)a0 < (s32)1024;
	if (cond)
		goto loc_0000500C;
	v0 = -1022;
	t5 = v0 - a0;
	v1 = (s32)t5 < (s32)57;
	if (v1 != 0)
		goto loc_00004F74;
	t2 = 0;
	t3 = 0;

loc_00004EF8:		
	v1 = 0;
	v0 = 255;
	v0 = t2 & v0;
	a0 = 128;
	v1 = t3 & v1;
	if (v0 == a0)
		goto loc_00004F44;
	t2 = t2 + 127;

loc_00004F14:		
	v0 = (u32)t2 < (u32)127;

loc_00004F18:		
	t3 = t3 + v0;
	v0 = 0xFFF0000;

loc_00004F20:		
	v0 = v0 | 0xFFFF;
	v0 = (u32)v0 < (u32)t3;
	v1 = 1;
	t2 = (u32)t2 >> 8;
	a0 = t3 << 24;
	if (v0 != 0)
		t1 = v1;
	t2 = t2 | a0;

loc_00004F3C:		
	t3 = (u32)t3 >> 8;
	goto loc_00004E80;

loc_00004F44:		
	if (v1 != 0)
	{
		t2 = t2 + 127;
		goto loc_00004F14;
	}
	v1 = 0;
	v0 = 256;
	v0 = t2 & v0;
	v1 = t3 & v1;
	v0 = v0 | v1;

loc_00004F64:		
	if (v0 == 0)
	{
		v0 = 0xFFF0000;
		goto loc_00004F20;
	}
	t2 = t2 + 128;
	v0 = (u32)t2 < (u32)128;
	goto loc_00004F18;

loc_00004F74:		
	a1 = 0;
	a0 = 1;
	a2 = t5 << 26;
	if ((s32)a2 >= 0)
		goto loc_00004F94;
	v1 = a0 << t5;
	v0 = 0;
	if (asm("b          loc_00004FAC"))
		goto ;

loc_00004F94:		
	v1 = a1 << t5;
	if (a2 == 0)
		goto loc_00004FA8;
	asm("negu       $a2, $t5");
	a2 = (u32)a0 >> a2;
	v1 = v1 | a2;

loc_00004FA8:		
	v0 = a0 << t5;

loc_00004FAC:		
	v0 = v0 - 1;

loc_00004FB0:		
	a3 = (u32)v0 < (u32)-1;
	v1 = v1 - 1;
	v1 = v1 + a3;
	v0 = t2 & v0;
	v1 = t3 & v1;
	v0 = v0 | v1;
	t0 = t5 << 26;
	if ((s32)t0 >= 0)
		goto loc_00004FE0;
	a2 = (u32)t3 >> t5;
	a3 = 0;
	if (asm("b          loc_00004FF8"))
		goto ;

loc_00004FE0:		
	a2 = (u32)t2 >> t5;
	if (t0 == 0)
		goto loc_00004FF4;
	asm("negu       $t0, $t5");
	t0 = t3 << t0;
	a2 = a2 | t0;

loc_00004FF4:		
	a3 = (u32)t3 >> t5;

loc_00004FF8:		
	v0 = (u32)0 < (u32)v0;

loc_00004FFC:		
	a1 = 0;
	t2 = a2 | v0;

loc_00005004:		
	t3 = a3 | a1;
	goto loc_00004EF8;

loc_0000500C:		
	t1 = 2047;
	if (v0 != 0)
		goto loc_00005024;

loc_00005014:		
	t2 = 0;
	t3 = 0;
	v0 = *(s32*)(sp + 4);
	goto loc_00004E84;

loc_00005024:		
	v1 = 0;
	v0 = 255;
	a2 = t2 & v0;
	v0 = 128;
	a3 = t3 & v1;
	t1 = a0 + 1023;
	if (a2 == v0)
		goto loc_00005084;
	t2 = t2 + 127;

loc_00005044:		
	v0 = (u32)t2 < (u32)127;

loc_00005048:		
	t3 = t3 + v0;
	v0 = 0x1FFF0000;

loc_00005050:		
	v0 = v0 | 0xFFFF;
	v0 = (u32)v0 < (u32)t3;
	if (v0 == 0)
	{
		t2 = (u32)t2 >> 8;
		goto loc_00005078;
	}
	v0 = t3 << 31;
	t2 = (u32)t2 >> 1;
	t2 = t2 | v0;
	t3 = (u32)t3 >> 1;
	t1 = t1 + 1;
	t2 = (u32)t2 >> 8;

loc_00005078:		
	v0 = t3 << 24;
	t2 = t2 | v0;
	goto loc_00004F3C;

loc_00005084:		
	if (a3 != 0)
	{
		t2 = t2 + 127;
		goto loc_00005044;
	}
	v1 = 0;
	v0 = 256;
	v0 = t2 & v0;
	v1 = t3 & v1;
	v0 = v0 | v1;
	if (v0 == 0)
	{
		v0 = 0x1FFF0000;
		goto loc_00005050;
	}
	t2 = t2 + 128;
	v0 = (u32)t2 < (u32)128;
	goto loc_00005048;
}

sub_000050B4(...) // at 0x000050B4 
{
	v0 = *(s32*)(a0 + 4);
	t0 = *(s32*)(a0 + 0);
	t2 = a1;
	v1 = (u32)v0 >> 31;
	t1 = v0;
	NONE;
	*(s32*)(a1 + 4) = v1;
	NONE;
	if (a3 != 0)
		goto loc_00005154;
	v0 = t0 | t1;
	cond = (v0 != 0);
	v0 = (u32)t0 >> 24;
	if (cond)
		goto loc_000050F0;
	v0 = 2;

loc_000050E8:		
	*(s32*)(t2 + 0) = v0;
	return (v0);

loc_000050F0:		
	a0 = 0xFFF0000;
	t1 = t1 << 8;
	t1 = t1 | v0;
	a0 = a0 | 0xFFFF;
	v0 = -1022;
	v1 = 3;
	a0 = (u32)a0 < (u32)t1;
	t0 = t0 << 8;
	*(s32*)(a1 + 8) = v0;
	*(s32*)(a1 + 0) = v1;
	if (a0 != 0)
		goto loc_00005148;
	a1 = 0xFFF0000;
	a1 = a1 | 0xFFFF;
	a0 = -1022;

loc_00005128:		
	v1 = (u32)t0 >> 31;
	t1 = t1 << 1;
	t1 = t1 | v1;
	v0 = (u32)a1 < (u32)t1;
	t0 = t0 << 1;
	a0 = a0 - 1;
	if (v0 == 0)
		goto loc_00005128;
	*(s32*)(t2 + 8) = a0;

loc_00005148:		
	*(s32*)(t2 + 16) = t0;
	*(s32*)(t2 + 20) = t1;
	return (v0);

loc_00005154:		
	v0 = 2047;
	a2 = (u32)t0 >> 24;
	if (a3 == v0)
		goto loc_00005194;
	v1 = t1 << 8;
	v1 = v1 | a2;
	a0 = 0;
	a1 = 0x10000000;
	v0 = t0 << 8;
	v0 = v0 | a0;
	v1 = v1 | a1;
	a2 = a3 - 1023;
	*(s32*)(t2 + 16) = v0;
	*(s32*)(t2 + 20) = v1;
	v0 = 3;
	*(s32*)(t2 + 8) = a2;
	goto loc_000050E8;

loc_00005194:		
	v0 = t0 | t1;
	cond = (v0 == 0);
	v0 = 4;
	if (cond)
		goto loc_000050E8;
	v0 = 0;
	v1 = 0x80000;
	v0 = t0 & v0;
	v1 = t1 & v1;
	v0 = v0 | v1;
	if (v0 == 0)
	{
		*(s32*)(a1 + 0) = 0;
		goto loc_00005148;
	}
	v0 = 1;
	*(s32*)(a1 + 0) = v0;
	goto loc_00005148;
}

sub_000051C8(...) // at 0x000051C8 
{
	v1 = *(s32*)(a0 + 0);
	v0 = (u32)v1 < (u32)2;
	a3 = a0;
	if (v0 != 0)
		goto loc_000051E8;
	a2 = *(s32*)(a1 + 0);
	v0 = (u32)a2 < (u32)2;
	if (v0 == 0)
	{
		v0 = v1 ^ 0x4;
		goto loc_000051F4;
	}

loc_000051E8:		
	a0 = 1;

loc_000051EC:		
	v0 = a0;
	return (v0);

loc_000051F4:		
	cond = (v0 != 0);
	v0 = v1 ^ 0x4;
	if (cond)
		goto loc_00005218;
	v0 = a2 ^ 0x4;
	if (v0 != 0)
	{
		v0 = v1 ^ 0x4;
		goto loc_00005218;
	}
	v1 = *(s32*)(a1 + 4);
	v0 = *(s32*)(a0 + 4);
	a0 = v1 - v0;
	goto loc_000051EC;

loc_00005218:		
	if (v0 == 0)
	{
		v1 = *(s32*)(a3 + 4);
		goto loc_0000526C;
	}
	v0 = a2 ^ 0x4;
	if (v0 == 0)
	{
		v1 = *(s32*)(a1 + 4);
		goto loc_00005250;
	}
	v0 = v1 ^ 0x2;
	cond = (v0 != 0);
	v0 = a2 ^ 0x2;
	if (cond)
		goto loc_00005260;
	a0 = 0;
	if (v0 == 0)
		goto loc_000051EC;
	v0 = v1 ^ 0x2;

loc_00005244:		
	if (v0 != 0)
	{
		v0 = a2 ^ 0x2;
		goto loc_00005260;
	}
	v1 = *(s32*)(a1 + 4);

loc_00005250:		
	a0 = 1;
	v0 = -1;

loc_00005258:		
	if (v1 == 0)
		a0 = v0;
	goto loc_000051EC;

loc_00005260:		
	if (v0 != 0)
	{
		a2 = *(s32*)(a3 + 4);
		goto loc_00005278;
	}
	v1 = *(s32*)(a3 + 4);

loc_0000526C:		
	a0 = -1;
	v0 = 1;
	goto loc_00005258;

loc_00005278:		
	v1 = *(s32*)(a1 + 4);
	a0 = -1;
	v0 = 1;
	if (a2 == 0)
		a0 = v0;
	if (a2 != v1)
		goto loc_000051EC;
	t1 = *(s32*)(a3 + 8);
	t0 = *(s32*)(a1 + 8);
	a0 = -1;
	v1 = (s32)t0 < (s32)t1;
	if (a2 == 0)
		a0 = v0;
	if (v1 != 0)
		goto loc_000051EC;
	a0 = 1;
	v0 = -1;
	v1 = (s32)t1 < (s32)t0;
	if (a2 == 0)
		a0 = v0;
	if (v1 != 0)
		goto loc_000051EC;
	t0 = *(s32*)(a3 + 20);
	a0 = *(s32*)(a1 + 20);
	v0 = (u32)a0 < (u32)t0;
	if (v0 != 0)
	{
		a0 = -1;
		goto loc_00005324;
	}
	if (t0 == a0)
	{
		v1 = *(s32*)(a3 + 16);
		goto loc_00005310;
	}
	v0 = (u32)t0 < (u32)a0;

loc_000052D8:		
	if (v0 != 0)
	{
		a0 = 1;
		goto loc_00005304;
	}
	if (a0 == t0)
	{
		v1 = *(s32*)(a1 + 16);
		goto loc_000052F0;
	}
	a0 = 0;
	goto loc_000051EC;

loc_000052F0:		
	v0 = *(s32*)(a3 + 16);
	v0 = (u32)v0 < (u32)v1;
	if (v0 == 0)
	{
		a0 = 0;
		goto loc_000051EC;
	}
	a0 = 1;

loc_00005304:		
	v0 = -1;

loc_00005308:		
	if (a2 == 0)
		a0 = v0;
	goto loc_000051EC;

loc_00005310:		
	v0 = *(s32*)(a1 + 16);
	v0 = (u32)v0 < (u32)v1;
	if (v0 == 0)
	{
		v0 = (u32)t0 < (u32)a0;
		goto loc_000052D8;
	}
	a0 = -1;

loc_00005324:		
	v0 = 1;
	goto loc_00005308;
}

sub_0000532C(...) // at 0x0000532C 
{
	sp = sp - 112;
	v0 = a0;
	v1 = a1;
	*(s32*)(sp + 96) = s0;
	a0 = sp + 64;
	a1 = sp;
	*(s32*)(sp + 64) = v0;
	*(s32*)(sp + 68) = v1;
	*(s32*)(sp + 100) = ra;
	*(s32*)(sp + 80) = a2;
	*(s32*)(sp + 84) = a3;
	s0 = sp + 32;
	v0 = sub_000050B4(...);
	a0 = sp + 80;
	a1 = s0;
	v0 = sub_000050B4(...);
	v0 = *(s32*)(sp + 0);
	v0 = (u32)v0 < (u32)2;
	v1 = 1;
	if (v0 != 0)
		goto loc_00005390;
	v0 = *(s32*)(sp + 32);
	a1 = s0;
	v0 = (u32)v0 < (u32)2;
	a0 = sp;
	if (v0 == 0)
		goto loc_000053A4;

loc_00005390:		
	ra = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	v0 = v1;
	sp = sp + 112;
	return (v0);

loc_000053A4:		
	v0 = sub_000051C8(...);
	v1 = v0;
	goto loc_00005390;
}

sub_000053B4(...) // at 0x000053B4 
{
	sp = sp - 64;
	v0 = a0;
	v1 = a1;
	a0 = sp + 32;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 32) = v0;
	*(s32*)(sp + 36) = v1;
	a1 = sp;
	v0 = sub_000050B4(...);
	a0 = sp;
	v0 = *(s32*)(sp + 4);
	v0 = (u32)v0 < (u32)1;
	*(s32*)(sp + 4) = v0;
	v0 = sub_00004E4C(...);
	ra = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

sub_000053F8(...) // at 0x000053F8 
{
	v0 = (s32)a1 < (s32)a3;
	t0 = (s32)a3 < (s32)a1;
	v1 = 0;
	if (v0 != 0)
		goto loc_0000542C;
	v0 = (u32)a0 < (u32)a2;
	v1 = 2;
	if (t0 != 0)
		goto loc_0000542C;
	a0 = (u32)a2 < (u32)a0;
	v1 = 0;
	if (v0 != 0)
		goto loc_0000542C;
	v1 = 2;
	v0 = 1;
	if (a0 == 0)
		v1 = v0;

loc_0000542C:		
	v0 = v1;
	return (v0);
}

sub_00005434(...) // at 0x00005434 
{
	sp = sp - 32;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = (s32)a1 >> 0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = s3;
	v0 = sub_00004A38(...);
	a0 = v0;
	s0 = 0x70000;
	s0 = *(s32*)(s0 - 16648);
	s1 = 0x70000;
	s1 = *(s32*)(s1 - 16644);
	a1 = v1;
	a2 = s0;
	a3 = s1;
	v0 = sub_00004414(...);
	a1 = v1;
	a0 = v0;
	a2 = s0;
	a3 = s1;
	v0 = sub_00004414(...);
	a0 = s2;
	s4 = v0;
	s5 = v1;
	v0 = sub_00004A38(...);
	a0 = v0;
	a1 = v1;
	if ((s32)s2 < 0)
		goto loc_000054EC;
	a0 = s4;

loc_000054B8:		
	a1 = s5;
	a2 = v0;
	a3 = v1;
	v0 = sub_00004338(...);
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000054EC:		
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16640);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16636);
	v0 = sub_00004338(...);
	a0 = s4;
	goto loc_000054B8;
}

sub_00005508(...) // at 0x00005508 
{
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16632);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16628);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = sub_000049B0(...);
	a0 = s0;
	a1 = s1;
	if ((s32)v0 < 0)
		goto loc_0000557C;
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16624);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16620);
	v0 = sub_00004338(...);
	a1 = v1;
	a0 = v0;
	v0 = sub_000056BC(...);
	v1 = 0x80000000;
	v0 = v0 + v1;
	ra = *(s32*)(sp + 8);

loc_0000556C:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000557C:		
	a1 = s1;
	v0 = sub_000056BC(...);
	ra = *(s32*)(sp + 8);
	goto loc_0000556C;
}

sub_0000558C(...) // at 0x0000558C 
{
	v1 = *(s32*)(a0 + 0);
	a2 = 0;
	a1 = *(s32*)(a0 + 12);
	v0 = (u32)v1 < (u32)2;
	t0 = *(s32*)(a0 + 4);
	a3 = 0;
	if (v0 == 0)
		goto loc_000055CC;
	v0 = 0x100000;
	a1 = a1 | v0;
	a3 = 255;

loc_000055B4:		
	NONE;

loc_000055B8:		
	NONE;
	NONE;
	asm("mtc1       $a2, $fcr0");
	return (v0);

loc_000055CC:		
	v0 = v1 ^ 0x4;
	if (v0 == 0)
	{
		a3 = 255;
		goto loc_0000567C;
	}
	v0 = v1 ^ 0x2;
	if (v0 == 0)
	{
		a1 = 0;
		goto loc_000055B4;
	}
	if (a1 == 0)
	{
		NONE;
		goto loc_000055B8;
	}
	a0 = *(s32*)(a0 + 8);
	v0 = (s32)a0 < (s32)-126;
	cond = (v0 == 0);
	v0 = (s32)a0 < (s32)128;
	if (cond)
		goto loc_00005670;
	v0 = -126;
	a0 = v0 - a0;
	v1 = (s32)a0 < (s32)26;
	v0 = 1;
	if (v1 != 0)
		goto loc_00005654;
	a1 = 0;

loc_00005614:		
	v1 = a1 & 0x7F;
	v0 = 64;
	if (v1 == v0)
	{
		v0 = a1 & 0x80;
		goto loc_00005644;
	}
	a1 = a1 + 63;

loc_00005628:		
	v0 = 0x3FFF0000;

loc_0000562C:		
	v0 = v0 | 0xFFFF;
	v0 = (u32)v0 < (u32)a1;
	v1 = 1;
	if (v0 != 0)
		a3 = v1;

loc_0000563C:		
	a1 = (u32)a1 >> 7;
	goto loc_000055B4;

loc_00005644:		
	if (v0 != 0)
	{
		a1 = a1 + 64;
		goto loc_00005628;
	}
	v0 = 0x3FFF0000;
	goto loc_0000562C;

loc_00005654:		
	v0 = v0 << a0;
	v0 = v0 - 1;
	v0 = a1 & v0;
	v1 = (u32)a1 >> a0;
	v0 = (u32)0 < (u32)v0;
	a1 = v1 | v0;
	goto loc_00005614;

loc_00005670:		
	if (v0 != 0)
	{
		v1 = a1 & 0x7F;
		goto loc_00005684;
	}
	a3 = 255;

loc_0000567C:		
	a1 = 0;
	goto loc_000055B4;

loc_00005684:		
	v0 = 64;
	a3 = a0 + 127;
	if (v1 == v0)
		goto loc_000056A8;
	a1 = a1 + 63;

loc_00005694:		
	if ((s32)a1 >= 0)
	{
		a1 = (u32)a1 >> 7;
		goto loc_000055B4;
	}
	a1 = (u32)a1 >> 1;
	a3 = a3 + 1;
	goto loc_0000563C;

loc_000056A8:		
	v0 = a1 & 0x80;
	if (v0 != 0)
	{
		a1 = a1 + 64;
		goto loc_00005694;
	}
	goto loc_00005694;
}

sub_000056BC(...) // at 0x000056BC 
{
	sp = sp - 64;
	v0 = a0;
	v1 = a1;
	a0 = sp + 32;
	*(s32*)(sp + 32) = v0;
	*(s32*)(sp + 36) = v1;
	*(s32*)(sp + 48) = ra;
	a1 = sp;
	v0 = sub_000050B4(...);
	a1 = 0;
	v1 = *(s32*)(sp + 0);
	v0 = v1 ^ 0x2;
	a0 = (u32)v1 < (u32)2;
	if (v0 == 0)
		goto loc_00005730;
	v0 = v1 ^ 0x4;
	if (a0 != 0)
		goto loc_00005730;
	v1 = 0x7FFF0000;
	a1 = 0x80000000;
	if (v0 == 0)
		goto loc_00005724;
	v0 = *(s32*)(sp + 8);
	a1 = 0;

loc_00005710:		
	a0 = (s32)v0 < (s32)31;
	if ((s32)v0 < 0)
		goto loc_00005730;
	v1 = 0x7FFF0000;
	a1 = 0x80000000;
	if (a0 != 0)
		goto loc_00005740;

loc_00005724:		
	v0 = *(s32*)(sp + 4);
	v1 = v1 | 0xFFFF;
	if (v0 == 0)
		a1 = v1;

loc_00005730:		
	ra = *(s32*)(sp + 48);
	v0 = a1;
	sp = sp + 64;
	return (v0);

loc_00005740:		
	a0 = 60;
	a0 = a0 - v0;
	v0 = *(s32*)(sp + 16);
	v1 = *(s32*)(sp + 20);
	t0 = a0 << 26;
	if ((s32)t0 >= 0)
		goto loc_00005768;
	a2 = (u32)v1 >> a0;
	a3 = 0;
	if (asm("b          loc_00005780"))
		goto ;

loc_00005768:		
	a2 = (u32)v0 >> a0;
	if (t0 == 0)
		goto loc_0000577C;
	asm("negu       $t0, $a0");
	t0 = v1 << t0;
	a2 = a2 | t0;

loc_0000577C:		
	a3 = (u32)v1 >> a0;

loc_00005780:		
	v0 = *(s32*)(sp + 4);
	asm("negu       $a1, $a2");
	if (v0 == 0)
		a1 = a2;
	goto loc_00005730;
}

module_start(...) // at 0x00005790 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00000000(...);
	v0 = 0;
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

module_stop(...) // at 0x000057B0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0001ABD8(...);
	v0 = 0;
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_F7AAC8FE(...) // at 0x000057D0 
{
	a1 = a0;
	a0 = 0x00000;
	sp = sp - 16;
	a0 = a0 + 4200;
	*(s32*)(sp + 0) = ra;
	a2 = 28;
	v0 = Kernel_Library_1839852A(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_A80C7961(...) // at 0x000057F8 
{
	v0 = 0x00000;
	v0 = v0 + 4200;
	return (v0);
}

sub_00005804(...) // at 0x00005804 
{
	a1 = a1 ^ 0xFFFF;
	a0 = a0 ^ 0x1;
	a1 = (u32)a1 < (u32)1;
	a0 = (u32)a0 < (u32)1;
	v1 = 0x00000;
	a1 = a1 & a0;
	v0 = v1 + 4200;
	if (a1 == 0)
		goto loc_00005840;
	*(s32*)(v1 + 4200) = 0;
	*(s32*)(v0 + 24) = 0;
	*(s32*)(v0 + 4) = 0;
	*(s32*)(v0 + 8) = 0;
	*(s32*)(v0 + 12) = 0;
	*(s32*)(v0 + 16) = 0;
	*(s32*)(v0 + 20) = 0;

loc_00005840:		
	return (v0);
}

sub_00005848(...) // at 0x00005848 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a1 = a1 ^ 0xFFFF;
	v0 = s1 ^ 0x1;
	*(s32*)(sp + 0) = s0;
	v0 = (u32)v0 < (u32)1;
	s0 = (u32)a1 < (u32)1;
	a0 = 0x00000;
	v0 = s0 & v0;
	*(s32*)(sp + 8) = ra;
	a0 = a0 + 4232;
	if (v0 != 0)
		goto loc_000058E4;

loc_0000587C:		
	v0 = (u32)s1 < (u32)1;
	v1 = 0x00000;
	s0 = s0 & v0;
	a0 = v1 + 4328;
	if (s0 != 0)
		goto loc_000058A4;

loc_00005890:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000058A4:		
	v0 = 0x70000;
	v0 = v0 - 16496;
	s1 = 0x00000;
	*(s32*)(v1 + 4328) = v0;
	v0 = sub_00006C9C(...);
	a0 = s1 + 4232;
	a0 = a0 + 4;
	if (s0 == 0)
		goto loc_00005890;
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(s1 + 4232) = v0;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s1 + 4232) = v1;
	goto loc_00005890;

loc_000058E4:		
	v0 = sub_00019ADC(...);
	v0 = 0x70000;
	a1 = 0x00000;
	v0 = v0 - 16496;
	v1 = 0x00000;
	a0 = a1 + 4332;
	*(s32*)(v1 + 4328) = v0;
	v0 = 11;
	v1 = 6;
	*(s32*)(a1 + 4332) = 0;
	*(s32*)(a0 + 4) = v0;
	*(s32*)(a0 + 8) = v1;
	*(s32*)(a0 + 16) = 0;
	*(s32*)(a0 + 12) = 0;
	goto loc_0000587C;
}

sub_00005924(...) // at 0x00005924 
{
	sp = sp - 16;
	v0 = a0 ^ 0x1;
	a1 = a1 ^ 0xFFFF;
	*(s32*)(sp + 0) = s0;
	v0 = (u32)v0 < (u32)1;
	s0 = (u32)a1 < (u32)1;
	*(s32*)(sp + 8) = s2;
	v0 = s0 & v0;
	s2 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a0 = s2 + 4632;
	*(s32*)(sp + 12) = ra;
	if (v0 != 0)
		goto loc_000059A8;
	v0 = (u32)s1 < (u32)1;

loc_00005960:		
	a0 = s2 + 4632;
	v0 = s0 & v0;
	a0 = a0 + 4;
	if (v0 != 0)
		goto loc_00005988;

loc_00005970:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00005988:		
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(s2 + 4632) = v0;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s2 + 4632) = v1;
	goto loc_00005970;

loc_000059A8:		
	v0 = sub_00019ADC(...);
	v0 = (u32)s1 < (u32)1;
	goto loc_00005960;
}

sub_000059B8(...) // at 0x000059B8 
{
	v0 = a0 ^ 0x1;
	a1 = a1 ^ 0xFFFF;
	a1 = (u32)a1 < (u32)1;
	v0 = (u32)v0 < (u32)1;
	sp = sp - 16;
	a0 = 0x00000;
	a1 = a1 & v0;
	*(s32*)(sp + 0) = ra;
	a0 = a0 + 5736;
	if (a1 != 0)
		goto loc_000059EC;
	ra = *(s32*)(sp + 0);

loc_000059E4:		
	sp = sp + 16;
	return (v0);

loc_000059EC:		
	v0 = sub_0000FA34(...);
	ra = *(s32*)(sp + 0);
	goto loc_000059E4;
}

sub_000059FC(...) // at 0x000059FC 
{
	sp = sp - 16;
	v0 = a0 ^ 0x1;
	a1 = a1 ^ 0xFFFF;
	*(s32*)(sp + 0) = s0;
	v0 = (u32)v0 < (u32)1;
	s0 = (u32)a1 < (u32)1;
	*(s32*)(sp + 8) = s2;
	v0 = s0 & v0;
	s2 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a0 = s2 + 4268;
	*(s32*)(sp + 12) = ra;
	if (v0 != 0)
		goto loc_00005A80;
	v0 = (u32)s1 < (u32)1;

loc_00005A38:		
	a0 = s2 + 4268;
	v0 = s0 & v0;
	a0 = a0 + 4;
	if (v0 != 0)
		goto loc_00005A60;

loc_00005A48:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00005A60:		
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(s2 + 4268) = v0;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s2 + 4268) = v1;
	goto loc_00005A48;

loc_00005A80:		
	v0 = sub_00019ADC(...);
	v0 = (u32)s1 < (u32)1;
	goto loc_00005A38;
	sp = sp - 16;
	a0 = 1;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_00005804(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_A3A7D7B1(...) // at 0x00005AB0 
{
	a0 = 0x20000;
	sp = sp - 16;
	a0 = a0 - 15304;
	a1 = 256;
	a2 = 1;
	a3 = 1;
	*(s32*)(sp + 0) = ra;
	t0 = 0;
	v0 = sceKernelCreateSema(...);
	v1 = 0x00000;
	ra = *(s32*)(sp + 0);
	*(s32*)(v1 + 4228) = v0;
	sp = sp + 16;
	return (v0);
}

onesegCore_80FD653C(...) // at 0x00005AE8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	v0 = *(s32*)(s0 + 4228);
	*(s32*)(sp + 4) = ra;
	a0 = v0;
	if ((s32)v0 <= 0)
		goto loc_00005B14;
	v0 = sceKernelDeleteSema(...);
	*(s32*)(s0 + 4228) = 0;
	v0 = 0;

loc_00005B14:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_41DAD1AE(...) // at 0x00005B24 
{
	v0 = 0x00000;
	*(s8*)(v0 + 1552) = a0;
	return (v0);
}

sub_00005B30(...) // at 0x00005B30 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a2 = a1;
	a1 = *(s32*)(v0 + 200);
	v0 = sub_00005B54(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00005B54(...) // at 0x00005B54 
{
	t0 = a0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = a1;
	a3 = a2;
	v0 = t0;
	if ((s32)t0 < 0)
		goto loc_00005B7C;

loc_00005B70:		
	ra = *(s32*)(sp + 0);

loc_00005B74:		
	sp = sp + 16;
	return (v0);

loc_00005B7C:		
	v0 = 0x00000;
	a1 = *(s32*)(v0 + 204);
	v0 = 0x80100000;
	if (a2 == a1)
		goto loc_00005BB8;
	v0 = *(s32*)(a2 + 0);
	*(s32*)(a1 + 0) = v0;
	v1 = *(s32*)(a2 + 4);
	*(s32*)(a1 + 4) = v1;
	v0 = *(s32*)(a2 + 8);
	*(s32*)(a1 + 8) = v0;
	v1 = *(s32*)(a2 + 12);
	*(s32*)(a1 + 12) = v1;
	v0 = *(s32*)(a2 + 16);
	*(s32*)(a1 + 16) = v0;
	v0 = 0x80100000;

loc_00005BB8:		
	v0 = v0 | 0x9002;
	v0 = (s32)v0 < (s32)t0;
	cond = (v0 != 0);
	v0 = 0x80100000;
	if (cond)
		goto loc_00005C6C;
	v0 = v0 | 0x9001;
	v0 = (s32)t0 < (s32)v0;
	cond = (v0 == 0);
	v0 = 0x80010000;
	if (cond)
		goto loc_00005C54;
	v0 = v0 | 0xD;
	cond = (t0 == v0);
	v0 = 0x80010000;
	if (cond)
		goto loc_00005C38;
	v0 = 0x80020000;
	v0 = v0 | 0x321;
	cond = (t0 == v0);
	v0 = 0x80020000;
	if (cond)
		goto loc_00005C1C;

loc_00005BF4:		
	v0 = t0;
	if (a0 == 0)
		goto loc_00005B70;
	v1 = *(s32*)(a0 + 0);
	a1 = t0;
	a2 = a3;
	v0 = *(s32*)(v1 + 20);

loc_00005C0C:		
	v0 = $v0(...);
	ra = *(s32*)(sp + 0);
	goto loc_00005B74;

loc_00005C1C:		
	v0 = v0 | 0x321;
	if (a0 == 0)
		goto loc_00005B70;
	v1 = *(s32*)(a0 + 0);
	a1 = 0x80020000;
	a1 = a1 | 0x321;
	v0 = *(s32*)(v1 + 8);
	goto loc_00005C0C;

loc_00005C38:		
	v0 = v0 | 0xD;
	if (a0 == 0)
		goto loc_00005B70;
	v1 = *(s32*)(a0 + 0);
	a1 = 0x80010000;
	a1 = a1 | 0xD;
	v0 = *(s32*)(v1 + 0);
	goto loc_00005C0C;

loc_00005C54:		
	v0 = t0;
	if (a0 == 0)
		goto loc_00005B70;
	v1 = *(s32*)(a0 + 0);
	a1 = t0;
	v0 = *(s32*)(v1 + 12);
	goto loc_00005C0C;

loc_00005C6C:		
	v0 = v0 | 0x9802;
	cond = (t0 != v0);
	v0 = 0x80100000;
	if (cond)
		goto loc_00005BF4;
	v0 = v0 | 0x9802;
	if (a0 == 0)
		goto loc_00005B70;
	v1 = *(s32*)(a0 + 0);
	a1 = 0x80100000;
	a1 = a1 | 0x9802;
	v0 = *(s32*)(v1 + 4);
	a2 = 1;
	v0 = $v0(...);
	ra = *(s32*)(sp + 0);
	goto loc_00005B74;
}

onesegCore_92167AFC(...) // at 0x00005CA0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	if (a0 == 0)
		goto loc_00005CC8;
	v0 = sub_000061A4(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);

loc_00005CC8:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00005CD8(...) // at 0x00005CD8 
{
	sp = sp - 96;
	*(s32*)(sp + 84) = ra;
	v0 = 0x20000;
	*(s32*)(sp + 80) = fp;
	*(s32*)(sp + 76) = s7;
	*(s32*)(sp + 72) = s6;
	*(s32*)(sp + 68) = s5;
	*(s32*)(sp + 64) = s4;
	*(s32*)(sp + 60) = s3;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;
	*(s32*)(sp + 48) = s0;
	s0 = *(s32*)(v0 - 11228);
	a0 = s0;
	v0 = scePaf_D7DCB972(...);
	s1 = v0;
	v0 = 0x20000;
	s6 = *(s32*)(v0 - 11224);
	a0 = s6;
	v0 = scePaf_D7DCB972(...);
	s3 = v0;
	v0 = 0x20000;
	v0 = *(s32*)(v0 - 11212);
	a0 = v0;
	*(s32*)(sp + 4) = v0;
	v0 = scePaf_D7DCB972(...);
	*(s32*)(sp + 0) = v0;
	v0 = 0x20000;
	v0 = *(s32*)(v0 - 11208);
	a0 = v0;
	*(s32*)(sp + 12) = v0;
	v0 = scePaf_D7DCB972(...);
	*(s32*)(sp + 8) = v0;
	v0 = 0x20000;
	v0 = *(s32*)(v0 - 11220);
	a0 = v0;
	*(s32*)(sp + 20) = v0;
	v0 = scePaf_D7DCB972(...);
	*(s32*)(sp + 16) = v0;
	v0 = 0x20000;
	v0 = *(s32*)(v0 - 11204);
	a0 = v0;
	*(s32*)(sp + 28) = v0;
	v0 = scePaf_D7DCB972(...);
	*(s32*)(sp + 24) = v0;
	v0 = 0x20000;
	v0 = *(s32*)(v0 - 11200);
	a0 = v0;
	*(s32*)(sp + 36) = v0;
	v0 = scePaf_D7DCB972(...);
	*(s32*)(sp + 32) = v0;
	v0 = 0x20000;
	s7 = *(s32*)(v0 - 11196);
	a0 = s7;
	v0 = scePaf_D7DCB972(...);
	s4 = v0;
	v0 = 0x20000;
	fp = *(s32*)(v0 - 11192);
	a0 = fp;
	v0 = scePaf_D7DCB972(...);
	a0 = s2;
	a1 = s0;
	a2 = s1;
	s5 = v0;
	v0 = scePaf_E0B32AE8(...);
	a1 = s6;
	if (v0 != 0)
		goto loc_00005E24;
	v0 = 0x00000;

loc_00005DEC:		
	v1 = *(s32*)(v0 + 4304);

loc_00005DF0:		
	ra = *(s32*)(sp + 84);

loc_00005DF4:		
	fp = *(s32*)(sp + 80);
	s7 = *(s32*)(sp + 76);
	s6 = *(s32*)(sp + 72);
	s5 = *(s32*)(sp + 68);
	s4 = *(s32*)(sp + 64);
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v0 = v1;
	sp = sp + 96;
	return (v0);

loc_00005E24:		
	a2 = s3;
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	cond = (v0 == 0);
	v0 = 0x00000;
	if (cond)
		goto loc_00005DEC;
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(sp + 0);
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	cond = (v0 == 0);
	v0 = 0x00000;
	if (cond)
		goto loc_00005DEC;
	a1 = *(s32*)(sp + 12);
	a2 = *(s32*)(sp + 8);
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	cond = (v0 == 0);
	v0 = 0x00000;
	if (cond)
		goto loc_00005DEC;
	a1 = *(s32*)(sp + 20);
	a2 = *(s32*)(sp + 16);
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	cond = (v0 == 0);
	v0 = 0x00000;
	if (cond)
		goto loc_00005DEC;
	a1 = s7;
	a2 = s4;
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	a1 = fp;
	if (v0 != 0)
		goto loc_00005EA4;
	v0 = 0x00000;

loc_00005E9C:		
	v1 = *(s32*)(v0 + 4320);
	goto loc_00005DF0;

loc_00005EA4:		
	a2 = s5;

loc_00005EA8:		
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	cond = (v0 == 0);
	v0 = 0x00000;
	if (cond)
		goto loc_00005E9C;
	a1 = *(s32*)(sp + 28);
	a2 = *(s32*)(sp + 24);
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	a1 = *(s32*)(sp + 36);
	if (v0 != 0)
		goto loc_00005EDC;

loc_00005ED0:		
	v0 = 0x00000;
	v1 = *(s32*)(v0 + 4316);
	goto loc_00005DF0;

loc_00005EDC:		
	a2 = *(s32*)(sp + 32);
	a0 = s2;
	v0 = scePaf_E0B32AE8(...);
	v1 = 0;
	if (v0 == 0)
		goto loc_00005ED0;
	ra = *(s32*)(sp + 84);
	goto loc_00005DF4;
}

sub_00005EF8(...) // at 0x00005EF8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0;
	if (a0 == 0)
		goto loc_00005F10;
	a0 = *(s32*)(a0 + 0);
	v0 = sub_00005CD8(...);

loc_00005F10:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_D71F10C7(...) // at 0x00005F1C 
{
	sp = sp - 32;
	v0 = (s32)a1 < (s32)6;
	*(s32*)(sp + 12) = s3;
	a3 = a2 & 0xFF;
	s3 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 8) = s2;
	if (v0 == 0)
		goto loc_00005F7C;
	v1 = 0x00000;
	v0 = s1 << 2;
	v1 = v1 + 4304;
	a2 = 1;
	a0 = 0;
	a1 = 16;
	s2 = v0 + v1;
	if (a3 == a2)
		goto loc_00005FEC;
	v0 = *(s32*)(s2 + 0);
	if (v0 == 0)
		goto loc_00005F9C;

loc_00005F78:		
	s0 = v0;

loc_00005F7C:		
	v0 = s0;

loc_00005F80:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00005F9C:		
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	v0 = 0x00000;
	t2 = s1 << 4;
	v0 = v0 + 104;
	v0 = t2 + v0;
	a3 = *(u16*)(v0 + 4);
	t1 = *(s32*)(v0 + 12);
	a2 = *(s32*)(v0 + 0);
	t0 = *(s32*)(v0 + 8);
	v1 = 0x70000;
	v1 = v1 - 17208;
	t2 = t2 + v1;
	a1 = s3;
	a0 = s0;
	v0 = sub_00006038(...);
	*(s32*)(s2 + 0) = s0;
	v0 = s0;
	goto loc_00005F78;

loc_00005FEC:		
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	v0 = 0x00000;

loc_00005FFC:		
	t2 = s1 << 4;
	v0 = v0 + 104;
	v0 = t2 + v0;
	a3 = *(u16*)(v0 + 4);
	t1 = *(s32*)(v0 + 12);
	a2 = *(s32*)(v0 + 0);
	t0 = *(s32*)(v0 + 8);
	v1 = 0x70000;
	v1 = v1 - 17208;
	t2 = t2 + v1;
	a1 = s3;
	a0 = s0;
	v0 = sub_00006038(...);
	v0 = s0;
	goto loc_00005F80;
}

sub_00006038(...) // at 0x00006038 
{
	sp = sp - 64;
	*(s32*)(sp + 52) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 48) = fp;
	fp = t1;
	*(s32*)(sp + 44) = s7;
	s7 = t2;
	*(s32*)(sp + 40) = s6;
	s6 = t0;
	*(s32*)(sp + 36) = s5;
	s5 = a2;
	*(s32*)(sp + 32) = s4;
	s4 = a1;
	*(s32*)(sp + 28) = s3;
	s3 = a3;
	s3 = s3 & 0xFFFF;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = s5 << 1;
	s0 = s0 + s5;
	v1 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	s0 = s0 << 4;
	a3 = *(s32*)(v1 + 8);
	s0 = s0 + 64;
	v0 = $a3(...);
	a0 = s4;
	v0 = scePaf_D7DCB972(...);
	v0 = v0 + 1;
	a1 = v0;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	*(s32*)(s1 + 12) = v0;
	a1 = s4;
	a0 = v0;
	v0 = scePaf_726DFBA9(...);
	asm("mult       $s3, $s6");
	v0 = s3 << 1;

loc_000060E0:		
	s0 = s0 + v0;
	a0 = 0;
	asm("mflo       $v1");
	s0 = s0 + v1;
	a1 = s0;
	v0 = onesegSal_265926E7(...);
	*(s32*)(s1 + 8) = v0;
	a0 = 0;
	a1 = 48;
	v0 = onesegSal_265926E7(...);
	a2 = *(s32*)(s1 + 8);
	s2 = v0;
	a3 = s0;
	t0 = s7;
	a0 = v0;
	a1 = s4;
	t1 = 0;
	v0 = sub_00012E04(...);
	*(s32*)(s1 + 0) = s2;
	a1 = 28;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	t2 = *(s32*)(s1 + 0);
	a1 = *(s32*)(s1 + 8);
	a2 = s5;
	a3 = s3;
	t0 = s6;
	t1 = fp;
	a0 = v0;
	s0 = v0;
	v0 = sub_0001135C(...);
	a1 = *(s32*)(sp + 0);
	*(s32*)(s1 + 4) = s0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 12);
	a0 = a1;
	v0 = $v1(...);
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 64;
	return (v0);
}

sub_000061A4(...) // at 0x000061A4 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	a1 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a1 + 8);
	a0 = v0;
	v0 = $v1(...);
	s1 = *(s32*)(s0 + 4);
	if (s1 != 0)
		goto loc_000062A0;
	s1 = *(s32*)(s0 + 0);

loc_000061E4:		
	if (s1 != 0)
		goto loc_00006284;
	a1 = *(s32*)(s0 + 8);

loc_000061F0:		
	if (a1 != 0)
		goto loc_00006274;
	a1 = *(s32*)(s0 + 12);

loc_000061FC:		
	if (a1 != 0)
		goto loc_00006264;
	*(s32*)(s0 + 4) = 0;

loc_00006208:		
	v0 = 0x00000;
	a0 = v0 + 4304;
	*(s32*)(s0 + 0) = 0;
	v1 = 5;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;

loc_00006220:		
	v0 = *(s32*)(a0 + 0);
	v1 = v1 - 1;
	if (v0 == s0)
		goto loc_0000625C;

loc_0000622C:		
	a0 = a0 + 4;
	if ((s32)v1 >= 0)
		goto loc_00006220;
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000625C:		
	*(s32*)(a0 + 0) = 0;
	goto loc_0000622C;

loc_00006264:		
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 4) = 0;
	goto loc_00006208;

loc_00006274:		
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	a1 = *(s32*)(s0 + 12);
	goto loc_000061FC;

loc_00006284:		
	a0 = s1;
	v0 = sub_00012F30(...);
	a1 = s1;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	a1 = *(s32*)(s0 + 8);
	goto loc_000061F0;

loc_000062A0:		
	a0 = s1;
	v0 = sub_000114B0(...);
	a1 = s1;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	s1 = *(s32*)(s0 + 0);
	goto loc_000061E4;
}

onesegCore_ACA4EBF2(...) // at 0x000062BC 
{
	sp = sp - 16;
	*(s32*)(sp + 12) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = s2;
	s2 = v0 + 4304;
	*(s32*)(sp + 4) = s1;
	s1 = 5;
	s0 = *(s32*)(s2 + 0);

loc_000062E0:		
	s1 = s1 - 1;
	s2 = s2 + 4;
	a0 = s0;
	if (s0 != 0)
		goto loc_00006310;

loc_000062F0:		
	if ((s32)s1 >= 0)
	{
		s0 = *(s32*)(s2 + 0);
		goto loc_000062E0;
	}
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00006310:		
	v0 = sub_000061A4(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	goto loc_000062F0;
}

onesegCore_329E26FE(...) // at 0x0000632C 
{
	sp = sp - 80;
	a1 = 0;
	*(s32*)(sp + 64) = s0;
	s0 = a0;
	*(s32*)(sp + 68) = ra;
	a0 = sp;
	v0 = sceVshCommonUtil_A721B1D1(...);
	a0 = 0x00000;
	v1 = *(s32*)(a0 + 4232);
	a0 = a0 + 4232;
	*(s32*)(sp + 16) = a0;
	v0 = *(s32*)(v1 + 8);
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 4);
	v0 = sub_0001159C(...);
	a0 = v0;

loc_00006370:		
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 32;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006384:		
	v1 = v1 + 4;
	if (v0 == s0)
		goto loc_0000639C;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006384;
	}

loc_0000639C:		
	*(s32*)(a3 + 8) = a2;
	a1 = a3;
	*(s32*)(a3 + 0) = 0;
	*(s32*)(a3 + 4) = 0;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 16);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	a0 = sp;
	v0 = sceVshCommonUtil_3CA4266A(...);
	v0 = s0;
	ra = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	sp = sp + 80;
	return (v0);
}

onesegCore_FAFBAF9E(...) // at 0x000063EC 
{
	sp = sp - 64;
	*(s32*)(sp + 60) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;
	s1 = a2;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	a3 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a3 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s2 + 4);
	a2 = s1;
	a1 = s0;
	v0 = sub_000115BC(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006450:		
	v1 = v1 + 4;
	if (v0 == s2)
		goto loc_00006468;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006450;
	}

loc_00006468:		
	v0 = 1;
	*(s32*)(a3 + 4) = v0;
	a1 = a3;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 0) = 0;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

onesegCore_3D97DF93(...) // at 0x000064BC 
{
	sp = sp - 80;
	*(s32*)(sp + 68) = s1;
	s1 = a1;
	a1 = 0;
	*(s32*)(sp + 64) = s0;
	s0 = a0;
	*(s32*)(sp + 72) = ra;
	a0 = sp;
	v0 = sceVshCommonUtil_A721B1D1(...);
	a0 = 0x00000;
	v1 = *(s32*)(a0 + 4232);

loc_000064E8:		
	a0 = a0 + 4232;
	*(s32*)(sp + 16) = a0;
	v0 = *(s32*)(v1 + 8);
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 4);
	a1 = s1;
	v0 = sub_000119D4(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 32;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006520:		
	v1 = v1 + 4;
	if (v0 == s0)
		goto loc_00006538;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006520;
	}

loc_00006538:		
	v0 = 2;
	*(s32*)(a3 + 0) = s1;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 16);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	a0 = sp;
	v0 = sceVshCommonUtil_3CA4266A(...);
	v0 = s0;
	ra = *(s32*)(sp + 72);
	s1 = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	sp = sp + 80;
	return (v0);
}

onesegCore_9B5682EE(...) // at 0x00006590 
{
	sp = sp - 96;
	*(s32*)(sp + 80) = s4;
	v0 = 0x00000;
	s4 = a1;
	*(s32*)(sp + 76) = s3;
	*(s32*)(sp + 72) = s2;
	s2 = a3;
	*(s32*)(sp + 68) = s1;
	s1 = a0;
	*(s32*)(sp + 64) = s0;
	s0 = a2;
	s3 = s0 & 0x1000;
	*(s32*)(sp + 84) = ra;
	s0 = s0 & 0x3;
	t0 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(t0 + 8);
	a0 = v0;
	v0 = $v1(...);
	v0 = 2;
	cond = (s0 == v0);
	v0 = (u32)s0 < (u32)3;
	if (cond)
		goto loc_000066D4;
	cond = (v0 == 0);
	v0 = 3;
	if (cond)
		goto loc_000066C4;
	v0 = 1;
	if (s0 == v0)
	{
		s3 = s3 | 0x1;
		goto loc_000066A8;
	}

loc_00006600:		
	s0 = 0;
	if (s2 == 0)
		goto loc_00006614;
	v0 = 0x80100000;
	v0 = v0 | 0x9811;
	*(s32*)(s2 + 0) = v0;

loc_00006614:		
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006628:		
	v1 = v1 + 4;
	if (v0 == s1)
		goto loc_00006640;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006628;
	}

loc_00006640:		
	v0 = 3;
	a0 = *(s32*)(sp + 48);
	*(s32*)(a3 + 4) = v0;
	a1 = a3;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = s4;
	*(s32*)(a3 + 16) = s3;
	*(s32*)(a3 + 0) = s0;
	v0 = sub_00005B30(...);
	v0 = *(s32*)(sp + 48);
	if (s2 == 0)
		goto loc_00006670;
	*(s32*)(s2 + 0) = v0;

loc_00006670:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 84);
	s4 = *(s32*)(sp + 80);
	s3 = *(s32*)(sp + 76);
	s2 = *(s32*)(sp + 72);
	s1 = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	sp = sp + 96;
	return (v0);

loc_000066A8:		
	a0 = *(s32*)(s1 + 4);

loc_000066AC:		
	a2 = s3 & 0xFFFF;
	a1 = s4;
	a3 = sp + 48;
	v0 = sub_000116E8(...);
	s0 = v0;
	goto loc_00006614;

loc_000066C4:		
	if (s0 != v0)
		goto loc_00006600;
	a0 = *(s32*)(s1 + 4);
	goto loc_000066AC;

loc_000066D4:		
	a0 = *(s32*)(s1 + 4);
	s3 = s3 | 0x4;
	a1 = s4;
	a2 = s3;
	a3 = sp + 48;
	v0 = sub_00011614(...);
	s0 = v0;
	goto loc_00006614;
}

onesegCore_9F795E01(...) // at 0x000066F4 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 52) = s1;
	s1 = a1;
	*(s32*)(sp + 48) = s0;
	s0 = a0;
	a2 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a2 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s0 + 4);
	a1 = s1;
	v0 = sub_000119F4(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_0000674C:		
	v1 = v1 + 4;
	if (v0 == s0)
		goto loc_00006764;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_0000674C;
	}

loc_00006764:		
	v0 = 4;
	*(s32*)(a3 + 0) = s1;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);

loc_00006794:		
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

onesegCore_1A62FD45(...) // at 0x000067B4 
{
	sp = sp - 80;
	*(s32*)(sp + 64) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 60) = s3;
	s3 = a3;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;
	s1 = a2;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	t0 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(t0 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s2 + 4);
	a2 = s1;
	a3 = s3;

loc_00006808:		
	a1 = s0;
	v0 = sub_00011848(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006824:		
	v1 = v1 + 4;
	if (v0 == s2)
		goto loc_0000683C;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006824;
	}

loc_0000683C:		
	v0 = 5;
	*(s32*)(a3 + 0) = s3;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);

loc_0000686C:		
	v0 = $v0(...);

loc_00006874:		
	v0 = s0;
	ra = *(s32*)(sp + 64);
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 80;
	return (v0);
}

onesegCore_28035942(...) // at 0x00006894 
{
	sp = sp - 80;
	*(s32*)(sp + 64) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 60) = s3;
	s3 = a3;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;
	s1 = a2;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	t0 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(t0 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s2 + 4);
	a2 = s1;
	a3 = s3;
	a1 = s0;
	v0 = sub_000118BC(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006904:		
	v1 = v1 + 4;
	if (v0 == s2)
		goto loc_0000691C;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006904;
	}

loc_0000691C:		
	v0 = 6;
	*(s32*)(a3 + 0) = s3;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 64);
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 80;
	return (v0);
}

onesegCore_EEE4EB94(...) // at 0x00006974 
{
	sp = sp - 80;
	*(s32*)(sp + 60) = s3;
	v0 = 0x00000;
	s3 = a1;
	*(s32*)(sp + 56) = s2;
	s2 = a2;
	*(s32*)(sp + 52) = s1;
	s1 = a0;
	*(s32*)(sp + 48) = s0;
	s0 = a3;
	*(s32*)(sp + 64) = ra;
	t0 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(t0 + 8);
	a0 = v0;
	v0 = $v1(...);
	v0 = 1;
	cond = (s0 == v0);
	v0 = (s32)s0 < (s32)2;
	if (cond)
		goto loc_00006A88;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_00006A78;
	a3 = 2;
	if (s0 == v0)
		goto loc_00006A60;
	a0 = 0x80100000;

loc_000069D8:		
	a0 = a0 | 0x9811;

loc_000069DC:		
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_000069F0:		
	v1 = v1 + 4;
	if (v0 == s1)
		goto loc_00006A08;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_000069F0;
	}

loc_00006A08:		
	v0 = 7;
	*(s32*)(a3 + 0) = s3;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 64);
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 80;
	return (v0);

loc_00006A60:		
	a0 = *(s32*)(s1 + 4);
	a2 = s2;
	a1 = s3;
	v0 = sub_00011928(...);
	a0 = v0;
	goto loc_000069DC;

loc_00006A78:		
	a3 = 0;
	if (s0 == 0)
		goto loc_00006A60;
	a0 = 0x80100000;
	goto loc_000069D8;

loc_00006A88:		
	a3 = 1;
	goto loc_00006A60;
}

sub_00006A90(...) // at 0x00006A90 
{
	sp = sp - 64;
	*(s32*)(sp + 52) = s1;
	v0 = 0x00000;
	s1 = a1;
	*(s32*)(sp + 48) = s0;
	s0 = a0;
	*(s32*)(sp + 56) = ra;
	a2 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a2 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s1 + 16);
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006ADC:		
	v1 = v1 + 4;
	if (v0 == s0)
		goto loc_00006AF4;

loc_00006AE4:		
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006ADC;
	}

loc_00006AF4:		
	v0 = 8;
	*(s32*)(a3 + 0) = s1;
	a1 = a3;
	*(s32*)(a3 + 4) = v0;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 12) = 0;
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;

loc_00006B1C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

sub_00006B44(...) // at 0x00006B44 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 52) = s1;
	s1 = a0;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	a2 = *(s32*)(v0 + 4232);
	v0 = v0 + 4232;
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a2 + 8);
	a0 = v0;
	v0 = $v1(...);
	a0 = *(s32*)(s1 + 4);
	a1 = s0;
	v0 = sub_00011A58(...);
	a0 = v0;
	v0 = 0x00000;
	v1 = v0 + 4304;
	a3 = sp + 16;
	a2 = 0;
	v0 = *(s32*)(v1 + 0);

loc_00006B9C:		
	v1 = v1 + 4;
	if (v0 == s1)
		goto loc_00006BB4;
	a2 = a2 + 1;
	v0 = (s32)a2 < (s32)6;
	if (v0 != 0)
	{
		v0 = *(s32*)(v1 + 0);
		goto loc_00006B9C;
	}

loc_00006BB4:		
	v0 = 9;
	*(s32*)(a3 + 4) = v0;
	a1 = a3;
	*(s32*)(a3 + 8) = a2;
	*(s32*)(a3 + 0) = 0;
	*(s32*)(a3 + 12) = 0;

loc_00006BCC:		
	*(s32*)(a3 + 16) = 0;
	v0 = sub_00005B30(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

sub_00006C04(...) // at 0x00006C04 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	a0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(a0 + 4232);
	a0 = a0 + 4232;
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 8);
	s0 = a1;
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(a0 + 0);
	s0 = *(s32*)(v0 + 40);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
	sp = sp - 16;
	a0 = 1;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_00005848(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a0 = 0;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_00005848(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00006C9C(...) // at 0x00006C9C 
{
	v0 = 0x70000;
	v0 = v0 - 16456;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = a1;
	return (v0);
	v0 = a1;
	return (v0);
	v0 = a1;
	return (v0);
	v0 = a1;
	return (v0);
	v0 = a1;
	return (v0);
	v0 = a1;
	return (v0);
}

onesegCore_AA5E4EE3(...) // at 0x00006CDC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	s0 = s0 + 208;
	a1 = a0;
	a2 = 7;
	*(s32*)(sp + 4) = ra;
	a0 = s0;
	v0 = scePaf_706ABBFF(...);
	v0 = s0;
	*(s8*)(s0 + 7) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_0EE158D8(...) // at 0x00006D18 
{
	v0 = 0x00000;
	v0 = v0 + 208;
	return (v0);
}

onesegCore_436C75B7(...) // at 0x00006D24 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = s0;
	a1 = a0;
	s0 = 0;
	*(s32*)(sp + 52) = ra;
	if ((s32)a0 < 0)
		goto loc_00006D54;
	v1 = 0x20000;
	v0 = *(s32*)(v1 - 11244);
	a2 = a0;
	v0 = (s32)a1 < (s32)v0;
	a0 = sp;
	if (v0 != 0)
		goto loc_00006D68;

loc_00006D54:		
	v0 = s0;

loc_00006D58:		
	ra = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);

loc_00006D68:		
	v0 = 0x20000;
	a1 = *(s32*)(0x20000 - 11248);	// off_1d410 "channellist%d.vsd"
	s0 = 0x00000;
	s0 = s0 + 4352;
	v0 = scePaf_A138A376(...);
	v0 = onesegCore_0EE158D8(...);
	a2 = v0;
	v0 = 0x20000;
	a3 = *(s32*)(v0 - 11252);
	a1 = 0x20000;
	a1 = a1 - 14984;
	a0 = s0;
	t0 = sp;
	v0 = scePaf_A138A376(...);
	v0 = s0;
	goto loc_00006D58;
}

onesegCore_DD225DB6(...) // at 0x00006DAC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	s0 = s0 + 4352;
	v0 = onesegCore_0EE158D8(...);
	v1 = 0x20000;
	a0 = 0x20000;
	t0 = *(s32*)(a0 - 11240);	// off_1d418	//"appsetting.vsd"
	a3 = *(s32*)(v1 - 11252);	// off_1d40c	""
	a1 = 0x20000;
	a0 = s0;
	a1 = a1 - 14984;
	a2 = v0;
	v0 = scePaf_A138A376(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_942F32D8(...) // at 0x00006DFC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	s0 = s0 + 4352;
	v0 = onesegCore_0EE158D8(...);
	v1 = 0x20000;
	a0 = 0x20000;
	t0 = *(s32*)(a0 - 11236);	// "usesetting.vsd"
	a3 = *(s32*)(v1 - 11252);
	a1 = 0x20000;
	a0 = s0;
	a1 = a1 - 14984;
	a2 = v0;
	v0 = scePaf_A138A376(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_639911F2(...) // at 0x00006E4C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	s0 = s0 + 4352;
	v0 = onesegCore_0EE158D8(...);
	v1 = 0x20000;
	a0 = 0x20000;
	t0 = *(s32*)(a0 - 11232);	// "reservationrec.vsd"
	a3 = *(s32*)(v1 - 11252);
	a1 = 0x20000;
	a0 = s0;
	a1 = a1 - 14984;
	a2 = v0;
	v0 = scePaf_A138A376(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_C3FCC158(...) // at 0x00006E9C 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = s0;
	a2 = a1;
	s0 = 0;
	*(s32*)(sp + 52) = ra;
	if ((s32)a1 < 0)
		goto loc_00006F00;
	v0 = 1;
	cond = (a0 == v0);
	v0 = (s32)a1 < (s32)10;
	if (cond)
		goto loc_00006F58;
	v0 = (s32)a0 < (s32)2;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_00006F34;
	if (a0 == v0)
		goto loc_00006F14;

loc_00006ED4:		
	s0 = 0x00000;
	v0 = onesegCore_0EE158D8(...);
	a2 = v0;
	v0 = 0x20000;
	a3 = *(s32*)(v0 - 11252);
	s0 = s0 + 4352;
	a1 = 0x20000;
	a1 = a1 - 14984;	// dw_1c578
	a0 = s0;
	t0 = sp;
	v0 = scePaf_A138A376(...);

loc_00006F00:		
	v0 = s0;
	ra = *(s32*)(sp + 52);

loc_00006F08:		
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);

loc_00006F14:		
	s0 = 0;
	if ((s32)a1 > 0)
		goto loc_00006F00;
	a1 = 0x20000;
	a1 = a1 - 15140;	// "PROGLOG%d.DB"

loc_00006F24:		
	a0 = sp;
	v0 = scePaf_A138A376(...);
	goto loc_00006ED4;

loc_00006F34:		
	v0 = (s32)a1 < (s32)3;
	if (a0 != 0)
		goto loc_00006ED4;
	a1 = 0x20000;
	s0 = 0;
	a1 = a1 - 15156;	// "PROGREC%d.DB"

loc_00006F48:		
	cond = (v0 != 0);
	v0 = s0;
	if (cond)
		goto loc_00006F24;
	ra = *(s32*)(sp + 52);
	goto loc_00006F08;

loc_00006F58:		
	a1 = 0x20000;
	s0 = 0;
	a1 = a1 - 15124;	// "CHLIST0%d.DB"
	goto loc_00006F48;
}

sub_00006F68(...) // at 0x00006F68 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	v1 = 0x00000;
	v0 = t0 << 2;
	*(s32*)(sp + 12) = s3;
	v1 = v1 + 4304;
	v0 = v0 + v1;
	*(s32*)(sp + 8) = s2;
	a2 = a2 & 0xFF;
	s3 = 1;
	*(s32*)(sp + 4) = s1;
	s2 = t0;
	s4 = a0;
	*(s32*)(sp + 0) = s0;
	s1 = a1;
	s0 = a3;
	*(s32*)(sp + 20) = ra;
	v0 = *(s32*)(v0 + 0);
	*(s32*)(a0 + 0) = v0;
	if (a2 == s3)
		goto loc_0000701C;
	if (v0 == 0)
	{
		v0 = 1;
		goto loc_00007020;
	}
	a0 = *(s32*)(v0 + 12);
	v0 = scePaf_4CF09BA2(...);
	if (v0 != 0)
	{
		*(s8*)(s0 + 0) = s3;
		goto loc_00006FD4;
	}
	*(s8*)(s0 + 0) = 0;

loc_00006FD4:		
	v1 = *(u8*)(s0 + 0);
	v0 = 1;
	a0 = s1;
	a1 = s2;
	a2 = 1;
	if (v1 == v0)
		goto loc_0000700C;

loc_00006FEC:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_0000700C:		
	v0 = onesegCore_D71F10C7(...);
	*(s32*)(s4 + 0) = v0;
	goto loc_00006FEC;

loc_0000701C:		
	v0 = 1;

loc_00007020:		
	*(s8*)(s0 + 0) = v0;
	goto loc_00006FD4;
}

onesegCore_E166992B(...) // at 0x00007028 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = a1 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a3;
	*(s32*)(sp + 16) = s0;
	s0 = a2 & 0xFF;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = s4;
	v0 = onesegCore_436C75B7(...);
	v1 = -1;
	if (v0 == 0)
		goto loc_000070B8;
	a1 = v0;
	a0 = sp + 4;
	a2 = s0;
	a3 = sp;
	t0 = 0;
	s4 = 0;
	v0 = sub_00006F68(...);
	v0 = 1;
	if (s2 == 0)
		goto loc_0000711C;
	if (s0 == v0)
		goto loc_0000711C;

loc_0000708C:		
	a0 = *(s32*)(sp + 4);
	if (s2 != 0)
		goto loc_000070F8;
	v1 = *(u8*)(sp + 0);
	if ((s32)s3 < 0)
		goto loc_000070EC;

loc_0000709C:		
	v0 = 1;
	if (v1 == v0)
		goto loc_000070DC;

loc_000070A8:		
	v1 = s3;
	if (s1 == 0)
		goto loc_000070B8;
	*(s8*)(s1 + 0) = s4;
	*(s32*)(s1 + 4) = 0;

loc_000070B8:		
	ra = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_000070DC:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_92167AFC(...);
	goto loc_000070A8;

loc_000070EC:		
	if (s0 != 0)
	{
		v1 = *(u8*)(sp + 0);
		goto loc_0000709C;
	}
	a0 = *(s32*)(sp + 4);

loc_000070F8:		
	a1 = 0;
	a2 = 0;
	v0 = onesegCore_FAFBAF9E(...);
	a0 = *(s32*)(sp + 4);
	a1 = 0;
	s4 = 1;
	v0 = onesegCore_3D97DF93(...);
	v1 = *(u8*)(sp + 0);
	goto loc_0000709C;

loc_0000711C:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_329E26FE(...);
	s3 = v0;
	goto loc_0000708C;
}

sub_0000712C(...) // at 0x0000712C 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	s5 = 0;
	*(s32*)(sp + 32) = s4;
	s4 = 0;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = a0 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 40) = ra;
	s0 = a1 & 0xFF;
	v0 = onesegCore_DD225DB6(...);
	a1 = v0;
	a0 = sp + 4;
	a2 = s0;
	a3 = sp;
	t0 = 2;
	v0 = sub_00006F68(...);
	v0 = 1;
	if (s2 == 0)
		goto loc_0000722C;
	if (s0 == v0)
		goto loc_0000722C;

loc_00007190:		
	a0 = *(s32*)(sp + 4);
	if (s2 != 0)
		goto loc_00007200;
	if ((s32)s4 < 0)
		goto loc_000071F4;

loc_000071A0:		
	v1 = *(u8*)(sp + 0);

loc_000071A4:		
	v0 = 1;
	if (v1 == v0)
		goto loc_000071E4;

loc_000071B0:		
	v0 = s4;
	if (s1 == 0)
		goto loc_000071C0;
	*(s32*)(s1 + 4) = s3;
	*(s8*)(s1 + 0) = s5;

loc_000071C0:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000071E4:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_92167AFC(...);
	goto loc_000071B0;

loc_000071F4:		
	v1 = *(u8*)(sp + 0);
	if (s0 != 0)
		goto loc_000071A4;
	a0 = *(s32*)(sp + 4);

loc_00007200:		
	a1 = 0;
	a2 = 0;
	v0 = onesegCore_FAFBAF9E(...);
	a0 = *(s32*)(sp + 4);
	a1 = 0;
	s5 = 1;
	v0 = onesegCore_3D97DF93(...);
	s3 = v0;
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		s4 = s3;
	goto loc_000071A0;

loc_0000722C:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_329E26FE(...);
	s4 = v0;
	goto loc_00007190;
}

sub_0000723C(...) // at 0x0000723C 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	s5 = 0;
	*(s32*)(sp + 32) = s4;
	s4 = 0;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = a0 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a2;

loc_00007268:		
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 40) = ra;
	s0 = a1 & 0xFF;
	v0 = onesegCore_942F32D8(...);
	a1 = v0;
	a0 = sp + 4;
	a2 = s0;
	a3 = sp;

loc_0000728C:		
	t0 = 3;
	v0 = sub_00006F68(...);
	v0 = 1;
	if (s2 == 0)
		goto loc_0000733C;
	if (s0 == v0)
		goto loc_0000733C;

loc_000072A0:		
	a0 = *(s32*)(sp + 4);
	if (s2 != 0)
		goto loc_00007310;
	if ((s32)s4 < 0)
		goto loc_00007304;

loc_000072B0:		
	v1 = *(u8*)(sp + 0);

loc_000072B4:		
	v0 = 1;
	if (v1 == v0)
		goto loc_000072F4;

loc_000072C0:		
	v0 = s4;
	if (s1 == 0)
		goto loc_000072D0;
	*(s32*)(s1 + 4) = s3;
	*(s8*)(s1 + 0) = s5;

loc_000072D0:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000072F4:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_92167AFC(...);
	goto loc_000072C0;

loc_00007304:		
	v1 = *(u8*)(sp + 0);
	if (s0 != 0)
		goto loc_000072B4;
	a0 = *(s32*)(sp + 4);

loc_00007310:		
	a1 = 0;
	a2 = 0;
	v0 = onesegCore_FAFBAF9E(...);

loc_0000731C:		
	a0 = *(s32*)(sp + 4);
	a1 = 0;
	s5 = 1;
	v0 = onesegCore_3D97DF93(...);
	s3 = v0;
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		s4 = s3;
	goto loc_000072B0;

loc_0000733C:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_329E26FE(...);
	s4 = v0;
	goto loc_000072A0;
}

sub_0000734C(...) // at 0x0000734C 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	s5 = 0;
	*(s32*)(sp + 32) = s4;
	s4 = 0;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = a0 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 40) = ra;
	s0 = a1 & 0xFF;
	v0 = onesegCore_639911F2(...);

loc_00007388:		
	a1 = v0;
	a0 = sp + 4;
	a2 = s0;
	a3 = sp;
	t0 = 5;
	v0 = sub_00006F68(...);
	v0 = 1;
	if (s2 == 0)
		goto loc_0000744C;
	if (s0 == v0)
		goto loc_0000744C;

loc_000073B0:		
	a0 = *(s32*)(sp + 4);
	if (s2 != 0)
		goto loc_00007420;
	if ((s32)s4 < 0)
		goto loc_00007414;

loc_000073C0:		
	v1 = *(u8*)(sp + 0);

loc_000073C4:		
	v0 = 1;
	if (v1 == v0)
		goto loc_00007404;

loc_000073D0:		
	v0 = s4;
	if (s1 == 0)
		goto loc_000073E0;
	*(s32*)(s1 + 4) = s3;
	*(s8*)(s1 + 0) = s5;

loc_000073E0:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00007404:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_92167AFC(...);
	goto loc_000073D0;

loc_00007414:		
	v1 = *(u8*)(sp + 0);
	if (s0 != 0)
		goto loc_000073C4;
	a0 = *(s32*)(sp + 4);

loc_00007420:		
	a1 = 0;
	a2 = 0;
	v0 = onesegCore_FAFBAF9E(...);
	a0 = *(s32*)(sp + 4);
	a1 = 0;
	s5 = 1;
	v0 = onesegCore_3D97DF93(...);
	s3 = v0;
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		s4 = s3;
	goto loc_000073C0;

loc_0000744C:		
	a0 = *(s32*)(sp + 4);
	v0 = onesegCore_329E26FE(...);
	s4 = v0;
	goto loc_000073B0;
}

sub_0000745C(char *lpszString) // at 0x0000745C 
{
	s0 = loc_1100;
	v0 = onesegCore_0EE158D8();
	a2 = 0x20000 - 14976;
	v0 = scePaf_7B7133D5(loc_1100, 255, a2, v0, lpszString);
	return (s0);
}

sub_000074B0(...) // at 0x000074B0 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0x20000 - 15260;	// "/PSP/APP/1SEG"
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v0 = sub_0000745C(...);
	a0 = v0;
	v0 = sceIoDopen(...);
	s0 = 0;
	a0 = 0x20000;
	a0 = a0 - 15272;
	s1 = s0;
	if ((s32)v0 < 0)
		goto loc_00007524;
	a0 = v0;
	s0 = 1;

loc_000074F8:		
	v0 = sceIoDclose(...);

loc_00007500:		
	if (s2 != 0)
	{
		*(s32*)(s2 + 0) = s1;
		goto loc_00007508;
	}

loc_00007508:		
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00007524:		
	s1 = 1;
	v0 = sub_0000745C(...);
	a0 = v0;
	v0 = sceIoDopen(...);
	a0 = 0x20000;
	a0 = a0 - 15280;
	if ((s32)v0 < 0)
		goto loc_00007548;
	a0 = v0;
	goto loc_000074F8;

loc_00007548:		
	s1 = 3;
	v0 = sub_0000745C(...);
	a0 = v0;
	v0 = sceIoDopen(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007500;
	s1 = 2;
	goto loc_000074F8;
}

sub_00007568(...) // at 0x00007568 
{
	v0 = sub_000074B0(0);
	if (v0 == 0)
	{
		v0 = sub_0000745C("/PSP");
		v0 = sceIoMkdir(v0, 0);
		v0 = sub_0000745C("/PSP/APP");
		v0 = sceIoMkdir(v0, 0);
		v0 = sub_0000745C("/PSP/APP/1SEG");
		v0 = sceIoMkdir(v0, 0);
	}
	return (0);
}

onesegCore_BB39A24B(...) // at 0x000075E0 
{
	sp = sp - 48;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = s4;
	s4 = 0;
	*(s32*)(sp + 28) = s3;
	s3 = a2 & 0xFF;
	*(s32*)(sp + 24) = s2;
	s2 = a1 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a3;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 36) = s5;
	*(s8*)(sp + 0) = 0;
	*(s32*)(sp + 4) = 0;
	v0 = sub_00007568(...);
	v1 = (u32)s0 < (u32)7;
	v0 = -1;
	if (v1 == 0)
		goto loc_000076B8;
	v1 = 0x20000;
	v0 = s0 << 2;
	v1 = v1 - 11188;
	v0 = v0 + v1;
	a0 = *(s32*)(v0 + 0);
	a0;
	v0 = 0x20000;
	if (s1 == 0)
		goto loc_0000765C;
	*(s8*)(s1 + 0) = 0;
	*(s32*)(s1 + 4) = 0;

loc_0000765C:		
	v0 = *(s32*)(v0 - 11244);
	s0 = 0;
	if ((s32)v0 <= 0)
		goto loc_000076B4;
	s5 = v0;
	s6 = 1;
	a0 = s0;

loc_00007674:		
	a1 = s2;
	a2 = s3;
	a3 = sp;
	v0 = onesegCore_E166992B(...);
	a0 = *(u8*)(sp + 0);
	v1 = (s32)v0 < (s32)0;
	if (v1 != 0)
		s4 = v0;
	if (a0 == 0)
		goto loc_000076A4;
	v0 = *(s32*)(sp + 4);
	if (s1 == 0)
		goto loc_000076A4;
	*(s8*)(s1 + 0) = s6;
	*(s32*)(s1 + 4) = v0;

loc_000076A4:		
	s0 = s0 + 1;
	v0 = (s32)s0 < (s32)s5;
	a0 = s0;
	if (v0 != 0)
		goto loc_00007674;

loc_000076B4:		
	v0 = s4;

loc_000076B8:		
	ra = *(s32*)(sp + 44);

loc_000076BC:		
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);
	a0 = s2;
	a1 = s3;
	a2 = s1;
	v0 = sub_0000712C(...);
	ra = *(s32*)(sp + 44);
	goto loc_000076BC;
	a0 = s2;
	a1 = s3;
	a2 = s1;
	v0 = sub_0000723C(...);
	ra = *(s32*)(sp + 44);
	goto loc_000076BC;
	a0 = s2;
	a1 = s3;
	a2 = s1;
	v0 = sub_0000734C(...);
	ra = *(s32*)(sp + 44);
	goto loc_000076BC;
	v0 = -1;
	goto loc_000076B8;
}

sub_00007730(...) // at 0x00007730 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 44) = s3;
	s3 = a0;
	*(s32*)(sp + 40) = s2;
	s2 = a1;
	*(s32*)(sp + 36) = s1;
	s1 = a2;
	*(s32*)(sp + 32) = s0;
	s0 = a3;
	v0 = onesegCore_0EE158D8(...);
	a0 = v0;
	a1 = s0;
	a2 = s1;
	a3 = s2;
	t0 = s3;
	v0 = vsh_343F22BB(...);
	a0 = v0;
	a1 = sp;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_000077A4;

loc_00007784:		
	ra = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 64;
	return (v0);

loc_000077A4:		
	v1 = 6;
	v0 = 10;
	*(s32*)(sp + 8) = v1;
	*(s32*)(sp + 4) = v0;
	*(s32*)(sp + 0) = 0;
	*(s32*)(sp + 12) = 0;
	*(s32*)(sp + 16) = 0;
	v0 = sub_00005B30(...);
	v1 = v0;
	goto loc_00007784;
}

sub_000077CC(...) // at 0x000077CC 
{
	sp = sp - 144;
	*(s32*)(sp + 128) = s0;
	s0 = a1;
	*(s32*)(sp + 132) = ra;

loc_000077E0:		
	a1 = sp;
	v0 = sceIoGetstat(...);
	v1 = v0;

loc_000077E8:		
	a0 = v0;
	a1 = sp + 96;
	if ((s32)v0 < 0)
		goto loc_00007814;
	v0 = *(s32*)(sp + 8);
	if (s0 == 0)
		goto loc_00007800;
	*(s32*)(s0 + 0) = v0;

loc_00007800:		
	v0 = v1;
	ra = *(s32*)(sp + 132);

loc_00007808:		
	s0 = *(s32*)(sp + 128);
	sp = sp + 144;
	return (v0);

loc_00007814:		
	v1 = 6;
	v0 = 10;
	*(s32*)(sp + 100) = v0;
	*(s32*)(sp + 104) = v1;
	*(s32*)(sp + 96) = 0;
	*(s32*)(sp + 108) = 0;
	*(s32*)(sp + 112) = 0;
	v0 = sub_00005B30(...);
	ra = *(s32*)(sp + 132);
	goto loc_00007808;
}

sub_0000783C(...) // at 0x0000783C 
{
	v1 = a0 + 26623;
	asm("div        $v1, $a0");
	sp = sp - 48;
	v0 = 0x20000;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	s2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = s4;

loc_00007874:		
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00007878;
	}

loc_00007878:		
	v0 = *(s32*)(v0 - 11244);
	asm("mflo       $s3");
	s4 = v0;
	if ((s32)v0 <= 0)
		goto loc_000078D8;

loc_00007888:		
	a0 = s1;
	v0 = onesegCore_436C75B7(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	s1 = s1 + 1;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	a0 = (s32)s1 < (s32)s4;
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_000078C8;
	}

loc_000078C8:		
	asm("mflo       $v0");
	v0 = s3 - v0;
	s2 = s2 + v0;
	if (a0 != 0)
		goto loc_00007888;

loc_000078D8:		
	v0 = s2;
	ra = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);
}

sub_000078FC(...) // at 0x000078FC 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = a0 + 6879;
	asm("div        $s1, $a0");
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00007920;
	}

loc_00007920:		
	asm("mflo       $s1");
	v0 = onesegCore_DD225DB6(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_0000795C;
	}

loc_0000795C:		
	ra = *(s32*)(sp + 24);
	s0 = *(s32*)(sp + 16);
	asm("mflo       $v0");
	s1 = s1 - v0;
	v0 = s1;
	s1 = *(s32*)(sp + 20);
	sp = sp + 32;
	return (v0);
}

sub_0000797C(...) // at 0x0000797C 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = 0x60000;

loc_00007988:		
	s1 = s1 | 0x83EF;
	s1 = a0 + s1;
	asm("div        $s1, $a0");
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_000079A8;
	}

loc_000079A8:		
	asm("mflo       $s1");
	v0 = onesegCore_942F32D8(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_000079E4;
	}

loc_000079E4:		
	ra = *(s32*)(sp + 24);
	s0 = *(s32*)(sp + 16);
	asm("mflo       $v0");
	s1 = s1 - v0;
	v0 = s1;
	s1 = *(s32*)(sp + 20);
	sp = sp + 32;
	return (v0);
}

sub_00007A04(...) // at 0x00007A04 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = 0x10000;
	s1 = s1 | 0xF29D;
	s1 = a0 + s1;
	asm("div        $s1, $a0");
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00007A30;
	}

loc_00007A30:		
	asm("mflo       $s1");
	v0 = onesegCore_639911F2(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);

loc_00007A4C:		
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00007A6C;
	}

loc_00007A6C:		
	ra = *(s32*)(sp + 24);
	s0 = *(s32*)(sp + 16);
	asm("mflo       $v0");

loc_00007A78:		
	s1 = s1 - v0;
	v0 = s1;
	s1 = *(s32*)(sp + 20);
	sp = sp + 32;
	return (v0);
}

sub_00007A8C(...) // at 0x00007A8C 
{
	v0 = a0 + 23567;
	asm("div        $v0, $a0");
	sp = sp - 48;
	v1 = a0 + 4143;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	s2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 36) = ra;
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00007AC8;
	}

loc_00007AC8:		
	asm("mflo       $s4");
	asm("div        $v1, $a0");
	asm("mflo       $s3");

loc_00007AD4:		
	a1 = s1;
	a0 = 0;
	v0 = onesegCore_C3FCC158(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	s1 = s1 + 1;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	a0 = (s32)s1 < (s32)3;
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00007B18;
	}

loc_00007B18:		
	asm("mflo       $v0");
	v0 = s4 - v0;
	s2 = s2 + v0;
	if (a0 != 0)
		goto loc_00007AD4;
	s1 = 0;

loc_00007B2C:		
	a1 = s1;
	a0 = 1;
	v0 = onesegCore_C3FCC158(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	s1 = s1 + 1;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	a0 = (s32)s1 < (s32)10;
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00007B70;
	}

loc_00007B70:		
	asm("mflo       $v0");
	v0 = s3 - v0;
	s2 = s2 + v0;
	if (a0 != 0)
		goto loc_00007B2C;
	a0 = 2;
	a1 = 0;
	v0 = onesegCore_C3FCC158(...);
	a0 = v0;
	a1 = sp;
	v0 = sub_000077CC(...);
	v1 = *(s32*)(sp + 0);
	v0 = (s32)v0 < (s32)0;
	if (v0 != 0)
		v1 = 0;
	v0 = v1 + s0;
	v0 = v0 - 1;
	asm("div        $v0, $s0");
	*(s32*)(sp + 0) = v1;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00007BBC;
	}

loc_00007BBC:		
	ra = *(s32*)(sp + 36);
	s3 = *(s32*)(sp + 28);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	asm("mflo       $v0");
	v0 = s4 - v0;
	s2 = s2 + v0;
	v0 = s2;
	s4 = *(s32*)(sp + 32);
	s2 = *(s32*)(sp + 24);
	sp = sp + 48;
	return (v0);
}

sub_00007BEC(...) // at 0x00007BEC 
{
	v0 = 0x60000;
	v0 = v0 | 0x83F0;
	return (v0);
}

sub_00007BF8(...) // at 0x00007BF8 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = s4;
	a1 = sp + 4;
	s4 = a0;
	a2 = sp + 8;
	a0 = sp;
	a3 = sp + 12;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	v0 = sub_00007730(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007CD4;
	s0 = *(s32*)(sp + 8);
	v0 = *(s32*)(sp + 12);
	asm("mult       $s0, $v0");
	asm("mflo       $s0");
	v0 = sub_00007BEC(...);
	s2 = v0 + s0;
	s2 = s2 - 1;
	asm("div        $s2, $s0");
	a0 = sp + 16;
	if (s0 == 0)
	{
		asm("break      0x7");
		goto loc_00007C60;
	}

loc_00007C60:		
	asm("mflo       $s2");
	v0 = sub_000074B0(...);
	a0 = s0;
	s3 = *(s32*)(sp + 16);
	v0 = sub_0000783C(...);
	a0 = s0;
	s1 = v0;
	v0 = sub_000078FC(...);
	a0 = s0;
	s1 = s1 + v0;
	v0 = sub_0000797C(...);
	a0 = s0;
	s1 = s1 + v0;
	v0 = sub_00007A04(...);
	s1 = s1 + v0;
	s1 = s1 + s3;
	asm("mult       $s0, $s1");
	asm("mflo       $s1");
	a0 = s0;
	v0 = sub_00007A8C(...);
	s2 = s2 + v0;
	s2 = s2 + 3;
	asm("mult       $s0, $s2");
	v0 = s4 ^ 0x1;
	asm("mflo       $s0");
	s1 = s1 + s0;
	asm("mflo       $a0");
	if (v0 == 0)
		a0 = s1;

loc_00007CD4:		
	ra = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);

loc_00007CE4:		
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = a0;
	sp = sp + 64;
	return (v0);
}

onesegCore_F84EB75C(...) // at 0x00007CF8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = 1;
	v0 = sub_00007BF8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_F31926B3(...) // at 0x00007D14 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = 2;
	v0 = sub_00007BF8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_F38AD858(...) // at 0x00007D30 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	a2 = sp + 8;
	s1 = a0;
	*(s32*)(sp + 16) = s0;

loc_00007D44:		
	a0 = sp;
	s0 = a1;
	a3 = sp + 12;
	*(s32*)(sp + 24) = ra;
	a1 = sp + 4;
	v0 = sub_00007730(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00007DA8;
	a0 = *(s32*)(sp + 8);
	v1 = *(s32*)(sp + 12);
	asm("mult       $a0, $v1");
	asm("mflo       $a0");
	v0 = s1 + a0;
	v0 = v0 - 1;
	asm("div        $v0, $a0");
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00007D88;
	}

loc_00007D88:		
	v1 = *(s32*)(sp + 4);
	asm("mflo       $a1");
	v0 = (u32)v1 < (u32)a1;
	if (v0 != 0)
		goto loc_00007DC0;
	if (s0 != 0)
	{
		*(s32*)(s0 + 0) = 0;
		goto loc_00007DA4;
	}

loc_00007DA4:		
	v1 = 0;

loc_00007DA8:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00007DC0:		
	v0 = a1 - v1;
	if (s0 == 0)
		goto loc_00007DA4;
	asm("mult       $v0, $a0");
	asm("mflo       $v0");
	*(s32*)(s0 + 0) = v0;
	goto loc_00007DA4;
}

sub_00007DD8(...) // at 0x00007DD8 
{
	sp = sp - 48;
	*(s32*)(sp + 16) = s4;
	s4 = a2;
	a2 = 1;
	*(s32*)(sp + 0) = s0;
	s0 = a3;
	a3 = 0;
	*(s32*)(sp + 32) = fp;
	fp = 0;
	*(s32*)(sp + 28) = s7;
	s7 = a0;
	*(s32*)(sp + 24) = s6;
	s6 = t0;
	*(s32*)(sp + 20) = s5;
	s5 = t1;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	v0 = onesegCore_9B5682EE(...);
	s3 = v0;
	v0 = -1;
	if (s3 == 0)
		goto loc_00007ED4;
	a1 = s0;
	a0 = s4;
	a2 = 2;
	a3 = 0;
	v0 = onesegCore_9B5682EE(...);
	s2 = v0;
	v0 = -1;
	if (s2 == 0)
		goto loc_00007ED4;
	a0 = s4;
	a1 = s2;
	v0 = sub_00006C04(...);
	s0 = v0;
	s1 = 0;
	if (v0 == 0)
		goto loc_00007EB8;
	a2 = s0 - s1;

loc_00007E70:		
	v0 = (u32)s5 < (u32)a2;
	if (v0 != 0)
		a2 = s5;
	a0 = s4;
	a1 = s6;
	a3 = s2;
	v0 = onesegCore_1A62FD45(...);
	s1 = s1 + v0;
	a0 = s7;
	a1 = s6;
	a2 = v0;
	a3 = s3;
	if ((s32)v0 < 0)
		goto loc_00007F04;
	v0 = onesegCore_28035942(...);
	v1 = (u32)s1 < (u32)s0;
	if ((s32)v0 < 0)
		goto loc_00007F04;
	a2 = s0 - s1;
	if (v1 != 0)
		goto loc_00007E70;

loc_00007EB8:		
	a0 = s7;
	a1 = s3;
	v0 = onesegCore_9F795E01(...);
	a0 = s4;
	a1 = s2;
	v0 = onesegCore_9F795E01(...);
	v0 = fp;

loc_00007ED4:		
	ra = *(s32*)(sp + 36);
	fp = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);

loc_00007EF8:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_00007F04:		
	fp = v0;
	goto loc_00007EB8;
}

onesegCore_4C4AB11A(...) // at 0x00007F0C 
{
	sp = sp - 16;
	a0 = 0;
	a1 = 4;
	a2 = 0;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegCore_D71F10C7(...);
	a2 = 0x20000;
	a1 = 0x20000;
	s0 = v0;
	a1 = a1 - 11160;
	a0 = v0;

loc_00007F40:		
	a2 = a2 | 0xC620;
	v0 = onesegCore_FAFBAF9E(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00007F58(...) // at 0x00007F58 
{
	v1 = *(u8*)(a0 + 1);
	v0 = *(u8*)(a0 + 0);
	v1 = v1 << 8;
	v0 = v0 | v1;
	return (v0);
}

onesegCore_807ECC40(...) // at 0x00007F6C 
{
	sp = sp - 432;
	*(s32*)(sp + 400) = s4;
	a2 = 0;
	s4 = a0;
	*(s32*)(sp + 384) = s0;
	a0 = 0;
	s0 = a1;
	a1 = 1;
	*(s32*)(sp + 420) = ra;
	*(s32*)(sp + 412) = s7;

loc_00007F94:		
	s7 = sp + 96;
	*(s32*)(sp + 396) = s3;
	*(s32*)(sp + 392) = s2;
	*(s32*)(sp + 388) = s1;
	*(s32*)(sp + 416) = fp;
	*(s32*)(sp + 408) = s6;
	*(s32*)(sp + 404) = s5;
	v0 = onesegCore_D71F10C7(...);
	a2 = 0x20000;
	a1 = 0x50000;
	a1 = a1 - 25976;
	a2 = a2 | 0x2240;
	a0 = v0;
	s2 = v0;
	v0 = onesegCore_FAFBAF9E(...);
	a0 = s4;
	a1 = 0;
	a2 = 0;
	v0 = onesegCore_FAFBAF9E(...);
	v1 = 0x20000;
	v0 = 0x20000;
	s1 = *(s32*)(v1 - 11220);
	s3 = *(s32*)(v0 - 11216);
	a1 = 0x20000;
	a3 = s0;
	a1 = a1 - 14968;
	a0 = sp;	//
	a2 = s1;
	t0 = s3;
	v0 = scePaf_A138A376(...);
	s0 = sp + 48;	//
	a1 = 0x20000;
	a3 = 0x20000;
	a0 = s0;
	a1 = a1 - 14956;	// dw_1c594
	a2 = s1;
	a3 = a3 - 14948;	// "CH_LIST"
	t0 = s3;
	v0 = scePaf_A138A376(...);
	a1 = s0;
	a0 = s4;
	a2 = s2;
	a3 = sp;	//
	t0 = s7;
	t1 = 128;
	v0 = sub_00007DD8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000081C4;
	a0 = s2;
	a1 = sp;
	a2 = 2;
	a3 = 0;
	v0 = onesegCore_9B5682EE(...);
	s1 = v0;
	if (v0 == 0)
		goto loc_000081C4;
	a1 = sp + 224;
	a0 = s2;
	a2 = 8;
	a3 = v0;
	v0 = onesegCore_1A62FD45(...);
	*(s32*)(sp + 368) = v0;
	if ((s32)v0 < 0)
		goto loc_000081D4;
	v0 = *(s32*)(sp + 228);
	s5 = 0;
	if (v0 == 0)
		goto loc_00008170;
	v0 = 0x20000;
	*(s32*)(sp + 372) = s3;
	fp = v0 - 14940;
	s3 = sp + 272;
	a0 = s2;

loc_000080AC:		
	a2 = 30;
	a3 = s1;
	a1 = sp + 240;
	v0 = onesegCore_1A62FD45(...);
	s6 = sp + 320;
	s5 = s5 + 1;
	a0 = sp + 261;
	if ((s32)v0 < 0)
		goto loc_000081D4;
	v0 = sub_00007F58(...);
	v1 = 0x20000;
	a2 = *(s32*)(v1 - 11228);
	t0 = *(s32*)(sp + 372);
	a1 = fp;
	a3 = v0;
	a0 = s3;
	v0 = scePaf_A138A376(...);
	a0 = sp + 263;
	v0 = sub_00007F58(...);
	v1 = 0x20000;
	a2 = *(s32*)(v1 - 11224);
	t0 = *(s32*)(sp + 372);
	a3 = v0;
	a0 = s6;
	a1 = fp;
	v0 = scePaf_A138A376(...);
	a0 = s4;
	a1 = s3;
	a2 = s2;
	a3 = s3;
	t0 = s7;
	t1 = 128;
	v0 = sub_00007DD8(...);
	s0 = v0;
	a1 = s6;
	a0 = s4;
	a2 = s2;
	a3 = s6;
	t0 = s7;
	t1 = 128;
	if ((s32)v0 < 0)
		goto loc_000081B8;
	v0 = sub_00007DD8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000081B8;
	v0 = *(s32*)(sp + 228);
	v0 = (u32)s5 < (u32)v0;
	a0 = s2;
	if (v0 != 0)
		goto loc_000080AC;

loc_00008170:		
	a1 = s1;
	a0 = s2;
	v0 = onesegCore_9F795E01(...);
	a0 = s2;
	v0 = onesegCore_92167AFC(...);
	v0 = 0;

loc_00008188:		
	ra = *(s32*)(sp + 420);
	fp = *(s32*)(sp + 416);
	s7 = *(s32*)(sp + 412);
	s6 = *(s32*)(sp + 408);
	s5 = *(s32*)(sp + 404);
	s4 = *(s32*)(sp + 400);
	s3 = *(s32*)(sp + 396);
	s2 = *(s32*)(sp + 392);
	s1 = *(s32*)(sp + 388);
	s0 = *(s32*)(sp + 384);
	sp = sp + 432;
	return (v0);

loc_000081B8:		
	a1 = s1;
	a0 = s2;
	v0 = onesegCore_9F795E01(...);

loc_000081C4:		
	a0 = s2;
	v0 = onesegCore_92167AFC(...);
	v0 = s0;
	goto loc_00008188;

loc_000081D4:		
	a1 = s1;
	a0 = s2;
	v0 = onesegCore_9F795E01(...);
	s0 = *(s32*)(sp + 368);
	goto loc_000081C4;
}

sub_000081E8(...) // at 0x000081E8 
{
	v0 = 0x00000;
	v1 = *(s32*)(v0 + 4624);
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = v1;
	if (v1 != 0)
		goto loc_00008210;
	ra = *(s32*)(sp + 0);

loc_00008208:		
	sp = sp + 16;
	return (v0);

loc_00008210:		
	v0 = sub_00013630(...);
	ra = *(s32*)(sp + 0);
	goto loc_00008208;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v0 = *(s32*)(v0 + 4628);
	a1 = a0;
	if (v0 == 0)
		goto loc_0000824C;
	a0 = v0;
	v0 = sub_00014660(...);
	ra = *(s32*)(sp + 0);

loc_00008244:		
	sp = sp + 16;
	return (v0);

loc_0000824C:		
	v0 = sub_000081E8(...);
	ra = *(s32*)(sp + 0);
	goto loc_00008244;
}

onesegCore_88C6EFD9(...) // at 0x0000825C 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = ra;
	v0 = 0x00000;
	a1 = 0;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(v0 + 4608);
	v1 = v1 + 1;
	a0 = (s32)v1 < (s32)2;
	*(s32*)(v0 + 4608) = v1;
	if (a0 != 0)
		goto loc_000082B0;

loc_00008290:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a1;
	sp = sp + 48;
	return (v0);

loc_000082B0:		
	s0 = 0x00000;
	a0 = s0 + 4616;
	v0 = onesegHalToolbox_35CAA030(...);
	a1 = 0x20000;
	if ((s32)v0 > 0)
		goto loc_000083B4;
	a1 = a1 - 14928;	// "AW_AudioDecodeTask"
	a0 = sp;
	v0 = sub_000134F8(...);
	s3 = 0x00000;
	s2 = 0x00000;
	if ((s32)v0 <= 0)
		goto loc_00008364;

loc_000082DC:		
	a0 = *(s32*)(s2 + 4628);

loc_000082E0:		
	s1 = 0x00000;
	if (a0 != 0)
		goto loc_0000834C;

loc_000082E8:		
	a0 = *(s32*)(s0 + 4616);
	if (a0 != 0)
		goto loc_0000833C;

loc_000082F4:		
	a0 = *(s32*)(s3 + 4624);

loc_000082F8:		
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_00008328;
	}

loc_00008300:		
	a0 = *(s32*)(s1 + 4628);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_00008314;
	}

loc_0000830C:		
	a1 = 3;
	goto loc_00008290;

loc_00008314:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s1 + 4628) = 0;
	goto loc_0000830C;

loc_00008328:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s3 + 4624) = 0;
	goto loc_00008300;

loc_0000833C:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s0 + 4616) = 0;
	goto loc_000082F4;

loc_0000834C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s2 + 4628) = 0;
	goto loc_000082E8;

loc_00008364:		
	v1 = *(s32*)(sp + 0);
	v0 = 0x10000;
	v0 = v0 - 32224;
	*(s32*)(v1 + 1008) = v0;
	a1 = 0x20000;
	a0 = s2 + 4628;
	a1 = a1 - 14908;	// "AW_AudioRenderTask"
	*(s32*)(s3 + 4624) = v1;
	v0 = sub_00013D20(...);
	a0 = *(s32*)(s2 + 4628);
	if ((s32)v0 > 0)
		goto loc_000082E0;
	v0 = 0x10000;
	v0 = v0 - 32280;
	*(s32*)(a0 + 28) = v0;
	v0 = sub_000144A4(...);
	v1 = 1;
	v0 = 0x00000;
	a1 = 0;
	*(s32*)(v0 + 4612) = v1;
	goto loc_00008290;

loc_000083B4:		
	s3 = 0x00000;
	s2 = 0x00000;
	goto loc_000082DC;
}

onesegCore_1F6E93FF(...) // at 0x000083C0 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	v1 = 0x00000;
	s2 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	*(s32*)(sp + 12) = ra;
	v0 = *(s32*)(v1 + 4608);
	v0 = v0 - 1;
	*(s32*)(v1 + 4608) = v0;
	if ((s32)v0 <= 0)
		goto loc_00008410;

loc_000083F4:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_00008410:		
	v0 = *(s32*)(s0 + 4628);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000845C;

loc_0000841C:		
	v0 = *(s32*)(s1 + 4616);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000844C;

loc_00008428:		
	v1 = *(s32*)(s2 + 4624);
	a0 = v1;
	if (v1 == 0)
		goto loc_000083F4;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s2 + 4624) = 0;
	goto loc_000083F4;

loc_0000844C:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s1 + 4616) = 0;
	goto loc_00008428;

loc_0000845C:		
	v0 = sub_000144D8(...);
	a0 = *(s32*)(s0 + 4628);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 4628) = 0;
	goto loc_0000841C;
}

onesegCore_B5C3AE24(...) // at 0x00008480 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = s6;
	s6 = a2;
	*(s32*)(sp + 52) = s5;
	s5 = a0;
	*(s32*)(sp + 48) = s4;
	s4 = 0x00000;
	*(s32*)(sp + 44) = s3;
	s3 = 0x00000;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;

loc_000084AC:		
	s1 = 0x00000;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 32) = s0;
	v0 = *(s32*)(s1 + 4616);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);
	s2 = 1;
	v0 = $v0(...);
	v1 = *(s32*)(s4 + 4612);
	v0 = 1;
	if (v1 == v0)
	{
		a0 = *(s32*)(sp + 0);
		goto loc_000085D4;
	}
	a0 = *(s32*)(s1 + 4616);

loc_000084E8:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = *(s32*)(s3 + 4624);
	v0 = sub_000135F0(...);
	a0 = *(s32*)(s1 + 4616);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s4 + 4612);
	if (v1 == s2)
		goto loc_000085B8;
	a0 = *(s32*)(s1 + 4616);
	if (s0 == 0)
		goto loc_000084E8;
	s1 = 0x00000;
	a0 = *(s32*)(s1 + 4620);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_000085A4;
	}

loc_0000853C:		
	a1 = *(s32*)(s0 + 28);
	v1 = *(s32*)(s5 + 0);
	a0 = *(s32*)(sp + 0);
	*(s32*)(sp + 16) = a1;
	v1 = (s32)v1 < (s32)a1;
	v0 = sp + 16;
	if (v1 != 0)
		v0 = s5;
	a1 = *(s32*)(v0 + 0);
	v1 = *(s32*)(s0 + 24);
	a2 = *(s32*)(a0 + 0);
	*(s32*)(s5 + 0) = a1;
	v0 = *(s32*)(a2 + 4);
	*(s32*)(s6 + 0) = v1;
	*(s32*)(s1 + 4620) = s0;
	v0 = $v0(...);
	v0 = 0;

loc_0000857C:		
	ra = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 64;
	return (v0);

loc_000085A4:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s1 + 4620) = 0;
	goto loc_0000853C;

loc_000085B8:		
	a0 = *(s32*)(sp + 0);
	if (s0 == 0)
		goto loc_000085D4;
	v1 = *(s32*)(s0 + 0);
	v0 = *(s32*)(v1 + 0);
	a0 = s0;
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);

loc_000085D4:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 2;
	goto loc_0000857C;
}

onesegCore_5253B6A3(...) // at 0x000085EC 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	v0 = 0x00000;
	s5 = t3 & 0xFF;
	*(s32*)(sp + 32) = s4;
	s4 = t2 & 0xFF;
	*(s32*)(sp + 28) = s3;
	s3 = t1;
	*(s32*)(sp + 24) = s2;
	s2 = t0;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 40) = ra;
	a0 = *(s32*)(v0 + 4616);
	v0 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v1 = *(s32*)(v0 + 0);
	s0 = a1;
	v0 = $v1(...);
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 4612);
	v1 = 1;
	a1 = s0;
	if (a0 == v1)
		goto loc_000086CC;
	a0 = *(s32*)(s1 + 4620);
	v0 = sub_00013218(...);
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 4624);
	v1 = *(s32*)(s1 + 4620);
	v0 = *(s32*)(sp + 48);
	a2 = *(s32*)(a0 + 0);
	*(s32*)(v1 + 32) = s2;
	*(s32*)(v1 + 36) = s3;
	*(s32*)(v1 + 60) = v0;
	*(s8*)(v1 + 40) = s4;
	*(s8*)(v1 + 56) = s5;
	v0 = *(s32*)(a2 + 40);
	a1 = v1;
	v0 = $v0(...);
	a1 = *(s32*)(sp + 0);
	*(s32*)(s1 + 4620) = 0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	v0 = 0;

loc_000086A8:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000086CC:		
	v1 = *(s32*)(s1 + 4620);
	a0 = v1;
	if (v1 != 0)
		goto loc_000086F4;

loc_000086D8:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 2;
	goto loc_000086A8;

loc_000086F4:		
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s1 + 4620) = 0;
	goto loc_000086D8;
}

onesegCore_BEF8E97D(...) // at 0x0000870C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	v0 = 0x00000;
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(v0 + 4616);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s0 = 0x00000;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 4624);
	a0 = v1;
	if (v1 == 0)
		goto loc_000087A4;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 48);
	v0 = $v0(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_000087A8;
	v0 = *(s32*)(s0 + 4624);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	v0 = *(s32*)(v1 + 32);
	v0 = $v0(...);
	a1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_000087A4;
	v0 = 0x00000;
	*(s32*)(v0 + 4612) = 0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	v0 = 0;

loc_00008794:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_000087A4:		
	v0 = *(s32*)(sp + 0);

loc_000087A8:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 2;
	goto loc_00008794;
}

onesegCore_458C9E66(...) // at 0x000087C0 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(v0 + 4616);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;

loc_000087E4:		
	v0 = *(s32*)(v1 + 0);
	s0 = 0x00000;
	v0 = $v0(...);
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 4628);
	a1 = 2;
	v0 = sub_000146F4(...);
	a1 = *(s32*)(s0 + 4620);
	v1 = 1;
	v0 = 0x00000;
	a0 = a1;
	*(s32*)(v0 + 4612) = v1;
	if (a1 != 0)
		goto loc_000088B4;

loc_00008818:		
	v0 = *(s32*)(s1 + 4624);
	a1 = 16;
	a0 = 2;
	if (v0 != 0)
		goto loc_00008854;
	a0 = *(s32*)(sp + 0);

loc_0000882C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);

loc_00008854:		
	v0 = onesegSdkCore_838A1E79(...);
	a1 = 0x7FFF0000;
	a0 = v0;
	a1 = a1 | 0xFFFF;
	s0 = v0;
	v0 = onesegSdkCore_ED582126(...);
	a0 = *(s32*)(s1 + 4624);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	a1 = s0;
	v0 = $v0(...);
	a0 = *(s32*)(s1 + 4624);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 36);
	v0 = $v0(...);
	a0 = *(s32*)(s1 + 4624);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 52);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	goto loc_0000882C;

loc_000088B4:		
	v1 = *(s32*)(a1 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 4620) = 0;
	goto loc_00008818;
}

onesegCore_7755122A(...) // at 0x000088CC 
{
	v1 = 0x00000;
	v0 = a0;
	a0 = *(s32*)(v1 + 4628);
	sp = sp - 16;
	a3 = a1;
	*(s32*)(sp + 0) = ra;
	a1 = v0;
	v0 = sub_000145F4(...);
	v0 = 0;
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_AAB8112F(...) // at 0x000088FC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	t6 = a0;
	a0 = *(s32*)(v0 + 4628);
	t4 = a2;
	t5 = a3;
	t2 = t0;
	t3 = t1;
	a2 = t6;
	a3 = a1;
	t0 = t4;
	t1 = t5;
	v0 = sub_00014528(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

onesegCore_2A9595F9(...) // at 0x00008944 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = *(s32*)(s2 + 4628);
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = sub_00014754(...);
	v1 = v0;
	v0 = 4;
	a0 = *(s32*)(s2 + 4628);
	if (s0 == v0)
		goto loc_000089E0;
	a1 = s0;
	v0 = sub_000146F4(...);
	v0 = onesegSal_39AF4F3B(...);
	s1 = v0;

loc_0000898C:		
	v0 = onesegSal_39AF4F3B(...);
	v0 = v0 - s1;
	v0 = (u32)v0 < (u32)2000;
	ra = *(s32*)(sp + 12);
	if (v0 == 0)
		goto loc_000089C8;
	a0 = *(s32*)(s2 + 4628);
	v0 = sub_00014754(...);
	a0 = 10;
	if (v0 == s0)
		goto loc_000089C4;
	v0 = onesegSal_FB5FE576(...);
	goto loc_0000898C;

loc_000089C4:		
	ra = *(s32*)(sp + 12);

loc_000089C8:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_000089E0:		
	v0 = 1;
	if (v1 != v0)
	{
		ra = *(s32*)(sp + 12);
		goto loc_000089C8;
	}
	a0 = *(s32*)(s2 + 4628);
	a1 = 4;
	v0 = sub_000146F4(...);
	ra = *(s32*)(sp + 12);
	goto loc_000089C8;
}

onesegCore_6EFD61E5(...) // at 0x00008A00 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = a0 & 0xFF;
	v1 = *(s32*)(v0 + 4616);
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 4628);
	a1 = s0;
	v0 = sub_000146DC(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_B949A746(...) // at 0x00008A60 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	v1 = *(s32*)(v0 + 4616);
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 4628);
	a1 = s0;
	v0 = sub_000146E4(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

onesegCore_14794291(...) // at 0x00008AC4 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(v0 + 4616);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 4628);
	v0 = sub_000146EC(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_278B5940(...) // at 0x00008B24 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 5788);
	v0 = sub_00015124(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_DBE529D9(...) // at 0x00008B44 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 5788);
	v0 = sub_00015180(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_1367815B(...) // at 0x00008B64 
{
	v1 = 0x00000;
	v0 = a0;
	a0 = *(s32*)(v1 + 5788);
	sp = sp - 16;
	a2 = a1;
	*(s32*)(sp + 0) = ra;
	a1 = v0;
	v0 = sub_000151DC(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_5D9A7E2C(...) // at 0x00008B90 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a1 = a0;
	a0 = *(s32*)(v0 + 5788);
	v0 = sub_00015248(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_FA82BAED(...) // at 0x00008BB4 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	t2 = a0;
	a0 = *(s32*)(v0 + 5788);
	v1 = a1;
	t0 = a2;
	t1 = a3;
	a1 = t2;
	a2 = v1;
	v0 = sub_00015290(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_B58AE8B3(...) // at 0x00008BEC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 5788);
	v0 = sub_000153A8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00008C0C(...) // at 0x00008C0C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v0 = v0 + 5736;
	v1 = *(u8*)(v0 + 70);
	a1 = 0;
	if (v1 != 0)
		goto loc_00008C2C;
	a1 = *(s32*)(v0 + 76);

loc_00008C2C:		
	a0 = *(s32*)(v0 + 52);
	v0 = sub_00015414(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_449F7B91(...) // at 0x00008C40 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	s1 = s1 + 5736;
	*(s32*)(sp + 16) = s0;
	s0 = a0 & 0xFF;
	v1 = *(s32*)(s1 + 40);
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	*(s8*)(s1 + 70) = s0;
	v0 = sub_00008C0C(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_5C1BA4F4(...) // at 0x00008CA4 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	s0 = s0 + 5736;
	v0 = *(s32*)(s0 + 40);
	a1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a1 + 0);
	a0 = v0;
	v0 = $v1(...);
	*(s32*)(s0 + 76) = s1;
	v0 = sub_00008C0C(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_C93F65D6(...) // at 0x00008D10 
{
	v0 = 0;
	return (v0);
}

onesegCore_3F6E6C27(...) // at 0x00008D18 
{

loc_00008D1C:		
	v0 = 0;
	return (v0);
}

onesegCore_B27C4716(...) // at 0x00008D20 
{
	v1 = (u32)a2 < (u32)1;
	v0 = (u32)a0 < (u32)1;
	sp = sp - 48;
	v1 = v1 | v0;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = a2;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = a1;
	*(s32*)(sp + 32) = ra;
	if (v1 != 0)
		goto loc_00008E10;
	v0 = sub_00005CD8(...);
	a0 = v0;
	if (v0 == 0)
		goto loc_00008D88;
	v0 = 1;
	cond = (s0 == v0);
	v0 = (s32)s0 < (s32)2;
	if (cond)
		goto loc_00008E04;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_00008DF0;
	a1 = s1;
	if (s0 == v0)
		goto loc_00008DB8;
	*(s32*)(s2 + 0) = 0;

loc_00008D88:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;

loc_00008D9C:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00008DB8:		
	a2 = 3;

loc_00008DBC:		
	a3 = sp;
	v0 = onesegCore_9B5682EE(...);
	*(s32*)(s2 + 0) = v0;
	v0 = *(s32*)(s2 + 0);

loc_00008DD0:		
	if (v0 == 0)
	{
		a0 = *(s32*)(sp + 0);
		goto loc_00008DDC;
	}
	v0 = s3;
	goto loc_00008D9C;

loc_00008DDC:		
	s3 = 0x80000000;
	s3 = s3 | 0x8;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s3;
	goto loc_00008D9C;

loc_00008DF0:		
	if (s0 != 0)
	{
		*(s32*)(s2 + 0) = 0;
		goto loc_00008D88;
	}
	a1 = s1;
	a2 = 1;
	goto loc_00008DBC;

loc_00008E04:		
	a1 = s1;
	a2 = 2;
	goto loc_00008DBC;

loc_00008E10:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	goto loc_00008D9C;
}

onesegCore_9F1FE5B3(...) // at 0x00008E24 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x80000000;
	s1 = s1 | 0x8;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = sub_00005EF8(...);
	a0 = v0;
	a1 = s0;
	if (v0 == 0)
		goto loc_00008E80;
	v0 = onesegCore_9F795E01(...);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s1 = 0;
	a0 = v0;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s1;

loc_00008E6C:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00008E80:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_00008E6C;
}

onesegCore_F0A1D896(...) // at 0x00008E98 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1;
	v0 = sub_00005EF8(...);
	a0 = 0x80010000;
	a1 = s0;
	a0 = a0 | 0x16;
	a3 = s1;
	a2 = s2;
	s0 = 0;
	if (v0 == 0)
		goto loc_00008F28;
	a0 = v0;
	v0 = onesegCore_1A62FD45(...);
	if (v0 == s2)
	{
		v0 = s0;
		goto loc_00008EFC;
	}
	s0 = 0x80000000;
	a0 = v0;
	s0 = s0 | 0x9;
	if ((s32)v0 < 0)
		goto loc_00008F14;
	v0 = s0;

loc_00008EFC:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00008F14:		
	s0 = 0x80000000;
	s0 = s0 | 0x8;
	v0 = onesegSal_69D4A9F4(...);

loc_00008F20:		
	v0 = s0;
	goto loc_00008EFC;

loc_00008F28:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_00008EFC;
}

onesegCore_42238199(...) // at 0x00008F3C 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1;
	v0 = sub_00005EF8(...);
	a0 = 0x80010000;
	a1 = s0;
	a0 = a0 | 0x16;
	a3 = s1;
	a2 = s2;
	s0 = 0;
	if (v0 == 0)
		goto loc_00008FC8;
	a0 = v0;
	v0 = onesegCore_28035942(...);
	if (v0 == s2)
	{
		v0 = s0;
		goto loc_00008FA0;
	}
	s0 = 0x80000000;
	a0 = v0;
	s0 = s0 | 0x8;
	if ((s32)v0 < 0)
		goto loc_00008FB8;
	v0 = s0;

loc_00008FA0:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00008FB8:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = s0;
	goto loc_00008FA0;

loc_00008FC8:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_00008FA0;
}

onesegCore_50F31264(...) // at 0x00008FDC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = 0x80000000;
	*(s32*)(sp + 4) = ra;
	s0 = s0 | 0x8;
	v0 = sub_00005EF8(...);
	a0 = v0;
	a1 = 0;
	if (v0 == 0)
		goto loc_0000902C;
	v0 = onesegCore_3D97DF93(...);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s0 = 0;
	a0 = v0;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s0;

loc_0000901C:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000902C:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_0000901C;
}

onesegCore_339BBB3B(...) // at 0x00009044 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a0 = 0;
	*(s32*)(sp + 16) = s4;
	s4 = 0;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_69D4A9F4(...);
	a0 = 0x80010000;
	if (s3 == 0)
		goto loc_0000916C;
	a0 = s1;
	v0 = sub_00005EF8(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_00009154;
	a0 = v0;
	a1 = s1;
	a2 = 0;
	a3 = 1;
	v0 = onesegCore_EEE4EB94(...);
	a0 = s0;
	if ((s32)v0 < 0)
		goto loc_00009134;
	a1 = s1;
	v0 = sub_00006A90(...);
	s2 = v0;
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009138;
	a0 = s0;
	a1 = s1;
	a2 = 0;
	a3 = 2;
	v0 = onesegCore_EEE4EB94(...);
	a0 = s0;
	if ((s32)v0 < 0)
		goto loc_00009134;
	a1 = s1;
	v0 = sub_00006A90(...);
	v1 = (s32)v0 >> 31;
	*(s32*)(s3 + 0) = v0;
	*(s32*)(s3 + 4) = v1;
	v0 = *(s32*)(s3 + 4);
	a1 = s1;
	if ((s32)v0 < 0)
		goto loc_0000914C;
	a0 = s0;
	a2 = s2;
	a3 = 0;
	v0 = onesegCore_EEE4EB94(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009138;
	v0 = s4;

loc_00009114:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00009134:		
	a0 = v0;

loc_00009138:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x8;
	goto loc_00009114;

loc_0000914C:		
	a0 = *(s32*)(s3 + 0);
	goto loc_00009138;

loc_00009154:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_00009114;

loc_0000916C:		
	s4 = 0x80000000;
	a0 = a0 | 0x16;
	s4 = s4 | 0x4;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s4;
	goto loc_00009114;
}

onesegCore_F3F160D4(...) // at 0x00009184 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = a0;
	*(s32*)(sp + 16) = s4;
	s4 = 0;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	s0 = t0;

loc_000091AC:		
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 12) = s3;
	v0 = sub_00005EF8(...);
	s1 = v0;
	if (v0 == 0)
		goto loc_000091E8;
	a0 = 0;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 1;
	a3 = 1;
	if (s0 == v0)
		goto loc_00009220;
	v0 = (s32)s0 < (s32)2;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_00009250;
	a3 = 2;
	if (s0 == v0)
		goto loc_00009220;

loc_000091E8:		
	a0 = 0x80010000;

loc_000091EC:		

loc_000091F0:		
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;

loc_000091FC:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00009220:		
	a0 = s1;
	a1 = s5;
	a2 = s2;
	v0 = onesegCore_EEE4EB94(...);
	v1 = 0x80000000;
	v0 = (u32)v0 >> 31;
	v1 = v1 | 0x8;
	if (v0 != 0)
		s4 = v1;
	a0 = v0;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s4;
	goto loc_000091FC;

loc_00009250:		
	a3 = 0;
	if (s0 == 0)
		goto loc_00009220;
	a0 = 0x80010000;
	goto loc_000091EC;
}

onesegCore_7C40562F(...) // at 0x00009260 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = 0;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 16) = ra;
	s1 = a1;
	v0 = sub_00005EF8(...);
	a0 = 0x80010000;
	s0 = v0;
	a0 = a0 | 0x16;
	if (v0 == 0)
		goto loc_00009318;
	a0 = 0;
	v0 = onesegSal_69D4A9F4(...);
	a0 = s0;
	a1 = s2;
	if (s1 == 0)
		goto loc_00009304;
	v0 = sub_00006A90(...);
	v1 = (s32)v0 >> 31;
	*(s32*)(s1 + 0) = v0;
	*(s32*)(s1 + 4) = v1;
	v0 = *(s32*)(s1 + 4);
	if ((s32)v0 < 0)
	{
		a0 = *(s32*)(s1 + 0);
		goto loc_000092EC;
	}
	v0 = s3;

loc_000092D0:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000092EC:		
	s3 = 0x80000000;
	s3 = s3 | 0x8;

loc_000092F4:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = s3;
	goto loc_000092D0;

loc_00009304:		
	a0 = 0x80010000;
	s3 = 0x80000000;
	a0 = a0 | 0x16;
	s3 = s3 | 0x4;
	goto loc_000092F4;

loc_00009318:		
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_000092D0;
}

onesegCore_EB136A28(...) // at 0x0000932C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	if (a0 == 0)
		goto loc_000093A4;
	s1 = 0x80000000;
	v0 = sub_00005CD8(...);
	s1 = s1 | 0x8;
	a0 = v0;
	a1 = s0;
	if (v0 == 0)
		goto loc_0000938C;
	v0 = sub_00006B44(...);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s1 = 0;
	a0 = v0;
	v0 = onesegSal_69D4A9F4(...);
	v0 = s1;

loc_00009378:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000938C:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	v0 = v0 | 0x4;
	goto loc_00009378;

loc_000093A4:		
	a0 = 0x80010000;
	a0 = a0 | 0x16;
	v0 = onesegSal_69D4A9F4(...);
	v0 = 0x80000000;
	goto loc_00009378;
}

onesegCore_9DADF136(...) // at 0x000093B8 
{
	sp = sp - 80;
	v0 = 0x80000000;
	*(s32*)(sp + 72) = s6;
	v0 = v0 | 0x4;
	s6 = a0;
	*(s32*)(sp + 64) = s4;
	a0 = a1;
	s4 = a3;
	*(s32*)(sp + 76) = ra;
	a1 = a2;
	*(s32*)(sp + 68) = s5;
	*(s32*)(sp + 60) = s3;
	*(s32*)(sp + 56) = s2;
	*(s32*)(sp + 52) = s1;
	*(s32*)(sp + 48) = s0;
	if (a3 == 0)
		goto loc_00009484;
	a2 = 0;
	a3 = 2;
	v0 = scePaf_D0D9615E(...);
	s2 = v0;
	v0 = 0x80000000;
	if (s2 == 0)
		goto loc_00009484;
	v1 = *(s32*)(s2 + 44);
	s1 = s2 + 44;
	a0 = s2;
	*(s32*)(sp + 16) = v1;
	a1 = 1;
	v0 = *(s32*)(s1 + 4);
	*(s32*)(sp + 0) = v1;
	*(s32*)(sp + 4) = v0;
	*(s32*)(sp + 20) = v0;
	v0 = scePaf_8EDF4126(...);
	a0 = s6;
	a3 = *(s32*)(sp + 0);
	t0 = *(s32*)(sp + 4);
	a1 = s4;

loc_00009448:		
	a2 = 1;
	t1 = 0;
	*(s32*)(sp + 32) = v0;
	*(s32*)(sp + 36) = v1;
	v0 = onesegHalToolbox_92CE3260(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009530;
	v1 = *(s32*)(s1 + 56);
	v0 = 3;
	cond = (v1 == v0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_000094AC;
	s0 = 0x80000000;

loc_00009478:		
	a0 = s2;
	v0 = onesegSal_71AED199(...);
	v0 = s0;

loc_00009484:		
	ra = *(s32*)(sp + 76);
	s6 = *(s32*)(sp + 72);
	s5 = *(s32*)(sp + 68);
	s4 = *(s32*)(sp + 64);
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 80;
	return (v0);

loc_000094AC:		
	a0 = *(u16*)(s1 + 72);
	s3 = 0;
	v0 = v0 << 2;
	v0 = v0 + a0;
	v0 = v0 - 1;
	asm("div        $v0, $a0");
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_000094CC;
	}

loc_000094CC:		
	v1 = *(s32*)(sp + 4);
	asm("mflo       $v0");
	asm("mult       $v0, $a0");
	asm("mflo       $s5");

loc_000094E0:		
	s1 = 0;
	if (v1 == 0)
		goto loc_00009478;
	t1 = *(s32*)(sp + 32);

loc_000094E8:		
	a1 = *(s32*)(s4 + 0);
	t0 = *(s32*)(sp + 0);
	t1 = t1 + s1;
	a3 = s3;
	a0 = s6;
	a2 = 0;
	t2 = 8;
	v0 = onesegHalToolbox_21E5600F(...);
	s3 = s3 + 1;
	s0 = v0;
	s1 = s1 + s5;
	if ((s32)v0 < 0)
		goto loc_00009478;
	v0 = *(s32*)(sp + 4);
	v0 = (u32)s3 < (u32)v0;
	t1 = *(s32*)(sp + 32);
	if (v0 != 0)
		goto loc_000094E8;
	goto loc_00009478;

loc_00009530:		
	a0 = s2;
	v0 = onesegSal_71AED199(...);
	v0 = 0x80000000;
	goto loc_00009484;
}

onesegCore_AFA1CE96(...) // at 0x00009540 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_000095E0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_9925EA20(...) // at 0x0000955C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_000095FC(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_30D7BE7D(...) // at 0x00009578 
{
	sp = sp - 16;
	a0 = 0;
	a1 = 1052;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	v0 = 0x70000;
	v1 = -1;
	v0 = v0 - 16416;
	*(s32*)(s0 + 20) = v1;
	a1 = 0x20000;
	a0 = s0 + 796;
	*(s32*)(s0 + 8) = v1;
	a1 = 0x20000 - 14888;	// "USER AGENT"
	*(s32*)(s0 + 0) = v0;
	*(s32*)(s0 + 24) = 0;
	*(s8*)(s0 + 540) = 0;
	*(s8*)(s0 + 28) = 0;
	*(s8*)(s0 + 284) = 0;
	v0 = onesegSal_12F99955(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000095E0(...) // at 0x000095E0 
{
	v0 = 0x00000;
	v1 = -1;
	*(s32*)(v0 + 216) = v1;
	a0 = 1;
	v0 = 0x00000;
	*(s8*)(v0 + 4668) = a0;
	return (v0);
}

sub_000095FC(...) // at 0x000095FC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	v0 = 0x00000;
	v1 = *(s32*)(s1 + 216);
	*(s32*)(sp + 12) = ra;

loc_00009614:		
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	*(s8*)(v0 + 4668) = 0;
	if ((s32)v1 < 0)
		goto loc_00009674;
	v0 = 0x00000;
	s0 = v0 + 4636;
	s2 = s1;

loc_00009630:		
	a0 = 10;
	v0 = onesegSal_FB5FE576(...);
	a0 = s0;
	a1 = 1;
	a2 = 0;
	v0 = sceKernelLockLwMutex(...);
	v1 = *(s32*)(s1 + 216);

loc_0000964C:		
	a0 = v1;
	if ((s32)v1 < 0)
		goto loc_0000965C;
	v0 = sceHttpAbortRequest(...);

loc_0000965C:		
	a0 = s0;
	a1 = 1;
	v0 = sceKernelUnlockLwMutex(...);
	v1 = *(s32*)(s2 + 216);
	if ((s32)v1 >= 0)
		goto loc_00009630;

loc_00009674:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16416;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if ((s32)v1 < 0)
		goto loc_000096C4;
	v0 = sceHttpDeleteTemplate(...);
	v1 = -1;
	*(s32*)(s0 + 8) = v1;

loc_000096C4:		
	v0 = 0x70000;
	v0 = v0 - 16336;
	*(s32*)(s0 + 0) = v0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16416;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if ((s32)v1 < 0)
		goto loc_00009718;
	v0 = sceHttpDeleteTemplate(...);
	v1 = -1;
	*(s32*)(s0 + 8) = v1;

loc_00009718:		
	v0 = 0x70000;
	v0 = v0 - 16336;
	*(s32*)(s0 + 0) = v0;
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = s6;
	v0 = 0x00000;
	t2 = t2 & 0xFF;
	*(s32*)(sp + 20) = s5;
	s6 = a0;
	s5 = t1;
	*(s32*)(sp + 16) = s4;
	s4 = t0;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	a2 = t2;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 4) = s1;
	v1 = *(u8*)(v0 + 4668);
	v0 = 0;
	if (v1 != 0)
		goto loc_000097BC;

loc_00009794:		
	ra = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000097BC:		
	v0 = sub_00009B3C(...);
	s1 = v0;
	a1 = v0;
	a3 = 0;
	t1 = s3;
	t2 = s4;
	t0 = s2;
	t3 = s5;
	a0 = s6;
	a2 = s0;
	v0 = 0;
	if ((s32)s1 < 0)
		goto loc_00009794;
	v0 = sub_00009E44(...);
	s0 = v0;
	a0 = s6;
	a1 = s1;
	v0 = sub_00009C1C(...);
	v0 = s0;
	goto loc_00009794;
	sp = sp - 48;
	*(s32*)(sp + 28) = s7;
	v0 = 0x00000;
	t3 = t3 & 0xFF;
	*(s32*)(sp + 24) = s6;
	s7 = a0;
	s6 = t2;
	*(s32*)(sp + 20) = s5;
	s5 = t1;
	*(s32*)(sp + 16) = s4;
	s4 = t0;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	a2 = t3;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 4) = s1;
	v1 = *(u8*)(v0 + 4668);
	v0 = 0;
	if (v1 != 0)
		goto loc_00009898;

loc_0000986C:		
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_00009898:		
	v0 = sub_00009B3C(...);
	s1 = v0;
	a1 = v0;
	t0 = s3;
	t1 = s4;
	t2 = s5;
	t3 = s6;
	a3 = s2;
	a0 = s7;
	a2 = s0;
	v0 = 0;
	if ((s32)s1 < 0)
		goto loc_0000986C;
	v0 = sub_00009E44(...);
	s0 = v0;
	a0 = s7;
	a1 = s1;
	v0 = sub_00009C1C(...);
	v0 = s0;
	goto loc_0000986C;
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	v0 = 0x00000;
	s5 = a3;
	*(s32*)(sp + 16) = s4;
	s4 = a2;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 0) = s0;
	s0 = t0 & 0xFF;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 4) = s1;
	v1 = *(u8*)(v0 + 4668);
	v0 = 0;
	if (v1 != 0)
		goto loc_00009954;

loc_00009930:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00009954:		
	v0 = sceKernelGetSystemTimeLow(...);
	a0 = s2;
	a1 = s3;
	a2 = s0;
	v0 = sub_00009B3C(...);
	s1 = v0;
	a1 = v0;
	t0 = s5;
	a0 = s2;
	a2 = s3;
	a3 = s4;
	v0 = 0;
	if ((s32)s1 < 0)
		goto loc_00009930;
	v0 = sub_00009FEC(...);
	s0 = v0;
	a0 = s2;
	a1 = s1;
	v0 = sub_00009C1C(...);
	v0 = sceKernelGetSystemTimeLow(...);
	v0 = s0;
	goto loc_00009930;
	v0 = 0;
	return (v0);
	sp = sp - 16;
	a1 = a3;
	*(s32*)(sp + 0) = ra;
	a0 = t0;
	v0 = sub_000099DC(...);
	ra = *(s32*)(sp + 0);

loc_000099D8:		
	sp = sp + 16;
	return (v0);
}

sub_000099DC(...) // at 0x000099DC 
{
	v0 = 1;
	*(s8*)(a0 + 16) = v0;
	sp = sp - 16;
	a2 = 255;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 284;
	v0 = onesegSal_E37427BE(...);
	v0 = 0;
	*(s8*)(s0 + 539) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00009A18(...) // at 0x00009A18 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	a1 = 1;
	s2 = a0;
	a2 = 1;
	a0 = a0 + 796;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = sceHttpCreateTemplate(...);
	s1 = v0;
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009AA0;
	v0 = sceHttpDisableAuth(...);
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_00009AB8;
	a0 = s1;
	v0 = sceHttpDisableCookie(...);
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_00009AB8;
	a0 = s1;
	v0 = sceHttpEnableCache(...);
	a1 = 0x10000;
	s0 = v0;
	a0 = s1;
	a1 = a1 - 26180;
	a2 = s2;
	if ((s32)v0 < 0)
		goto loc_00009AB8;
	a0 = s1;
	v0 = sceHttpSetRedirectCallback(...);
	v0 = s1;

loc_00009AA0:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00009AB8:		
	v0 = sceHttpDeleteTemplate(...);
	v0 = s0;
	goto loc_00009AA0;
	v0 = a0;
	v1 = a1;
	t1 = a2;
	t2 = a3;
	sp = sp - 16;
	a0 = t0;
	a1 = v0;
	a2 = v1;
	a3 = t1;
	*(s32*)(sp + 0) = ra;
	t0 = t2;
	v0 = sub_00009B04(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00009B04(...) // at 0x00009B04 
{
	sp = sp - 16;
	v0 = 6;
	*(s32*)(sp + 0) = ra;
	if (a3 == v0)
		goto loc_00009B20;

loc_00009B14:		
	ra = *(s32*)(sp + 0);

loc_00009B18:		
	sp = sp + 16;
	return (v0);

loc_00009B20:		
	v0 = *(s32*)(a0 + 12);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009B14;
	v0 = sceHttpAbortRequest(...);
	ra = *(s32*)(sp + 0);
	goto loc_00009B18;
}

sub_00009B3C(...) // at 0x00009B3C 
{
	v0 = -1;
	*(s32*)(a0 + 12) = v0;
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a2 & 0xFF;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a0;
	v0 = sceWlanGetSwitchState(...);
	v1 = -1;
	if (v0 == 0)
		goto loc_00009C10;
	v0 = *(s32*)(s0 + 8);
	a0 = s0;
	if ((s32)v0 < 0)
		goto loc_00009BF4;

loc_00009B7C:		
	a0 = *(s32*)(s0 + 8);
	*(s8*)(s0 + 16) = 0;
	a2 = (u32)0 < (u32)s1;
	a1 = s2;
	v0 = sceHttpCreateConnectionWithURL(...);
	a0 = 0x10000;
	s1 = v0;
	a0 = a0 - 25912;
	a1 = s0;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00009BD8;
	v0 = sceNetApctlAddHandler(...);
	*(s32*)(s0 + 4) = v0;
	a0 = s0 + 28;
	a2 = 255;
	a1 = s2;
	v1 = -1;
	if ((s32)v0 < 0)
		goto loc_00009BD8;
	v0 = onesegSal_E37427BE(...);
	*(s8*)(s0 + 283) = 0;
	v1 = s1;

loc_00009BD8:		
	ra = *(s32*)(sp + 12);

loc_00009BDC:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00009BF4:		
	v0 = sub_00009A18(...);
	*(s32*)(s0 + 8) = v0;
	v1 = v0;
	if ((s32)v0 >= 0)
		goto loc_00009B7C;
	ra = *(s32*)(sp + 12);
	goto loc_00009BDC;

loc_00009C10:		
	v0 = -260;
	*(s32*)(s0 + 24) = v0;
	goto loc_00009BD8;
}

sub_00009C1C(...) // at 0x00009C1C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = a1;
	*(s32*)(sp + 4) = ra;
	if ((s32)a1 <= 0)
		goto loc_00009C3C;
	v0 = sceHttpDeleteConnection(...);

loc_00009C3C:		
	v0 = *(s32*)(s0 + 4);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00009C50;
	v0 = sceNetApctlDelHandler(...);

loc_00009C50:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00009C60(...) // at 0x00009C60 
{
	sp = sp - 112;
	*(s32*)(sp + 92) = s3;
	a0 = sp;
	s3 = sp + 48;
	*(s32*)(sp + 88) = s2;
	v0 = 0;
	s2 = sp + 64;
	*(s32*)(sp + 84) = s1;
	s1 = a1;
	a1 = a2;
	*(s32*)(sp + 96) = ra;
	*(s32*)(sp + 80) = s0;
	if (a2 == 0)
		goto loc_00009D2C;
	v0 = 0x00000;
	v0 = v0 + 0;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = 0;
	v0 = sub_00019DB4(...);
	a1 = sp + 32;
	a0 = sp;
	a2 = 0;
	a3 = 1;
	v0 = 58;
	*(s8*)(sp + 32) = v0;
	v0 = sub_00019E04(...);
	a3 = v0;
	a0 = s3;
	a1 = sp;
	a2 = 0;
	s0 = v0;
	v0 = sub_00019D58(...);
	a3 = *(s32*)(sp + 4);
	s0 = s0 + 1;
	a2 = s0;
	a3 = a3 - s0;
	a0 = s2;
	a1 = sp;
	v0 = sub_00019D58(...);
	a1 = *(s32*)(sp + 48);
	a2 = *(s32*)(sp + 64);
	a3 = 0;
	a0 = s1;
	v0 = sceHttpAddExtraHeader(...);
	a0 = s2;
	s0 = v0;
	v0 = sub_00019D28(...);

loc_00009D18:		
	a0 = s3;
	v0 = sub_00019D28(...);
	a0 = sp;
	v0 = sub_00019D28(...);
	v0 = s0;

loc_00009D2C:		
	ra = *(s32*)(sp + 96);
	s3 = *(s32*)(sp + 92);
	s2 = *(s32*)(sp + 88);
	s1 = *(s32*)(sp + 84);
	s0 = *(s32*)(sp + 80);
	sp = sp + 112;
	return (v0);
}

sub_00009D48(...) // at 0x00009D48 
{
	sp = sp - 48;
	*(s32*)(sp + 24) = s2;
	s2 = a1;
	a1 = sp;
	*(s32*)(sp + 36) = s5;
	s5 = a0;
	a0 = s2;
	*(s32*)(sp + 32) = s4;
	s4 = a3;
	*(s32*)(sp + 28) = s3;
	s3 = a2;
	*(s32*)(sp + 40) = ra;

loc_00009D78:		
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	v0 = sceHttpGetContentLength(...);
	if (v0 != 0)
	{
		s0 = 0x40000;
		goto loc_00009DB4;
	}
	v0 = *(s32*)(sp + 4);
	if (v0 != 0)
	{
		s0 = 0x40000;
		goto loc_00009DB4;
	}
	s0 = *(s32*)(sp + 0);
	if (v0 != 0)
		goto loc_00009DB4;
	v0 = *(s32*)(sp + 0);
	v0 = (u32)v0 < (u32)29;
	s0 = 0x40000;
	if (v0 == 0)
		goto loc_00009DB4;
	s0 = *(s32*)(sp + 0);

loc_00009DB4:		
	a0 = s0;
	v0 = onesegSal_456203B0(...);
	s1 = v0;
	v0 = 0;
	if (s1 == 0)
		goto loc_00009E04;
	v0 = 0;
	v1 = 0;
	a0 = s2;
	a2 = s0;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = v1;
	a1 = s1;
	v0 = sceHttpReadData(...);
	if ((s32)v0 < 0)
	{
		a1 = v0;
		goto loc_00009E28;
	}
	if (s3 == 0)
	{
		v0 = 1;
		goto loc_00009E04;
	}
	*(s32*)(s3 + 0) = s1;
	*(s32*)(s4 + 0) = v0;
	v0 = 1;

loc_00009E04:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00009E28:		
	a0 = s5;
	v0 = sub_0000A268(...);
	*(s32*)(s5 + 24) = v0;
	a0 = s1;
	v0 = onesegSal_BF12FF51(...);
	v0 = 0;
	goto loc_00009E04;
}

sub_00009E44(...) // at 0x00009E44 
{
	sp = sp - 64;
	v1 = (s32)t1 >> 31;
	*(s32*)(sp + 16) = s0;
	s0 = t1;
	t1 = v1;
	*(s32*)(sp + 36) = s5;
	s5 = t0;
	t0 = s0;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	a0 = a1;
	a1 = 1;
	*(s32*)(sp + 44) = s7;
	s7 = t2;
	*(s32*)(sp + 40) = s6;
	s6 = t3;
	*(s32*)(sp + 32) = s4;
	s4 = a3;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 52) = ra;

loc_00009E98:		
	*(s32*)(sp + 48) = fp;
	v0 = sceHttpCreateRequestWithURL(...);
	v1 = 0x00000;
	s1 = v0;
	v0 = v1 + 4632;
	s3 = v0 + 4;
	a2 = 0;
	a0 = s3;
	a1 = 1;
	if ((s32)s1 < 0)
		goto loc_00009FB8;
	fp = 0x00000;
	v0 = sceKernelLockLwMutex(...);
	*(s32*)(s2 + 12) = s1;
	a0 = s3;
	a1 = 1;
	v0 = 0x00000;
	*(s32*)(sp + 0) = 0;
	*(s32*)(v0 + 216) = s1;
	v0 = sceKernelUnlockLwMutex(...);
	a2 = s4;
	a0 = s2;
	a1 = s1;
	v0 = sub_00009C60(...);
	cond = (v0 != 0);
	v0 = *(u8*)(fp + 4668);
	if (cond)
		goto loc_00009F40;
	a3 = s0;
	a2 = s5;
	a0 = s2;
	a1 = s1;
	if (v0 == 0)
		goto loc_00009F40;
	v0 = sub_0000A14C(...);
	cond = ((s32)v0 < 0);
	v0 = *(u8*)(fp + 4668);
	if (cond)
		goto loc_00009F40;
	a3 = s6;
	a2 = s7;
	a0 = s2;
	a1 = s1;
	if (v0 == 0)
		goto loc_00009F40;

loc_00009F38:		
	v0 = sub_00009D48(...);
	*(s32*)(sp + 0) = v0;

loc_00009F40:		
	v1 = 0x00000;
	s0 = v1 + 4632;
	s0 = s0 + 4;
	a1 = 1;
	a2 = 0;
	a0 = s0;
	v0 = sceKernelLockLwMutex(...);
	v1 = -1;
	*(s32*)(s2 + 12) = v1;
	a0 = s1;
	v0 = 0x00000;
	*(s32*)(v0 + 216) = v1;
	v0 = sceHttpDeleteRequest(...);
	a0 = s0;
	a1 = 1;
	v0 = sceKernelUnlockLwMutex(...);
	v1 = *(s32*)(sp + 0);

loc_00009F84:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);

loc_00009FA0:		
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 64;
	return (v0);

loc_00009FB8:		
	a1 = s1;
	a0 = s2;
	v0 = sub_0000A268(...);
	v1 = 0;
	*(s32*)(s2 + 24) = v0;
	goto loc_00009F84;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = a1;
	v0 = onesegSal_BF12FF51(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00009FEC(...) // at 0x00009FEC 
{
	sp = sp - 48;
	*(s32*)(sp + 16) = s4;
	s4 = t0;
	t0 = 0;
	t1 = 0;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = a1;
	a1 = 0;
	*(s32*)(sp + 28) = s7;
	s7 = 0x00000;
	*(s32*)(sp + 24) = s6;
	s6 = 0x00000;
	*(s32*)(sp + 20) = s5;
	s5 = 0x00000;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = fp;
	v0 = sceHttpCreateRequestWithURL(...);
	s1 = v0;
	v0 = s6 + 4632;
	s0 = v0 + 4;
	a2 = 0;

loc_0000A054:		
	a0 = s0;

loc_0000A058:		
	a1 = 1;
	if ((s32)s1 < 0)
		goto loc_0000A134;
	fp = 0;
	v0 = sceKernelLockLwMutex(...);
	*(s32*)(s2 + 12) = s1;
	a0 = s0;
	a1 = 1;
	*(s32*)(s7 + 216) = s1;
	v0 = sceKernelUnlockLwMutex(...);
	v0 = *(u8*)(s5 + 4668);
	a3 = 0;
	a0 = s2;
	a1 = s1;
	a2 = 0;
	if (v0 == 0)
		goto loc_0000A0C4;
	v0 = sub_0000A14C(...);
	cond = ((s32)v0 < 0);
	v0 = *(u8*)(s5 + 4668);
	if (cond)
		goto loc_0000A0C4;
	a3 = s4;
	a2 = s3;
	a0 = s2;
	a1 = s1;
	if (v0 == 0)
		goto loc_0000A0C4;
	v0 = sub_00009D48(...);
	fp = v0;

loc_0000A0C4:		
	s0 = s6 + 4632;
	s0 = s0 + 4;
	a1 = 1;
	a2 = 0;
	a0 = s0;
	v0 = sceKernelLockLwMutex(...);
	v1 = -1;
	*(s32*)(s2 + 12) = v1;
	a0 = s1;
	*(s32*)(s7 + 216) = v1;
	v0 = sceHttpDeleteRequest(...);
	a0 = s0;
	a1 = 1;
	v0 = sceKernelUnlockLwMutex(...);
	v1 = fp;

loc_0000A100:		
	ra = *(s32*)(sp + 36);
	fp = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);

loc_0000A124:		
	s0 = *(s32*)(sp + 0);
	v0 = v1;

loc_0000A130:		
	sp = sp + 48;
	return (v0);

loc_0000A134:		
	a1 = s1;
	a0 = s2;
	v0 = sub_0000A268(...);
	v1 = 0;
	*(s32*)(s2 + 24) = v0;
	goto loc_0000A100;
}

sub_0000A14C(...) // at 0x0000A14C 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = a1;
	*(s32*)(sp + 20) = s1;
	s1 = a3;
	*(s32*)(sp + 16) = s0;
	s0 = a2;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	v0 = sceKernelGetSystemTimeLow(...);
	a1 = s0;
	a0 = s3;
	a2 = s1;
	v0 = sceHttpSendRequest(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000A230;
	v0 = sceKernelGetSystemTimeLow(...);
	a0 = s3;
	a1 = sp + 4;
	v0 = sceHttpGetStatusCode(...);
	v1 = *(s32*)(sp + 4);
	v0 = 200;
	*(s32*)(s2 + 20) = v1;
	if (v1 != v0)
		goto loc_0000A208;
	a0 = s3;
	a1 = sp + 8;
	a2 = sp + 12;
	v0 = sceHttpGetAllHeader(...);
	s0 = v0;
	v0 = 0;
	if (s0 != 0)
		goto loc_0000A1EC;
	v1 = *(u8*)(s2 + 16);
	v0 = s2 + 28;
	a1 = s2 + 284;
	if (v1 == 0)
		a1 = v0;
	a0 = s2 + 540;
	v0 = onesegSal_12F99955(...);
	v0 = 0;

loc_0000A1EC:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_0000A208:		
	v0 = 401;
	cond = (v1 == v0);
	v0 = -120;
	if (cond)
		goto loc_0000A228;
	v0 = 407;
	if (v1 == v0)
	{
		v0 = -401;
		goto loc_0000A228;
	}

loc_0000A220:		
	v0 = -1;
	goto loc_0000A1EC;

loc_0000A228:		
	*(s32*)(s2 + 24) = v0;
	goto loc_0000A220;

loc_0000A230:		
	a0 = s2;
	a1 = v0;
	v0 = sub_0000A268(...);
	v1 = 0x80430000;
	v1 = v1 | 0x1063;
	*(s32*)(s2 + 24) = v0;
	if (s0 == v1)
		goto loc_0000A254;

loc_0000A24C:		
	v0 = s0;
	goto loc_0000A1EC;

loc_0000A254:		
	a0 = s3;
	a1 = sp;
	v0 = sceHttpGetNetworkPspError(...);
	s0 = v0;
	goto loc_0000A24C;
}

sub_0000A268(...) // at 0x0000A268 
{
	NONE;
	v0 = 65;
	a0 = -500;
	if (v1 == v0)
		goto loc_0000A2EC;

loc_0000A278:		
	v0 = 0x80410000;
	v0 = v0 | 0xA08;
	v0 = (s32)v0 < (s32)a1;
	cond = (v0 != 0);
	v0 = 0x80430000;
	if (cond)
		goto loc_0000A2B8;
	v0 = 0x80410000;

loc_0000A290:		
	v0 = v0 | 0xA05;
	v0 = (s32)a1 < (s32)v0;
	if (v0 == 0)
	{
		a0 = -260;
		goto loc_0000A2B0;
	}
	v0 = 0x80410000;
	v0 = v0 | 0x40E;

loc_0000A2A8:		
	if (a1 == v0)
	{
		a0 = -260;
		goto loc_0000A2B0;
	}

loc_0000A2B0:		
	v0 = a0;
	return (v0);

loc_0000A2B8:		
	v0 = v0 | 0x1068;
	if (a1 == v0)
	{
		a0 = -250;
		goto loc_0000A2B0;
	}
	v0 = (s32)v0 < (s32)a1;
	cond = (v0 != 0);
	v0 = 0x80430000;
	if (cond)
		goto loc_0000A2D8;
	v0 = v0 | 0x1063;
	goto loc_0000A2A8;

loc_0000A2D8:		
	v0 = v0 | 0x1075;
	if (a1 == v0)
	{
		a0 = -300;
		goto loc_0000A2B0;
	}
	goto loc_0000A2B0;

loc_0000A2EC:		
	NONE;
	v0 = v0 ^ 0x4;
	v1 = -100;
	if (v0 == 0)
		a0 = v1;
	goto loc_0000A278;
	sp = sp - 16;
	a0 = 1;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_00005924(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a0 = 0;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_00005924(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_40A76362(...) // at 0x0000A340 
{
	v0 = 0x00000;
	v0 = v0 + 4672;
	v1 = 31;

loc_0000A34C:		
	v1 = v1 - 1;
	*(s8*)(v0 + 0) = 0;
	*(s32*)(v0 + 4) = 0;
	*(s32*)(v0 + 8) = 0;
	*(s8*)(v0 + 12) = 0;
	*(s32*)(v0 + 16) = 0;
	*(s32*)(v0 + 20) = 0;
	*(s32*)(v0 + 24) = 0;
	*(s8*)(v0 + 28) = 0;
	v0 = v0 + 32;
	if ((s32)v1 >= 0)
		goto loc_0000A34C;
	v0 = 0x00000;
	a0 = v0 + 5696;
	*(s32*)(v0 + 5696) = 0;
	v1 = 0x00000;
	v0 = 0;
	*(s32*)(a0 + 4) = 0;
	*(s32*)(v1 + 5704) = 0;
	return (v0);
}

onesegCore_6C74C2C1(...) // at 0x0000A398 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	v0 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = 31;
	*(s32*)(sp + 0) = s0;
	s0 = v0 + 4672;

loc_0000A3B4:		
	v0 = *(s32*)(s0 + 4);
	s1 = s1 - 1;
	a0 = v0;
	if (v0 != 0)
		goto loc_0000A434;

loc_0000A3C4:		
	a0 = *(s32*)(s0 + 16);
	*(s32*)(s0 + 8) = 0;
	if (a0 == 0)
		goto loc_0000A3DC;
	v0 = *(u8*)(s0 + 28);
	if (v0 == 0)
		goto loc_0000A424;

loc_0000A3DC:		
	*(s32*)(s0 + 20) = 0;
	s0 = s0 + 32;
	if ((s32)s1 >= 0)
		goto loc_0000A3B4;
	s0 = 0x00000;
	a0 = *(s32*)(s0 + 5696);
	s1 = s0 + 5696;
	if (a0 != 0)
		goto loc_0000A410;

loc_0000A3F8:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000A410:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4) = 0;
	*(s32*)(s0 + 5696) = 0;
	goto loc_0000A3F8;

loc_0000A424:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 16) = 0;
	goto loc_0000A3DC;

loc_0000A434:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 4) = 0;
	goto loc_0000A3C4;
}

sub_0000A444(...) // at 0x0000A444 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a1 = 1;
	a0 = *(s32*)(v0 + 4228);
	a2 = 0;
	v0 = sceKernelWaitSema(...);
	v1 = 0;
	if (v0 != 0)
		goto loc_0000A478;
	v1 = 1;
	v0 = 0x00000;
	*(s8*)(v0 + 5728) = v1;
	v1 = 1;

loc_0000A478:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000A488(...) // at 0x0000A488 
{
	v1 = 0x00000;
	v0 = *(u8*)(v1 + 5728);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 1;
	if (v0 != 0)
		goto loc_0000A4AC;
	ra = *(s32*)(sp + 0);

loc_0000A4A4:		
	sp = sp + 16;
	return (v0);

loc_0000A4AC:		
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 4228);
	*(s8*)(v1 + 5728) = 0;
	v0 = sceKernelSignalSema(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000A4A4;
}

sub_0000A4C4(...) // at 0x0000A4C4 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	v0 = 0x00000;
	a0 = a0 << 5;
	*(s32*)(sp + 4) = s1;
	s2 = a1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	v0 = v0 + 4672;
	s0 = a0 + v0;
	a0 = 0;
	if (v1 == 0)
		goto loc_0000A524;
	v0 = *(u8*)(s0 + 0);
	ra = *(s32*)(sp + 12);
	if (v0 != 0)
		goto loc_0000A528;
	v0 = *(s32*)(s0 + 4);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000A540;
	*(s32*)(s0 + 8) = s1;

loc_0000A51C:		
	a0 = 1;
	*(s32*)(s0 + 4) = s2;

loc_0000A524:		
	ra = *(s32*)(sp + 12);

loc_0000A528:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);

loc_0000A540:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 8) = s1;
	goto loc_0000A51C;
}

sub_0000A550(...) // at 0x0000A550 
{
	v0 = 0x00000;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	a0 = a0 << 5;
	v0 = v0 + 4672;
	a0 = a0 + v0;
	a3 = 0;
	if (v1 == 0)
		goto loc_0000A58C;
	v1 = *(s32*)(a0 + 4);
	if (v1 == 0)
		goto loc_0000A58C;
	v0 = *(s32*)(a0 + 8);
	*(s32*)(a1 + 0) = v1;
	a3 = 1;
	*(s32*)(a2 + 0) = v0;

loc_0000A58C:		
	v0 = a3;
	return (v0);
}

sub_0000A594(...) // at 0x0000A594 
{
	v0 = 0x00000;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	a0 = a0 << 5;
	v0 = v0 + 4672;
	a0 = a0 + v0;
	t0 = 0;
	if (v1 == 0)
		goto loc_0000A5CC;
	v1 = *(s32*)(a0 + 16);
	if (v1 == 0)
		goto loc_0000A5CC;

loc_0000A5C0:		
	v0 = *(s32*)(a0 + 24);

loc_0000A5C8:		
	if (v0 == a1)
	{
		v0 = *(s32*)(a0 + 20);
		goto loc_0000A5D4;
	}

loc_0000A5CC:		
	v0 = t0;
	return (v0);

loc_0000A5D4:		
	*(s32*)(a2 + 0) = v1;
	t0 = 1;
	*(s32*)(a3 + 0) = v0;
	goto loc_0000A5CC;
}

sub_0000A5E4(...) // at 0x0000A5E4 
{
	sp = sp - 32;

loc_0000A5E8:		
	*(s32*)(sp + 20) = s5;
	v0 = 0x00000;
	s5 = 0x00000;
	*(s32*)(sp + 16) = s4;
	v1 = s5 + 4672;
	s4 = a1;

loc_0000A600:		
	*(s32*)(sp + 12) = s3;
	a1 = 0;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = t0 & 0xFF;
	*(s32*)(sp + 0) = s0;
	s0 = a0 << 5;
	*(s32*)(sp + 24) = ra;
	t1 = *(u8*)(v0 + 5728);
	a0 = s0 + v1;
	if (t1 == 0)
		goto loc_0000A674;
	v0 = *(u8*)(a0 + 12);
	v1 = a0 + 16;
	if (v0 != 0)
		goto loc_0000A674;
	a0 = *(s32*)(a0 + 16);
	v0 = s5 + 4672;
	if (a0 == 0)
		goto loc_0000A65C;
	v0 = *(u8*)(v1 + 12);
	if (v0 == 0)
		goto loc_0000A69C;
	v0 = s5 + 4672;

loc_0000A65C:		
	v0 = s0 + v0;
	*(s8*)(v0 + 28) = s1;
	a1 = 1;
	*(s32*)(v0 + 16) = s2;
	*(s32*)(v0 + 20) = s3;
	*(s32*)(v0 + 24) = s4;

loc_0000A674:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);

loc_0000A684:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a1;
	sp = sp + 32;
	return (v0);

loc_0000A69C:		
	v0 = scePaf_412B2F09(...);
	v0 = s5 + 4672;
	goto loc_0000A65C;
}

sub_0000A6AC(...) // at 0x0000A6AC 
{
	v0 = 0x00000;
	v0 = v0 + 4672;
	a0 = a0 << 5;
	a0 = a0 + v0;
	v0 = *(u8*)(a0 + 0);
	return (v0);
}

sub_0000A6C4(...) // at 0x0000A6C4 
{
	v0 = 0x00000;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	v0 = v0 + 4672;
	a0 = a0 << 5;
	a0 = a0 + v0;
	a1 = a1 & 0xFF;
	v0 = 0;
	if (v1 == 0)
		goto loc_0000A6F0;
	*(s8*)(a0 + 0) = a1;
	v0 = 1;

loc_0000A6F0:		
	return (v0);
}

sub_0000A6F8(...) // at 0x0000A6F8 
{
	v0 = 0x00000;
	v0 = v0 + 4672;
	a0 = a0 << 5;
	a0 = a0 + v0;
	v0 = *(u8*)(a0 + 12);
	return (v0);
}

sub_0000A710(...) // at 0x0000A710 
{
	v0 = 0x00000;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	v0 = v0 + 4672;
	a0 = a0 << 5;
	a0 = a0 + v0;
	a1 = a1 & 0xFF;
	v0 = 0;
	if (v1 == 0)
		goto loc_0000A73C;
	*(s8*)(a0 + 12) = a1;
	v0 = 1;

loc_0000A73C:		
	return (v0);
}

sub_0000A744(...) // at 0x0000A744 
{
	v0 = 0x00000;
	v1 = *(u8*)(v0 + 5728);
	v0 = 0x00000;
	v0 = v0 + 4672;
	a0 = a0 << 5;
	a0 = a0 + v0;
	a2 = a1;
	v0 = 0x80000000;
	if (v1 == 0)
		goto loc_0000A7A4;
	a0 = *(s32*)(a0 + 4);
	a1 = a0 + 48;
	if (a0 == 0)
		goto loc_0000A7A4;
	v0 = *(u8*)(a0 + 48);
	v1 = *(u8*)(a1 + 1);
	a0 = *(u8*)(a1 + 2);
	v0 = v0 << 24;
	a1 = *(u8*)(a1 + 3);
	v1 = v1 << 16;
	v0 = v0 | v1;
	a0 = a0 << 8;
	v0 = v0 | a0;
	v0 = v0 | a1;
	*(s32*)(a2 + 0) = v0;
	v0 = 0;

loc_0000A7A4:		
	return (v0);
}

onesegCore_9CCCDEC9(...) // at 0x0000A7AC 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	a1 = 4296;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	a1 = s1;
	a0 = v0;
	v0 = sub_0000AE40(...);
	*(s32*)(s2 + 0) = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_F180B994(...) // at 0x0000A800 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = *(s32*)(a0 + 0);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000A820;
	ra = *(s32*)(sp + 0);

loc_0000A818:		
	sp = sp + 16;
	return (v0);

loc_0000A820:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000A818;
}

onesegCore_97541756(...) // at 0x0000A838 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 0);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000A85C;
	v0 = sub_0000C464(...);
	v1 = v0;

loc_0000A85C:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_4B824B94(...) // at 0x0000A86C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 0);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000A890;
	v0 = sub_0000B5D0(...);
	v1 = v0;

loc_0000A890:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_DCBD8E67(...) // at 0x0000A8A0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 0);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000A8C4;
	v0 = sub_0000B694(...);
	v1 = v0;

loc_0000A8C4:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000A8D4(...) // at 0x0000A8D4 
{
	v0 = 0x70000;
	v1 = -1;
	v0 = v0 - 16176;
	*(s32*)(a0 + 4) = v1;
	*(s32*)(a0 + 0) = v0;
	return (v0);
}

sub_0000A8EC(...) // at 0x0000A8EC 
{
	v0 = 0x70000;
	v0 = v0 - 16176;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16176;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16176;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_E6E45D08(...) // at 0x0000A938 
{
	sp = sp - 16;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	v0 = sub_0000A8D4(...);
	v0 = 0x70000;
	v0 = v0 - 16192;
	*(s32*)(s1 + 0) = v0;
	a0 = 0;
	a1 = 4464;
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	a1 = s2;
	a0 = v0;
	v0 = sub_0000B440(...);
	*(s32*)(s1 + 8) = s0;
	*(s32*)(s1 + 4) = 0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;

loc_0000A9B0:		
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16192;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000A9E0;

loc_0000A9C8:		
	a0 = s0;
	v0 = sub_0000A8EC(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000A9E0:		
	v0 = *(s32*)(v1 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	goto loc_0000A9C8;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16192;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000AA44;

loc_0000AA20:		
	a0 = s0;
	v0 = sub_0000A8EC(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000AA44:		
	v0 = *(s32*)(v1 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	goto loc_0000AA20;
}

onesegCore_12A155DA(...) // at 0x0000AA5C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AA84;
	v0 = sub_0000C71C(...);
	v1 = v0;

loc_0000AA84:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000AA94(...) // at 0x0000AA94 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AABC;
	v0 = sub_0000D33C(...);
	v1 = v0;

loc_0000AABC:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_F5B421BF(...) // at 0x0000AACC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AAF4;
	v0 = sub_0000D60C(...);
	v1 = v0;

loc_0000AAF4:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_8EE48A7F(...) // at 0x0000AB04 
{
	sp = sp - 16;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	v0 = sub_0000A8D4(...);
	v0 = 0x70000;
	v0 = v0 - 16208;
	*(s32*)(s2 + 0) = v0;
	a0 = 0;
	a1 = 4312;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a0 = v0;
	a1 = s0;
	v0 = sub_0000B3A0(...);
	*(s32*)(s2 + 8) = s1;
	if (s1 == 0)
		goto loc_0000AB5C;
	v0 = 1;
	*(s32*)(s2 + 4) = v0;

loc_0000AB5C:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16208;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000ABB4;

loc_0000AB9C:		
	a0 = s0;
	v0 = sub_0000A8EC(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000ABB4:		
	v0 = *(s32*)(v1 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	goto loc_0000AB9C;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = v0 - 16208;
	v1 = *(s32*)(a0 + 8);
	*(s32*)(s0 + 0) = v0;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000AC18;

loc_0000ABF4:		
	a0 = s0;
	v0 = sub_0000A8EC(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000AC18:		
	v0 = *(s32*)(v1 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	goto loc_0000ABF4;
}

onesegCore_BFDBA62B(...) // at 0x0000AC30 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AC58;
	v0 = sub_0000D040(...);
	v1 = v0;

loc_0000AC58:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000AC68(...) // at 0x0000AC68 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AC90;
	v0 = sub_0000DD20(...);
	v1 = v0;

loc_0000AC90:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_5E203223(...) // at 0x0000ACA0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000ACC8;
	v0 = sub_0000DF98(...);
	v1 = v0;

loc_0000ACC8:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_643115FB(...) // at 0x0000ACD8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AD00;
	v0 = sub_0000D698(...);
	v1 = v0;

loc_0000AD00:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_7E5F333D(...) // at 0x0000AD10 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AD38;
	v0 = sub_0000DAC0(...);
	v1 = v0;

loc_0000AD38:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_2C480A6E(...) // at 0x0000AD48 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000AD70;
	v0 = sub_0000D8A0(...);
	v1 = v0;

loc_0000AD70:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_6BCB80D7(...) // at 0x0000AD80 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000ADA8;
	v0 = sub_0000DB5C(...);
	v1 = v0;

loc_0000ADA8:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_42C968BD(...) // at 0x0000ADB8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000ADE0;
	v0 = sub_0000DCDC(...);
	v1 = v0;

loc_0000ADE0:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000ADF0(...) // at 0x0000ADF0 
{
	v1 = 0x70000;
	a2 = -1;
	v1 = v1 - 16224;
	*(s32*)(a0 + 0) = v1;
	sp = sp - 16;
	*(s32*)(a0 + 4288) = a2;
	*(s8*)(a0 + 4292) = 0;
	*(s8*)(a0 + 84) = 0;
	*(s16*)(a0 + 88) = 0;
	*(s8*)(a0 + 90) = 0;
	*(s8*)(a0 + 4264) = 0;
	*(s32*)(a0 + 4276) = a2;
	*(s32*)(a0 + 4280) = a2;
	*(s32*)(a0 + 4284) = 0;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0000E114(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000AE40(...) // at 0x0000AE40 
{
	v1 = 0x70000;
	a2 = -1;
	v1 = v1 - 16224;
	*(s32*)(a0 + 0) = v1;
	sp = sp - 16;
	*(s32*)(a0 + 4288) = a2;
	*(s8*)(a0 + 4292) = 0;
	*(s8*)(a0 + 84) = 0;
	*(s16*)(a0 + 88) = 0;
	*(s8*)(a0 + 90) = 0;
	*(s8*)(a0 + 4264) = 0;
	*(s32*)(a0 + 4276) = a2;
	*(s32*)(a0 + 4280) = a2;
	*(s32*)(a0 + 4284) = 0;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0000E114(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000AE90(...) // at 0x0000AE90 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	v0 = v0 - 16224;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v1 = *(u8*)(a0 + 4264);
	*(s32*)(a0 + 0) = v0;
	if (v1 != 0)
		goto loc_0000AEC0;
	v0 = *(s32*)(a0 + 4188);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000AED8;

loc_0000AEC0:		
	a0 = s0;
	v0 = sub_0000E218(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000AED8:		

loc_0000AEDC:		
	v0 = scePaf_412B2F09(...);
	goto loc_0000AEC0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	v0 = v0 - 16224;

loc_0000AEF8:		
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v1 = *(u8*)(a0 + 4264);
	*(s32*)(a0 + 0) = v0;
	if (v1 != 0)
		goto loc_0000AF18;
	v0 = *(s32*)(a0 + 4188);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000AF30;

loc_0000AF18:		
	a0 = s0;
	v0 = sub_0000E218(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000AF30:		
	v0 = scePaf_412B2F09(...);
	goto loc_0000AF18;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x70000;
	v0 = v0 - 16224;

loc_0000AF50:		
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v1 = *(u8*)(a0 + 4264);
	*(s32*)(a0 + 0) = v0;
	if (v1 != 0)
		goto loc_0000AF70;

loc_0000AF64:		
	v0 = *(s32*)(a0 + 4188);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000AF94;

loc_0000AF70:		
	a0 = s0;
	v0 = sub_0000E218(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000AF94:		
	v0 = scePaf_412B2F09(...);
	goto loc_0000AF70;
}

sub_0000AFA4(...) // at 0x0000AFA4 
{
	sp = sp - 112;
	*(s32*)(sp + 108) = ra;
	*(s32*)(sp + 104) = s2;
	s2 = 0;
	*(s32*)(sp + 100) = s1;
	s1 = a1;
	*(s32*)(sp + 96) = s0;
	s0 = a2;
	a1 = sp;

loc_0000AFC8:		
	a0 = s1;
	v0 = sceIoGetstat(...);
	cond = (v0 != 0);
	v0 = 0;
	if (cond)
		goto loc_0000B000;
	v0 = *(s32*)(sp + 4);
	v0 = v0 & 0x18;
	cond = (v0 != 0);
	v0 = 0;
	if (cond)
		goto loc_0000B000;
	v0 = *(s32*)(sp + 8);
	*(s32*)(s0 + 0) = v0;
	if (v0 != 0)
		goto loc_0000AFFC;
	if (s2 == 0)
		goto loc_0000B018;

loc_0000AFFC:		
	v0 = 1;

loc_0000B000:		
	ra = *(s32*)(sp + 108);
	s2 = *(s32*)(sp + 104);
	s1 = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	sp = sp + 112;
	return (v0);

loc_0000B018:		
	s2 = 1;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	a1 = 0;
	v0 = sceIoSync(...);
	a1 = sp;
	goto loc_0000AFC8;
}

sub_0000B034(...) // at 0x0000B034 
{
	sp = sp - 112;
	a0 = a1;
	*(s32*)(sp + 96) = ra;
	a1 = sp;
	v0 = sceIoGetstat(...);
	v1 = 1;
	if (v0 != 0)
		goto loc_0000B060;
	v0 = *(s32*)(sp + 4);
	v0 = v0 & 0x10;
	ra = *(s32*)(sp + 96);
	if (v0 != 0)
		goto loc_0000B068;

loc_0000B060:		
	v1 = 0;
	ra = *(s32*)(sp + 96);

loc_0000B068:		
	v0 = v1;
	sp = sp + 112;
	return (v0);
}

sub_0000B074(...) // at 0x0000B074 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	v0 = sub_0000E0FC(...);
	s0 = v0;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	v0 = onesegSal_3B70E875(...);
	a2 = v0;
	a0 = s1;
	a1 = s0;
	v0 = onesegSal_00850EAA(...);
	v1 = 0;
	if (v0 != 0)
		goto loc_0000B0C8;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	v0 = onesegSal_3B70E875(...);
	v1 = s1 + v0;

loc_0000B0C8:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000B0E0(...) // at 0x0000B0E0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 47;
	s0 = a1 + 1;
	*(s32*)(sp + 4) = ra;
	a0 = s0;
	a2 = 8;
	v1 = *(s8*)(a1 + 0);
	a1 = 0x70000;
	a1 = a1 - 17112;	// "MPE_ROOT"
	a3 = 0;
	if (v1 != v0)
		goto loc_0000B124;
	v0 = onesegSal_00850EAA(...);
	v1 = s0 + 8;
	a3 = 0;
	if (v0 == 0)
		a3 = v1;

loc_0000B124:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a3;
	sp = sp + 16;
	return (v0);
}

sub_0000B138(...) // at 0x0000B138 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	v0 = 47;
	s2 = a0;
	*(s32*)(sp + 0) = s0;
	a3 = 0;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v1 = *(s8*)(a1 + 0);
	s0 = a1 + 1;
	if (v1 != v0)
		goto loc_0000B1F0;
	v1 = *(s8*)(s0 + 0);
	v0 = 49;
	s0 = s0 + 1;
	if (v1 != v0)
		goto loc_0000B1F0;
	v0 = *(s8*)(s0 + 0);
	s0 = s0 + 1;
	v1 = v0 << 2;
	v1 = v1 + v0;
	v0 = v0 - 48;
	v1 = v1 << 1;
	v0 = (u32)v0 < (u32)10;
	v1 = v1 + 32;
	if (v0 == 0)
		goto loc_0000B1F0;
	v0 = *(u8*)(s0 + 0);
	s1 = v1 & 0xFF;
	v1 = s1 + v0;
	v0 = v0 - 48;
	v1 = v1 - 48;
	v0 = v0 & 0xFF;
	s1 = v1 & 0xFF;
	v0 = (u32)v0 < (u32)10;
	v1 = (u32)s1 < (u32)32;
	if (v0 == 0)
		goto loc_0000B1F0;
	s0 = s0 + 1;
	a1 = 0x70000;
	a1 = a1 - 17100;
	a2 = 5;
	a0 = s0;
	if (v1 == 0)
		goto loc_0000B1F0;
	v0 = onesegSal_00850EAA(...);
	a3 = 0;
	if (v0 != 0)
		goto loc_0000B1F0;

loc_0000B1E8:		
	*(s8*)(s2 + 84) = s1;

loc_0000B1EC:		
	a3 = s0 + 5;

loc_0000B1F0:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a3;
	sp = sp + 16;
	return (v0);
}

sub_0000B20C(...) // at 0x0000B20C 
{
	sp = sp - 32;
	*(s32*)(sp + 8) = s2;
	v0 = 47;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	a2 = 0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 0) = s0;
	v1 = *(s8*)(a1 + 0);
	s1 = a0;
	if (v1 == v0)
		goto loc_0000B26C;

loc_0000B244:		
	ra = *(s32*)(sp + 24);

loc_0000B248:		
	s5 = *(s32*)(sp + 20);

loc_0000B24C:		
	s4 = *(s32*)(sp + 16);

loc_0000B250:		
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 32;
	return (v0);

loc_0000B26C:		
	s0 = a1 + 1;
	a1 = 0x70000;
	a2 = 3;
	a1 = a1 - 17076;
	a0 = s0;
	v0 = onesegSal_00850EAA(...);
	a2 = 0;
	if (v0 != 0)
		goto loc_0000B244;
	s0 = s0 + 3;
	a1 = *(u8*)(s0 + 0);
	a0 = (s8)a1;
	v1 = a0 - 65;
	v1 = v1 & 0xFF;
	v0 = a0 - 48;
	v0 = (u32)v0 < (u32)10;
	v1 = (u32)v1 < (u32)26;
	v0 = v0 | v1;
	if (v0 != 0)
	{
		s0 = s0 + 1;
		goto loc_0000B2C8;
	}
	v0 = 95;
	ra = *(s32*)(sp + 24);
	if (a0 != v0)
		goto loc_0000B248;
	s0 = s0 + 1;

loc_0000B2C8:		
	s4 = *(s8*)(s0 + 0);
	s5 = (s8)a1;
	v0 = s4 - 48;

loc_0000B2D4:		
	v0 = (u32)v0 < (u32)10;
	a2 = 0;
	if (v0 == 0)
		goto loc_0000B244;
	s0 = s0 + 1;
	a0 = *(s8*)(s0 + 0);
	v0 = a0 - 48;
	v0 = (u32)v0 < (u32)10;
	ra = *(s32*)(sp + 24);
	if (v0 == 0)
		goto loc_0000B248;
	v1 = 100;
	asm("mult       $a0, $v1");
	s0 = s0 + 1;
	a0 = *(s8*)(s0 + 0);
	asm("mflo       $v1");
	v0 = a0 - 48;
	v1 = v1 - 4800;
	v0 = (u32)v0 < (u32)10;
	s3 = v1 & 0xFFFF;
	if (v0 == 0)
		goto loc_0000B248;
	s0 = s0 + 1;
	a1 = *(u8*)(s0 + 0);
	v0 = a0 << 2;
	v0 = v0 + a0;
	v0 = v0 << 1;
	v1 = a1 - 48;
	v0 = s3 + v0;
	v1 = v1 & 0xFF;
	v0 = v0 - 480;
	v1 = (u32)v1 < (u32)10;
	s3 = v0 & 0xFFFF;
	if (v1 == 0)
		goto loc_0000B248;
	s0 = s0 + 1;
	v0 = (s8)a1;
	v0 = v0 + s3;
	v1 = *(s8*)(s0 + 0);
	v0 = v0 - 48;
	s3 = v0 & 0xFFFF;
	v0 = 46;
	if (v1 != v0)
	{
		s5 = *(s32*)(sp + 20);
		goto loc_0000B24C;
	}
	s0 = s0 + 1;
	a0 = s0;
	a1 = s2;
	v0 = onesegSal_BABF0A73(...);
	a2 = 0;
	if (v0 != 0)
		goto loc_0000B244;
	*(s16*)(s1 + 88) = s3;
	a2 = 1;
	*(s8*)(s1 + 85) = s5;
	*(s8*)(s1 + 86) = s4;
	goto loc_0000B244;
}

sub_0000B3A0(...) // at 0x0000B3A0 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = sub_0000ADF0(...);
	v0 = 0x70000;
	v0 = v0 - 16240;
	*(s32*)(s0 + 0) = v0;
	*(s32*)(s0 + 4304) = 0;
	*(s32*)(s0 + 4296) = 0;
	*(s32*)(s0 + 4300) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16240;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0000AE90(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16240;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000AE90(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000B440(...) // at 0x0000B440 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;

loc_0000B44C:		
	s0 = a0;
	v0 = sub_0000ADF0(...);
	v0 = 0x70000;
	v0 = v0 - 16256;
	*(s32*)(s0 + 0) = v0;
	*(s32*)(s0 + 4456) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16256;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0000AE90(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16256;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000AE90(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000B4D8(...) // at 0x0000B4D8 
{
	sp = sp - 48;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	a0 = a1;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	s3 = a2 & 0xFF;
	*(s32*)(sp + 20) = s1;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	v0 = onesegSal_3B70E875(...);
	s0 = v0;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	v0 = onesegSal_3B70E875(...);
	v0 = v0 + 31;
	v1 = 0x80000000;
	a2 = sp;
	a0 = s2;
	a1 = s1;
	v1 = v1 | 0x4;
	if (s0 != v0)
		goto loc_0000B5B0;
	v0 = sub_0000AFA4(...);
	a1 = s1;
	if (v0 == 0)
		goto loc_0000B5A8;
	a0 = s2;
	if (s3 == 0)
		goto loc_0000B558;
	v0 = *(s32*)(sp + 0);
	v0 = (u32)v0 < (u32)64;
	v1 = 0x80000000;
	if (v0 != 0)
		goto loc_0000B5AC;

loc_0000B558:		
	v0 = sub_0000B074(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B5A8;
	v0 = sub_0000B0E0(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B5A8;
	v0 = sub_0000B138(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B5A8;
	a2 = 0x70000;
	a2 = a2 - 17088;
	v0 = sub_0000B20C(...);
	v1 = 0;
	if (v0 != 0)
		goto loc_0000B5B0;

loc_0000B5A8:		
	v1 = 0x80000000;

loc_0000B5AC:		
	v1 = v1 | 0x4;

loc_0000B5B0:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);
}

sub_0000B5D0(...) // at 0x0000B5D0 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = a1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	v0 = onesegSal_3B70E875(...);
	s1 = v0;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	v0 = onesegSal_3B70E875(...);
	v0 = v0 + 31;
	v1 = 0x80000000;
	a1 = s0;
	a0 = s2;
	v1 = v1 | 0x4;
	if (s1 != v0)
		goto loc_0000B678;
	v0 = sub_0000B074(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B670;
	v0 = sub_0000B0E0(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B670;
	v0 = sub_0000B138(...);
	a2 = 0x70000;
	a2 = a2 - 17080;
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B670;
	v0 = sub_0000B20C(...);
	v1 = 0;
	if (v0 != 0)
		goto loc_0000B678;

loc_0000B670:		
	v1 = 0x80000000;
	v1 = v1 | 0x4;

loc_0000B678:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000B694(...) // at 0x0000B694 
{
	sp = sp - 48;
	*(s32*)(sp + 40) = s2;
	s2 = a1;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 16) = 0;
	v0 = sub_0000BBC4(...);
	s1 = v0;
	a0 = s0;
	a1 = v0;
	a2 = 1;
	s0 = 0x80000000;
	if (v0 == 0)
		goto loc_0000B750;
	v0 = sub_0000B4D8(...);
	s0 = v0;
	t2 = sp;
	a0 = s1;
	a1 = 1;
	a2 = sp + 16;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	if ((s32)v0 < 0)
		goto loc_0000B750;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	a3 = 0;
	a2 = 24;
	t0 = 0;
	t1 = sp;
	if ((s32)v0 < 0)
		goto loc_0000B750;
	a0 = *(s32*)(sp + 16);
	v0 = onesegSal_950E5178(...);
	s0 = v0;
	a1 = s2;
	a2 = 24;
	a3 = sp;
	if ((s32)v0 < 0)
		goto loc_0000B744;
	a0 = *(s32*)(sp + 16);
	v0 = onesegSal_8A14C632(...);
	s0 = v0;

loc_0000B744:		
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);

loc_0000B750:		
	v0 = s0;
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);
}

sub_0000B76C(...) // at 0x0000B76C 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = a1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_3B70E875(...);
	s0 = v0;
	v0 = sub_0000E0FC(...);
	a0 = v0;
	v0 = onesegSal_3B70E875(...);
	v0 = v0 + 18;
	v1 = 0x80000000;
	a0 = s2;
	a1 = s1;
	v1 = v1 | 0x4;
	if (s0 != v0)
		goto loc_0000B804;
	v0 = sub_0000B034(...);
	a0 = s2;
	a1 = s1;
	if (v0 == 0)
		goto loc_0000B820;
	v0 = sub_0000B074(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B820;
	v0 = sub_0000B0E0(...);
	a1 = v0;
	a0 = s2;
	if (v0 == 0)
		goto loc_0000B820;
	v0 = sub_0000B138(...);
	v1 = 0;
	if (v0 == 0)
		goto loc_0000B820;

loc_0000B804:		
	ra = *(s32*)(sp + 12);

loc_0000B808:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_0000B820:		
	v1 = 0x80000000;
	v1 = v1 | 0x4;
	goto loc_0000B804;
}

sub_0000B82C(...) // at 0x0000B82C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = a0;
	v0 = sub_0000E0FC(...);
	a3 = v0;
	t3 = *(u16*)(s0 + 88);
	t0 = *(u8*)(s0 + 84);
	t1 = *(u8*)(s0 + 85);
	t2 = *(u8*)(s0 + 86);
	a2 = 0x70000;
	s0 = s0 + 91;	// '['
	v0 = 0x70000;
	a0 = s0;
	v0 = v0 - 17092;	// "MGL"
	a2 = a2 - 17072;	// "%s/MPE_ROOT/1%02dAET01/TAQ%c%c%03d.%s"
	a1 = 4096;
	*(s32*)(sp + 0) = v0;
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000B88C(...) // at 0x0000B88C 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	v0 = sub_0000B82C(...);
	a1 = v0;
	a0 = s0;
	a2 = sp;
	v0 = sub_0000AFA4(...);
	v1 = 0;
	if (v0 == 0)
		goto loc_0000B8C4;
	v0 = *(s32*)(sp + 0);
	ra = *(s32*)(sp + 20);
	if (v0 != 0)
		goto loc_0000B8D0;

loc_0000B8C4:		
	v1 = 0x80000000;
	v1 = v1 | 0x8;
	ra = *(s32*)(sp + 20);

loc_0000B8D0:		
	s0 = *(s32*)(sp + 16);

loc_0000B8D4:		
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_0000B8E0(...) // at 0x0000B8E0 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	s2 = s1 + 91;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1 & 0xFF;
	v0 = sub_0000E0FC(...);
	a3 = v0;
	a2 = 0x70000;
	v0 = 255;
	a1 = 4096;
	a2 = a2 - 17032;	// "%s/MPE_ROOT/1%02dAET01/MLST1%02d%1X.MSF"
	a0 = s2;
	t0 = *(u8*)(s1 + 84);
	t2 = s0;
	if (s0 == v0)
		goto loc_0000B94C;

loc_0000B928:		
	t1 = t0;
	v0 = onesegSal_433AC527(...);
	v0 = s2;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000B94C:		
	t2 = *(u8*)(s1 + 90);
	goto loc_0000B928;
}

sub_0000B954(...) // at 0x0000B954 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	t1 = a0;
	v0 = a1 & 0xFF;
	*(s32*)(sp + 4) = ra;
	a2 = 0x70000;

loc_0000B96C:		
	s0 = a0 + 91;
	v1 = 255;
	a1 = 4096;
	a2 = a2 - 16992;	// "MLST1%02d%1X.MSF"
	t0 = v0;
	a0 = s0;
	a3 = *(u8*)(t1 + 84);
	if (v0 == v1)
		goto loc_0000B9A8;

loc_0000B98C:		
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000B9A8:		
	t0 = *(u8*)(t1 + 90);
	goto loc_0000B98C;
}

sub_0000B9B0(...) // at 0x0000B9B0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000E0FC(...);
	a2 = 0x70000;
	t0 = *(u8*)(s0 + 84);
	s0 = s0 + 91;
	a3 = v0;
	a0 = s0;
	a2 = a2 - 16972;	//"%s/MPE_ROOT/1%02dAET01"
	a1 = 4096;
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 4);

loc_0000B9EC:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000B9F8(...) // at 0x0000B9F8 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x80000000;
	s1 = s1 | 0x8;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 4288);
	s0 = a0;
	if ((s32)v0 < 0)
		goto loc_0000BA24;
	v0 = sub_0000BA58(...);

loc_0000BA24:		
	a0 = s0;
	v0 = sub_0000B9B0(...);
	a0 = v0;
	v0 = sceIoDopen(...);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s1 = 0;
	*(s32*)(s0 + 4288) = v0;
	v0 = s1;

loc_0000BA44:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000BA58(...) // at 0x0000BA58 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 4288);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000BA7C;
	v0 = sceIoDclose(...);

loc_0000BA7C:		
	v1 = -1;
	*(s32*)(s0 + 4288) = v1;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000BA98(...) // at 0x0000BA98 
{
	sp = sp - 384;
	*(s32*)(sp + 376) = s6;
	v1 = 255;
	s6 = 255;
	*(s32*)(sp + 372) = s5;
	s5 = 12;
	*(s32*)(sp + 368) = s4;
	s4 = 255;
	*(s32*)(sp + 364) = s3;
	s3 = 0x70000;
	*(s32*)(sp + 360) = s2;
	s2 = a0;
	*(s32*)(sp + 380) = ra;
	*(s32*)(sp + 356) = s1;
	*(s32*)(sp + 352) = s0;
	v0 = *(s32*)(a0 + 4288);
	*(s32*)(sp + 344) = 0;
	if ((s32)v0 < 0)
		goto loc_0000BB78;
	a0 = *(s32*)(s2 + 4288);

loc_0000BAE4:		
	a1 = sp;
	v0 = sceIoDread(...);
	cond = ((s32)v0 <= 0);
	v0 = *(s32*)(sp + 12);
	if (cond)
		goto loc_0000BB74;
	s1 = sp + 88;
	if ((s32)v0 <= 0)
		goto loc_0000BBAC;

loc_0000BAFC:		
	a0 = s1;
	a1 = s3 - 16916;

loc_0000BB08:		
	a2 = 4;
	v0 = onesegSal_00850EAA(...);
	if (v0 == 0)
		goto loc_0000BB24;

loc_0000BB14:		
	a0 = 0;
	v0 = onesegSal_FB5FE576(...);
	a0 = *(s32*)(s2 + 4288);
	goto loc_0000BAE4;

loc_0000BB24:		
	a0 = s1;
	v0 = onesegSal_3B70E875(...);
	s0 = 0;
	if (v0 != s5)
		goto loc_0000BB14;

loc_0000BB34:		
	s4 = 255;
	a1 = s0;

loc_0000BB3C:		
	a0 = s2;
	v0 = sub_0000B954(...);
	a0 = v0;
	a1 = s1;
	a2 = 12;
	v0 = onesegSal_00850EAA(...);
	v1 = s0 + 1;
	if (v0 == 0)
		goto loc_0000BBA4;
	s0 = v1 & 0xFF;
	v0 = (u32)s0 < (u32)16;
	a1 = s0;
	if (v0 != 0)
		goto loc_0000BB3C;

loc_0000BB6C:		
	if (s4 == s6)
		goto loc_0000BB14;

loc_0000BB74:		
	v1 = s4;

loc_0000BB78:		
	ra = *(s32*)(sp + 380);
	s6 = *(s32*)(sp + 376);
	s5 = *(s32*)(sp + 372);
	s4 = *(s32*)(sp + 368);
	s3 = *(s32*)(sp + 364);
	s2 = *(s32*)(sp + 360);
	s1 = *(s32*)(sp + 356);
	s0 = *(s32*)(sp + 352);
	v0 = v1;
	sp = sp + 384;
	return (v0);

loc_0000BBA4:		
	s4 = s0;
	goto loc_0000BB6C;

loc_0000BBAC:		
	cond = (v0 != 0);
	v0 = *(s32*)(sp + 8);
	if (cond)
		goto loc_0000BB14;
	if (v0 == 0)
		goto loc_0000BB14;
	s1 = sp + 88;
	goto loc_0000BAFC;
}

sub_0000BBC4(...) // at 0x0000BBC4 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = a0;
	v0 = sub_0000E0FC(...);
	a3 = v0;
	t3 = *(u16*)(s0 + 88);
	t0 = *(u8*)(s0 + 84);
	t1 = *(u8*)(s0 + 85);
	t2 = *(u8*)(s0 + 86);
	a2 = 0x70000;
	s0 = s0 + 91;
	v0 = 0x70000;
	a0 = s0;
	v0 = v0 - 17088;
	a2 = a2 - 17072;
	a1 = 4096;
	*(s32*)(sp + 0) = v0;
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000BC24(...) // at 0x0000BC24 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = a0;
	v0 = sub_0000E0FC(...);
	a3 = v0;
	t3 = *(u16*)(s0 + 88);
	t0 = *(u8*)(s0 + 84);
	t1 = *(u8*)(s0 + 85);
	t2 = *(u8*)(s0 + 86);
	a2 = 0x70000;
	s0 = s0 + 91;
	v0 = 0x70000;
	a0 = s0;
	v0 = v0 - 17084;
	a2 = a2 - 17072;
	a1 = 4096;
	*(s32*)(sp + 0) = v0;
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000BC84(...) // at 0x0000BC84 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	s0 = s0 + 91;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	v0 = sub_0000E0FC(...);
	a2 = 0x70000;
	a3 = v0;
	t0 = s1;
	a0 = s0;
	a2 = a2 - 16948;	// "%s/MPE_ROOT/%08X.MSF"
	a1 = 4096;
	v0 = onesegSal_433AC527(...);
	v0 = s0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000BCD8(...) // at 0x0000BCD8 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	v0 = sub_0000BC84(...);
	a1 = v0;

loc_0000BCF0:		
	a0 = s0;
	a2 = sp;
	v0 = sub_0000AFA4(...);
	v1 = 0;
	if (v0 == 0)
		goto loc_0000BD10;
	v0 = *(s32*)(sp + 0);
	ra = *(s32*)(sp + 20);
	if (v0 != 0)
		goto loc_0000BD1C;

loc_0000BD10:		
	v1 = 0x80000000;
	v1 = v1 | 0x8;
	ra = *(s32*)(sp + 20);

loc_0000BD1C:		
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_0000BD2C(...) // at 0x0000BD2C 
{
	sp = sp - 176;
	*(s32*)(sp + 152) = s2;
	a1 = 255;
	s2 = a0;
	*(s32*)(sp + 160) = ra;
	*(s32*)(sp + 148) = s1;
	*(s32*)(sp + 144) = s0;
	s0 = 0;
	*(s32*)(sp + 156) = s3;
	v0 = sub_0000B8E0(...);
	a1 = sp + 112;
	a0 = *(u8*)(s2 + 84);
	a2 = sp + 116;
	s1 = v0;
	*(s32*)(sp + 112) = 0;
	v0 = sub_0000A550(...);
	s3 = sp + 96;
	if (v0 == 0)
		goto loc_0000BD94;

loc_0000BD74:		
	v0 = s0;

loc_0000BD78:		
	ra = *(s32*)(sp + 160);
	s3 = *(s32*)(sp + 156);
	s2 = *(s32*)(sp + 152);
	s1 = *(s32*)(sp + 148);
	s0 = *(s32*)(sp + 144);
	sp = sp + 176;
	return (v0);

loc_0000BD94:		
	a0 = s1;
	a2 = sp + 120;
	a1 = 1;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = s3;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000BD74;
	a0 = *(s32*)(sp + 120);
	a2 = 0;
	a3 = 0;
	t0 = 2;
	t1 = s3;
	v0 = onesegSal_950E5178(...);
	a0 = *(s32*)(sp + 120);
	if ((s32)v0 < 0)
		goto loc_0000BE08;
	a1 = sp + 128;
	a2 = s3;
	v0 = onesegSal_099DBC39(...);
	v1 = *(s32*)(sp + 128);
	if ((s32)v0 < 0)
		goto loc_0000BE08;
	v0 = 16048;
	a0 = *(s32*)(sp + 120);
	if (v1 != v0)
		goto loc_0000BE0C;
	v0 = *(s32*)(sp + 132);
	t0 = 0;
	if (v0 == 0)
		goto loc_0000BE20;

loc_0000BE08:		
	a0 = *(s32*)(sp + 120);

loc_0000BE0C:		
	a1 = s3;
	v0 = onesegSal_9CBB0F5D(...);
	v0 = 0x80000000;
	v0 = v0 | 0x8;
	goto loc_0000BD78;

loc_0000BE20:		
	a2 = 0;
	a3 = 0;
	t1 = s3;
	*(s32*)(sp + 116) = v1;
	v0 = onesegSal_950E5178(...);
	a1 = *(s32*)(sp + 116);
	if ((s32)v0 < 0)
		goto loc_0000BE08;
	a0 = 16;
	v0 = scePaf_0C2CD696(...);
	*(s32*)(sp + 112) = v0;
	if (v0 == 0)
		goto loc_0000BEC4;
	a0 = *(s32*)(sp + 120);
	a2 = *(s32*)(sp + 116);
	a1 = v0;
	a3 = s3;
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000BE84;
	a0 = *(s32*)(sp + 112);
	a1 = 0x70000;
	a1 = a1 - 16916;	// "MLST"
	a2 = 4;
	v0 = onesegSal_6DEC6268(...);
	s0 = 0x80000000;
	if (v0 == 0)
		goto loc_0000BEA8;

loc_0000BE84:		
	a0 = *(s32*)(sp + 120);

loc_0000BE88:		
	a1 = s3;
	v0 = onesegSal_9CBB0F5D(...);
	if ((s32)s0 >= 0)
	{
		v0 = s0;
		goto loc_0000BD78;
	}
	a0 = *(s32*)(sp + 112);
	v0 = scePaf_412B2F09(...);
	v0 = s0;
	goto loc_0000BD78;

loc_0000BEA8:		
	a0 = *(u8*)(s2 + 84);
	a1 = *(s32*)(sp + 112);
	a2 = *(s32*)(sp + 116);
	s0 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(s32*)(sp + 120);
	goto loc_0000BE88;

loc_0000BEC4:		
	a0 = *(s32*)(sp + 120);
	a1 = s3;
	v0 = onesegSal_9CBB0F5D(...);
	v0 = 0x80000000;
	v0 = v0 | 0x2;
	goto loc_0000BD78;
}

sub_0000BEDC(...) // at 0x0000BEDC 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 44) = s3;
	s3 = a0;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	v0 = sub_0000B82C(...);
	a0 = v0;
	a2 = sp + 16;
	a1 = 1;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C098;
	a0 = *(s32*)(sp + 16);
	a2 = 0;
	a3 = 0;
	t0 = 2;
	t1 = sp;
	v0 = onesegSal_950E5178(...);
	a0 = *(s32*)(sp + 16);
	if ((s32)v0 < 0)
		goto loc_0000BF84;
	s1 = sp + 24;
	a1 = s1;
	a2 = sp;
	v0 = onesegSal_099DBC39(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 28);
	if (cond)
		goto loc_0000BF84;

loc_0000BF5C:		
	if ((s32)v0 <= 0)
		goto loc_0000C0E4;
	a1 = *(s32*)(s1 + 4);

loc_0000BF68:		
	a0 = *(s32*)(sp + 16);
	if ((s32)a1 > 0)
		goto loc_0000BF88;
	s2 = *(s32*)(sp + 24);
	if (a1 != 0)
		goto loc_0000BFB8;
	v0 = (u32)s2 < (u32)4673;
	if (v0 != 0)
		goto loc_0000BFB8;

loc_0000BF84:		
	a0 = *(s32*)(sp + 16);

loc_0000BF88:		
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	v0 = 0x80000000;
	v0 = v0 | 0x8;

loc_0000BF98:		
	ra = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 64;
	return (v0);
	a0 = *(s32*)(sp + 16);

loc_0000BFB8:		
	a2 = 0;
	a3 = 0;
	t0 = 0;
	t1 = sp;
	v0 = onesegSal_950E5178(...);
	cond = ((s32)v0 < 0);
	v0 = 1;
	if (cond)
		goto loc_0000BF84;
	v1 = *(u8*)(s3 + 4264);
	if (v1 == v0)
	{
		*(s8*)(s3 + 4264) = 0;
		goto loc_0000C0D8;
	}

loc_0000BFE0:		
	a0 = 16;
	a1 = s2;
	v0 = scePaf_0C2CD696(...);
	s1 = v0;
	if (v0 == 0)
		goto loc_0000C0C0;
	a0 = *(s32*)(sp + 16);
	a1 = v0;
	a2 = s2;
	a3 = sp;
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C084;
	a1 = 0x70000;
	a1 = a1 - 16924;	// "LICS"
	a0 = s1;
	a2 = 4;
	v0 = onesegSal_6DEC6268(...);
	s0 = 0x80000000;
	if (v0 != 0)
		goto loc_0000C084;
	a0 = *(s32*)(s3 + 4188);
	if (a0 == 0)
	{
		*(s32*)(s3 + 4188) = s1;
		goto loc_0000C048;
	}
	v0 = *(u8*)(s3 + 4264);
	if (v0 == 0)
		goto loc_0000C0B0;
	*(s32*)(s3 + 4188) = s1;

loc_0000C048:		
	v1 = s1 + 8;
	s0 = 0;
	v0 = *(u8*)(s1 + 8);
	a0 = *(u8*)(v1 + 1);
	a1 = *(u8*)(v1 + 2);
	a2 = *(u8*)(v1 + 3);
	v0 = v0 << 24;
	a0 = a0 << 16;
	v0 = v0 | a0;
	a1 = a1 << 8;
	v0 = v0 | a1;
	v0 = v0 | a2;
	*(s32*)(s3 + 4296) = v0;
	*(s32*)(s3 + 4192) = s2;
	*(s8*)(s3 + 4264) = 0;

loc_0000C084:		
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	if ((s32)s0 < 0)
		goto loc_0000C0A0;

loc_0000C098:		
	v0 = s0;
	goto loc_0000BF98;

loc_0000C0A0:		
	a0 = s1;
	v0 = scePaf_412B2F09(...);
	v0 = s0;
	goto loc_0000BF98;

loc_0000C0B0:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s3 + 4188) = s1;
	goto loc_0000C048;

loc_0000C0C0:		
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	v0 = 0x80000000;
	v0 = v0 | 0x2;
	goto loc_0000BF98;

loc_0000C0D8:		
	*(s32*)(s3 + 4188) = 0;
	*(s32*)(s3 + 4192) = 0;
	goto loc_0000BFE0;

loc_0000C0E4:		
	s2 = *(s32*)(sp + 24);
	if (v0 != 0)
		goto loc_0000BF84;
	v0 = (u32)s2 < (u32)17;
	a0 = *(s32*)(sp + 16);
	if (v0 != 0)
		goto loc_0000BF88;
	a1 = *(s32*)(s1 + 4);
	goto loc_0000BF68;
}

sub_0000C100(...) // at 0x0000C100 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = ra;
	*(s32*)(sp + 52) = s5;
	s5 = a2;
	*(s32*)(sp + 48) = s4;
	s4 = a3;
	*(s32*)(sp + 44) = s3;
	s3 = a1;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	v0 = sub_0000BC84(...);
	a0 = v0;
	a2 = sp + 16;
	a1 = 1;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C1B4;
	a0 = *(s32*)(sp + 16);
	a2 = 0;
	a3 = 0;
	t0 = 2;
	t1 = sp;
	v0 = onesegSal_950E5178(...);
	a0 = *(s32*)(sp + 16);
	if ((s32)v0 < 0)
		goto loc_0000C2CC;
	s1 = sp + 24;
	a1 = s1;
	a2 = sp;
	v0 = onesegSal_099DBC39(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C2CC;
	v0 = *(s32*)(sp + 28);
	if ((s32)v0 <= 0)
		goto loc_0000C2E4;
	a1 = *(s32*)(s1 + 4);

loc_0000C1A0:		
	if ((s32)a1 <= 0)
		goto loc_0000C1DC;

loc_0000C1A8:		
	a0 = *(s32*)(sp + 16);

loc_0000C1AC:		
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);

loc_0000C1B4:		
	v0 = s0;

loc_0000C1B8:		
	ra = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 64;
	return (v0);

loc_0000C1DC:		
	s2 = *(s32*)(sp + 24);
	if (a1 != 0)
		goto loc_0000C1F0;
	v0 = (u32)s2 < (u32)16385;
	a0 = *(s32*)(sp + 16);
	if (v0 == 0)
		goto loc_0000C1AC;

loc_0000C1F0:		
	a0 = *(s32*)(sp + 16);
	a2 = 0;
	a3 = 0;
	t0 = 0;
	t1 = sp;
	v0 = onesegSal_950E5178(...);
	a0 = 16;
	if ((s32)v0 < 0)
		goto loc_0000C2CC;
	a1 = s2;
	v0 = scePaf_0C2CD696(...);
	s1 = v0;
	v0 = 0x80000000;
	v0 = v0 | 0x2;
	if (s1 == 0)
		goto loc_0000C1B8;
	a0 = *(s32*)(sp + 16);
	a1 = s1;
	a2 = s2;
	a3 = sp;
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C294;
	a1 = 0x70000;
	a1 = a1 - 16908;	// "EKB2"
	a0 = s1;
	a2 = 4;
	v0 = onesegSal_6DEC6268(...);
	if (v0 != 0)
	{
		*(s32*)(s5 + 0) = 0;
		goto loc_0000C2C4;
	}
	a0 = s1 + 32;
	v0 = *(u8*)(s1 + 32);
	v1 = *(u8*)(a0 + 1);
	a1 = *(u8*)(a0 + 2);
	v0 = v0 << 24;
	v1 = v1 << 16;
	a2 = *(u8*)(a0 + 3);
	v0 = v0 | v1;
	a1 = a1 << 8;
	v0 = v0 | a1;
	v0 = v0 | a2;
	if (v0 == s3)
	{
		s0 = 0;
		goto loc_0000C2B8;
	}

loc_0000C294:		
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	if ((s32)s0 >= 0)
	{
		v0 = s0;
		goto loc_0000C1B8;
	}
	a0 = s1;
	v0 = scePaf_412B2F09(...);
	v0 = s0;
	goto loc_0000C1B8;

loc_0000C2B8:		
	*(s32*)(s4 + 0) = s2;
	*(s32*)(s5 + 0) = s1;
	goto loc_0000C294;

loc_0000C2C4:		
	s0 = 0x80000000;
	goto loc_0000C294;

loc_0000C2CC:		
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);

loc_0000C2D8:		
	v0 = 0x80000000;
	v0 = v0 | 0x8;
	goto loc_0000C1B8;

loc_0000C2E4:		
	s2 = *(s32*)(sp + 24);
	if (v0 != 0)
		goto loc_0000C1A8;
	v0 = (u32)s2 < (u32)76;
	a0 = *(s32*)(sp + 16);
	if (v0 != 0)
		goto loc_0000C1AC;
	a1 = *(s32*)(s1 + 4);
	goto loc_0000C1A0;
}

sub_0000C300(...) // at 0x0000C300 
{
	sp = sp - 64;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;
	s1 = a2;
	a2 = sp + 36;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	a1 = sp + 32;
	a0 = *(u8*)(a0 + 84);
	v0 = sub_0000A550(...);
	v1 = *(s32*)(sp + 36);
	v0 = *(s32*)(sp + 32);
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 4) = v1;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 0) = v0;
	v0 = sub_0000E108(...);
	a0 = v0;
	a1 = *(u8*)(s2 + 84);
	a3 = sp + 16;
	a2 = sp;
	v0 = sceVshBridge_2C2DB18C(...);

loc_0000C360:		
	v1 = v0;
	ra = *(s32*)(sp + 60);
	v0 = 0x80000000;
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v1 = (s32)v1 < (s32)0;
	v0 = v0 | 0x8;
	if (v1 == 0)
		v0 = 0;
	sp = sp + 64;
	return (v0);
}

sub_0000C38C(...) // at 0x0000C38C 
{
	sp = sp - 64;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 56) = s2;
	s2 = a0;
	*(s32*)(sp + 52) = s1;

loc_0000C3A0:		
	s1 = a2;
	a2 = sp + 36;
	*(s32*)(sp + 48) = s0;
	s0 = a1;
	a1 = sp + 32;
	a0 = *(u8*)(a0 + 84);
	v0 = sub_0000A550(...);
	v1 = *(s32*)(sp + 36);
	v0 = *(s32*)(sp + 32);
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 4) = v1;
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 20) = s1;
	v0 = sub_0000E108(...);
	a0 = v0;
	a1 = *(u8*)(s2 + 84);
	a2 = *(u16*)(s2 + 88);
	a3 = s2 + 4188;
	t1 = sp + 16;
	t0 = sp;
	v0 = sceVshBridge_37EFB3B5(...);
	*(s32*)(s2 + 4276) = v0;
	v1 = 0;
	if ((s32)v0 < 0)
		goto loc_0000C41C;

loc_0000C400:		
	ra = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v0 = v1;
	sp = sp + 64;
	return (v0);

loc_0000C41C:		
	v0 = -1;
	*(s32*)(s2 + 4276) = v0;
	v1 = 0x80000000;
	goto loc_0000C400;
}

sub_0000C42C(...) // at 0x0000C42C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 4276);
	v0 = sceVshBridge_34D51F83(...);
	v1 = v0;
	*(s32*)(s0 + 4280) = v1;
	v0 = (s32)v0 < (s32)0;
	v0 = v0 << 31;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000C464(...) // at 0x0000C464 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 4) = 0;
	*(s32*)(sp + 8) = 0;
	v0 = sub_0000B76C(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C570;
	v0 = sub_0000A444(...);
	v1 = 16;

loc_0000C498:		
	*(s8*)(s1 + 90) = v1;
	a0 = s1;
	v0 = sub_0000B9F8(...);

loc_0000C4A8:		
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C560;

loc_0000C4AC:		
	a0 = s1;
	v0 = sub_0000BA98(...);
	v1 = (u32)v0 < (u32)16;
	*(s8*)(s1 + 90) = v0;
	if (v1 == 0)
		goto loc_0000C560;
	a0 = s1;
	v0 = sub_0000BD2C(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C4AC;
	a0 = *(u8*)(s1 + 84);
	a1 = sp;
	v0 = sub_0000A744(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C4AC;
	a1 = *(s32*)(sp + 0);
	a0 = s1;
	v0 = sub_0000BCD8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C5D0;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 0);
	a2 = sp + 4;
	a3 = sp + 8;
	v0 = sub_0000A594(...);
	a1 = *(s32*)(sp + 4);
	if (v0 != 0)
		goto loc_0000C54C;
	a1 = *(s32*)(sp + 0);
	a0 = s1;
	a2 = sp + 4;
	a3 = sp + 8;
	v0 = sub_0000C100(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C5D0;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 0);
	a2 = *(s32*)(sp + 4);
	a3 = *(s32*)(sp + 8);
	t0 = 0;
	v0 = sub_0000A5E4(...);
	a1 = *(s32*)(sp + 4);

loc_0000C54C:		
	a2 = *(s32*)(sp + 8);
	a0 = s1;
	v0 = sub_0000C300(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C588;

loc_0000C560:		
	a0 = s1;
	v0 = sub_0000BA58(...);
	v0 = sub_0000A488(...);

loc_0000C570:		
	v0 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000C588:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a2 = 0;
	a1 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(u8*)(s1 + 84);

loc_0000C5AC:		
	a1 = 0;
	v0 = sub_0000A710(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	v0 = sub_0000A5E4(...);
	goto loc_0000C4AC;

loc_0000C5D0:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;

loc_0000C5E4:		
	a2 = 0;
	v0 = sub_0000A4C4(...);
	goto loc_0000C4AC;
}

sub_0000C5F4(...) // at 0x0000C5F4 
{
	sp = sp - 32;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	v0 = *(s32*)(s1 + 5696);
	*(s32*)(sp + 12) = s3;
	s3 = s1 + 5696;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 8) = s2;
	if (v0 == 0)
		goto loc_0000C640;

loc_0000C620:		
	v0 = s0;

loc_0000C624:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_0000C640:		
	*(s32*)(s3 + 4) = 0;
	*(s32*)(s1 + 5696) = 0;
	v0 = sub_0000E108(...);
	a0 = v0;
	a1 = s3;
	v0 = sceVshBridge_D1B1EFB6(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C710;
	a0 = 16;
	a1 = v0;
	v0 = scePaf_0C2CD696(...);
	s0 = 0x80000000;
	*(s32*)(s1 + 5696) = v0;
	s0 = s0 | 0x2;
	if (v0 != 0)
		goto loc_0000C6A4;
	a0 = *(s32*)(s1 + 5696);

loc_0000C680:		
	s2 = s1 + 5696;
	if (a0 == 0)
		goto loc_0000C620;
	v0 = scePaf_412B2F09(...);
	v0 = 0x00000;
	*(s32*)(s1 + 5696) = 0;
	*(s32*)(s2 + 4) = 0;
	*(s32*)(v0 + 5704) = 0;
	goto loc_0000C620;

loc_0000C6A4:		
	*(s32*)(s3 + 4) = s2;
	v0 = sub_0000E108(...);
	a0 = v0;
	a1 = s3;
	v0 = sceVshBridge_D1B1EFB6(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C6FC;
	a1 = *(s32*)(s1 + 5696);
	a3 = 0x00000;
	*(s32*)(a3 + 5704) = 0;
	v1 = a1 + 32;
	v0 = *(u8*)(a1 + 32);
	a0 = *(u8*)(v1 + 1);
	a1 = *(u8*)(v1 + 2);
	a2 = *(u8*)(v1 + 3);
	v0 = v0 << 24;
	a0 = a0 << 16;
	v0 = v0 | a0;
	a1 = a1 << 8;
	v0 = v0 | a1;
	v0 = v0 | a2;
	*(s32*)(a3 + 5704) = v0;

loc_0000C6FC:		
	s0 = 0;

loc_0000C700:		
	v0 = s0;
	if ((s32)s2 >= 0)
		goto loc_0000C624;
	a0 = *(s32*)(s1 + 5696);
	goto loc_0000C680;

loc_0000C710:		
	s0 = 0x80000000;
	s0 = s0 | 0x8;
	goto loc_0000C700;
}

sub_0000C71C(...) // at 0x0000C71C 
{
	sp = sp - 192;

loc_0000C720:		
	*(s32*)(sp + 180) = s5;
	v0 = 0x00000;
	s5 = 0;

loc_0000C72C:		
	*(s32*)(sp + 176) = s4;
	s4 = 0;
	*(s32*)(sp + 172) = s3;
	s3 = 0;
	*(s32*)(sp + 168) = s2;
	s2 = a1;
	*(s32*)(sp + 164) = s1;
	s1 = a0;
	*(s32*)(sp + 184) = ra;
	*(s32*)(sp + 160) = s0;
	v1 = *(s32*)(v0 + 5708);
	v0 = 0x80000000;
	*(s32*)(sp + 148) = 0;
	v0 = v0 | 0x5;
	*(s32*)(sp + 152) = 0;
	if ((s32)v1 <= 0)
		goto loc_0000CA00;
	v0 = sub_0000C5F4(...);
	a1 = s2;
	if ((s32)v0 < 0)
		goto loc_0000CA00;
	a0 = s1;
	a2 = 0;
	v0 = sub_0000B4D8(...);
	ra = *(s32*)(sp + 184);
	if ((s32)v0 < 0)
		goto loc_0000CA04;
	v0 = sub_0000A444(...);
	v1 = 16;
	*(s8*)(s1 + 90) = v1;
	a0 = s1;
	v0 = sub_0000B9F8(...);
	if ((s32)v0 < 0)
		goto loc_0000C864;

loc_0000C7B0:		
	a0 = s1;
	v0 = sub_0000BA98(...);
	v1 = (u32)v0 < (u32)16;
	*(s8*)(s1 + 90) = v0;
	if (v1 == 0)
		goto loc_0000C864;
	a0 = s1;
	v0 = sub_0000BD2C(...);
	cond = ((s32)v0 < 0);
	s3 = 1;
	if (cond)
		goto loc_0000C7B0;
	a0 = *(u8*)(s1 + 84);
	a1 = sp + 144;
	v0 = sub_0000A744(...);
	a1 = *(s32*)(sp + 144);
	if ((s32)v0 < 0)
		goto loc_0000C7B0;

loc_0000C7EC:		
	a0 = s1;
	v0 = sub_0000BCD8(...);
	a2 = sp + 148;
	if ((s32)v0 < 0)
		goto loc_0000CD60;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 144);
	a3 = sp + 152;
	v0 = sub_0000A594(...);
	a1 = *(s32*)(sp + 148);
	if (v0 != 0)
		goto loc_0000C844;
	a1 = *(s32*)(sp + 144);
	a0 = s1;
	a2 = sp + 148;
	a3 = sp + 152;
	v0 = sub_0000C100(...);
	a1 = *(s32*)(sp + 144);
	if ((s32)v0 < 0)
		goto loc_0000CD34;
	a0 = *(u8*)(s1 + 84);
	a2 = *(s32*)(sp + 148);
	a3 = *(s32*)(sp + 152);
	t0 = 0;
	v0 = sub_0000A5E4(...);
	a1 = *(s32*)(sp + 148);

loc_0000C844:		
	a2 = *(s32*)(sp + 152);
	a0 = s1;
	v0 = sub_0000C300(...);
	if ((s32)v0 < 0)
	{
		a0 = *(u8*)(s1 + 84);
		goto loc_0000CCEC;
	}
	s4 = 1;
	s3 = 0;
	*(s32*)(s1 + 4456) = s4;

loc_0000C864:		
	a0 = s1;
	v0 = sub_0000BA58(...);
	if (s4 != 0)
	{
		v0 = *(u8*)(s1 + 90);
		goto loc_0000CCE0;
	}
	if (s3 != 0)
	{
		a0 = *(s32*)(s1 + 4280);
		goto loc_0000C978;
	}
	s5 = 0;

loc_0000C880:		
	a0 = *(u8*)(s1 + 84);
	if (s4 != 0)
		goto loc_0000CC8C;
	v1 = 0x00000;
	s0 = v1 + 5696;
	v0 = 0x00000;
	a2 = *(s32*)(v1 + 5696);
	a3 = *(s32*)(s0 + 4);
	a1 = *(s32*)(v0 + 5704);
	t0 = 1;
	v0 = sub_0000A5E4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 1;
	v0 = sub_0000A710(...);
	v0 = sub_0000E108(...);
	a1 = *(u8*)(s1 + 84);
	t1 = s0;
	t0 = -1;
	a0 = v0;
	a2 = 0;
	a3 = 0;
	v0 = sceVshBridge_09EBF066(...);
	v0 = sub_0000E108(...);
	a1 = *(u8*)(s1 + 84);
	a0 = v0;
	a2 = 0;
	a3 = 0;
	v0 = sceVshBridge_2C2DB18C(...);
	a0 = 16;
	a1 = 16048;
	v0 = scePaf_0C2CD696(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_0000C974;
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = s0;
	a2 = 16048;
	v0 = sub_0000A4C4(...);
	a0 = s0;

loc_0000C938:		
	a1 = 0;
	a2 = 16048;
	v0 = Kernel_Library_A089ECA4(...);
	v1 = 1;
	*(s32*)(s1 + 4456) = v1;
	a0 = *(s32*)(s1 + 4448);

loc_0000C950:		
	if (a0 != 0)
		goto loc_0000CC7C;

loc_0000C958:		
	a0 = 16;
	a1 = 21056;
	v0 = scePaf_0C2CD696(...);
	*(s32*)(s1 + 4448) = v0;
	if (v0 != 0)
		goto loc_0000CA90;

loc_0000C96C:		
	*(s32*)(s1 + 4448) = 0;
	*(s32*)(s1 + 4452) = 0;

loc_0000C974:		
	a0 = *(s32*)(s1 + 4280);

loc_0000C978:		
	s0 = -1;
	if (a0 == s0)
	{
		a0 = *(s32*)(s1 + 4276);
		goto loc_0000C994;
	}
	v0 = sceVshBridge_6F20A6DE(...);
	*(s32*)(s1 + 4280) = s0;
	a0 = *(s32*)(s1 + 4276);

loc_0000C994:		
	if (a0 == s0)
	{
		v1 = *(s32*)(s1 + 4456);
		goto loc_0000C9AC;
	}
	v0 = sceVshBridge_66810AF1(...);
	*(s32*)(s1 + 4276) = s0;
	v1 = *(s32*)(s1 + 4456);

loc_0000C9AC:		
	v0 = 2;
	if (v1 == v0)
		goto loc_0000CA80;

loc_0000C9B8:		
	s0 = 1;
	if (v1 == s0)
		goto loc_0000CA64;
	v0 = *(u8*)(s1 + 4264);

loc_0000C9C8:		
	if (v0 != 0)
		goto loc_0000CA4C;
	a0 = *(s32*)(s1 + 4188);
	if (a0 != 0)
		goto loc_0000CA38;

loc_0000C9DC:		
	a0 = *(s32*)(s1 + 4448);

loc_0000C9E0:		
	if (a0 != 0)
		goto loc_0000CA24;
	s0 = 0x80000000;

loc_0000C9EC:		
	s0 = s0 | 0x8;
	*(s32*)(s1 + 4456) = 0;

loc_0000C9F4:		
	v0 = sub_0000A488(...);
	v0 = s0;

loc_0000CA00:		
	ra = *(s32*)(sp + 184);

loc_0000CA04:		
	s5 = *(s32*)(sp + 180);
	s4 = *(s32*)(sp + 176);
	s3 = *(s32*)(sp + 172);
	s2 = *(s32*)(sp + 168);
	s1 = *(s32*)(sp + 164);
	s0 = *(s32*)(sp + 160);
	sp = sp + 192;
	return (v0);

loc_0000CA24:		
	s0 = 0x80000000;
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4448) = 0;
	*(s32*)(s1 + 4452) = 0;
	goto loc_0000C9EC;

loc_0000CA38:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4188) = 0;
	*(s32*)(s1 + 4192) = 0;
	goto loc_0000C9DC;

loc_0000CA4C:		
	if (v0 != s0)
	{
		a0 = *(s32*)(s1 + 4448);
		goto loc_0000C9E0;
	}
	*(s32*)(s1 + 4188) = 0;
	*(s32*)(s1 + 4192) = 0;
	*(s8*)(s1 + 4264) = 0;
	goto loc_0000C9DC;

loc_0000CA64:		
	a0 = s1;
	v0 = sub_0000CFF0(...);
	a0 = s1;
	a1 = s5;
	v0 = sub_0000D018(...);
	v0 = *(u8*)(s1 + 4264);
	goto loc_0000C9C8;

loc_0000CA80:		
	a0 = s1;
	v0 = sub_0000CFF0(...);
	v1 = *(s32*)(s1 + 4456);
	goto loc_0000C9B8;

loc_0000CA90:		
	v0 = *(s32*)(s1 + 4268);
	a0 = 2;
	v1 = 0x80000;
	v0 = v0 | v1;
	NONE;
	v1 = 0x10000;
	v0 = v0 | v1;
	NONE;
	v1 = 21056;
	*(s32*)(s1 + 4452) = v1;
	s0 = s1 + 4448;

loc_0000CABC:		
	*(s32*)(s1 + 4268) = v0;
	v0 = sub_0000E108(...);
	a0 = v0;
	a3 = s1 + 4265;
	a1 = s0;
	a2 = sp;
	t0 = 2;
	v0 = sceVshBridge_F933DA92(...);
	a2 = s1 + 4304;
	if ((s32)v0 < 0)
		goto loc_0000C974;
	a3 = sp;
	t0 = sp + 144;

loc_0000CAEC:		
	v0 = *(s32*)(a3 + 0);
	v1 = *(s32*)(a3 + 4);
	a0 = *(s32*)(a3 + 8);
	a1 = *(s32*)(a3 + 12);
	*(s32*)(a2 + 0) = v0;
	a3 = a3 + 16;
	a2 = a2 + 16;
	*(s32*)(a2 - 12) = v1;
	*(s32*)(a2 - 8) = a0;
	*(s32*)(a2 - 4) = a1;
	if (a3 != t0)
		goto loc_0000CAEC;
	s2 = 0x00000;
	v0 = sub_0000E108(...);
	a1 = *(u8*)(s1 + 84);
	v1 = 0x00000;
	v1 = v1 + 4676;
	a2 = *(u16*)(s1 + 88);
	t1 = a1 << 5;
	t2 = v1 + 12;
	t2 = t1 + t2;
	t0 = s2 + 5696;
	t1 = t1 + v1;
	a0 = v0;
	a3 = s0;
	v0 = sceVshBridge_ACBF4681(...);
	a0 = *(u8*)(s1 + 84);
	if ((s32)v0 < 0)
		goto loc_0000CC38;
	*(s32*)(s1 + 4452) = v0;
	a1 = 1;
	v0 = sub_0000A6C4(...);
	v1 = *(u8*)(s1 + 4264);
	if (v1 != 0)
	{
		v0 = *(s32*)(s1 + 4448);
		goto loc_0000CB80;
	}
	a0 = *(s32*)(s1 + 4188);
	if (a0 != 0)
		goto loc_0000CC24;

loc_0000CB7C:		
	v0 = *(s32*)(s1 + 4448);

loc_0000CB80:		
	v1 = *(s32*)(s1 + 4452);
	*(s8*)(s1 + 4264) = 0;
	a0 = s1;
	*(s32*)(s1 + 4188) = v0;
	*(s32*)(s1 + 4192) = v1;
	*(s32*)(s1 + 4448) = 0;
	*(s32*)(s1 + 4452) = 0;
	v0 = sub_0000CD6C(...);
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_0000C974;
	a1 = s5;
	v0 = sub_0000CDF8(...);
	if ((s32)v0 < 0)
	{
		a0 = *(s32*)(s1 + 4280);
		goto loc_0000C978;
	}
	a0 = s1;
	v0 = sub_0000CEDC(...);
	if ((s32)v0 < 0)
	{
		a0 = *(s32*)(s1 + 4280);
		goto loc_0000C978;
	}
	v0 = sub_0000E108(...);
	a0 = v0;
	v0 = sceVshBridge_EF8229E9(...);
	cond = ((s32)v0 < 0);
	v0 = 2;
	if (cond)
		goto loc_0000C974;
	a1 = *(u8*)(s1 + 90);
	v1 = (u32)a1 < (u32)16;
	*(s32*)(s1 + 4456) = v0;
	if (v1 != 0)
		goto loc_0000CC14;
	v0 = s2 + 5696;

loc_0000CBF4:		
	a1 = *(s32*)(s2 + 5696);
	a2 = *(s32*)(v0 + 4);
	a0 = s1;
	v0 = sub_0000C38C(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000C974;
	*(s8*)(s1 + 90) = s5;
	goto loc_0000C9F4;

loc_0000CC14:		
	a0 = s1;
	v0 = sub_0000D018(...);
	v0 = s2 + 5696;
	goto loc_0000CBF4;

loc_0000CC24:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4188) = 0;
	*(s32*)(s1 + 4192) = 0;
	goto loc_0000CB7C;

loc_0000CC38:		
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a2 = 0;
	a1 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A710(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	v0 = sub_0000A5E4(...);
	a0 = *(s32*)(s1 + 4280);
	goto loc_0000C978;

loc_0000CC7C:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4452) = 0;
	goto loc_0000C958;

loc_0000CC8C:		
	a1 = sp + 156;
	v0 = sub_0000A744(...);
	v1 = 0x00000;
	if ((s32)v0 < 0)
		goto loc_0000C974;
	a1 = *(s32*)(v1 + 5704);
	v0 = *(s32*)(sp + 156);
	v0 = (u32)v0 < (u32)a1;
	if (v0 == 0)
	{
		a0 = *(s32*)(s1 + 4448);
		goto loc_0000C950;
	}
	v0 = 0x00000;
	v1 = v0 + 5696;
	a0 = *(u8*)(s1 + 84);
	a2 = *(s32*)(v0 + 5696);
	a3 = *(s32*)(v1 + 4);
	t0 = 1;
	v0 = sub_0000A5E4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 1;
	v0 = sub_0000A710(...);
	a0 = *(s32*)(s1 + 4448);
	goto loc_0000C950;

loc_0000CCE0:		
	v0 = v0 + 1;
	s5 = v0 & 0xF;
	goto loc_0000C880;

loc_0000CCEC:		
	a1 = 0;
	s3 = 1;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a2 = 0;
	a1 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A710(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	v0 = sub_0000A5E4(...);
	goto loc_0000C7B0;

loc_0000CD34:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	s3 = 1;

loc_0000CD40:		
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	v0 = sub_0000A4C4(...);

loc_0000CD5C:		
	goto loc_0000C7B0;

loc_0000CD60:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	goto loc_0000CD40;
}

sub_0000CD6C(...) // at 0x0000CD6C 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s1;
	s1 = a0;

loc_0000CD78:		
	*(s32*)(sp + 40) = ra;
	*(s32*)(sp + 32) = s0;
	v0 = sub_0000B82C(...);
	a0 = v0;
	a2 = sp + 16;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	a1 = 0;
	a3 = 0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_0000CDE0;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	a3 = sp;
	if ((s32)v0 < 0)
		goto loc_0000CDDC;
	a1 = *(s32*)(s1 + 4188);
	a0 = *(s32*)(sp + 16);
	a2 = *(s32*)(s1 + 4192);
	v0 = onesegSal_71C6AB48(...);
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	s0 = v0;
	v0 = onesegSal_9CBB0F5D(...);

loc_0000CDDC:		
	v1 = s0;

loc_0000CDE0:		
	ra = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 48;
	return (v0);
}

sub_0000CDF8(...) // at 0x0000CDF8 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = s0;
	s0 = a1 & 0xFF;
	*(s32*)(sp + 40) = ra;
	a0 = *(u8*)(a0 + 84);
	v0 = sub_0000A6AC(...);
	a1 = s0;
	a0 = s1;

loc_0000CE20:		
	v1 = 0;
	if (v0 != 0)
		goto loc_0000CE40;

loc_0000CE28:		
	ra = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_0000CE40:		
	v0 = sub_0000B8E0(...);
	s0 = v0;
	a2 = sp + 20;
	a1 = sp + 16;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_0000CE28;
	a0 = *(u8*)(s1 + 84);
	v0 = sub_0000A550(...);
	a0 = s0;
	a3 = 0;
	a2 = sp + 24;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	a1 = 0;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	a3 = sp;
	if ((s32)v0 < 0)
		goto loc_0000CEC0;
	a1 = *(s32*)(sp + 16);
	a0 = *(s32*)(sp + 24);
	a2 = *(s32*)(sp + 20);
	v0 = onesegSal_71C6AB48(...);
	s0 = v0;
	a1 = sp;
	if ((s32)v0 < 0)
		goto loc_0000CEC8;
	a0 = *(s32*)(sp + 24);
	v0 = onesegSal_9CBB0F5D(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);

loc_0000CEC0:		
	v1 = s0;
	goto loc_0000CE28;

loc_0000CEC8:		
	a0 = *(s32*)(sp + 24);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	v1 = s0;
	goto loc_0000CE28;
}

sub_0000CEDC(...) // at 0x0000CEDC 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s1;
	s1 = a0;

loc_0000CEE8:		
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 32) = s0;
	s0 = *(u8*)(a0 + 84);
	a0 = s0;
	v0 = sub_0000A6F8(...);
	a0 = s0;
	a1 = sp + 16;
	v1 = 0;
	if (v0 != 0)
		goto loc_0000CF2C;

loc_0000CF10:		
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_0000CF2C:		
	v0 = sub_0000A744(...);
	s0 = v0;
	a0 = s1;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_0000CF10;
	a1 = *(s32*)(sp + 16);
	v0 = sub_0000BC84(...);
	s2 = v0;
	a2 = sp + 20;
	a3 = sp + 24;
	v1 = s0;
	if (v0 == 0)
		goto loc_0000CF10;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 16);
	v0 = sub_0000A594(...);
	a0 = s2;
	a2 = sp + 28;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	a1 = 0;
	a3 = 0;
	v1 = s0;
	if (v0 == 0)
		goto loc_0000CF10;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	a3 = sp;
	if ((s32)v0 < 0)
		goto loc_0000CFD4;
	a1 = *(s32*)(sp + 20);
	a0 = *(s32*)(sp + 28);
	a2 = *(s32*)(sp + 24);
	v0 = onesegSal_71C6AB48(...);
	s0 = v0;
	a1 = sp;
	if ((s32)v0 < 0)
		goto loc_0000CFDC;
	a0 = *(s32*)(sp + 28);
	v0 = onesegSal_9CBB0F5D(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A710(...);

loc_0000CFD4:		
	v1 = s0;
	goto loc_0000CF10;

loc_0000CFDC:		
	a0 = *(s32*)(sp + 28);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	v1 = s0;
	goto loc_0000CF10;
}

sub_0000CFF0(...) // at 0x0000CFF0 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	v0 = sub_0000B82C(...);
	a0 = v0;
	a1 = sp;
	v0 = onesegSal_653384D2(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000D018(...) // at 0x0000D018 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	a1 = a1 & 0xFF;
	v0 = sub_0000B8E0(...);
	a0 = v0;
	a1 = sp;
	v0 = onesegSal_653384D2(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000D040(...) // at 0x0000D040 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v0 = 0x00000;
	s1 = a0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(v0 + 5708);
	v0 = 0x80000000;
	*(s32*)(sp + 4) = 0;
	v0 = v0 | 0x5;
	*(s32*)(sp + 8) = 0;
	if ((s32)v1 <= 0)
		goto loc_0000D1FC;
	a2 = 1;
	v0 = sub_0000B4D8(...);
	ra = *(s32*)(sp + 24);
	if ((s32)v0 < 0)
		goto loc_0000D200;
	a0 = s1;
	v0 = sub_0000B88C(...);
	ra = *(s32*)(sp + 24);
	if ((s32)v0 < 0)
		goto loc_0000D200;
	v0 = sub_0000A444(...);
	v1 = 16;
	*(s8*)(s1 + 90) = v1;
	a0 = s1;
	v0 = sub_0000B9F8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D1D4;

loc_0000D0B0:		
	a0 = s1;
	v0 = sub_0000BA98(...);
	v1 = (u32)v0 < (u32)16;
	*(s8*)(s1 + 90) = v0;
	if (v1 == 0)
		goto loc_0000D1D4;
	a0 = s1;
	v0 = sub_0000BD2C(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D0B0;
	a0 = *(u8*)(s1 + 84);
	a1 = sp;
	v0 = sub_0000A744(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D0B0;
	a1 = *(s32*)(sp + 0);
	a0 = s1;
	v0 = sub_0000BCD8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D2C8;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 0);
	a2 = sp + 4;
	a3 = sp + 8;
	v0 = sub_0000A594(...);
	a1 = *(s32*)(sp + 4);
	if (v0 != 0)
		goto loc_0000D150;
	a1 = *(s32*)(sp + 0);
	a0 = s1;
	a2 = sp + 4;
	a3 = sp + 8;
	v0 = sub_0000C100(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D2C8;
	a0 = *(u8*)(s1 + 84);
	a1 = *(s32*)(sp + 0);
	a2 = *(s32*)(sp + 4);
	a3 = *(s32*)(sp + 8);
	t0 = 0;
	v0 = sub_0000A5E4(...);
	a1 = *(s32*)(sp + 4);

loc_0000D150:		
	a2 = *(s32*)(sp + 8);
	a0 = s1;
	v0 = sub_0000C300(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D280;
	v0 = 1;
	*(s32*)(s1 + 4300) = v0;
	a0 = s1;
	v0 = sub_0000BEDC(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D1D4;
	a0 = s1;
	v0 = sub_0000DEBC(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D1D4;
	a1 = *(s32*)(s1 + 4296);
	a0 = s1;
	v0 = sub_0000BCD8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D1D4;
	a1 = *(s32*)(s1 + 4296);
	a0 = s1;
	a2 = sp + 4;
	a3 = sp + 8;
	*(s32*)(sp + 4) = 0;
	v0 = sub_0000C100(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D1D4;
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(sp + 8);
	a0 = s1;
	v0 = sub_0000C38C(...);
	s0 = v0;

loc_0000D1D4:		
	a0 = s1;
	v0 = sub_0000BA58(...);
	v0 = sub_0000A488(...);
	a0 = *(s32*)(sp + 4);

loc_0000D1E8:		
	if (a0 != 0)
		goto loc_0000D270;

loc_0000D1F0:		
	if ((s32)s0 < 0)
	{
		a0 = *(s32*)(s1 + 4280);
		goto loc_0000D210;
	}

loc_0000D1F8:		
	v0 = s0;

loc_0000D1FC:		
	ra = *(s32*)(sp + 24);

loc_0000D200:		
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000D210:		
	s0 = -1;
	if (a0 == s0)
	{
		a0 = *(s32*)(s1 + 4276);
		goto loc_0000D22C;
	}

loc_0000D220:		
	v0 = sceVshBridge_6F20A6DE(...);

loc_0000D224:		
	*(s32*)(s1 + 4280) = s0;
	a0 = *(s32*)(s1 + 4276);

loc_0000D22C:		
	if (a0 == s0)
	{
		a0 = *(s32*)(s1 + 4188);
		goto loc_0000D244;
	}
	v0 = sceVshBridge_66810AF1(...);
	*(s32*)(s1 + 4276) = s0;
	a0 = *(s32*)(s1 + 4188);

loc_0000D244:		
	if (a0 != 0)
		goto loc_0000D25C;

loc_0000D24C:		
	*(s32*)(s1 + 4300) = 0;
	s0 = 0x80000000;
	s0 = s0 | 0x8;
	goto loc_0000D1F8;

loc_0000D25C:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 4188) = 0;
	*(s32*)(s1 + 4192) = 0;
	goto loc_0000D24C;

loc_0000D270:		
	v0 = scePaf_412B2F09(...);
	goto loc_0000D1F0;

loc_0000D280:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a2 = 0;
	a1 = 0;
	v0 = sub_0000A4C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A710(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	v0 = sub_0000A5E4(...);
	goto loc_0000D0B0;

loc_0000D2C8:		
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	v0 = sub_0000A6C4(...);
	a0 = *(u8*)(s1 + 84);
	a1 = 0;
	a2 = 0;
	v0 = sub_0000A4C4(...);
	goto loc_0000D0B0;
}

onesegCore_7CC912FE(...) // at 0x0000D2EC 
{
	v0 = a1;
	sp = sp - 16;
	a3 = a2;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a2 = v0;
	v0 = sub_0000AC68(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_19C693D9(...) // at 0x0000D314 
{
	v0 = a1;
	sp = sp - 16;
	a3 = a2;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a2 = v0;
	v0 = sub_0000AA94(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000D33C(...) // at 0x0000D33C 
{
	sp = sp - 80;
	*(s32*)(sp + 52) = s5;
	s5 = a3;
	*(s32*)(sp + 48) = s4;
	*(s32*)(sp + 44) = s3;
	s3 = a2 + 8;
	*(s32*)(sp + 40) = s2;
	s2 = a0;
	*(s32*)(sp + 32) = s0;
	s0 = a2;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 64) = fp;
	*(s32*)(sp + 60) = s7;
	*(s32*)(sp + 56) = s6;
	*(s32*)(sp + 36) = s1;
	v0 = *(u8*)(a2 + 8);
	v1 = *(u8*)(s3 + 1);
	a1 = *(u8*)(s3 + 2);

loc_0000D384:		
	v0 = v0 << 24;
	v1 = v1 << 16;
	a2 = *(u8*)(s3 + 3);
	v0 = v0 | v1;
	a1 = a1 << 8;
	s6 = *(s32*)(a3 + 0);
	v0 = v0 | a1;
	v1 = 0x54530000;
	s4 = v0 | a2;
	v1 = v1 | 0x5031;

loc_0000D3AC:		
	a0 = s6;
	if (s4 == v1)
		goto loc_0000D534;

loc_0000D3B4:		
	v0 = 0xAAAA0000;
	v0 = v0 | 0xAAAB;
	asm("multu      $a0, $v0");
	asm("mfhi       $v0");
	v0 = (u32)v0 >> 12;
	s4 = 0;
	if (v0 == 0)
		goto loc_0000D498;
	v0 = 0x54530000;
	v0 = v0 | 0x5031;
	*(s32*)(sp + 16) = v0;
	s7 = 0x54530000;
	fp = 0xAAAA0000;
	s7 = s7 | 0x5032;
	fp = fp | 0xAAAB;
	a3 = s0 + 8;

loc_0000D3F0:		
	v0 = *(u8*)(s0 + 8);
	v1 = *(u8*)(a3 + 1);
	t0 = *(u8*)(a3 + 2);
	v0 = v0 << 24;
	v1 = v1 << 16;
	t1 = *(u8*)(a3 + 3);
	v0 = v0 | v1;
	t0 = t0 << 8;
	v0 = v0 | t0;
	s1 = s2 + 4320;
	v0 = v0 | t1;
	a0 = s0 + 144;
	a1 = s1;
	a2 = 16;
	s3 = s0 + 160;
	if (v0 == s7)
		goto loc_0000D4E4;
	v1 = *(s32*)(sp + 16);
	cond = (v0 != v1);
	v1 = 0x80000000;
	if (cond)
		goto loc_0000D4DC;

loc_0000D43C:		
	a1 = s1;
	a0 = sp;
	a2 = 16;
	v0 = Kernel_Library_1839852A(...);
	a0 = *(s32*)(s2 + 4280);
	t0 = *(s32*)(s2 + 4284);
	a1 = s3;

loc_0000D458:		
	a2 = s3;
	a3 = 5984;
	t1 = sp;
	s4 = s4 + 1;
	s0 = s0 + 6144;
	s6 = s6 - 6144;
	v0 = sceVshBridge_368B2054(...);

loc_0000D474:		
	v1 = 0x80000000;
	if ((s32)v0 < 0)
		goto loc_0000D4DC;
	v0 = *(s32*)(s5 + 0);
	asm("multu      $v0, $fp");
	asm("mfhi       $v0");
	v0 = (u32)v0 >> 12;
	v0 = (u32)s4 < (u32)v0;
	a3 = s0 + 8;
	if (v0 != 0)
		goto loc_0000D3F0;

loc_0000D498:		
	v0 = *(s32*)(s5 + 0);
	v1 = 0;
	v0 = v0 - s6;
	*(s32*)(s5 + 0) = v0;

loc_0000D4A8:		
	ra = *(s32*)(sp + 68);
	fp = *(s32*)(sp + 64);
	s7 = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);

loc_0000D4C0:		
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 80;
	return (v0);

loc_0000D4DC:		
	v1 = v1 | 0x8;
	goto loc_0000D4A8;

loc_0000D4E4:		
	v0 = Kernel_Library_1839852A(...);
	a0 = s3;
	a1 = 0;
	a2 = 32;
	v0 = Kernel_Library_A089ECA4(...);
	v1 = *(u8*)(s0 + 100);

loc_0000D500:		
	a0 = s0 + 140;
	*(s8*)(s0 + 164) = v1;
	v0 = *(s32*)(s2 + 4284);
	v0 = v0 + 32;
	v1 = (u32)v0 >> 24;
	a1 = (u32)v0 >> 16;
	a2 = (u32)v0 >> 8;
	*(s32*)(s2 + 4284) = v0;
	*(s8*)(s0 + 140) = v1;
	*(s8*)(a0 + 3) = v0;
	*(s8*)(a0 + 1) = a1;
	*(s8*)(a0 + 2) = a2;
	goto loc_0000D43C;

loc_0000D534:		
	v0 = *(u8*)(s2 + 4336);
	a0 = s0 + 24;
	a1 = s2 + 4338;
	*(s8*)(s0 + 22) = v0;
	a2 = 24;
	s1 = s2 + 4320;
	v0 = *(u16*)(s2 + 4336);
	s7 = 3;
	v0 = (u32)v0 >> 8;
	*(s8*)(s0 + 23) = v0;
	v0 = Kernel_Library_1839852A(...);
	a0 = s0 + 144;
	a1 = s1;
	a2 = 16;
	v0 = Kernel_Library_1839852A(...);
	a0 = s0 + 160;
	a1 = 0;
	a2 = 32;
	v0 = Kernel_Library_A089ECA4(...);
	a0 = *(u8*)(s0 + 100);
	v1 = s0 + 140;
	*(s8*)(s0 + 164) = a0;
	*(s32*)(s2 + 4284) = 0;
	*(s8*)(s0 + 140) = 0;
	*(s8*)(v1 + 3) = 0;
	*(s8*)(v1 + 1) = 0;
	*(s8*)(v1 + 2) = 0;
	v0 = *(s32*)(s2 + 4456);
	if (v0 == s7)
	{
		a0 = *(s32*)(s5 + 0);
		goto loc_0000D3B4;
	}
	v0 = *(u8*)(s0 + 8);
	v1 = *(u8*)(s3 + 1);
	a0 = *(u8*)(s3 + 2);
	v0 = v0 << 24;
	v1 = v1 << 16;
	a1 = *(u8*)(s3 + 3);
	v0 = v0 | v1;
	a0 = a0 << 8;
	v0 = v0 | a0;
	v0 = v0 | a1;
	if (v0 == s4)
	{
		a0 = s2;
		goto loc_0000D5E4;
	}
	a0 = *(s32*)(s5 + 0);
	goto loc_0000D3B4;

loc_0000D5E4:		
	a1 = s0;
	a2 = 64;

loc_0000D5EC:		
	a3 = 2;
	v0 = sub_0000C42C(...);
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	if ((s32)v0 < 0)
		goto loc_0000D4A8;
	a0 = *(s32*)(s5 + 0);
	*(s32*)(s2 + 4456) = s7;
	goto loc_0000D3B4;
}

sub_0000D60C(...) // at 0x0000D60C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = -1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 4456);
	s0 = a0;
	if (v0 == 0)
		goto loc_0000D66C;
	v0 = *(s32*)(a0 + 4280);
	a0 = v0;
	if (v0 == s1)
		goto loc_0000D644;
	v0 = sceVshBridge_6F20A6DE(...);
	*(s32*)(s0 + 4280) = s1;

loc_0000D644:		
	v0 = *(s32*)(s0 + 4276);
	a0 = v0;
	if (v0 == s1)
		goto loc_0000D65C;
	v0 = sceVshBridge_66810AF1(...);
	*(s32*)(s0 + 4276) = s1;

loc_0000D65C:		
	v0 = *(s32*)(s0 + 4188);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000D684;

loc_0000D668:		
	*(s32*)(s0 + 4456) = 0;

loc_0000D66C:		
	ra = *(s32*)(sp + 8);

loc_0000D670:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000D684:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 4188) = 0;
	*(s32*)(s0 + 4192) = 0;
	goto loc_0000D668;
}

sub_0000D698(...) // at 0x0000D698 
{
	sp = sp - 64;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 48) = s4;
	s4 = 1;
	*(s32*)(sp + 40) = s2;
	s2 = a0;
	*(s32*)(sp + 36) = s1;
	s1 = s2 + 4;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 44) = s3;
	v0 = sub_0000BBC4(...);
	a0 = v0;
	a2 = sp + 16;
	a1 = 1;
	a3 = 0;

loc_0000D6D4:		
	t0 = 0;
	t1 = 0;
	t2 = sp;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	v0 = 0x80000000;
	if ((s32)s0 < 0)
		goto loc_0000D85C;
	a0 = s1;
	a1 = 0;
	a2 = 80;
	v0 = Kernel_Library_A089ECA4(...);
	v0 = 84;
	*(s8*)(s2 + 4) = v0;
	s3 = s1;
	v0 = 21576;
	a0 = 0x54480000;
	v1 = 0x540000;
	*(s8*)(s3 + 1) = v0;
	a0 = a0 | 0x4D48;
	v1 = v1 | 0x484D;
	v0 = 35;
	*(s8*)(s3 + 2) = v1;
	s1 = s2 + 20;
	v1 = 2;
	*(s8*)(s3 + 3) = a0;
	a3 = 0;
	a2 = 24;
	t0 = 0;
	*(s8*)(s2 + 10) = v0;
	v0 = 80;
	t1 = sp;
	*(s8*)(s2 + 13) = v1;

loc_0000D754:		
	*(s8*)(s2 + 17) = s4;
	*(s8*)(s2 + 8) = s4;
	*(s8*)(s2 + 9) = 0;
	*(s8*)(s2 + 11) = 0;
	*(s8*)(s2 + 12) = 0;
	*(s8*)(s2 + 14) = 0;
	*(s8*)(s2 + 16) = 0;
	*(s8*)(s2 + 20) = 0;
	*(s8*)(s1 + 3) = v0;
	*(s8*)(s1 + 1) = 0;
	*(s8*)(s1 + 2) = 0;
	s1 = s2 + 36;
	a0 = *(s32*)(sp + 16);
	v0 = onesegSal_950E5178(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D84C;
	a0 = *(s32*)(sp + 16);
	a1 = s1;
	a2 = 24;

loc_0000D7A4:		
	a3 = sp;
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D84C;
	a0 = *(s32*)(sp + 16);
	a3 = 0;
	a2 = 144;
	t0 = 0;
	t1 = sp;
	v0 = onesegSal_950E5178(...);
	s0 = v0;
	s1 = s2 + 68;
	if ((s32)v0 < 0)
		goto loc_0000D84C;
	a0 = *(s32*)(sp + 16);
	a1 = s1;
	a2 = 16;
	a3 = sp;
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D84C;
	a0 = *(s32*)(sp + 16);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	a0 = s2;
	*(s32*)(sp + 16) = 0;
	v0 = sub_0000BC24(...);
	a0 = v0;
	a2 = s2 + 4304;
	a1 = 0;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D84C;
	a0 = *(s32*)(s2 + 4304);
	a1 = s3;
	a2 = 80;
	a3 = sp;
	v0 = onesegSal_71C6AB48(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000D88C;

loc_0000D84C:		
	a0 = *(s32*)(sp + 16);
	if (a0 != 0)
		goto loc_0000D87C;
	v0 = s0;

loc_0000D85C:		
	ra = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 64;
	return (v0);

loc_0000D87C:		
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	v0 = s0;
	goto loc_0000D85C;

loc_0000D88C:		
	a0 = *(s32*)(s2 + 4304);
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	*(s32*)(s2 + 4304) = 0;
	goto loc_0000D84C;
}

sub_0000D8A0(...) // at 0x0000D8A0 
{
	sp = sp - 128;
	v0 = a0 + 4;
	*(s32*)(sp + 88) = s2;
	s2 = a3;
	a3 = 3;
	*(s32*)(sp + 80) = s0;
	s0 = a1;
	a1 = v0;
	*(s32*)(sp + 64) = a2;
	a2 = 64;
	*(s32*)(sp + 112) = fp;
	fp = t0;
	*(s32*)(sp + 84) = s1;
	s1 = a0;
	*(s32*)(sp + 116) = ra;
	*(s32*)(sp + 108) = s7;
	*(s32*)(sp + 104) = s6;
	*(s32*)(sp + 100) = s5;
	*(s32*)(sp + 96) = s4;
	*(s32*)(sp + 92) = s3;
	v0 = sub_0000C42C(...);
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	if ((s32)v0 < 0)
		goto loc_0000DA68;
	v0 = s2 & 0xF;
	v1 = 16;
	a0 = 2;
	v1 = v1 - v0;
	*(s32*)(s1 + 4300) = a0;
	a0 = 0;
	if (v1 == 0)
		goto loc_0000D938;
	v0 = *(s32*)(sp + 64);
	a3 = s2 + v0;

loc_0000D924:		
	a0 = a0 + 1;
	v0 = (u32)a0 < (u32)v1;
	*(s8*)(a3 + 0) = v1;
	a3 = a3 + 1;
	if (v0 != 0)
		goto loc_0000D924;

loc_0000D938:		
	a0 = sp + 32;
	a1 = 0;
	a2 = 32;
	v0 = Kernel_Library_A089ECA4(...);
	v0 = 84;
	t0 = s0;
	*(s8*)(sp + 32) = v0;
	v0 = 21576;
	NONE;
	NONE;
	v1 = fp + 32;
	*(s8*)(sp + 33) = v0;
	t1 = 0x54480000;
	a3 = 0x540000;
	v0 = 0x80000000;
	t1 = t1 | 0x4D50;
	a3 = a3 | 0x484D;
	s5 = (u32)t0 >> 24;
	s6 = (u32)t0 >> 16;
	s7 = (u32)t0 >> 8;
	a1 = s1 + 68;
	t2 = (u32)v1 >> 24;
	t3 = (u32)v1 >> 16;
	t4 = (u32)v1 >> 8;
	a0 = sp + 16;
	a2 = 16;
	t5 = (u32)s0 >> 24;
	t6 = (u32)s0 >> 16;
	t7 = (u32)s0 >> 8;
	v0 = v0 | 0x8;
	s2 = (u32)fp >> 24;
	s3 = (u32)fp >> 16;
	s4 = (u32)fp >> 8;
	*(s8*)(sp + 34) = a3;
	*(s8*)(sp + 35) = t1;
	*(s8*)(sp + 43) = t0;
	*(s32*)(sp + 68) = v0;
	*(s8*)(sp + 36) = t2;
	*(s8*)(sp + 37) = t3;

loc_0000D9D4:		
	*(s8*)(sp + 38) = t4;
	*(s8*)(sp + 39) = v1;
	*(s8*)(sp + 40) = s5;
	*(s8*)(sp + 41) = s6;
	*(s8*)(sp + 42) = s7;
	*(s8*)(sp + 44) = t5;
	*(s8*)(sp + 45) = t6;
	*(s8*)(sp + 46) = t7;
	*(s8*)(sp + 48) = s2;
	*(s8*)(sp + 49) = s3;
	*(s8*)(sp + 50) = s4;
	*(s8*)(sp + 47) = s0;
	*(s8*)(sp + 51) = fp;
	v0 = Kernel_Library_1839852A(...);
	t0 = s0;
	a1 = *(s32*)(sp + 64);
	a0 = *(s32*)(s1 + 4280);
	t1 = sp + 16;
	a2 = a1;
	a3 = fp;
	v0 = sceVshBridge_368B2054(...);
	a1 = sp + 32;
	if ((s32)v0 < 0)
		goto loc_0000DA9C;
	a0 = *(s32*)(s1 + 4304);
	a2 = 32;
	a3 = sp;
	v0 = onesegSal_71C6AB48(...);
	*(s32*)(sp + 68) = v0;
	if ((s32)v0 < 0)
		goto loc_0000DA9C;
	a0 = *(s32*)(s1 + 4304);
	a1 = *(s32*)(sp + 64);

loc_0000DA50:		
	a2 = fp;
	a3 = sp;
	v0 = onesegSal_71C6AB48(...);
	*(s32*)(sp + 68) = v0;
	v1 = 0;
	if ((s32)v0 < 0)
		goto loc_0000DA9C;

loc_0000DA68:		
	ra = *(s32*)(sp + 116);
	fp = *(s32*)(sp + 112);
	s7 = *(s32*)(sp + 108);
	s6 = *(s32*)(sp + 104);
	s5 = *(s32*)(sp + 100);
	s4 = *(s32*)(sp + 96);
	s3 = *(s32*)(sp + 92);
	s2 = *(s32*)(sp + 88);
	s1 = *(s32*)(sp + 84);
	s0 = *(s32*)(sp + 80);
	v0 = v1;
	sp = sp + 128;
	return (v0);

loc_0000DA9C:		
	a0 = *(s32*)(s1 + 4304);
	if (a0 != 0)
		goto loc_0000DAB0;

loc_0000DAA8:		
	v1 = *(s32*)(sp + 68);
	goto loc_0000DA68;

loc_0000DAB0:		
	a1 = sp;
	v0 = onesegSal_9CBB0F5D(...);
	*(s32*)(s1 + 4304) = 0;
	goto loc_0000DAA8;
}

sub_0000DAC0(...) // at 0x0000DAC0 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	v0 = sub_0000BC24(...);

loc_0000DAD8:		
	a0 = v0;
	a2 = s1 + 4304;
	a1 = 1;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	t2 = sp;
	v0 = onesegSal_2D9F26C3(...);
	s0 = v0;
	a1 = s1 + 4;
	a2 = 80;
	a3 = sp;
	if ((s32)v0 < 0)
		goto loc_0000DB34;
	a0 = *(s32*)(s1 + 4304);
	v0 = onesegSal_8A14C632(...);
	s0 = v0;
	v0 = 0;
	if ((s32)s0 < 0)
		goto loc_0000DB34;

loc_0000DB20:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000DB34:		
	v0 = *(s32*)(s1 + 4304);
	a1 = sp;
	a0 = v0;
	if (v0 != 0)
		goto loc_0000DB4C;

loc_0000DB44:		
	v0 = s0;
	goto loc_0000DB20;

loc_0000DB4C:		
	v0 = onesegSal_9CBB0F5D(...);
	*(s32*)(s1 + 4304) = 0;
	goto loc_0000DB44;
}

sub_0000DB5C(...) // at 0x0000DB5C 
{
	sp = sp - 96;
	v0 = a0 + 4;
	*(s32*)(sp + 80) = s4;
	a3 = 3;
	s4 = a2;
	*(s32*)(sp + 72) = s2;
	a2 = 64;
	s2 = a1;
	a1 = v0;
	*(s32*)(sp + 64) = s0;
	s0 = a0;
	*(s32*)(sp + 84) = ra;
	*(s32*)(sp + 76) = s3;
	*(s32*)(sp + 68) = s1;
	v0 = sub_0000C42C(...);
	t0 = 0x80000000;
	a1 = sp + 16;
}

sub_0000DBA0(...) // at 0x0000DBA0 
{
	a3 = sp;
	a2 = 32;
	t0 = t0 | 0x5;
	if ((s32)v0 < 0)
		goto loc_0000DC90;
	v0 = 2;

loc_0000DBB4:		
	a0 = *(s32*)(s0 + 4304);
	*(s32*)(s0 + 4300) = v0;
	v0 = onesegSal_8A14C632(...);
	a3 = sp;
	a1 = s2;
	if ((s32)v0 < 0)
		goto loc_0000DCB4;
	v0 = *(u8*)(sp + 32);
	v1 = *(u8*)(sp + 33);
	a2 = *(u8*)(sp + 34);
	t0 = *(u8*)(sp + 35);
	v1 = v1 << 16;
	v0 = v0 << 24;
	v0 = v0 | v1;
	a2 = a2 << 8;
	v0 = v0 | a2;
	a0 = *(s32*)(s0 + 4304);
	s1 = v0 | t0;
	a2 = s1;
	v0 = onesegSal_8A14C632(...);
	s3 = sp + 48;
	a1 = s0 + 68;
	a0 = s3;
	a2 = 16;
	if ((s32)v0 < 0)
		goto loc_0000DCB4;
	v0 = Kernel_Library_1839852A(...);
	t0 = *(u8*)(sp + 28);
	v0 = *(u8*)(sp + 29);
	v1 = *(u8*)(sp + 30);
	a0 = *(u8*)(sp + 31);
	v0 = v0 << 16;
	t0 = t0 << 24;
	t0 = t0 | v0;
	v1 = v1 << 8;
	t0 = t0 | v1;

loc_0000DC40:		
	t0 = t0 | a0;
	a0 = *(s32*)(s0 + 4280);
	a3 = s1;
	a1 = s2;
	t1 = s3;
	a2 = s2;
	v0 = sceVshBridge_24A3355D(...);
	t0 = 0;
	if ((s32)v0 < 0)
		goto loc_0000DCB4;
	v0 = *(u8*)(sp + 20);
	v1 = *(u8*)(sp + 21);
	a0 = *(u8*)(sp + 22);
	a1 = *(u8*)(sp + 23);
	v0 = v0 << 24;
	v1 = v1 << 16;
	v0 = v0 | v1;
	a0 = a0 << 8;
	v0 = v0 | a0;
	v0 = v0 | a1;
	*(s32*)(s4 + 0) = v0;

loc_0000DC90:		
	ra = *(s32*)(sp + 84);
	s4 = *(s32*)(sp + 80);
	s3 = *(s32*)(sp + 76);
	s2 = *(s32*)(sp + 72);
	s1 = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	v0 = t0;
	sp = sp + 96;
	return (v0);

loc_0000DCB4:		
	v0 = *(s32*)(s0 + 4304);
	a1 = sp;

loc_0000DCC0:		
	a0 = v0;
	if (v0 != 0)
		goto loc_0000DCCC;

loc_0000DCC4:		
	t0 = 0x80000000;
	goto loc_0000DC90;

loc_0000DCCC:		
	v0 = onesegSal_9CBB0F5D(...);
	*(s32*)(s0 + 4304) = 0;
	goto loc_0000DCC4;
}

sub_0000DCDC(...) // at 0x0000DCDC 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	a1 = sp;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	v0 = *(s32*)(a0 + 4304);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000DD10;

loc_0000DCFC:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;

loc_0000DD08:		
	sp = sp + 32;
	return (v0);

loc_0000DD10:		
	v0 = onesegSal_9CBB0F5D(...);
	*(s32*)(s0 + 4304) = 0;
	goto loc_0000DCFC;
}

sub_0000DD20(...) // at 0x0000DD20 
{
	sp = sp - 64;
	*(s32*)(sp + 36) = s5;
	s5 = a3;
	*(s32*)(sp + 24) = s2;

loc_0000DD30:		
	s2 = a0;
	*(s32*)(sp + 20) = s1;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	s0 = 2;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	s3 = *(s32*)(a3 + 0);
	v0 = *(s32*)(a0 + 4300);
	v1 = s3;
	if (v0 == s0)
		goto loc_0000DD8C;
	a1 = a2;
	a3 = 2;
	a2 = 64;
	v0 = sub_0000C42C(...);
	v1 = 0x80000000;
	v1 = v1 | 0x5;
	if ((s32)v0 < 0)
		goto loc_0000DE8C;
	*(s32*)(s2 + 4300) = s0;
	v1 = *(s32*)(s5 + 0);

loc_0000DD8C:		
	v0 = 0xAAAA0000;
	v0 = v0 | 0xAAAB;
	asm("multu      $v1, $v0");
	asm("mfhi       $v0");
	v0 = (u32)v0 >> 12;
	s4 = 0;
	if (v0 == 0)
		goto loc_0000DE7C;
	s6 = 0xAAAA0000;
	s7 = 0x80000;
	s6 = s6 | 0xAAAB;

loc_0000DDB4:		
	v1 = s1 + 140;
	v0 = *(u8*)(v1 + 1);
	s0 = *(u8*)(s1 + 140);
	a0 = *(u8*)(v1 + 2);
	a3 = *(u8*)(v1 + 3);
	v0 = v0 << 16;
	s0 = s0 << 24;
	s0 = s0 | v0;
	a0 = a0 << 8;
	a1 = s1 + 144;
	s0 = s0 | a0;
	a2 = 16;
	a0 = sp;
	s0 = s0 | a3;
	v0 = Kernel_Library_1839852A(...);
	a0 = *(s32*)(s2 + 4280);
	a1 = s1 + 160;
	t0 = s0;
	a2 = a1;
	a3 = 5984;
	t1 = sp;
	v0 = sceVshBridge_24A3355D(...);
	v1 = 0x80000000;
	s4 = s4 + 1;
	s3 = s3 - 6144;
	v1 = v1 | 0x8;
	if ((s32)v0 < 0)
		goto loc_0000DE8C;
	v1 = *(s32*)(s2 + 4268);
	NONE;
	NONE;
	a1 = a0 << 6;
	v0 = v0 << 5;

loc_0000DE34:		
	NONE;
	a1 = a1 | v0;
	a0 = a0 << 4;
	NONE;
	a1 = a1 | a0;
	v0 = v0 << 2;
	v1 = v1 & s7;
	a1 = a1 | v0;
	if (v1 != 0)
		goto loc_0000DE60;
	*(s8*)(s1 + 100) = a1;
	*(s8*)(s1 + 164) = a1;

loc_0000DE60:		
	v0 = *(s32*)(s5 + 0);
	asm("multu      $v0, $s6");
	asm("mfhi       $v0");
	v0 = (u32)v0 >> 12;
	v0 = (u32)s4 < (u32)v0;
	s1 = s1 + 6144;
	if (v0 != 0)
		goto loc_0000DDB4;

loc_0000DE7C:		
	v0 = *(s32*)(s5 + 0);
	v1 = 0;
	v0 = v0 - s3;
	*(s32*)(s5 + 0) = v0;

loc_0000DE8C:		
	ra = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);

loc_0000DE94:		
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 64;
	return (v0);
}

sub_0000DEBC(...) // at 0x0000DEBC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000DF2C(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_0000DF18;
	a1 = *(u8*)(s0 + 4229);
	a2 = *(u8*)(s0 + 4230);
	v0 = *(s32*)(s0 + 4268);
	v1 = a1 & 0xFF;
	NONE;
	NONE;
	NONE;
	a1 = a1 & 0x1;
	NONE;
	NONE;
	a2 = a2 & 0x3;
	NONE;
	NONE;
	NONE;
	*(s32*)(s0 + 4268) = v0;
	v1 = 0;

loc_0000DF18:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000DF2C(...) // at 0x0000DF2C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = 0x80000000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 4188);
	v1 = v1 | 0x5;
	if (v0 == 0)
		goto loc_0000DF58;
	v0 = *(s32*)(a0 + 4192);
	if (v0 != 0)
		goto loc_0000DF6C;

loc_0000DF58:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_0000DF6C:		
	v0 = sub_0000E108(...);
	a0 = v0;
	a3 = s0 + 4188;
	a1 = s0 + 4200;
	a2 = 64;
	t0 = 1;
	v0 = sceVshBridge_DCF0B1FE(...);
	v0 = (s32)v0 < (s32)0;
	v1 = v0 << 31;
	goto loc_0000DF58;
}

sub_0000DF98(...) // at 0x0000DF98 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = -1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 4300);
	s0 = a0;
	if (v0 == 0)
		goto loc_0000DFF8;
	v0 = *(s32*)(a0 + 4280);
	a0 = v0;
	if (v0 == s1)
		goto loc_0000DFD0;
	v0 = sceVshBridge_6F20A6DE(...);
	*(s32*)(s0 + 4280) = s1;

loc_0000DFD0:		
	v0 = *(s32*)(s0 + 4276);
	a0 = v0;
	if (v0 == s1)
		goto loc_0000DFE8;
	v0 = sceVshBridge_66810AF1(...);
	*(s32*)(s0 + 4276) = s1;

loc_0000DFE8:		
	v0 = *(s32*)(s0 + 4188);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000E010;

loc_0000DFF4:		
	*(s32*)(s0 + 4300) = 0;

loc_0000DFF8:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000E010:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 4188) = 0;
	*(s32*)(s0 + 4192) = 0;
	goto loc_0000DFF4;
}

sub_0000E024(...) // at 0x0000E024 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	t2 = 0x00000;
	a3 = a0;
	*(s32*)(sp + 0) = s0;
	a2 = 0;
	t1 = t2 + 5716;
	*(s32*)(sp + 4) = s1;
	t0 = 58;
	s1 = 0;
	a1 = a3 + a2;

loc_0000E050:		
	a0 = *(u8*)(a1 + 0);
	v0 = a2 + t1;
	*(s8*)(v0 + 0) = a0;
	v1 = *(s8*)(a1 + 0);
	a2 = a2 + 1;
	if (v1 == t0)
		goto loc_0000E074;
	v0 = (u32)a2 < (u32)7;
	a1 = a3 + a2;
	if (v0 != 0)
		goto loc_0000E050;

loc_0000E074:		
	s0 = t2 + 5716;
	v1 = a2 + s0;
	*(s8*)(v1 + 0) = 0;
	a1 = 0x20000;
	v0 = 0x00000;
	a1 = a1 - 14864;
	a0 = s0;
	a2 = 4;
	*(s32*)(v0 + 5712) = s0;
	v0 = onesegSal_00850EAA(...);
	v1 = 32;
	if (v0 != 0)
		goto loc_0000E0C4;

loc_0000E0A4:		
	v0 = 0x00000;
	*(s32*)(v0 + 5724) = v1;

loc_0000E0AC:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000E0C4:		
	a1 = 0x20000;
	a0 = s0;
	a1 = a1 - 14856;
	a2 = 4;
	v0 = onesegSal_00850EAA(...);
	cond = (v0 != 0);
	v0 = 0x00000;
	if (cond)
		goto loc_0000E0E8;
	v1 = 16;
	goto loc_0000E0A4;

loc_0000E0E8:		
	*(s8*)(v0 + 5716) = 0;
	v0 = 0x00000;
	s1 = 0x80000000;

loc_0000E0F4:		
	*(s32*)(v0 + 5724) = 0;
	goto loc_0000E0AC;
}

sub_0000E0FC(...) // at 0x0000E0FC 
{
	v1 = 0x00000;
	v0 = *(s32*)(v1 + 5712);
	return (v0);
}

sub_0000E108(...) // at 0x0000E108 
{
	v1 = 0x00000;
	v0 = *(s32*)(v1 + 5724);
	return (v0);
}

sub_0000E114(...) // at 0x0000E114 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	s4 = 0x00000;
	a2 = 0;

loc_0000E124:		
	*(s32*)(sp + 12) = s3;
	s3 = a0;
	a0 = *(s32*)(s4 + 4228);
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	a1 = 1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;

loc_0000E148:		
	*(s32*)(sp + 8) = s2;
	v0 = sceKernelWaitSema(...);
	s0 = v0;
	if (v0 != 0)
		goto loc_0000E1AC;
	s2 = 0x00000;
	v0 = *(s32*)(s2 + 5708);
	if (v0 == 0)
		goto loc_0000E1D0;
	a0 = *(s32*)(s4 + 4228);
	if ((s32)v0 <= 0)
		goto loc_0000E1A4;
	v0 = sub_0000E0FC(...);
	a1 = v0;
	a0 = s1;
	a2 = 4;
	v0 = scePaf_E0B32AE8(...);
	a0 = *(s32*)(s4 + 4228);
	if (v0 != 0)
		goto loc_0000E1A4;

loc_0000E18C:		
	v0 = *(s32*)(s2 + 5708);
	v1 = 1;
	*(s8*)(s3 + 4292) = v1;
	v0 = v0 + 1;
	*(s32*)(s2 + 5708) = v0;

loc_0000E1A0:		
	a0 = *(s32*)(s4 + 4228);

loc_0000E1A4:		
	a1 = 1;
	v0 = sceKernelSignalSema(...);

loc_0000E1AC:		
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_0000E1D0:		
	a0 = s1;
	v0 = sub_0000E024(...);
	s0 = v0;
	if (v0 != 0)
		goto loc_0000E1A0;
	v0 = sceVshBridge_C40F345F(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000E1A0;
	v0 = sub_0000E108(...);
	a0 = v0;
	v0 = sceVshBridge_474E9245(...);
	s0 = v0;
	if ((s32)v0 >= 0)
		goto loc_0000E18C;
	v0 = sceVshBridge_C04F9353(...);
	a0 = *(s32*)(s4 + 4228);
	goto loc_0000E1A4;
}

sub_0000E218(...) // at 0x0000E218 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a0 = *(s32*)(s2 + 4228);
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	a2 = 0;
	v0 = sceKernelWaitSema(...);
	s0 = v0;
	a0 = 0x00000;
	if (v0 != 0)
		goto loc_0000E274;
	v0 = *(s32*)(a0 + 5708);
	v1 = v0 - 1;
	if ((s32)v0 <= 0)
		goto loc_0000E2A0;
	*(s8*)(s1 + 4292) = 0;

loc_0000E260:		
	*(s32*)(a0 + 5708) = v1;
	if (v1 == 0)
		goto loc_0000E290;

loc_0000E268:		
	a0 = *(s32*)(s2 + 4228);

loc_0000E26C:		
	a1 = 1;
	v0 = sceKernelSignalSema(...);

loc_0000E274:		
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000E290:		
	v0 = sceVshBridge_C04F9353(...);
	s0 = v0;
	goto loc_0000E268;

loc_0000E2A0:		
	v0 = *(u8*)(s1 + 4292);
	if (v0 != 0)
	{
		*(s8*)(s1 + 4292) = 0;
		goto loc_0000E268;
	}
	a0 = *(s32*)(s2 + 4228);
	goto loc_0000E26C;
}

onesegCore_39434011(...) // at 0x0000E2B4 
{
	v0 = a0;
	sp = sp - 16;
	a2 = 0x20000;
	a0 = 0x00000;
	v1 = 0x80000000;
	*(s32*)(sp + 0) = ra;
	a2 = a2 - 14848;
	a0 = a0 + 220;
	a3 = v0;
	a1 = 16;
	v1 = v1 | 0x4;
	if (v0 == 0)
		goto loc_0000E2F0;
	v0 = scePaf_7B7133D5(...);
	v1 = 0;

loc_0000E2F0:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

onesegCore_81D3051E(...) // at 0x0000E300 
{
	v0 = 0x00000;
	v0 = v0 + 220;
	return (v0);
}

sub_0000E30C(...) // at 0x0000E30C 
{
	a2 = 0x20000;

loc_0000E310:		
	a3 = 0x00000;
	sp = sp - 16;
	t0 = a0;
	a2 = a2 - 14844;
	a0 = a1;
	a3 = a3 + 220;
	*(s32*)(sp + 0) = ra;
	a1 = 16;
	v0 = scePaf_7B7133D5(...);
	ra = *(s32*)(sp + 0);

loc_0000E338:		
	sp = sp + 16;
	return (v0);
}

onesegCore_FB30B10F(...) // at 0x0000E340 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s1;
	s1 = a1;
	a1 = sp;
	*(s32*)(sp + 40) = ra;
	*(s32*)(sp + 32) = s0;
	v0 = sub_0000E30C(...);
	a1 = 1;
	a0 = sp;
	a2 = sp + 16;
	v0 = onesegCore_B27C4716(...);
	a1 = sp + 24;
	if (v0 == 0)
		goto loc_0000E388;

loc_0000E374:		
	ra = *(s32*)(sp + 40);

loc_0000E378:		
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);

loc_0000E388:		
	a0 = *(s32*)(sp + 16);
	v0 = onesegCore_339BBB3B(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_0000E3A8;
	a0 = *(s32*)(sp + 16);
	v0 = onesegCore_9F1FE5B3(...);
	v0 = s0;
	goto loc_0000E374;

loc_0000E3A8:		
	v0 = *(s32*)(sp + 24);
	a0 = *(s32*)(sp + 16);
	*(s32*)(s1 + 0) = v0;
	v0 = onesegCore_9F1FE5B3(...);
	ra = *(s32*)(sp + 40);
	goto loc_0000E378;
}

onesegCore_2E825E27(...) // at 0x0000E3C0 
{
	sp = sp - 64;
	*(s32*)(sp + 44) = s3;
	s3 = a1;
	a1 = a2;
	*(s32*)(sp + 40) = s2;
	s2 = a2;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 36) = s1;
	v0 = onesegCore_FB30B10F(...);
	a0 = s0;
	a1 = sp;
	if (v0 == 0)
		goto loc_0000E414;

loc_0000E3F8:		
	ra = *(s32*)(sp + 48);

loc_0000E3FC:		
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 64;
	return (v0);

loc_0000E414:		
	v0 = sub_0000E30C(...);
	a1 = 1;
	a0 = sp;
	a2 = sp + 16;
	v0 = onesegCore_B27C4716(...);
	a1 = s3;
	if (v0 != 0)
		goto loc_0000E3F8;
	a2 = *(s32*)(s2 + 0);
	a0 = *(s32*)(sp + 16);
	v0 = onesegCore_F0A1D896(...);
	s1 = v0;
	if (v0 == 0)
		goto loc_0000E458;
	a0 = *(s32*)(sp + 16);
	v0 = onesegCore_9F1FE5B3(...);
	v0 = s1;
	goto loc_0000E3F8;

loc_0000E458:		
	a0 = *(s32*)(sp + 16);
	v0 = onesegCore_9F1FE5B3(...);
	ra = *(s32*)(sp + 48);
	goto loc_0000E3FC;
}

sub_0000E468(...) // at 0x0000E468 
{
	v0 = sceVshCommonUtil_D3A016E1(13, 0);
	return (v0);
}

onesegCore_B7ED451A(...) // at 0x0000E488 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	a1 = 1;
	v0 = *(s32*)(s1 + 5732);
	*(s32*)(sp + 8) = ra;
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	if (v0 == 0)
	{
		v0 = onesegSal_265926E7(...);
		s0 = v0;
		a0 = v0;
		v0 = sub_0000E468(...);
		*(s32*)(s1 + 5732) = s0;
		v0 = s0;
	}

	return (v0);
}

onesegCore_202C1B74(...) // at 0x0000E4E0 
{
	return (v0);
}

onesegCore_5CFED6A2(...) // at 0x0000E4E8 
{
	sp = sp - 32;
	a0 = sp;
	*(s32*)(sp + 16) = ra;
	a1 = sp + 4;
	v0 = vsh_05A2E98E(...);
	v0 = *(s32*)(sp + 0);

loc_0000E500:		
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_8D3895CC(...) // at 0x0000E50C 
{
	sp = sp - 32;
	a0 = sp;
	*(s32*)(sp + 16) = ra;
	a1 = sp + 4;
	v0 = vsh_05A2E98E(...);
	v0 = *(s32*)(sp + 4);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_0AB4A2FB(...) // at 0x0000E530 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s7;
	s7 = a3;
	a3 = 0;
	*(s32*)(sp + 20) = s5;
	s5 = a0;
	a0 = a1;

loc_0000E54C:		
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	a1 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	a2 = 0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 24) = s6;
	s6 = t0;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSdk_239EDAE8(...);
	s0 = v0 << 1;
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	a2 = v0;
	a0 = s2;
	a1 = s1;
	a3 = s0;
	s3 = v0;
	v0 = onesegSdk_239EDAE8(...);
	s4 = v0;
	s1 = (u32)s1 < (u32)1;
	v0 = (u32)s6 < (u32)1;
	s1 = s1 | v0;
	s0 = 0;
	s2 = 0;
	v0 = 0;
	if (s1 != 0)
		goto loc_0000E64C;
	s1 = s7;
	if (s4 == 0)
		goto loc_0000E620;
	v0 = s3 + s0;

loc_0000E5D4:		
	a0 = *(u8*)(v0 + 0);

loc_0000E5D8:		
	s0 = s0 + 1;
	v1 = a0 - 161;
	v0 = a0 & 0x80;
	v1 = (u32)v1 < (u32)63;
	if (v0 == 0)
		goto loc_0000E5F4;
	v0 = s3 + s0;
	if (v1 == 0)
		goto loc_0000E678;

loc_0000E5F4:		
	v0 = a0;
	a1 = v0;

loc_0000E5FC:		
	a0 = s5;
	v0 = onesegCore_0AAEDDCE(...);
	s2 = s2 + 2;
	v1 = (u32)s0 < (u32)s4;
	if (s1 == 0)
		goto loc_0000E618;
	*(s16*)(s1 + 0) = v0;
	s1 = s1 + 2;

loc_0000E618:		
	v0 = s3 + s0;
	if (v1 != 0)
		goto loc_0000E5D4;

loc_0000E620:		
	v0 = s6 - 2;
	if (s7 == 0)
		goto loc_0000E634;
	v0 = (u32)s2 < (u32)v0;
	if (v0 != 0)
	{
		*(s16*)(s1 + 0) = 0;
		goto loc_0000E634;
	}

loc_0000E634:		
	s2 = s2 + 2;
	if (s3 == 0)
		goto loc_0000E648;
	a1 = s3;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);

loc_0000E648:		
	v0 = s2;

loc_0000E64C:		
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);

loc_0000E654:		
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_0000E678:		
	v0 = *(u8*)(v0 + 0);
	a0 = a0 << 8;
	s0 = s0 + 1;
	a0 = a0 | v0;
	v0 = onesegHalToolbox_996928FF(...);
	a1 = v0;
	goto loc_0000E5FC;
}

onesegCore_0AAEDDCE(...) // at 0x0000E694 
{
	a1 = a1 & 0xFFFF;
	v1 = a1 - 33;
	a2 = v1 & 0xFF;
	v0 = (u32)a1 >> 8;
	sp = sp - 16;
	v0 = v0 - 32;
	v1 = (u32)a2 < (u32)94;
	*(s32*)(sp + 0) = ra;
	v0 = v0 & 0xFF;
	if (v1 == 0)
		goto loc_0000E718;
	v1 = v0 - 85;
	v0 = (u32)v1 < (u32)10;
	a0 = a1;
	if (v0 == 0)
		goto loc_0000E71C;

	/*v0 = v1 << 2;
	v1 = 0x70000;
	v1 = v1 - 16900;
	v0 = v0 + v1;
	a0 = *(s32*)(v0 + 0);
	a0;*/
	switch (v1)
	{
	case 85:
	}
	
	v0 = 0x00000;

loc_0000E6EC:		
	v1 = a2 << 1;
	v0 = v0 + 236;

loc_0000E6F4:		
	v1 = v1 + v0;
	v0 = *(u16*)(v1 + 0);

loc_0000E6FC:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 424;
	goto loc_0000E6F4;

loc_0000E718:		
	a0 = a1;

loc_0000E71C:		
	a1 = 9632;
	v0 = scePaf_57BFC1C8(...);
	v0 = v0 & 0xFFFF;
	goto loc_0000E6FC;
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 612;
	goto loc_0000E6F4;
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 800;
	goto loc_0000E6F4;
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 988;
	goto loc_0000E6F4;
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 1176;
	goto loc_0000E6F4;
	v0 = 0x00000;
	v1 = a2 << 1;
	v0 = v0 + 1364;
	goto loc_0000E6F4;
}

onesegCore_D23ECC1D(...) // at 0x0000E77C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	t1 = a1;
	t2 = a2;
	t0 = a3;
	v0 = -2;
	if (a0 == 0)
		goto loc_0000E7BC;
	v0 = 0x00000;
	v0 = v0 + 5736;

loc_0000E7A0:		
	v1 = *(s32*)(v0 + 48);
	a1 = a0;
	a2 = t1;
	a0 = v1;
	a3 = t2;
	v0 = -1;
	if (v1 != 0)
		goto loc_0000E7C8;

loc_0000E7BC:		
	ra = *(s32*)(sp + 0);

loc_0000E7C0:		
	sp = sp + 16;
	return (v0);

loc_0000E7C8:		
	v0 = sub_0000F61C(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000E7C0;
}

onesegCore_3F30C2B9(...) // at 0x0000E7D8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v1 = *(s32*)(v0 + 5784);
	v0 = -1;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000E800;
	ra = *(s32*)(sp + 0);

loc_0000E7F8:		
	sp = sp + 16;
	return (v0);

loc_0000E800:		
	v0 = sub_0000F720(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000E7F8;
}

onesegCore_101B2A2B(...) // at 0x0000E810 
{
	v1 = (u32)a1 < (u32)1;
	v0 = (u32)a0 < (u32)1;
	sp = sp - 16;
	v0 = v0 | v1;
	*(s32*)(sp + 0) = s0;
	v1 = -2;
	s0 = a1;
	*(s32*)(sp + 4) = ra;
	if (v0 != 0)
		goto loc_0000E854;
	v0 = 0x00000;
	v0 = v0 + 5736;
	v1 = *(s32*)(v0 + 48);
	a1 = a0;
	v0 = -1;
	a0 = v1;
	if (v1 != 0)
		goto loc_0000E868;

loc_0000E850:		
	v1 = v0;

loc_0000E854:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_0000E868:		
	v0 = sub_0000F794(...);
	*(s8*)(s0 + 0) = v0;
	v0 = 0;
	goto loc_0000E850;
}

onesegCore_8383E17F(...) // at 0x0000E87C 
{
	v0 = 0x10000;
	v0 = v0 | 0x8000;
	v1 = a0 + v0;
	a0 = (u32)a0 < (u32)1;
	v0 = (u32)a2 < (u32)1;

loc_0000E890:		
	a0 = a0 | v0;
	a3 = -2;
	if (a0 != 0)
		goto loc_0000E8E8;
	v0 = *(u8*)(v1 + 17356);
	if (v0 == 0)
		goto loc_0000E8E8;
	if (a1 == 0)
		goto loc_0000E8E8;
	v0 = *(s16*)(v1 + 17352);
	v0 = (u32)a1 < (u32)v0;
	a0 = a1 & 0x3F;
	if (v0 != 0)
		goto loc_0000E8E8;
	if (a0 != 0)
		goto loc_0000E8E8;
	v0 = *(s16*)(v1 + 17354);
	a3 = 0;
	asm("mult       $a1, $v0");
	asm("mflo       $v0");
	v0 = v0 << 2;
	v0 = v0 + 63;
	NONE;
	*(s32*)(a2 + 0) = v0;

loc_0000E8E8:		
	v0 = a3;
	return (v0);
}

onesegCore_452A9ED2(...) // at 0x0000E8F0 
{
	v1 = (u32)a0 < (u32)1;
	v0 = (u32)a3 < (u32)1;
	sp = sp - 96;
	v1 = v1 | v0;
	*(s32*)(sp + 84) = s5;
	s5 = a2;
	a2 = -2;
	*(s32*)(sp + 76) = s3;
	s3 = a3;
	*(s32*)(sp + 72) = s2;
	s2 = a1;
	*(s32*)(sp + 68) = s1;
	s1 = a0;
	*(s32*)(sp + 88) = ra;
	*(s32*)(sp + 80) = s4;
	*(s32*)(sp + 64) = s0;
	if (v1 != 0)
		goto loc_0000E970;
	v0 = 0x10000;
	v0 = v0 | 0x8000;
	s0 = a0 + v0;
	v1 = *(u8*)(s0 + 17356);
	ra = *(s32*)(sp + 88);
	if (v1 == 0)
		goto loc_0000E974;
	if (a1 == 0)
		goto loc_0000E974;
	v0 = *(s16*)(s0 + 17352);
	v0 = (u32)a1 < (u32)v0;
	if (v0 != 0)
	{
		s5 = *(s32*)(sp + 84);
		goto loc_0000E978;
	}
	v0 = a1 & 0x3F;
	if (v0 == 0)
		goto loc_0000E998;

loc_0000E970:		
	ra = *(s32*)(sp + 88);

loc_0000E974:		
	s5 = *(s32*)(sp + 84);

loc_0000E978:		
	s4 = *(s32*)(sp + 80);
	s3 = *(s32*)(sp + 76);
	s2 = *(s32*)(sp + 72);
	s1 = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	v0 = a2;
	sp = sp + 96;
	return (v0);

loc_0000E998:		
	a2 = sp + 48;
	v0 = onesegCore_8383E17F(...);
	a2 = v0;
	if ((s32)v0 < 0)
		goto loc_0000E970;
	v0 = *(s32*)(sp + 48);
	v0 = (u32)s5 < (u32)v0;
	a2 = -2;
	if (v0 != 0)
		goto loc_0000E970;
	a0 = sp;
	a1 = 0;
	a2 = 48;
	v0 = Kernel_Library_A089ECA4(...);
	t1 = *(s16*)(s0 + 17352);
	t0 = *(s16*)(s0 + 17354);
	t2 = 0x10000;
	v1 = (s32)t1 >> 31;
	v0 = (s32)t0 >> 31;
	v0 = (u32)v0 >> 28;
	v1 = (u32)v1 >> 28;
	a2 = 0x10000;

loc_0000E9E8:		
	a3 = 0x10000;
	t0 = t0 + v0;
	t1 = t1 + v1;
	t2 = t2 | 0x2C00;
	a2 = a2 | 0x7700;
	a3 = a3 | 0x9C80;
	a1 = 0x9600;
	a0 = 0xBB80;
	v1 = 0xE100;
	a3 = s1 + a3;
	a1 = s1 + a1;
	a0 = s1 + a0;
	v1 = s1 + v1;
	t2 = s1 + t2;
	a2 = s1 + a2;
	t0 = (s32)t0 >> 4;
	t1 = (s32)t1 >> 4;
	v0 = s1 + 19200;
	*(s32*)(sp + 24) = v0;
	s4 = -1;
	*(s32*)(sp + 32) = a1;
	*(s32*)(sp + 40) = a0;
	*(s32*)(sp + 20) = v1;
	*(s32*)(sp + 28) = t2;
	*(s32*)(sp + 36) = a2;
	*(s32*)(sp + 44) = a3;
	*(s32*)(sp + 0) = t0;
	*(s32*)(sp + 4) = t1;
	*(s32*)(sp + 16) = s1;
	*(s32*)(sp + 8) = 0;
	*(s32*)(sp + 12) = 0;
	v0 = onesegCore_E4FA1424(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_0000EA94;
	a0 = v0;
	a3 = s2;
	a1 = s3;
	a2 = 0;

loc_0000EA80:		
	t0 = sp;
	v0 = onesegCore_669F1BDD(...);
	a0 = s0;
	s4 = v0;
	v0 = onesegCore_6C6A13B0(...);

loc_0000EA94:		
	a1 = *(s32*)(sp + 48);
	a0 = s3;
	v0 = sceKernelDcacheInvalidateRange(...);
	a2 = s4;
	goto loc_0000E970;
}

sub_0000EAA8(...) // at 0x0000EAA8 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 104;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a0 = v0;
	v0 = sub_0000F404(...);
	a1 = s0;
	a0 = s1;
	if (s1 == 0)
		goto loc_0000EB00;
	v0 = sub_0000F488(...);
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_0000EB1C;
	*(s32*)(s2 + 0) = s1;

loc_0000EB00:		
	v0 = 0;

loc_0000EB04:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000EB1C:		
	v0 = sub_0000F520(...);
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 16);
	a0 = s1;
	v0 = $v0(...);
	v0 = s0;
	goto loc_0000EB04;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = sub_0000F520(...);
	s1 = v0;
	a0 = s0;
	if (s0 == 0)
		goto loc_0000EB70;
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(v0 + 16);
	v0 = $v1(...);

loc_0000EB70:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	*(s32*)(a0 + 52) = 0;
	sp = sp - 48;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = s4;
	s4 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 8);
	v0 = $v1(...);
	v0 = *(u8*)(s0 + 4);
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 68);
		goto loc_0000EC08;
	}

loc_0000EBD0:		
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 8);
	v0 = $v1(...);
	ra = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 48;
	return (v0);

loc_0000EC08:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 40);
	v0 = (u32)v1 < (u32)5;
	*(s32*)(s0 + 44) = v1;
	if (v0 == 0)
		goto loc_0000EC68;
	v0 = v1 << 2;
	v1 = 0x70000;
	v1 = v1 - 16860;
	v0 = v0 + v1;
	a0 = *(s32*)(v0 + 0);
	a0;
	if (s1 != 0)
	{
		a0 = *(s32*)(s0 + 52);
		goto loc_0000EC80;
	}
	a0 = *(s32*)(s0 + 68);

loc_0000EC50:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);

loc_0000EC60:		
	a0 = s0;
	v0 = sub_0000F5B8(...);

loc_0000EC68:		
	s1 = *(s32*)(s0 + 44);

loc_0000EC6C:		
	v0 = *(u8*)(s0 + 4);

loc_0000EC70:		
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 68);
		goto loc_0000EC08;
	}
	goto loc_0000EBD0;

loc_0000EC80:		
	v0 = *(s32*)(s0 + 48);
	s2 = s0 + 56;
	s3 = s0 + 60;
	v0 = $v0(...);
	*(s32*)(s0 + 52) = 0;
	a0 = s4;
	v0 = *(s32*)(s0 + 48);

loc_0000EC9C:		

loc_0000ECA0:		
	v0 = $v0(...);
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);

loc_0000ECB0:		
	*(s32*)(sp + 0) = v0;
	a0 = v0;

loc_0000ECB8:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 56);
	a0 = *(s32*)(sp + 0);
	if (v1 == 0)
		goto loc_0000ED10;
	s1 = 0;
	if (s3 == 0)
		goto loc_0000ECDC;
	s1 = *(s32*)(s0 + 60);

loc_0000ECDC:		
	a0 = s2;
	a1 = s2 + 4;
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s4 = s1;
	v0 = $v0(...);
	if (s1 == 0)
	{
		a0 = *(s32*)(s0 + 68);
		goto loc_0000EC50;
	}
	v0 = *(s32*)(s0 + 48);
	a0 = s1;
	goto loc_0000EC9C;

loc_0000ED10:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s4 = 0;
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 68);
	goto loc_0000EC50;
	v0 = sceDisplayGetVcount(...);
	a1 = *(s32*)(s0 + 68);
	*(s32*)(s0 + 72) = v0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	goto loc_0000EC60;

loc_0000ED50:		
	if (s4 == 0)
		goto loc_0000F01C;
	v1 = *(s32*)(s0 + 44);
	v0 = v1 - 3;
	v0 = (u32)v0 < (u32)2;
	a0 = -1;
	if (v0 != 0)
		goto loc_0000ED8C;
	v0 = *(s32*)(s4 + 8);
	if (v0 == a0)
	{
		v0 = *(s32*)(s4 + 12);
		goto loc_0000F00C;
	}

loc_0000ED78:		
	a0 = *(s32*)(s4 + 8);
	a1 = *(s32*)(s4 + 12);
	v0 = sub_0000FA90(...);
	v1 = *(s32*)(s0 + 44);
	a0 = v0;

loc_0000ED8C:		
	v0 = 4;

loc_0000ED94:		
	cond = (v1 == v0);
	v0 = 2;
	if (cond)
		goto loc_0000F000;

loc_0000ED98:		
	v0 = (s32)a0 < (s32)16;
	cond = (v0 != 0);
	v0 = (s32)a0 < (s32)-2000;
	if (cond)
		goto loc_0000EE04;
	v0 = 0x10000;
	v0 = v0 | 0x86A0;
	v0 = (s32)v0 < (s32)a0;
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 68);
		goto loc_0000EDE4;
	}
	v0 = *(s32*)(s0 + 48);

loc_0000EDBC:		
	a0 = s4;
	s4 = 0;
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 68);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = *(u8*)(s0 + 4);
	goto loc_0000EC70;

loc_0000EDE4:		
	v1 = *(s32*)(a0 + 0);

loc_0000EDE8:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = sceDisplayWaitVblankStart(...);
	s1 = *(s32*)(s0 + 44);
	goto loc_0000EC6C;

loc_0000EE04:		
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 48);
		goto loc_0000EDBC;
	}
	t1 = *(s32*)(s0 + 96);
	v0 = -1;
	t2 = t1;
	if (t1 == v0)
		goto loc_0000EFE4;
	t0 = *(s32*)(s0 + 100);

loc_0000EE20:		
	a0 = *(s32*)(s4 + 8);
	a1 = *(s32*)(s4 + 12);
	v1 = 0;
	v0 = 0x80000;

loc_0000EE30:		
	v0 = v0 | 0x3D60;
	t4 = a0 + v0;
	a3 = (u32)t4 < (u32)v0;
	t5 = a1 + v1;
	t5 = t5 + a3;
	a2 = (s32)t5 < (s32)t0;
	if (a2 != 0)
		goto loc_0000EFC4;
	v0 = (u32)t4 < (u32)t2;
	if (t0 == t5)
		goto loc_0000EFBC;

loc_0000EE58:		
	v0 = -1;

loc_0000EE5C:		
	cond = (t1 == v0);
	v0 = 0x7FFF0000;
	if (cond)
		goto loc_0000EFA8;
	v1 = *(s32*)(s4 + 12);

loc_0000EE68:		
	v0 = (s32)v1 < (s32)t0;
	if (v0 != 0)
		goto loc_0000EF68;
	a0 = *(s32*)(s4 + 8);
	if (t0 == v1)
		goto loc_0000EF94;

loc_0000EE7C:		
	v0 = (s32)t0 < (s32)v1;
	if (a0 == t1)
		goto loc_0000EF84;

loc_0000EE84:		

loc_0000EE88:		
	if (v0 != 0)
		goto loc_0000EEE4;
	v0 = (u32)t1 < (u32)a0;
	if (v1 == t0)
		goto loc_0000EEDC;

loc_0000EE94:		
	v0 = *(s32*)(s4 + 8);
	v1 = *(s32*)(s4 + 12);
	*(s32*)(s0 + 80) = v0;
	*(s32*)(s0 + 84) = v1;
	v0 = sceDisplayGetVcount(...);
	*(s32*)(s0 + 72) = v0;
	v0 = *(s32*)(s0 + 48);
	a0 = *(s32*)(s0 + 52);
	v0 = $v0(...);
	a1 = *(s32*)(s0 + 68);
	*(s32*)(s0 + 52) = s4;
	s4 = 0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	s1 = *(s32*)(s0 + 44);
	goto loc_0000EC6C;

loc_0000EEDC:		
	if (v0 == 0)
		goto loc_0000EE94;

loc_0000EEE4:		
	v0 = *(s32*)(s4 + 8);
	v1 = *(s32*)(s4 + 12);
	a0 = *(s32*)(s0 + 96);
	a1 = *(s32*)(s0 + 100);
	a2 = (u32)v0 < (u32)a0;
	v1 = v1 - a1;
	v1 = v1 - a2;

loc_0000EF00:		
	v0 = v0 - a0;
	if ((s32)v1 <= 0)
		goto loc_0000EF44;

loc_0000EF08:		
	v0 = -1;
	v1 = 0x7FFF0000;
	v1 = v1 | 0xFFFF;
	*(s32*)(s0 + 96) = v0;
	*(s32*)(s0 + 100) = v1;

loc_0000EF1C:		
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 12);
	a0 = *(s32*)(s4 + 32);
	v0 = $v1(...);
	a0 = s0;
	a1 = s4;
	v0 = sub_0000F7F4(...);
	goto loc_0000EE94;

loc_0000EF44:		
	v0 = (u32)v0 < (u32)6007;
	if (v1 != 0)
		goto loc_0000EF54;
	if (v0 == 0)
		goto loc_0000EF08;

loc_0000EF54:		
	v0 = -1;
	v1 = 0x7FFF0000;
	v1 = v1 | 0xFFFF;
	*(s32*)(s0 + 96) = v0;
	*(s32*)(s0 + 100) = v1;

loc_0000EF68:		
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 8);
	v0 = $v1(...);
	goto loc_0000EE94;

loc_0000EF84:		
	if (v1 != t0)
		goto loc_0000EE84;
	goto loc_0000EF08;

loc_0000EF94:		
	v0 = (u32)a0 < (u32)t1;
	if (v0 == 0)
		goto loc_0000EE7C;

loc_0000EFA0:		
	goto loc_0000EF68;

loc_0000EFA8:		
	v0 = v0 | 0xFFFF;
	if (t0 != v0)
	{
		v1 = *(s32*)(s4 + 12);
		goto loc_0000EE68;
	}
	goto loc_0000EF1C;

loc_0000EFBC:		
	cond = (v0 == 0);
	v0 = -1;
	if (cond)
		goto loc_0000EE5C;

loc_0000EFC4:		
	v0 = -1;
	v1 = 0x7FFF0000;
	v1 = v1 | 0xFFFF;
	*(s32*)(s0 + 96) = v0;
	*(s32*)(s0 + 100) = v1;
	t1 = *(s32*)(s0 + 96);
	t0 = *(s32*)(s0 + 100);
	goto loc_0000EE58;

loc_0000EFE4:		
	t0 = *(s32*)(s0 + 100);
	v0 = 0x7FFF0000;
	v0 = v0 | 0xFFFF;
	cond = (t0 != v0);
	v0 = -1;
	if (cond)
		goto loc_0000EE20;
	goto loc_0000EE5C;

loc_0000F000:		
	*(s32*)(s0 + 40) = v0;
	a0 = 0;
	goto loc_0000ED98;

loc_0000F00C:		
	if (v0 != a0)
		goto loc_0000ED78;
	v0 = *(s32*)(s0 + 48);
	goto loc_0000EDBC;

loc_0000F01C:		
	s1 = s0 + 56;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 56);
	v0 = s0 + 60;
	if (v1 == 0)
		goto loc_0000F09C;
	s2 = 0;
	if (v0 == 0)
		goto loc_0000F054;
	s2 = *(s32*)(s0 + 60);

loc_0000F054:		
	a0 = s1;
	a1 = s1 + 4;
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	s1 = s2;

loc_0000F068:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s4 = s1;
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 68);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	if (s1 != 0)
	{
		s1 = *(s32*)(s0 + 44);
		goto loc_0000EC6C;
	}
	goto loc_0000EC60;

loc_0000F09C:		
	a0 = *(s32*)(sp + 0);
	s1 = 0;
	goto loc_0000F068;
	v1 = s1 ^ 0x2;
	v0 = s1 ^ 0x4;
	v1 = (u32)0 < (u32)v1;
	v0 = (u32)0 < (u32)v0;
	v1 = v1 & v0;
	if (v1 == 0)
		goto loc_0000ED50;
	a0 = *(s32*)(s0 + 68);
	goto loc_0000EC50;
}

sub_0000F0CC(...) // at 0x0000F0CC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_0000F0F0;
	v0 = onesegSdkCore_ADCCA76D(...);
	v1 = v0;

loc_0000F0F0:		
	ra = *(s32*)(sp + 0);

loc_0000F0F4:		
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_0000F100(...) // at 0x0000F100 
{
	v0 = 1;
	*(s8*)(a0 + 4) = v0;

loc_0000F108:		
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000F5EC(...);
	v1 = 0;
	v0 = *(s32*)(s0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F140;

loc_0000F12C:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_0000F140:		
	v0 = onesegSdkCore_EE0853A1(...);
	v1 = v0;
	goto loc_0000F12C;
}

sub_0000F150(...) // at 0x0000F150 
{
	sp = sp - 48;
	*(s32*)(sp + 40) = s2;
	s2 = a0 + 56;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 44) = ra;
	a0 = *(s32*)(a0 + 68);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 44);
	a0 = s1;
	if (v1 != 0)
		goto loc_0000F1C8;
	v0 = *(s32*)(s0 + 48);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);

loc_0000F1A0:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);

loc_0000F1C8:		
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 16) = v0;

loc_0000F1D8:		
	a1 = *(s32*)(v1 + 0);
	a0 = v0;
	v0 = $a1(...);
	a1 = *(s32*)(s2 + 8);
	a2 = s1;
	a0 = s2;
	v0 = sub_00011ED8(...);
	a0 = *(s32*)(sp + 16);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s0;
	v0 = sub_0000F5EC(...);
	a0 = *(s32*)(sp + 0);
	goto loc_0000F1A0;
}

sub_0000F218(...) // at 0x0000F218 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 24) = ra;
	a0 = *(s32*)(a0 + 68);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s0 = a1;
	v0 = $v0(...);
	a0 = s1;
	*(s32*)(s1 + 40) = s0;
	if (s0 != 0)
		goto loc_0000F264;
	v0 = -1;
	v1 = 0x7FFF0000;
	v1 = v1 | 0xFFFF;
	*(s32*)(s1 + 96) = v0;
	*(s32*)(s1 + 100) = v1;

loc_0000F264:		
	v0 = sub_0000F5EC(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000F294(...) // at 0x0000F294 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v0 = 2;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	if (a1 == 0)
		goto loc_0000F2EC;
	a0 = *(s32*)(a0 + 68);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(s0 + 44);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(s1 + 0) = v0;
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 0;

loc_0000F2EC:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_0000F300(...) // at 0x0000F300 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 68);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(s0 + 80);
	v1 = *(s32*)(s0 + 84);
	a1 = *(s32*)(a0 + 0);
	*(s32*)(s1 + 0) = v0;
	*(s32*)(s1 + 4) = v1;
	v0 = *(s32*)(a1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_0000F368(...) // at 0x0000F368 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 8);
	v0 = $v1(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_0000F394(...) // at 0x0000F394 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(a0 + 68);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s0 = a1;
	v0 = $v0(...);
	*(s32*)(s1 + 76) = s0;

loc_0000F3C4:		
	s0 = (u32)s0 < (u32)1;
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 16);
	a0 = s0;
	v0 = $v1(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_0000F404(...) // at 0x0000F404 
{
	sp = sp - 16;
	v0 = 0x70000;
	*(s32*)(sp + 4) = s1;
	v0 = v0 - 16160;
	s1 = 1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(a0 + 0) = v0;
	*(s32*)(s0 + 40) = s1;
	*(s32*)(s0 + 44) = s1;
	*(s8*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;
	*(s8*)(s0 + 28) = 0;
	*(s8*)(s0 + 29) = 0;
	*(s32*)(sp + 8) = ra;
	a0 = a0 + 56;
	v0 = sub_00011F5C(...);
	v0 = -1;
	v1 = 0x7FFF0000;
	v1 = v1 | 0xFFFF;
	*(s32*)(s0 + 76) = s1;
	*(s32*)(s0 + 96) = v0;
	*(s32*)(s0 + 100) = v1;
	*(s32*)(s0 + 80) = v0;
	*(s32*)(s0 + 84) = v1;
	*(s32*)(s0 + 88) = v0;
	*(s32*)(s0 + 92) = v1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000F488(...) // at 0x0000F488 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = onesegSal_74AF7C06(...);
	v1 = 0x81000000;
	a0 = s0 + 24;
	*(s32*)(s0 + 12) = v0;
	v1 = v1 | 0x3;
	if (v0 == 0)
		goto loc_0000F500;
	v0 = onesegHalToolbox_35CAA030(...);
	a0 = s0 + 68;
	if ((s32)v0 < 0)
		goto loc_0000F518;
	v0 = onesegHalToolbox_35CAA030(...);
	a0 = s0 + 8;
	a1 = s1;
	a2 = 5;
	a3 = 16384;
	if ((s32)v0 < 0)
		goto loc_0000F518;
	v0 = onesegSdkCore_F942A64D(...);
	a1 = s0;
	if ((s32)v0 < 0)
		goto loc_0000F518;
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSdkCore_00565C73(...);
	v1 = 0;

loc_0000F500:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_0000F518:		
	v1 = v0;
	goto loc_0000F500;
}

sub_0000F520(...) // at 0x0000F520 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_0000F100(...);
	v1 = *(s32*)(s0 + 8);

loc_0000F538:		
	a0 = v1;
	if (v1 != 0)
		goto loc_0000F5A8;

loc_0000F540:		
	v0 = *(s32*)(s0 + 68);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F598;

loc_0000F54C:		
	v0 = *(s32*)(s0 + 24);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F588;

loc_0000F558:		
	v0 = *(s32*)(s0 + 12);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F578;

loc_0000F564:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000F578:		
	v0 = onesegSal_6086187E(...);
	*(s32*)(s0 + 12) = 0;
	goto loc_0000F564;

loc_0000F588:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s0 + 24) = 0;
	goto loc_0000F558;

loc_0000F598:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s0 + 68) = 0;
	goto loc_0000F54C;

loc_0000F5A8:		
	v0 = onesegSdkCore_C13FF004(...);
	*(s32*)(s0 + 8) = 0;
	goto loc_0000F540;
}

sub_0000F5B8(...) // at 0x0000F5B8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = -1;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F5DC;
	ra = *(s32*)(sp + 0);

loc_0000F5D4:		
	sp = sp + 16;
	return (v0);

loc_0000F5DC:		
	v0 = onesegSdkCore_A66140B4(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000F5D4;
}

sub_0000F5EC(...) // at 0x0000F5EC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_0000F60C;
	ra = *(s32*)(sp + 0);

loc_0000F604:		
	sp = sp + 16;
	return (v0);

loc_0000F60C:		
	v0 = onesegSdkCore_C65BBBDC(...);
	ra = *(s32*)(sp + 0);
	goto loc_0000F604;
}

sub_0000F61C(...) // at 0x0000F61C 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = -3;

loc_0000F628:		
	*(s32*)(sp + 16) = s4;
	s4 = a3;
	*(s32*)(sp + 12) = s3;
	s3 = t0;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	a0 = *(s32*)(a0 + 24);
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 0);
	s1 = a1;
	v0 = $v1(...);
	v0 = 0x10000;
	v0 = v0 | 0x8000;
	v0 = s1 + v0;
	*(s8*)(v0 + 17356) = 0;
	v0 = -1;
	*(s32*)(s0 + 16) = s1;
	if (s2 == 0)
		goto loc_0000F684;
	v0 = *(s32*)(s2 + 0);

loc_0000F684:		
	a0 = *(s32*)(s0 + 24);
	v1 = 1;
	*(s8*)(s0 + 29) = v1;
	a1 = *(s32*)(a0 + 0);

loc_0000F694:		
	*(s8*)(s0 + 28) = v1;
	*(s32*)(s0 + 20) = v0;
	*(s32*)(s0 + 32) = s4;
	*(s32*)(s0 + 36) = s3;
	v0 = *(s32*)(a1 + 4);
	v0 = $v0(...);
	a1 = *(s32*)(s0 + 20);
	a0 = *(s32*)(s0 + 12);
	v0 = onesegSal_A74C56C6(...);
	a0 = *(s32*)(s0 + 24);
	v1 = *(s32*)(a0 + 0);

loc_0000F6C4:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 24);
	*(s8*)(s0 + 29) = 0;

loc_0000F6D8:		
	v0 = 0x10000;
	v0 = v0 | 0x8000;
	v1 = *(s32*)(a0 + 0);
	v0 = s1 + v0;
	a1 = *(u8*)(v0 + 17356);
	a2 = *(s32*)(v1 + 4);
	if (a1 != 0)
		s5 = 0;
	v0 = $a2(...);
	v0 = s5;
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
}

sub_0000F720(...) // at 0x0000F720 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = *(s32*)(a0 + 24);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 28);
	if (v1 == 0)
	{
		a0 = *(s32*)(s0 + 24);
		goto loc_0000F760;
	}
	v0 = *(u8*)(s0 + 29);
	*(s8*)(s0 + 28) = 0;
	if (v0 != 0)
		goto loc_0000F784;
	a0 = *(s32*)(s0 + 24);

loc_0000F760:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000F784:		
	a0 = *(s32*)(s0 + 12);
	v0 = onesegSal_3F2ADE66(...);
	a0 = *(s32*)(s0 + 24);
	goto loc_0000F760;
}

sub_0000F794(...) // at 0x0000F794 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	a0 = *(s32*)(a0 + 24);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	s0 = a1;
	v0 = $v0(...);
	a0 = *(s32*)(s1 + 24);
	v0 = 0x10000;
	v0 = v0 | 0x8000;
	v1 = *(s32*)(a0 + 0);
	s0 = s0 + v0;
	v0 = *(s32*)(v1 + 4);
	s1 = *(u8*)(s0 + 17356);
	v0 = $v0(...);
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0000F7F4(...) // at 0x0000F7F4 
{
	sp = sp - 144;
	*(s32*)(sp + 128) = fp;
	*(s32*)(sp + 124) = s7;
	s7 = a0;
	*(s32*)(sp + 132) = ra;
	*(s32*)(sp + 120) = s6;
	*(s32*)(sp + 116) = s5;
	*(s32*)(sp + 112) = s4;
	*(s32*)(sp + 108) = s3;
	*(s32*)(sp + 104) = s2;
	*(s32*)(sp + 100) = s1;
	*(s32*)(sp + 96) = s0;
	a0 = *(s32*)(a0 + 24);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	fp = a1;
	v0 = $v0(...);
	v1 = *(u8*)(s7 + 28);
	if (v1 == 0)
	{
		a0 = *(s32*)(s7 + 24);
		goto loc_0000F868;
	}
	v0 = *(s16*)(fp + 28);
	v0 = (s32)v0 < (s32)321;
	if (v0 == 0)
	{
		a0 = *(s32*)(s7 + 24);
		goto loc_0000F868;
	}
	v0 = *(s16*)(fp + 30);
	v0 = (s32)v0 < (s32)241;
	if (v0 != 0)
	{
		s0 = *(s32*)(s7 + 16);
		goto loc_0000F8A8;
	}

loc_0000F864:		
	a0 = *(s32*)(s7 + 24);

loc_0000F868:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 132);
	fp = *(s32*)(sp + 128);
	s7 = *(s32*)(sp + 124);
	s6 = *(s32*)(sp + 120);
	s5 = *(s32*)(sp + 116);
	s4 = *(s32*)(sp + 112);
	s3 = *(s32*)(sp + 108);
	s2 = *(s32*)(sp + 104);
	s1 = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	sp = sp + 144;
	return (v0);

loc_0000F8A8:		
	a1 = *(s32*)(fp + 32);
	a0 = 0x10000;
	a0 = a0 | 0xC200;
	a0 = s0 + a0;
	a2 = 400;
	v0 = Kernel_Library_1839852A(...);
	s4 = *(s16*)(fp + 30);
	s5 = *(s16*)(fp + 28);
	v0 = 0x10000;
	*(s32*)(sp + 0) = s4;
	v0 = v0 | 0xC218;
	v0 = s0 + v0;
	*(s32*)(sp + 4) = s5;
	t1 = 0x10000;
	t2 = 0x10000;
	s6 = *(s32*)(v0 + 28);
	t4 = *(s32*)(v0 + 0);

loc_0000F8EC:		
	t5 = *(s32*)(v0 + 8);
	t6 = *(s32*)(v0 + 16);
	t7 = *(s32*)(v0 + 24);
	s1 = *(s32*)(v0 + 4);
	s2 = *(s32*)(v0 + 12);
	s3 = *(s32*)(v0 + 20);
	t0 = 0x10000;
	t1 = t1 | 0x2C00;
	t2 = t2 | 0x7700;
	t0 = t0 | 0x9C80;
	a3 = 0x9600;
	v1 = 0xBB80;
	v0 = 0xE100;
	t0 = s0 + t0;
	a3 = s0 + a3;
	v1 = s0 + v1;
	v0 = s0 + v0;
	t1 = s0 + t1;
	t2 = s0 + t2;
	t3 = s0 + 19200;

loc_0000F93C:		
	a0 = sp + 48;
	a1 = sp;
	a2 = 3;
	*(s32*)(sp + 16) = t4;
	*(s32*)(sp + 24) = t5;

loc_0000F950:		
	*(s32*)(sp + 32) = t6;
	*(s32*)(sp + 40) = t7;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 28) = s2;
	*(s32*)(sp + 36) = s3;
	*(s32*)(sp + 44) = s6;
	*(s32*)(sp + 48) = s4;
	*(s32*)(sp + 52) = s5;
	*(s32*)(sp + 72) = t3;
	*(s32*)(sp + 80) = a3;
	*(s32*)(sp + 88) = v1;
	*(s32*)(sp + 68) = v0;
	*(s32*)(sp + 76) = t1;
	*(s32*)(sp + 84) = t2;
	*(s32*)(sp + 92) = t0;
	*(s32*)(sp + 64) = s0;
	v0 = sceMpegBaseYCrCbCopy(...);
	cond = ((s32)v0 < 0);
	v0 = 0x10000;
	if (cond)
		goto loc_0000F864;
	a0 = *(s32*)(s7 + 16);
	a2 = *(u16*)(fp + 28);
	v0 = v0 | 0x8000;
	a0 = a0 + v0;
	v1 = 1;
	*(s8*)(a0 + 17356) = v1;
	*(s16*)(a0 + 17352) = a2;
	v0 = *(s32*)(fp + 40);
	v1 = *(s32*)(fp + 44);
	a1 = *(u16*)(fp + 30);
	a2 = *(u8*)(s7 + 29);
	*(s32*)(a0 + 17344) = v0;
	*(s32*)(a0 + 17348) = v1;
	*(s16*)(a0 + 17354) = a1;
	*(s8*)(s7 + 28) = 0;
	if (a2 != 0)
		goto loc_0000FA24;
	v0 = *(s32*)(s7 + 32);

loc_0000F9E0:		
	a0 = *(s32*)(s7 + 24);
	if (v0 == 0)
		goto loc_0000F868;
}

sub_0000F9E8(...) // at 0x0000F9E8 
{
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = *(s32*)(s7 + 36);
	v0 = *(s32*)(s7 + 32);
	a1 = 0;
	v0 = $v0(...);
	a0 = *(s32*)(s7 + 24);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(s7 + 24);
	goto loc_0000F868;

loc_0000FA24:		
	a0 = *(s32*)(s7 + 12);
	v0 = onesegSal_3F2ADE66(...);
	v0 = *(s32*)(s7 + 32);
	goto loc_0000F9E0;
}

sub_0000FA34(...) // at 0x0000FA34 
{
	a1 = 1;
	a3 = -1;
	a2 = -1;
	v1 = 0;
	v0 = 1024;
	*(s8*)(a0 + 80) = a1;
	*(s32*)(a0 + 24) = a2;
	*(s32*)(a0 + 28) = a3;
	*(s32*)(a0 + 32) = v0;
	*(s32*)(a0 + 36) = v1;
	*(s32*)(a0 + 0) = 0;
	*(s8*)(a0 + 8) = 0;
	*(s8*)(a0 + 9) = 0;
	*(s8*)(a0 + 10) = 0;
	*(s32*)(a0 + 16) = a2;
	*(s32*)(a0 + 20) = a3;
	*(s32*)(a0 + 56) = 0;
	*(s8*)(a0 + 68) = 0;
	*(s8*)(a0 + 69) = 0;
	*(s8*)(a0 + 70) = 0;
	*(s32*)(a0 + 72) = a1;
	*(s32*)(a0 + 76) = a1;
	return (v0);
}

sub_0000FA90(...) // at 0x0000FA90 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v0 = 0x00000;
	v1 = v0 + 5736;
	*(s32*)(sp + 16) = s0;
	v0 = -1;

loc_0000FAA8:		
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	s1 = a1;
	a2 = *(s32*)(v1 + 16);
	a0 = sp;
	if (a2 == v0)
		goto loc_0000FB30;

loc_0000FAC0:		
	a1 = 0x7FFF0000;
	v0 = -1;
	a1 = a1 | 0xFFFF;
	if (s0 == v0)
		goto loc_0000FB20;

loc_0000FAD0:		
	v0 = onesegHalToolbox_7A7C971B(...);
	a3 = 0;
	a2 = 90;
	v1 = 0;
	if ((s32)v0 < 0)
		goto loc_0000FB08;
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	v0 = (u32)s0 < (u32)a0;
	a1 = s1 - a1;
	a0 = s0 - a0;
	a1 = a1 - v0;
	v0 = sub_0000345C(...);
	v1 = v0;

loc_0000FB08:		
	ra = *(s32*)(sp + 24);

loc_0000FB0C:		
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_0000FB20:		
	v1 = 0;
	if (s1 != a1)
		goto loc_0000FAD0;
	ra = *(s32*)(sp + 24);
	goto loc_0000FB0C;

loc_0000FB30:		
	v0 = *(s32*)(v1 + 20);
	v1 = 0;
	if (v0 != a2)
		goto loc_0000FAC0;
	ra = *(s32*)(sp + 24);
	goto loc_0000FB0C;
}

onesegCore_52DA7BB0(...) // at 0x0000FB44 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	v1 = 0x00000;
	s0 = v1 + 5736;
	*(s32*)(sp + 20) = ra;
	a0 = s0 + 40;
	v0 = *(s32*)(v1 + 5736);
	v0 = v0 + 1;
	a1 = (s32)v0 < (s32)2;
	*(s32*)(v1 + 5736) = v0;
	v0 = 0;
	if (a1 != 0)
		goto loc_0000FB84;

loc_0000FB74:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000FB84:		
	v0 = onesegHalToolbox_35CAA030(...);
	a1 = 0x20000;
	a1 = a1 - 14832;	// "VW_VideoDecodeTask"
	a0 = sp;
	if ((s32)v0 < 0)
		goto loc_0000FC18;
	v0 = sub_00015908(...);
	a1 = 0x20000;
	a0 = s0 + 52;
	a1 = a1 - 14812;	// "VW_CaptionRenderTask"
	if ((s32)v0 < 0)
		goto loc_0000FC18;
	v1 = *(s32*)(sp + 0);
	v0 = 0x10000;
	v0 = v0 + 1804;
	*(s32*)(v1 + 2008) = v0;

loc_0000FBC4:		
	*(s32*)(s0 + 44) = v1;
	v0 = sub_00014C80(...);
	a1 = 0x20000;
	a0 = s0 + 48;
	a1 = a1 - 14788;	// "VW_VideoRenderTask"
	if ((s32)v0 < 0)
		goto loc_0000FC18;
	v0 = sub_0000EAA8(...);
	v1 = 1;
	if ((s32)v0 < 0)
		goto loc_0000FC18;
	a0 = *(s32*)(s0 + 48);
	v0 = 0x10000;
	v0 = v0 + 1864;
	*(s32*)(a0 + 48) = v0;
	*(s8*)(s0 + 8) = v1;
	*(s32*)(s0 + 4) = v1;
	v0 = sub_0000F0CC(...);
	a0 = *(s32*)(s0 + 52);
	v0 = sub_000150A0(...);
	v0 = 0;
	goto loc_0000FB74;

loc_0000FC18:		
	*(s32*)(s0 + 0) = 0;
	v0 = 2;
	goto loc_0000FB74;
}

onesegCore_96DFC77E(...) // at 0x0000FC24 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = 0x00000;
	s0 = v1 + 5736;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(v1 + 5736);
	v0 = v0 - 1;
	*(s32*)(v1 + 5736) = v0;
	if ((s32)v0 <= 0)
		goto loc_0000FC5C;

loc_0000FC48:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_0000FC5C:		
	v0 = *(u8*)(s0 + 8);
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 44);
		goto loc_0000FC84;
	}
	a0 = *(s32*)(s0 + 48);
	*(s8*)(s0 + 8) = 0;
	if (a0 != 0)
		goto loc_0000FD14;
	a0 = *(s32*)(s0 + 52);

loc_0000FC78:		
	if (a0 != 0)
		goto loc_0000FD04;
	a0 = *(s32*)(s0 + 44);

loc_0000FC84:		
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_0000FCF0;
	}

loc_0000FC8C:		
	a0 = *(s32*)(s0 + 48);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_0000FCDC;
	}

loc_0000FC98:		
	a0 = *(s32*)(s0 + 52);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_0000FCC8;
	}

loc_0000FCA4:		
	a0 = *(s32*)(s0 + 40);
	if (a0 != 0)
		goto loc_0000FCB8;

loc_0000FCB0:		
	*(s32*)(s0 + 0) = 0;
	goto loc_0000FC48;

loc_0000FCB8:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s0 + 40) = 0;
	goto loc_0000FCB0;

loc_0000FCC8:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 52) = 0;
	goto loc_0000FCA4;

loc_0000FCDC:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 48) = 0;
	goto loc_0000FC98;

loc_0000FCF0:		
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 44) = 0;
	goto loc_0000FC8C;

loc_0000FD04:		
	v0 = sub_000150D4(...);
	a0 = *(s32*)(s0 + 44);
	goto loc_0000FC84;

loc_0000FD14:		
	v0 = sub_0000F100(...);
	a0 = *(s32*)(s0 + 52);
	goto loc_0000FC78;
}

onesegCore_4EFCB25E(...) // at 0x0000FD24 
{
	v0 = 0;
	return (v0);
}

onesegCore_678E8026(...) // at 0x0000FD2C 
{
	v0 = 0x00000;
	v1 = t0 - 1024;
	t1 = v0 + 5736;
	v1 = (u32)v1 < (u32)1025;
	*(s32*)(t1 + 16) = a0;
	*(s32*)(t1 + 20) = a1;
	a1 = 0;
	a0 = 1024;
	*(s32*)(t1 + 24) = a2;
	*(s32*)(t1 + 28) = a3;
	v0 = 0;
	if (v1 == 0)
		goto loc_0000FD64;
	a0 = t0;
	a1 = 0;

loc_0000FD64:		
	*(s32*)(t1 + 32) = a0;
	*(s32*)(t1 + 36) = a1;
	return (v0);
}

onesegCore_36B11A27(...) // at 0x0000FD70 
{
	sp = sp - 48;
	*(s32*)(sp + 40) = ra;
	*(s32*)(sp + 36) = s5;
	s5 = 0x00000;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;

loc_0000FD88:		
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	a1 = s2;
	*(s32*)(sp + 20) = s1;
	s1 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = s5 + 5736;
	s4 = s0;
	a0 = *(s32*)(s0 + 48);
	v0 = sub_0000F218(...);
	a0 = *(s32*)(s0 + 52);
	a1 = s2;
	s0 = 0;
	v0 = sub_00015484(...);
	v0 = onesegSal_39AF4F3B(...);
	s3 = v0;

loc_0000FDCC:		
	v0 = onesegSal_39AF4F3B(...);
	v0 = v0 - s3;
	v0 = (u32)v0 < (u32)2000;
	a1 = sp;
	if (v0 == 0)
		goto loc_0000FE0C;
	if (s0 == 0)
		goto loc_0000FE54;

loc_0000FDEC:		
	a1 = sp;
	if (s1 == 0)
		goto loc_0000FE3C;

loc_0000FDF4:		
	a0 = 10;
	v0 = onesegSal_FB5FE576(...);
	if (s0 == 0)
		goto loc_0000FDCC;

loc_0000FE04:		
	if (s1 == 0)
		goto loc_0000FDCC;

loc_0000FE0C:		
	v0 = s5 + 5736;
	*(s32*)(v0 + 4) = s2;
	v0 = 0;
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);

loc_0000FE2C:		
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_0000FE3C:		
	a0 = *(s32*)(s4 + 52);
	v0 = sub_000154E4(...);
	v1 = *(s32*)(sp + 0);
	asm("xor        $v1, $v1, $s2");
	s1 = (u32)v1 < (u32)1;
	goto loc_0000FDF4;

loc_0000FE54:		
	a0 = *(s32*)(s4 + 48);
	v0 = sub_0000F294(...);
	v1 = *(s32*)(sp + 0);
	asm("xor        $v1, $v1, $s2");
	s0 = (u32)v1 < (u32)1;
	goto loc_0000FDEC;
}

onesegCore_5E49C77E(...) // at 0x0000FE6C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	s0 = s0 + 5736;
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(s0 + 40);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 8);
	v0 = *(s32*)(sp + 0);
	if (v1 != 0)
		goto loc_0000FEC8;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;

loc_0000FEB8:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000FEC8:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0;
	goto loc_0000FEB8;
}

onesegCore_AAA66B27(...) // at 0x0000FEE0 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	s0 = s0 + 5736;
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(s0 + 40);

loc_0000FEF8:		
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 8);
	if (v1 != 0)
		goto loc_0000FF40;
	v0 = *(s32*)(sp + 0);
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;

loc_0000FF30:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000FF40:		
	v0 = onesegCore_42BB1BDC(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	v0 = 0;
	goto loc_0000FF30;
}

onesegCore_8F5E044D(...) // at 0x0000FF64 
{
	sp = sp - 48;
	v0 = 0x00000;
	*(s32*)(sp + 20) = s1;
	s1 = v0 + 5736;
	v1 = *(s32*)(s1 + 40);
	*(s32*)(sp + 28) = s3;
	s3 = a0;
	a0 = v1;
	*(s32*)(sp + 24) = s2;
	s2 = a1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	v0 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v1 = *(s32*)(v0 + 0);
	s0 = a2 & 0xFF;
	v0 = $v1(...);
	v0 = *(u8*)(s1 + 9);
	a0 = *(s32*)(sp + 0);
	if (v0 == 0)
		goto loc_0000FFE4;
	a0 = *(s32*)(s1 + 56);
	if (s0 != 0)
		goto loc_00010040;
	if (a0 == 0)
	{
		a0 = *(s32*)(sp + 0);
		goto loc_0000FFE4;
	}

loc_0000FFC4:		
	v1 = *(s32*)(a0 + 28);
	a1 = *(s32*)(s1 + 64);
	v0 = *(s32*)(s2 + 0);
	a0 = v1 - a1;
	v0 = (u32)a0 < (u32)v0;
	cond = (v0 == 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00010014;

loc_0000FFE0:		
	a0 = *(s32*)(sp + 0);

loc_0000FFE4:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 1;

loc_0000FFF8:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00010014:		
	v1 = *(s32*)(s1 + 60);
	*(s32*)(s2 + 0) = a0;
	a0 = v0;
	v1 = v1 + a1;
	a1 = *(s32*)(v0 + 0);
	*(s32*)(s3 + 0) = v1;
	v0 = *(s32*)(a1 + 4);
	v0 = $v0(...);
	v0 = 0;
	goto loc_0000FFF8;

loc_00010040:		
	if (a0 != 0)
	{
		v0 = *(s32*)(a0 + 24);
		goto loc_0001009C;
	}
	a0 = *(s32*)(s1 + 40);

loc_0001004C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = *(s32*)(s1 + 44);
	v0 = sub_00015A00(...);
	a0 = *(s32*)(s1 + 40);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s1 + 9);
	if (v1 == 0)
		goto loc_000100A8;
	if (s0 == 0)
	{
		a0 = *(s32*)(s1 + 40);
		goto loc_0001004C;
	}
	*(s32*)(s1 + 56) = s0;
	a0 = s0;
	v0 = *(s32*)(a0 + 24);

loc_0001009C:		
	*(s32*)(s1 + 64) = 0;
	*(s32*)(s1 + 60) = v0;
	goto loc_0000FFC4;

loc_000100A8:		
	a0 = s0;
	if (s0 == 0)
		goto loc_0000FFE0;
	a1 = 4;
	v0 = sub_00013218(...);
	v1 = *(s32*)(s0 + 0);
	v0 = *(s32*)(v1 + 0);
	a0 = s0;
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	goto loc_0000FFE4;
}

onesegCore_C19A063F(...) // at 0x000100D0 
{
	sp = sp - 32;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = v0 + 5736;
	v1 = *(s32*)(s0 + 40);
	*(s32*)(sp + 20) = s1;

loc_000100E8:		
	s1 = a0;
	*(s32*)(sp + 24) = ra;
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 9);
	v0 = *(s32*)(sp + 0);
	if (v1 != 0)
		goto loc_00010138;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);

loc_0001011C:		
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;

loc_00010124:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00010138:		
	*(s32*)(s0 + 64) = s1;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0;
	goto loc_00010124;
}

onesegCore_6776E47D(...) // at 0x00010154 
{
	sp = sp - 64;
	v0 = 0x00000;
	*(s32*)(sp + 32) = s4;
	s4 = v0 + 5736;
	*(s32*)(sp + 44) = s7;
	s7 = t0 & 0xFF;
	*(s32*)(sp + 40) = s6;
	s6 = t1 & 0xFF;
	*(s32*)(sp + 36) = s5;
	s5 = a1;
	*(s32*)(sp + 28) = s3;
	s3 = a3;
	*(s32*)(sp + 24) = s2;
	s2 = a2;
	*(s32*)(sp + 20) = s1;
	s1 = t3;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 48) = ra;
	a0 = *(s32*)(s4 + 40);
	v0 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v1 = *(s32*)(v0 + 0);
	s0 = t2;
	v0 = $v1(...);
	v0 = *(u8*)(s4 + 9);
	if (v0 != 0)
	{
		a0 = *(s32*)(s4 + 56);
		goto loc_00010204;
	}
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 1;

loc_000101D8:		
	ra = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 64;
	return (v0);

loc_00010204:		
	a1 = s5;
	v0 = sub_00013218(...);
	a0 = *(s32*)(s4 + 56);
	v0 = -1;
	*(s32*)(a0 + 32) = s2;
	*(s32*)(a0 + 36) = s3;
	*(s8*)(a0 + 40) = s6;
	*(s8*)(a0 + 41) = s7;
	if (s0 == v0)
		goto loc_000102C0;

loc_00010228:		
	v0 = *(u8*)(s4 + 80);

loc_0001022C:		
	if (v0 == 0)
	{
		v0 = v0 & 0xFF;
		goto loc_00010254;
	}
	if (s7 == 0)
	{
		v0 = v0 & 0xFF;
		goto loc_00010254;
	}
	v1 = -1;
	if (s0 == v1)
		goto loc_000102B0;
	*(s8*)(s4 + 80) = 0;

loc_0001024C:		
	v0 = 0;
	v0 = v0 & 0xFF;

loc_00010254:		
	if (v0 == 0)
		goto loc_000102A0;
	v1 = -1;
	v0 = -1;
	*(s32*)(a0 + 48) = v0;
	*(s32*)(a0 + 52) = v1;
	a0 = *(s32*)(s4 + 44);

loc_00010270:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 40);
	a1 = *(s32*)(s4 + 56);
	v0 = $v0(...);
	a1 = *(s32*)(sp + 0);
	*(s32*)(s4 + 56) = 0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	v0 = 0;
	goto loc_000101D8;

loc_000102A0:		
	*(s32*)(a0 + 48) = s0;
	*(s32*)(a0 + 52) = s1;
	a0 = *(s32*)(s4 + 44);
	goto loc_00010270;

loc_000102B0:		
	if (s1 != v1)
	{
		*(s8*)(s4 + 80) = 0;
		goto loc_0001024C;
	}
	v0 = v0 & 0xFF;
	goto loc_00010254;

loc_000102C0:		
	if (s1 != v0)
	{
		v0 = *(u8*)(s4 + 80);
		goto loc_0001022C;
	}
	v0 = 1;
	*(s8*)(s4 + 80) = v0;
	goto loc_00010228;
}

onesegCore_65EDA589(...) // at 0x000102D4 
{
	sp = sp - 32;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = v0 + 5736;
	a0 = *(s32*)(s0 + 40);
	*(s32*)(sp + 20) = ra;
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 44);
	v1 = *(s32*)(s0 + 48);
	v0 = 1;
	a1 = *(s32*)(a0 + 0);
	a2 = -1;
	a3 = 0x7FFF0000;
	a3 = a3 | 0xFFFF;
	*(s8*)(s0 + 80) = v0;
	*(s8*)(s0 + 9) = v0;
	*(s8*)(s0 + 10) = v0;
	*(s32*)(v1 + 88) = a2;
	*(s32*)(v1 + 92) = a3;
	*(s32*)(v1 + 80) = a2;
	*(s32*)(v1 + 84) = a3;

loc_00010338:		
	*(s8*)(s0 + 68) = 0;
	*(s32*)(s0 + 56) = 0;
	v0 = *(s32*)(a1 + 48);
	v0 = $v0(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00010398;
	v0 = *(s32*)(s0 + 44);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	v0 = *(s32*)(v1 + 32);
	v0 = $v0(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00010398;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0;

loc_00010388:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);

loc_00010394:		
	sp = sp + 32;
	return (v0);

loc_00010398:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;
	goto loc_00010388;
}

onesegCore_C7AF840F(...) // at 0x000103B0 
{
	sp = sp - 32;
	v0 = 0x00000;
	*(s32*)(sp + 20) = s1;
	s1 = v0 + 5736;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(s1 + 40);
	v1 = *(s32*)(a0 + 0);

loc_000103D0:		
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s1 + 8);
	a1 = 16;
	if (v1 == 0)
		goto loc_000104CC;
	v0 = *(s32*)(s1 + 44);
	a0 = 2;
	*(s8*)(s1 + 9) = 0;
	if (v0 != 0)
		goto loc_00010480;
	v0 = *(s32*)(s1 + 56);

loc_00010400:		
	a1 = 4;
	a0 = v0;
	if (v0 != 0)
		goto loc_0001045C;

loc_0001040C:		
	v0 = *(s32*)(s1 + 44);
	a0 = v0;
	if (v0 != 0)
		goto loc_00010444;
	a0 = *(s32*)(sp + 0);

loc_0001041C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 0;

loc_00010430:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00010444:		
	v1 = *(s32*)(v0 + 0);
	v0 = *(s32*)(v1 + 52);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	goto loc_0001041C;

loc_0001045C:		
	v0 = sub_00013218(...);
	a0 = *(s32*)(s1 + 56);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s1 + 56) = 0;
	goto loc_0001040C;

loc_00010480:		
	v0 = onesegSdkCore_838A1E79(...);
	a1 = 0x7FFF0000;
	a0 = v0;
	a1 = a1 | 0xFFFF;
	s0 = v0;
	v0 = onesegSdkCore_ED582126(...);
	a0 = *(s32*)(s1 + 44);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	a1 = s0;
	v0 = $v0(...);
	a0 = *(s32*)(s1 + 44);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 36);
	v0 = $v0(...);
	v0 = *(s32*)(s1 + 56);
	goto loc_00010400;

loc_000104CC:		
	v0 = *(s32*)(sp + 0);
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;
	goto loc_00010430;
}

onesegCore_5BC4D11C(...) // at 0x000104E8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a1 = a0;
	a0 = *(s32*)(v0 + 5784);
	v0 = sub_0000F300(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_42BB1BDC(...) // at 0x0001050C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 5784);
	v0 = sub_0000F368(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0001052C(...) // at 0x0001052C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v0 = v0 + 5736;
	v1 = *(u8*)(v0 + 69);
	a1 = 0;
	if (v1 != 0)
		goto loc_0001054C;
	a1 = *(s32*)(v0 + 72);

loc_0001054C:		
	a0 = *(s32*)(v0 + 48);
	v0 = sub_0000F394(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_19332984(...) // at 0x00010560 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	s1 = s1 + 5736;
	*(s32*)(sp + 16) = s0;
	s0 = a0 & 0xFF;
	v1 = *(s32*)(s1 + 40);
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	*(s8*)(s1 + 69) = s0;
	v0 = sub_0001052C(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_5887EAF7(...) // at 0x000105C4 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	s0 = s0 + 5736;
	v0 = *(s32*)(s0 + 40);
	a1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	v1 = *(s32*)(a1 + 0);
	a0 = v0;
	v0 = $v1(...);

loc_000105FC:		
	*(s32*)(s0 + 72) = s1;
	v0 = sub_0001052C(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_149D4626(...) // at 0x00010630 
{
	sp = sp - 32;
	v0 = 0x00000;
	*(s32*)(sp + 20) = s1;
	s1 = v0 + 5736;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	v1 = *(s32*)(s1 + 40);
	*(s32*)(sp + 24) = ra;
	a1 = *(s32*)(v1 + 0);
	*(s32*)(sp + 0) = v1;
	v0 = *(s32*)(a1 + 0);
	a0 = v1;
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	if (s0 == 0)
		goto loc_00010674;
	v0 = *(s32*)(s1 + 72);
	*(s32*)(s0 + 0) = v0;

loc_00010674:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

onesegCore_54B4AFCB(...) // at 0x0001069C 
{
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v0 + 5736;
	a1 = 4;
	*(s32*)(sp + 4) = ra;
	if (s0 == 0)
		goto loc_000106E8;
	a0 = *(s32*)(s0 + 48);
	v0 = sub_0000F218(...);
	a0 = 50;
	v0 = onesegSal_FB5FE576(...);
	a0 = *(s32*)(s0 + 52);
	a1 = 4;
	v0 = sub_00015484(...);
	v0 = 0x00000;
	v1 = *(s32*)(v0 + 4628);
	a1 = 4;
	a0 = v1;
	if (v1 != 0)
		goto loc_000106FC;

loc_000106E8:		
	ra = *(s32*)(sp + 4);

loc_000106EC:		
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_000106FC:		
	v0 = sub_000146F4(...);
	ra = *(s32*)(sp + 4);
	goto loc_000106EC;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v0 = *(s32*)(v0 + 5784);
	a1 = a0;
	if (v0 == 0)
		goto loc_00010738;
	a0 = v0;
	v0 = sub_0000F150(...);
	ra = *(s32*)(sp + 0);

loc_00010730:		
	sp = sp + 16;
	return (v0);

loc_00010738:		
	v0 = sub_00010748(...);
	ra = *(s32*)(sp + 0);
	goto loc_00010730;
}

sub_00010748(...) // at 0x00010748 
{
	v0 = 0x00000;
	v1 = *(s32*)(v0 + 5780);
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = v1;
	if (v1 != 0)
		goto loc_00010770;
	ra = *(s32*)(sp + 0);

loc_00010768:		
	sp = sp + 16;
	return (v0);

loc_00010770:		
	v0 = sub_00015A40(...);
	ra = *(s32*)(sp + 0);
	goto loc_00010768;
	sp = sp - 16;
	a0 = 1;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_000059B8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000107A0(...) // at 0x000107A0 
{
	*(s32*)(a0 + 4) = a2;
	*(s32*)(a0 + 0) = a1;
	return (v0);
}

sub_000107AC(...) // at 0x000107AC 
{
	return (v0);
}

sub_000107B4(...) // at 0x000107B4 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	a1 = 0;
	a2 = 64;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 4);
	v0 = Kernel_Library_A089ECA4(...);
	a0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(s0 + 4);
	v0 = 0x46500000;
	a1 = 0x31300000;
	t0 = *(s32*)(a0 + 16);
	t2 = *(s32*)(a0 + 12);
	t1 = *(s32*)(a0 + 8);
	v0 = v0 | 0x4453;
	a1 = a1 | 0x3030;
	*(s32*)(v1 + 0) = v0;
	v0 = 0;
	*(s32*)(v1 + 4) = a1;
	a2 = *(s32*)(t0 + 4);
	a0 = *(s32*)(t1 + 4);
	a1 = *(s32*)(t2 + 4);
	a3 = *(s32*)(t0 + 12);
	t3 = *(s32*)(t1 + 8);
	t0 = *(u16*)(t2 + 8);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	a0 = a0 - v1;
	a1 = a1 - v1;
	a2 = a2 - v1;
	*(s32*)(v1 + 28) = a3;
	*(s32*)(v1 + 8) = a0;
	*(s32*)(v1 + 12) = a1;
	*(s32*)(v1 + 16) = a2;
	*(s32*)(v1 + 20) = t3;
	*(s16*)(v1 + 24) = t0;
	sp = sp + 32;
	return (v0);
}

sub_00010850(...) // at 0x00010850 
{
	*(s32*)(a0 + 8) = a3;
	*(s32*)(a0 + 0) = a1;
	*(s32*)(a0 + 4) = a2;
	return (v0);
}

sub_00010860(...) // at 0x00010860 
{
	return (v0);
}

sub_00010868(...) // at 0x00010868 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 0;
	v0 = *(s32*)(a0 + 8);
	a0 = *(s32*)(a0 + 4);
	a2 = v0 << 1;
	a2 = a2 + v0;
	a2 = a2 << 4;
	v0 = Kernel_Library_A089ECA4(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_0001089C(...) // at 0x0001089C 
{
	a2 = *(s32*)(a0 + 8);
	a3 = *(s32*)(a0 + 4);
	a0 = 0;
	if (a2 == 0)
		goto loc_000108CC;
	v1 = a3;
	v0 = *(s8*)(v1 + 0);

loc_000108B4:		
	v1 = v1 + 48;
	if (v0 == 0)
		goto loc_000108CC;
	a0 = a0 + 1;
	v0 = (u32)a0 < (u32)a2;
	if (v0 != 0)
	{
		v0 = *(s8*)(v1 + 0);
		goto loc_000108B4;
	}

loc_000108CC:		
	v1 = 0x80100000;
	v0 = (u32)a0 < (u32)a2;
	v1 = v1 | 0x9812;
	if (v0 == 0)
		goto loc_000108F4;
	v0 = a0 << 1;
	v0 = v0 + a0;
	v0 = v0 << 4;
	v0 = a3 + v0;
	*(s32*)(a1 + 0) = v0;
	v1 = 0;

loc_000108F4:		
	v0 = v1;
	return (v0);
}

sub_000108FC(...) // at 0x000108FC 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s6;
	s6 = a2;
	*(s32*)(sp + 16) = s4;
	s4 = a1;
	*(s32*)(sp + 12) = s3;
	s3 = a0;
	a0 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = 0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 0) = s0;
	s5 = *(s32*)(s3 + 4);
	v0 = scePaf_D7DCB972(...);
	a0 = *(s32*)(s3 + 8);
	s1 = v0;
	v1 = (u32)v0 < (u32)32;
	v0 = 31;
	if (v1 == 0)
		s1 = v0;
	if (a0 == 0)
		goto loc_00010994;
	s0 = s5;
	a1 = s0;

loc_0001095C:		
	a0 = s4;
	a2 = s1;
	v0 = scePaf_E0B32AE8(...);
	v1 = s0 + s1;
	s0 = s0 + 48;
	if (v0 != 0)
		goto loc_00010980;
	v0 = *(s8*)(v1 + 0);
	if (v0 == 0)
	{
		a0 = *(s32*)(s3 + 8);
		goto loc_00010994;
	}

loc_00010980:		
	a0 = *(s32*)(s3 + 8);
	s2 = s2 + 1;
	v0 = (u32)s2 < (u32)a0;
	a1 = s0;
	if (v0 != 0)
		goto loc_0001095C;

loc_00010994:		
	v1 = 0x80100000;
	v0 = (u32)s2 < (u32)a0;
	v1 = v1 | 0x9814;
	if (v0 == 0)
		goto loc_000109BC;
	v0 = s2 << 1;
	v0 = v0 + s2;
	v0 = v0 << 4;
	v0 = s5 + v0;
	*(s32*)(s6 + 0) = v0;
	v1 = 0;

loc_000109BC:		
	ra = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_000109E8(...) // at 0x000109E8 
{
	v0 = 0;
	*(s32*)(a1 + 40) = 0;
	*(s8*)(a1 + 0) = 0;
	*(s16*)(a1 + 32) = 0;
	*(s16*)(a1 + 34) = 0;
	return (v0);
}

sub_00010A00(...) // at 0x00010A00 
{
	a3 = a3 & 0xFFFF;
	v0 = 0xFFFF;
	v1 = a3 - 1;
	*(s32*)(a0 + 0) = a1;
	*(s32*)(a0 + 4) = a2;
	*(s16*)(a0 + 8) = a3;
	if (a3 == v0)
		goto loc_00010A24;
	return (v0);

loc_00010A24:		
	*(s16*)(a0 + 8) = v1;
	return (v0);
}

sub_00010A2C(...) // at 0x00010A2C 
{
	return (v0);
}

sub_00010A34(...) // at 0x00010A34 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 0;
	a2 = *(u16*)(a0 + 8);
	a0 = *(s32*)(a0 + 4);
	a2 = a2 << 1;
	v0 = Kernel_Library_A089ECA4(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00010A60(...) // at 0x00010A60 
{
	a3 = 0x80100000;
	a1 = a1 & 0xFFFF;
	a3 = a3 | 0x9811;
	if (a1 == 0)
		goto loc_00010A94;
	v0 = *(u16*)(a0 + 8);
	v0 = (u32)v0 < (u32)a1;
	v1 = a1 << 1;
	if (v0 != 0)
		goto loc_00010A94;
	v0 = *(s32*)(a0 + 4);
	a3 = 0;
	v0 = v0 + v1;
	v1 = *(u16*)(v0 - 2);
	*(s16*)(a2 + 0) = v1;

loc_00010A94:		
	v0 = a3;
	return (v0);
}

sub_00010A9C(...) // at 0x00010A9C 
{
	v1 = 0x80100000;
	a1 = a1 & 0xFFFF;
	v1 = v1 | 0x9811;
	a2 = a2 & 0xFFFF;
	if (a1 == 0)
		goto loc_00010AD0;
	v0 = *(u16*)(a0 + 8);
	v0 = (u32)v0 < (u32)a1;
	a3 = a1 << 1;
	if (v0 != 0)
		goto loc_00010AD0;
	v0 = *(s32*)(a0 + 4);
	v1 = 0;
	v0 = v0 + a3;
	*(s16*)(v0 - 2) = a2;

loc_00010AD0:		
	v0 = v1;
	return (v0);
}

sub_00010AD8(...) // at 0x00010AD8 
{
	t1 = *(u16*)(a0 + 8);
	t2 = *(s32*)(a0 + 4);
	v0 = t1 & 0xFFFF;
	a3 = 0;
	if (v0 == 0)
		goto loc_00010B18;
	t0 = v0;
	v0 = a3 << 1;

loc_00010AF4:		
	a2 = v0 + t2;
	v0 = *(u16*)(a2 + 0);
	v1 = a3 + 1;
	if (v0 == 0)
		goto loc_00010B3C;
	a3 = v1 & 0xFFFF;
	v0 = (u32)a3 < (u32)t0;
	cond = (v0 != 0);
	v0 = a3 << 1;
	if (cond)
		goto loc_00010AF4;

loc_00010B14:		
	v0 = t1 & 0xFFFF;

loc_00010B18:		
	v1 = 0x80100000;
	v0 = (u32)a3 < (u32)v0;
	v1 = v1 | 0x9812;
	if (v0 == 0)
		goto loc_00010B34;
	v0 = a3 + 1;
	*(s16*)(a1 + 0) = v0;
	v1 = 0;

loc_00010B34:		
	v0 = v1;
	return (v0);

loc_00010B3C:		
	v0 = -1;
	*(s16*)(a2 + 0) = v0;
	t1 = *(u16*)(a0 + 8);
	goto loc_00010B14;
}

sub_00010B4C(...) // at 0x00010B4C 
{
	a1 = a1 & 0xFFFF;
	v1 = (u32)a2 >> 31;
	v0 = (u32)a1 < (u32)1;
	sp = sp - 48;
	v0 = v0 | v1;
	*(s32*)(sp + 36) = s5;
	s5 = t1;
	*(s32*)(sp + 32) = s4;
	s4 = t0;
	*(s32*)(sp + 28) = s3;
	s3 = a0;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	if (v0 != 0)
		goto loc_00010BA0;
	v0 = *(u16*)(a0 + 8);
	v0 = (u32)v0 < (u32)a1;
	if (v0 == 0)
	{
		v0 = *(s32*)(a0 + 0);
		goto loc_00010BD4;
	}

loc_00010BA0:		
	v1 = 0x80100000;
	v1 = v1 | 0x9811;

loc_00010BA8:		
	ra = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00010BD4:		
	s0 = a2 + a3;
	v1 = *(s32*)(v0 + 16);
	s1 = *(s32*)(v1 + 12);
	v0 = (u32)s0 < (u32)s1;
	s2 = a1;
	if (v0 != 0)
		goto loc_00010C28;
	s6 = 0xFFFF;
	a1 = s2;

loc_00010BF4:		
	a0 = s3;
	a2 = sp;
	v0 = sub_00010A60(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00010BA8;
	v0 = *(u16*)(sp + 0);
	if (v0 == s6)
	{
		*(s16*)(s4 + 0) = s2;
		goto loc_00010C2C;
	}
	s0 = s0 - s1;
	s2 = v0;
	v0 = (u32)s0 < (u32)s1;
	if (v0 == 0)
	{
		a1 = s2;
		goto loc_00010BF4;
	}

loc_00010C28:		
	*(s16*)(s4 + 0) = s2;

loc_00010C2C:		
	v1 = 0;
	*(s32*)(s5 + 0) = s0;
	goto loc_00010BA8;
}

sub_00010C38(...) // at 0x00010C38 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 28) = s3;
	s3 = 0xFFFF;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	*(s32*)(sp + 16) = s0;
	s0 = a1 & 0xFFFF;
	a1 = s0;

loc_00010C60:		
	a0 = s2;
	a2 = sp;
	v0 = sub_00010A60(...);
	s1 = v0;
	a1 = s0;
	a0 = s2;
	a2 = 0;
	if ((s32)v0 < 0)
		goto loc_00010C94;
	v0 = sub_00010A9C(...);
	s0 = *(u16*)(sp + 0);
	a1 = s0;
	if (s0 != s3)
		goto loc_00010C60;

loc_00010C94:		
	v0 = s1;
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);
}

sub_00010CB4(...) // at 0x00010CB4 
{
	*(s32*)(a0 + 12) = t0;
	*(s32*)(a0 + 0) = a1;
	*(s32*)(a0 + 4) = a2;
	*(s16*)(a0 + 8) = a3;
	return (v0);
}

sub_00010CC8(...) // at 0x00010CC8 
{
	return (v0);
}

sub_00010CD0(...) // at 0x00010CD0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 0;
	a2 = *(u16*)(a0 + 8);
	v0 = *(s32*)(a0 + 12);
	asm("mult       $a2, $v0");
	asm("mflo       $a2");
	a0 = *(s32*)(a0 + 4);
	v0 = Kernel_Library_A089ECA4(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00010D04(...) // at 0x00010D04 
{
	sp = sp - 16;
	t1 = 0x80100000;
	a2 = a2 & 0xFFFF;

loc_00010D10:		
	v1 = a0;
	*(s32*)(sp + 0) = ra;
	t1 = t1 | 0x9811;
	a0 = a1;
	if (a2 == 0)
		goto loc_00010D48;
	v0 = *(u16*)(v1 + 8);
	v0 = (u32)v0 < (u32)a2;
	t2 = t0 + a3;
	if (v0 != 0)
		goto loc_00010D48;
	a1 = *(s32*)(v1 + 12);
	t3 = a2 - 1;
	v0 = (u32)a1 < (u32)t2;
	a2 = a3;
	if (v0 == 0)
		goto loc_00010D58;

loc_00010D48:		
	ra = *(s32*)(sp + 0);
	v0 = t1;
	sp = sp + 16;
	return (v0);

loc_00010D58:		
	asm("mult       $t3, $a1");
	a1 = *(s32*)(v1 + 4);
	asm("mflo       $v0");
	a1 = a1 + v0;
}

sub_00010D6C(...) // at 0x00010D6C 
{
	a1 = a1 + t0;
	v0 = Kernel_Library_1839852A(...);
	t1 = 0;
	goto loc_00010D48;
}

sub_00010D78(...) // at 0x00010D78 
{
	sp = sp - 16;
	v1 = 0x80100000;
	a2 = a2 & 0xFFFF;
	*(s32*)(sp + 0) = ra;
	v1 = v1 | 0x9811;
	if (a2 == 0)
		goto loc_00010DB4;
	v0 = *(u16*)(a0 + 8);
	v0 = (u32)v0 < (u32)a2;
	t2 = t0 + a3;
	if (v0 != 0)
		goto loc_00010DB4;
	t1 = *(s32*)(a0 + 12);
	t3 = a2 - 1;
	v0 = (u32)t1 < (u32)t2;
	a2 = a3;
	if (v0 == 0)
		goto loc_00010DC4;

loc_00010DB4:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00010DC4:		
	asm("mult       $t3, $t1");
	a0 = *(s32*)(a0 + 4);
	asm("mflo       $v0");
	a0 = a0 + v0;
	a0 = a0 + t0;
	v0 = Kernel_Library_1839852A(...);
	v1 = 0;
	goto loc_00010DB4;
}

sub_00010DE4(...) // at 0x00010DE4 
{
	v0 = (u32)a1 < (u32)1;
	v1 = (u32)t2 < (u32)1;
	sp = sp - 64;
	v0 = v0 | v1;
	*(s32*)(sp + 48) = fp;
	t4 = a1;
	fp = t3;
	*(s32*)(sp + 44) = s7;
	a1 = a3 & 0xFFFF;
	s7 = t2;
	*(s32*)(sp + 36) = s5;
	t2 = 0;
	s5 = a2;
	*(s32*)(sp + 20) = s1;
	a2 = t0;
	s1 = a0;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 16) = s0;
	if (v0 != 0)
		goto loc_00010E58;
	a0 = *(s32*)(sp + 64);
	v0 = (u32)t3 < (u32)1;
	v1 = (u32)a0 < (u32)1;
	v0 = v0 | v1;
	s3 = t4;
	if (v0 == 0)
		goto loc_00010E90;

loc_00010E58:		
	v0 = 0x80100000;
	v0 = v0 | 0x9811;

loc_00010E60:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);

loc_00010E8C:		
	sp = sp + 64;
	return (v0);

loc_00010E90:		
	s4 = a1;
	s2 = t1;
	s6 = 0;
	if (s5 != 0)
		goto loc_00010EB8;

loc_00010EA0:		
	v1 = *(s32*)(sp + 64);

loc_00010EA4:		
	*(s32*)(s7 + 0) = s6;
	v0 = t2;
	*(s16*)(fp + 0) = s4;
	*(s32*)(v1 + 0) = s2;
	goto loc_00010E60;

loc_00010EB8:		
	v0 = *(s32*)(s1 + 0);

loc_00010EBC:		
	a1 = s4;
	a3 = s2;
	a0 = *(s32*)(v0 + 12);
	t0 = sp;
	t1 = sp + 4;
	v0 = sub_00010B4C(...);
	t2 = v0;
	a1 = s3;
	a0 = s1;
	s0 = s5 - s6;
	if ((s32)v0 < 0)
		goto loc_00010EA0;
	v0 = *(s32*)(sp + 4);
	v1 = *(s32*)(s1 + 12);
	t2 = 0x80100000;
	t0 = v0;
	a2 = v1 - v0;
	v1 = (u32)v1 < (u32)v0;
	v0 = (u32)a2 < (u32)s0;
	if (v0 != 0)
		s0 = a2;
	t2 = t2 | 0x9813;
	a3 = s0;
	if (v1 != 0)
		goto loc_00010EA0;
	a2 = *(u16*)(sp + 0);
	s6 = s6 + s0;
	s3 = s3 + s0;
	v0 = sub_00010D04(...);
	t2 = v0;
	v0 = *(s32*)(sp + 4);
	v1 = (u32)s6 < (u32)s5;
	s4 = *(u16*)(sp + 0);
	s2 = v0 + s0;

loc_00010F38:		
	a2 = 0;
	if ((s32)t2 < 0)
		goto loc_00010EA0;
	if (v1 != 0)
	{
		v0 = *(s32*)(s1 + 0);
		goto loc_00010EBC;
	}
	v1 = *(s32*)(sp + 64);
	goto loc_00010EA4;
}

sub_00010F50(...) // at 0x00010F50 
{
	v0 = (u32)a1 < (u32)1;
	v1 = (u32)t2 < (u32)1;
	sp = sp - 80;
	v0 = v0 | v1;
	*(s32*)(sp + 44) = s3;
	t4 = a1;
	s3 = a0;
	*(s32*)(sp + 40) = s2;
	a1 = a3 & 0xFFFF;
	s2 = a2;
	*(s32*)(sp + 36) = s1;
	s1 = 0;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 64) = fp;
	*(s32*)(sp + 60) = s7;
	*(s32*)(sp + 56) = s6;
	*(s32*)(sp + 52) = s5;
	*(s32*)(sp + 48) = s4;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 8) = t2;
	*(s32*)(sp + 12) = t3;
	if (v0 != 0)
		goto loc_00010FC0;
	a0 = *(s32*)(sp + 80);
	v0 = (u32)t3 < (u32)1;
	v1 = (u32)a0 < (u32)1;
	v0 = v0 | v1;
	if (v0 == 0)
	{
		v0 = *(s32*)(s3 + 0);
		goto loc_00010FF8;
	}

loc_00010FC0:		
	v0 = 0x80100000;
	v0 = v0 | 0x9811;

loc_00010FC8:		
	ra = *(s32*)(sp + 68);
	fp = *(s32*)(sp + 64);
	s7 = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 80;
	return (v0);

loc_00010FF8:		
	s6 = t4;
	s5 = a1;
	fp = *(s32*)(v0 + 12);
	*(s32*)(sp + 16) = t0;
	s4 = t1;
	s7 = 0;
	if (s2 != 0)
		goto loc_00011034;

loc_00011014:		
	a1 = *(s32*)(sp + 8);

loc_00011018:		
	v1 = *(s32*)(sp + 12);
	a0 = *(s32*)(sp + 80);
	*(s32*)(a1 + 0) = s7;
	v0 = s1;
	*(s16*)(v1 + 0) = s5;
	*(s32*)(a0 + 0) = s4;
	goto loc_00010FC8;

loc_00011034:		
	a2 = *(s32*)(sp + 16);

loc_00011038:		
	a1 = s5;
	a0 = fp;
	a3 = s4;
	t0 = sp;
	t1 = sp + 4;
	v0 = sub_00010B4C(...);
	s1 = v0;
	a1 = s6;
	a0 = s3;
	s0 = s2 - s7;
	if ((s32)v0 < 0)
		goto loc_00011014;
	v1 = *(s32*)(sp + 4);
	a2 = *(s32*)(s3 + 12);
	t0 = v1;
	a3 = a2 - v1;
	v0 = (u32)a3 < (u32)s0;
	if (v0 != 0)
		s0 = a3;
	v1 = (u32)v1 < (u32)a2;
	a3 = s0;
	if (v1 == 0)
		goto loc_000110C4;
	a2 = *(u16*)(sp + 0);
	*(s32*)(sp + 16) = 0;
	s6 = s6 + s0;
	v0 = sub_00010D78(...);
	s1 = v0;
	v0 = *(s32*)(sp + 4);
	s7 = s7 + s0;
	s5 = *(u16*)(sp + 0);
	s4 = v0 + s0;
	if ((s32)s1 < 0)
		goto loc_00011014;
	v0 = (u32)s7 < (u32)s2;

loc_000110B4:		
	a2 = *(s32*)(sp + 16);
	if (v0 != 0)
		goto loc_00011038;
	a1 = *(s32*)(sp + 8);
	goto loc_00011018;

loc_000110C4:		
	a0 = fp;
	a1 = sp + 2;
	v0 = sub_00010AD8(...);
	s1 = v0;
	a0 = fp;
	if ((s32)v0 < 0)
		goto loc_00011014;
	a1 = *(u16*)(sp + 0);
	a2 = *(u16*)(sp + 2);
	v0 = sub_00010A9C(...);
	v0 = (u32)s7 < (u32)s2;
	goto loc_000110B4;
}

sub_000110F0(...) // at 0x000110F0 
{
	*(s32*)(a0 + 20) = 0;
	*(s32*)(a0 + 0) = 0;
	*(s32*)(a0 + 4) = 0;
	*(s16*)(a0 + 8) = 0;
	*(s32*)(a0 + 12) = 0;
	*(s32*)(a0 + 16) = 0;
	return (v0);
}

sub_0001110C(...) // at 0x0001110C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_000110F0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00011128(...) // at 0x00011128 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_000110F0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00011144(...) // at 0x00011144 
{
	t1 = *(s32*)(a0 + 8);
	v1 = 0;
	a3 = 0;
	if (t1 == 0)
		goto loc_00011180;
	a1 = *(s32*)(a0 + 0);
	t0 = 0;

loc_0001115C:		
	v0 = *(u8*)(a1 + 0);
	a3 = a3 + 1;
	v0 = v0 ^ 0x1;
	v0 = v0 & 0x1;
	a2 = (u32)a3 < (u32)t1;
	if (v0 != 0)
		goto loc_00011188;
	a1 = a1 + 4;
	t0 = t0 + 24;
	if (a2 != 0)
		goto loc_0001115C;

loc_00011180:		
	v0 = v1;
	return (v0);

loc_00011188:		
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(a0 + 4);
	v0 = v0 | 0x1;
	v1 = v1 + t0;
	*(s32*)(a1 + 0) = v0;
	goto loc_00011180;
}

sub_000111A0(...) // at 0x000111A0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = a0;
	v0 = 0xAAAA0000;
	a0 = *(s32*)(a0 + 4);
	v0 = v0 | 0xAAAB;
	a3 = *(s32*)(v1 + 0);
	a1 = a1 - a0;
	asm("multu      $a1, $v0");
	asm("mfhi       $a1");
	a1 = (u32)a1 >> 4;
	v1 = a1 << 2;
	v1 = v1 + a3;
	a2 = *(s32*)(v1 + 0);
	v0 = a1 << 1;
	v0 = v0 + a1;
	NONE;
	*(s32*)(v1 + 0) = a2;
	v0 = v0 << 3;
	a0 = a0 + v0;
	v0 = sub_000110F0(...);
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00011204(...) // at 0x00011204 
{
	sp = sp - 32;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = a1 << 1;
	*(s32*)(a0 + 8) = s0;
	a1 = a1 + s0;
	a1 = a1 << 3;
	*(s32*)(sp + 16) = s4;
	a1 = a1 + 4;
	s4 = a0;
	a0 = 0;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 20) = ra;
	s1 = s0 - 1;
	v0 = onesegSal_265926E7(...);
	s3 = v0 + 4;
	*(s32*)(s3 - 4) = s0;
	s2 = s3;
	if (s0 == 0)
		goto loc_00011270;
	s0 = -1;

loc_0001125C:		
	a0 = s2;
	s1 = s1 - 1;
	v0 = sub_0001110C(...);
	s2 = s2 + 24;
	if (s1 != s0)
		goto loc_0001125C;

loc_00011270:		
	a1 = *(s32*)(s4 + 8);
	*(s32*)(s4 + 4) = s3;
	a0 = 0;
	a1 = a1 << 2;
	v0 = onesegSal_265926E7(...);
	a1 = *(s32*)(s4 + 8);
	*(s32*)(s4 + 0) = v0;
	a0 = 0;
	if (a1 == 0)
		goto loc_000112AC;
	v1 = v0;

loc_00011298:		
	a0 = a0 + 1;
	v0 = (u32)a0 < (u32)a1;
	*(s32*)(v1 + 0) = 0;
	v1 = v1 + 4;
	if (v0 != 0)
		goto loc_00011298;

loc_000112AC:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
}

sub_000112CC(...) // at 0x000112CC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	a1 = *(s32*)(a0 + 4);
	s1 = a0;
	if (a1 == 0)
		goto loc_0001132C;
	v1 = *(s32*)(a1 - 4);
	v0 = v1 << 1;
	v0 = v0 + v1;
	v0 = v0 << 3;
	s0 = a1 + v0;

loc_000112FC:		
	cond = (a1 == s0);
	s0 = s0 - 24;
	if (cond)
		goto loc_00011314;
	a0 = s0;
	v0 = sub_00011128(...);
	a1 = *(s32*)(s1 + 4);
	goto loc_000112FC;

loc_00011314:		
	a1 = a1 - 4;
	if (a1 == 0)
	{
		*(s32*)(s1 + 4) = 0;
		goto loc_0001132C;
	}
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s1 + 4) = 0;

loc_0001132C:		
	a1 = *(s32*)(s1 + 0);
	if (a1 != 0)
		goto loc_0001134C;

loc_00011338:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0001134C:		
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s1 + 0) = 0;
	goto loc_00011338;
}

sub_0001135C(...) // at 0x0001135C 
{
	sp = sp - 48;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(s2 + 0) = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 8;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s7;
	s7 = t2;
	*(s32*)(sp + 24) = s6;
	s6 = t1;
	*(s32*)(sp + 20) = s5;
	s5 = t0;
	*(s32*)(sp + 16) = s4;

loc_0001139C:		
	s4 = a3 & 0xFFFF;
	*(s32*)(sp + 12) = s3;
	s3 = a2;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSal_265926E7(...);
	s1 = v0;

loc_000113B4:		
	a2 = s0;
	a0 = v0;
	a1 = s2;
	v0 = sub_000107A0(...);
	*(s32*)(s2 + 4) = s1;
	a0 = 0;
	a1 = 12;
	v0 = onesegSal_265926E7(...);
	s0 = s0 + 64;
	s1 = v0;
	a2 = s0;
	a3 = s3;
	a0 = v0;

loc_000113E8:		
	a1 = s2;
	v0 = sub_00010850(...);
	*(s32*)(s2 + 8) = s1;
	v0 = s3 << 1;
	v0 = v0 + s3;
	v0 = v0 << 4;
	a0 = 0;
	a1 = 12;
	s0 = s0 + v0;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a2 = s0;
	a3 = s4;
	a0 = v0;
	a1 = s2;
	v0 = sub_00010A00(...);
	*(s32*)(s2 + 12) = s1;
	v0 = s4 << 1;

loc_00011430:		
	a0 = 0;
	a1 = 16;
	s0 = s0 + v0;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a2 = s0;
	a3 = s4;
	t0 = s5;
	a0 = v0;
	a1 = s2;
	v0 = sub_00010CB4(...);
	*(s32*)(s2 + 16) = s1;
	a0 = 0;
	a1 = 12;
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	a1 = s6;
	a0 = v0;
	v0 = sub_00011204(...);
	*(s32*)(s2 + 24) = s7;
	*(s32*)(s2 + 20) = s0;
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);
}

sub_000114B0(...) // at 0x000114B0 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = *(s32*)(a0 + 4);
	s1 = a0;
	if (s0 != 0)
		goto loc_00011580;
	s0 = *(s32*)(s1 + 8);

loc_000114D0:		
	if (s0 != 0)
		goto loc_00011564;
	s0 = *(s32*)(s1 + 12);

loc_000114DC:		
	if (s0 != 0)
		goto loc_00011548;
	s0 = *(s32*)(s1 + 16);

loc_000114E8:		
	if (s0 != 0)
		goto loc_0001152C;
	s0 = *(s32*)(s1 + 20);

loc_000114F4:		
	if (s0 != 0)
		goto loc_00011510;
	ra = *(s32*)(sp + 8);

loc_00011500:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00011510:		
	a0 = s0;
	v0 = sub_000112CC(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 8);
	goto loc_00011500;

loc_0001152C:		
	a0 = s0;
	v0 = sub_00010CC8(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	s0 = *(s32*)(s1 + 20);
	goto loc_000114F4;

loc_00011548:		
	a0 = s0;
	v0 = sub_00010A2C(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	s0 = *(s32*)(s1 + 16);
	goto loc_000114E8;

loc_00011564:		
	a0 = s0;
	v0 = sub_00010860(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	s0 = *(s32*)(s1 + 12);
	goto loc_000114DC;

loc_00011580:		
	a0 = s0;
	v0 = sub_000107AC(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	s0 = *(s32*)(s1 + 8);
	goto loc_000114D0;
}

sub_0001159C(...) // at 0x0001159C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	a1 = sp;
	a0 = *(s32*)(a0 + 24);
	v0 = sub_00013020(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_000115BC(...) // at 0x000115BC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	if (a1 == 0)
		goto loc_000115EC;
	a0 = *(s32*)(a0 + 0);
	v0 = Kernel_Library_1839852A(...);
	ra = *(s32*)(sp + 4);

loc_000115DC:		
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_000115EC:		
	a0 = *(s32*)(a0 + 4);
	v0 = sub_000107B4(...);
	a0 = *(s32*)(s0 + 8);
	v0 = sub_00010868(...);
	a0 = *(s32*)(s0 + 12);
	v0 = sub_00010A34(...);
	a0 = *(s32*)(s0 + 16);
	v0 = sub_00010CD0(...);
	ra = *(s32*)(sp + 4);
	goto loc_000115DC;
}

sub_00011614(...) // at 0x00011614 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;

loc_0001161C:		
	s4 = a2;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(a0 + 20);
	v0 = sub_00011144(...);
	s0 = v0;
	if (s3 == 0)
		goto loc_00011654;
	*(s32*)(s3 + 0) = 0;

loc_00011654:		
	a1 = s2;
	if (s0 == 0)
		goto loc_000116D4;
	a0 = *(s32*)(s1 + 8);
	a2 = s0;
	v0 = sub_000108FC(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_000116B8;
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(s0 + 20);
	*(s32*)(s0 + 12) = 0;
	a1 = s0;
	v1 = v1 | s4;
	a0 = *(u16*)(v0 + 32);
	*(s32*)(s0 + 20) = v1;
	*(s16*)(s0 + 8) = a0;
	*(s32*)(s0 + 16) = 0;

loc_00011694:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a1;
	sp = sp + 32;
	return (v0);

loc_000116B8:		
	a0 = *(s32*)(s1 + 20);
	a1 = s0;
	v0 = sub_000111A0(...);
	if (s3 != 0)
	{
		*(s32*)(s3 + 0) = s2;
		goto loc_000116CC;
	}

loc_000116CC:		
	a1 = 0;
	goto loc_00011694;

loc_000116D4:		
	v0 = 0x80100000;
	if (s3 == 0)
		goto loc_000116CC;
	v0 = v0 | 0x9815;
	*(s32*)(s3 + 0) = v0;
	goto loc_000116CC;
}

sub_000116E8(...) // at 0x000116E8 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s6;
	s6 = a1;
	*(s32*)(sp + 12) = s3;
	s3 = 2;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a3;
	*(s32*)(sp + 0) = s0;
	s0 = a2 & 0xFFFF;
	*(s32*)(sp + 28) = ra;

loc_00011718:		
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	if (a3 == 0)
		goto loc_00011728;
	*(s32*)(a3 + 0) = 0;

loc_00011728:		
	v0 = s0 & 0x1;
	if (v0 != 0)
		goto loc_00011838;
	v0 = s0 & 0x1000;

loc_00011738:		
	s3 = v0 | s3;
	a0 = s2;
	a1 = s6;
	a2 = s3;
	a3 = s1;
	v0 = sub_00011614(...);
	if (v0 == 0)
		goto loc_00011780;

loc_00011758:		
	ra = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);

loc_00011768:		
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00011780:		
	if (s1 != 0)
	{
		*(s32*)(s1 + 0) = 0;
		goto loc_00011788;
	}

loc_00011788:		
	a0 = *(s32*)(s2 + 20);
	v0 = sub_00011144(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_00011820;
	a0 = *(s32*)(s2 + 8);
	a1 = v0;
	v0 = sub_0001089C(...);
	s4 = v0;
	if ((s32)v0 < 0)
		goto loc_00011804;
	s5 = *(s32*)(s0 + 0);
	a0 = *(s32*)(s2 + 12);
	a1 = s5 + 32;
	v0 = sub_00010AD8(...);
	s4 = v0;
	if ((s32)v0 < 0)
		goto loc_00011804;
	v0 = *(u16*)(s5 + 32);
	*(s32*)(s0 + 20) = s3;
	a2 = 32;
	a0 = s5;
	*(s16*)(s0 + 8) = v0;
	a1 = 0;
	*(s32*)(s0 + 12) = 0;
	*(s32*)(s0 + 16) = 0;
	v0 = Kernel_Library_A089ECA4(...);
	a0 = s5;
	a1 = s6;
	a2 = 31;
	v0 = scePaf_706ABBFF(...);
	*(s32*)(s5 + 40) = 0;
	v0 = s0;
	goto loc_00011758;

loc_00011804:		
	a0 = *(s32*)(s2 + 20);
	a1 = s0;
	v0 = sub_000111A0(...);
	if (s1 != 0)
	{
		*(s32*)(s1 + 0) = s4;
		goto loc_00011818;
	}

loc_00011818:		
	v0 = 0;
	goto loc_00011758;

loc_00011820:		
	if (s1 == 0)
	{
		v0 = 0;
		goto loc_00011758;
	}
	v0 = 0x80100000;
	v0 = v0 | 0x9815;
	*(s32*)(s1 + 0) = v0;
	goto loc_00011818;

loc_00011838:		
	s3 = 3;
	v0 = sub_00011A58(...);
	v0 = s0 & 0x1000;
	goto loc_00011738;
}

sub_00011848(...) // at 0x00011848 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = ra;
	t0 = a2;
	t2 = sp + 16;
	*(s32*)(sp + 32) = s0;
	s0 = a3;
	t3 = s0 + 8;
	v0 = *(s32*)(a3 + 0);
	v1 = *(s32*)(a3 + 16);
	t1 = *(s32*)(s0 + 12);
	a2 = *(s32*)(v0 + 40);
	a3 = *(u16*)(a3 + 8);
	a0 = *(s32*)(a0 + 16);
	a2 = a2 - v1;
	v0 = (u32)a2 < (u32)t0;

loc_00011884:		
	if (v0 == 0)
		a2 = t0;
	v0 = s0 + 12;
	t0 = 0;
	*(s32*)(sp + 0) = v0;
	v0 = sub_00010DE4(...);
	a0 = *(s32*)(s0 + 16);
	v1 = *(s32*)(sp + 16);
	ra = *(s32*)(sp + 36);
	a0 = a0 + v1;
	*(s32*)(s0 + 16) = a0;
	if (v1 != 0)
		v0 = v1;
	s0 = *(s32*)(sp + 32);

loc_000118B4:		
	sp = sp + 48;
	return (v0);
}

sub_000118BC(...) // at 0x000118BC 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = s0;
	s0 = a3;
	v0 = s0 + 12;
	*(s32*)(sp + 36) = ra;
	t3 = s0 + 8;
	t0 = 0;
	a0 = *(s32*)(a0 + 16);
	a3 = *(u16*)(a3 + 8);
	t1 = *(s32*)(s0 + 12);
	t2 = sp + 16;
	*(s32*)(sp + 0) = v0;
	v0 = sub_00010F50(...);
	v1 = *(s32*)(sp + 16);
	a0 = *(s32*)(s0 + 16);
	a1 = *(s32*)(s0 + 0);
	if (v1 != 0)
		v0 = v1;
	a0 = a0 + v1;
	*(s32*)(s0 + 16) = a0;
	v1 = *(s32*)(a1 + 40);

loc_0001190C:		
	v1 = (u32)v1 < (u32)a0;
	if (v1 != 0)
	{
		*(s32*)(a1 + 40) = a0;
		goto loc_00011918;
	}

loc_00011918:		
	ra = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 48;
	return (v0);
}

sub_00011928(...) // at 0x00011928 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	v0 = 1;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	a1 = *(s32*)(a1 + 0);
	v1 = *(s32*)(a1 + 40);
	if (a3 == v0)
		goto loc_000119C8;
	v0 = (s32)a3 < (s32)2;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_000119B8;
	s0 = v1 + a2;
	if (a3 == v0)
		goto loc_0001197C;
	v0 = 0x80100000;

loc_00011964:		
	v0 = v0 | 0x9811;

loc_00011968:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00011978:		
	sp = sp + 16;
	return (v0);

loc_0001197C:		
	v0 = (u32)s0 >> 31;
	v1 = (s32)v1 < (s32)s0;
	v1 = v1 | v0;
	v0 = 0x80100000;
	v0 = v0 | 0x9811;
	if (v1 != 0)
		goto loc_00011968;
	a1 = *(u16*)(a1 + 32);
	a0 = *(s32*)(a0 + 12);
	t0 = s1 + 8;
	t1 = s1 + 12;
	a2 = s0;
	a3 = 0;
	v0 = sub_00010B4C(...);
	*(s32*)(s1 + 16) = s0;
	goto loc_00011968;

loc_000119B8:		
	s0 = a2;
	if (a3 == 0)
		goto loc_0001197C;
	v0 = 0x80100000;
	goto loc_00011964;

loc_000119C8:		
	v0 = *(s32*)(s1 + 16);
	s0 = v0 + a2;
	goto loc_0001197C;
}

sub_000119D4(...) // at 0x000119D4 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	a1 = sp;
	a0 = *(s32*)(a0 + 24);
	v0 = sub_00013168(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_000119F4(...) // at 0x000119F4 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	v0 = *(s32*)(a1 + 20);
	v0 = v0 & 0x1000;
	s0 = 0;
	if (v0 != 0)
		goto loc_00011A48;

loc_00011A20:		
	a0 = *(s32*)(s2 + 20);
	a1 = s1;
	v0 = sub_000111A0(...);
	if (s0 != 0)
		v0 = s0;
	ra = *(s32*)(sp + 12);

loc_00011A34:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00011A48:		
	v0 = sub_000119D4(...);
	s0 = v0;
	goto loc_00011A20;
}

sub_00011A58(...) // at 0x00011A58 
{
	sp = sp - 16;
	a2 = 4;
	a3 = 0;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = sub_00011614(...);
	s1 = v0;
	v0 = 0x80100000;
	v0 = v0 | 0x9814;
	if (s1 == 0)
		goto loc_00011AB8;
	s0 = *(s32*)(s1 + 0);
	a0 = *(s32*)(s2 + 12);
	a1 = *(u16*)(s0 + 32);
	v0 = sub_00010C38(...);
	a0 = *(s32*)(s2 + 8);
	a1 = s0;
	v0 = sub_000109E8(...);
	a0 = s2;
	a1 = s1;
	v0 = sub_000119F4(...);
	v0 = 0;

loc_00011AB8:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_E4FA1424(...) // at 0x00011AD0 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	a0 = 0x00000;
	s1 = 0x00000;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 24) = ra;
	v1 = *(s32*)(a0 + 4268);
	a0 = a0 + 4268;
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 8);
	s0 = 0x00000;
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 5824);
	a0 = 0;
	a1 = 208;
	if (v1 == 0)
		goto loc_00011B54;

loc_00011B10:		
	v1 = *(s32*)(sp + 0);

loc_00011B14:		
	s0 = *(s32*)(s0 + 5828);
	a0 = v1;
	if (s0 == 0)
		goto loc_00011B2C;
	v0 = *(s32*)(s1 + 5824);
	v0 = v0 + 1;
	*(s32*)(s1 + 5824) = v0;

loc_00011B2C:		
	v0 = *(s32*)(v1 + 0);
	v1 = *(s32*)(v0 + 12);
	v0 = $v1(...);
	v0 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00011B54:		
	v0 = onesegSal_265926E7(...);
	*(s32*)(s0 + 5828) = v0;
	a0 = v0;
	a1 = 0x20000;
	if (v0 == 0)
		goto loc_00011B10;
	v0 = sub_00011C3C(...);
	v1 = *(s32*)(sp + 0);
	if (v0 == 0)
		goto loc_00011B14;
	v0 = *(s32*)(s0 + 5828);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00011B94;
	*(s32*)(s0 + 5828) = 0;
	goto loc_00011B10;

loc_00011B94:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 5828) = 0;
	goto loc_00011B10;
}

onesegCore_6C6A13B0(...) // at 0x00011BA4 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	a0 = 0x00000;
	*(s32*)(sp + 20) = ra;
	v1 = *(s32*)(a0 + 4268);
	a0 = a0 + 4268;
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 8);
	s0 = 0x00000;
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 5828);
	v1 = 0x00000;
	if (a0 == 0)
		goto loc_00011BE8;
	v0 = *(s32*)(v1 + 5824);
	v0 = v0 - 1;
	*(s32*)(v1 + 5824) = v0;
	if (v0 == 0)
		goto loc_00011C0C;

loc_00011BE8:		
	v0 = *(s32*)(sp + 0);
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 12);
	a0 = v0;
	v0 = $a1(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00011C0C:		
	v0 = sub_00011D40(...);
	v0 = *(s32*)(s0 + 5828);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00011C2C;
	*(s32*)(s0 + 5828) = 0;
	goto loc_00011BE8;

loc_00011C2C:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 5828) = 0;
	goto loc_00011BE8;
}

sub_00011C3C(...) // at 0x00011C3C 
{
	*(s32*)(a0 + 0) = 0;
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	a0 = 512;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 28) = ra;
	s2 = a1;
	v0 = scePaf_0C2CD696(...);
	s0 = v0;
	v0 = v0 + s2;
	v0 = v0 - 1;
	v1 = s0;
	NONE;
	NONE;
	a0 = 512;
	a1 = s2;
	if (v1 == v0)
		goto loc_00011D38;
	v0 = scePaf_0C2CD696(...);
	*(s32*)(s1 + 0) = v0;
	a0 = s0;
	v0 = scePaf_412B2F09(...);

loc_00011C9C:		
	v1 = *(s32*)(s1 + 0);
	t0 = 7;
	v0 = v1 + s2;
	a3 = v1;
	v0 = v0 - 1;
	NONE;
	NONE;
	if (v1 == 0)
		goto loc_00011D1C;
	s0 = s1 + 8;
	a2 = 1;
	a1 = 4;
	a0 = s0;
	if (a3 != v0)
		goto loc_00011D1C;
	*(s32*)(sp + 0) = v1;
	v0 = sub_00011F70(...);
	a1 = v0;

loc_00011CDC:		
	a0 = 0;
	t0 = 4;
	if ((s32)v0 < 0)
		goto loc_00011D1C;
	v0 = onesegSal_265926E7(...);
	*(s32*)(s1 + 4) = v0;
	a3 = sp;
	a1 = v0;
	a0 = s0;
	t0 = 7;
	if (v0 == 0)
		goto loc_00011D1C;
	a2 = *(s32*)(s1 + 0);
	NONE;
	v0 = sub_00012014(...);
	t0 = 4;
	if (v0 == 0)
		t0 = 0;

loc_00011D1C:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = t0;
	sp = sp + 32;
	return (v0);

loc_00011D38:		
	*(s32*)(s1 + 0) = s0;
	goto loc_00011C9C;
}

sub_00011D40(...) // at 0x00011D40 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0 + 8;
	a1 = sp;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 24) = ra;
	a0 = s0;
	v0 = sub_00012224(...);
	a0 = s0;
	v0 = sub_00012294(...);
	v1 = *(s32*)(s1 + 4);
	a0 = 0;
	a1 = v1;
	if (v1 != 0)
		goto loc_00011D9C;

loc_00011D7C:		
	a0 = *(s32*)(s1 + 0);
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 0) = 0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);

loc_00011D94:		
	sp = sp + 32;
	return (v0);

loc_00011D9C:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s1 + 4) = 0;
	goto loc_00011D7C;
}

onesegCore_0F14B1C4(...) // at 0x00011DAC 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	a0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(a0 + 4268);
	a0 = a0 + 4268;
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 8);
	s0 = a1;
	v0 = $v0(...);
	a1 = s0;
	a0 = 512;
	v0 = sceMpegbase_AC9E717E(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

onesegCore_669F1BDD(...) // at 0x00011E0C 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = ra;
	a0 = 0x00000;
	*(s32*)(sp + 28) = s3;
	s3 = t0;
	*(s32*)(sp + 24) = s2;
	s2 = a1;
	*(s32*)(sp + 20) = s1;
	s1 = a3;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(a0 + 4268);
	a0 = a0 + 4268;
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 8);
	s0 = a2;
	v0 = $v0(...);
	a1 = s0;
	a2 = s1;
	a3 = s3;
	a0 = s2;
	v0 = sceMpegBaseCscAvc(...);
	a0 = *(s32*)(sp + 0);
	s0 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 12);

loc_00011E74:		
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);
	sp = sp - 16;
	a0 = 1;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_000059FC(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a0 = 0;
	*(s32*)(sp + 0) = ra;
	a1 = 0xFFFF;
	v0 = sub_000059FC(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00011ED8(...) // at 0x00011ED8 
{
	v0 = (u32)0 < (u32)a1;
	v1 = (u32)0 < (u32)a2;
	v0 = v0 & v1;
	if (v0 == 0)
		goto loc_00011F10;
	v0 = *(s32*)(a0 + 8);
	if (a1 == v0)
	{
		*(s32*)(a0 + 8) = a2;
		goto loc_00011EF8;
	}

loc_00011EF8:		
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(a1 + 0);
	*(s32*)(a1 + 0) = a2;
	v0 = v0 + 1;
	*(s32*)(a0 + 0) = v0;
	*(s32*)(a2 + 0) = v1;

loc_00011F10:		
	return (v0);
}

sub_00011F18(...) // at 0x00011F18 
{
	if (a1 == 0)
		goto loc_00011F4C;
	v1 = *(s32*)(a1 + 0);
	if (v1 == 0)
		goto loc_00011F4C;
	v0 = *(s32*)(a0 + 8);
	if (v1 == v0)
	{
		*(s32*)(a0 + 8) = a1;
		goto loc_00011F54;
	}

loc_00011F38:		
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v1 + 0);
	v0 = v0 - 1;
	*(s32*)(a1 + 0) = v1;
	*(s32*)(a0 + 0) = v0;

loc_00011F4C:		
	return (v0);

loc_00011F54:		
	v1 = *(s32*)(a1 + 0);
	goto loc_00011F38;
}

sub_00011F5C(...) // at 0x00011F5C 
{
	v0 = a0 + 4;
	*(s32*)(a0 + 8) = v0;
	*(s32*)(a0 + 0) = 0;
	*(s32*)(a0 + 4) = 0;
	return (v0);
}

sub_00011F70(...) // at 0x00011F70 
{
	v0 = a1 - 4;
	sp = sp - 16;
	v0 = (u32)v0 < (u32)2;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	s0 = a1;

loc_00011F98:		
	a1 = -1101;
	*(s32*)(sp + 12) = ra;
	if (v0 != 0)
		goto loc_00011FC0;

loc_00011FA4:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a1;
	sp = sp + 16;
	return (v0);

loc_00011FC0:		
	v0 = sceMpegQueryMemSize(...);
	v1 = v0;
	a3 = v0 & 0xF;
	a2 = v0;
	v0 = s1 << 4;
	v0 = v0 + s1;
	a0 = v0 << 2;
	a1 = v1;
	if ((s32)v1 < 0)
		goto loc_00011FA4;
	v0 = (s32)v1 >> 31;
	v0 = (u32)v0 >> 28;
	v0 = v1 + v0;
	*(s32*)(s2 + 144) = s0;
	NONE;
	*(s32*)(s2 + 136) = s1;
	*(s32*)(s2 + 140) = v1;
	if (a3 == 0)
		goto loc_0001200C;
	a2 = v0 + 16;

loc_0001200C:		
	a1 = a2 + a0;
	goto loc_00011FA4;
}

sub_00012014(...) // at 0x00012014 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	t2 = a2;
	v0 = a0 + 4;
	*(s32*)(sp + 4) = s1;
	s3 = a3;
	t0 = 512;
	*(s32*)(sp + 0) = s0;
	a3 = v0;
	s1 = a0;
	*(s32*)(sp + 16) = ra;
	s0 = a1;
	*(s32*)(sp + 8) = s2;
	t1 = *(s32*)(a0 + 144);
	a2 = *(s32*)(a0 + 140);
	v0 = sceMpegCreate(...);
	a0 = v0;
	if (v0 != 0)
		goto loc_000120EC;
	v1 = *(s32*)(s1 + 140);
	a2 = s0 + v1;
	v0 = v1 & 0xF;
	a1 = a2;
	if (v0 == 0)
		goto loc_0001208C;
	v0 = (s32)v1 >> 31;
	v0 = (u32)v0 >> 28;
	v0 = v1 + v0;
	NONE;
	v0 = v1 - v0;
	v0 = a2 - v0;
	a1 = v0 + 16;

loc_0001208C:		
	v1 = *(s32*)(s1 + 136);
	*(s32*)(s1 + 132) = a1;
	s2 = 0;
	v0 = v1 << 2;
	a2 = a1 + v0;
	if ((s32)v1 <= 0)
		goto loc_000120EC;
	s0 = a2;
	v0 = *(s32*)(s1 + 132);

loc_000120AC:		
	v1 = s2 << 2;
	a0 = v1 + s3;
	v1 = v1 + v0;
	*(s32*)(v1 + 0) = s0;
	a2 = s0;
	s2 = s2 + 1;
	a1 = *(s32*)(a0 + 0);
	a0 = s1;
	s0 = s0 + 64;
	v0 = sceMpegInitAu(...);
	a0 = v0;
	if (v0 != 0)
		goto loc_000120EC;
	v0 = *(s32*)(s1 + 136);
	v0 = (s32)s2 < (s32)v0;
	if (v0 != 0)
	{
		v0 = *(s32*)(s1 + 132);
		goto loc_000120AC;
	}

loc_000120EC:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;

loc_00012104:		
	sp = sp + 32;
	return (v0);
}

sub_0001210C(...) // at 0x0001210C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	t0 = a3 << 2;
	v0 = *(s32*)(a0 + 136);
	v0 = (s32)v0 < (s32)a3;
	a3 = -1101;
	if (v0 != 0)
		goto loc_0001213C;
	v0 = *(s32*)(a0 + 132);
	v0 = t0 + v0;
	a3 = *(s32*)(v0 + 0);
	v0 = sceMpegGetAvcEsAu(...);
	a3 = v0;

loc_0001213C:		
	ra = *(s32*)(sp + 0);
	v0 = a3;
	sp = sp + 16;
	return (v0);
}

sub_0001214C(...) // at 0x0001214C 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	v1 = a1 << 2;
	s2 = a3;
	*(s32*)(sp + 20) = s1;
	t0 = a2;
	s1 = a0;
	*(s32*)(sp + 28) = ra;
	a3 = 0;
	a2 = 512;
	*(s32*)(sp + 16) = s0;
	v0 = *(s32*)(a0 + 136);
	v0 = (s32)v0 < (s32)a1;
	a1 = -1101;
	if (v0 != 0)
		goto loc_000121F8;
	v0 = *(s32*)(a0 + 132);
	v0 = v1 + v0;
	a1 = *(s32*)(v0 + 0);
	v0 = sceMpegAvcDecode(...);
	s0 = v0;
	a1 = s1 + 156;
	a0 = s1;
	if (v0 != 0)
		goto loc_00012214;
	a0 = s1;
	a1 = sp;
	if (s2 == 0)
		goto loc_000121CC;
	v0 = sceMpegAvcDecodeGetDecodeSEI(...);

loc_000121C0:		
	a1 = v0;
	if (v0 != 0)
		goto loc_000121F8;
	v0 = *(s32*)(sp + 0);
	*(s32*)(s2 + 0) = v0;

loc_000121CC:		
	a1 = s1 + 156;
	a0 = s1;
	v0 = sceMpegAvcDecodeDetail2(...);
	a1 = v0;
	if (v0 != 0)
		goto loc_000121F8;
	v0 = *(s32*)(s1 + 156);

loc_000121E4:		
	a1 = 0;
	v1 = *(s32*)(v0 + 16);
	*(s32*)(s1 + 164) = v1;
	a0 = *(s32*)(v0 + 44);
	*(s32*)(s1 + 160) = a0;

loc_000121F8:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a1;
	sp = sp + 32;
	return (v0);

loc_00012214:		
	v0 = sceMpegAvcDecodeDetail2(...);
	a1 = s0;
	goto loc_000121F8;
}

sub_00012224(...) // at 0x00012224 
{
	sp = sp - 16;
	a3 = a1;
	a2 = 0;
	a1 = 512;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sceMpegAvcDecodeStop(...);
	a2 = v0;
	a1 = s0 + 156;
	a0 = s0;
	if (v0 == 0)
		goto loc_00012268;

loc_00012254:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 16;
	return (v0);

loc_00012268:		
	v0 = sceMpegAvcDecodeDetail2(...);
	a2 = v0;
	if (v0 != 0)
		goto loc_00012254;
	v0 = *(s32*)(s0 + 156);
	a2 = 0;
	v1 = *(s32*)(v0 + 16);
	*(s32*)(s0 + 164) = v1;
	a0 = *(s32*)(v0 + 44);
	*(s32*)(s0 + 160) = a0;
	goto loc_00012254;
}

sub_00012294(...) // at 0x00012294 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sceMpegDelete(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 4);
	v0 = sub_00012D94(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 4);
	v0 = sub_00012DB0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 4);
	v0 = sub_00012DCC(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_ED4A7205(...) // at 0x0001234C 
{
	sp = sp - 16;
}

sub_00012350(...) // at 0x00012350 
{
	*(s32*)(sp + 0) = ra;
	v0 = sub_00012368(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00012368(...) // at 0x00012368 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = 0;
	v0 = onesegSal_DB69838E(...);
	a1 = 376;
	v0 = *(s32*)(s2 + 5832);
	a0 = 0;
	if (v0 == 0)
		goto loc_000123D4;

loc_0001239C:		
	v1 = 0x00000;
	*(s32*)(s1 + 0) = v0;
	v0 = *(s32*)(v1 + 5836);
	v0 = v0 + 1;
	*(s32*)(v1 + 5836) = v0;

loc_000123B0:		
	v0 = onesegSal_8FE81670(...);
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000123D4:		
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	a0 = v0;
	v0 = sub_00012718(...);
	a0 = s0;
	*(s32*)(s2 + 5832) = s0;
	v0 = sub_000124B0(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00012404;
	v0 = *(s32*)(s2 + 5832);
	goto loc_0001239C;

loc_00012404:		
	a0 = *(s32*)(s2 + 5832);
	v0 = sub_0001262C(...);
	v0 = *(s32*)(s2 + 5832);
	a0 = v0;
	if (v0 != 0)
		goto loc_00012420;
	*(s32*)(s2 + 5832) = 0;
	goto loc_000123B0;

loc_00012420:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 20);
	v0 = $v1(...);
	*(s32*)(s2 + 5832) = 0;
	goto loc_000123B0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSal_DB69838E(...);
	v1 = 0x00000;
	v0 = *(s32*)(v1 + 5836);
	v0 = v0 - 1;
	*(s32*)(v1 + 5836) = v0;
	if (v0 != 0)
		goto loc_000124A0;
	v0 = 0x00000;
	*(s32*)(v0 + 5832) = 0;
	v0 = onesegSal_8FE81670(...);
	a0 = s0;
	v0 = sub_0001262C(...);
	a0 = s0;
	if (s0 == 0)
		goto loc_0001248C;
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(v0 + 20);
	v0 = $v1(...);

loc_0001248C:		
	ra = *(s32*)(sp + 4);

loc_00012490:		
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_000124A0:		
	v0 = onesegSal_8FE81670(...);
	ra = *(s32*)(sp + 4);
	goto loc_00012490;
}

sub_000124B0(...) // at 0x000124B0 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = a0;
	v0 = sub_00017224(...);
	v1 = 0x80000000;
	*(s32*)(s0 + 8) = v0;
	if (v0 == 0)
		goto loc_00012618;
	a0 = sp;
	v0 = sub_00018448(...);
	v1 = *(s32*)(sp + 0);
	a0 = 16;
	a1 = v1 << 2;
	a1 = a1 + v1;
	a1 = a1 << 2;
	v0 = scePaf_0C2CD696(...);
	*(s32*)(s0 + 44) = v0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012618;
	a2 = *(s32*)(sp + 0);
	a3 = -1;
	a1 = 0;
	v1 = s0;
	a0 = 19;

loc_00012510:		
	v0 = *(s32*)(s0 + 44);
	a0 = a0 - 1;
	*(s32*)(v1 + 64) = a2;
	v0 = v0 + a1;
	a1 = a1 + a2;
	*(s32*)(v1 + 56) = v0;
	*(s32*)(v1 + 60) = a3;
	*(s8*)(v1 + 68) = 0;
	v1 = v1 + 16;
	if ((s32)a0 >= 0)
		goto loc_00012510;
	a0 = 0;
	a1 = 8;
	v0 = onesegSal_265926E7(...);
	v1 = 0x70000;
	v1 = v1 - 16016;
	*(s32*)(v0 + 0) = v1;
	a0 = v0;
	*(s32*)(s0 + 12) = v0;
	v0 = *(s32*)(v1 + 8);
	a1 = s0;
	v0 = $v0(...);
	a0 = 0;
	a1 = 8;
	v0 = onesegSal_265926E7(...);
	v1 = 0x70000;
	v1 = v1 - 15984;
	*(s32*)(v0 + 0) = v1;
	a0 = v0;
	*(s32*)(s0 + 16) = v0;
	v0 = *(s32*)(v1 + 8);
	a1 = s0;
	v0 = $v0(...);
	a0 = 0;
	a1 = 8;
	v0 = onesegSal_265926E7(...);
	v1 = 0x70000;
	v1 = v1 - 14920;

loc_000125A4:		
	*(s32*)(v0 + 0) = v1;
	a0 = v0;
	*(s32*)(s0 + 20) = v0;
	v0 = *(s32*)(v1 + 8);
	a1 = s0;
	v0 = $v0(...);
	a0 = 0;
	a1 = 8;
	v0 = onesegSal_265926E7(...);
	v1 = 0x70000;
	v1 = v1 - 14864;
	*(s32*)(v0 + 0) = v1;
	a0 = v0;
	*(s32*)(s0 + 24) = v0;
	v0 = *(s32*)(v1 + 8);
	a1 = s0;
	v0 = $v0(...);
	a0 = 0;
	a1 = 8;
	v0 = onesegSal_265926E7(...);
	v1 = 0x70000;
	v1 = v1 - 16048;
	*(s32*)(v0 + 0) = v1;
	a0 = v0;
	*(s32*)(s0 + 32) = v0;
	v0 = *(s32*)(v1 + 8);
	a1 = s0;
	v0 = $v0(...);
	v1 = 0;

loc_00012618:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_0001262C(...) // at 0x0001262C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = *(s32*)(a0 + 12);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_00012704;
	}

loc_00012648:		
	a0 = *(s32*)(s0 + 16);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_000126F0;
	}

loc_00012654:		
	a0 = *(s32*)(s0 + 20);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_000126DC;
	}

loc_00012660:		
	a0 = *(s32*)(s0 + 24);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_000126C8;
	}

loc_0001266C:		
	a0 = *(s32*)(s0 + 32);
	if (a0 != 0)
	{
		v1 = *(s32*)(a0 + 0);
		goto loc_000126B4;
	}

loc_00012678:		
	a0 = *(s32*)(s0 + 44);
	if (a0 != 0)
		goto loc_000126A4;

loc_00012684:		
	a0 = *(s32*)(s0 + 8);
	v0 = sub_000173E8(...);
	*(s32*)(s0 + 8) = 0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000126A4:		
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 44) = 0;
	goto loc_00012684;

loc_000126B4:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 32) = 0;
	goto loc_00012678;

loc_000126C8:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 24) = 0;
	goto loc_0001266C;

loc_000126DC:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 20) = 0;
	goto loc_00012660;

loc_000126F0:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 16) = 0;
	goto loc_00012654;

loc_00012704:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 12) = 0;
	goto loc_00012648;
}

sub_00012718(...) // at 0x00012718 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = onesegHalToolbox_EAA7BE5A(...);
	v0 = 0x70000;
	v0 = v0 - 16128;
	*(s32*)(s0 + 0) = v0;
	*(s32*)(s0 + 40) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;
	*(s32*)(s0 + 16) = 0;
	*(s32*)(s0 + 20) = 0;
	*(s32*)(s0 + 24) = 0;
	*(s32*)(s0 + 28) = 0;
	*(s32*)(s0 + 32) = 0;
	*(s32*)(s0 + 44) = 0;
	*(s32*)(s0 + 48) = 0;
	*(s32*)(s0 + 52) = 0;
	*(s8*)(s0 + 36) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a1;
	v0 = $v0(...);
	a1 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_000127B4;
	a0 = *(s32*)(s1 + 8);
	v0 = sub_00017494(...);
	v1 = v0;

loc_000127B4:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = a0;
	*(s32*)(sp + 16) = s4;
	s4 = a1;
	*(s32*)(sp + 12) = s3;
	s3 = t0;
	*(s32*)(sp + 8) = s2;
	s2 = a3;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 24) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = t1 & 0xFF;
	v0 = $v0(...);
	a1 = s4;
	a2 = s1;
	a3 = s2;
	t0 = s3;
	t1 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012838;

loc_0001282C:		
	a0 = *(s32*)(s5 + 8);
	v0 = sub_0001750C(...);
	v1 = v0;

loc_00012838:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 32;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	s4 = a2;
	*(s32*)(sp + 12) = s3;
	s3 = t0;
	*(s32*)(sp + 8) = s2;
	s2 = a3;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a0;
	v0 = $v0(...);
	a0 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_000128CC;
	v0 = sub_00012A94(...);
	a0 = *(s32*)(s0 + 8);
	a1 = s1;
	a2 = s4;
	a3 = s2;
	t0 = s3;
	v0 = sub_000176FC(...);
	v1 = v0;

loc_000128CC:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 32;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;

loc_00012904:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a1;
	v0 = $v0(...);
	a1 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_0001292C;
	a0 = *(s32*)(s1 + 8);
	v0 = sub_000177A0(...);
	v1 = v0;

loc_0001292C:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a1;
	v0 = $v0(...);
	a1 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012980;
	a0 = *(s32*)(s1 + 8);
	v0 = sub_000178C0(...);
	v1 = v0;

loc_00012980:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 20) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);

loc_000129AC:		
	s0 = a0;
	v0 = $v0(...);
	a1 = sp;
	v1 = 0;
	if (v0 != 0)
		goto loc_000129D4;

loc_000129C0:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_000129D4:		
	a0 = *(s32*)(s0 + 8);
	v0 = sub_00017AEC(...);
	v1 = *(s32*)(sp + 0);
	goto loc_000129C0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);

loc_000129F8:		
	s0 = a0;
	v0 = $v0(...);
	a0 = s0;
	if (v0 == 0)
		goto loc_00012A28;

loc_00012A08:		
	*(s32*)(s0 + 52) = 0;
	v1 = 0;
	*(s32*)(s0 + 48) = 0;
	ra = *(s32*)(sp + 4);

loc_00012A18:		
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00012A28:		
	v0 = onesegHalToolbox_A5B6534C(...);
	v1 = v0;
	if ((s32)v0 >= 0)
		goto loc_00012A08;
	ra = *(s32*)(sp + 4);
	goto loc_00012A18;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a0;
	v0 = $v0(...);
	a0 = s0;
	if (v0 != 0)
		goto loc_00012A7C;

loc_00012A64:		
	a0 = s0;
	v0 = onesegHalToolbox_5D026D4E(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00012A7C:		
	v1 = *(s32*)(s0 + 0);
	v0 = *(s32*)(v1 + 32);
	v0 = $v0(...);

loc_00012A90:		
	goto loc_00012A64;
}

sub_00012A94(...) // at 0x00012A94 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(a0 + 48) = 0;
	*(s32*)(s0 + 52) = 0;
	*(s32*)(sp + 20) = ra;
	a0 = sp;
	v0 = sub_00018448(...);
	a1 = 0;
	v1 = *(s32*)(s0 + 44);
	a0 = v1;
	if (v1 != 0)
		goto loc_00012AD4;
	ra = *(s32*)(sp + 20);

loc_00012AC8:
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00012AD4:
	v0 = *(s32*)(sp + 0);
	a2 = v0 << 2;
	a2 = a2 + v0;
	a2 = a2 << 2;
	v0 = onesegSal_FDC7AC2A(...);
	ra = *(s32*)(sp + 20);
	goto loc_00012AC8;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a0;
	v0 = $v0(...);
	a0 = s0;
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012B40;
	v0 = sub_00012A94(...);
	a0 = *(s32*)(s0 + 8);
	v0 = sub_00017B14(...);
	v1 = v0;
	a0 = s0;
	if ((s32)v0 < 0)
		goto loc_00012B40;
	v0 = onesegHalToolbox_FAD1DB25(...);
	v1 = v0;

loc_00012B40:
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 24);
	s0 = a0;
	v0 = $v0(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012B98;
	a0 = *(s32*)(s0 + 8);
	v0 = sub_00017CE0(...);
	v1 = v0;
	a0 = s0;
	if ((s32)v0 < 0)
		goto loc_00012B98;
	v0 = onesegHalToolbox_C17258E3(...);
	v1 = v0;

loc_00012B98:
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	v0 = 20;
	s3 = a3;
	*(s32*)(sp + 24) = s2;
	s2 = a2;
	*(s32*)(sp + 20) = s1;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 24);
	s0 = a0;
	v0 = $v0(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00012C94;
	v1 = *(s32*)(s0 + 52);
	a1 = s0 + 56;
	a2 = sp;
	if (v1 != 0)
		goto loc_00012C28;
	a0 = *(s32*)(s0 + 8);
	v0 = sub_00017B88(...);
	a2 = v0;
	if ((s32)v0 < 0)
		goto loc_00012CB4;
	v0 = *(s32*)(sp + 0);
	*(s32*)(s0 + 48) = 0;
	v1 = v0;
	*(s32*)(s0 + 52) = v0;

loc_00012C20:
	cond = (v1 == 0);
	v1 = a2;
	if (cond)
		goto loc_00012C94;

loc_00012C28:
	v0 = *(s32*)(s0 + 48);
	a0 = s1 + 4;
	v0 = v0 << 4;
	v0 = v0 + s0;
	a2 = *(s32*)(v0 + 64);
	a1 = *(s32*)(v0 + 56);
	v0 = onesegSal_AA6EEB53(...);
	v1 = *(s32*)(s0 + 48);
	a2 = 0;
	v1 = v1 << 4;
	v1 = v1 + s0;

loc_00012C54:
	a0 = *(s32*)(v1 + 64);
	*(s32*)(s2 + 0) = a0;
	v0 = *(s32*)(s0 + 48);
	v0 = v0 << 4;
	v0 = v0 + s0;
	a0 = *(s32*)(v0 + 60);
	a1 = *(u8*)(v0 + 68);
	*(s32*)(s1 + 0) = a0;
	v1 = *(s32*)(s0 + 52);
	v0 = *(s32*)(s0 + 48);
	*(s8*)(s3 + 0) = a1;
	v1 = v1 - 1;
	v0 = v0 + 1;
	*(s32*)(s0 + 48) = v0;
	*(s32*)(s0 + 52) = v1;

loc_00012C90:
	v1 = a2;

loc_00012C94:
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00012CB4:
	v1 = *(s32*)(s0 + 52);
	goto loc_00012C20;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 8);
	v0 = sub_00017E10(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

Func_12CD8()
{
	s0 = a1;
	s1 = a0;
	v0 = onesegSal_BABF0A73(s0, "tunerAntCtl");
	if (v0 != 0)
	{
		v0 = onesegSal_BABF0A73(s0, "tuner");
		if (v0 != 0)
		{
			v0 = onesegSal_BABF0A73(s0, "tunerInfo");
			if (v0 != 0)
			{
				v0 = onesegSal_BABF0A73(s0, "tunerCPCtl");
				if (v0 != 0)
				{
					v0 = onesegSal_BABF0A73(s0, "pspTuner");
					v1 = 0;
					if (v0 != 0)
						goto loc_00012D0C;
					v1 = *(s32*)(s1 + 32);
					goto loc_00012D0C;
				}
				v1 = *(s32*)(s1 + 16);
				goto loc_00012D0C;
			}
			v1 = *(s32*)(s1 + 24);
			goto loc_00012D0C;
		}
		v1 = *(s32*)(s1 + 20);
		goto loc_00012D0C;
	}
	v1 = *(s32*)(s1 + 12);

loc_00012D0C:
	return (v1);
}

sub_00012D94(...) // at 0x00012D94 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 8);
	v0 = sub_00017630(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00012DB0(...) // at 0x00012DB0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 8);
	v0 = sub_00017684(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00012DCC(...) // at 0x00012DCC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = *(s32*)(a0 + 8);
	v0 = sub_000176C0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

onesegCore_6CD38204(...) // at 0x00012DE8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00018448(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00012E04(...) // at 0x00012E04 
{
	sp = sp - 48;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	a1 = 0x20000;
	*(s32*)(sp + 4) = s1;
	a1 = a1 | 0x10;
	s1 = a0;

loc_00012E20:		
	a0 = 0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s7;

loc_00012E2C:		
	s7 = t0;
	*(s32*)(sp + 24) = s6;
	s6 = a3;
	*(s32*)(sp + 20) = s5;
	s5 = a2;
	*(s32*)(sp + 16) = s4;
	s4 = t1;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	a0 = s2;
	*(s32*)(s1 + 36) = v0;
	s3 = v0;
	s3 = s3 + 15;
	v0 = scePaf_D7DCB972(...);
	v0 = v0 + 1;
	a1 = v0;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	s0 = v0;
	a1 = s2;
	a0 = v0;
	v0 = scePaf_726DFBA9(...);
	*(s32*)(s1 + 40) = s0;
	s2 = 0x20000;
	a0 = s0;
	s2 = s2 - 14700;
	v0 = scePaf_D7DCB972(...);
	a0 = s2;
	s0 = v0;
	v0 = scePaf_D7DCB972(...);
	s0 = s0 + v0;
	s0 = s0 + 1;
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	a1 = *(s32*)(s1 + 40);
	s0 = v0;
	a0 = v0;
	v0 = scePaf_726DFBA9(...);
	a0 = s0;
	a1 = s2;
	v0 = scePaf_98BA1D0B(...);

loc_00012ED8:		
	v1 = *(s32*)(s1 + 40);
	NONE;
	v0 = 0x20000;
	*(s32*)(s1 + 20) = s4;
	*(s32*)(s1 + 44) = s0;
	*(s32*)(s1 + 0) = s3;
	*(s32*)(s1 + 12) = s5;
	*(s32*)(s1 + 16) = s6;
	*(s32*)(s1 + 24) = s7;
	*(s32*)(s1 + 4) = v0;
	*(s32*)(s1 + 8) = v1;
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);
}

sub_00012F30(...) // at 0x00012F30 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 36);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00012FA0;

loc_00012F50:		
	v0 = *(s32*)(s0 + 40);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00012F90;

loc_00012F60:		
	v0 = *(s32*)(s0 + 44);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00012F80;

loc_00012F70:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00012F7C:		
	sp = sp + 16;
	return (v0);

loc_00012F80:		
	v0 = onesegSal_E64CF915(...);
}

sub_00012F8C(...) // at 0x00012F8C 
{
	*(s32*)(s0 + 44) = 0;
	goto loc_00012F70;

loc_00012F90:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 40) = 0;
	goto loc_00012F60;

loc_00012FA0:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 36) = 0;
	goto loc_00012F50;
}

sub_00012FB0(...) // at 0x00012FB0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a2 = a1;
	v0 = *(s32*)(a0 + 44);
	a1 = *(s32*)(a0 + 16);
	a0 = v0;
	v0 = sub_00002900(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00012FD8(...) // at 0x00012FD8 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a1;
	v0 = sub_00002B38(...);
	v1 = (u32)v0 < (u32)1;

loc_00012FF8:		
	a0 = (u32)0 < (u32)s0;
	v1 = v1 & a0;
	ra = *(s32*)(sp + 8);
	if (v1 == 0)
		goto loc_00013010;
	v1 = *(s32*)(s1 + 32);
	*(s32*)(s0 + 0) = v1;

loc_00013010:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00013020(...) // at 0x00013020 
{
	sp = sp - 144;
	*(s32*)(sp + 120) = s2;
	s2 = a1;
	a1 = sp + 96;
	*(s32*)(sp + 116) = s1;
	*(s32*)(sp + 112) = s0;
	s0 = a0;
	*(s32*)(sp + 128) = ra;
	*(s32*)(sp + 124) = s3;
	v0 = sub_00012FD8(...);
	s1 = v0;
	a0 = s0;
	a1 = sp + 96;
	if (v0 != 0)
		goto loc_00013084;

loc_00013058:		
	v0 = *(s32*)(sp + 96);
	if (s2 == 0)
		goto loc_00013064;
	*(s32*)(s2 + 0) = v0;

loc_00013064:		
	v0 = s1;
	ra = *(s32*)(sp + 128);
	s3 = *(s32*)(sp + 124);

loc_00013070:		
	s2 = *(s32*)(sp + 120);
	s1 = *(s32*)(sp + 116);
	s0 = *(s32*)(sp + 112);
	sp = sp + 144;
	return (v0);

loc_00013084:		
	v0 = *(s32*)(s0 + 44);
	s3 = *(s32*)(s0 + 8);
	*(s32*)(s0 + 8) = v0;
	v0 = sub_00012FD8(...);
	s1 = v0;
	a1 = sp;
	if (v0 == 0)
		goto loc_000130A8;
	*(s32*)(s0 + 8) = s3;
	goto loc_00013058;

loc_000130A8:		
	a0 = *(s32*)(s0 + 40);
	v0 = sceIoGetstat(...);
	if (v0 == 0)
		goto loc_000130CC;
	a0 = *(s32*)(s0 + 44);

loc_000130BC:		

loc_000130C0:		
	a1 = *(s32*)(s0 + 40);
	v0 = sceIoRename(...);
	*(s32*)(s0 + 8) = s3;
	goto loc_00013058;

loc_000130CC:		
	a0 = *(s32*)(s0 + 40);
	v0 = sceIoRemove(...);
	a0 = *(s32*)(s0 + 44);
	goto loc_000130BC;
}

sub_000130DC(...) // at 0x000130DC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	a3 = 0x46500000;
	a2 = 0x80100000;
	*(s32*)(sp + 0) = s0;
	a3 = a3 | 0x4453;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	s1 = a1;
	v0 = *(s32*)(a0 + 16);
	v0 = (u32)v0 < (u32)4;
	a2 = a2 | 0x9804;
	if (v0 != 0)
		goto loc_00013124;
	v1 = *(s32*)(a0 + 12);
	a2 = 0x80100000;
	v0 = *(s32*)(v1 + 0);
	a2 = a2 | 0x9804;
	if (v0 == a3)
		goto loc_0001313C;

loc_00013124:		
	ra = *(s32*)(sp + 8);

loc_00013128:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 16;
	return (v0);

loc_0001313C:		
	v0 = sub_00002FD0(...);
	v1 = (u32)v0 < (u32)1;
	a2 = v0;
	v0 = (u32)0 < (u32)s1;
	v1 = v1 & v0;
	ra = *(s32*)(sp + 8);
	if (v1 == 0)
		goto loc_00013128;
	v0 = *(s32*)(s0 + 32);
	*(s32*)(s1 + 0) = v0;
	goto loc_00013128;
}

sub_00013168(...) // at 0x00013168 
{
	sp = sp - 128;
	*(s32*)(sp + 112) = s0;
	s0 = a1;
	a1 = sp + 96;
	*(s32*)(sp + 116) = s1;
	*(s32*)(sp + 120) = ra;
	s1 = a0;
	v0 = sub_00012FB0(...);

loc_00013188:		
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_000131A8;
	v0 = *(s32*)(sp + 96);
	v1 = 0x80100000;
	a1 = s0;
	a0 = s1;
	v1 = v1 | 0x9802;
	if (v0 == 0)
		goto loc_000131C0;

loc_000131A8:		
	ra = *(s32*)(sp + 120);
	s1 = *(s32*)(sp + 116);
	s0 = *(s32*)(sp + 112);
	v0 = v1;
	sp = sp + 128;
	return (v0);

loc_000131C0:		
	v0 = *(s32*)(s1 + 44);
	s0 = *(s32*)(s1 + 8);
	*(s32*)(s1 + 8) = v0;
	v0 = sub_000130DC(...);
	a1 = sp;
	*(s32*)(s1 + 8) = s0;
	if (v0 == 0)
		goto loc_000131E4;
	v1 = v0;
	goto loc_000131A8;

loc_000131E4:		
	a0 = *(s32*)(s1 + 40);
	v0 = sceIoGetstat(...);
	if (v0 == 0)
		goto loc_00013208;
	a1 = *(s32*)(s1 + 40);

loc_000131F8:		
	a0 = *(s32*)(s1 + 44);
	v0 = sceIoRename(...);
	v1 = v0;
	goto loc_000131A8;

loc_00013208:		
	a0 = *(s32*)(s1 + 40);
	v0 = sceIoRemove(...);
	a1 = *(s32*)(s1 + 40);
	goto loc_000131F8;
}

sub_00013218(...) // at 0x00013218 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a2 = *(s32*)(a0 + 8);
	*(s32*)(a0 + 28) = a1;
	v0 = *(s32*)(a2 + 0);
	v1 = *(s32*)(v0 + 44);
	a0 = a2;
	v0 = $v1(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = a2;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSdkCore_25893CF1(...);
	s2 = v0;
	a0 = 0;
	a1 = 48;
	if ((s32)v0 < 0)
		goto loc_000132AC;
	v0 = onesegSal_265926E7(...);
	a1 = *(s32*)(s1 + 60);
	a2 = *(s32*)(s1 + 56);
	s0 = v0;
	asm("mult       $s3, $a1");
	a0 = v0;
	asm("mflo       $a1");
	a3 = 0;
	v0 = sub_00016524(...);
	*(s32*)(s1 + 64) = s0;
	v0 = 0x80000000;
	if (s0 == 0)
		goto loc_000132B0;

loc_000132AC:		
	v0 = s2;

loc_000132B0:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = *(s32*)(a0 + 64);
	a0 = s0;
	if (s0 != 0)
		goto loc_00013308;

loc_000132EC:		
	a0 = s1;
	v0 = onesegSdkCore_AAD37865(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00013308:		
	v0 = sub_000165B0(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s1 + 64) = 0;
	goto loc_000132EC;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1 & 0xFF;
	a1 = s1;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a0;
	v0 = onesegSdkCore_297BCD6E(...);
	s2 = v0;
	if (v0 == 0)
		goto loc_00013384;
	a0 = *(s32*)(s0 + 64);

loc_00013354:		
	a1 = *(s32*)(s0 + 56);
	v0 = sub_0001667C(...);
	v1 = v0;
	if (s1 == 0)
		goto loc_000133A0;
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 56);
		goto loc_0001337C;
	}
	a0 = *(s32*)(s0 + 4);
	v0 = onesegSal_1EFAB50D(...);
	a0 = *(s32*)(s0 + 64);
	goto loc_00013354;

loc_0001337C:		
	*(s32*)(s2 + 24) = v1;
	*(s32*)(s2 + 28) = v0;

loc_00013384:		
	v0 = s2;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000133A0:		
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 56);
		goto loc_0001337C;
	}
	a1 = s2;
	a0 = s0;
	v0 = onesegSdkCore_246BFCD9(...);
	s2 = 0;
	goto loc_00013384;
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = *(s32*)(s1 + 28);
	a1 = *(s32*)(a1 + 24);
	a0 = *(s32*)(a0 + 64);
	a1 = a1 + v0;
	v0 = sub_00016608(...);
	a0 = *(s32*)(s0 + 4);
	v0 = onesegSal_3F2ADE66(...);
	a0 = s0;

loc_000133F8:		
	a1 = s1;
	v0 = onesegSdkCore_246BFCD9(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;

loc_00013424:		
	s1 = a0;
	v0 = onesegSdkCore_FC227770(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00013438;

loc_00013430:		
	a0 = *(s32*)(s1 + 64);
	v0 = sub_000165F0(...);

loc_00013438:		
	v0 = s0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = a1 + 3;
	v0 = (s32)a1 >> 31;
	v0 = (u32)v0 >> 30;
	a0 = *(s32*)(a0 + 64);
	a1 = a1 + v0;
	NONE;
	v0 = sub_000166F8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00013480(...) // at 0x00013480 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	s1 = s1 + 3;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	s0 = s0 + 3;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	v0 = onesegSdkCore_2E32B2D9(...);
	v0 = (s32)s1 >> 31;
	v1 = (s32)s0 >> 31;
	v0 = (u32)v0 >> 30;
	v1 = (u32)v1 >> 30;
	s1 = s1 + v0;
	s0 = s0 + v1;
	v0 = 0x70000;
	NONE;
	NONE;
	v0 = v0 - 15832;
	*(s32*)(s2 + 60) = s0;
	*(s32*)(s2 + 56) = s1;
	*(s32*)(s2 + 0) = v0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000134F8(...) // at 0x000134F8 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 1048;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSdkCore_838A1E79(...);
	a0 = v0;
	s1 = v0;
	v0 = sub_00013840(...);
	v0 = 0x87010000;
	a1 = s0;
	a0 = s1;
	v0 = v0 | 0x2;
	if (s1 == 0)
		goto loc_00013564;
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 100);
	v0 = $v0(...);
	s0 = v0;

loc_00013554:		
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_0001357C;

loc_0001355C:		
	*(s32*)(s2 + 0) = s1;
	v0 = 0;

loc_00013564:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0001357C:		
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 104);
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 160);

loc_00013598:		
	a0 = s1;
	v0 = $v0(...);
	v0 = s0;
	goto loc_00013564;
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 104);
	s0 = a0;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 0);
	s1 = v0;
	v0 = *(s32*)(v1 + 160);
	a0 = s0;
	v0 = $v0(...);
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000135F0(...) // at 0x000135F0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 1;
	v0 = 0;
	v1 = *(s32*)(a0 + 100);
	a0 = v1;
	if (v1 != 0)
		goto loc_00013618;
	ra = *(s32*)(sp + 0);

loc_00013610:		
	sp = sp + 16;
	return (v0);

loc_00013618:		
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	ra = *(s32*)(sp + 0);
	goto loc_00013610;
}

sub_00013630(...) // at 0x00013630 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 96);
	a0 = v0;
	if (v0 != 0)
		goto loc_00013668;
	ra = *(s32*)(sp + 8);

loc_00013658:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00013660:		
	sp = sp + 16;
	return (v0);

loc_00013668:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 104;
	a1 = s1;
	v0 = sub_00016480(...);
	a0 = *(s32*)(s0 + 96);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s0;
	v0 = onesegSdkCore_C68F14A9(...);
	ra = *(s32*)(sp + 8);
	goto loc_00013658;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v1 = *(u8*)(a1 + 56);
	s0 = a0;
	if (v1 == 0)
		goto loc_000136D4;
	v0 = *(u8*)(a0 + 1012);
	cond = (v0 == 0);
	v0 = 1;
	if (cond)
		goto loc_00013714;

loc_000136D4:		
	a0 = s0;
	if (v1 != 0)
		goto loc_000136E8;
	v0 = *(u8*)(s0 + 1012);
	if (v0 != 0)
		goto loc_00013704;

loc_000136E8:		
	a1 = s1;
	v0 = onesegSdkCore_2797088E(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00013704:		
	*(s8*)(s0 + 1012) = 0;
	v0 = sub_00013BD0(...);

loc_00013710:		
	a0 = s0;
	goto loc_000136E8;

loc_00013714:		
	*(s8*)(a1 + 40) = v0;
	*(s32*)(a0 + 1016) = 0;
	*(s8*)(a0 + 1012) = v0;
	v0 = sub_00013B0C(...);
	a0 = s0;
	goto loc_000136E8;
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 16) = s4;
	s4 = a1;
	*(s32*)(sp + 12) = s3;
	s3 = 0;
	*(s32*)(sp + 4) = s1;
	s1 = a0;

loc_00013754:		
	a0 = s1;
	v0 = sub_00013A98(...);
	s2 = s1 + 48;
	s0 = v0;
	a1 = 100;
	if (v0 != 0)
		goto loc_000137D8;
	a0 = *(s32*)(s1 + 40);
	v0 = onesegSdkCore_A66140B4(...);
	a0 = s2;
	v0 = onesegSdkCore_18EC071A(...);
	a0 = s2;
	if ((s32)v0 <= 0)
		goto loc_00013754;
	v0 = onesegSdkCore_1BFE7BBC(...);
	v1 = *(s32*)(s1 + 0);
	a1 = v0;
	a2 = *(s32*)(v1 + 128);
	a0 = s1;
	v0 = $a2(...);
	cond = ((s32)v0 >= 0);
	s3 = v0;
	if (cond)
		goto loc_00013754;
	a0 = s1;

loc_000137AC:		
	a1 = s4;
	v0 = onesegSdkCore_1FC4079F(...);
	v0 = s3;
	ra = *(s32*)(sp + 20);

loc_000137BC:		
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);

loc_000137CC:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000137D8:		
	a0 = s1;
	a1 = s4;
	a2 = v0;
	v0 = sub_00013A04(...);
	v1 = *(s32*)(s0 + 32);
	a1 = s0;
	if (v1 == 0)
		goto loc_00013830;
	a1 = *(s32*)(s1 + 1008);
	if (a1 == 0)
	{
		a1 = s0;
		goto loc_00013830;
	}

loc_00013800:		
	v0 = *(u8*)(s0 + 7);
	if (v0 == 0)
		goto loc_00013820;
	v0 = *(s32*)(s1 + 1016);
	v0 = v0 + v1;
	*(s32*)(s1 + 1016) = v0;
	v1 = *(s32*)(s0 + 28);
	*(s32*)(s1 + 1020) = v1;

loc_00013820:		
	a0 = s0;
	v0 = $a1(...);
	a0 = s1;
	goto loc_000137AC;

loc_00013830:		
	a0 = s1;
	v0 = sub_00013630(...);
	a0 = s1;
	goto loc_000137AC;
}

sub_00013840(...) // at 0x00013840 
{
	sp = sp - 16;

loc_00013844:		
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = onesegSdkCore_9DFB2C64(...);
	v0 = 0x70000;
	v0 = v0 - 15704;
	*(s32*)(s0 + 0) = v0;
	a0 = s0 + 104;
	*(s32*)(s0 + 96) = 0;

loc_0001386C:		
	*(s32*)(s0 + 100) = 0;
	v0 = sub_0001604C(...);
	*(s32*)(s0 + 1008) = 0;
	a0 = s0 + 1024;
	v0 = onesegSdkCore_257DFA20(...);
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(s0 + 1024) = v0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 20) = s1;
	v0 = onesegSdkCore_07BAA6AB(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000139A0;
	a0 = s2 + 104;
	v0 = sub_0001610C(...);
	v1 = 0x80000000;
	if (v0 != 0)
		s0 = v1;
	a0 = s0;
	if ((s32)s0 < 0)
		goto loc_00013980;
	a0 = s2 + 96;
	v0 = onesegHalToolbox_36A48AF0(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000139A0;
	a1 = 68;
	a0 = 0;
	v0 = onesegSdkCore_838A1E79(...);
	a0 = v0;
	a1 = 512;
	a2 = 1024;
	s0 = v0;
	v0 = sub_00013480(...);

loc_00013908:		
	v0 = 0x70000;
	v0 = v0 - 15768;
	*(s32*)(s0 + 0) = v0;

loc_00013918:		
	s3 = s2 + 100;
	if (s0 == 0)
		goto loc_00013940;
	v0 = *(s32*)(v0 + 4);
	a1 = 0x20000;
	a1 = a1 - 14692;	// "AW_AudioAuAllocator"
	a0 = s0;
	a2 = 16;
	a3 = s2;
	v0 = $v0(...);

loc_0001393C:		
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_000139A8;

loc_00013940:		
	*(s32*)(s3 + 0) = s0;
	v0 = 0;

loc_00013948:		
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000139A0;
	s1 = s2 + 24;

loc_00013954:		
	a0 = s1;
	a1 = sp;
	v0 = onesegSdkCore_78110A7F(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000139A0;
	a1 = *(s32*)(sp + 0);
	a0 = s1;
	v0 = onesegSdkCore_C65BF203(...);
	v1 = *(s32*)(s2 + 100);
	a0 = 0;
	*(s32*)(v0 + 12) = v1;

loc_00013980:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 48;
	return (v0);

loc_000139A0:		
	a0 = s0;
	goto loc_00013980;

loc_000139A8:		
	v1 = *(s32*)(s0 + 0);
	v0 = *(s32*)(v1 + 52);
	a0 = s0;
	v0 = $v0(...);
	v0 = s1;
	goto loc_00013948;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 96);
	a0 = v0;
	if (v0 != 0)
		goto loc_000139F4;

loc_000139DC:		
	a0 = s0;
	v0 = onesegSdkCore_22437F04(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000139F4:		
	v0 = onesegHalToolbox_8C50868C(...);
	*(s32*)(s0 + 96) = 0;
	goto loc_000139DC;
}

sub_00013A04(...) // at 0x00013A04 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = a2;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 16) = ra;
	v0 = *(s32*)(a0 + 96);
	a0 = v0;
	if (v0 != 0)
		goto loc_00013A58;
	v0 = s1;

loc_00013A3C:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00013A58:		
	v0 = *(s32*)(v0 + 0);

loc_00013A5C:		
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 104;
	a1 = s2;
	a2 = s3;
	v0 = sub_0001623C(...);
	a0 = *(s32*)(s0 + 96);
	s1 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s1;
	goto loc_00013A3C;
}

sub_00013A98(...) // at 0x00013A98 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 96);
	a0 = v0;
	if (v0 != 0)
		goto loc_00013AD4;
	v0 = s1;

loc_00013AC0:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00013AD4:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 104;
	v0 = sub_00016430(...);
	a0 = *(s32*)(s0 + 96);
	s1 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s1;
	goto loc_00013AC0;
}

sub_00013B0C(...) // at 0x00013B0C 
{
	sp = sp - 64;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 56) = s2;
	s2 = sp + 16;
	*(s32*)(sp + 52) = s1;
	*(s32*)(sp + 48) = s0;
	s0 = a0;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	s1 = s0 + 68;
	v0 = *(s32*)(v1 + 0);
	s0 = s0 + 1024;
	v0 = $v0(...);
	a1 = *(s32*)(s1 + 8);
	a2 = *(s32*)(s1 + 12);
	v1 = *(s32*)(s1 + 4);
	v0 = *(s32*)(s1 + 16);
	*(s32*)(s0 + 8) = a1;
	a0 = s2;
	*(s32*)(s0 + 12) = a2;
	*(s32*)(s0 + 4) = v1;
	*(s32*)(s0 + 16) = v0;
	v0 = onesegSdkCore_257DFA20(...);
	v0 = *(s32*)(sp + 20);
	v1 = *(s32*)(sp + 32);
	a0 = s2;
	*(s32*)(s1 + 4) = v0;
	*(s32*)(s1 + 16) = v1;
	v0 = *(s32*)(sp + 24);
	v1 = *(s32*)(sp + 28);
	*(s32*)(s1 + 8) = v0;
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(s1 + 12) = v1;
	*(s32*)(sp + 16) = v0;
	v0 = onesegSdkCore_3B9B8073(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 64;
	return (v0);
}

sub_00013BD0(...) // at 0x00013BD0 
{
	sp = sp - 64;
	v0 = a0 + 1024;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	a0 = v0;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 48) = fp;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;

loc_00013C0C:		
	*(s32*)(sp + 0) = v0;
	v0 = onesegSdkCore_5EB7A8F8(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_00013CD0;
	s6 = *(s32*)(v0 + 32);
	s7 = *(s32*)(v0 + 36);
	v1 = *(s32*)(s1 + 1020);
	s4 = 0;

loc_00013C28:		
	s5 = 0;
	s2 = s6;
	cond = ((s32)v1 <= 0);
	s3 = s7;
	if (cond)
		goto loc_00013C64;
	a0 = *(s32*)(s1 + 1016);
	v0 = 0x10000;
	v0 = v0 | 0x5F90;
	asm("mult       $a0, $v0");
	a2 = v1;
	asm("mfhi       $a1");
	asm("mflo       $a0");
	a3 = (s32)v1 >> 31;
	v0 = sub_0000345C(...);
	s4 = v0;
	s5 = v1;

loc_00013C64:		
	fp = 1;
	v0 = (u32)s2 < (u32)s6;

loc_00013C6C:		
	a3 = s3 - s7;
	a3 = a3 - v0;
	v0 = (s32)a3 < (s32)s5;
	a2 = s2 - s6;
	a1 = s0;
	a0 = s1;
	v1 = s1 + 68;
	if (v0 != 0)
		goto loc_00013CA0;

loc_00013C8C:		
	v0 = (u32)a2 < (u32)s4;
	if (s5 == a3)
		goto loc_00013D10;
	v0 = 1;
	*(s8*)(s0 + 40) = v0;

loc_00013C9C:		
	fp = 0;

loc_00013CA0:		
	if (fp == 0)
	{
		a0 = v1;
		goto loc_00013D00;
	}
	v0 = onesegSdkCore_1FC4079F(...);

loc_00013CB0:		
	a0 = *(s32*)(sp + 0);
	v0 = onesegSdkCore_5EB7A8F8(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_00013CD0;
	s2 = *(s32*)(s0 + 32);
	s3 = *(s32*)(s0 + 36);
	v0 = (u32)s2 < (u32)s6;
	goto loc_00013C6C;

loc_00013CD0:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);

loc_00013CF8:		
	sp = sp + 64;
	return (v0);

loc_00013D00:		
	a1 = s0;
	v0 = onesegSdkCore_46053998(...);

loc_00013D08:		
	goto loc_00013CB0;

loc_00013D10:		
	cond = (v0 != 0);
	v0 = 1;
	if (cond)
		goto loc_00013CA0;
	*(s8*)(s0 + 40) = v0;
	goto loc_00013C9C;
}

sub_00013D20(...) // at 0x00013D20 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 120;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a0 = v0;
	v0 = sub_000147AC(...);
	a1 = s0;
	a0 = s1;
	if (s1 == 0)
		goto loc_00013D78;
	v0 = sub_0001485C(...);
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_00013D94;
	*(s32*)(s2 + 0) = s1;

loc_00013D78:		
	v0 = 0;

loc_00013D7C:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00013D90:		
	sp = sp + 16;
	return (v0);

loc_00013D94:		
	v0 = sub_0001490C(...);
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 16);
	a0 = s1;
	v0 = $v0(...);
	v0 = s0;
	goto loc_00013D7C;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = sub_0001490C(...);
	s1 = v0;

loc_00013DD0:		
	a0 = s0;
	if (s0 == 0)
		goto loc_00013DE8;
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(v0 + 16);
	v0 = $v1(...);

loc_00013DE8:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 80;
	*(s32*)(sp + 48) = s4;
	s4 = 1;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 64) = ra;
	*(s32*)(sp + 60) = s7;
	*(s32*)(sp + 56) = s6;
	*(s32*)(sp + 52) = s5;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	v0 = *(u8*)(a0 + 4);
	s0 = a0;
	if (v0 != 0)
		goto loc_00013EA8;
	s6 = 1;
	s7 = 2;
	a0 = *(s32*)(s0 + 12);

loc_00013E44:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 20);
	a0 = *(s32*)(s0 + 24);
	*(s32*)(s0 + 24) = v1;
	if (v1 == s6)
		goto loc_0001446C;
	v0 = (s32)v1 < (s32)2;
	if (v0 != 0)
		goto loc_00014190;
	v0 = 4;
	if (v1 == s7)
		goto loc_00014154;
	cond = (v1 == v0);
	v1 = a0 ^ 0x4;
	if (cond)
		goto loc_00013EE0;
	a0 = *(s32*)(s0 + 12);

loc_00013E84:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s0;
	v0 = sub_0001499C(...);
	v0 = *(u8*)(s0 + 4);

loc_00013EA0:		
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00013E44;
	}

loc_00013EA8:		
	a0 = s0;
	v0 = sub_00014A00(...);
	ra = *(s32*)(sp + 64);
	s7 = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = 0;
	sp = sp + 80;
	return (v0);

loc_00013EE0:		
	v0 = a0 ^ 0x1;
	v0 = (u32)v0 < (u32)1;
	v1 = (u32)v1 < (u32)1;
	v0 = v0 | v1;
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00014048;
	}
	s1 = 0;
	if (s4 != 0)
		goto loc_000140A4;
	v0 = *(s32*)(s0 + 16);
	s2 = *(s32*)(v0 + 8);
	s3 = *(s32*)(v0 + 12);
	a0 = 0x00000;
	a0 = *(s32*)(a0 + 5784);

loc_00013F14:		
	v1 = -1;
	v0 = -1;
	*(s32*)(sp + 16) = v0;
	*(s32*)(sp + 20) = v1;
	if (a0 != 0)
		goto loc_00014094;

loc_00013F28:		
	v0 = *(s32*)(sp + 16);
	v1 = *(s32*)(sp + 20);
	a0 = (u32)v0 < (u32)s2;
	v1 = v1 - s3;
	v1 = v1 - a0;
	v0 = v0 - s2;
	if ((s32)v1 <= 0)
		goto loc_0001407C;
	s4 = s0 + 48;

loc_00013F48:		
	s5 = s0 + 52;

loc_00013F4C:		
	a0 = s1;
	if (s1 == 0)
		goto loc_00013F64;
	v0 = *(s32*)(s0 + 28);
	s2 = *(s32*)(s1 + 16);

loc_00013F5C:		
	s3 = *(s32*)(s1 + 20);
	v0 = $v0(...);

loc_00013F64:		
	s1 = 0;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = *(s32*)(s0 + 48);
	a0 = s4;
	a1 = s4 + 4;
	if (v0 == 0)
		goto loc_00014060;
	if (s5 != 0)
	{
		s1 = *(s32*)(s0 + 52);
		goto loc_00013F9C;
	}

loc_00013F9C:		
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	if (s1 == 0)
	{
		*(s32*)(s0 + 20) = s6;
		goto loc_00014040;
	}
	v0 = *(s32*)(sp + 16);
	v1 = *(s32*)(sp + 20);
	a0 = (u32)v0 < (u32)s2;
	v1 = v1 - s3;
	v0 = v0 - s2;
	v1 = v1 - a0;
	a0 = (u32)v0 < (u32)1891;
	if ((s32)v1 > 0)
		goto loc_00013F4C;
	if (v1 != 0)
		goto loc_00013FF0;
	if (a0 == 0)
		goto loc_00013F4C;

loc_00013FF0:		
	if (s1 == 0)
	{
		*(s32*)(s0 + 20) = s6;
		goto loc_00014040;
	}
	s4 = s0 + 48;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = s4;
	a2 = s1;
	a1 = s0 + 52;
	v0 = sub_00011ED8(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	*(s32*)(s0 + 20) = s6;

loc_00014040:		
	s4 = 1;
	a0 = *(s32*)(s0 + 12);

loc_00014048:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);

loc_00014050:		
	v0 = $v0(...);
	v0 = *(u8*)(s0 + 4);
	goto loc_00013EA0;

loc_00014060:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s1 = 0;
	v0 = $v0(...);
	goto loc_00013FF0;

loc_0001407C:		
	v0 = (u32)v0 < (u32)1891;
	if (v1 != 0)
		goto loc_00013FF0;
	s4 = s0 + 48;
	if (v0 == 0)
		goto loc_00013F48;
	goto loc_00013FF0;

loc_00014094:		
	a1 = sp + 16;
	v0 = sub_0000F300(...);
	goto loc_00013F28;

loc_000140A4:		
	s1 = s0 + 48;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 48);
	a0 = *(s32*)(sp + 0);
	if (v1 == 0)
		goto loc_0001413C;
	v0 = s0 + 52;

loc_000140D4:		
	s2 = 0;
	if (v0 == 0)
		goto loc_000140E0;
	s2 = *(s32*)(s0 + 52);

loc_000140E0:		
	a0 = s1;
	a1 = s1 + 4;
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s1 = s2;
	v0 = $v0(...);
	a0 = 0x00000;
	if (s2 == 0)
		goto loc_00014118;
	s3 = *(s32*)(s2 + 20);
	s2 = *(s32*)(s2 + 16);
	a0 = *(s32*)(a0 + 5784);
	goto loc_00013F14;

loc_00014118:		
	v0 = *(s32*)(s0 + 12);

loc_0001411C:		
	*(s32*)(s0 + 20) = s6;
	s4 = 1;

loc_00014124:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);

loc_00014134:		
	v0 = *(u8*)(s0 + 4);
	goto loc_00013EA0;

loc_0001413C:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = *(s32*)(s0 + 12);
	goto loc_0001411C;

loc_00014154:		
	if (a0 == s7)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00013E84;
	}
	t2 = *(s32*)(s0 + 112);
	t3 = *(s32*)(s0 + 116);
	a2 = -1;
	a3 = 0x7FFF0000;
	a3 = a3 | 0xFFFF;
	a0 = s0;
	t0 = a2;
	t1 = a3;
	v0 = sub_00014528(...);
	a0 = s0;
	v0 = sub_00014A00(...);
	a0 = *(s32*)(s0 + 12);
	goto loc_00013E84;

loc_00014190:		
	if (v1 != 0)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00013E84;
	}
	if (a0 == s7)
		goto loc_0001445C;

loc_000141A0:		
	s1 = s0 + 48;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);

loc_000141AC:		
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);

loc_000141B8:		
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 48);
	v0 = s0 + 52;
	if (v1 == 0)
		goto loc_00014440;
	s2 = 0;
	if (v0 == 0)
		goto loc_000141D8;
	s2 = *(s32*)(s0 + 52);

loc_000141D8:		
	a0 = s1;
	a1 = s1 + 4;
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s1 = s2;
	v0 = $v0(...);
	if (s2 == 0)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00013E84;
	}
	v1 = *(s32*)(s2 + 32);
	v0 = *(s32*)(s0 + 36);
	a0 = *(s32*)(s2 + 28);
	if (v1 == v0)
		goto loc_0001442C;
	v1 = a0 ^ 0x5DC0;

loc_00014214:		
	v0 = a0 ^ 0xAC44;

loc_00014218:		
	v1 = (u32)v1 < (u32)1;
	v0 = (u32)v0 < (u32)1;
	v1 = v1 | v0;
	v0 = 0xBB80;
	if (v1 != 0)
		goto loc_00014404;
	if (a0 == v0)
	{
		*(s32*)(s0 + 32) = a0;
		goto loc_00014408;
	}
	v1 = *(u8*)(s1 + 6);

loc_00014238:		
	v0 = 1;
	if (v1 != 0)
		s4 = v0;
	if (s4 == 0)
	{
		v0 = *(s32*)(s0 + 16);
		goto loc_000143F4;
	}
	s2 = *(s32*)(s1 + 16);
	s3 = *(s32*)(s1 + 20);
	v0 = *(u8*)(s1 + 7);

loc_00014254:		
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_00014328;
	}
	v0 = *(s32*)(s0 + 12);
	*(s32*)(s1 + 16) = s2;
	*(s32*)(s1 + 20) = s3;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	a0 = *(s32*)(s0 + 16);
	if (s4 != 0)
		goto loc_00014318;
	a2 = 0;
	a3 = 0;

loc_00014288:		
	v0 = sub_00018E8C(...);

loc_00014290:		
	if (s4 != 0)
	{
		v0 = *(s32*)(s0 + 28);
		goto loc_000142FC;
	}
	v0 = *(u8*)(s1 + 7);

loc_0001429C:		
	if (v0 != 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_000142D4;
	}
	v0 = *(u8*)(s0 + 60);
	if (v0 != 0)
	{
		a2 = *(s32*)(s1 + 32);
		goto loc_000142C0;
	}
	v0 = *(s32*)(s0 + 64);
	if (v0 != 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_000142D4;
	}
	a2 = *(s32*)(s1 + 32);

loc_000142C0:		
	a0 = *(s32*)(s1 + 36);
	a1 = 0;
	a2 = a2 << 2;
	v0 = Kernel_Library_A089ECA4(...);
	a0 = *(s32*)(s0 + 16);

loc_000142D4:		
	v0 = 0x8000;
	a2 = *(s32*)(s1 + 16);
	a3 = *(s32*)(s1 + 20);
	*(s32*)(a0 + 24) = v0;
	t0 = *(s32*)(s1 + 36);
	v0 = sub_00018FCC(...);
	v0 = *(s32*)(s0 + 40);
	if (v0 != 0)
	{
		a1 = *(s32*)(s0 + 44);
		goto loc_00014304;
	}
	v0 = *(s32*)(s0 + 28);

loc_000142FC:		
	a0 = s1;
	goto loc_00014050;

loc_00014304:		
	a0 = 1;
	a2 = 0;
	v0 = $v0(...);
	v0 = *(s32*)(s0 + 28);
	goto loc_000142FC;

loc_00014318:		
	s4 = 0;
	v0 = sub_00018E20(...);
	v0 = *(u8*)(s1 + 7);
	goto loc_0001429C;

loc_00014328:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s0;
	a2 = s2;
	a3 = s3;
	t0 = sp + 24;
	v0 = sub_00014ACC(...);
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 28);
		goto loc_000142FC;
	}
	a2 = *(s32*)(sp + 24);
	a3 = *(s32*)(sp + 28);
	v1 = 0;
	v0 = 0x10000;
	v0 = v0 | 0x5F90;
	t0 = a2 + v0;
	a0 = (u32)t0 < (u32)v0;
	t1 = a3 + v1;
	t1 = t1 + a0;
	if (t1 != 0)
	{
		s4 = 1;
		goto loc_00014398;
	}
	v0 = 0x20000;
	if (t1 != 0)
		goto loc_00014398;
	v0 = v0 | 0xBF20;
	v0 = (u32)v0 < (u32)t0;
	if (v0 != 0)
	{
		s4 = 1;
		goto loc_00014398;
	}

loc_00014398:		

loc_0001439C:		
	if (s4 == 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_00014288;
	}
	t0 = a2 - 1;
	v0 = (u32)t0 < (u32)-1;
	t1 = a3 - 1;
	t1 = t1 + v0;
	if (t1 != 0)
		goto loc_00014290;
	a0 = a2;
	if (t1 != 0)
		goto loc_000143D4;
	v0 = 0x890000;
	v0 = v0 | 0x543F;
	v0 = (u32)v0 < (u32)t0;
	if (v0 != 0)
		goto loc_00014290;

loc_000143D4:		
	a1 = a3;
	a3 = 0;
	a2 = 90;
	v0 = sub_0000345C(...);
	a0 = v0;
	v0 = onesegSal_FB5FE576(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_00014318;

loc_000143F4:		
	s2 = *(s32*)(v0 + 8);
	s3 = *(s32*)(v0 + 12);
	v0 = *(u8*)(s1 + 7);
	goto loc_00014254;

loc_00014404:		
	*(s32*)(s0 + 32) = a0;

loc_00014408:		
	s4 = 1;
	v0 = *(s32*)(s1 + 32);
	a0 = *(s32*)(s0 + 16);
	*(s32*)(s0 + 36) = v0;
	a1 = *(s32*)(s1 + 28);
	a2 = *(s32*)(s1 + 32);
	v0 = sub_00018E50(...);
	v1 = *(u8*)(s1 + 6);
	goto loc_00014238;

loc_0001442C:		
	v0 = *(s32*)(s0 + 32);
	if (a0 != v0)
	{
		v1 = a0 ^ 0x5DC0;
		goto loc_00014214;
	}
	v1 = *(u8*)(s1 + 6);
	goto loc_00014238;

loc_00014440:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 12);
	goto loc_00013E84;

loc_0001445C:		
	a0 = s0;
	v0 = sub_00014A00(...);
	goto loc_000141A0;

loc_0001446C:		
	if (a0 == s6)
	{
		a0 = *(s32*)(s0 + 12);
		goto loc_0001449C;
	}
	t2 = *(s32*)(s0 + 112);
	t3 = *(s32*)(s0 + 116);
	a2 = -1;
	a3 = 0x7FFF0000;
	a3 = a3 | 0xFFFF;
	a0 = s0;
	t0 = a2;
	t1 = a3;
	v0 = sub_00014528(...);
	a0 = *(s32*)(s0 + 12);

loc_0001449C:		
	s4 = 1;
	goto loc_00013E84;
}

sub_000144A4(...) // at 0x000144A4 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_000144C8;

loc_000144BC:		
	v0 = onesegSdkCore_ADCCA76D(...);
	v1 = v0;

loc_000144C8:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_000144D8(...) // at 0x000144D8 
{
	v0 = 1;
	*(s8*)(a0 + 4) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_000149D0(...);
	v1 = 0;
	v0 = *(s32*)(s0 + 8);

loc_00014500:		
	a0 = v0;
	if (v0 != 0)
		goto loc_00014518;

loc_00014504:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00014518:		
	v0 = onesegSdkCore_EE0853A1(...);
	v1 = v0;
	goto loc_00014504;
}

sub_00014528(...) // at 0x00014528 
{
	sp = sp - 48;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s7;
	s7 = t1;
	*(s32*)(sp + 36) = s6;
	s6 = t0;
	*(s32*)(sp + 32) = s5;
	s5 = a3;
	*(s32*)(sp + 28) = s4;
	s4 = a2;
	*(s32*)(sp + 24) = s3;
	s3 = t3;
	*(s32*)(sp + 20) = s2;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s2 = t2;
	v0 = $v0(...);
	v1 = *(s32*)(sp + 0);
	a2 = -1;
	a3 = 0x7FFF0000;
	a3 = a3 | 0xFFFF;
	*(s32*)(s0 + 72) = s4;
	*(s32*)(s0 + 76) = s5;
	a1 = *(s32*)(v1 + 0);
	*(s32*)(s0 + 80) = s6;
	*(s32*)(s0 + 84) = s7;
	*(s32*)(s0 + 112) = s2;
	*(s32*)(s0 + 116) = s3;
	*(s32*)(s0 + 96) = a2;
	*(s32*)(s0 + 100) = a3;
	*(s32*)(s0 + 88) = a2;
	*(s32*)(s0 + 92) = a3;
	*(s32*)(s0 + 104) = 0;
	*(s32*)(s0 + 108) = 0;

loc_000145C0:		
	v0 = *(s32*)(a1 + 4);
	a0 = v1;
	v0 = $v0(...);
	ra = *(s32*)(sp + 44);
	s7 = *(s32*)(sp + 40);
	s6 = *(s32*)(sp + 36);
	s5 = *(s32*)(sp + 32);
	s4 = *(s32*)(sp + 28);
	s3 = *(s32*)(sp + 24);
	s2 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);
}

sub_000145F4(...) // at 0x000145F4 
{
	sp = sp - 32;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	s2 = a2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a3;
	v0 = $v0(...);
	v1 = *(s32*)(sp + 0);
	*(s32*)(s0 + 44) = s1;
	a1 = *(s32*)(v1 + 0);
	*(s32*)(s0 + 40) = s2;

loc_00014638:		
	v0 = *(s32*)(a1 + 4);
	a0 = v1;
	v0 = $v0(...);
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_00014660(...) // at 0x00014660 
{
	sp = sp - 32;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	*(s32*)(sp + 20) = s1;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	v0 = onesegSdkCore_A50A47BF(...);
	a0 = v0;
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	s0 = s2 + 48;
	v0 = $v0(...);
	a1 = *(s32*)(s0 + 8);
	a2 = s1;
	a0 = s0;
	v0 = sub_00011ED8(...);
	a0 = *(s32*)(sp + 0);

loc_000146AC:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);

loc_000146C0:		
	a0 = s2;
	v0 = sub_000149D0(...);
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_000146DC(...) // at 0x000146DC 
{
	*(s8*)(a0 + 60) = a1;
	return (v0);
}

sub_000146E4(...) // at 0x000146E4 
{
	*(s32*)(a0 + 64) = a1;
	return (v0);
}

sub_000146EC(...) // at 0x000146EC 
{
	v0 = *(s32*)(a0 + 64);
	return (v0);
}

sub_000146F4(...) // at 0x000146F4 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	*(s32*)(s0 + 20) = s1;
	a0 = s0;
	v0 = sub_000149D0(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_00014754(...) // at 0x00014754 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s0 = *(s32*)(s1 + 24);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_000147AC(...) // at 0x000147AC 
{
	sp = sp - 16;
	v0 = 0x70000;
	v1 = 2;
	*(s32*)(sp + 0) = s0;
	v0 = v0 - 15272;
	s0 = a0;
	*(s32*)(a0 + 0) = v0;
	*(s32*)(s0 + 24) = v1;
	*(s32*)(s0 + 20) = v1;
	*(s8*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;
	*(s32*)(s0 + 16) = 0;
	*(s32*)(s0 + 28) = 0;
	*(s32*)(s0 + 32) = 0;
	*(s32*)(s0 + 36) = 0;
	*(s32*)(s0 + 40) = 0;

loc_000147F0:		
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 48;
	v0 = sub_00011F5C(...);

loc_000147FC:		
	a0 = -1;
	a1 = 0x7FFF0000;
	a1 = a1 | 0xFFFF;
	v1 = 0;
	v0 = 1024;
	a2 = 1;
	*(s32*)(s0 + 112) = v0;

loc_00014818:		
	*(s32*)(s0 + 116) = v1;
	*(s32*)(s0 + 64) = a2;
	*(s32*)(s0 + 96) = a0;
	*(s32*)(s0 + 100) = a1;
	*(s8*)(s0 + 60) = 0;
	*(s32*)(s0 + 72) = a0;
	*(s32*)(s0 + 76) = a1;
	*(s32*)(s0 + 80) = a0;
	*(s32*)(s0 + 84) = a1;
	*(s32*)(s0 + 88) = a0;
	*(s32*)(s0 + 92) = a1;
	*(s32*)(s0 + 104) = 0;
	*(s32*)(s0 + 108) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0001485C(...) // at 0x0001485C 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = a0 + 12;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1;
	v0 = onesegHalToolbox_35CAA030(...);
	s1 = v0;
	a0 = s2 + 8;
	a1 = s0;
	a3 = 16384;
	a2 = 5;
	if ((s32)v0 < 0)
		goto loc_00014904;
	v0 = onesegSdkCore_F942A64D(...);
	s1 = v0;
	a0 = 0;
	a1 = 16432;
	if ((s32)v0 < 0)
		goto loc_00014904;
	v0 = onesegSal_265926E7(...);
	a0 = v0;
	a1 = 0;

loc_000148C0:		
	a2 = 16432;
	s0 = v0;
	v0 = scePaf_D9E2D6E1(...);
	v0 = 0x80000000;
	if (s0 == 0)
		s1 = v0;
	a1 = s2;
	*(s32*)(s2 + 16) = s0;
	if ((s32)s1 < 0)
		goto loc_00014904;
	a0 = *(s32*)(s2 + 8);
	v0 = onesegSdkCore_00565C73(...);
	v0 = 0;

loc_000148EC:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
}

sub_000148F8(...) // at 0x000148F8 
{
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00014904:		
	v0 = s1;
	goto loc_000148EC;
}

sub_0001490C(...) // at 0x0001490C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s1 = a0;
	v0 = sub_000144D8(...);
	s0 = *(s32*)(s1 + 16);
	a0 = s0;
	if (s0 != 0)
		goto loc_00014980;

loc_00014930:		
	v0 = *(s32*)(s1 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_00014970;

loc_0001493C:		
	v0 = *(s32*)(s1 + 12);
	a0 = v0;
	if (v0 != 0)
		goto loc_00014960;

loc_00014948:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_00014960:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s1 + 12) = 0;
	goto loc_00014948;

loc_00014970:		
	v0 = onesegSdkCore_C13FF004(...);
	*(s32*)(s1 + 8) = 0;
	goto loc_0001493C;

loc_00014980:		
	v0 = sub_00018E04(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s1 + 16) = 0;
	goto loc_00014930;
}

sub_0001499C(...) // at 0x0001499C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = -1;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_000149C0;
	ra = *(s32*)(sp + 0);

loc_000149B8:		
	sp = sp + 16;
	return (v0);

loc_000149C0:		
	v0 = onesegSdkCore_A66140B4(...);
	ra = *(s32*)(sp + 0);
	goto loc_000149B8;
}

sub_000149D0(...) // at 0x000149D0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_000149F0;
	ra = *(s32*)(sp + 0);

loc_000149E8:		
	sp = sp + 16;
	return (v0);

loc_000149F0:		
	v0 = onesegSdkCore_C65BBBDC(...);
	ra = *(s32*)(sp + 0);
	goto loc_000149E8;
}

sub_00014A00(...) // at 0x00014A00 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 28) = s3;
	s3 = a0 + 52;
	*(s32*)(sp + 24) = s2;
	s2 = a0 + 48;
	*(s32*)(sp + 20) = s1;
	s1 = a0;

loc_00014A24:		

loc_00014A28:		
	s0 = 0;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);

loc_00014A30:		
	a0 = v0;
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = *(s32*)(s1 + 48);
	a0 = s2;
	a1 = s2 + 4;
	if (v0 == 0)
		goto loc_00014AB0;
	if (s3 != 0)
	{
		s0 = *(s32*)(s1 + 52);
		goto loc_00014A5C;
	}

loc_00014A5C:		
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	a0 = s0;
	if (s0 == 0)
		goto loc_00014A94;
	v0 = *(s32*)(s1 + 28);
	v0 = $v0(...);
	goto loc_00014A24;

loc_00014A94:		
	ra = *(s32*)(sp + 32);

loc_00014A98:		
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00014AB0:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 32);
	goto loc_00014A98;
}

sub_00014ACC(...) // at 0x00014ACC 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = a3;
	*(s32*)(sp + 24) = s2;
	s2 = a2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = ra;
	v0 = *(s32*)(a0 + 72);
	a0 = -1;
	s1 = t0;
	if (v0 == a0)
		goto loc_00014C64;
	v0 = *(s32*)(s0 + 80);

loc_00014B04:		
	if (v0 == a0)
	{
		v1 = *(s32*)(s0 + 84);
		goto loc_00014C4C;
	}
	v0 = -1;

loc_00014B10:		
	cond = (s2 == v0);
	v0 = 0x7FFF0000;
	if (cond)
		goto loc_00014C38;

loc_00014B18:		
	a0 = sp;
	v0 = onesegHalToolbox_7A7C971B(...);
	v1 = 3;
	if ((s32)v0 < 0)
		goto loc_00014BB4;
	a1 = *(s32*)(s0 + 88);
	v0 = -1;
	v1 = *(s32*)(s0 + 92);
	if (a1 == v0)
		goto loc_00014C20;
	a0 = *(s32*)(sp + 4);

loc_00014B3C:		
	v0 = (s32)a0 < (s32)v1;
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 104);
		goto loc_00014C14;
	}
	v0 = *(s32*)(sp + 0);
	if (v1 == a0)
		goto loc_00014C04;

loc_00014B50:		
	a0 = *(s32*)(sp + 0);
	a1 = *(s32*)(sp + 4);
	a2 = *(s32*)(s0 + 96);
	v0 = -1;
	*(s32*)(s0 + 88) = a0;
	*(s32*)(s0 + 92) = a1;
	v1 = *(s32*)(s0 + 100);
	if (a2 == v0)
		goto loc_00014BEC;
	v0 = (s32)s3 < (s32)v1;

loc_00014B74:		
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 108);
		goto loc_00014BE0;
	}
	v0 = (u32)s2 < (u32)a2;
	if (v1 == s3)
		goto loc_00014BD4;

loc_00014B84:		
	v0 = (u32)s2 < (u32)a0;

loc_00014B88:		
	a0 = s2 - a0;
	a0 = a0 + 1800;
	a1 = s3 - a1;
	v1 = (u32)a0 < (u32)1800;
	a1 = a1 - v0;
	a1 = a1 + v1;
	*(s32*)(s0 + 96) = s2;
	*(s32*)(s0 + 100) = s3;
	v1 = 0;
	*(s32*)(s1 + 0) = a0;
	*(s32*)(s1 + 4) = a1;

loc_00014BB4:		
	ra = *(s32*)(sp + 32);

loc_00014BB8:		
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00014BD4:		
	cond = (v0 == 0);
	v0 = (u32)s2 < (u32)a0;
	if (cond)
		goto loc_00014B88;
	v0 = *(s32*)(s0 + 108);

loc_00014BE0:		
	v0 = v0 + 1;
	*(s32*)(s0 + 108) = v0;
	goto loc_00014B84;

loc_00014BEC:		
	v0 = 0x7FFF0000;
	v0 = v0 | 0xFFFF;
	if (v1 != v0)
	{
		v0 = (s32)s3 < (s32)v1;
		goto loc_00014B74;
	}
	v0 = (u32)s2 < (u32)a0;
	goto loc_00014B88;

loc_00014C04:		
	v0 = (u32)v0 < (u32)a1;
	if (v0 == 0)
		goto loc_00014B50;
	v0 = *(s32*)(s0 + 104);

loc_00014C14:		
	v0 = v0 + 1;
	*(s32*)(s0 + 104) = v0;
	goto loc_00014B50;

loc_00014C20:		
	v0 = 0x7FFF0000;
	v0 = v0 | 0xFFFF;
	a0 = *(s32*)(sp + 4);
	if (v1 != v0)
		goto loc_00014B3C;
	goto loc_00014B50;

loc_00014C38:		
	v0 = v0 | 0xFFFF;
	v1 = 3;
	if (s3 != v0)
		goto loc_00014B18;
	ra = *(s32*)(sp + 32);
	goto loc_00014BB8;

loc_00014C4C:		
	v0 = 0x7FFF0000;
	v0 = v0 | 0xFFFF;
	cond = (v1 != v0);
	v0 = -1;
	if (cond)
		goto loc_00014B10;
	v1 = 3;
	goto loc_00014BB4;

loc_00014C64:		
	v1 = *(s32*)(s0 + 76);
	v0 = 0x7FFF0000;
	v0 = v0 | 0xFFFF;

loc_00014C74:		
	if (v1 != v0)
	{
		v0 = *(s32*)(s0 + 80);
		goto loc_00014B04;
	}
	v1 = 3;
	goto loc_00014BB4;
}

sub_00014C80(...) // at 0x00014C80 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 68;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a0 = v0;
	v0 = sub_00015550(...);
	a1 = s0;
	a0 = s1;
	if (s1 == 0)
		goto loc_00014CD8;
	v0 = sub_000155A4(...);
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_00014CF4;
	*(s32*)(s2 + 0) = s1;

loc_00014CD8:		
	v0 = 0;

loc_00014CDC:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00014CF4:		
	v0 = sub_000156AC(...);
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 16);
	a0 = s1;
	v0 = $v0(...);
	v0 = s0;
	goto loc_00014CDC;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a0;
	v0 = sub_000156AC(...);
	s1 = v0;
	a0 = s0;
	if (s0 == 0)
		goto loc_00014D48;
	v0 = *(s32*)(s0 + 0);
	v1 = *(s32*)(v0 + 16);
	v0 = $v1(...);

loc_00014D48:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 36) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = s0;
	s0 = 0;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s2;
	v0 = *(u8*)(a0 + 4);
	*(s32*)(a0 + 32) = 0;
	*(s32*)(a0 + 36) = 0;
	if (v0 == 0)
		goto loc_00014DB0;

loc_00014D8C:		
	a0 = s1;
	v0 = sub_000153A8(...);
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = 0;

loc_00014DA8:		
	sp = sp + 48;
	return (v0);

loc_00014DB0:		
	a0 = *(s32*)(s1 + 12);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 16);
	v0 = (u32)v1 < (u32)5;
	*(s32*)(s1 + 20) = v1;
	if (v0 == 0)
		goto loc_00014E14;
	v0 = v1 << 2;
	v1 = 0x70000;
	v1 = v1 - 16840;
	v0 = v0 + v1;
	a0 = *(s32*)(v0 + 0);
	a0;
	if (s0 != 0)
		goto loc_00014E28;
	a0 = *(s32*)(s1 + 12);

loc_00014DFC:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s1;
	v0 = sub_0001574C(...);

loc_00014E14:		
	v0 = *(u8*)(s1 + 4);

loc_00014E18:		
	s0 = *(s32*)(s1 + 20);
	if (v0 == 0)
		goto loc_00014DB0;
	goto loc_00014D8C;

loc_00014E28:		
	a0 = s1;
	v0 = sub_00015820(...);
	a0 = *(s32*)(s1 + 12);
	goto loc_00014DFC;
	v1 = *(s32*)(s1 + 32);

loc_00014E3C:		
	v0 = 1;
	if (v1 == 0)
		goto loc_00014F94;
	a0 = *(s32*)(s1 + 20);
	a1 = -1;
	if (a0 == v0)
		goto loc_00014F80;
	v1 = a0 ^ 0x3;
	v0 = 4;
	if (v1 == 0)
		a1 = 0;
	if (a0 == v0)
		goto loc_00014F1C;

loc_00014E60:		
	v0 = a1 + 299;
	v0 = (u32)v0 < (u32)360;

loc_00014E6C:		
	if (v0 != 0)
		goto loc_00014ECC;
	v0 = a1 - 61;
	v0 = (u32)v0 < (u32)4940;
	if (v0 == 0)
	{
		a1 = *(s32*)(s1 + 32);
		goto loc_00014EA4;
	}
	a0 = *(s32*)(s1 + 12);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = sceDisplayWaitVblankStart(...);
	v0 = *(u8*)(s1 + 4);
	goto loc_00014E18;

loc_00014EA4:		
	a0 = s1;
	v0 = sub_000157B0(...);
	v0 = *(s32*)(s1 + 12);
	*(s32*)(s1 + 32) = 0;

loc_00014EB4:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = *(u8*)(s1 + 4);
	goto loc_00014E18;

loc_00014ECC:		
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(s1 + 32);
	a1 = *(s32*)(v0 + 0);
	a0 = *(s32*)(v1 + 4);
	v0 = $a1(...);
	a1 = *(s32*)(s1 + 36);
	a0 = s1;
	v0 = sub_000157B0(...);
	v0 = *(s32*)(s1 + 12);
	a1 = *(s32*)(s1 + 32);
	*(s32*)(s1 + 32) = 0;
	a0 = v0;
	v1 = *(s32*)(v0 + 0);
	*(s32*)(s1 + 36) = a1;

loc_00014F08:		
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = *(u8*)(s1 + 4);
	goto loc_00014E18;

loc_00014F1C:		
	a0 = sp + 16;
	v0 = onesegCore_5BC4D11C(...);
	a1 = *(s32*)(s1 + 32);
	a0 = *(s32*)(sp + 20);
	v1 = *(s32*)(a1 + 20);
	v0 = (s32)v1 < (s32)a0;
	if (v0 != 0)
	{
		a1 = 0;
		goto loc_00014E60;
	}
	if (a0 == v1)
	{
		v0 = *(s32*)(a1 + 16);
		goto loc_00014F68;
	}
	a1 = *(s32*)(s1 + 12);

loc_00014F48:		
	v0 = 2;
	*(s32*)(s1 + 16) = v0;
	v0 = *(s32*)(a1 + 0);

loc_00014F54:		
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	v0 = *(u8*)(s1 + 4);
	goto loc_00014E18;

loc_00014F68:		
	v1 = *(s32*)(sp + 16);
	v0 = (u32)v0 < (u32)v1;
	if (v0 == 0)
	{
		a1 = *(s32*)(s1 + 12);
		goto loc_00014F48;
	}
	a1 = 0;
	goto loc_00014E60;

loc_00014F80:		
	a0 = *(s32*)(v1 + 16);
	a1 = *(s32*)(v1 + 20);
	v0 = sub_0000FA90(...);
	a1 = v0;
	goto loc_00014E60;

loc_00014F94:		
	a0 = *(s32*)(s1 + 12);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s2 = s1 + 44;
	v0 = $v0(...);

loc_00014FA8:		
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	s0 = *(s32*)(s1 + 44);
	v0 = $v0(...);
	if (s0 == 0)
		goto loc_00015068;
	a0 = *(s32*)(s1 + 12);

loc_00014FE8:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 0) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 44);
	a0 = *(s32*)(sp + 0);
	if (v1 == 0)
		goto loc_00015060;
	v0 = s1 + 48;
	s0 = 0;
	if (v0 == 0)
		goto loc_00015034;
	s0 = *(s32*)(s1 + 48);

loc_00015034:		
	a0 = s2;
	a1 = s2 + 4;
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);

loc_00015044:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = *(s32*)(s1 + 12);
	*(s32*)(s1 + 32) = s0;
	goto loc_00014EB4;

loc_00015060:		
	s0 = 0;
	goto loc_00015044;

loc_00015068:		
	a0 = s1;
	v0 = sub_0001574C(...);
	a0 = *(s32*)(s1 + 12);
	goto loc_00014FE8;
	v1 = s0 ^ 0x4;
	v0 = s0 ^ 0x2;
	v0 = (u32)0 < (u32)v0;
	v1 = (u32)0 < (u32)v1;
	v0 = v0 & v1;
	if (v0 == 0)
	{
		v1 = *(s32*)(s1 + 32);
		goto loc_00014E3C;
	}
	a0 = *(s32*)(s1 + 12);
	v1 = *(s32*)(a0 + 0);
	goto loc_00014F08;
}

sub_000150A0(...) // at 0x000150A0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 == 0)
		goto loc_000150C4;
	v0 = onesegSdkCore_ADCCA76D(...);
	v1 = v0;

loc_000150C4:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_000150D4(...) // at 0x000150D4 
{
	v0 = 1;
	*(s8*)(a0 + 4) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_00015780(...);
	v1 = 0;
	v0 = *(s32*)(s0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015114;

loc_00015100:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00015114:		
	v0 = onesegSdkCore_EE0853A1(...);
	v1 = v0;
	goto loc_00015100;
}

sub_00015124(...) // at 0x00015124 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a1 = *(s32*)(sp + 0);
	v0 = 1;
	*(s32*)(s0 + 56) = v0;
	v1 = *(s32*)(a1 + 0);

loc_0001515C:		
	*(s32*)(s0 + 24) = 0;
	v0 = *(s32*)(v1 + 4);
	a0 = a1;
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_00015180(...) // at 0x00015180 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	*(s32*)(s0 + 24) = 0;
	a0 = s0;
	v0 = sub_000153A8(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_000151DC(...) // at 0x000151DC 
{
	sp = sp - 32;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;

loc_000151E8:		
	s2 = a1;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a2;
	v0 = $v0(...);
	v1 = *(s32*)(sp + 0);
	*(s32*)(s0 + 28) = s1;
	a1 = *(s32*)(v1 + 0);
	*(s32*)(s0 + 24) = s2;
	v0 = *(s32*)(a1 + 4);
	a0 = v1;
	v0 = $v0(...);
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_00015248(...) // at 0x00015248 
{
	a2 = *(s32*)(a0 + 60);
	t0 = 0x10000;
	t0 = t0 | 0x2C10;
	v1 = (s32)a2 < (s32)4;
	a3 = a0;
	t1 = a1;
	v0 = 0;
	if (v1 != 0)
		goto loc_00015270;
	*(s32*)(a0 + 60) = 0;
	a2 = 0;

loc_00015270:		
	asm("mult       $a2, $t0");
	a0 = *(s32*)(a3 + 64);
	a1 = a2 + 1;

loc_0001527C:		
	*(s32*)(a3 + 60) = a1;
	asm("mflo       $v1");
	a0 = a0 + v1;
	*(s32*)(t1 + 0) = a0;
	return (v0);
}

sub_00015290(...) // at 0x00015290 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = s6;
	s6 = a0 + 44;
	*(s32*)(sp + 52) = s5;
	s5 = a1;
	*(s32*)(sp + 48) = s4;
	s4 = a2;
	*(s32*)(sp + 44) = s3;
	s3 = t1;
	*(s32*)(sp + 40) = s2;
	s2 = t0;
	*(s32*)(sp + 36) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 60) = ra;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s0 = 0;
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 40);
	a3 = 0;
	v0 = *(s32*)(v1 + 0);
	a2 = v1 + 4;
	a0 = v1;
	a1 = a2;
	if (v0 == 0)
		goto loc_00015310;

loc_00015304:		
	if (a2 != 0)
	{
		a3 = *(s32*)(v1 + 4);
		goto loc_00015308;
	}

loc_00015308:		
	s0 = a3;
	v0 = sub_00011F18(...);

loc_00015310:		
	*(s32*)(s0 + 16) = s2;
	*(s32*)(s0 + 20) = s3;
	*(s32*)(s0 + 4) = s5;
	*(s32*)(s0 + 8) = s4;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	*(s32*)(sp + 16) = v0;
	a0 = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);

loc_0001533C:		
	a1 = *(s32*)(s6 + 8);
	a2 = s0;
	a0 = s6;
	v0 = sub_00011ED8(...);
	a0 = *(s32*)(sp + 16);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s1;
	v0 = sub_00015780(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = 0;
	sp = sp + 64;
	return (v0);
}

sub_000153A8(...) // at 0x000153A8 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);

loc_000153C0:		
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 0);
	a0 = 0;
	v0 = $v1(...);
	a0 = s0;
	v0 = sub_00015820(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);

loc_000153FC:		
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_00015414(...) // at 0x00015414 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s0 = a1;
	v0 = $v0(...);
	v0 = onesegCore_A80C7961(...);
	v1 = *(s32*)(v0 + 4);
	a0 = (u32)s0 < (u32)1;
	v0 = $v1(...);
	a1 = *(s32*)(sp + 0);
	*(s32*)(s1 + 56) = s0;
	v0 = *(s32*)(a1 + 0);
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_00015484(...) // at 0x00015484 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	*(s32*)(s0 + 16) = s1;
	a0 = s0;
	v0 = sub_00015780(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_000154E4(...) // at 0x000154E4 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v0 = 2;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	if (a1 == 0)
		goto loc_0001553C;
	a0 = *(s32*)(a0 + 12);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(s0 + 20);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(s1 + 0) = v0;
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = 0;

loc_0001553C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
}

sub_00015550(...) // at 0x00015550 
{
	sp = sp - 16;
	v0 = 0x70000;

loc_00015558:		
	*(s32*)(sp + 4) = s1;
	v0 = v0 - 15240;
	s1 = 1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(a0 + 0) = v0;
	*(s32*)(s0 + 16) = s1;
	*(s32*)(s0 + 20) = s1;
	*(s8*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(sp + 8) = ra;
	a0 = a0 + 44;
	v0 = sub_00011F5C(...);
	*(s32*)(s0 + 56) = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000155A4(...) // at 0x000155A4 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = a0;
	a0 = a0 + 12;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 8) = s2;
	v0 = onesegHalToolbox_35CAA030(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0001565C;
	a0 = s3 + 8;
	a1 = s1;
	a2 = 4;
	a3 = 16384;
	v0 = onesegSdkCore_F942A64D(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0001565C;
	a1 = 112;
	a0 = 0;
	v0 = onesegSal_265926E7(...);
	s1 = v0;
	a0 = v0;
	v0 = sub_00011F5C(...);
	a0 = s1;
	v0 = sub_00011F5C(...);
	s0 = s1 + 16;
	s2 = 3;

loc_00015618:		
	a1 = *(s32*)(s1 + 8);
	a2 = s0;
	a0 = s1;
	s2 = s2 - 1;
	v0 = sub_00011ED8(...);
	s0 = s0 + 24;
	if ((s32)s2 >= 0)
		goto loc_00015618;
	*(s32*)(s3 + 40) = s1;
	s0 = 0x80000000;
	if (s1 == 0)
		goto loc_0001565C;
	*(s32*)(s3 + 60) = 0;
	a1 = 0x40000;
	a0 = 16;
	a1 = a1 | 0xB040;
	v0 = onesegSal_020B3CC6(...);
	*(s32*)(s3 + 64) = v0;
	if (v0 != 0)
		goto loc_00015698;

loc_0001565C:		
	a1 = *(s32*)(s3 + 40);
	if (a1 != 0)
		goto loc_00015688;

loc_00015668:		
	v0 = s0;

loc_0001566C:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00015688:		
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s3 + 40) = 0;
	goto loc_00015668;

loc_00015698:		
	a0 = *(s32*)(s3 + 8);
	a1 = s3;
	v0 = onesegSdkCore_00565C73(...);
	v0 = 0;
	goto loc_0001566C;
}

sub_000156AC(...) // at 0x000156AC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_000150D4(...);
	v1 = *(s32*)(s0 + 64);
	a0 = v1;
	if (v1 != 0)
		goto loc_00015738;

loc_000156CC:		
	v0 = *(s32*)(s0 + 40);
	a0 = 0;
	a1 = v0;
	if (v0 != 0)
		goto loc_00015728;

loc_000156DC:		
	v0 = *(s32*)(s0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015718;

loc_000156E8:		
	v0 = *(s32*)(s0 + 12);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015708;

loc_000156F4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_00015708:		
	v0 = onesegHalToolbox_896D6109(...);
	*(s32*)(s0 + 12) = 0;
	goto loc_000156F4;

loc_00015718:		
	v0 = onesegSdkCore_C13FF004(...);
	*(s32*)(s0 + 8) = 0;
	goto loc_000156E8;

loc_00015728:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 40) = 0;
	goto loc_000156DC;

loc_00015738:		

loc_0001573C:		
	v0 = onesegSal_BF12FF51(...);
	*(s32*)(s0 + 64) = 0;
	*(s32*)(s0 + 60) = 0;
	goto loc_000156CC;
}

sub_0001574C(...) // at 0x0001574C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = -1;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015770;
	ra = *(s32*)(sp + 0);

loc_00015768:		
	sp = sp + 16;
	return (v0);

loc_00015770:		
	v0 = onesegSdkCore_A66140B4(...);
	ra = *(s32*)(sp + 0);
	goto loc_00015768;
}

sub_00015780(...) // at 0x00015780 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = *(s32*)(a0 + 8);
	a0 = v0;
	if (v0 != 0)
		goto loc_000157A0;
	ra = *(s32*)(sp + 0);

loc_00015798:		
	sp = sp + 16;
	return (v0);

loc_000157A0:		
	v0 = onesegSdkCore_C65BBBDC(...);
	ra = *(s32*)(sp + 0);
	goto loc_00015798;
}

sub_000157B0(...) // at 0x000157B0 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	v1 = (u32)0 < (u32)a1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	a2 = a1;

loc_000157C8:		
	s0 = a1;
	*(s32*)(sp + 8) = ra;
	a3 = *(s32*)(a0 + 40);
	v0 = (u32)0 < (u32)a3;
	v0 = v0 & v1;
	a0 = a3;
	if (v0 != 0)
		goto loc_000157F8;
	ra = *(s32*)(sp + 8);

loc_000157E8:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000157F8:		
	a1 = *(s32*)(a3 + 8);
	v0 = sub_00011ED8(...);
	v0 = *(s32*)(s1 + 24);
	if (v0 == 0)
	{
		ra = *(s32*)(sp + 8);
		goto loc_000157E8;
	}
	a0 = *(s32*)(s1 + 28);
	a1 = *(s32*)(s0 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 8);
	goto loc_000157E8;
}

sub_00015820(...) // at 0x00015820 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	s3 = a0 + 48;
	*(s32*)(sp + 24) = s2;
	s2 = a0 + 44;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 16) = s0;

loc_00015848:		
	a1 = *(s32*)(a0 + 36);
	v0 = sub_000157B0(...);
	*(s32*)(s1 + 36) = 0;
	a0 = s1;
	a1 = *(s32*)(s1 + 32);
	v0 = sub_000157B0(...);
	*(s32*)(s1 + 32) = 0;

loc_00015860:		
	s0 = 0;
	v0 = onesegSdkCore_A50A47BF(...);
	v1 = *(s32*)(v0 + 0);
	a0 = v0;
	*(s32*)(sp + 0) = v0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = *(s32*)(s1 + 44);
	a0 = s2;
	a1 = s2 + 4;
	if (v0 == 0)
		goto loc_000158EC;
	if (s3 != 0)
	{
		s0 = *(s32*)(s1 + 48);
		goto loc_00015898;
	}

loc_00015898:		
	v0 = sub_00011F18(...);
	a0 = *(s32*)(sp + 0);
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 4);
	v0 = $v1(...);
	a1 = s0;
	a0 = s1;
	if (s0 == 0)
		goto loc_000158D0;

loc_000158C4:		
	v0 = sub_000157B0(...);
	goto loc_00015860;

loc_000158D0:		
	ra = *(s32*)(sp + 32);

loc_000158D4:		
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000158EC:		
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 32);
	goto loc_000158D4;
}

sub_00015908(...) // at 0x00015908 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;

loc_00015914:		
	a0 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	a1 = 2016;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	v0 = onesegSdkCore_838A1E79(...);
	a0 = v0;
	s1 = v0;
	v0 = sub_00015C24(...);
	v0 = 0x87010000;
	a1 = s0;
	a0 = s1;

loc_0001594C:		
	v0 = v0 | 0x2;
	if (s1 == 0)
		goto loc_00015974;
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 100);
	v0 = $v0(...);

loc_00015960:		
	s0 = v0;
	a0 = s1;
	if ((s32)v0 < 0)
		goto loc_0001598C;
	*(s32*)(s2 + 0) = s1;
	v0 = 0;

loc_00015974:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0001598C:		
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 104);
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 0);
	v0 = *(s32*)(v1 + 160);
	a0 = s1;
	v0 = $v0(...);
	v0 = s0;
	goto loc_00015974;
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 104);
	s0 = a0;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 0);
	s1 = v0;
	v0 = *(s32*)(v1 + 160);
	a0 = s0;
	v0 = $v0(...);

loc_000159E8:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00015A00(...) // at 0x00015A00 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 1;
	v0 = 0;
	v1 = *(s32*)(a0 + 108);
	a0 = v1;
	if (v1 != 0)
		goto loc_00015A28;
	ra = *(s32*)(sp + 0);

loc_00015A20:		
	sp = sp + 16;
	return (v0);

loc_00015A28:		
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 12);
	v0 = $v0(...);
	ra = *(s32*)(sp + 0);
	goto loc_00015A20;
}

sub_00015A40(...) // at 0x00015A40 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015A78;
	ra = *(s32*)(sp + 8);

loc_00015A68:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00015A78:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 112;
	a1 = s1;
	v0 = sub_00016E90(...);
	a0 = *(s32*)(s0 + 104);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	a0 = s0;
	v0 = onesegSdkCore_C68F14A9(...);
	ra = *(s32*)(sp + 8);
	goto loc_00015A68;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;

loc_00015AC8:		
	*(s32*)(sp + 8) = ra;
	v0 = *(u8*)(a1 + 40);
	s0 = a1;
	if (v0 != 0)
		goto loc_00015B48;
	a1 = *(s32*)(s0 + 24);

loc_00015ADC:		
	a2 = *(s32*)(s0 + 28);
	t0 = *(s32*)(s0 + 32);
	t1 = *(s32*)(s0 + 36);
	t2 = *(s32*)(s0 + 48);
	t3 = *(s32*)(s0 + 52);
	a0 = s1;
	v0 = sub_00015E48(...);
	a2 = *(s32*)(s0 + 32);
	a3 = *(s32*)(s0 + 36);
	v0 = *(s32*)(s1 + 96);
	a0 = s1;
	a1 = s0;
	if (v0 == a2)
		goto loc_00015B34;

loc_00015B10:		
	*(s32*)(s1 + 96) = a2;
	*(s32*)(s1 + 100) = a3;

loc_00015B18:		
	v0 = onesegSdkCore_1FC4079F(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00015B2C:		
	sp = sp + 16;
	return (v0);

loc_00015B34:		
	v0 = *(s32*)(s1 + 100);
	if (v0 != a3)
		goto loc_00015B10;
	goto loc_00015B18;

loc_00015B48:		
	v0 = sub_00015F90(...);
	a1 = *(s32*)(s0 + 24);
	goto loc_00015ADC;
	sp = sp - 16;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 8) = s2;
	s2 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;

loc_00015B74:		
	a0 = s0;
	v0 = sub_00015DE0(...);
	s1 = s0 + 48;
	a0 = s0;
	if (v0 == 0)
		goto loc_00015C08;
	v0 = sub_00015F1C(...);

loc_00015B90:		
	a1 = 100;
	if (v0 == 0)
		goto loc_00015BCC;
	a0 = v0;
	a1 = v0;
	v0 = *(s32*)(s0 + 2008);
	if (v0 == 0)
		goto loc_00015BBC;
	v0 = $v0(...);
	goto loc_00015B74;

loc_00015BBC:		
	a0 = s0;
	v0 = sub_00015A40(...);
	goto loc_00015B74;

loc_00015BCC:		
	a0 = *(s32*)(s0 + 40);
	v0 = onesegSdkCore_A66140B4(...);
	a0 = s1;
	v0 = onesegSdkCore_18EC071A(...);
	a0 = s1;
	if ((s32)v0 <= 0)
		goto loc_00015B74;
	v0 = onesegSdkCore_1BFE7BBC(...);
	v1 = *(s32*)(s0 + 0);
	a1 = v0;
	a2 = *(s32*)(v1 + 128);
	a0 = s0;
	v0 = $a2(...);
	s2 = v0;
	if ((s32)v0 >= 0)
		goto loc_00015B74;

loc_00015C08:		
	v0 = s2;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00015C1C:		
	sp = sp + 16;
	return (v0);
}

sub_00015C24(...) // at 0x00015C24 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = onesegSdkCore_9DFB2C64(...);
	v0 = 0x70000;
	v0 = v0 - 15144;
	*(s32*)(s0 + 0) = v0;
	v0 = 0;

loc_00015C48:
	v1 = 0;
	a0 = s0 + 112;
	*(s32*)(s0 + 96) = v0;
	*(s32*)(s0 + 100) = v1;
	*(s32*)(s0 + 104) = 0;
	*(s32*)(s0 + 108) = 0;
	v0 = sub_000168B0(...);
	*(s32*)(s0 + 2008) = 0;

loc_00015C68:
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

Func()
{
	sp = sp - 48;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 16) = s0;
	v0 = onesegSdkCore_07BAA6AB(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00015D3C;
	a0 = s1 + 104;
	v0 = onesegHalToolbox_36A48AF0(...);
	a1 = 68;
	if ((s32)v0 < 0)
		goto loc_00015D5C;
	a0 = 0;
	v0 = onesegSdkCore_838A1E79(...);
	a0 = v0;
	a1 = 8192;
	a2 = 0x20000;
	s0 = v0;
	v0 = sub_00013480(...);
	v0 = 0x70000;
	v0 = v0 - 15208;
	*(s32*)(s0 + 0) = v0;
	s3 = s1 + 108;
	if (s0 == 0)
		goto loc_00015D04;
	v0 = *(s32*)(v0 + 4);
	a1 = 0x20000;
	a1 = a1 - 14672;	// "VW_VideoAuAllocator"
	a0 = s0;
	a2 = 48;
	a3 = s1;
	v0 = $v0(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_00015D64;

loc_00015D04:		
	*(s32*)(s3 + 0) = s0;
	v0 = 0;

loc_00015D0C:		
	s0 = s1 + 24;
	if ((s32)v0 < 0)
		goto loc_00015D5C;

loc_00015D14:		
	a0 = s0;
	a1 = sp;
	v0 = onesegSdkCore_78110A7F(...);
	a1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00015D5C;

loc_00015D28:		
	a0 = s0;
	v0 = onesegSdkCore_C65BF203(...);
	v1 = *(s32*)(s1 + 108);
	a0 = 0;
	*(s32*)(v0 + 12) = v1;

loc_00015D3C:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 48;
	return (v0);

loc_00015D5C:		
	a0 = v0;
	goto loc_00015D3C;

loc_00015D64:		
	v1 = *(s32*)(s0 + 0);
	v0 = *(s32*)(v1 + 52);
	a0 = s0;
	v0 = $v0(...);
	v0 = s2;
	goto loc_00015D0C;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015DB0;

loc_00015D98:		
	a0 = s0;
	v0 = onesegSdkCore_22437F04(...);

loc_00015DA0:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00015DB0:		
	v0 = onesegHalToolbox_8C50868C(...);
	*(s32*)(s0 + 104) = 0;
	goto loc_00015D98;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00015F90(...);
	v0 = 0;
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00015DE0(...) // at 0x00015DE0 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015E1C;
	v0 = s1;

loc_00015E08:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00015E1C:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = *(s32*)(s0 + 104);
	v1 = *(s32*)(a0 + 0);

loc_00015E34:		
	v0 = *(s32*)(v1 + 4);

loc_00015E3C:		
	s1 = *(s32*)(s0 + 316);
	v0 = $v0(...);
	v0 = s1;
	goto loc_00015E08;
}

sub_00015E48(...) // at 0x00015E48 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s7;
	s7 = a2;
	*(s32*)(sp + 24) = s6;
	s6 = a1;
	*(s32*)(sp + 20) = s5;
	s5 = t3;
	*(s32*)(sp + 16) = s4;
	s4 = t2;
	*(s32*)(sp + 12) = s3;
	s3 = t1;
	*(s32*)(sp + 8) = s2;
	s2 = t0;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015ECC;
	v0 = s1;

loc_00015EA0:		
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);

loc_00015EAC:		
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_00015ECC:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 112;
	a1 = s6;
	a2 = s7;
	t0 = s2;
	t1 = s3;
	t2 = s4;
	t3 = s5;
	v0 = sub_00016AA0(...);
	a0 = *(s32*)(s0 + 104);
	s1 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s1;
	goto loc_00015EA0;
}

sub_00015F1C(...) // at 0x00015F1C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015F58;
	v0 = s1;

loc_00015F44:		
	ra = *(s32*)(sp + 8);

loc_00015F48:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00015F58:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 112;
	v0 = sub_00016BA0(...);
	a0 = *(s32*)(s0 + 104);
	s1 = v0;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s1;
	goto loc_00015F44;
}

sub_00015F90(...) // at 0x00015F90 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_00015FBC;
	ra = *(s32*)(sp + 4);

loc_00015FB0:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00015FBC:		
	v0 = *(s32*)(v0 + 0);
	v1 = *(s32*)(v0 + 0);
	v0 = $v1(...);
	a0 = s0 + 112;
	a1 = 0;
	v0 = sub_00016EB8(...);
	a0 = *(s32*)(s0 + 104);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 4);
	goto loc_00015FB0;
}

sub_00015FF4(...) // at 0x00015FF4 
{
	v0 = *(u8*)(a0 + 2);
	v0 = (u32)v0 >> 6;
	return (v0);
}

sub_00016000(...) // at 0x00016000 
{
	v1 = *(u8*)(a0 + 2);
	v0 = 0x70000;
	v0 = v0 - 16820;
	NONE;
	a0 = v1 << 2;
	v1 = (u32)v1 < (u32)12;
	a0 = a0 + v0;
	v0 = 0;
	if (v1 == 0)
		goto loc_00016028;
	v0 = *(s32*)(a0 + 0);

loc_00016028:		
	return (v0);
}

sub_00016030(...) // at 0x00016030 
{
	v0 = *(u8*)(a0 + 2);
	v1 = *(u8*)(a0 + 3);
	v0 = v0 & 0x1;
	v1 = (u32)v1 >> 6;
	v0 = v0 << 2;
	v0 = v0 | v1;
	return (v0);
}

sub_0001604C(...) // at 0x0001604C 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 864;
	v0 = sub_00011F5C(...);
	a0 = s0 + 876;
	v0 = sub_00011F5C(...);
	v0 = 2;
	v1 = 1;
	*(s32*)(s0 + 900) = v0;
	v0 = 24000;
	*(s8*)(s0 + 888) = v1;
	v1 = 4;
	*(s32*)(s0 + 892) = v0;
	v0 = 0x00000;
	*(s32*)(s0 + 896) = v1;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	*(s32*)(v0 + 5900) = 0;
	sp = sp + 16;
	return (v0);
}

sub_000160A4(...) // at 0x000160A4 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	v0 = 0x00000;
	s1 = v0 + 5888;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	v0 = *(s32*)(s1 + 12);
	s0 = a0;
	if (v0 != 0)
		goto loc_000160FC;

loc_000160C8:		
	s0 = s0 + 32;
	s1 = 11;

loc_000160D0:		
	a0 = *(s32*)(s0 + 4);
	s1 = s1 - 1;
	v0 = scePaf_412B2F09(...);
	*(s32*)(s0 + 4) = 0;
	s0 = s0 + 72;
	if ((s32)s1 >= 0)
		goto loc_000160D0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000160FC:		
	a0 = v0;
	v0 = scePaf_412B2F09(...);
	*(s32*)(s1 + 12) = 0;
	goto loc_000160C8;
}

sub_0001610C(...) // at 0x0001610C 
{
	sp = sp - 32;
	v0 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = v0 + 5888;
	a1 = 4099;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	a0 = s0;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	v0 = sceAudiocodecCheckNeedMem(...);
	v1 = 5;
	if ((s32)v0 < 0)
		goto loc_000161E0;
	a1 = *(s32*)(s0 + 16);
	a0 = 64;
	v0 = scePaf_0C2CD696(...);

loc_0001614C:		
	*(s32*)(s0 + 12) = v0;
	v1 = 5;
	if (v0 == 0)
		goto loc_000161E0;
	v0 = 24000;
	*(s32*)(s1 + 892) = v0;
	a0 = s1;
	v0 = sub_000161FC(...);
	a0 = s0;
	a1 = 4099;
	a2 = sp;
	v0 = sceAudiocodec_59176A0F(...);
	s0 = s1;
	if (v0 == 0)
		goto loc_00016188;
	v0 = 4096;
	*(s32*)(sp + 0) = v0;

loc_00016188:		
	s2 = s1 + 864;
	s1 = 11;

loc_00016190:		
	a1 = *(s32*)(sp + 0);

loc_00016194:		
	a0 = 64;
	s1 = s1 - 1;
	v0 = scePaf_0C2CD696(...);
	v1 = *(s32*)(sp + 0);
	*(s32*)(s0 + 36) = v0;
	a2 = s0;
	a0 = s2;
	*(s32*)(s0 + 44) = v1;
	*(s32*)(s0 + 40) = v1;
	*(s32*)(s0 + 48) = 0;
	*(s8*)(s0 + 6) = 0;
	*(s8*)(s0 + 7) = 0;
	*(s32*)(s0 + 64) = 0;
	s0 = s0 + 72;
	a1 = *(s32*)(s2 + 8);
	v0 = sub_00011ED8(...);
	if ((s32)s1 >= 0)
	{
		a1 = *(s32*)(sp + 0);
		goto loc_00016194;
	}
	v1 = 0;

loc_000161E0:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_000161FC(...) // at 0x000161FC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v1 = 1;
	a2 = *(s32*)(a0 + 892);
	v0 = v0 + 5888;
	*(s8*)(a0 + 888) = v1;
	a1 = 4099;
	a0 = v0;
	*(s32*)(v0 + 40) = a2;
	*(s8*)(v0 + 44) = v1;
	*(s8*)(v0 + 45) = v1;
	v0 = sceAudiocodecInit(...);
	ra = *(s32*)(sp + 0);

loc_00016234:		
	sp = sp + 16;
	return (v0);
}

sub_0001623C(...) // at 0x0001623C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;

loc_00016244:		
	s4 = a0;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s6;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	if (a1 == 0)
		goto loc_00016428;
	s2 = *(s32*)(a1 + 24);
	v0 = 1;
	if (s2 == 0)
		goto loc_00016350;
	a0 = s2;
	if (a2 == 0)
		goto loc_00016350;
	a2 = *(u8*)(a1 + 40);
	v0 = *(s32*)(a1 + 32);
	v1 = *(s32*)(a1 + 36);
	*(s8*)(s1 + 6) = a2;
	a1 = *(u8*)(a1 + 56);
	*(s32*)(s1 + 16) = v0;
	*(s32*)(s1 + 20) = v1;
	*(s8*)(s1 + 7) = a1;
	v0 = *(u8*)(s3 + 40);

loc_000162AC:		
	s0 = (u32)0 < (u32)v0;
	v0 = sub_00015FF4(...);
	v1 = v0 ^ 0x1;
	s5 = v0;
	a0 = s2;
	v0 = 1;
	if (v1 != 0)
		s0 = v0;
	v0 = sub_00016000(...);
	v1 = v0;
	v0 = *(s32*)(s4 + 892);
	if (v0 == v1)
		goto loc_000162E0;
	*(s32*)(s4 + 892) = v1;
	s0 = 1;

loc_000162E0:		
	a0 = s2;
	v0 = sub_00016030(...);
	v1 = v0;
	v0 = *(s32*)(s4 + 896);
	if (v0 == v1)
		goto loc_00016300;
	*(s32*)(s4 + 896) = v1;
	s0 = 1;

loc_00016300:		
	if (s0 != 0)
		goto loc_00016418;
	v0 = *(s32*)(s1 + 36);

loc_0001630C:		
	s6 = 0x00000;
	a0 = s6 + 5888;
	*(s32*)(a0 + 32) = v0;
	v0 = 1;
	*(s32*)(a0 + 24) = s2;
	*(s32*)(a0 + 36) = 0;
	if (s5 == v0)
		goto loc_000163DC;

loc_00016328:		
	v0 = s6 + 5888;

loc_0001632C:		
	v1 = *(s32*)(v0 + 36);
	v1 = (u32)v1 >> 2;
	*(s32*)(s1 + 32) = v1;
	a0 = *(s32*)(v0 + 36);
	if (a0 != 0)
	{
		v0 = *(u8*)(s4 + 888);
		goto loc_00016378;
	}
	v0 = 1;
	*(s8*)(s4 + 888) = v0;
	v0 = 0;

loc_00016350:		
	ra = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00016378:		
	if (v0 == 0)
	{
		v1 = *(s32*)(s4 + 892);
		goto loc_00016390;
	}
	v0 = 1;
	*(s8*)(s4 + 888) = 0;
	*(s8*)(s1 + 6) = v0;
	v1 = *(s32*)(s4 + 892);

loc_00016390:		
	a0 = *(s32*)(s1 + 32);

loc_00016394:		
	a2 = *(s32*)(s1 + 40);

loc_00016398:		
	v0 = *(s32*)(s1 + 44);
	asm("mult       $v1, $a0");
	a3 = s1 + 40;
	v0 = (u32)v0 < (u32)a2;
	a1 = s1 + 44;
	if (v0 == 0)
		a1 = a3;
	asm("mflo       $v1");
	v1 = (u32)v1 >> 10;
	*(s32*)(s1 + 28) = v1;
	a0 = s4;
	a2 = *(s32*)(a1 + 0);
	a3 = *(s32*)(s3 + 60);
	a1 = *(s32*)(s1 + 36);
	a2 = (u32)a2 >> 1;
	v0 = sub_000164A8(...);
	v0 = 0;
	goto loc_00016350;

loc_000163DC:		
	s2 = a0;
	s0 = 0;
	a0 = s2;

loc_000163E8:		
	a1 = 4099;
	v0 = sceAudiocodecDecode(...);
	s0 = s0 + 1;
	a0 = s4;
	if (v0 == 0)
		goto loc_00016328;
	*(s32*)(s2 + 36) = 0;
	v0 = sub_000161FC(...);
	v0 = (s32)s0 < (s32)2;
	a0 = s2;
	if (v0 != 0)
		goto loc_000163E8;
	v0 = s6 + 5888;
	goto loc_0001632C;

loc_00016418:		
	a0 = s4;
	v0 = sub_000161FC(...);
	v0 = *(s32*)(s1 + 36);
	goto loc_0001630C;

loc_00016428:		
	v0 = 1;
	goto loc_00016350;
}

sub_00016430(...) // at 0x00016430 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = a0;
	a2 = v1 + 868;
	*(s32*)(sp + 4) = ra;
	a1 = a2;
	s0 = 0;
	v0 = *(s32*)(a0 + 864);
	a0 = a0 + 864;
	if (v0 == 0)
		goto loc_0001646C;
	v0 = 0;
	if (a2 == 0)
		goto loc_00016464;
	v0 = *(s32*)(v1 + 868);

loc_00016464:		
	s0 = v0;
	v0 = sub_00011F18(...);

loc_0001646C:		
	v0 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00016480(...) // at 0x00016480 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = a0 + 864;
	a2 = a1;
	v0 = *(s32*)(a0 + 8);
	a1 = v0;
	v0 = sub_00011ED8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000164A8(...) // at 0x000164A8 
{
	v0 = (u32)a3 < (u32)6;

loc_000164AC:		
	v1 = 0x70000;
	if (v0 == 0)
		goto loc_000164EC;
	v0 = a3 << 2;
	v1 = v1 - 16772;
	v0 = v0 + v1;
	a0 = *(s32*)(v0 + 0);
	a0;

loc_000164CC:		
	a0 = 0;
	if (a2 == 0)
		goto loc_000164EC;

loc_000164D4:		
	v0 = *(u16*)(a1 + 0);
	a0 = a0 + 2;
	v1 = (u32)a0 < (u32)a2;
	*(s16*)(a1 + 2) = v0;
	a1 = a1 + 4;
	if (v1 != 0)
		goto loc_000164D4;

loc_000164EC:		
	return (v0);

loc_000164F4:		
	return (v0);
	a0 = 0;
	if (a2 == 0)
		goto loc_000164EC;

loc_00016504:		
	v0 = *(u16*)(a1 + 2);
	a0 = a0 + 2;
	v1 = (u32)a0 < (u32)a2;

loc_00016510:		
	*(s16*)(a1 + 0) = v0;
	a1 = a1 + 4;
	if (v1 != 0)
		goto loc_00016504;
	goto loc_000164F4;
}

sub_00016524(...) // at 0x00016524 
{
	sp = sp - 16;
	v0 = a1 + a2;
	*(s32*)(sp + 8) = s2;
	v0 = v0 + a3;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	a1 = v0;
	*(s32*)(sp + 0) = s0;
	s0 = a3;
	*(s32*)(sp + 12) = ra;
	*(s32*)(a0 + 4) = a2;
	a0 = 0;
	*(s32*)(s2 + 0) = v0;
	*(s32*)(s2 + 8) = a3;
	v0 = onesegSal_265926E7(...);
	v1 = v0 + s0;
	a1 = v1 + s1;
	a0 = s2;
	*(s32*)(s2 + 12) = v0;
	if (v0 == 0)
		goto loc_000165A4;
	*(s32*)(s2 + 20) = a1;
	*(s32*)(s2 + 32) = v1;
	*(s32*)(s2 + 16) = v1;
	v0 = sub_000165F0(...);
	*(s32*)(s2 + 44) = 0;

loc_0001658C:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000165A4:		
	v0 = 7;
	*(s32*)(s2 + 44) = v0;
	goto loc_0001658C;
}

sub_000165B0(...) // at 0x000165B0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = 0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(s0 + 12);
	a1 = v0;
	if (v0 != 0)
		goto loc_000165E0;

loc_000165D0:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000165E0:		
	v0 = onesegSal_E64CF915(...);
	*(s32*)(s0 + 12) = 0;
	goto loc_000165D0;
}

sub_000165F0(...) // at 0x000165F0 
{
	v0 = *(s32*)(a0 + 32);
	*(s32*)(a0 + 36) = v0;
	*(s32*)(a0 + 28) = v0;
	*(s32*)(a0 + 24) = v0;
	*(s32*)(a0 + 40) = v0;
	return (v0);
}

sub_00016608(...) // at 0x00016608 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	a2 = 0;
	*(s32*)(sp + 4) = ra;
	v0 = *(s32*)(a0 + 24);
	s0 = a0;
	if (a1 == v0)
		goto loc_00016668;
	a2 = *(s32*)(a0 + 28);
	a3 = *(s32*)(a0 + 32);

loc_0001662C:		
	*(s32*)(s0 + 24) = a1;
	v0 = sub_000167B4(...);
	a0 = s0;
	if (v0 == 0)
		goto loc_00016644;
	v0 = *(s32*)(s0 + 24);
	*(s32*)(s0 + 28) = v0;

loc_00016644:		
	a1 = *(s32*)(s0 + 24);
	a2 = *(s32*)(s0 + 32);
	v0 = sub_0001673C(...);
	a2 = 1;
	if (v0 != 0)
		goto loc_00016668;
	v1 = *(s32*)(s0 + 24);
	v0 = *(s32*)(s0 + 32);
	*(s32*)(s0 + 36) = v1;
	*(s32*)(s0 + 40) = v0;

loc_00016668:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;

loc_00016678:		
	sp = sp + 16;
	return (v0);
}

sub_0001667C(...) // at 0x0001667C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;

loc_00016690:		
	s0 = a1;
	v0 = sub_0001681C(...);
	v0 = (u32)v0 < (u32)s0;
	a0 = s1;
	v1 = 0;
	if (v0 != 0)
		goto loc_000166E0;
	a1 = *(s32*)(s1 + 24);
	a2 = *(s32*)(s1 + 32);
	v0 = sub_0001673C(...);
	v1 = *(s32*)(s1 + 32);
	if (v0 != 0)
		goto loc_000166E0;
	v0 = *(s32*)(s1 + 20);
	v0 = (u32)v0 < (u32)v1;
	ra = *(s32*)(sp + 8);
	if (v0 == 0)
		goto loc_000166E4;
	v0 = *(s32*)(s1 + 16);
	*(s32*)(s1 + 40) = v1;
	v1 = v0;
	*(s32*)(s1 + 36) = v0;
	*(s32*)(s1 + 32) = v0;

loc_000166E0:		
	ra = *(s32*)(sp + 8);

loc_000166E4:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_000166F8(...) // at 0x000166F8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = a1;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a2 = *(s32*)(a0 + 32);
	a1 = *(s32*)(a0 + 24);
	a2 = a2 + v0;
	*(s32*)(a0 + 32) = a2;
	v0 = sub_0001673C(...);
	ra = *(s32*)(sp + 4);
	if (v0 != 0)
		goto loc_00016730;
	v0 = *(s32*)(s0 + 32);
	*(s32*)(s0 + 40) = v0;

loc_00016730:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0001673C(...) // at 0x0001673C 
{
	v0 = (u32)a2 < (u32)a1;
	return (v0);
}

sub_00016744(...) // at 0x00016744 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1;
	v0 = sub_0001673C(...);
	a1 = s1 - s0;
	if (v0 == 0)
		goto loc_00016798;
	v0 = *(s32*)(s2 + 40);
	a2 = *(s32*)(s2 + 36);
	a1 = 0;
	v1 = v0 - s0;

loc_00016780:		
	a0 = (u32)a2 < (u32)s1;
	v0 = (u32)s0 < (u32)v0;
	if (v0 != 0)
		a1 = v1;
	if (a0 == 0)
		goto loc_00016798;

loc_00016790:		
	v0 = s1 - a2;
	a1 = a1 + v0;

loc_00016798:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a1;
	sp = sp + 16;
	return (v0);
}

sub_000167B4(...) // at 0x000167B4 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	a2 = a1;
	*(s32*)(sp + 0) = s0;
	a1 = s1;
	s0 = a0;
	v0 = sub_00016744(...);
	a0 = s0;
	a1 = s1;
	a2 = s3;
	s2 = v0;
	v0 = sub_00016744(...);
	v0 = (u32)v0 < (u32)s2;
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v0 ^ 0x1;
	sp = sp + 32;
	return (v0);
}

sub_0001681C(...) // at 0x0001681C 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	a1 = *(s32*)(a0 + 24);
	a2 = *(s32*)(a0 + 32);
	v0 = sub_0001673C(...);
	if (v0 == 0)
	{
		v0 = *(s32*)(s0 + 20);
		goto loc_00016874;
	}
	v1 = *(s32*)(s0 + 32);
	v0 = *(s32*)(s0 + 24);
	v0 = v0 - v1;
	s1 = v0 - 1;

loc_00016858:		
	NONE;

loc_0001685C:		
	v0 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00016870:		
	sp = sp + 16;
	return (v0);

loc_00016874:		
	v1 = *(s32*)(s0 + 32);

loc_00016878:		
	a0 = v0 - v1;
	v0 = (u32)v0 < (u32)v1;
	if (v0 == 0)
	{
		v0 = *(s32*)(s0 + 4);
		goto loc_000168A8;
	}
	v1 = *(s32*)(s0 + 24);
	v0 = *(s32*)(s0 + 16);
	a0 = v1 - v0;
	v0 = (u32)v0 < (u32)v1;
	if (v0 != 0)
	{
		s1 = a0 - 1;
		goto loc_00016858;
	}
	NONE;
	goto loc_0001685C;

loc_000168A8:		
	s1 = a0 + v0;
	goto loc_00016858;
}

sub_000168B0(...) // at 0x000168B0 
{
	sp = sp - 80;
	*(s32*)(sp + 52) = s5;
	s5 = a0 + 192;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	a0 = s5;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 64) = fp;
	fp = 0x20000;
	fp = fp | 0xFD00;
	*(s32*)(sp + 60) = s7;
	*(s32*)(sp + 56) = s6;
	s7 = -1;
	s6 = -1;
	*(s32*)(sp + 48) = s4;
	s4 = 3;
	*(s32*)(sp + 44) = s3;
	s3 = s0;
	*(s32*)(sp + 40) = s2;
	s2 = s0;
	*(s32*)(sp + 36) = s1;
	v0 = sub_00011F5C(...);
	v0 = 0x70000;
	asm("lwc1       $fpr00, -16744($v0)");
	*(s32*)(s0 + 212) = 0;
	v0 = 0x20000;
	a0 = 0x10000;
	asm("swc1       $fpr00, 1820($s0)");
	*(s32*)(s0 + 216) = 0;
	*(s32*)(s0 + 1888) = 0;
	*(s32*)(s0 + 1892) = 0;

loc_0001692C:		
	*(s32*)(sp + 12) = v0;
	*(s32*)(sp + 16) = v0;
	v0 = 0x10000;
	v0 = v0 | 0xFE00;
	*(s32*)(sp + 8) = a0;
	a0 = a0 | 0x7E80;
	*(s32*)(sp + 0) = a0;
	*(s32*)(sp + 4) = v0;
	v0 = onesegCore_E4FA1424(...);
	a1 = 0xB0000;
	*(s32*)(s0 + 212) = v0;
	a0 = 16;
	a1 = a1 | 0xF400;
	v0 = scePaf_0C2CD696(...);
	a0 = *(s32*)(sp + 8);
	*(s32*)(s0 + 216) = v0;
	s1 = v0;
	a0 = a0 | 0x3EC0;
	v0 = *(s32*)(sp + 12);
	*(s32*)(sp + 8) = a0;
	s0 = s0 + 220;
	v0 = v0 | 0x7D80;
	a0 = *(s32*)(sp + 16);
	*(s32*)(sp + 12) = v0;
	a0 = a0 | 0xBD40;
	*(s32*)(sp + 16) = a0;
	a0 = *(s32*)(sp + 0);

loc_00016998:		
	v0 = s1 + 32640;
	*(s32*)(s2 + 32) = s0;
	v1 = s1 + a0;
	a2 = s2;
	a0 = *(s32*)(sp + 4);
	*(s32*)(s0 + 24) = s1;
	s4 = s4 - 1;
	a3 = s1 + a0;
	a0 = 0xFF00;
	t0 = s1 + a0;

loc_000169C0:		
	a0 = *(s32*)(sp + 8);
	*(s32*)(s0 + 28) = v0;
	s2 = s2 + 48;
	t1 = s1 + a0;
	a0 = *(s32*)(sp + 12);
	*(s32*)(s0 + 32) = v1;
	t2 = s1 + a0;
	a0 = *(s32*)(sp + 16);
	*(s32*)(s0 + 36) = a3;
	t3 = s1 + a0;
	*(s32*)(s0 + 40) = t0;
	a0 = s5;
	s1 = s1 + fp;
	*(s32*)(s0 + 44) = t1;
	*(s32*)(s0 + 48) = t2;
	*(s32*)(s0 + 52) = t3;
	s0 = s0 + 400;
	*(s32*)(s3 + 1824) = s6;
	*(s32*)(s3 + 1828) = s7;
	*(s32*)(s3 + 1856) = s6;
	*(s32*)(s3 + 1860) = s7;
	s3 = s3 + 8;
	a1 = *(s32*)(s5 + 8);
	v0 = sub_00011ED8(...);
	a0 = *(s32*)(sp + 0);
	if ((s32)s4 >= 0)
		goto loc_00016998;
	ra = *(s32*)(sp + 68);
	fp = *(s32*)(sp + 64);
	s7 = *(s32*)(sp + 60);
	s6 = *(s32*)(sp + 56);
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	sp = sp + 80;
	return (v0);
}

sub_00016A58(...) // at 0x00016A58 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = *(s32*)(a0 + 216);
	v0 = scePaf_412B2F09(...);
	v0 = *(s32*)(s0 + 212);
	*(s32*)(s0 + 216) = 0;
	a0 = v0;
	if (v0 != 0)
		goto loc_00016A90;

loc_00016A80:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00016A90:		
	v0 = onesegCore_6C6A13B0(...);
	*(s32*)(s0 + 212) = 0;
	goto loc_00016A80;
}

sub_00016AA0(...) // at 0x00016AA0 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s6;
	a3 = 0;
	s6 = 0;
	*(s32*)(sp + 20) = s5;

loc_00016AB4:		
	s5 = t1;
	*(s32*)(sp + 16) = s4;
	s4 = t0;
	t0 = 4;
	*(s32*)(sp + 12) = s3;
	s3 = t3;
	*(s32*)(sp + 8) = s2;
	s2 = t2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 28) = ra;
	v0 = *(s32*)(a0 + 212);
	s1 = v0 + 8;
	a0 = s1;
	if (v0 == 0)
		goto loc_00016B64;
	v0 = sub_0001210C(...);
	v1 = v0;

loc_00016B00:		
	a1 = 0;
	a3 = 0;
	a2 = s0 + 208;
	a0 = s1;
	if (v0 == 0)
		goto loc_00016B90;

loc_00016B14:		
	if (v1 == 0)
	{
		a0 = *(s32*)(s0 + 1892);
		goto loc_00016B28;
	}
	*(s32*)(s0 + 208) = 0;
	s6 = -1;
	a0 = *(s32*)(s0 + 1892);

loc_00016B28:		
	v1 = *(s32*)(s0 + 208);
	t0 = s6;
	v0 = (s32)a0 < (s32)4;
	*(s32*)(s0 + 204) = v1;
	if (v0 != 0)
		goto loc_00016B44;
	*(s32*)(s0 + 1892) = 0;
	a0 = 0;

loc_00016B44:		
	v0 = a0 << 3;
	v0 = v0 + s0;
	v1 = a0 + 1;
	*(s32*)(v0 + 1856) = s2;
	*(s32*)(v0 + 1860) = s3;
	*(s32*)(s0 + 1892) = v1;
	*(s32*)(v0 + 1824) = s4;
	*(s32*)(v0 + 1828) = s5;

loc_00016B64:		
	ra = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = t0;
	sp = sp + 32;
	return (v0);

loc_00016B90:		
	v0 = sub_0001214C(...);
	v1 = v0;
	goto loc_00016B14;
}

sub_00016BA0(...) // at 0x00016BA0 
{
	sp = sp - 144;
	*(s32*)(sp + 116) = s1;
	s1 = a0;
	*(s32*)(sp + 112) = s0;
	*(s32*)(sp + 136) = ra;
	*(s32*)(sp + 132) = s5;
	*(s32*)(sp + 128) = s4;

loc_00016BBC:		
	*(s32*)(sp + 124) = s3;
	*(s32*)(sp + 120) = s2;
	v1 = *(s32*)(a0 + 208);
	a2 = *(s32*)(a0 + 204);
	v0 = *(s32*)(a0 + 212);
	a0 = 0;
	s0 = v1 - a2;
	if (v0 == 0)
		goto loc_00016DF0;
	if (a2 == 0)
	{
		ra = *(s32*)(sp + 136);
		goto loc_00016DF4;
	}
	v0 = *(s32*)(s1 + 192);
	a1 = s1 + 196;
	if (v0 == 0)
		goto loc_00016DF0;
	v0 = 0;
	if (a1 == 0)
		goto loc_00016BFC;
	v0 = *(s32*)(s1 + 196);

loc_00016BFC:		
	s3 = v0;
	a0 = s1 + 192;
	v0 = sub_00011F18(...);
	a2 = sp;
	if (s3 == 0)
		goto loc_00016E88;
	a0 = *(s32*)(s1 + 212);
	a1 = s0;
	a0 = a0 + 8;
	v0 = sceMpeg_AB0E9556(...);
	a1 = sp + 96;
	if (v0 != 0)
		goto loc_00016E7C;
	a0 = *(s32*)(s1 + 212);
	a0 = a0 + 8;
	v0 = sceMpegAvcDecodeDetail2(...);
	t3 = *(s32*)(sp + 96);
	if (v0 != 0)
		goto loc_00016E7C;
	a0 = 44;
	asm("mult       $s0, $a0");
	v0 = 0x20000;
	a1 = *(s32*)(t3 + 44);
	v1 = v0 - 14652;
	t1 = *(s32*)(v0 - 14652);
	asm("mflo       $a0");
	t5 = a1 + a0;
	v0 = *(s32*)(t5 + 36);
	t2 = *(s32*)(v1 + 24);
	a3 = *(s32*)(v1 + 4);
	t4 = *(u8*)(v0 + 32);
	a0 = *(s32*)(v1 + 8);
	v0 = *(s32*)(v1 + 12);
	a1 = *(s32*)(v1 + 16);
	a2 = *(s32*)(v1 + 20);
	t0 = (u32)t4 < (u32)7;
	*(s32*)(sp + 64) = t1;
	*(s32*)(sp + 68) = a3;
	*(s32*)(sp + 72) = a0;
	*(s32*)(sp + 76) = v0;
	*(s32*)(sp + 80) = a1;
	*(s32*)(sp + 84) = a2;
	*(s32*)(sp + 88) = t2;
	if (t0 == 0)
		goto loc_00016E70;
	v0 = t4 << 2;
	v0 = v0 + sp;
	v1 = *(s32*)(v0 + 64);
	*(s32*)(s3 + 24) = v1;

loc_00016CB0:		
	v1 = 100;
	asm("mult       $s0, $v1");
	a2 = *(s32*)(t3 + 48);
	a1 = *(s32*)(t3 + 16);
	v0 = s0 << 2;
	v0 = v0 + s0;
	asm("mflo       $v1");
	a0 = *(s32*)(s3 + 32);
	s2 = a2 + v1;
	v0 = v0 << 3;
	a1 = a1 + v0;
	a2 = t5;
	a3 = s2;
	v0 = sub_00019420(...);
	v1 = *(s32*)(s1 + 1888);
	v0 = (s32)v1 < (s32)4;
	a0 = v1 << 3;
	if (v0 != 0)
		goto loc_00016D04;
	*(s32*)(s1 + 1888) = 0;
	v1 = 0;
	a0 = v1 << 3;

loc_00016D04:		
	a0 = a0 + s1;
	a2 = *(s32*)(a0 + 1824);
	a3 = *(s32*)(a0 + 1828);
	v0 = v1 + 1;
	*(s32*)(s1 + 1888) = v0;
	*(s32*)(s3 + 8) = a2;
	*(s32*)(s3 + 12) = a3;
	v0 = *(s32*)(a0 + 1856);
	v1 = *(s32*)(a0 + 1860);
	*(s32*)(s3 + 40) = v0;
	*(s32*)(s3 + 44) = v1;
	if (s2 == 0)
	{
		v0 = *(s32*)(s3 + 24);
		goto loc_00016DAC;
	}
	s0 = *(s32*)(s2 + 32);
	a0 = s0;
	v0 = sub_00004A38(...);
	if ((s32)s0 < 0)
	{
		a0 = v0;
		goto loc_00016E50;
	}

loc_00016D4C:		
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16688);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16684);
	a0 = v0;
	a1 = v1;
	v0 = sub_00004414(...);
	s0 = *(s32*)(s2 + 36);
	s4 = v0;
	s5 = v1;
	a0 = s0;
	v0 = sub_00004A38(...);
	a0 = v0;
	if ((s32)s0 < 0)
		goto loc_00016E30;
	a2 = v0;

loc_00016D88:		
	a3 = v1;
	a0 = s4;
	a1 = s5;
	v0 = sub_0000478C(...);
	a0 = v0;
	a1 = v1;
	v0 = sub_00004B48(...);
	asm("swc1       $fpr00, 1820($s1)");
	v0 = *(s32*)(s3 + 24);

loc_00016DAC:		
	v1 = (u32)v0 >> 1;
	if ((s32)v0 < 0)
		goto loc_00016E18;
	asm("mtc1       $v0, $fcr1");
	asm("cvt.s.w    $fpr00, $fpr01");

loc_00016DBC:		
	asm("lwc1       $fpr12, 1820($s1)");
	asm("mul.s      $fpr12, $fpr00, $fpr12");
	v0 = sub_0000340C(...);
	a1 = *(u16*)(sp + 8);
	a2 = *(u16*)(sp + 12);
	a0 = *(s32*)(s1 + 204);
	*(s32*)(s3 + 16) = v0;
	*(s32*)(s3 + 20) = v1;
	a0 = a0 - 1;
	*(s16*)(s3 + 28) = a1;
	*(s16*)(s3 + 30) = a2;
	*(s32*)(s1 + 204) = a0;
	a0 = s3;

loc_00016DF0:		
	ra = *(s32*)(sp + 136);

loc_00016DF4:		
	s5 = *(s32*)(sp + 132);
	s4 = *(s32*)(sp + 128);
	s3 = *(s32*)(sp + 124);
	s2 = *(s32*)(sp + 120);
	s1 = *(s32*)(sp + 116);
	s0 = *(s32*)(sp + 112);
	v0 = a0;
	sp = sp + 144;
	return (v0);

loc_00016E18:		
	v0 = v0 & 0x1;
	v0 = v0 | v1;
	asm("mtc1       $v0, $fcr1");
	asm("cvt.s.w    $fpr00, $fpr01");
	asm("add.s      $fpr00, $fpr00, $fpr00");
	goto loc_00016DBC;

loc_00016E30:		
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16696);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16692);
	a1 = v1;
	v0 = sub_00004338(...);
	a2 = v0;
	goto loc_00016D88;

loc_00016E50:		
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16696);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16692);
	a1 = v1;
	v0 = sub_00004338(...);
	goto loc_00016D4C;

loc_00016E70:		
	v0 = 1;

loc_00016E74:		
	*(s32*)(s3 + 24) = v0;
	goto loc_00016CB0;

loc_00016E7C:		
	a0 = s1;
	a1 = s3;
	v0 = sub_00016E90(...);

loc_00016E88:		
	a0 = 0;
	goto loc_00016DF0;
}

sub_00016E90(...) // at 0x00016E90 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;

loc_00016E98:		
	a0 = a0 + 192;
	a2 = a1;
	v0 = *(s32*)(a0 + 8);
	a1 = v0;
	v0 = sub_00011ED8(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00016EB8(...) // at 0x00016EB8 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	a2 = 0;
	s1 = a1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	a0 = *(s32*)(a0 + 212);
	*(s32*)(sp + 0) = 0;
	if (a0 != 0)
		goto loc_00016F40;

loc_00016EE0:		
	if (s1 == 0)
	{
		*(s32*)(s0 + 204) = 0;
		goto loc_00016EF4;
	}
	v0 = *(s32*)(sp + 0);
	*(s32*)(s1 + 0) = v0;
	*(s32*)(s0 + 204) = 0;

loc_00016EF4:		
	v0 = s0;
	a1 = -1;
	a0 = -1;
	*(s32*)(s0 + 1888) = 0;
	v1 = 3;
	*(s32*)(s0 + 1892) = 0;

loc_00016F0C:		
	v1 = v1 - 1;
	*(s32*)(v0 + 1824) = a0;
	*(s32*)(v0 + 1828) = a1;
	*(s32*)(v0 + 1856) = a0;
	*(s32*)(v0 + 1860) = a1;
	v0 = v0 + 8;
	if ((s32)v1 >= 0)
		goto loc_00016F0C;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a2;
	sp = sp + 32;
	return (v0);

loc_00016F40:		
	a0 = a0 + 8;
	a1 = sp;
	v0 = sub_00012224(...);
	a2 = v0;
	v0 = 770;
	if (a2 != 0)
		a2 = v0;
	goto loc_00016EE0;
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);

loc_00016F80:		
	a0 = v1;
	if (v1 == 0)
		goto loc_00016F94;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 40);
	v0 = $v0(...);

loc_00016F94:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = t0;
	*(s32*)(sp + 16) = s4;
	s4 = a3;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;

loc_00016FD0:		
	*(s32*)(sp + 24) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 36);
	s0 = t1 & 0xFF;
	v0 = $v0(...);
	v1 = *(s32*)(s1 + 4);
	a1 = s3;
	a2 = s2;
	a0 = v1;
	a3 = s4;
	t0 = s5;
	t1 = s0;
	v0 = 0x80000000;
	if (v1 == 0)
		goto loc_00017018;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 44);
	v0 = $v0(...);

loc_00017018:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	s4 = t0;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;
	v1 = *(s32*)(a0 + 0);

loc_0001706C:		
	v0 = *(s32*)(v1 + 36);

loc_00017074:		
	s0 = a0;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 4);
	a1 = s1;
	a2 = s2;
	a0 = v1;
	a3 = s3;
	t0 = s4;
	v0 = 0x80000000;
	if (v1 == 0)
		goto loc_000170A8;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 48);
	v0 = $v0(...);

loc_000170A8:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);
	a0 = v1;
	if (v1 == 0)
		goto loc_000170F0;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 52);
	v0 = $v0(...);

loc_000170F0:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);
	a0 = v1;
	if (v1 == 0)
		goto loc_00017124;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 68);
	v0 = $v0(...);

loc_00017124:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 36);
	s0 = a0;
	v0 = $v0(...);
	v1 = *(s32*)(s0 + 4);
	v0 = 0;

loc_00017154:		
	a0 = v1;
	if (v1 == 0)
		goto loc_0001716C;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 56);
	v0 = $v0(...);

loc_0001716C:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);
	a0 = v1;
	if (v1 == 0)
		goto loc_000171A4;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 40);
	v0 = $v0(...);

loc_000171A4:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);
	a0 = v1;
	if (v1 == 0)
		goto loc_000171D8;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 52);
	v0 = $v0(...);

loc_000171D8:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x80000000;
	v1 = *(s32*)(a0 + 4);
	a0 = v1;
	if (v1 == 0)
		goto loc_0001720C;
	v1 = *(s32*)(v1 + 0);
	v0 = *(s32*)(v1 + 68);
	v0 = $v0(...);

loc_0001720C:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x86010000;
	v0 = v0 | 0x4;
	return (v0);
}

sub_00017224(...) // at 0x00017224 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;

loc_0001722C:		
	*(s32*)(sp + 4) = ra;
	a0 = 152;
	v0 = onesegSal_456203B0(...);

loc_00017238:		
	s0 = v0;
	if (v0 == 0)
		goto loc_000172F0;
	a2 = 152;
	a0 = v0;
	a1 = 0;
	v0 = onesegSal_FDC7AC2A(...);
	v0 = onesegSal_4F5AD890(...);
	*(s32*)(s0 + 0) = v0;
	a1 = 0x20000;
	a1 = a1 - 14624;	// "TunerHALCmdSem"
	a0 = 1;
	v0 = onesegSal_AE582306(...);
	*(s32*)(s0 + 4) = v0;
	v0 = onesegSal_74AF7C06(...);
	*(s32*)(s0 + 8) = v0;
	a0 = 0x20000;
	a0 = a0 - 14608;	// "TunerHALTask"
	a1 = 5;
	a2 = 8192;
	v0 = onesegSal_0886DCE2(...);

loc_0001728C:		
	a0 = *(s32*)(s0 + 0);
	v1 = v0;
	*(s32*)(s0 + 12) = v0;
	if (a0 == 0)
		goto loc_000172C4;
	v0 = *(s32*)(s0 + 4);
	if (v0 == 0)
		goto loc_000172BC;
	if (v1 == 0)
		goto loc_000172BC;
	v0 = *(s32*)(s0 + 8);
	cond = (v0 != 0);
	v0 = 0x5F50000;
	if (cond)
		goto loc_00017344;

loc_000172BC:		
	if (a0 != 0)
		goto loc_00017334;

loc_000172C4:		
	a0 = *(s32*)(s0 + 4);

loc_000172C8:		
	if (a0 != 0)
		goto loc_00017324;
	a0 = *(s32*)(s0 + 8);

loc_000172D4:		
	if (a0 != 0)
		goto loc_00017314;
	a0 = *(s32*)(s0 + 12);

loc_000172E0:		
	if (a0 != 0)
		goto loc_00017304;

loc_000172E8:		
	a0 = s0;
	v0 = onesegSal_BF12FF51(...);

loc_000172F0:		
	v0 = 0;

loc_000172F4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00017304:		
	v0 = onesegSal_78B02C08(...);
	goto loc_000172E8;

loc_00017314:		
	v0 = onesegSal_6086187E(...);
	a0 = *(s32*)(s0 + 12);
	goto loc_000172E0;

loc_00017324:		
	v0 = onesegSal_F2DADC23(...);
	a0 = *(s32*)(s0 + 8);
	goto loc_000172D4;

loc_00017334:		
	v0 = onesegSal_5FC83C98(...);
	a0 = *(s32*)(s0 + 4);
	goto loc_000172C8;

loc_00017344:		
	v0 = v0 | 0xE100;
	v1 = 1;
	*(s32*)(s0 + 32) = v0;
	*(s8*)(s0 + 137) = v1;
	*(s8*)(s0 + 44) = 0;
	*(s32*)(s0 + 40) = 0;
	*(s8*)(s0 + 16) = 0;
	*(s32*)(s0 + 20) = v1;
	*(s32*)(s0 + 96) = 0;
	*(s32*)(s0 + 104) = 0;
	*(s8*)(s0 + 24) = 0;
	*(s8*)(s0 + 25) = 0;
	*(s32*)(s0 + 108) = 0;
	*(s32*)(s0 + 28) = v0;
	*(s32*)(s0 + 36) = 0;
	*(s8*)(s0 + 128) = 0;
	*(s32*)(s0 + 132) = 0;
	*(s8*)(s0 + 136) = 0;
	*(s8*)(s0 + 138) = 0;
	*(s8*)(s0 + 139) = 0;
	*(s8*)(s0 + 140) = 0;
	v0 = sub_00018464(...);
	*(s32*)(s0 + 104) = v0;
	if (v0 != 0)
		goto loc_000173AC;

loc_000173A8:		
	a0 = *(s32*)(s0 + 0);
	goto loc_000172BC;

loc_000173AC:		
	a0 = *(s32*)(s0 + 4);
	v0 = onesegSal_8B2F9A5B(...);
	if (v0 != 0)
	{
		a0 = *(s32*)(s0 + 4);
		goto loc_000173C4;
	}
	v0 = s0;
	goto loc_000172F4;

loc_000173C4:		
	*(s32*)(s0 + 72) = 0;
	v0 = onesegSal_6763AD27(...);
	a0 = *(s32*)(s0 + 12);
	a1 = 0x20000;
	a1 = a1 - 31888;
	a2 = s0;
	v0 = onesegSal_B46CEECD(...);
	v0 = s0;
	goto loc_000172F4;
}

sub_000173E8(...) // at 0x000173E8 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	v0 = 0x80000000;
	s0 = a0;
}

sub_000173F8(...) // at 0x000173F8 
{
	*(s32*)(sp + 20) = ra;
	if (a0 == 0)
		goto loc_00017410;
	a0 = *(s32*)(a0 + 4);
	v0 = onesegSal_8B2F9A5B(...);
	cond = (v0 != 0);
	v0 = 0;
	if (cond)
		goto loc_00017420;

loc_00017410:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00017420:		
	v0 = 1;
	*(s32*)(s0 + 72) = v0;
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSal_3F2ADE66(...);
	a0 = *(s32*)(s0 + 12);
	a1 = sp;
	v0 = onesegSal_E549E5A9(...);
	a0 = *(s32*)(s0 + 12);
	v0 = onesegSal_78B02C08(...);
	a0 = *(s32*)(s0 + 4);
	*(s32*)(s0 + 20) = 0;
	v0 = onesegSal_F2DADC23(...);
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSal_6086187E(...);
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_5FC83C98(...);
	a0 = *(s32*)(s0 + 104);
	v0 = sub_00018C54(...);
	v0 = *(s32*)(s0 + 104);
	a0 = 0;
	a1 = v0;
	if (v0 == 0)
		goto loc_00017480;
	v0 = onesegSal_E64CF915(...);

loc_00017480:		
	*(s32*)(s0 + 104) = 0;
	a0 = s0;
	v0 = onesegSal_BF12FF51(...);
	v0 = 0;
	goto loc_00017410;
}

sub_00017494(...) // at 0x00017494 
{
	t0 = 0x80000000;
	if (a0 == 0)
		goto loc_00017504;

loc_0001749C:		
	a3 = 0;
	a2 = 1;
	a0 = 1;
	if (a1 == 0)
		goto loc_00017504;
	v0 = 0x10000;
	v1 = 13;
	*(s32*)(a1 + 0) = v0;
	v0 = 62;
	t0 = 0;
	*(s32*)(a1 + 8) = v1;
	v1 = 192;
	*(s32*)(a1 + 12) = v0;
	v0 = 4;
	*(s32*)(a1 + 60) = a0;
	*(s32*)(a1 + 24) = v1;
	*(s32*)(a1 + 28) = v0;
	*(s32*)(a1 + 48) = a2;
	*(s32*)(a1 + 52) = a3;
	*(s32*)(a1 + 4) = 0;
	*(s8*)(a1 + 16) = 0;
	*(s8*)(a1 + 17) = 0;
	*(s32*)(a1 + 20) = 0;
	*(s32*)(a1 + 32) = a0;
	*(s32*)(a1 + 40) = a2;
	*(s32*)(a1 + 44) = a3;
	*(s32*)(a1 + 56) = 0;

loc_00017504:		
	v0 = t0;
	return (v0);
}

sub_0001750C(...) // at 0x0001750C 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	v1 = 0x80000000;
	s5 = t0;
	*(s32*)(sp + 16) = s4;
	s4 = a3;
	*(s32*)(sp + 12) = s3;
	s3 = a2;
	*(s32*)(sp + 8) = s2;
	s2 = t1 & 0xFF;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	if (a0 == 0)
		goto loc_000175DC;
	a0 = *(s32*)(a0 + 0);
	v0 = onesegSal_533835A6(...);
	if (v0 == 0)
		goto loc_00017598;
	v0 = s1 & 0x80;
	if (s2 == 0)
		goto loc_00017574;
	v0 = *(u8*)(s0 + 16);
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 104);
		goto loc_00017620;
	}
	v0 = s1 & 0x80;

loc_00017574:		
	if (v0 == 0)
	{
		*(s8*)(s0 + 138) = 0;
		goto loc_00017590;
	}

loc_0001757C:		
	v1 = *(u8*)(s0 + 16);
	v0 = 1;
	*(s8*)(s0 + 138) = v0;
	if (v1 != 0)
	{
		v0 = sub_000184C8(*(s32*)(s0 + 104));
		*(s8*)(s0 + 16) = 0;
		goto loc_0001758C;
	}

loc_0001758C:		
	s1 = s1 & 0x7F;

loc_00017590:		
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_363E72DD(...);

loc_00017598:		
	a0 = *(s32*)(s0 + 4);
	v0 = onesegSal_8B2F9A5B(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_000175DC;
	v0 = 4;
	if (s2 != 0)
		goto loc_000175B4;
	v0 = 2;

loc_000175B4:		
	*(s32*)(s0 + 72) = v0;
	v0 = -1;
	*(s32*)(s0 + 76) = s1;
	if (s3 == v0)
		goto loc_00017604;
	*(s32*)(s0 + 80) = s3;

loc_000175C8:		
	*(s32*)(s0 + 84) = s4;
	*(s32*)(s0 + 88) = s5;

loc_000175D0:		
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSal_3F2ADE66(...);
	v1 = 0;

loc_000175DC:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);

loc_000175E4:		
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00017604:		
	v0 = 22;
	*(s32*)(s0 + 80) = v0;
	goto loc_000175C8;

loc_00017620:		
	a1 = s1;
	v0 = sub_000186CC(...);
	v0 = s1 & 0x80;
	goto loc_00017574;
}

sub_00017630(...) // at 0x00017630 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = 0x80000000;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	if (a0 == 0)
		goto loc_00017670;
	a0 = *(s32*)(a0 + 4);
	v0 = onesegSal_8B2F9A5B(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00017670;
	v0 = 5;
	*(s32*)(s0 + 72) = v0;
	*(s8*)(s0 + 140) = 0;
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSal_3F2ADE66(...);
	v1 = 0;

loc_00017670:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_00017684(...) // at 0x00017684 
{
	v0 = (u32)a0 < (u32)1;
	v1 = (u32)a1 < (u32)1;
	v0 = v0 | v1;
	a2 = 0x80000000;
	if (v0 != 0)
		goto loc_000176B8;
	v0 = *(u8*)(a0 + 139);
	if (v0 == 0)
		goto loc_000176B8;
	v0 = *(s32*)(a0 + 144);
	v1 = *(s32*)(a0 + 148);
	a2 = 0;
	*(s32*)(a1 + 0) = v0;
	*(s32*)(a1 + 4) = v1;

loc_000176B8:		
	v0 = a2;
	return (v0);
}

sub_000176C0(...) // at 0x000176C0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v1 = 0x80000000;
	if (a0 == 0)
		goto loc_000176DC;
	v0 = *(s32*)(a0 + 104);
	a0 = v0;
	if (v0 != 0)
		goto loc_000176EC;

loc_000176DC:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_000176EC:		
	v0 = sub_000186B0(...);
	v1 = 0;
	goto loc_000176DC;
}

sub_000176FC(...) // at 0x000176FC 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	v1 = 0x80000000;
	s4 = t0;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	if (a0 == 0)
		goto loc_00017770;
	a0 = *(s32*)(a0 + 4);
	v0 = onesegSal_8B2F9A5B(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_00017770;
	v0 = 3;
	*(s32*)(s0 + 72) = v0;
	v0 = -1;
	*(s32*)(s0 + 76) = s2;
	if (s1 == v0)
		goto loc_00017794;
	*(s32*)(s0 + 80) = s1;

loc_0001775C:		
	*(s32*)(s0 + 84) = s3;

loc_00017760:		
	*(s32*)(s0 + 88) = s4;
	a0 = *(s32*)(s0 + 8);
	v0 = onesegSal_3F2ADE66(...);
	v1 = 0;

loc_00017770:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00017794:		
	v0 = 22;
	*(s32*)(s0 + 80) = v0;
	goto loc_0001775C;
}

sub_000177A0(...) // at 0x000177A0 
{
	a3 = a0;
	a2 = a1;
	v0 = 0x80000000;
	if (a0 == 0)
		goto loc_0001781C;

loc_000177B0:		
	v0 = *(u8*)(a0 + 16);
	*(s8*)(a1 + 24) = v0;
	if (v0 == 0)
		goto loc_000178B0;
	v0 = *(u8*)(a0 + 24);
	a0 = *(s32*)(a0 + 20);
	*(s8*)(a1 + 0) = v0;

loc_000177C8:		
	v1 = *(u8*)(a3 + 25);
	*(s32*)(a1 + 20) = a0;
	*(s8*)(a1 + 1) = v1;

loc_000177D4:		
	v1 = *(s32*)(a2 + 20);
	v0 = 5;
	if (v1 == v0)
	{
		v1 = *(s32*)(a3 + 28);
		goto loc_00017858;
	}
	v0 = 2;
	cond = (v1 == v0);
	v0 = 0x5F50000;
	if (cond)
		goto loc_00017824;
	v0 = v0 | 0xE100;
	*(s32*)(a2 + 32) = v0;
	*(s32*)(a2 + 28) = v0;
	*(s32*)(a2 + 36) = 0;
	v0 = *(s32*)(a3 + 52);
	*(s32*)(a2 + 16) = 0;
	*(s32*)(a2 + 4) = v0;
	v1 = *(s32*)(a3 + 56);
	*(s32*)(a2 + 12) = 0;
	*(s32*)(a2 + 8) = v1;

loc_00017818:		
	v0 = 0;

loc_0001781C:		

loc_00017820:		
	return (v0);

loc_00017824:		
	v0 = v0 | 0xE100;
	*(s32*)(a2 + 32) = v0;
	*(s32*)(a2 + 28) = v0;
	*(s32*)(a2 + 36) = 0;
	v1 = *(s32*)(a3 + 76);
	a0 = *(s32*)(a3 + 88);
	a1 = *(s32*)(a3 + 84);
	*(s32*)(a2 + 4) = v1;
	v0 = *(s32*)(a3 + 80);
	*(s32*)(a2 + 16) = a0;
	*(s32*)(a2 + 8) = v0;
	*(s32*)(a2 + 12) = a1;
	goto loc_00017818;

loc_00017858:		
	a0 = *(s32*)(a3 + 60);
	a1 = *(s32*)(a3 + 64);
	*(s32*)(a2 + 28) = v1;
	v0 = *(s32*)(a3 + 32);
	*(s32*)(a2 + 12) = a0;
	*(s32*)(a2 + 32) = v0;
	v1 = *(s32*)(a3 + 36);
	*(s32*)(a2 + 16) = a1;
	*(s32*)(a2 + 36) = v1;
	v0 = *(s32*)(a3 + 52);
	*(s32*)(a2 + 4) = v0;
	v1 = *(s32*)(a3 + 56);
	*(s32*)(a2 + 8) = v1;
	v0 = *(s32*)(a3 + 112);
	*(s32*)(a2 + 40) = v0;
	v1 = *(s32*)(a3 + 116);
	*(s32*)(a2 + 44) = v1;
	v0 = *(s32*)(a3 + 120);
	*(s32*)(a2 + 48) = v0;
	v1 = *(s32*)(a3 + 124);
	*(s32*)(a2 + 52) = v1;
	goto loc_00017818;

loc_000178B0:		
	*(s32*)(a1 + 20) = 0;
	*(s8*)(a1 + 0) = 0;
	*(s8*)(a1 + 1) = 0;
	goto loc_000177D4;
}

sub_000178C0(...) // at 0x000178C0 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	v0 = 0x80000000;
	s2 = a0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	if (a0 == 0)
		goto loc_000179A8;
	v0 = 2;
	*(s8*)(a1 + 25) = v0;
	v0 = 1;
	s1 = a1 + 27;
	*(s8*)(a1 + 26) = v0;
	a0 = s1;
	a1 = 0;
	a2 = 22;
	v0 = Kernel_Library_A089ECA4(...);
	v0 = *(u8*)(s2 + 16);
	*(s8*)(s0 + 24) = v0;
	if (v0 == 0)
		goto loc_00017ACC;
	v0 = *(u8*)(s2 + 24);
	a0 = *(s32*)(s2 + 20);
	*(s8*)(s0 + 0) = v0;
	v1 = *(u8*)(s2 + 25);
	*(s32*)(s0 + 20) = a0;
	*(s8*)(s0 + 1) = v1;
	v0 = *(u8*)(s2 + 139);
	*(s8*)(s1 + 19) = v0;
	v1 = *(u8*)(s2 + 140);
	*(s8*)(s1 + 20) = v1;

loc_0001793C:		
	v1 = *(s32*)(s0 + 20);
	a3 = 5;
	v0 = 2;
	if (v1 == a3)
		goto loc_00017A08;
	a0 = -31;
	if (v1 == v0)
		goto loc_000179C0;
	v1 = *(s32*)(s2 + 52);
	a1 = -11;
	*(s32*)(s0 + 4) = v1;
	v0 = *(s32*)(s2 + 56);
	*(s32*)(s0 + 16) = 0;
	*(s32*)(s0 + 8) = v0;
	*(s32*)(s0 + 12) = 0;
	*(s8*)(s1 + 21) = 0;
	*(s8*)(s1 + 5) = a0;
	*(s8*)(s1 + 6) = a1;
	*(s8*)(s1 + 7) = a3;
	*(s8*)(s1 + 0) = 0;
	*(s8*)(s1 + 1) = a0;
	*(s8*)(s1 + 2) = a1;

loc_0001798C:		
	*(s8*)(s1 + 3) = a3;
	*(s8*)(s1 + 4) = 0;
	*(s8*)(s1 + 8) = 0;
	*(s8*)(s1 + 9) = 0;
	*(s8*)(s1 + 10) = 0;
	*(s8*)(s1 + 11) = 0;

loc_000179A4:		
	v0 = 0;

loc_000179A8:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);

loc_000179B0:		
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000179C0:		
	v0 = *(s32*)(s2 + 76);
	v1 = *(s32*)(s2 + 88);
	a0 = *(s32*)(s2 + 84);
	*(s32*)(s0 + 4) = v0;
	a1 = -31;
	a2 = -11;
	v0 = *(s32*)(s2 + 80);
	*(s32*)(s0 + 16) = v1;
	*(s32*)(s0 + 8) = v0;
	*(s32*)(s0 + 12) = a0;
	*(s8*)(s1 + 21) = 0;
	*(s8*)(s1 + 5) = a1;
	*(s8*)(s1 + 6) = a2;
	*(s8*)(s1 + 7) = a3;
	*(s8*)(s1 + 0) = 0;
	*(s8*)(s1 + 1) = a1;
	*(s8*)(s1 + 2) = a2;
	goto loc_0001798C;

loc_00017A08:		
	v1 = *(s32*)(s2 + 52);
	a0 = *(s32*)(s2 + 64);
	a2 = *(s32*)(s2 + 60);
	*(s32*)(s0 + 4) = v1;
	v0 = *(s32*)(s2 + 56);
	*(s32*)(s0 + 16) = a0;
	*(s32*)(s0 + 8) = v0;

loc_00017A24:		
	v1 = *(s32*)(s2 + 28);
	*(s32*)(s0 + 12) = a2;
	a1 = (u32)v1 >> 24;
	NONE;
	NONE;
	*(s8*)(s1 + 2) = a0;
	*(s8*)(s1 + 3) = a1;
	*(s8*)(s1 + 0) = v1;
	*(s8*)(s1 + 1) = v0;
	v0 = *(s32*)(s2 + 32);
	a1 = (u32)v0 >> 24;
	NONE;
	NONE;
	*(s8*)(s1 + 6) = a0;
	*(s8*)(s1 + 7) = a1;
	*(s8*)(s1 + 4) = v0;
	*(s8*)(s1 + 5) = v1;
	v1 = *(s32*)(s2 + 36);
	NONE;
	NONE;
	a1 = (u32)v1 >> 24;
	*(s8*)(s1 + 10) = a0;
	*(s8*)(s1 + 9) = v0;
	*(s8*)(s1 + 11) = a1;
	*(s8*)(s1 + 8) = v1;
	v0 = *(u8*)(s2 + 120);
	*(s8*)(s1 + 12) = v0;
	v1 = *(u8*)(s2 + 121);
	*(s8*)(s1 + 13) = v1;
	v0 = *(u8*)(s2 + 122);
	*(s8*)(s1 + 14) = v0;
	v1 = *(u8*)(s2 + 123);
	*(s8*)(s1 + 15) = v1;
	v0 = *(u8*)(s2 + 124);
	*(s8*)(s1 + 16) = v0;
	v0 = 1;
	v1 = *(u8*)(s2 + 125);
	*(s8*)(s1 + 17) = v1;
	a0 = *(u8*)(s2 + 126);
	*(s8*)(s1 + 21) = v0;

loc_00017AC8:		
	*(s8*)(s1 + 18) = a0;
	goto loc_000179A4;

loc_00017ACC:		
	*(s8*)(s0 + 0) = 0;
	*(s8*)(s0 + 1) = 0;
	v1 = *(u8*)(s2 + 139);
	*(s32*)(s0 + 20) = 0;
	*(s8*)(s1 + 19) = v1;
	v0 = *(u8*)(s2 + 140);
	*(s8*)(s1 + 20) = v0;
	goto loc_0001793C;
}

sub_00017AEC(...) // at 0x00017AEC 
{
	v0 = 0x80000000;
	if (a0 == 0)
		goto loc_00017B0C;
	v0 = *(u8*)(a0 + 16);
	if (v0 == 0)
	{
		*(s32*)(a1 + 0) = 0;
		goto loc_00017B08;
	}
	v0 = *(s32*)(a0 + 20);
	*(s32*)(a1 + 0) = v0;

loc_00017B08:		
	v0 = 0;

loc_00017B0C:		
	return (v0);
}

sub_00017B14(...) // at 0x00017B14 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x80000000;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	if (a0 == 0)
		goto loc_00017B5C;
	a0 = *(s32*)(a0 + 0);
	s1 = 0x80000000;
	v0 = onesegSal_533835A6(...);
	cond = (v0 == 0);
	v0 = s1;
	if (cond)
		goto loc_00017B5C;
	v0 = *(u8*)(s0 + 138);
	s1 = 0;
	if (v0 == 0)
		goto loc_00017B70;

loc_00017B50:		
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_363E72DD(...);
	v0 = s1;

loc_00017B5C:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00017B70:		
	a0 = *(s32*)(s0 + 104);
	v0 = sub_000184C8(...);
	s1 = v0;
	v0 = 1;
	*(s8*)(s0 + 16) = v0;
	goto loc_00017B50;
}

sub_00017B88(...) // at 0x00017B88 
{
	sp = sp - 48;
	*(s32*)(sp + 12) = s3;
	v0 = 0x80000000;
	s3 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s7;
	*(s32*)(sp + 24) = s6;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 4) = s1;
	if (a0 == 0)
		goto loc_00017C7C;
	s7 = 0x80000000;
	v0 = onesegSal_39AF4F3B(...);
	s1 = v0;
	v1 = *(s32*)(s0 + 76);
	v0 = *(s32*)(s0 + 52);
	if (v1 != v0)
		goto loc_00017CD0;
	v1 = *(s32*)(s0 + 20);
	v0 = 2;
	if (v1 == v0)
		goto loc_00017CD0;
	v0 = *(u8*)(s0 + 16);
	s4 = 3;
	if (v0 == 0)
		goto loc_00017C78;
	s5 = 5;
	s6 = 42;

loc_00017C04:		
	v0 = onesegSal_39AF4F3B(...);
	a3 = v0 - s1;
	v1 = v0;
	v0 = (u32)v0 < (u32)a3;
	cond = (v0 != 0);
	v0 = a3 - 1;
	if (cond)
		goto loc_00017CC8;
	v0 = (u32)a3 < (u32)42;

loc_00017C24:		
	cond = (v0 == 0);
	v0 = s7;
	if (cond)
		goto loc_00017C7C;
	v0 = *(s32*)(s0 + 20);
	if (v0 == s4)
		goto loc_00017CB8;
	if (v0 != s5)
		goto loc_00017CA8;
	v0 = (u32)v1 < (u32)a3;

loc_00017C48:		
	a3 = s6 - a3;
	if (v0 == 0)
		goto loc_00017C54;
	v0 = s1 - v1;
	a3 = v0 + 43;

loc_00017C54:		
	a0 = *(s32*)(s0 + 104);
	a1 = s3;
	a2 = s2;
	v0 = sub_000187EC(...);
	if ((s32)v0 > 0)
	{
		s7 = 0;
		goto loc_00017C78;
	}
	v0 = *(u8*)(s0 + 16);

loc_00017C70:		
	if (v0 != 0)
		goto loc_00017C04;

loc_00017C78:		
	v0 = s7;

loc_00017C7C:		
	ra = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_00017CA8:		
	a0 = 1;
	v0 = onesegSal_FB5FE576(...);
	v0 = s7;
	goto loc_00017C7C;

loc_00017CB8:		
	a0 = 10;
	v0 = onesegSal_FB5FE576(...);
	v0 = *(u8*)(s0 + 16);
	goto loc_00017C70;

loc_00017CC8:		
	v0 = (u32)v0 < (u32)42;
	goto loc_00017C24;

loc_00017CD0:		
	a0 = 1;
	v0 = onesegSal_FB5FE576(...);
	v0 = 0x80000000;
	goto loc_00017C7C;
}

sub_00017CE0(...) // at 0x00017CE0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v0 = 0x80000000;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	if (a0 == 0)
		goto loc_00017D28;
	a0 = *(s32*)(a0 + 0);
	s1 = 0x80000000;
	v0 = onesegSal_533835A6(...);
	cond = (v0 == 0);
	v0 = s1;
	if (cond)
		goto loc_00017D28;
	v0 = *(u8*)(s0 + 16);
	s1 = 0;
	if (v0 != 0)
		goto loc_00017D3C;

loc_00017D1C:		
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_363E72DD(...);
	v0 = s1;

loc_00017D28:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00017D3C:		
	*(s8*)(s0 + 16) = 0;
	a0 = *(s32*)(s0 + 104);
	v0 = sub_00018554(...);
	s1 = v0;
	v0 = 0x5F50000;
	v0 = v0 | 0xE100;
	if (s1 != 0)
		goto loc_00017D1C;
	*(s32*)(s0 + 32) = v0;
	*(s8*)(s0 + 24) = 0;
	*(s8*)(s0 + 25) = 0;
	*(s32*)(s0 + 28) = v0;
	*(s32*)(s0 + 36) = 0;
	goto loc_00017D1C;
}

sub_00017D70(...) // at 0x00017D70 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(a0 + 0);
	v0 = onesegSal_533835A6(...);
	ra = *(s32*)(sp + 20);
	if (v0 == 0)
		goto loc_00017DE8;

loc_00017D90:		
	a1 = *(s32*)(s0 + 96);
	if (a1 == 0)
		goto loc_00017DDC;
	v0 = *(s32*)(s0 + 100);
	v1 = *(s32*)(s0 + 108);
	*(s32*)(sp + 0) = v0;
	*(s32*)(sp + 4) = v1;
	if (v1 != 0)
		goto loc_00017DB8;
	v0 = *(s32*)(s0 + 20);
	*(s32*)(sp + 8) = v0;

loc_00017DB8:		
	v1 = *(s32*)(sp + 4);
	v0 = 1;
	if (v1 == v0)
	{
		v0 = *(u8*)(s0 + 25);
		goto loc_00017E00;
	}

loc_00017DC8:		
	v0 = 2;
	if (v1 == v0)
	{
		v0 = *(s32*)(s0 + 32);
		goto loc_00017DF8;
	}

loc_00017DD4:		
	a0 = sp;
	v0 = $a1(...);

loc_00017DDC:		
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_363E72DD(...);
	ra = *(s32*)(sp + 20);

loc_00017DE8:		
	s0 = *(s32*)(sp + 16);
	v0 = 1;
	sp = sp + 32;
	return (v0);

loc_00017DF8:		

loc_00017DFC:		
	*(s32*)(sp + 8) = v0;
	goto loc_00017DD4;

loc_00017E00:		
	v0 = v0 ^ 0x1;
	v0 = (u32)v0 < (u32)1;
	*(s8*)(sp + 8) = v0;
	goto loc_00017DC8;
}

sub_00017E10(...) // at 0x00017E10 
{
	sp = sp - 32;
	*(s32*)(sp + 8) = s2;
	v0 = 0x80000000;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 12) = s3;
	if (a0 == 0)
		goto loc_00017E78;
	a0 = *(s32*)(a0 + 0);
	s3 = 0x80000000;
	v0 = onesegSal_533835A6(...);
	cond = (v0 == 0);
	v0 = s3;
	if (cond)
		goto loc_00017E78;
	v1 = *(s32*)(s0 + 20);
	v0 = 6;
	if (v1 == v0)
		goto loc_00017E6C;
	*(s32*)(s0 + 96) = s1;
	s3 = 0;
	*(s32*)(s0 + 100) = s2;

loc_00017E6C:		
	a0 = *(s32*)(s0 + 0);
	v0 = onesegSal_363E72DD(...);
	v0 = s3;

loc_00017E78:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);

loc_00017E80:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
}

sub_00017E94(...) // at 0x00017E94 
{
	sp = sp - 64;
	*(s32*)(sp + 52) = s5;
	v1 = 0x2FA0000;
	v1 = v1 | 0xF07F;
	*(s32*)(sp + 48) = s4;
	s4 = 0;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 36) = s1;
	s1 = 0;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 56) = ra;
	*(s32*)(sp + 40) = s2;
	v0 = *(s32*)(a0 + 32);
	a1 = *(u8*)(a0 + 25);
	a0 = *(s32*)(a0 + 72);
	v1 = (u32)v1 < (u32)v0;
	v0 = 5;
	s3 = v1 ^ 0x1;
	s2 = *(s32*)(s0 + 20);
	s5 = a1 & 0xFF;
	if (a0 == v0)
		goto loc_00018348;
	v0 = a0 - 2;
	v0 = (u32)v0 < (u32)3;

loc_00017EF4:		

loc_00017EF8:		
	if (v0 == 0)
	{
		v1 = *(s32*)(s0 + 48);
		goto loc_000180F0;
	}
	v0 = 4;
	*(s8*)(s0 + 139) = 0;
	s3 = 1;
	*(s32*)(s0 + 32) = 0;
	if (a0 == v0)
		goto loc_000180D4;
	v0 = *(u8*)(s0 + 128);
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 104);
		goto loc_00017F58;
	}
	v1 = s2 ^ 0x5;
	v0 = s2 ^ 0x2;
	v1 = (u32)v1 < (u32)1;
	v0 = (u32)v0 < (u32)1;
	v1 = v1 | v0;
	if (v1 == 0)
	{
		*(s8*)(s0 + 128) = 0;
		goto loc_00017F4C;
	}
	v1 = *(s32*)(s0 + 80);
	v0 = *(s32*)(s0 + 56);
	if (v1 == v0)
	{
		v0 = *(s32*)(s0 + 76);
		goto loc_000180C4;
	}

loc_00017F48:		
	*(s8*)(s0 + 128) = 0;

loc_00017F4C:		
	s4 = 1;
	if (s1 != 0)
		goto loc_00017F94;

loc_00017F54:		
	a0 = *(s32*)(s0 + 104);

loc_00017F58:		
	a1 = *(s32*)(s0 + 76);
	v0 = sub_00018758(...);
	v1 = 1;
	if (v0 == v1)
	{
		s1 = 1;
		goto loc_00017F74;
	}
	*(s8*)(s0 + 128) = 0;
	s4 = 1;

loc_00017F74:		
	v0 = *(s32*)(s0 + 76);
	v1 = *(s32*)(s0 + 80);
	a0 = *(s32*)(s0 + 84);
	a1 = *(s32*)(s0 + 88);
	*(s32*)(s0 + 52) = v0;

loc_00017F88:		
	*(s32*)(s0 + 56) = v1;
	*(s32*)(s0 + 60) = a0;
	*(s32*)(s0 + 64) = a1;

loc_00017F94:		
	v1 = *(s32*)(s0 + 72);
	v0 = 5;
	*(s32*)(s0 + 48) = v1;
	if (s1 != 0)
		goto loc_00017FB4;
	v0 = 2;
	cond = (v1 == v0);
	v0 = 3;
	if (cond)
		goto loc_00017FB4;
	v0 = 4;

loc_00017FB4:		
	*(s32*)(s0 + 20) = v0;
	v0 = 5;
	v1 = *(s32*)(s0 + 20);
	*(s32*)(s0 + 72) = 0;
	if (v1 == v0)
		goto loc_000180B8;
	v0 = v1 - 3;
	v0 = (u32)v0 < (u32)2;
	if (v0 == 0)
		goto loc_00017FE4;
	v0 = *(u8*)(s0 + 44);
	if (v0 == 0)
		goto loc_000180A0;

loc_00017FE4:		
	a0 = *(s32*)(s0 + 4);
	v0 = onesegSal_6763AD27(...);

loc_00017FEC:		
	v0 = *(u8*)(s0 + 128);

loc_00017FF0:		
	ra = *(s32*)(sp + 56);
	if (v0 != 0)
		goto loc_00018050;
	*(s32*)(s0 + 108) = 0;
	if (s4 == 0)
		goto loc_0001800C;
	s2 = *(s32*)(s0 + 132);
	s5 = *(u8*)(s0 + 136);
	s3 = *(u8*)(s0 + 137);

loc_0001800C:		
	v0 = *(s32*)(s0 + 20);
	if (s2 == v0)
	{
		v0 = *(u8*)(s0 + 25);
		goto loc_00018028;
	}
	*(s32*)(s0 + 108) = 0;
	a0 = s0;
	v0 = sub_00017D70(...);
	v0 = *(u8*)(s0 + 25);

loc_00018028:		
	cond = (s5 == v0);
	v0 = 1;
	if (cond)
		goto loc_0001803C;
	*(s32*)(s0 + 108) = v0;
	a0 = s0;
	v0 = sub_00017D70(...);

loc_0001803C:		
	v1 = *(s32*)(s0 + 20);

loc_00018040:		
	v0 = 5;
	if (v1 == v0)
	{
		v1 = *(s32*)(s0 + 32);
		goto loc_00018074;
	}

loc_0001804C:		
	ra = *(s32*)(sp + 56);

loc_00018050:		
	s5 = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = 0;
	sp = sp + 64;
	return (v0);

loc_00018074:		
	v0 = 0x2FA0000;
	v0 = v0 | 0xF07F;
	v0 = (u32)v0 < (u32)v1;
	v0 = v0 ^ 0x1;
	cond = (s3 == v0);
	v0 = 2;
	if (cond)
		goto loc_0001804C;
	*(s32*)(s0 + 108) = v0;
	a0 = s0;
	v0 = sub_00017D70(...);
	ra = *(s32*)(sp + 56);
	goto loc_00018050;

loc_000180A0:		
	v0 = onesegSal_39AF4F3B(...);
	*(s32*)(s0 + 40) = v0;
	v0 = 1;
	*(s8*)(s0 + 44) = v0;
	goto loc_00017FE4;

loc_000180B8:		
	*(s32*)(s0 + 40) = 0;
	*(s8*)(s0 + 44) = 0;
	goto loc_00017FE4;

loc_000180C4:		
	v1 = *(s32*)(s0 + 52);
	asm("xor        $v0, $v0, $v1");
	s1 = (u32)v0 < (u32)1;
	goto loc_00017F48;

loc_000180D4:		
	v0 = 2;
	*(s8*)(s0 + 136) = a1;
	*(s32*)(s0 + 72) = v0;
	*(s8*)(s0 + 128) = s3;
	*(s32*)(s0 + 132) = s2;

loc_000180E8:		
	*(s8*)(s0 + 137) = s3;
	goto loc_00017F54;

loc_000180F0:		
	v0 = 2;
	if (v1 != v0)
	{
		v0 = *(u8*)(s0 + 128);
		goto loc_00017FF0;
	}
	v0 = *(u8*)(s0 + 16);
	if (v0 == 0)
	{
		v0 = *(u8*)(s0 + 128);
		goto loc_00017FF0;
	}
	*(s8*)(s0 + 139) = 0;
	a2 = sp + 16;
	a1 = sp;
	a0 = *(s32*)(s0 + 104);
	s1 = 1;
	v0 = sub_00018A48(...);
	t4 = 0x70000;
	if (v0 == 0)
		goto loc_00018238;
	v0 = 0x5F50000;
	v0 = v0 | 0xE100;
	s1 = 0;
	*(s32*)(s0 + 32) = v0;
	*(s8*)(s0 + 24) = 0;
	*(s8*)(s0 + 25) = 0;
	*(s32*)(s0 + 28) = v0;
	*(s32*)(s0 + 36) = 0;

loc_00018148:		
	v0 = 1;
	cond = (s1 == v0);
	v0 = (s32)s1 < (s32)2;
	if (cond)
		goto loc_00018220;
	cond = (v0 != 0);
	v0 = 2;
	if (cond)
		goto loc_00018210;
	if (s1 == v0)
	{
		v1 = *(s32*)(s0 + 20);
		goto loc_000181B0;
	}

loc_00018164:		
	v1 = *(s32*)(s0 + 20);

loc_00018168:		
	v1 = v1 ^ 0x4;

loc_0001816C:		
	v0 = s2 ^ 0x3;
	v1 = (u32)v1 < (u32)1;
	v0 = (u32)0 < (u32)v0;

loc_00018178:		
	v1 = v1 & v0;
	if (v1 == 0)
	{
		v0 = *(u8*)(s0 + 128);
		goto loc_00017FF0;
	}
	a0 = *(s32*)(s0 + 104);
	a1 = *(s32*)(s0 + 52);
	v0 = sub_00018758(...);
	v1 = 1;
	if (v0 != v1)
	{
		v0 = *(u8*)(s0 + 128);
		goto loc_00017FF0;
	}
	v0 = 5;
	*(s32*)(s0 + 20) = v0;
	s3 = 1;
	*(s32*)(s0 + 32) = 0;
	goto loc_00017FEC;

loc_000181B0:		
	v0 = 3;
	if (v1 == v0)
		goto loc_000181E4;

loc_000181BC:		
	v0 = 5;
	cond = (v1 != v0);
	v1 = v1 ^ 0x4;
	if (cond)
		goto loc_0001816C;
	v0 = 3;
	*(s32*)(s0 + 20) = v0;
	v0 = onesegSal_39AF4F3B(...);
	*(s32*)(s0 + 40) = v0;
	v0 = 1;
	*(s8*)(s0 + 44) = v0;
	goto loc_00018164;

loc_000181E4:		
	v0 = onesegSal_39AF4F3B(...);
	v1 = *(s32*)(s0 + 40);
	v0 = v0 - v1;
	v0 = (u32)v0 < (u32)1001;

loc_000181FC:		
	if (v0 != 0)
	{
		v1 = *(s32*)(s0 + 20);
		goto loc_000181BC;
	}
	v0 = 4;
	v1 = 4;
	*(s32*)(s0 + 20) = v0;
	goto loc_00018168;

loc_00018210:		
	v1 = *(s32*)(s0 + 20);
	if (s1 == 0)
		goto loc_000181B0;
	v1 = v1 ^ 0x4;
	goto loc_0001816C;

loc_00018220:		
	v0 = 5;
	v1 = 5;
	*(s32*)(s0 + 20) = v0;
	*(s32*)(s0 + 40) = 0;
	*(s8*)(s0 + 44) = 0;
	goto loc_00018168;
}

loc_00018238(...) // at 0x00018238 
{

loc_00018238:		
	asm("lwc1       $fpr00, 0($sp)");
	asm("lwc1       $fpr01, -16740($t4)");
	t3 = 0x70000;
	asm("lwc1       $fpr02, -16736($t3)");
	asm("mul.s      $fpr00, $fpr00, $fpr01");
	a2 = *(u8*)(sp + 19);
	a0 = *(u8*)(sp + 18);
	a3 = *(u8*)(sp + 16);
	asm("c.le.s     $fpr02, $fpr00");
	a1 = *(u8*)(sp + 17);
	t0 = *(u8*)(sp + 20);
	t1 = *(u8*)(sp + 21);
	t2 = *(u8*)(sp + 22);
	v0 = (u32)0 < (u32)a2;
	v1 = (u32)0 < (u32)a0;
	*(s8*)(s0 + 24) = v0;
	*(s8*)(s0 + 25) = v1;
	*(s8*)(s0 + 120) = a3;
	*(s8*)(s0 + 121) = a1;
	*(s8*)(s0 + 122) = a0;
	*(s8*)(s0 + 123) = a2;
	*(s8*)(s0 + 124) = t0;
	*(s8*)(s0 + 125) = t1;
	*(s8*)(s0 + 126) = t2;
	if (asm("bc1t       loc_00018330"))
		goto ;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");

loc_000182A4:		
	asm("lwc1       $fpr01, -16740($t4)");
	asm("lwc1       $fpr00, 4($sp)");
	asm("lwc1       $fpr02, -16736($t3)");
	asm("mul.s      $fpr00, $fpr00, $fpr01");
	asm("c.le.s     $fpr02, $fpr00");
	*(s32*)(s0 + 32) = v1;
	if (asm("bc1t       loc_00018318"))
		goto ;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");

loc_000182CC:		
	v0 = 0x70000;
	asm("lwc1       $fpr00, 8($sp)");
	asm("lwc1       $fpr01, -16732($v0)");
	asm("lwc1       $fpr02, -16736($t3)");
	asm("mul.s      $fpr00, $fpr00, $fpr01");
	asm("c.le.s     $fpr02, $fpr00");
	*(s32*)(s0 + 28) = v1;
	if (asm("bc1t       loc_00018300"))
		goto ;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");

loc_000182F8:		
	*(s32*)(s0 + 36) = v1;
	goto loc_00018148;

loc_00018300:		
	asm("sub.s      $fpr00, $fpr00, $fpr02");
	v0 = 0x80000000;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");
	v1 = v1 | v0;
	goto loc_000182F8;

loc_00018318:		
	asm("sub.s      $fpr00, $fpr00, $fpr02");
	v0 = 0x80000000;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");
	v1 = v1 | v0;
	goto loc_000182CC;

loc_00018330:		
	asm("sub.s      $fpr00, $fpr00, $fpr02");
	v0 = 0x80000000;
	asm("trunc.w.s  $fpr00, $fpr00");
	asm("mfc1       $v1, $fcr0");
	v1 = v1 | v0;
	goto loc_000182A4;

loc_00018348:		
	a0 = *(s32*)(s0 + 104);
	a1 = s0 + 144;
	v0 = sub_000185AC(...);
	cond = ((s32)v0 < 0);
	v0 = 1;
	if (cond)
		goto loc_00018360;
	*(s8*)(s0 + 139) = v0;

loc_00018360:		
	v0 = 1;
	*(s8*)(s0 + 140) = v0;
	*(s32*)(s0 + 72) = 0;
	goto loc_00017FE4;
	sp = sp - 32;
	*(s32*)(sp + 0) = s0;
	v0 = 6;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	v1 = *(s32*)(a0 + 20);
	s0 = a0;
	if (v1 == v0)
		goto loc_00018404;
	s2 = 1;
	s1 = 6;
	s4 = 5;
	s3 = 2;
	a0 = *(s32*)(s0 + 8);

loc_000183B0:		
	a1 = 500;
	v0 = onesegSal_A74C56C6(...);
	if (v0 == 0)
		goto loc_000183F0;
	v0 = *(s32*)(s0 + 72);
	v1 = (s32)v0 < (s32)2;
	a0 = (s32)v0 < (s32)5;
	if (v0 == s2)
		goto loc_00018430;
	if (v1 != 0)
		goto loc_000183E8;
	if (a0 != 0)
	{
		*(s32*)(s0 + 20) = s3;
		goto loc_000183E8;
	}
	if (v0 == s4)
	{
		*(s32*)(s0 + 108) = 0;
		goto loc_00018428;
	}

loc_000183E8:		
	a0 = s0;
	v0 = sub_00017D70(...);

loc_000183F0:		
	a0 = s0;
	v0 = sub_00017E94(...);
	v1 = *(s32*)(s0 + 20);
	if (v1 != s1)
	{
		a0 = *(s32*)(s0 + 8);
		goto loc_000183B0;
	}

loc_00018404:		
	ra = *(s32*)(sp + 20);

loc_00018408:		
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);

loc_00018410:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 32;
	return (v0);

loc_00018428:		
	*(s32*)(s0 + 20) = 0;
	goto loc_000183E8;

loc_00018430:		
	*(s32*)(s0 + 20) = s1;
	a0 = s0;
	*(s32*)(s0 + 72) = 0;
	v0 = sub_00017D70(...);
	ra = *(s32*)(sp + 20);
	goto loc_00018408;
}

sub_00018448(...) // at 0x00018448 
{
	v0 = 0x80000000;
	if (a0 == 0)
		goto loc_0001845C;
	v0 = 192;
	*(s32*)(a0 + 0) = v0;
	v0 = 0;

loc_0001845C:		
	return (v0);
}

sub_00018464(...) // at 0x00018464 
{
	sp = sp - 16;
	a1 = 11680;
	a0 = 0;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	a0 = v0;
	s0 = v0;
	v0 = sub_00018BD8(...);
	a0 = s0;
	if (s0 == 0)
		goto loc_000184A4;
	v0 = sub_00018BFC(...);
	a1 = s0;
	a0 = 0;
	if ((s32)v0 < 0)
		goto loc_000184B8;

loc_000184A4:		
	v0 = s0;

loc_000184A8:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000184B8:		
	s0 = 0;
	v0 = onesegSal_E64CF915(...);
	v0 = s0;
	goto loc_000184A8;
}

sub_000184C8(...) // at 0x000184C8 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;

loc_000184D4:		
	*(s32*)(sp + 20) = ra;
	a0 = *(s32*)(a0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v0 = *(u8*)(s0 + 11665);
	a0 = s0;
	a2 = 0;
	if (v0 != 0)
		goto loc_00018514;
	v0 = sub_00018CFC(a0, *(s32*)(s0 + 0));
	v1 = *(u8*)(s0 + 8);
	v0 = *(s32*)(sp + 0);
	if (v1 == 0)
		goto loc_0001853C;

loc_00018514:		
	v0 = *(s32*)(sp + 0);
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0;

loc_0001852C:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0001853C:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0x80000000;
	goto loc_0001852C;
}

sub_00018554(...) // at 0x00018554 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);

loc_00018574:		
	v0 = $v0(...);
	a0 = s0;
	v0 = sub_00018DC8(...);
	a0 = *(s32*)(sp + 0);
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 32;
	return (v0);
}

sub_000185AC(...) // at 0x000185AC 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = s2;
	v1 = 0x80000000;

loc_000185B8:		
	s2 = a1;
	*(s32*)(sp + 48) = s0;
	s0 = a0;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 52) = s1;
	if (a1 == 0)
		goto loc_0001865C;
	v0 = sub_00018C9C(...);
	v1 = 0x80000000;
	if (v0 == 0)
		goto loc_0001865C;
	a0 = *(s32*)(s0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 8);
	a2 = 0;
	a3 = 0;
	*(s32*)(sp + 32) = a2;
	*(s32*)(sp + 36) = a3;
	a0 = s0;
	if (v1 != 0)
		goto loc_000186A0;

loc_00018614:		
	a0 = sp + 32;
	v0 = sub_00000978(...);
	s1 = v0;
	v0 = *(u8*)(s0 + 8);
	a0 = s0;
	a2 = 0;
	if (v0 != 0)
		goto loc_00018690;

loc_00018630:		
	a0 = *(s32*)(sp + 0);
	if (s1 != 0)
		goto loc_00018678;
	v0 = *(s32*)(sp + 32);
	v1 = *(s32*)(sp + 36);
	a1 = *(s32*)(a0 + 0);
	*(s32*)(s2 + 0) = v0;
	*(s32*)(s2 + 4) = v1;
	v0 = *(s32*)(a1 + 4);
	v0 = $v0(...);
	v1 = 0;

loc_0001865C:		
	ra = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v0 = v1;
	sp = sp + 64;
	return (v0);

loc_00018678:		
	v1 = *(s32*)(a0 + 0);
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v1 = 0x80000000;
	goto loc_0001865C;

loc_00018690:		
	a1 = *(s32*)(s0 + 0);
	v0 = sub_00018CFC(...);
	goto loc_00018630;

loc_000186A0:		
	v0 = sub_00018DC8(...);
	goto loc_00018614;
}

sub_000186B0(...) // at 0x000186B0 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_0000106C(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_000186CC(...) // at 0x000186CC 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	a0 = *(s32*)(a0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 8);
	a1 = *(s32*)(sp + 0);
	if (v1 != 0)
		goto loc_00018738;
	v0 = 1;
	*(s8*)(s0 + 11665) = v0;
	v0 = *(s32*)(a1 + 0);
	*(s32*)(s0 + 0) = s1;
	v1 = *(s32*)(v0 + 4);
	a0 = a1;
	v0 = $v1(...);
	v0 = 0;

loc_00018724:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00018738:		
	v0 = *(s32*)(sp + 0);
	*(s8*)(s0 + 11665) = 0;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0x80000000;
	goto loc_00018724;
}

sub_00018758(...) // at 0x00018758 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a0 = *(s32*)(a0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a1;
	v0 = $v0(...);
	*(s32*)(s0 + 0) = s1;
	a0 = s0;
	v0 = sub_00018DC8(...);
	a0 = s0;
	a1 = s1;

loc_0001879C:		
	a2 = 0;
	v0 = sub_00018CFC(...);
	v1 = *(u8*)(s0 + 8);
	v0 = *(s32*)(sp + 0);
	if (v1 == 0)
		goto loc_000187D4;
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 1;

loc_000187C0:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_000187D4:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 2;
	goto loc_000187C0;
}

sub_000187EC(...) // at 0x000187EC 
{
	sp = sp - 112;
	*(s32*)(sp + 96) = ra;
	*(s32*)(sp + 88) = s6;
	*(s32*)(sp + 84) = s5;
	s5 = a2;
	*(s32*)(sp + 80) = s4;
	s4 = a1;
	*(s32*)(sp + 76) = s3;
	*(s32*)(sp + 72) = s2;
	*(s32*)(sp + 64) = s0;
	s0 = a0;
	*(s32*)(sp + 92) = s7;
	*(s32*)(sp + 68) = s1;
	a0 = *(s32*)(a0 + 4);
	v0 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v1 = *(s32*)(v0 + 0);
	s3 = a3;
	v0 = $v1(...);
	v0 = 1000;
	asm("mult       $s3, $v0");
	s2 = *(s32*)(s5 + 0);
	asm("mflo       $v0");
	*(s32*)(sp + 48) = v0;
	v0 = onesegSal_39AF4F3B(...);
	s6 = v0;
	v0 = *(u8*)(s0 + 8);
	a0 = *(s32*)(sp + 0);
	if (v0 == 0)
		goto loc_00018910;
	s7 = 188;
	if (s2 == 0)
		goto loc_00018910;

loc_00018868:		
	v0 = onesegSal_39AF4F3B(...);
	v1 = v0 - s6;
	a0 = v0;
	v0 = (u32)v0 < (u32)v1;
	cond = (v0 != 0);
	v0 = v1 - 1;
	if (cond)
		goto loc_00018A40;
	v0 = (u32)v1 < (u32)s3;

loc_00018888:		
	cond = (v0 == 0);
	v0 = (u32)a0 < (u32)v1;
	if (cond)
		goto loc_0001890C;
	v1 = s3 - v1;
	if (v0 == 0)
		goto loc_000188A4;
	v0 = s6 - a0;
	v0 = s3 + v0;
	v1 = v0 + 1;

loc_000188A4:		
	v0 = 1000;
	asm("mult       $v1, $v0");
	a1 = *(s32*)(s0 + 12);
	asm("mflo       $v0");
	*(s32*)(sp + 48) = v0;
	if (a1 == 0)
		goto loc_000189F4;

loc_000188BC:		
	v0 = *(u8*)(s0 + 11666);

loc_000188C0:		
	if (v0 != 0)
	{
		*(s8*)(s0 + 11666) = 0;
		goto loc_000188E0;
	}
	v0 = *(s32*)(a1 + 0);
	s1 = 1;
	if (v0 == 0)
		goto loc_000189AC;
	if (v0 == s1)
	{
		v0 = *(s32*)(a1 + 4);
		goto loc_0001897C;
	}
	*(s8*)(s0 + 11664) = s1;

loc_000188E0:		
	s1 = *(s32*)(a1 + 208);
	*(s32*)(a1 + 208) = 0;
	a0 = *(s32*)(s0 + 12);
	v0 = sub_000006D8(...);

loc_000188F0:		
	if (v0 != 0)
		goto loc_0001895C;
	v0 = *(u8*)(s0 + 11664);
	*(s32*)(s0 + 12) = s1;
	if (v0 != 0)
		goto loc_0001890C;
	if (s2 != 0)
		goto loc_00018868;

loc_0001890C:		
	a0 = *(s32*)(sp + 0);

loc_00018910:		
	s0 = *(s32*)(s5 + 0);
	v1 = *(s32*)(a0 + 0);
	s0 = s0 - s2;
	*(s32*)(s5 + 0) = s0;
	v0 = *(s32*)(v1 + 4);
	v0 = $v0(...);
	v0 = s0;
	ra = *(s32*)(sp + 96);
	s7 = *(s32*)(sp + 92);
	s6 = *(s32*)(sp + 88);
	s5 = *(s32*)(sp + 84);
	s4 = *(s32*)(sp + 80);
	s3 = *(s32*)(sp + 76);
	s2 = *(s32*)(sp + 72);
	s1 = *(s32*)(sp + 68);
	s0 = *(s32*)(sp + 64);
	sp = sp + 112;
	return (v0);

loc_0001895C:		
	a0 = s0;
	v0 = sub_00018DC8(...);
	a1 = *(s32*)(s0 + 0);
	a0 = s0;
	a2 = 0;
	v0 = sub_00018CFC(...);
	a0 = *(s32*)(sp + 0);
	goto loc_00018910;

loc_0001897C:		
	a0 = *(s32*)(s4 + 0);
	a1 = a1 + 16;
	*(s32*)(s4 + 4) = v0;
	a2 = 188;
	s2 = s2 - 1;
	v0 = Kernel_Library_1839852A(...);
	a1 = *(s32*)(s0 + 12);
	*(s8*)(s4 + 12) = s1;
	*(s32*)(s4 + 8) = s7;
	s4 = s4 + 16;
	*(s8*)(s0 + 11664) = 0;
	goto loc_000188E0;

loc_000189AC:		
	v0 = *(s32*)(a1 + 4);
	a0 = *(s32*)(s4 + 0);
	a1 = a1 + 16;
	*(s32*)(s4 + 4) = v0;
	a2 = 188;
	v0 = Kernel_Library_1839852A(...);
	v1 = *(u8*)(s0 + 11664);
	*(s32*)(s4 + 8) = s7;
	if (v1 == 0)
		goto loc_000189EC;
	v0 = 1;
	*(s8*)(s4 + 12) = v0;
	*(s8*)(s0 + 11664) = 0;

loc_000189DC:		
	a1 = *(s32*)(s0 + 12);
	s4 = s4 + 16;
	s2 = s2 - 1;
	goto loc_000188E0;

loc_000189EC:		
	*(s8*)(s4 + 12) = 0;
	goto loc_000189DC;

loc_000189F4:		
	a0 = s0 + 12;
	a1 = sp + 48;
	v0 = sub_00000844(...);
	v1 = v0;
	v0 = 0x80020000;
	v0 = v0 | 0x1A8;
	if (v1 == v0)
		goto loc_00018A30;
	if (v1 != 0)
		goto loc_0001895C;
	a1 = *(s32*)(s0 + 12);
	if (a1 != 0)
	{
		v0 = *(u8*)(s0 + 11666);
		goto loc_000188C0;
	}
	goto loc_0001895C;

loc_00018A30:		
	a0 = sp + 16;
	v0 = sub_00000A38(...);
	a0 = *(s32*)(sp + 0);
	goto loc_00018910;

loc_00018A40:		
	v0 = (u32)v0 < (u32)s3;
	goto loc_00018888;
}

sub_00018A48(...) // at 0x00018A48 
{
	sp = sp - 80;
	*(s32*)(sp + 56) = s2;
	s2 = a1;
	*(s32*)(sp + 52) = s1;
	*(s32*)(sp + 48) = s0;
	s0 = a0;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 64) = s5;
	*(s32*)(sp + 60) = s4;
	a0 = *(s32*)(a0 + 4);
	v1 = *(s32*)(a0 + 0);
	*(s32*)(sp + 0) = a0;
	v0 = *(s32*)(v1 + 0);
	s1 = a2;
	v0 = $v0(...);
	v1 = *(u8*)(s0 + 8);
	a0 = sp + 16;
	if (v1 == 0)
		goto loc_00018BBC;
	v0 = sub_00000A38(...);
	cond = (v0 != 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00018BC0;
	v0 = *(s32*)(sp + 36);
	cond = (v0 == 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00018BC0;
	v0 = *(s32*)(sp + 28);
	v1 = *(u8*)(sp + 28);
	asm("lwc1       $fpr01, 24($sp)");
	asm("lwc1       $fpr02, 32($sp)");
	asm("lwc1       $fpr00, 20($sp)");
	NONE;
	NONE;
	NONE;
	NONE;
	NONE;
	v1 = v1 & 0x3;
	NONE;
	asm("swc1       $fpr00, 0($s2)");
	asm("swc1       $fpr01, 4($s2)");
	asm("swc1       $fpr02, 8($s2)");
	*(s8*)(s1 + 6) = a0;
	*(s8*)(s1 + 1) = a1;
	*(s8*)(s1 + 2) = a2;
	*(s8*)(s1 + 3) = a3;
	*(s8*)(s1 + 0) = v1;
	*(s8*)(s1 + 4) = t0;
	*(s8*)(s1 + 5) = v0;
	asm("lwc1       $fpr12, 0($s2)");
	v0 = sub_00003FA4(...);
	s4 = 0x70000;
	s4 = *(s32*)(s4 - 16680);
	s5 = 0x70000;
	s5 = *(s32*)(s5 - 16676);
	a0 = v0;
	a1 = v1;
	a2 = s4;
	a3 = s5;
	s0 = v0;
	s1 = v1;
	v0 = sub_000049B0(...);
	if ((s32)v0 < 0)
		goto loc_00018B98;

loc_00018B40:		
	asm("lwc1       $fpr12, 4($s2)");
	v0 = sub_00003FA4(...);
	a0 = v0;
	a1 = v1;
	a2 = s4;
	a3 = s5;
	v0 = sub_000049B0(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00018B98;

loc_00018B64:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0;

loc_00018B78:		
	ra = *(s32*)(sp + 68);
	s5 = *(s32*)(sp + 64);
	s4 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	sp = sp + 80;
	return (v0);

loc_00018B98:		
	a2 = 0x70000;
	a2 = *(s32*)(a2 - 16672);
	a3 = 0x70000;
	a3 = *(s32*)(a3 - 16668);
	a0 = s0;
	a1 = s1;
	v0 = sub_000049B0(...);
	if ((s32)v0 < 0)
	{
		v0 = *(s32*)(sp + 0);
		goto loc_00018B64;
	}

loc_00018BBC:		
	v0 = *(s32*)(sp + 0);

loc_00018BC0:		
	v1 = *(s32*)(v0 + 0);
	a1 = *(s32*)(v1 + 4);
	a0 = v0;
	v0 = $a1(...);
	v0 = 0x80000000;
	goto loc_00018B78;
}

sub_00018BD8(...) // at 0x00018BD8 
{
	v0 = 23;
	v1 = 1;
	*(s32*)(a0 + 0) = v0;
	*(s8*)(a0 + 11664) = v1;
	*(s8*)(a0 + 11665) = 0;
	*(s32*)(a0 + 4) = 0;
	*(s8*)(a0 + 8) = 0;
	*(s32*)(a0 + 12) = 0;
	return (v0);
}

sub_00018BFC(...) // at 0x00018BFC 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a0;

loc_00018C08:		
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	a0 = a0 + 4;
	v0 = onesegHalToolbox_36A48AF0(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00018C34;
	v0 = sub_00000118(...);
	cond = (v0 == 0);
	v0 = 1;
	if (cond)
		goto loc_00018C4C;
	s0 = 0x80000000;

loc_00018C34:		
	v0 = s0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_00018C44:		
	sp = sp + 16;
	return (v0);

loc_00018C4C:		
	*(s8*)(s1 + 11664) = v0;
	goto loc_00018C34;
}

sub_00018C54(...) // at 0x00018C54 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_000005BC(...);
	v0 = sub_000002C0(...);
	v1 = *(s32*)(s0 + 4);
	a0 = v1;
	if (v1 != 0)
		goto loc_00018C8C;

loc_00018C7C:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00018C8C:		
	v0 = onesegHalToolbox_8C50868C(...);
	*(s32*)(s0 + 4) = 0;
	goto loc_00018C7C;
}

sub_00018C9C(...) // at 0x00018C9C 
{
	s0 = 0;
	v0 = sceUsbGetState();
	v0 = v0 & 0xF;
	if (v0 == PSP_USB_CONNECTION_ESTABLISHED)
	{
		v0 = sceUsbAccGetAuthStat();
		a0 = sp;
		if ((s32)v0 < 0){ return (s0); }
		s0 = 1;
		sceUsb1SegGetModule(sp);
		sceUsb1Seg_6B12C11E(sp + 2);
	}

loc_00018CC0:		
	v0 = s0;

loc_00018CC4:
	return (v0);
}

sub_00018CFC(a0, a1, a2) // at 0x00018CFC 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = a2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	v0 = *(u8*)(a0 + 8);
	s0 = a1;
	if (v0 != 0)
		goto loc_00018D9C;
	v0 = sub_00018C9C(...);
	a1 = s1;
	if (v0 == 0)
		goto loc_00018D9C;
	v0 = sub_00000370(s0, s1, 200, 0);
	s1 = 0;

loc_00018D48:		
	s0 = s2;
	if (v0 != 0)
		goto loc_00018DB8;

loc_00018D50:		
	v0 = s0 + 240;
	*(s32*)(s0 + 224) = v0;
	a0 = s0 + 32;
	a1 = 0;
	a2 = 192;
	s1 = s1 + 1;
	v0 = Kernel_Library_A089ECA4(...);
	v1 = (u32)s1 < (u32)52;
	s0 = s0 + 224;
	if (v1 != 0)
		goto loc_00018D50;
	*(s32*)(s2 + 11648) = 0;
	a0 = s2 + 16;
	v0 = sub_000006D8(...);
	cond = (v0 != 0);
	v0 = 1;
	if (cond)
		goto loc_00018DB8;
	*(s8*)(s2 + 11666) = v0;
	*(s32*)(s2 + 12) = 0;
	*(s8*)(s2 + 8) = v0;
	*(s8*)(s2 + 11664) = v0;

loc_00018D9C:		
	ra = *(s32*)(sp + 12);

loc_00018DA0:		
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0x80000000;
	sp = sp + 16;
	return (v0);

loc_00018DB8:		

loc_00018DBC:		
	v0 = sub_000005BC(...);
	ra = *(s32*)(sp + 12);
	goto loc_00018DA0;
}

sub_00018DC8(...) // at 0x00018DC8 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	v0 = *(u8*)(a0 + 8);
	s0 = a0;
	if (v0 != 0)
		goto loc_00018DF4;

loc_00018DE0:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_00018DF4:		
	v0 = sub_000005BC(...);
	*(s8*)(s0 + 8) = 0;
	goto loc_00018DE0;
}

sub_00018E04(...) // at 0x00018E04 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sceVaudioChRelease(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00018E20(...) // at 0x00018E20 
{
	v0 = 1;
	*(s8*)(a0 + 28) = v0;
	v0 = 0;
	v1 = 0;
	*(s32*)(a0 + 0) = v0;
	*(s32*)(a0 + 4) = v1;
	v0 = 3;
	*(s32*)(a0 + 32) = v0;
	*(s32*)(a0 + 44) = 0;
	*(s32*)(a0 + 36) = 0;
	*(s32*)(a0 + 40) = 0;
	return (v0);
}

sub_00018E50(...) // at 0x00018E50 
{
	*(s32*)(a0 + 16) = a2;
	sp = sp - 16;
	*(s32*)(a0 + 20) = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sceVaudioChRelease(...);
	a2 = 2;
	a1 = *(s32*)(s0 + 20);
	a0 = *(s32*)(s0 + 16);
	v0 = sceVaudioChReserve(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00018E8C(...) // at 0x00018E8C 
{
	t2 = a0;
	a1 = *(s32*)(a0 + 4);
	a0 = *(s32*)(a0 + 0);
	t0 = (u32)a0 >> 25;
	v1 = a1 << 7;
	v0 = a0 << 7;
	v1 = v1 | t0;
	t1 = (u32)v0 < (u32)a0;
	v1 = v1 - a1;
	v0 = v0 - a0;
	v0 = v0 + a2;
	v1 = v1 - t1;
	t0 = (u32)v0 < (u32)a2;
	v1 = v1 + a3;
	v1 = v1 + t0;
	a1 = (s32)v1 >> 31;
	a0 = (u32)a1 >> 25;
	v0 = v0 + a0;
	a1 = 0;
	a2 = (u32)v0 < (u32)a0;
	v1 = v1 + a1;
	v1 = v1 + a2;
	a3 = v1 << 25;
	v0 = (u32)v0 >> 7;
	v0 = v0 | a3;
	v1 = (s32)v1 >> 7;
	*(s32*)(t2 + 0) = v0;
	*(s32*)(t2 + 4) = v1;
	v0 = 3;
	a0 = *(s32*)(t2 + 4);
	v1 = (s32)a0 < (s32)-1;

loc_00018F08:		
	*(s32*)(t2 + 32) = v0;
	if (v1 != 0)
		goto loc_00018FC4;
	v0 = -1;
	if (a0 == v0)
	{
		v1 = *(s32*)(t2 + 0);
		goto loc_00018F84;
	}

loc_00018F1C:		
	if ((s32)a0 <= 0)
		goto loc_00018F64;
	v1 = *(s32*)(t2 + 0);
	v0 = v1 - 910;
	asm("mult       $v0, $v0");

loc_00018F30:		
	v1 = 0x52D90000;
	v1 = v1 | 0xB70D;
	a0 = *(s32*)(t2 + 32);
	asm("mflo       $v0");
	asm("mult       $v0, $v1");
	v0 = (s32)v0 >> 31;
	asm("mfhi       $v1");
	v1 = (s32)v1 >> 19;
	v1 = v1 - v0;
	a0 = a0 + v1;
	*(s32*)(t2 + 32) = a0;

loc_00018F5C:		
	return (v0);

loc_00018F64:		
	if (a0 != 0)
		goto loc_00018F5C;
	v1 = *(s32*)(t2 + 0);
	v0 = (u32)v1 < (u32)911;
	cond = (v0 != 0);
	v0 = v1 - 910;
	if (cond)
		goto loc_00018F5C;
	asm("mult       $v0, $v0");
	goto loc_00018F30;

loc_00018F84:		
	v0 = (u32)v1 < (u32)-900;
	if (v0 == 0)
		goto loc_00018F1C;

loc_00018F90:		
	v1 = v1 + 900;

loc_00018F94:		
	asm("mult       $v1, $v1");
	v0 = 0x52D90000;
	v0 = v0 | 0xB70D;
	asm("mflo       $v1");
	asm("mult       $v1, $v0");
	v1 = (s32)v1 >> 31;
	asm("mfhi       $v0");
	v0 = (s32)v0 >> 19;
	v0 = v0 - v1;
	v0 = v0 + 3;
	*(s32*)(t2 + 32) = v0;
	return (v0);

loc_00018FC4:		
	v1 = *(s32*)(t2 + 0);
	goto loc_00018F90;
}

sub_00018FCC(...) // at 0x00018FCC 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = fp;
	fp = t0;
	*(s32*)(sp + 28) = s7;
	s7 = a3;
	*(s32*)(sp + 24) = s6;
	s6 = a2;
	*(s32*)(sp + 0) = s0;

loc_00018FEC:		
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	v0 = *(u8*)(a0 + 28);
	s0 = a0;
	if (v0 == 0)
		goto loc_0001901C;
	*(s32*)(a0 + 8) = s6;
	*(s32*)(a0 + 12) = s7;
	*(s8*)(a0 + 28) = 0;

loc_0001901C:		
	v0 = *(s32*)(s0 + 40);
	t0 = *(s32*)(s0 + 16);
	s5 = 0;
	v0 = v0 << 13;
	v0 = s0 + v0;
	s1 = v0 + 48;
	s2 = 0;
	s3 = 0;
	a0 = t0;
	if ((s32)t0 <= 0)
		goto loc_000190A4;
	s4 = 0x10000;
	s4 = s4 | 0x5F90;

loc_0001904C:		
	a1 = *(s32*)(s0 + 44);
	v0 = (s32)a1 < (s32)a0;
	v1 = a1;
	if (v0 == 0)
		goto loc_0001908C;
	v0 = s2 << 2;
	if (s5 == 0)
		goto loc_000191B0;
	a0 = *(s32*)(s0 + 36);
	v0 = a1 + 1;
	if ((s32)a0 <= 0)
		goto loc_000191A8;
	v1 = a1 << 2;
	v1 = v1 + s1;
	a0 = a0 - 1;
	a1 = v0;
	*(s32*)(v1 + 0) = 0;
	*(s32*)(s0 + 36) = a0;
	*(s32*)(s0 + 44) = v0;

loc_0001908C:		
	v0 = (s32)a1 < (s32)t0;
	if (v0 == 0)
	{
		a0 = *(s32*)(s0 + 24);
		goto loc_000190D4;
	}

loc_00019098:		
	v0 = (s32)s2 < (s32)t0;
	a0 = t0;
	if (v0 != 0)
		goto loc_0001904C;

loc_000190A4:		
	ra = *(s32*)(sp + 36);
	fp = *(s32*)(sp + 32);
	s7 = *(s32*)(sp + 28);
	s6 = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 48;
	return (v0);

loc_000190D4:		
	a1 = s1;
	s3 = s3 + 1;
	v0 = sceVaudioOutputBlocking(...);
	v1 = 1;
	t0 = *(s32*)(s0 + 16);
	if (s3 == v1)
		goto loc_0001915C;
	a2 = *(s32*)(s0 + 20);
	asm("mult       $t0, $s4");
	if (a2 == 0)
	{
		asm("break      0x7");
		goto loc_000190FC;
	}

loc_000190FC:		
	a0 = *(s32*)(s0 + 8);
	a1 = *(s32*)(s0 + 12);
	asm("mflo       $v0");
	asm("div        $v0, $a2");
	asm("mflo       $v0");
	a0 = a0 + v0;
	v1 = (s32)v0 >> 31;
	a2 = (u32)a0 < (u32)v0;
	a1 = a1 + v1;
	a1 = a1 + a2;
	*(s32*)(s0 + 8) = a0;
	*(s32*)(s0 + 12) = a1;
	v0 = *(s32*)(s0 + 40);

loc_00019130:		
	*(s32*)(s0 + 44) = 0;
	v0 = v0 + 1;
	v1 = (s32)v0 < (s32)2;
	*(s32*)(s0 + 40) = v0;
	if (v1 != 0)
		goto loc_00019148;
	*(s32*)(s0 + 40) = 0;

loc_00019148:		
	v0 = *(s32*)(s0 + 40);
	v0 = v0 << 13;
	v0 = s0 + v0;
	s1 = v0 + 48;
	goto loc_00019098;

loc_0001915C:		
	a0 = *(s32*)(s0 + 20);
	v0 = s2 - t0;
	asm("mult       $v0, $s4");
	if (a0 == 0)
	{
		asm("break      0x7");
		goto loc_00019170;
	}

loc_00019170:		
	asm("mflo       $v0");
	asm("div        $v0, $a0");
	asm("mflo       $v0");
	v1 = (s32)v0 >> 31;
	a2 = s6 + v0;
	a0 = (u32)a2 < (u32)v0;
	a3 = s7 + v1;
	a3 = a3 + a0;
	v0 = a2;
	v1 = a3;
	*(s32*)(s0 + 8) = v0;
	*(s32*)(s0 + 12) = v1;
	v0 = *(s32*)(s0 + 40);
	goto loc_00019130;

loc_000191A8:		
	s5 = 0;
	goto loc_0001908C;

loc_000191B0:		
	v0 = v0 + fp;
	t2 = *(s32*)(v0 + 0);
	a3 = *(s32*)(s0 + 32);
	a2 = (s16)t2;

loc_000191C0:		
	asm("negu       $t1, $a3");
	v0 = (s32)a2 < (s32)t1;
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 36);
		goto loc_00019224;
	}
	v0 = (s32)a3 < (s32)a2;
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 36);
		goto loc_00019224;
	}
	a2 = (s32)t2 >> 16;
	v0 = (s32)a2 < (s32)t1;
	if (v0 != 0)
	{
		v0 = *(s32*)(s0 + 36);
		goto loc_00019224;
	}
	v0 = (s32)a3 < (s32)a2;
	cond = (v0 != 0);
	v0 = *(s32*)(s0 + 36);
	if (cond)
		goto loc_00019224;
	s2 = s2 + 1;
	v0 = v0 + 1;
	v1 = (s32)v0 < (s32)a0;

loc_00019204:		
	*(s32*)(s0 + 36) = v0;
	if (v1 != 0)
		goto loc_0001908C;

loc_0001920C:		
	a0 = s0;
	v0 = sub_00019248(...);
	t0 = *(s32*)(s0 + 16);
	a1 = *(s32*)(s0 + 44);
	s5 = 1;
	goto loc_0001908C;

loc_00019224:		
	cond = ((s32)v0 > 0);
	v0 = v1 << 2;
	if (cond)
		goto loc_0001920C;
	v0 = v0 + s1;
	v1 = v1 + 1;
	*(s32*)(v0 + 0) = t2;

loc_00019238:		
	a1 = v1;
	s2 = s2 + 1;
	*(s32*)(s0 + 44) = v1;
	goto loc_0001908C;
}

sub_00019248(...) // at 0x00019248 
{
	sp = sp - 48;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	s4 = *(s32*)(a0 + 36);
	v0 = (s32)s4 < (s32)2;

loc_0001926C:		
	s0 = a0;
	if (v0 != 0)
		goto loc_00019378;

loc_00019274:		
	s2 = *(s32*)(a0 + 0);
	s3 = *(s32*)(a0 + 4);
	a0 = s2 + 900;
	v0 = (u32)a0 < (u32)900;
	a1 = s3 + v0;
	if (a1 != 0)
	{
		v0 = *(s32*)(s0 + 4);
		goto loc_000192A8;
	}
	ra = *(s32*)(sp + 36);
	if (a1 != 0)
		goto loc_0001937C;
	v0 = (u32)a0 < (u32)1801;
	if (v0 != 0)
	{
		s4 = *(s32*)(sp + 32);
		goto loc_00019380;
	}
	v0 = *(s32*)(s0 + 4);

loc_000192A8:		
	if ((s32)v0 <= 0)
		goto loc_00019398;
	s1 = *(s32*)(s0 + 20);

loc_000192B4:		
	t2 = s2 - 900;
	v0 = (u32)t2 < (u32)-900;
	t3 = s3 - 1;
	t3 = t3 + v0;
	a3 = 0;
	a2 = 0x10000;
	a2 = a2 | 0x5F90;
	v1 = (s32)s1 >> 31;
	asm("mult       $t2, $v1");
	asm("mflo       $t0");
	asm("multu      $t2, $s1");
	asm("mfhi       $a1");
	asm("mflo       $a0");
	asm("mult       $s1, $t3");
	t0 = t0 + a1;
	asm("mflo       $v0");
	a1 = t0 + v0;
	v0 = sub_0000345C(...);
	a0 = *(s32*)(s0 + 16);
	*(s32*)(sp + 0) = v0;
	a2 = sp + 4;

loc_00019308:		
	a1 = (u32)a0 >> 31;
	a0 = a0 + a1;
	a0 = (s32)a0 >> 1;
	*(s32*)(sp + 4) = a0;
	a0 = (s32)a0 < (s32)v0;
	if (a0 == 0)
		a2 = sp;
	v0 = *(s32*)(a2 + 0);
	v1 = s4 + v0;

loc_00019328:		
	a0 = 0x10000;
	if (s4 == v1)
		goto loc_00019378;
	v0 = s4 - v1;
	a0 = a0 | 0x5F90;
	asm("mult       $v0, $a0");
	if (s1 == 0)
	{
		asm("break      0x7");
		goto loc_00019344;
	}

loc_00019344:		
	*(s32*)(s0 + 36) = v1;
	asm("mflo       $v0");
	asm("div        $v0, $s1");
	asm("mflo       $v0");
	v1 = (s32)v0 >> 31;
	a2 = s2 + v0;
	a0 = (u32)a2 < (u32)v0;
	a3 = s3 + v1;
	a3 = a3 + a0;
	v0 = a2;
	v1 = a3;
	*(s32*)(s0 + 0) = v0;
	*(s32*)(s0 + 4) = v1;

loc_00019378:		
	ra = *(s32*)(sp + 36);

loc_0001937C:		
	s4 = *(s32*)(sp + 32);

loc_00019380:		
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00019398:		
	s1 = *(s32*)(s0 + 20);
	if (v0 != 0)
		goto loc_000193B0;
	v0 = *(s32*)(s0 + 0);
	v0 = (u32)v0 < (u32)901;
	if (v0 == 0)
		goto loc_000192B4;

loc_000193B0:		
	t2 = s2 + 900;
	v0 = (u32)t2 < (u32)900;

loc_000193B8:		
	v1 = (s32)s1 >> 31;
	asm("mult       $t2, $v1");
	t3 = s3 + v0;
	a3 = 0;
	a2 = 0x10000;
	a2 = a2 | 0x5F90;
	asm("mflo       $t0");
	asm("multu      $t2, $s1");
	asm("mfhi       $a1");
	asm("mflo       $a0");
	asm("mult       $s1, $t3");
	t0 = t0 + a1;
	asm("mflo       $v0");
	a1 = t0 + v0;
	v0 = sub_0000345C(...);
	a0 = 0x70000;
	a1 = *(s32*)(a0 - 16616);
	a2 = s4 + v0;
	*(s32*)(sp + 0) = v0;
	a1 = (s32)a2 < (s32)a1;
	a0 = a0 - 16616;
	*(s32*)(sp + 8) = a2;
	v0 = sp + 8;
	if (a1 == 0)
		a0 = v0;
	v1 = *(s32*)(a0 + 0);
	goto loc_00019328;
}

sub_00019420(...) // at 0x00019420 
{
	sp = sp - 144;
	*(s32*)(sp + 124) = s7;
	s7 = a3;
	*(s32*)(sp + 120) = s6;
	s6 = a0;
	*(s32*)(sp + 100) = s1;
	s1 = a1;
	*(s32*)(sp + 96) = s0;
	s0 = a2;
	*(s32*)(sp + 128) = ra;
	*(s32*)(sp + 116) = s5;
	*(s32*)(sp + 112) = s4;
	*(s32*)(sp + 108) = s3;
	*(s32*)(sp + 104) = s2;
	v0 = *(s32*)(a1 + 8);
	t0 = *(s32*)(a2 + 36);
	a2 = 164;
	*(s32*)(a0 + 0) = v0;
	a0 = a0 + 56;
	v0 = *(s32*)(a1 + 12);
	a1 = t0;
	*(s32*)(s6 + 4) = v0;
	v0 = *(s32*)(s1 + 16);
	*(s32*)(s6 + 8) = v0;
	v1 = *(s32*)(s1 + 20);

loc_00019484:		
	*(s32*)(s6 + 12) = v1;
	v0 = *(s32*)(s1 + 24);
	*(s32*)(s6 + 16) = v0;
	v1 = *(s32*)(s1 + 28);
	*(s32*)(s6 + 20) = v1;
	if (t0 != 0)
		goto loc_000195D8;
	*(s8*)(s6 + 56) = 0;
	v0 = *(s32*)(s0 + 40);

loc_000194A4:		
	a0 = s6 + 220;
	a2 = 164;
	a1 = v0;
	if (v0 != 0)
		goto loc_000195C8;
	*(s8*)(s6 + 220) = 0;
	s4 = *(s32*)(s0 + 0);

loc_000194BC:		
	s3 = *(s32*)(s0 + 8);
	a0 = *(s32*)(s1 + 12);
	s5 = *(s32*)(s0 + 28);
	a3 = *(s32*)(s0 + 4);
	t0 = *(s32*)(s0 + 16);
	t1 = *(s32*)(s0 + 20);
	t2 = *(s32*)(s0 + 12);
	t3 = *(s32*)(s0 + 24);
	v1 = *(s32*)(s1 + 8);
	t4 = *(s32*)(s6 + 24);

loc_000194E4:		
	t5 = *(s32*)(s6 + 28);
	t6 = *(s32*)(s6 + 40);
	t7 = *(s32*)(s6 + 44);
	s0 = *(s32*)(s6 + 32);
	s1 = *(s32*)(s6 + 36);
	s2 = *(s32*)(s6 + 48);
	a2 = (u32)0 < (u32)s4;
	v0 = a2 | 0x2;
	*(s32*)(sp + 0) = a0;
	if (s3 != 0)
		a2 = v0;
	a1 = sp;
	*(s32*)(sp + 4) = v1;
	a0 = sp + 48;
	*(s32*)(sp + 20) = a3;
	*(s32*)(sp + 32) = t0;
	*(s32*)(sp + 36) = t1;
	*(s32*)(sp + 28) = t2;
	*(s32*)(sp + 40) = t3;
	*(s32*)(sp + 44) = s5;
	*(s32*)(sp + 64) = t4;
	*(s32*)(sp + 68) = t5;
	*(s32*)(sp + 80) = t6;
	*(s32*)(sp + 84) = t7;
	*(s32*)(sp + 72) = s0;
	*(s32*)(sp + 76) = s1;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 24) = s3;
	*(s32*)(sp + 88) = s2;
	v0 = *(s32*)(s6 + 52);
	*(s32*)(sp + 92) = v0;
	v0 = sceMpegBaseYCrCbCopy(...);
	v0 = 1;
	if (s7 == 0)
		goto loc_000195C0;
	*(s8*)(s6 + 384) = v0;
	v1 = *(u8*)(s7 + 0);
	*(s8*)(s6 + 385) = v1;
	v0 = *(u8*)(s7 + 1);
	*(s8*)(s6 + 386) = v0;
	v1 = *(s32*)(s7 + 4);
	*(s32*)(s6 + 388) = v1;
	v0 = *(s32*)(s7 + 8);
	*(s32*)(s6 + 392) = v0;
	v1 = *(u8*)(s7 + 16);
	*(s8*)(s6 + 396) = v1;

loc_00019594:		
	ra = *(s32*)(sp + 128);
	s7 = *(s32*)(sp + 124);
	s6 = *(s32*)(sp + 120);
	s5 = *(s32*)(sp + 116);
	s4 = *(s32*)(sp + 112);
	s3 = *(s32*)(sp + 108);
	s2 = *(s32*)(sp + 104);
	s1 = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	sp = sp + 144;
	return (v0);

loc_000195C0:		
	*(s8*)(s6 + 384) = 0;
	goto loc_00019594;

loc_000195C8:		
	v0 = Kernel_Library_1839852A(...);
	s4 = *(s32*)(s0 + 0);
	goto loc_000194BC;

loc_000195D8:		
	v0 = Kernel_Library_1839852A(...);
	v0 = *(s32*)(s0 + 40);
	goto loc_000194A4;
}

sub_000195E8(...) // at 0x000195E8 
{
	sp = sp - 64;
	t1 = (u32)a0 < (u32)1;
	v1 = (u32)a3 < (u32)1;
	*(s32*)(sp + 32) = s4;
	t0 = 0x80000000;
	s4 = a0;
	a0 = t1 | v1;
	*(s32*)(sp + 52) = ra;
	v0 = t0 | 0x103;
	*(s32*)(sp + 48) = fp;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	if (a0 != 0)
		goto loc_00019660;
	v0 = a1 ^ 0x80;
	t4 = a1 ^ 0xC0;
	t2 = (u32)0 < (u32)v0;
	t3 = (u32)0 < (u32)t4;

loc_00019640:		
	a0 = t2 & t3;
	s2 = a2 ^ 0x80;
	if (a0 == 0)
		goto loc_00019690;
	t5 = 256;
	s1 = a2 ^ 0xC0;
	if (a1 == t5)
		goto loc_00019694;
	a1 = 0x80000000;

loc_0001965C:		
	v0 = a1 | 0x1FE;

loc_00019660:		
	ra = *(s32*)(sp + 52);
	fp = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 64;
	return (v0);

loc_00019690:		
	s1 = a2 ^ 0xC0;

loc_00019694:		
	t7 = (u32)0 < (u32)s2;
	s0 = (u32)0 < (u32)s1;
	t6 = t7 & s0;
	fp = (s32)a2 >> 31;
	if (t6 == 0)
		goto loc_000196B8;
	s3 = 256;
	if (a2 != s3)
	{
		a1 = 0x80000000;
		goto loc_0001965C;
	}
	fp = (s32)a2 >> 31;

loc_000196B8:		
	t0 = (s32)a1 >> 31;
	t8 = (u32)fp >> 27;
	t9 = (u32)t0 >> 27;
	s6 = a2 + t8;
	s7 = a1 + t9;
	fp = (s32)s7 >> 5;
	s1 = (s32)s6 >> 5;
	s5 = (s32)fp < (s32)s1;
	t1 = fp + 6;
	a2 = s1 + 6;
	if (s5 != 0)
		t1 = a2;
	*(s32*)(s4 + 964) = fp;
	s3 = 0;
	*(s32*)(s4 + 960) = s1;
	*(s32*)(s4 + 968) = t1;
	if ((s32)s1 <= 0)
		goto loc_00019740;
	t0 = s4;
	s2 = s1;

loc_00019700:		
	v0 = a3 + s3;
	a1 = *(u8*)(v0 + 3);
	s0 = *(u8*)(v0 + 2);
	t5 = *(u8*)(v0 + 1);
	t2 = *(u8*)(v0 + 0);
	t6 = a1 << 24;
	t7 = s0 << 16;
	t3 = t6 | t7;
	t4 = t5 << 8;
	a0 = t3 | t4;
	v1 = a0 | t2;
	s2 = s2 - 1;
	*(s32*)(t0 + 0) = v1;
	s3 = s3 + 4;
	t0 = t0 + 4;
	if (s2 != 0)
		goto loc_00019700;

loc_00019740:		
	s2 = t1 + 1;
	asm("mult       $fp, $s2");
	a3 = (s32)s1 < (s32)7;
	asm("mflo       $s6");
	if (a3 == 0)
	{
		s5 = (s32)s1 < (s32)s6;
		goto loc_00019904;
	}
	t1 = (s32)s1 < (s32)s6;
	s3 = s1;
	s7 = 0;
	if (t1 == 0)
		goto loc_0001981C;
	a2 = s1 << 2;
	*(s32*)(sp + 12) = a2;
	s5 = s4;

loc_00019774:		
	t6 = s3 << 2;
	s0 = t6 + s4;
	t5 = *(s32*)(s0 - 4);
	s2 = 1;

loc_00019784:		
	asm("rotr       $a0, $t5, 8");
	v0 = sub_00001A8C(...);
	t4 = 0x70000;
	a0 = t4 - 16612;
	t3 = *(s32*)(s5 + 0);
	v1 = s7 + a0;
	t2 = *(u8*)(v1 + 0);
	asm("xor        $t0, $t3, $v0");
	t8 = (s32)s2 < (s32)s1;
	asm("xor        $t9, $t0, $t2");
	*(s32*)(s0 + 0) = t9;
	if (t8 == 0)
		goto loc_00019804;
	a0 = s3 + 1;
	t7 = (s32)a0 < (s32)s6;
	a2 = a0;
	if (t7 == 0)
		goto loc_00019804;
	t2 = a2 - s1;

loc_000197C8:		
	a3 = t2 << 2;
	t0 = a2 << 2;
	t1 = t0 + s4;
	a1 = a3 + s4;
	t8 = *(s32*)(a1 + 0);
	t9 = *(s32*)(t1 - 4);
	s2 = s2 + 1;
	a2 = s2 + s3;
	asm("xor        $v0, $t8, $t9");
	s0 = (s32)s2 < (s32)s1;
	a3 = (s32)a2 < (s32)s6;
	*(s32*)(t1 + 0) = v0;
	if (s0 == 0)
		goto loc_00019804;
	if (a3 != 0)
	{
		t2 = a2 - s1;
		goto loc_000197C8;
	}

loc_00019804:		
	a2 = *(s32*)(sp + 12);
	s3 = s3 + s1;
	s2 = (s32)s3 < (s32)s6;

loc_00019810:		
	s7 = s7 + 1;
	s5 = s5 + a2;
	if (s2 != 0)
		goto loc_00019774;

loc_0001981C:		
	s1 = (s32)0 < (s32)fp;

loc_00019820:		
	*(s32*)(sp + 4) = s1;
	if (s1 == 0)
		goto loc_00019858;
	s5 = s6 - fp;
	s7 = s5 << 2;
	s3 = s7 + s4;
	a0 = s3 + 480;
	v1 = s4;
	s3 = fp;

loc_00019840:		
	s2 = *(s32*)(v1 + 0);
	s3 = s3 - 1;
	v1 = v1 + 4;
	*(s32*)(a0 + 0) = s2;
	a0 = a0 + 4;
	if (s3 != 0)
		goto loc_00019840;

loc_00019858:		
	s5 = s6 - fp;
	t7 = (s32)fp < (s32)s5;
	s2 = fp;
	v1 = s5;
	if (t7 == 0)
		goto loc_000198BC;

loc_0001986C:		
	t1 = *(s32*)(sp + 4);
	s7 = v1 - s2;
	if (t1 == 0)
		goto loc_000198AC;
	t8 = s7 << 2;
	v1 = t8 + s4;
	a0 = s2 << 2;
	s1 = v1 + 480;
	s0 = a0 + s4;
	s3 = fp;

loc_00019890:		
	a0 = *(s32*)(s0 + 0);
	s3 = s3 - 1;
	s0 = s0 + 4;
	v0 = sub_00001B54(...);
	*(s32*)(s1 + 0) = v0;
	s1 = s1 + 4;
	if (s3 != 0)
		goto loc_00019890;

loc_000198AC:		
	s2 = s2 + fp;
	t9 = (s32)s2 < (s32)s5;
	v1 = s5;
	if (t9 != 0)
		goto loc_0001986C;

loc_000198BC:		
	s0 = (s32)s5 < (s32)s6;
	s3 = s6 - s5;
	if (s0 == 0)
		goto loc_000198FC;
	t4 = fp - s6;

loc_000198CC:		
	t3 = t4 << 2;
	t0 = s5 << 2;
	t2 = t3 + s4;
	fp = t0 + t2;
	a0 = t0 + s4;
	v1 = fp + 480;

loc_000198E4:		
	s4 = *(s32*)(a0 + 0);
	s3 = s3 - 1;
	a0 = a0 + 4;
	*(s32*)(v1 + 0) = s4;
	v1 = v1 + 4;
	if (s3 != 0)
		goto loc_000198E4;

loc_000198FC:		
	v0 = 0;
	goto loc_00019660;

loc_00019904:		
	s3 = s1;
	s7 = 0;
	if (s5 == 0)
		goto loc_0001981C;
	t3 = s1 << 2;
	*(s32*)(sp + 8) = t3;
	s5 = s4;

loc_0001991C:		
	t9 = s3 << 2;
	s0 = t9 + s4;
	v0 = *(s32*)(s0 - 4);
	*(s32*)(sp + 0) = t9;
	s2 = 1;
	asm("rotr       $a0, $v0, 8");
	v0 = sub_00001A8C(...);
	t8 = 0x70000;
	v1 = t8 - 16612;
	t1 = *(s32*)(s5 + 0);
	a0 = s7 + v1;
	t7 = *(u8*)(a0 + 0);
	asm("xor        $t6, $t1, $v0");
	v1 = s3 + 1;
	asm("xor        $t5, $t6, $t7");
	t4 = (s32)v1 < (s32)s6;
	*(s32*)(s0 + 0) = t5;
	if (t4 == 0)
		goto loc_000199A8;
	a2 = v1;
	t6 = a2 - s1;

loc_0001996C:		
	a3 = t6 << 2;
	t5 = a2 << 2;
	t0 = t5 + s4;
	a1 = a3 + s4;
	t3 = *(s32*)(a1 + 0);
	t4 = *(s32*)(t0 - 4);
	s2 = s2 + 1;
	a2 = s2 + s3;

loc_0001998C:		
	asm("xor        $t2, $t3, $t4");
	s0 = (s32)s2 < (s32)4;
	a3 = (s32)a2 < (s32)s6;
	*(s32*)(t0 + 0) = t2;
	if (s0 == 0)
		goto loc_000199A8;
	t6 = a2 - s1;
	if (a3 != 0)
		goto loc_0001996C;

loc_000199A8:		
	a2 = s3 + 4;
	s2 = (s32)a2 < (s32)s6;
	a0 = *(s32*)(sp + 0);
	if (s2 != 0)
		goto loc_00019A38;

loc_000199B8:		
	s2 = 5;
	v1 = (s32)s2 < (s32)s1;
	a0 = s3 + 5;
	if (v1 == 0)
		goto loc_00019A18;
	t8 = (s32)a0 < (s32)s6;
	a2 = a0;
	if (t8 == 0)
		goto loc_00019A18;
	t5 = a2 - s1;

loc_000199D8:		
	a3 = a2 << 2;
	a1 = t5 << 2;
	s0 = a3 + s4;
	t4 = a1 + s4;
	t0 = *(s32*)(t4 + 0);
	t2 = *(s32*)(s0 - 4);
	s2 = s2 + 1;
	t3 = s2 + s3;
	asm("xor        $v0, $t0, $t2");
	t9 = (s32)s2 < (s32)s1;
	a2 = t3;
	a3 = (s32)t3 < (s32)s6;

loc_00019A0C:		
	*(s32*)(s0 + 0) = v0;
	if (t9 == 0)
		goto loc_00019A18;

loc_00019A10:		
	t5 = a2 - s1;
	if (a3 != 0)
		goto loc_000199D8;

loc_00019A18:		
	a2 = *(s32*)(sp + 8);
	s3 = s3 + s1;
	t6 = (s32)s3 < (s32)s6;
	s7 = s7 + 1;
	s5 = s5 + a2;
	if (t6 != 0)
		goto loc_0001991C;
	s1 = (s32)0 < (s32)fp;
	goto loc_00019820;

loc_00019A38:		
	s2 = a0 + s4;

loc_00019A3C:		
	a0 = *(s32*)(s2 + 12);
	v0 = sub_00001A8C(...);
	t1 = *(s32*)(s5 + 16);
	asm("xor        $t7, $t1, $v0");
	*(s32*)(s2 + 16) = t7;
	goto loc_000199B8;
}

sub_00019A54(...) // at 0x00019A54 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	v0 = 0x6C070000;
	*(s32*)(a0 + 4) = a1;
	a1 = v0 | 0x8965;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	a0 = a0 + 8;
	*(s32*)(sp + 0) = s0;
	s0 = 1;

loc_00019A7C:		
	t1 = *(s32*)(a0 - 4);
	v0 = (u32)t1 >> 30;
	asm("xor        $t0, $t1, $v0");
	asm("mult       $t0, $a1");
	asm("mflo       $a3");
	v1 = a3 + s0;
	s0 = s0 + 1;
	a2 = (s32)s0 < (s32)624;
	*(s32*)(a0 + 0) = v1;

loc_00019AA4:		
	a0 = a0 + 4;
	if (a2 != 0)
		goto loc_00019A7C;

loc_00019AA8:		
	*(s32*)(s1 + 0) = 0;
	s0 = 623;
	s0 = s0 - 1;

loc_00019AB4:		
	a0 = s1;
	v0 = sub_00002840(...);
	cond = ((s32)s0 >= 0);
	s0 = s0 - 1;
	if (cond)
		goto loc_00019AB4;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00019ADC(...) // at 0x00019ADC 
{
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = 0x20000;
	*(s32*)(sp + 0) = s0;
	a1 = a1 - 15292;
	s0 = a0;
	a2 = 256;
	a0 = a0 + 4;
	a3 = 0;
	*(s32*)(sp + 4) = ra;
	t0 = 0;
	v0 = sceKernelCreateLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16568;
	*(s32*)(s0 + 0) = v1;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16520;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16520;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 4;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s0 + 0) = v1;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 4;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;

loc_00019BD4:		
	v1 = v1 - 16520;
	*(s32*)(s0 + 0) = v1;
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a0 = a0 + 4;
	a1 = 1;
	*(s32*)(sp + 0) = ra;
	a2 = 0;
	v0 = sceKernelLockLwMutex(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a0 = a0 + 4;
	*(s32*)(sp + 0) = ra;
	a1 = 1;
	v0 = sceKernelUnlockLwMutex(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 4;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s0 + 0) = v1;
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16544;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 4;
	v0 = sceKernelDeleteLwMutex(...);
	v1 = 0x70000;
	v1 = v1 - 16520;
	*(s32*)(s0 + 0) = v1;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16496;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00006C9C(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16496;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = sub_00006C9C(...);
	a0 = s0;
	v0 = scePaf_DB1612F1(...);

loc_00019D18:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00019D28(...) // at 0x00019D28 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = 0x00000;
	v0 = v0 + 0;
	v1 = *(s32*)(a0 + 0);
	a0 = v1;
	if (v1 == v0)
		goto loc_00019D4C;
	v0 = scePaf_9AF12ADC(...);

loc_00019D4C:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00019D58(...) // at 0x00019D58 
{
	sp = sp - 32;

loc_00019D5C:		
	v0 = -1;
	*(s32*)(sp + 16) = s0;
	v1 = a2;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	if (a3 == v0)
		goto loc_00019DA8;

loc_00019D74:		
	v0 = 0x00000;
	a1 = *(s32*)(a1 + 0);
	v0 = v0 + 0;
	*(s32*)(s0 + 4) = 0;
	a2 = a3;
	a1 = a1 + v1;
	*(s32*)(s0 + 0) = v0;
	v0 = sub_00019EEC(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00019DA8:		
	v0 = *(s32*)(a1 + 4);
	a3 = v0 - a2;
	goto loc_00019D74;
}

sub_00019DB4(...) // at 0x00019DB4 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	v0 = 0;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	a0 = a1;
	s0 = a1;
	*(s32*)(sp + 8) = ra;
	if (a1 == 0)
		goto loc_00019DE0;
	v0 = scePaf_D7DCB972(...);

loc_00019DE0:		
	a0 = s1;
	a1 = s0;
	a2 = v0;
	v0 = sub_00019EEC(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00019E04(...) // at 0x00019E04 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = a0;
	*(s32*)(sp + 16) = s4;
	s4 = a1;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	if (a3 != 0)
		goto loc_00019EE4;
	v1 = *(s32*)(a0 + 4);
	v0 = (u32)v1 < (u32)a2;
	a0 = a2;
	if (v0 == 0)
		goto loc_00019EB4;

loc_00019E44:		
	s2 = v1 - a2;
	v0 = (u32)s2 < (u32)s3;
	v1 = (u32)a2 < (u32)v1;
	v0 = v0 ^ 0x1;
	v1 = v1 & v0;
	a0 = -1;
	if (v1 == 0)
		goto loc_00019EB4;
	v0 = *(s32*)(s5 + 0);
	s1 = v0 + a2;

loc_00019E68:		
	a0 = s1;
	if (s2 == 0)
		goto loc_00019EDC;
	a1 = *(s8*)(s4 + 0);
	v0 = scePaf_C3B2D310(...);
	s0 = v0;
	a0 = v0;
	a1 = s4;
	a2 = s3;
	if (v0 == 0)
		goto loc_00019EDC;
	v0 = scePaf_E0B32AE8(...);
	v1 = s1 - s0;
	v1 = s2 + v1;
	if (v0 == 0)
		goto loc_00019EAC;
	s2 = v1 - 1;

loc_00019EA4:		
	s1 = s0 + 1;
	goto loc_00019E68;

loc_00019EAC:		
	v0 = *(s32*)(s5 + 0);
	a0 = s0 - v0;

loc_00019EB4:		
	ra = *(s32*)(sp + 24);
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);

loc_00019ECC:		
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 32;
	return (v0);

loc_00019EDC:		
	a0 = -1;
	goto loc_00019EB4;

loc_00019EE4:		
	v1 = *(s32*)(a0 + 4);
	goto loc_00019E44;
}

sub_00019EEC(...) // at 0x00019EEC 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = 0x00000;
	v0 = s3 + 0;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 16) = ra;
	v1 = *(s32*)(a0 + 0);
	a0 = v1;
	if (v1 == v0)
		goto loc_00019F2C;
	v0 = scePaf_9AF12ADC(...);

loc_00019F2C:		
	v1 = s3 + 0;
	if (s1 == 0)
		goto loc_00019F40;
	v0 = *(s8*)(s1 + 0);
	a0 = s2 + 1;
	if (v0 != 0)
		goto loc_00019F68;

loc_00019F40:		
	*(s32*)(s0 + 0) = v1;
	*(s32*)(s0 + 4) = 0;

loc_00019F48:		
	v0 = s0;
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00019F68:		
	v0 = scePaf_77ADEAEB(...);
	*(s32*)(s0 + 0) = v0;
	a0 = v0;
	a1 = s1;
	*(s32*)(s0 + 4) = s2;
	a2 = s2;
	v0 = Kernel_Library_1839852A(...);
	v1 = *(s32*)(s0 + 0);
	v1 = v1 + s2;
	*(s8*)(v1 + 0) = 0;
	goto loc_00019F48;
	v0 = 0x70000;
	v0 = v0 - 16336;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16336;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = *(s32*)(a0 + 20);
	return (v0);
	v0 = *(s32*)(a0 + 24);
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = a0 + 540;
	return (v0);
	return (v0);
	return (v0);
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	a2 = 255;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 796;
	v0 = onesegSal_E37427BE(...);
	*(s8*)(s0 + 1051) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = a0 + 796;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16160;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 16160;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;

loc_0001A070:		
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	*(s32*)(a0 + 4) = a1;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15936;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegHalToolbox_3FCF5660(...);
	a1 = s0;

loc_0001A138:		
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0001A14C:		
	v0 = 0x70000;
	v0 = v0 - 15936;
	*(s32*)(a0 + 0) = v0;

loc_0001A158:		
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegHalToolbox_3FCF5660(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);

loc_0001A1C0:		
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15936;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegHalToolbox_3FCF5660(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15936;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegHalToolbox_3FCF5660(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSdkCore_C56F59B8(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;

loc_0001A2DC:		
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_3B9B8073(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0001A304(...) // at 0x0001A304 
{
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_3B9B8073(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 1;
	return (v0);
	v0 = 5;
	*(s32*)(a1 + 0) = v0;
	v1 = 16384;
	v0 = 0;
	*(s32*)(a2 + 0) = v1;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;

loc_0001A35C:		
	v0 = onesegSdkCore_C7E3CDBB(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15704;
	sp = sp - 16;
	*(s32*)(a0 + 0) = v0;
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(s0 + 1024) = v0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 1024;
	v0 = onesegSdkCore_3B9B8073(...);
	a0 = s0 + 104;
	v0 = sub_000160A4(...);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(s0 + 0) = v0;
	a0 = s0 + 68;
	v0 = sub_0001A304(...);
	a0 = s0 + 48;
	v0 = onesegSdkCore_3ECA9AC8(...);
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(s0 + 24) = v0;
	a0 = s0 + 24;
	v0 = onesegSdkCore_DE141C98(...);
	v0 = 0x70000;
	v0 = v0 - 15408;

loc_0001A3E0:		
	*(s32*)(s0 + 12) = v0;
	s0 = s0 + 12;
	a0 = s0;
	v0 = onesegSdkCore_DE141C98(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15704;
	sp = sp - 16;
	*(s32*)(a0 + 0) = v0;
	v0 = 0x70000;

loc_0001A414:		
	v0 = v0 - 15528;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(s0 + 1024) = v0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 1024;
	v0 = onesegSdkCore_3B9B8073(...);
	a0 = s0 + 104;
	v0 = sub_000160A4(...);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(s0 + 0) = v0;
	a0 = s0 + 68;
	v0 = sub_0001A304(...);
	a0 = s0 + 48;
	v0 = onesegSdkCore_3ECA9AC8(...);
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(s0 + 24) = v0;
	a0 = s0 + 24;
	v0 = onesegSdkCore_DE141C98(...);
	v0 = 0x70000;
	v0 = v0 - 15408;
	*(s32*)(s0 + 12) = v0;
	a0 = s0 + 12;
	v0 = onesegSdkCore_DE141C98(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSdkCore_C56F59B8(...);
	ra = *(s32*)(sp + 4);

loc_0001A48C:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(a0 + 0) = v0;

loc_0001A4A4:		
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSdkCore_C56F59B8(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_0001A4D0:		
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(a0 + 0) = v0;

loc_0001A4E4:		
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;

loc_0001A4F0:		
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	ra = *(s32*)(sp + 0);

loc_0001A4F8:		
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	a0 = 0;
	s1 = a1;
	a1 = 64;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);

loc_0001A520:		
	a0 = v0;
	s0 = v0;
	v0 = onesegSdkCore_3BD4CA31(...);
	v0 = 0x70000;
	v0 = v0 - 15512;
	*(s32*)(s0 + 0) = v0;
	v0 = 0x80000000;
	if (s0 == 0)
		goto loc_0001A548;
	*(s32*)(s1 + 0) = s0;
	v0 = 0;

loc_0001A548:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15408;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_DE141C98(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15408;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_DE141C98(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a1 = 16;
	a0 = 0;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	a0 = v0;
	s0 = v0;
	v0 = onesegSdkCore_D5EFD0FA(...);
	v0 = 0x70000;
	v0 = v0 - 15288;
	*(s32*)(s0 + 0) = v0;
	v0 = s0;
	*(s32*)(s0 + 12) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0001A608:		
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_DE141C98(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_DE141C98(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	a1 = 16;
	a0 = 0;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	a0 = v0;
	s0 = v0;
	v0 = onesegSdkCore_D5EFD0FA(...);
	v0 = 0x70000;
	v0 = v0 - 15304;
	*(s32*)(s0 + 0) = v0;
	v0 = s0;
	*(s32*)(s0 + 12) = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);

loc_0001A6AC:		
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	if (a0 == 0)
		goto loc_0001A6D8;
	v0 = *(s32*)(a0 + 0);
	v1 = *(s32*)(v0 + 32);
	v0 = $v1(...);

loc_0001A6D8:		
	ra = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_A91C2037(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;

loc_0001A714:		
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_A91C2037(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15288;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_1ACB415D(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15288;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_1ACB415D(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15304;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_1ACB415D(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15304;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_1ACB415D(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_A91C2037(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_A91C2037(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15272;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15272;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15240;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15240;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0;
	return (v0);
	v0 = 1;
	return (v0);
	v0 = 4;
	*(s32*)(a1 + 0) = v0;
	v1 = 16384;
	v0 = 0;
	*(s32*)(a2 + 0) = v1;
	return (v0);
	v0 = 0x70000;

loc_0001A924:		
	v0 = v0 - 15144;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 112;
	v0 = sub_00016A58(...);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(s0 + 0) = v0;
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(s0 + 68) = v0;
	a0 = s0 + 68;
	v0 = onesegSdkCore_3B9B8073(...);
	a0 = s0 + 48;
	v0 = onesegSdkCore_3ECA9AC8(...);
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(s0 + 24) = v0;
	a0 = s0 + 24;
	v0 = onesegSdkCore_DE141C98(...);
	v0 = 0x70000;
	v0 = v0 - 15408;
	*(s32*)(s0 + 12) = v0;
	s0 = s0 + 12;
	a0 = s0;
	v0 = onesegSdkCore_DE141C98(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15144;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 112;
	v0 = sub_00016A58(...);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(s0 + 0) = v0;
	v0 = 0x70000;
	v0 = v0 - 15528;
	*(s32*)(s0 + 68) = v0;
	a0 = s0 + 68;
	v0 = onesegSdkCore_3B9B8073(...);
	a0 = s0 + 48;
	v0 = onesegSdkCore_3ECA9AC8(...);
	v0 = 0x70000;
	v0 = v0 - 15464;
	*(s32*)(s0 + 24) = v0;
	a0 = s0 + 24;
	v0 = onesegSdkCore_DE141C98(...);
	v0 = 0x70000;
	v0 = v0 - 15408;
	*(s32*)(s0 + 12) = v0;
	a0 = s0 + 12;
	v0 = onesegSdkCore_DE141C98(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSdkCore_C56F59B8(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSdkCore_C56F59B8(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x00000;
	v0 = v0 + 8;

loc_0001AA80:		
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = a0 + 8;
	v0 = onesegSdkCore_2E4F2374(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	a0 = 0;
	s1 = a1;
}

sub_0001AAB0(...) // at 0x0001AAB0 
{
	a1 = 56;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = onesegSal_265926E7(...);
	a0 = v0;

loc_0001AAC4:		
	s0 = v0;
	v0 = onesegSdkCore_3BD4CA31(...);
	v0 = 0x70000;
	v0 = v0 - 14968;
	*(s32*)(s0 + 0) = v0;
	v0 = 0x80000000;
	if (s0 == 0)
		goto loc_0001AAE8;
	*(s32*)(s1 + 0) = s0;
	v0 = 0;

loc_0001AAE8:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = onesegSdkCore_A91C2037(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15352;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;

loc_0001AB38:		
	*(s32*)(sp + 4) = ra;
	s0 = a0;
	v0 = onesegSdkCore_A91C2037(...);
	a1 = s0;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	return (v0);
	v0 = 0x70000;
	v0 = v0 - 15856;
	*(s32*)(a0 + 0) = v0;
	sp = sp - 16;
	a1 = a0;
	*(s32*)(sp + 0) = ra;
	a0 = 0;
	v0 = onesegSal_E64CF915(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_0001ABD8(...) // at 0x0001ABD8 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = ra;
	v0 = sub_00000030(...);
	ra = *(s32*)(sp + 20);
	sp = sp + 32;
	return (v0);
}
