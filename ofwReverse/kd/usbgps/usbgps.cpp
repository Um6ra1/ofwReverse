module_start(...) // at 0x00000000 
{\
	a0 = 0x00000 + 16;
	v0 = sceKernelRegisterSysEventHandler(...);
	s0 = 0x00000 + 340;
	*(s32*)(s0 + 24) = -1;
	*(s32*)(s0 + 48) = 4096;
	*(s32*)(s0 + 8) = -1;
	*(s32*)(s0 + 12) = -1;
	*(s32*)(s0 + 16) = -1;
	*(s32*)(s0 + 20) = -1;
	*(s32*)(s0 + 2964) = 0;
	*(s32*)(s0 + 44) = 0;
	*(s32*)(s0 + 80) = 0;
	*(s32*)(v0 + 340) = 0;
	v0 = memset(s0 + 84, 0, 2880);
	v0 = sub_00002A14();
	s1 = (s32)v0 < (s32)0;
	v0 = sub_00002A98(0x00000 + 6380, s0);
	sp = sp + 16;
	return (s1);
}

{
	sp = sp - 32;
	v1 = 1026;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	if (a0 == v1)
		goto loc_000000F8;
	v1 = 0x100000;
	s1 = 0x00000;
	if (a0 == v1)
		goto loc_000000F0;

loc_000000CC:		
	v0 = s0;

loc_000000D0:		
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000000F0:		
	*(s32*)(s1 + 336) = 0;
	goto loc_000000CC;

loc_000000F8:		
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	a1 = *(s32*)(a0 + 340);
	s2 = v0;
	v0 = 4;
	s1 = a0 + 340;
	if (a1 == v0)
		goto loc_00000134;
	a3 = 2;
	a2 = 0x00000;
	*(s32*)(a2 + 336) = a3;

loc_00000124:		
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	goto loc_000000D0;

loc_00000134:		
	s3 = 0x00000;
	v0 = *(s32*)(s3 + 336);
	s4 = 1;
	if (v0 == s4)
	{
		a0 = *(s32*)(s1 + 16);
		goto loc_00000190;
	}
	a1 = 16;
	if (v0 != 0)
		goto loc_00000124;
	a0 = *(s32*)(s1 + 16);
	a2 = 1;
	a3 = 0;
	v0 = sceKernelPollEventFlag(...);
	t2 = 0x80020000;
	t0 = t2 | 0x1AF;
	if (v0 == t0)
	{
		a0 = *(s32*)(s1 + 16);
		goto loc_00000180;
	}
	t3 = 0x80000000;

loc_00000174:		
	s0 = t3 | 0x21;
	*(s32*)(s3 + 336) = s4;
	goto loc_00000124;

loc_00000180:		
	a1 = 16;
	v0 = sceKernelSetEventFlag(...);
	t3 = 0x80000000;
	goto loc_00000174;

loc_00000190:		
	a1 = 16;
	a2 = 1;
	a3 = 0;
	v0 = sceKernelPollEventFlag(...);
	t5 = 0x80020000;
	t4 = t5 | 0x1AF;
	t7 = 2;
	if (v0 == t4)
		goto loc_000001C4;
	if (v0 != 0)
	{
		*(s32*)(s3 + 336) = t7;
		goto loc_00000124;
	}
	t6 = 0x80000000;
	s0 = t6 | 0x21;
	goto loc_00000124;

loc_000001C4:		
	*(s32*)(s3 + 336) = t7;
	goto loc_00000124;
}

sceUsbGpsOpen(...) // at 0x000001CC 
{
	s2 = k1;
	k1 = k1 << 11;
	s1 = 0;
	v0 = sceKernelIsIntrContext(...);
	s0 = 0x00000;
	if (v0 == 0)
	{
		v1 = *(s32*)(0x00000 + 340);
		s3 = 0x00000 + 340;
		if (v1 == 0)
		{
			a1 = 0x00000;
			a0 = a1 + 22028;
			a2 = 0;
			a1 = 513;
			a3 = 0;
			*(s32*)(s3 + 7972) = 0;
			*(s8*)(s3 + 7980) = 0;
			v0 = sceKernelCreateEventFlag(...);
			t1 = 0x100000;
			if ((s32)v0 <= 0)
			{
				s1 = v0;
				if ((s32)v0 >= 0)
					goto loc_0000034C;
				s0 = s0 + 340;
				goto loc_00000208;
			}
			a3 = 0x00000;
			a2 = 0x00000;
			a0 = a3 + 22048;
			a1 = a2 + 3576;
			t0 = t1 | 0x1;
			a2 = 16;
			a3 = 2048;
			t1 = 0;
			*(s32*)(s3 + 16) = v0;
			v0 = sceKernelCreateThread(...);
			t0 = 0x00000;
			if ((s32)v0 <= 0)
			{
				s1 = v0;
				if ((s32)v0 >= 0)
					goto loc_0000034C;
				s0 = s0 + 340;
				goto loc_00000208;
			}
			t2 = 0x100000;
			t3 = 0x00000;
			a1 = t0 + 4064;
			a0 = t3 + 22072;
			a2 = 17;
			a3 = 2048;
			t0 = t2 | 0x1;
			t1 = 0;
			*(s32*)(s3 + 8) = v0;
			v0 = sceKernelCreateThread(...);
			a0 = v0;
			if ((s32)v0 <= 0){
				s1 = v0;
				if ((s32)v0 >= 0)
					goto loc_0000034C;
				s0 = s0 + 340;
				goto loc_00000208;
			}
			a1 = 0;
			a2 = 0;
			*(s32*)(s3 + 12) = v0;
			v0 = sceKernelStartThread(...);
			a1 = 0;
			if ((s32)v0 < 0){
				s1 = v0;
				if ((s32)v0 >= 0)
					goto loc_0000034C;
				s0 = s0 + 340;
				goto loc_00000208;
			}
			a0 = *(s32*)(s3 + 8);
			a2 = 0;
			v0 = sceKernelStartThread(...);
			if ((s32)v0 < 0){
				s1 = v0;
				if ((s32)v0 >= 0)
					goto loc_0000034C;
				s0 = s0 + 340;
				goto loc_00000208;
			}

		loc_0000034C:
			t6 = 1;
			*(s32*)(s0 + 340) = t6;
			v0 = s1;
			goto loc_00000260;
		}
		s1 = 0x80244003;
	}
	else
	{
		s1 = 0x80020064;
	}
loc_00000204:		
	s0 = 0x00000 + 340;

loc_00000208:		
	a0 = *(s32*)(s0 + 16);
	if (a0 >= 0)
	{
		v0 = sceKernelDeleteEventFlag(...);
		a0 = -1;
		*(s32*)(s0 + 16) = a0;
	}
	a0 = *(s32*)(s0 + 8);	
	if (a0 >= 0)
	{
		v0 = sceKernelDeleteThread(...);
		t4 = -1;
		*(s32*)(s0 + 8) = t4;
	}
	a0 = *(s32*)(s0 + 12);		
	v0 = s1;
	if (a0 >= 0)
	{
		v0 = sceKernelDeleteThread(...);
		t5 = -1;
		*(s32*)(s0 + 12) = t5;
		v0 = s1;
	}
loc_00000260:		
	k1 = s2;
	return (v0);
}

sceUsbGpsClose(...) // at 0x0000036C 
{
	sp = sp - 32;
	*(s32*)(sp + 4) = s1;
	s1 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	v0 = sceKernelIsIntrContext(...);
	cond = (v0 != 0);
	v0 = s0;
	if (cond)
		goto loc_000003B0;
	s3 = 0x00000;
	v1 = *(s32*)(s3 + 340);
	s2 = s3 + 340;
	if (v1 != 0)
		goto loc_000003D0;
	v0 = s0;

loc_000003B0:		
	k1 = s1;
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_000003D0:		
	v0 = sub_00003524(...);
	a0 = *(s32*)(s2 + 8);
	s0 = v0;
	if (a0 >= 0)
	{
		v0 = sceKernelTerminateDeleteThread(...);
		v1 = -1;
		*(s32*)(s2 + 8) = v1;
		s0 = v0;
	}
	a0 = *(s32*)(s2 + 12);
	if ((s32)a0 < 0)
	{
		a0 = *(s32*)(s2 + 20);
		goto loc_0000041C;
	}
	v0 = sceKernelTerminateDeleteThread(...);
	a0 = -1;
	*(s32*)(s2 + 12) = a0;
	s0 = v0;
	a0 = *(s32*)(s2 + 20);

loc_0000041C:		
	if ((s32)a0 < 0)
	{
		a0 = *(s32*)(s2 + 16);
		goto loc_0000043C;
	}
	if (a0 >= 0)
	{
		v0 = sceKernelCancelAlarm(...);
		a1 = -1;
		*(s32*)(s2 + 20) = a1;
		s0 = v0;
	}
	a0 = *(s32*)(s2 + 16);

loc_0000043C:		
	if ((s32)a0 < 0)
	{
		v0 = sub_00003420(...);
		*(s32*)(s3 + 340) = 0;
		v0 = s0;
		goto loc_000003B0;
	}
	v0 = sceKernelDeleteEventFlag(...);
	a2 = -1;
	*(s32*)(s2 + 16) = a2;
	s0 = v0;
}

sceUsbGpsResetInitialPosition(...) // at 0x0000046C 
{
	at = 0x42B40000;
	asm("mtc1       $at, $fcr1");
	asm("c.lt.s     $fpr01, $fpr12");
	sp = sp - 64;
	*(s32*)(sp + 4) = s1;
	s1 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	asm("swc1       $fpr24, 48($sp)");
	asm("mov.s      $fpr24, $fpr14");
	asm("swc1       $fpr23, 44($sp)");
	asm("mov.s      $fpr23, $fpr12");
	asm("swc1       $fpr21, 36($sp)");
	asm("mov.s      $fpr21, $fpr15");
	asm("swc1       $fpr20, 32($sp)");
	asm("mov.s      $fpr20, $fpr13");
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	asm("swc1       $fpr25, 52($sp)");
	cond = (asm("bc1t       loc_00000578"));
	asm("swc1       $fpr22, 40($sp)");
	if (cond)
		goto ;
	at = 0xC2B40000;
	asm("mtc1       $at, $fcr1");
	asm("c.lt.s     $fpr12, $fpr01");
	v1 = 0x80240000;
	if (asm("bc1t       loc_0000057C"))
		goto ;
	at = 0x43340000;
	asm("mtc1       $at, $fcr25");
	asm("c.lt.s     $fpr25, $fpr13");
	if (asm("bc1tl      loc_00000580"))
	{
		k1 = s1;
		goto ;
	}
	at = 0xC3340000;
	asm("mtc1       $at, $fcr2");
	asm("c.lt.s     $fpr13, $fpr02");
	if (asm("bc1tl      loc_00000580"))
	{
		k1 = s1;
		goto ;
	}
	at = 0xC61C0000;
	at = at | 0x4000;
	asm("mtc1       $at, $fcr3");
	asm("c.lt.s     $fpr14, $fpr03");
	if (asm("bc1tl      loc_00000580"))
	{
		k1 = s1;
		goto ;
	}
	at = 0x461C0000;
	at = at | 0x4000;
	asm("mtc1       $at, $fcr4");
	asm("c.lt.s     $fpr04, $fpr14");
	if (asm("bc1tl      loc_00000580"))
	{
		k1 = s1;
		goto ;
	}
	at = 0xC47A0000;
	asm("mtc1       $at, $fcr5");
	asm("c.lt.s     $fpr15, $fpr05");
	if (asm("bc1tl      loc_00000580"))
	{
		k1 = s1;
		goto ;
	}
	at = 0x447A0000;
	asm("mtc1       $at, $fcr6");
	asm("c.lt.s     $fpr06, $fpr15");
	if (asm("bc1f       loc_000005B8"))
		goto ;

loc_00000578:		
	v1 = 0x80240000;

loc_0000057C:		
	k1 = s1;

loc_00000580:		
	v0 = v1 | 0x4007;

loc_00000584:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	asm("lwc1       $fpr25, 52($sp)");
	asm("lwc1       $fpr24, 48($sp)");
	asm("lwc1       $fpr23, 44($sp)");
	asm("lwc1       $fpr22, 40($sp)");
	asm("lwc1       $fpr21, 36($sp)");
	asm("lwc1       $fpr20, 32($sp)");
	sp = sp + 64;
	return (v0);

loc_000005B8:		
	v0 = sceKernelCpuSuspendIntr(...);
	a1 = 0x00000;
	s2 = a1 + 340;
	s3 = v0;
	v0 = *(u8*)(s2 + 6);
	a0 = 1;
	if (v0 == a0)
		goto loc_000005E8;
	a2 = *(s32*)(s2 + 44);
	if (a2 != 0)
	{
		s0 = s2 + 68;
		goto loc_000005FC;
	}

loc_000005E8:		
	a0 = s3;
	v0 = sceKernelCpuResumeIntr(...);
	k1 = s1;
	v0 = s0;
	goto loc_00000584;

loc_000005FC:		
	at = 0x40490000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr5");
	asm("mul.s      $fpr04, $fpr23, $fpr05");
	asm("mul.s      $fpr00, $fpr20, $fpr05");
	asm("div.s      $fpr23, $fpr04, $fpr25");
	asm("div.s      $fpr22, $fpr00, $fpr25");
	asm("mov.s      $fpr12, $fpr23");
	v0 = sub_0000306C(...);
	at = 0x3BDB0000;
	at = at | 0x5958;
	asm("mtc1       $at, $fcr3");
	asm("mov.s      $fpr12, $fpr23");
	asm("mul.s      $fpr20, $fpr00, $fpr03");
	v0 = sub_0000306C(...);
	at = 0x3F800000;
	asm("mtc1       $at, $fcr19");
	at = 0x4AC20000;
	at = at | 0xA532;
	asm("mtc1       $at, $fcr16");
	asm("mul.s      $fpr01, $fpr20, $fpr00");
	asm("add.s      $fpr25, $fpr24, $fpr21");
	asm("mov.s      $fpr12, $fpr23");
	asm("sub.s      $fpr18, $fpr19, $fpr01");
	asm("sqrt.s     $fpr17, $fpr18");
	asm("div.s      $fpr20, $fpr16, $fpr17");
	v0 = sub_000031B0(...);
	asm("mov.s      $fpr12, $fpr22");
	asm("add.s      $fpr15, $fpr20, $fpr25");
	asm("mul.s      $fpr21, $fpr15, $fpr00");
	v0 = sub_000031B0(...);
	asm("mov.s      $fpr12, $fpr22");
	asm("mul.s      $fpr14, $fpr21, $fpr00");
	asm("trunc.w.s  $fpr13, $fpr14");
	asm("swc1       $fpr13, 68($s2)");
	v0 = sub_0000306C(...);
	asm("mul.s      $fpr11, $fpr21, $fpr00");
	at = 0x3F7E0000;
	at = at | 0x494D;
	asm("mtc1       $at, $fcr12");
	asm("mul.s      $fpr10, $fpr20, $fpr12");
	asm("mov.s      $fpr12, $fpr23");
	asm("trunc.w.s  $fpr09, $fpr11");
	asm("add.s      $fpr21, $fpr10, $fpr25");
	asm("swc1       $fpr09, 4($s0)");
	v0 = sub_0000306C(...);
	asm("mul.s      $fpr08, $fpr21, $fpr00");
	a0 = 3;
	asm("trunc.w.s  $fpr07, $fpr08");
	asm("swc1       $fpr07, 8($s0)");
	v0 = sub_00001CA8(...);
	s0 = v0;
	goto loc_000005E8;
}

sceUsbGpsSetInitDataLocation(x) // at 0x000006D0 
{
	s3 = 0x00000 + 340;
	s2 = k1;
	k1 = k1 << 11;
	s0 = 0;
	if (*(s32*)(0x00000 + 340))
	{
		if (a0 < 3)
		{
			v0 = sceKernelCpuSuspendIntr(...);
			*(s32*)(s3 + 2964) = x;
			v0 = sceKernelCpuResumeIntr(v0);
		}
		else
		{
			s0 = 0x80244007;
		}
	}
	else
	{
		s0 = 0x80244002;
	}

	k1 = s2;
	return (s0);
}

sceUsbGpsGetInitDataLocation(...) // at 0x00000768 
{
	t0 = *(s32*)(0x00000 + 340);
	a2 = k1;
	a1 = 0;
	k1 = k1 << 11;
	a3 = 0x00000 + 340;
	if (t0 != 0)
	{
		v0 = a0 + 4;
		if (a0 == 0)
		{
			a1 = 0x80244007;
			goto loc_0000078C;
		}
		t1 = v0 | a0;
		t0 = t1 & k1;
		if ((s32)t0 >= 0)
		{
			*(s32*)(a0 + 0) = *(s32*)(a3 + 2964);
			goto loc_0000078C;
		}
		a1 = 0x80244006;
		goto loc_0000078C;
	}
	a1 = 0x80244002;

loc_0000078C:		
	k1 = a2;
	return (a1);
}

sceUsbGps_A8ED0BC2(...) // at 0x000007D0 - Aliases: sceUsbGps_driver_A8ED0BC2
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	s1 = a0 & 0xFF;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 36) = ra;
	s0 = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	s4 = v0;
	v0 = *(s32*)(a0 + 340);
	a1 = 4;
	*(s32*)(sp + 0) = 0;
	s2 = a0 + 340;
	if (v0 == a1)
		goto loc_00000874;
	v0 = *(s32*)(a0 + 340);
	v1 = 0x80240000;
	s0 = v1 | 0x4002;
	if (v0 == 0)
		goto loc_00000844;
	a1 = 0x80240000;
	a0 = (u32)v0 < (u32)4;
	s0 = a1 | 0x4010;
	if (a0 == 0)
		goto loc_00000844;
	s0 = 0;
	*(s8*)(s2 + 7980) = s1;

loc_00000844:		
	a0 = s4;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	k1 = s3;
	ra = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00000874:		
	a3 = (u32)s1 < (u32)2;
	if (a3 != 0)
	{
		t1 = *(u8*)(s2 + 7980);
		goto loc_0000088C;
	}
	t0 = 0x80240000;
	s0 = t0 | 0x4007;
	goto loc_00000844;

loc_0000088C:		
	a1 = 3072;
	if (t1 == s1)
		goto loc_00000844;
	a0 = *(s32*)(s2 + 16);
	a2 = 1;
	a3 = sp;
	*(s8*)(s2 + 7980) = s1;
	v0 = sceKernelPollEventFlag(...);
	if (v0 == 0)
	{
		a0 = *(s32*)(s2 + 16);
		goto loc_000008D4;
	}

loc_000008B0:		
	a0 = *(s32*)(s2 + 16);
	t8 = s1 ^ 0x1;
	t7 = 2048;
	a1 = 1024;
	if (t8 != 0)
		a1 = t7;
	v0 = sceKernelSetEventFlag(...);
	t6 = (s32)v0 < (s32)0;
	if (t6 != 0)
		s0 = v0;
	goto loc_00000844;

loc_000008D4:		
	a1 = -3073;
	v0 = sceKernelClearEventFlag(...);
	t3 = (s32)v0 < (s32)0;
	s0 = v0;
	if (t3 == 0)
		s0 = 0;
	goto loc_000008B0;
}

sceUsbGps_5881C826(...) // at 0x000008EC - Aliases: sceUsbGps_driver_5881C826
{
	a2 = k1;
	a1 = 0;
	k1 = k1 << 11;
	a3 = 0x00000 + 340;
	if (*(s32*)(0x00000 + 340))
	{
		v0 = a0 + 1;
		if (a0 == 0)
		{
			a1 = 0x80244007;
			goto loc_00000910;
		}
		t1 = v0 | a0;
		t0 = t1 & k1;
		if ((s32)t0 >= 0)
		{
			*(s8*)(a0 + 0) = *(u8*)(a3 + 7980);
			goto loc_00000910;
		}
		a1 = 0x80244006;
		goto loc_00000910;
	}
	a1 = 0x80244002;

loc_00000910:		
	k1 = a2;
	return (a1);
}

sceUsbGpsSaveInitData(...) // at 0x00000954 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sceKernelIsIntrContext(...);
	v1 = 0x80020064;
	if (!v0)
	{
		a0 = 0x00000 + 340;
		if (*(s32*)(0x00000 + 340) == 4)
		{
			v1 = 0x802440FF;
			if (*(s32*)(a0 + 44))
			{
				v0 = sub_000014E0(a0 + 44, 1);
				t8 = (s32)v0 < (s32)0;
				v1 = v0;
				if (t8 == 0)
					v1 = 0;
			}
		}
		else
		{
			a0 = *(s32*)(a1 + 340);
			v1 = 0x80244004;
			if (a0 != 1)
			{
				v1 = 0x80244002;
				if (a0)
				{
					if (a0 == 2)
					{
						v0 = sceUsbAccGetAuthStat(...);
						t2 = 0x80243701;
						v1 = t2;
						if (v0 != t2)
						{
							v1 = 0x80244005;
						}
					}
					else if (a0 == 3)
					{
						v1 = 0x80244005;
					}
					else
					{
						v1 = 0x80244010;
					}
				}
			}
		}
	}	
	k1 = s0;
	return (v1);
}

sceUsbGpsSetPowerSaveMode(...) // at 0x00000A34 
{
	sp = sp - 32;
	*(s32*)(sp + 8) = s2;
	s2 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 16) = ra;
	s0 = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	a1 = 0x00000;
	a2 = v0;
	t1 = s1 ^ 0xA;
	v0 = (u32)s1 < (u32)4;
	t0 = *(s32*)(a1 + 340);
	a0 = v0 ^ 0x1;
	a3 = (u32)0 < (u32)t1;
	v1 = a0 & a3;
	a3 = 1;
	a0 = a1 + 340;
	if (t0 == a3)
	{
		v0 = s3 - 30;
		if (v1 != 0)
		{
			t4 = 0x80240000;
			s0 = t4 | 0x4007;
			goto loc_00000A98;
		}
		t3 = 0xF0000;
		t2 = (u32)v0 < (u32)571;
		a1 = t3 | 0x4240;
		if (t2 != 0)
			goto loc_00000AE8;

	loc_00000AE8:
		asm("mult       $s3, $a1");
		*(s32*)(a0 + 7972) = s1;
		asm("mflo       $t5");
		*(s32*)(a0 + 7976) = (s32)(s3 * a1);//t5;
		goto loc_00000A98;
	}
	v1 = 0x80240000;
	s0 = v1 | 0x4002;

loc_00000A98:		
	a0 = a2;
	v0 = sceKernelCpuResumeIntr(...);
	k1 = s2;
	return (s0);
}

sceUsbGpsGetPowerSaveMode(...) // at 0x00000AFC 
{
	v1 = 0x00000;
	a2 = *(s32*)(v1 + 340);
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	s4 = v1 + 340;
	*(s32*)(sp + 12) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	if (a2 != 0)
		goto loc_00000B6C;
	v0 = 0x80240000;
	s1 = v0 | 0x4002;

loc_00000B44:		
	v0 = s1;

loc_00000B48:		
	k1 = s3;
	return (v0);

loc_00000B6C:		
	a0 = a0 | a1;
	t0 = s0 + 4;
	if (a0 != 0)
		goto loc_00000B84;
	a1 = 0x80240000;
	s1 = a1 | 0x4007;
	goto loc_00000B44;

loc_00000B84:		
	a3 = t0 | s0;
	a2 = a3 & k1;
	t4 = 0x80240000;
	if ((s32)a2 < 0)
		goto loc_00000BA8;
	t3 = a1 + 4;
	t2 = t3 | a1;
	t1 = t2 & k1;
	if ((s32)t1 >= 0)
		goto loc_00000BB0;

loc_00000BA8:		
	s1 = t4 | 0x4006;
	goto loc_00000B44;

loc_00000BB0:		
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = v0;
	if (s0 == 0)
		goto loc_00000BC8;
	t5 = *(s32*)(s4 + 7972);
	*(s32*)(s0 + 0) = t5;

loc_00000BC8:		
	if (s2 == 0)
		goto loc_00000BEC;
	t8 = *(s32*)(s4 + 7976);
	s4 = 0x431B0000;
	s0 = s4 | 0xDE83;
	asm("multu      $t8, $s0");
	asm("mfhi       $t7");
	t6 = (u32)t7 >> 18;
	*(s32*)(s2 + 0) = t6;

loc_00000BEC:		
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s1;
	goto loc_00000B48;
}

sceUsbGpsGetState(int *lpState) // at 0x00000BFC 
{
	s2 = k1;
	k1 = k1 << 11;
	s1 = 0;
	s0 = a0;
	a1 = *(s32*)(0x00000 + 340);
	v0 = 0x80240000;
	if (a1 != 0)
	{
		a2 = a0 + 4;
		if (a0 == 0)
		{
			s1 = 0x80244007;
			goto loc_00000C38;
		}
		a1 = a2 | a0;
		a0 = a1 & k1;
		a3 = 0x80240000;
		if ((s32)a0 >= 0)
		{
			v1 = *(s32*)(0x00000 + 340);
			s3 = 2;
			t0 = (u32)v1 < (u32)3;
			if (v1 == s3)
			{
				v0 = sceUsbAccGetAuthStat(...);
				t4 = 0x80240000;
				t3 = t4 | 0x3701;
				if (v0 != t3)
				{
					*(s32*)(s0 + 0) = s3;
					goto loc_00000C38;
				}
				t5 = 1;
				*(s32*)(s0 + 0) = t5;
				goto loc_00000C38;
			}
			a0 = 3;
			if (t0 == 0)
			{
				t2 = 4;
				if (v1 == a0)
				{
					*(s32*)(s0 + 0) = s3;
					goto loc_00000C38;
				}
				t6 = 0x80240000;
				if (v1 != t2)
					goto loc_00000CA4;
				*(s32*)(s0 + 0) = a0;
				goto loc_00000C38;
			}
			if (v1 == 1)
			{
				*(s32*)(s0 + 0) = 0;
				goto loc_00000C38;
			}
		loc_00000CA4:
			s1 = 0x80244010;
			goto loc_00000C38;
		}
		s1 = 0x80244006;
		goto loc_00000C38;
	}
	s1 = 0x80244002;

loc_00000C38:
	k1 = s2;
	return (s1);
}

sceUsbGpsGetData(gpsdata* lpGps, satdata* lpSat) // at 0x00000CFC 
{
	s1 = k1;
	s0 = 0;
	k1 = k1 << 11;
	if (*(s32*)(0x00000 + 340) == 4)
	{
		t6 = a0 + 48;
		if (a0)
		{
			t5 = t6 | a0;
			t4 = t5 & k1;
			v0 = 0x80240000;
			if ((s32)t4 < 0)
			{
				s0 = 0x80244006;
				goto loc_00000D64;
			}
		}

		t9 = a1 + 260;
		if (a1 == 0)
		{
			v0 = sub_00003F34(...);
			goto loc_00000D64;
		}
		t8 = t9 | a1;
		t7 = t8 & k1;
		if ((s32)t7 >= 0)
		{
			v0 = sub_00003F34(...);
			goto loc_00000D64;
		}
		s0 = 0x80244006;
		goto loc_00000D64;
	}
	s0 = 0x80244004;
	if (*(s32*)(0x00000 + 340) != 1)
	{
		s0 = 0x80244002;
		if (v1)
		{
			t0 = 3;
			if (v1 == 2)
			{
				v0 = sceUsbAccGetAuthStat(...);
				t2 = 0x80240000;
				t1 = t2 | 0x3701;
				s0 = t1;
				if (v0 != t1)
				{
					s0 = 0x80244005;
					goto loc_00000D64;
				}
			}
			else if (v1 == t0)
			{
				s0 = 0x80244005;
			}
			else
			{
				s0 = 0x80244010;
			}
		}
	}
loc_00000D64:
	k1 = s1;
	return (s0);
}

{
	sp = sp - 48;
	*(s32*)(sp + 36) = ra;
	a1 = 0xF0000;
	a0 = 0x80020000;
	v1 = 0x80020000;
	a2 = 0x00000;
	*(s32*)(sp + 32) = s4;
	s4 = 0x00000;
	*(s32*)(sp + 28) = s3;
	s3 = v1 | 0x1AF;
	*(s32*)(sp + 24) = s2;
	s2 = a0 | 0x321;
	*(s32*)(sp + 20) = s1;
	s1 = a1 | 0x4240;
	*(s32*)(sp + 16) = s0;
	s0 = a2 + 340;

loc_00000E38:		
	a0 = *(s32*)(s0 + 16);

loc_00000E3C:		
	a1 = 28672;
	a2 = 1;
	a3 = sp;
	t0 = sp + 4;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00000E38;
	a3 = v1 & 0x1000;
	t0 = v1 & 0x2000;
	if (a3 != 0)
		goto loc_00000F58;
	t1 = v1 & 0x4000;
	if (t0 != 0)
		goto loc_00000F38;
	if (t1 == 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_00000E3C;
	}
	a0 = s0 + 7;
	v0 = sub_0000389C(...);
	v1 = 1;
	if ((s32)v0 < 0)
		goto loc_00000EE4;
	t2 = *(u8*)(s0 + 6);
	if (t2 == v1)
	{
		t3 = *(u8*)(s0 + 7);
		goto loc_00000ED4;
	}
	v0 = *(u8*)(s0 + 7);
	if (v0 != v1)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_00000E3C;
	}
	a0 = s0;
	*(s8*)(s0 + 6) = v0;
	v0 = sub_00000F70(...);
	a0 = *(s32*)(s0 + 20);
	v0 = sceKernelCancelAlarm(...);
	t4 = 0x11E10000;
	a0 = t4 | 0xA300;
	a1 = s4 + 6344;
	a2 = s0;
	v0 = sceKernelSetAlarm(...);
	*(s32*)(s0 + 20) = v0;
	goto loc_00000E38;

loc_00000ED4:		
	if (t3 == 0)
	{
		*(s8*)(s0 + 6) = 0;
		goto loc_00000E38;
	}
	a0 = *(s32*)(s0 + 16);
	goto loc_00000E3C;

loc_00000EE4:		
	v1 = 0xF0000;
	if (v0 == s2)
		goto loc_00000EFC;
	a0 = v1 | 0x4240;
	v0 = sceKernelDelayThread(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_00000E3C;

loc_00000EFC:		
	v0 = 0x160000;
	a0 = v0 | 0xE360;
	v0 = sceKernelDelayThread(...);
	a0 = *(s32*)(s0 + 16);
	a1 = 8192;
	a2 = 1;
	a3 = 0;
	v0 = sceKernelPollEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	if (v0 != s3)
		goto loc_00000E3C;
	a1 = 8192;

loc_00000F28:		
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_00000E3C;

loc_00000F38:		
	a0 = *(s32*)(s0 + 16);
	a1 = -8193;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	a1 = -16385;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_00000E3C;

loc_00000F58:		
	a0 = *(s32*)(s0 + 16);
	a1 = -4097;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	a1 = 16384;
	goto loc_00000F28;
}

sub_00000F70(...) // at 0x00000F70 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	a1 = 1;
	a0 = *(s32*)(s0 + 16);
	a2 = 1;
	a3 = sp;
	s1 = v0;
	v0 = sceKernelPollEventFlag(...);
	a1 = 0x80020000;
	a0 = a1 | 0x1AF;
	a1 = 1;
	if (v0 == a0)
		goto loc_00000FD0;

loc_00000FB4:
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00000FD0:
	a0 = *(s32*)(s0 + 16);
	v0 = sceKernelSetEventFlag(...);
	goto loc_00000FB4;
}
{
	sp = sp - 80;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 48) = s4;
	s4 = 0x00000;
	*(s32*)(sp + 64) = fp;
	fp = 4;
	*(s32*)(sp + 60) = s7;
	s7 = 1;
	*(s32*)(sp + 56) = s6;
	s6 = 3;
	*(s32*)(sp + 52) = s5;
	s5 = 2;
	*(s32*)(sp + 44) = s3;
	s3 = s4 + 340;

loc_00001024:		
	*(s32*)(sp + 8) = 0;

loc_00001028:		
	*(s32*)(sp + 4) = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = sp;
	s0 = v0;
	v0 = sub_00002B04(...);
	a0 = *(s32*)(s3 + 7964);
	v0 = *(s32*)(s3 + 7960);
	cond = (a0 == v0);
	a0 = s0;
	if (cond)
		goto loc_000014D0;
	*(s32*)(s3 + 7964) = v0;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = sub_00003420(...);
	a0 = *(s32*)(s3 + 16);
	a1 = 8192;
	v0 = sceKernelSetEventFlag(...);
	v0 = 0x00000;
	s0 = v0 + 340;
	a0 = *(s32*)(s0 + 16);

loc_00001078:		
	a1 = 16384;
	a2 = 1;
	a3 = sp + 4;
	v0 = sceKernelPollEventFlag(...);
	a0 = s0 + 44;
	if (v0 != 0)
		goto loc_000010CC;
	a1 = *(s32*)(sp + 4);
	v1 = a1 & 0x10;
	if (v1 != 0)
		goto loc_000010B0;

loc_000010A0:		
	a0 = 1000;
	v0 = sceKernelDelayThread(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_00001078;

loc_000010B0:		
	v0 = sub_00001674(...);
	a0 = *(s32*)(s0 + 16);
	a1 = -17;
	v0 = sceKernelClearEventFlag(...);
	goto loc_000010A0;

loc_000010CC:		
	a0 = *(s32*)(s0 + 16);
	a1 = -8193;
	v0 = sceKernelClearEventFlag(...);
	a0 = sp + 8;
	v0 = sub_00004E9C(...);
	a3 = *(s32*)(sp + 8);
	a0 = 544;
	a2 = a3 & 0x220;
	t0 = 0x00000;
	if (a2 == a0)
		goto loc_000014C4;
	*(s32*)(t0 + 340) = s7;
	s0 = s4 + 340;

loc_000010FC:		
	a0 = *(s32*)(s0 + 12);
	a1 = 0;
	a2 = 0;
	v0 = sceKernelCancelEventFlag(...);
	a0 = *(s32*)(s0 + 20);
	if ((s32)a0 < 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_0000112C;
	}
	v0 = sceKernelCancelAlarm(...);
	t1 = -1;
	*(s32*)(s0 + 20) = t1;
	a0 = *(s32*)(s0 + 16);

loc_0000112C:		
	t2 = 0xFFFE0000;
	a1 = t2 | 0xF0F0;
	v0 = sceKernelClearEventFlag(...);
	a0 = 3;
	a1 = 0;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	t1 = 0;
	v0 = scePowerSetIdleCallback(...);

loc_00001154:		
	t3 = *(s32*)(s4 + 340);
	s1 = 1;
	s0 = 0x00000;
	s2 = s4 + 340;
	if (t3 == s1)
		goto loc_000014B0;
	t5 = *(s32*)(s0 + 340);
	if (t5 == s5)
	{
		s1 = 0x80240000;
		goto loc_0000143C;
	}
	a0 = *(s32*)(s0 + 340);
	if (a0 == s6)
		goto loc_00001384;
	t8 = *(s32*)(s0 + 340);
	if (t8 == fp)
	{
		a0 = *(s32*)(s2 + 16);
		goto loc_000011A4;
	}

loc_0000118C:		
	t9 = 0xF0000;

loc_00001190:		
	a0 = t9 | 0x4240;

loc_00001194:		
	v0 = sceKernelDelayThread(...);
	*(s32*)(sp + 8) = 0;
	goto loc_00001028;

loc_000011A4:		
	a1 = 0xF0000;
	a2 = 0x10000;
	v1 = a1 | 0x4240;
	a3 = sp + 16;
	a1 = a2 | 0xF1F;
	t0 = sp + 20;
	a2 = 1;
	*(s32*)(sp + 20) = v1;
	*(s32*)(sp + 16) = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = *(s32*)(sp + 16);
	if ((s32)v0 < 0)
		goto loc_0000118C;
	a0 = v1 & 0x100;
	t6 = v1 & 0x200;
	if (a0 == 0)
		goto loc_000012F4;
	t3 = *(s32*)(s2 + 7972);
	a3 = *(s32*)(s2 + 7968);
	s0 = t3 ^ 0xA;
	t2 = t3 ^ 0x3;
	t1 = (u32)t2 < (u32)1;
	t0 = (u32)s0 < (u32)1;
	s0 = t1 | t0;
	if (a3 == s0)
	{
		a0 = *(s32*)(s3 + 16);
		goto loc_00001220;
	}
	a0 = s0;
	v0 = sub_0000369C(...);
	t4 = -2;
	a0 = 1000;
	if (v0 == t4)
		goto loc_00001194;
	*(s32*)(s2 + 7968) = s0;
	a0 = *(s32*)(s3 + 16);

loc_00001220:		
	a1 = -257;

loc_00001224:		
	v0 = sceKernelClearEventFlag(...);
	v1 = *(s32*)(sp + 16);
	a3 = v1 & 0x10;

loc_00001234:		
	if (a3 != 0)
		goto loc_000012D0;
	s0 = 0x10000;

loc_00001240:		
	t1 = s0 | 0xE;
	t0 = v1 & t1;
	t7 = v1 & 0xC00;
	if (t0 == 0)
		goto loc_000012A4;
	t2 = v1 & 0x2;
	a0 = 0;
	if (t2 != 0)
		goto loc_00001278;
	t3 = v1 & 0x4;
	a0 = 1;
	if (t3 != 0)
		goto loc_00001278;
	v0 = v1 & 0x8;
	a0 = 2;
	t4 = 3;
	if (v0 == 0)
		a0 = t4;

loc_00001278:		
	v0 = sub_00003590(...);
	t5 = -2;
	a0 = 1000;
	if (v0 == t5)
		goto loc_00001194;
	a0 = *(s32*)(s3 + 16);
	s2 = 0xFFFE0000;
	a1 = s2 | 0xFFF1;
	v0 = sceKernelClearEventFlag(...);
	v1 = *(s32*)(sp + 16);
	t7 = v1 & 0xC00;

loc_000012A4:		
	t9 = 0xF0000;
	if (t7 == 0)
		goto loc_00001190;
	a0 = (v1 >> 10) & (0xFFFFFFFF >> (32 - 1));;
	v0 = sub_00004F04(...);
	a0 = 1000;
	if ((s32)v0 < 0)
		goto loc_00001194;
	a0 = *(s32*)(s3 + 16);
	a1 = -3073;
	v0 = sceKernelClearEventFlag(...);
	t9 = 0xF0000;
	goto loc_00001190;

loc_000012D0:		
	a0 = 0x00000;
	a0 = a0 + 384;
	s0 = 0x10000;
	v0 = sub_00001674(...);
	a0 = *(s32*)(s3 + 16);
	a1 = -17;
	v0 = sceKernelClearEventFlag(...);
	v1 = *(s32*)(sp + 16);
	goto loc_00001240;

loc_000012F4:		
	a1 = v1 & 0x1;
	if (t6 == 0)
		goto loc_0000134C;
	v0 = *(s32*)(s2 + 7972);
	s0 = 1;
	if (v0 == s1)
		goto loc_00001318;
	t7 = v0 - 2;
	s2 = (u32)t7 < (u32)2;
	s0 = 10;
	if (s2 == 0)
		s0 = 0;

loc_00001318:		
	s1 = s4 + 340;
	t8 = *(s32*)(s1 + 7968);
	if (t8 == s0)
	{
		a0 = *(s32*)(s3 + 16);
		goto loc_00001344;
	}
	a0 = s0;
	v0 = sub_0000369C(...);
	t9 = -2;
	if (v0 == t9)
	{
		a0 = 1000;
		goto loc_00001194;
	}
	*(s32*)(s1 + 7968) = s0;
	a0 = *(s32*)(s3 + 16);

loc_00001344:		
	a1 = -513;
	goto loc_00001224;

loc_0000134C:		
	a3 = v1 & 0x10;
	if (a1 == 0)
		goto loc_00001234;
	v1 = *(u8*)(s2 + 6);
	if (v1 == s1)
		goto loc_0000136C;
	a0 = *(s32*)(s3 + 16);

loc_00001364:		
	a1 = -2;
	goto loc_00001224;

loc_0000136C:		
	s1 = -2;
	v0 = sub_00003A5C(...);
	if (v0 != s1)
	{
		a0 = *(s32*)(s3 + 16);
		goto loc_00001364;
	}
	a0 = 1000;
	goto loc_00001194;

loc_00001384:		
	v0 = sub_000037AC(...);
	t0 = 0x11E10000;
	if ((s32)v0 < 0)
		goto loc_00001024;
	a3 = 0x00000;
	a0 = t0 | 0xA300;
	a1 = a3 + 6344;
	a2 = s2;
	*(s32*)(s0 + 340) = fp;
	v0 = sceKernelSetAlarm(...);
	s0 = *(s32*)(s2 + 7972);
	*(s32*)(s2 + 20) = v0;
	if (s0 != 0)
		goto loc_000013E8;
	s0 = s4 + 340;

loc_000013BC:		
	s1 = *(u8*)(s0 + 7980);
	a0 = *(s32*)(s0 + 16);
	if (s1 == s7)
		goto loc_000013D8;

loc_000013C8:		
	a1 = 4096;
	v0 = sceKernelSetEventFlag(...);
	t9 = 0xF0000;
	goto loc_00001190;

loc_000013D8:		
	a1 = 1024;
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 16);
	goto loc_000013C8;

loc_000013E8:		
	a2 = *(s32*)(s2 + 7976);
	t7 = 0x00000;
	t1 = s2;
	a3 = 0;
	a0 = 3;
	a1 = 256;
	t0 = t7 + 7292;
	v0 = scePowerSetIdleCallback(...);
	t6 = *(s32*)(s2 + 7972);
	t4 = t6 ^ 0xA;
	t5 = t6 ^ 0x3;
	t2 = (u32)t5 < (u32)1;
	t3 = (u32)t4 < (u32)1;
	t1 = t2 | t3;
	if (t1 == 0)
	{
		s0 = s4 + 340;
		goto loc_000013BC;
	}
	a0 = *(s32*)(s2 + 16);
	a1 = 256;
	v0 = sceKernelSetEventFlag(...);
	s0 = s4 + 340;
	goto loc_000013BC;

loc_0000143C:		
	*(s32*)(sp + 12) = 0;
	v0 = sceUsbAccGetAuthStat(...);
	t6 = s1 | 0x3701;
	t9 = 0xF0000;
	if (v0 == t6)
		goto loc_00001190;
	a0 = sp + 12;
	v0 = sub_00002AF0(...);
	cond = ((s32)v0 < 0);
	v0 = *(u8*)(sp + 13);
	if (cond)
		goto loc_0000118C;
	t9 = 16;
	cond = (v0 != t9);
	t9 = 0xF0000;
	if (cond)
		goto loc_00001190;
	v1 = *(s32*)(s2 + 44);
	s1 = s2 + 44;
	if (v1 == 0)
		goto loc_000014A0;

loc_00001478:		
	a0 = s1;
	v0 = sub_000032F4(...);
	t9 = 0xF0000;
	if ((s32)v0 < 0)
		goto loc_00001190;
	v0 = sub_00003490(...);
	if ((s32)v0 >= 0)
	{
		*(s32*)(s0 + 340) = s6;
		goto loc_0000118C;
	}
	t9 = 0xF0000;
	goto loc_00001190;

loc_000014A0:		
	a0 = s1;
	v0 = sub_00001690(...);
	goto loc_00001478;

loc_000014B0:		
	t4 = *(s32*)(sp + 0);
	if (t4 == s1)
	{
		*(s32*)(s4 + 340) = s5;
		goto loc_0000118C;
	}
	t9 = 0xF0000;
	goto loc_00001190;

loc_000014C4:		
	*(s32*)(s4 + 340) = s5;
	s0 = s4 + 340;
	goto loc_000010FC;

loc_000014D0:		
	a0 = s0;
	v0 = sceKernelCpuResumeIntr(...);
	goto loc_00001154;
}

sub_000014E0(...) // at 0x000014E0 
{
	s2 = a0;
	v0 = *(s32*)(a0 + 0);
	a0 = 2;
	s4 = 0;
	if (v0 == a0)
		goto loc_00001534;

loc_00001510:		
	v0 = s4;

loc_00001514:		
	ra = *(s32*)(sp + 52);

loc_00001518:
	return (v0);

loc_00001534:		
	t8 = 0x00000;
	if (a1 != 0)
		goto loc_000015F0;
	s1 = 0x00000;
	s0 = s1 + 368;
	a2 = 0;
	a3 = 0;
	a0 = s0;
	*(s32*)(sp + 0) = a2;
	*(s32*)(sp + 4) = a3;
	*(s32*)(sp + 8) = a2;
	*(s32*)(sp + 12) = a3;
	*(s32*)(sp + 16) = a2;
	*(s32*)(sp + 20) = a3;
	a1 = sp;
	v0 = sceRtcGetTick(...);
	a0 = s2 + 8;
	a1 = sp + 8;
	v0 = sceRtcGetTick(...);
	t0 = *(s32*)(sp + 0);
	t1 = *(s32*)(sp + 4);
	a0 = sp + 16;
	asm("negu       $a2, $t0");
	asm("negu       $a3, $t1");
	v0 = (u32)0 < (u32)a2;
	a3 = a3 - v0;
	a1 = sp + 8;
	v0 = sceRtcTickAddTicks(...);
	v0 = *(s32*)(sp + 20);

	if (!v0)
	{
		cond = (v0 != 0);
		v0 = s4;
		if (cond)
			goto loc_00001514;
		a3 = *(s32*)(sp + 16);
		v1 = 0x11E10000;
		a1 = v1 | 0xA300;
		a0 = (u32)a1 < (u32)a3;
		ra = *(s32*)(sp + 52);
		if (a0 == 0)
			goto loc_00001518;
	}
	t4 = *(s32*)(s2 + 8);

loc_000015D0:		
	*(s32*)(s1 + 368) = t4;
	t3 = *(s32*)(s2 + 12);
	*(s32*)(s0 + 4) = t3;
	t2 = *(s32*)(s2 + 16);
	*(s32*)(s0 + 8) = t2;
	t1 = *(s32*)(s2 + 20);
	*(s32*)(s0 + 12) = t1;
	t8 = 0x00000;

loc_000015F0:		
	s1 = t8 + 340;
	//s3 = *(s32*)(s1 + 2964);
	s0 = 0x00000;
	t5 = 0x00000 + *(s32*)(s1 + 2964) << 2;
	v0 = sceIoOpen(*(s32*)(t5 + 0), 514, 511);
	cond = ((s32)v0 < 0);
	s3 = v0;
	if (cond)
		goto loc_00001510;
	s1 = s1 + 2968;
	v0 = sub_00001A28(s2,s1,4992);
	s0 = v0;
	v0 = sceIoWrite(s3,s1,v0);
	s1 = 1;
	if (v0 == s0)
	{
		*(s32*)(s2 + 0) = s1;
	}
	else
	{
		s4 = -1;
	}
	if ((s32)s3 < 0)
	{
		v0 = s4;
		goto loc_00001514;
	}
	v0 = sceIoClose(s3);
	v0 = s4;
	goto loc_00001514;
}

sub_00001674(...) // at 0x00001674 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 0;
	v0 = sub_000014E0(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00001690(...) // at 0x00001690 
{
	sp = sp - 48;
	v1 = 0x00000;
	*(s32*)(sp + 20) = s5;
	s5 = v1 + 340;
	a1 = 0x00000;
	v0 = *(s32*)(s5 + 2964);
	*(s32*)(sp + 24) = s6;
	a3 = a1 + 0;
	a2 = v0 << 2;
	*(s32*)(sp + 16) = s4;
	a1 = a2 + a3;
	s6 = a0;
	*(s32*)(sp + 8) = s2;
	a2 = 0;
	s4 = 0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s7;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	a0 = *(s32*)(a1 + 0);
	a1 = 1;
	v0 = sceIoOpen(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_00001744;
	a0 = v0;
	a2 = 0;
	a3 = 0;
	t0 = 2;
	v0 = sceIoLseek(...);
	a0 = s2;
	a2 = 0;
	a3 = 0;
	t0 = 0;
	s0 = v0;
	v0 = sceIoLseek(...);
	a0 = (u32)s0 < (u32)4993;
	if ((s32)v0 < 0)
		goto loc_00001730;
	s7 = s5 + 2968;
	if (a0 != 0)
		goto loc_00001774;

loc_00001730:		
	s4 = -1;

loc_00001734:		
	v0 = s4;
	if ((s32)s2 < 0)
		goto loc_00001748;
	a0 = s2;
	v0 = sceIoClose(...);

loc_00001744:		
	v0 = s4;

loc_00001748:		
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

loc_00001774:		
	a2 = s0;
	a0 = s2;
	a1 = s7;
	v0 = sceIoRead(...);
	if (v0 != s0)
	{
		s4 = -1;
		goto loc_00001734;
	}
	a0 = s7;
	a1 = v0;
	a2 = s6;
	v0 = sub_00001910(...);
	t1 = s5 + 28;
	if ((s32)v0 < 0)
		goto loc_00001730;
	t5 = *(s32*)(s6 + 8);
	t0 = 1;
	*(s32*)(s5 + 28) = t5;
	t4 = *(s32*)(s6 + 12);
	*(s32*)(t1 + 4) = t4;
	t3 = *(s32*)(s6 + 16);
	*(s32*)(t1 + 8) = t3;
	t2 = *(s32*)(s6 + 20);
	*(s32*)(t1 + 12) = t2;
	*(s32*)(s6 + 0) = t0;
	goto loc_00001734;
}

module_stop(...) // at 0x000017D0 
{
	v0 = sub_00002A6C(...);
	s0 = (s32)v0 < 0;
	v0 = sub_00001674(0x00000 + 384);
	v0 = sceKernelUnregisterSysEventHandler(0x00000 + 16);
	return (s0);
}

syslib_ADF12745(a0) // at 0x00001814 
{
	if (a0 == 2){
		sub_00001674(0x00000 + 384, 2);
	}
	return (0);
}

sceUsbGpsReset(a0) // at 0x00001850 
{
	s2 = k1;
	k1 = k1 << 11;
	s1 = 0x80244007;
	if (a0 < 4)
	{
		curIntrState = sceKernelCpuSuspendIntr();
		s1 = sub_00001CA8(a0);
		sceKernelCpuResumeIntr(curIntrState);
	}
	k1 = s2;
	return (s1);
}

{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00000F70(...);
	v1 = 0x11E10000;
	ra = *(s32*)(sp + 0);
	v0 = v1 | 0xA300;
	sp = sp + 16;
	return (v0);
	v1 = 1;
	if (a0 == v1)
		goto loc_00001900;

loc_000018F8:		
	return (v0);

loc_00001900:		
	a0 = *(s32*)(a1 + 7964);
	v1 = a0 + 1;
	*(s32*)(a1 + 7964) = v1;
	goto loc_000018F8;
}

sub_00001910(...) // at 0x00001910 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	*(s32*)(sp + 20) = s1;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	s0 = a0 + 36;
	v0 = sub_00001DC0(...);
	s3 = v0;
	a0 = s1 + 40;
	a1 = s0;
	if ((s32)v0 < 0)
		goto loc_00001A20;
	asm("lwl        $v0, 15($s2)");
	asm("lwr        $v0, 12($s2)");
	asm("lwl        $v1, 19($s2)");
	asm("lwr        $v1, 16($s2)");
	asm("lwl        $a2, 23($s2)");
	asm("lwr        $a2, 20($s2)");
	asm("swl        $v0, 11($s1)");
	asm("swr        $v0, 8($s1)");
	asm("swl        $v1, 15($s1)");
	asm("swr        $v1, 12($s1)");
	asm("swl        $a2, 19($s1)");
	asm("swr        $a2, 16($s1)");
	asm("lwl        $v0, 27($s2)");
	asm("lwr        $v0, 24($s2)");
	asm("swl        $v0, 7($s1)");
	asm("swr        $v0, 4($s1)");
	asm("lwl        $v0, 35($s2)");
	asm("lwr        $v0, 32($s2)");
	asm("swl        $v0, 39($s1)");
	asm("swr        $v0, 36($s1)");
	a2 = *(s32*)(s1 + 36);
	v0 = memcpy(...);
	t1 = *(s32*)(s1 + 36);
	t0 = s0 + t1;
	a3 = t0 + 4;
	asm("lwl        $v0, 3($a3)");
	asm("lwr        $v0, 0($a3)");
	asm("swl        $v0, 3($sp)");
	asm("swr        $v0, 0($sp)");
	a1 = a3 + 4;
	a2 = *(s32*)(sp + 0);
	v1 = a1 + a2;
	a0 = v1 + 8;
	asm("lwl        $a2, 3($a0)");
	asm("lwr        $a2, 0($a0)");
	asm("swl        $a2, 27($s1)");
	asm("swr        $a2, 24($s1)");
	t0 = a0 + 4;
	asm("lwl        $a0, 3($t0)");
	asm("lwr        $a0, 0($t0)");
	asm("swl        $a0, 31($s1)");
	asm("swr        $a0, 28($s1)");
	asm("lwl        $v0, 7($t0)");
	asm("lwr        $v0, 4($t0)");
	asm("swl        $v0, 35($s1)");
	asm("swr        $v0, 32($s1)");

loc_00001A00:		
	v0 = s3;
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00001A20:		
	s3 = -1;
	goto loc_00001A00;
}

sub_00001A28(...) // at 0x00001A28 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	t2 = 71;
	t4 = 83;
	*(s32*)(sp + 20) = s5;
	s5 = 80;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	s3 = a2 - 64;
	a2 = 1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = *(s32*)(a0 + 36);
	a0 = 73;
	*(s8*)(s0 + 0) = t2;
	t5 = s2 + 52;
	t6 = (u32)t5 >> 24;
	a1 = (t5 >> 8) & (0xFFFFFFFF >> (32 - 8));;
	t7 = (t5 >> 16) & (0xFFFFFFFF >> (32 - 8));;
	*(s8*)(s0 + 1) = s5;
	s4 = (u32)s3 < (u32)s2;
	s5 = s2 + 64;
	*(s8*)(s0 + 2) = t4;
	if (s4 != 0)
		s2 = s3;
	t1 = (s2 >> 8) & (0xFFFFFFFF >> (32 - 8));;
	*(s8*)(s0 + 3) = a0;
	s3 = 101;
	t2 = (s2 >> 16) & (0xFFFFFFFF >> (32 - 8));;
	*(s8*)(s0 + 4) = a2;
	t4 = (u32)s2 >> 24;
	s4 = 109;
	*(s8*)(s0 + 9) = a1;
	a0 = s0 + 36;
	a1 = s1 + 40;
	*(s8*)(s0 + 8) = t5;
	a2 = s2;
	*(s8*)(s0 + 10) = t7;
	*(s8*)(s0 + 11) = t6;
	*(s8*)(s0 + 5) = 0;
	*(s8*)(s0 + 6) = 0;
	*(s8*)(s0 + 7) = 0;

	*(s8*)(s0 + 12) = *(u8*)(s1 + 8);
	a3 = *(u16*)(s1 + 8);
	v1 = (u32)a3 >> 8;
	*(s8*)(s0 + 13) = v1;
	t0 = *(u8*)(s1 + 10);
	*(s8*)(s0 + 14) = t0;
	t9 = *(u16*)(s1 + 10);
	t8 = (u32)t9 >> 8;
	*(s8*)(s0 + 15) = t8;
	t7 = *(u8*)(s1 + 12);
	*(s8*)(s0 + 16) = t7;
	t6 = *(u16*)(s1 + 12);
	t5 = (u32)t6 >> 8;
	*(s8*)(s0 + 17) = t5;
	v0 = *(u8*)(s1 + 14);
	*(s8*)(s0 + 18) = v0;
	t3 = *(u16*)(s1 + 14);
	a3 = (u32)t3 >> 8;
	*(s8*)(s0 + 19) = a3;
	a3 = 112;
	t0 = *(u8*)(s1 + 16);
	*(s8*)(s0 + 20) = t0;
	v1 = *(u16*)(s1 + 16);
	t9 = (u32)v1 >> 8;
	*(s8*)(s0 + 21) = t9;
	v1 = 104;
	t8 = *(u8*)(s1 + 18);
	*(s8*)(s0 + 22) = t8;
	t7 = *(u16*)(s1 + 18);
	t6 = (u32)t7 >> 8;
	*(s8*)(s0 + 23) = t6;
	t5 = *(u8*)(s1 + 4);
	*(s8*)(s0 + 24) = *(u8*)(s1 + 4);
	*(s8*)(s0 + 25) = *(u8*)(s1 + 5);
	*(s8*)(s0 + 26) = *(u8*)(s1 + 6);
	*(s8*)(s0 + 29) = a3;
	*(s8*)(s0 + 27) = *(u8*)(s1 + 7);
	*(s8*)(s0 + 30) = v1;
	*(s8*)(s0 + 33) = t1;
	*(s8*)(s0 + 34) = t2;
	*(s8*)(s0 + 35) = t4;
	*(s8*)(s0 + 28) = s3;
	*(s8*)(s0 + 31) = s4;
	*(s8*)(s0 + 32) = s2;
	v0 = memcpy(...);
	a2 = s0 + s2;

	*(s8*)(a2 + 38) = s4;
	*(s8*)(a2 + 39) = 97;
	*(s8*)(a2 + 46) = s3;
	*(s8*)(a2 + 47) = 102;
	*(s8*)(a2 + 48) = 12;
	*(s8*)(a2 + 36) = 97;
	*(s8*)(a2 + 44) = s3;
	*(s8*)(a2 + 37) = 108;
	*(s8*)(a2 + 45) = 99;
	*(s8*)(a2 + 40) = 0;
	*(s8*)(a2 + 41) = 0;
	*(s8*)(a2 + 42) = 0;
	*(s8*)(a2 + 43) = 0;
	*(s8*)(a2 + 49) = 0;
	*(s8*)(a2 + 50) = 0;
	*(s8*)(a2 + 51) = 0;

	*(s8*)(a2 + 52) = *(u8*)(s1 + 24);
	*(s8*)(a2 + 53) = *(u8*)(s1 + 25);
	*(s8*)(a2 + 54) = *(u8*)(s1 + 26);
	*(s8*)(a2 + 55) = *(u8*)(s1 + 27);
	*(s8*)(a2 + 56) = *(u8*)(s1 + 28);
	*(s8*)(a2 + 57) = *(u8*)(s1 + 29);
	*(s8*)(a2 + 58) = *(u8*)(s1 + 30);
	*(s8*)(a2 + 59) = *(u8*)(s1 + 31);
	*(s8*)(a2 + 60) = *(u8*)(s1 + 32);
	*(s8*)(a2 + 61) = *(u8*)(s1 + 33);
	*(s8*)(a2 + 62) = *(u8*)(s1 + 34);
	*(s8*)(a2 + 63) = *(u8*)(s1 + 35);
	return (s5);
}
{
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = a1;
	a1 = 256;
	a0 = *(s32*)(a2 + 16);
	a2 = 512;
	if (v0 != 0)
		a1 = a2;
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00001CA8(...) // at 0x00001CA8 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	a1 = 0x00000;
	s2 = a0;
	*(s32*)(sp + 20) = s1;
	a0 = 4;
	s1 = a1 + 340;
	*(s32*)(sp + 16) = s0;
	s0 = 0;
	*(s32*)(sp + 28) = ra;
	v0 = *(s32*)(a1 + 340);
	*(s32*)(sp + 0) = 0;
	if (v0 == a0)
		goto loc_00001D5C;
	v1 = *(s32*)(a1 + 340);
	a0 = 1;
	a1 = 0x80240000;
	s0 = a1 | 0x4004;
	if (v1 == a0)
		goto loc_00001D14;
	a2 = 0x80240000;
	s0 = a2 | 0x4002;
	if (v1 == 0)
		goto loc_00001D14;
	a3 = 2;
	t0 = 3;
	if (v1 == a3)
		goto loc_00001D3C;
	t4 = 0x80240000;
	if (v1 == t0)
		goto loc_00001D30;
	s0 = t4 | 0x4010;

loc_00001D14:		
	v0 = s0;

loc_00001D18:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00001D30:		
	t3 = 0x80240000;
	s0 = t3 | 0x4005;
	goto loc_00001D14;

loc_00001D3C:		
	v0 = sceUsbAccGetAuthStat(...);
	v1 = 0x80240000;
	t1 = v1 | 0x3701;
	s0 = t1;
	if (v0 != t1)
		goto loc_00001D30;
	v0 = s0;
	goto loc_00001D18;

loc_00001D5C:		
	a0 = *(s32*)(s1 + 16);
	t6 = 0x10000;
	a1 = t6 | 0xE;
	a2 = 1;
	a3 = sp;
	v0 = sceKernelPollEventFlag(...);
	if (v0 == 0)
	{
		a0 = *(s32*)(s1 + 16);
		goto loc_00001DA4;
	}

loc_00001D7C:		
	a1 = 0x00000;
	a0 = s2 << 2;
	v0 = a1 + 22192;
	t9 = a0 + v0;
	a1 = *(s32*)(t9 + 0);
	a0 = *(s32*)(s1 + 16);
	v0 = sceKernelSetEventFlag(...);
	s2 = (s32)v0 < (s32)0;
	if (s2 != 0)
		s0 = v0;
	goto loc_00001D14;

loc_00001DA4:		
	s0 = 0xFFFE0000;
	a1 = s0 | 0xFFF1;
	v0 = sceKernelClearEventFlag(...);
	t7 = (s32)v0 < (s32)0;
	s0 = v0;
	if (t7 == 0)
		s0 = 0;
	goto loc_00001D7C;
}

sub_00001DC0(...) // at 0x00001DC0 
{
	sp = sp - 144;
	*(s32*)(sp + 120) = s2;
	s2 = a1;
	a1 = a1 - 52;
	v1 = (u32)a1 < (u32)4941;
	*(s32*)(sp + 124) = s3;
	s3 = 0;
	*(s32*)(sp + 112) = s0;
	s0 = a0;
	*(s32*)(sp + 128) = ra;
	*(s32*)(sp + 116) = s1;
	if (v1 != 0)
		goto loc_00001E14;

loc_00001DF0:
	s3 = -1;

loc_00001DF4:
	v0 = s3;

loc_00001DF8:
	return (v0);

loc_00001E14:
	*(s32*)(sp + 0) = 0;
	v0 = 0x00000;
	a1 = v0 + 22096;
	a0 = sp;
	a2 = 4;
	asm("lwl        $v0, 3($s0)");
	asm("lwr        $v0, 0($s0)");
	asm("swl        $v0, 3($sp)");
	asm("swr        $v0, 0($sp)");
	*(s8*)(sp + 4) = 0;
	v0 = strncmp(...);
	if (v0 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	asm("lwl        $v0, 7($s0)");
	asm("lwr        $v0, 4($s0)");
	asm("swl        $v0, 83($sp)");
	asm("swr        $v0, 80($sp)");
	a0 = 1;
	a2 = *(s32*)(sp + 80);
	s1 = s0 + 4;
	if (a2 != a0)
		goto loc_00001DF0;
	s1 = s1 + 4;
	asm("lwl        $a2, 3($s1)");
	asm("lwr        $a2, 0($s1)");
	asm("swl        $a2, 87($sp)");
	asm("swr        $a2, 84($sp)");
	a3 = *(s32*)(sp + 84);
	v1 = (s32)a3 < (s32)4981;
	if (v1 == 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	*(s32*)(sp + 64) = 0;
	s1 = s1 + 4;
	a0 = sp + 64;
	*(s32*)(sp + 68) = 0;
	*(s32*)(sp + 72) = 0;
	asm("lwl        $v1, 3($s1)");
	asm("lwr        $v1, 0($s1)");
	asm("lwl        $a1, 7($s1)");
	asm("lwr        $a1, 4($s1)");
	asm("lwl        $a2, 11($s1)");
	asm("lwr        $a2, 8($s1)");
	asm("swl        $v1, 67($sp)");
	asm("swr        $v1, 64($sp)");
	asm("swl        $a1, 71($sp)");
	asm("swr        $a1, 68($sp)");
	asm("swl        $a2, 75($sp)");
	asm("swr        $a2, 72($sp)");
	*(s32*)(sp + 76) = 0;
	v0 = sceRtcCheckValid(...);
	s1 = s1 + 12;
	if ((s32)v0 < 0)
		goto loc_00001DF0;
	asm("lwl        $t0, 3($s1)");
	asm("lwr        $t0, 0($s1)");
	asm("swl        $t0, 91($sp)");
	asm("swr        $t0, 88($sp)");
	t0 = 4096;
	t1 = *(s32*)(sp + 88);
	if (t1 != t0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	*(s32*)(sp + 16) = 0;
	t2 = 0x00000;
	s1 = s1 + 4;
	a0 = sp + 16;
	a1 = t2 + 22104;
	a2 = 4;
	asm("lwl        $a3, 3($s1)");
	asm("lwr        $a3, 0($s1)");
	asm("swl        $a3, 19($sp)");
	asm("swr        $a3, 16($sp)");
	*(s8*)(sp + 20) = 0;
	v0 = strncmp(...);
	if (v0 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	s1 = s1 + 4;
	asm("lwl        $a0, 3($s1)");
	asm("lwr        $a0, 0($s1)");
	asm("swl        $a0, 95($sp)");
	asm("swr        $a0, 92($sp)");
	v1 = *(s32*)(sp + 92);
	t3 = (s32)v1 < (s32)2881;
	if (t3 == 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	t5 = v1 + 52;
	t4 = (u32)s2 < (u32)t5;
	if (t4 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	*(s32*)(sp + 32) = 0;
	t7 = s1 + 4;
	t6 = 0x00000;
	s1 = t7 + v1;
	a0 = sp + 32;
	a1 = t6 + 22112;
	a2 = 4;
	asm("lwl        $t0, 3($s1)");
	asm("lwr        $t0, 0($s1)");
	asm("swl        $t0, 35($sp)");
	asm("swr        $t0, 32($sp)");
	*(s8*)(sp + 36) = 0;
	v0 = strncmp(...);
	if (v0 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	s1 = s1 + 4;
	asm("lwl        $t0, 3($s1)");
	asm("lwr        $t0, 0($s1)");
	asm("swl        $t0, 99($sp)");
	asm("swr        $t0, 96($sp)");
	v1 = *(s32*)(sp + 96);
	s0 = (s32)v1 < (s32)2881;
	if (s0 == 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	a0 = *(s32*)(sp + 92);
	a1 = a0 + v1;
	t9 = a1 + 52;
	t8 = (u32)s2 < (u32)t9;
	if (t8 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	*(s32*)(sp + 48) = 0;
	a2 = s1 + 4;
	v0 = 0x00000;
	s1 = a2 + v1;
	a1 = v0 + 22120;
	a0 = sp + 48;
	a2 = 4;
	asm("lwl        $a3, 3($s1)");
	asm("lwr        $a3, 0($s1)");
	asm("swl        $a3, 51($sp)");
	asm("swr        $a3, 48($sp)");
	*(s8*)(sp + 52) = 0;
	v0 = strncmp(...);
	if (v0 != 0)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	asm("lwl        $a0, 7($s1)");
	asm("lwr        $a0, 4($s1)");
	asm("swl        $a0, 103($sp)");
	asm("swr        $a0, 100($sp)");
	s1 = 12;
	a3 = *(s32*)(sp + 100);
	if (a3 != s1)
	{
		s3 = -1;
		goto loc_00001DF4;
	}
	t2 = *(s32*)(sp + 92);
	t3 = *(s32*)(sp + 96);
	t1 = t2 + t3;
	t0 = t1 + 64;
	v1 = (u32)s2 < (u32)t0;
	v0 = s3;
	if (v1 == 0)
		goto loc_00001DF8;
	s3 = -1;
	goto loc_00001DF4;
	sp = sp - 32;
	a0 = sp;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	v0 = sceUsbAccGetInfo(...);
	a1 = 0x00000;
	if ((s32)v0 < 0)
		goto loc_0000209C;
	a2 = *(u16*)(sp + 2);
	v1 = *(u16*)(sp + 4);
	a0 = (u32)a2 >> 8;
	a2 = a1 + 8324;
	*(s8*)(a2 + 177) = a0;
	*(s32*)(a2 + 180) = v1;

loc_0000209C:
	s0 = a1 + 8324;
	v0 = sceKernelCpuSuspendIntr(...);
	v1 = *(s32*)(s0 + 188);
	a1 = 1;
	s1 = v0;
	a0 = 0;
	*(s8*)(s0 + 176) = a1;
	if (v1 != 0)
		goto loc_000020E4;
	a0 = *(s32*)(s0 + 168);

loc_000020C0:
	a1 = -2;
	v0 = sceKernelClearEventFlag(...);
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_000020E4:
	a1 = *(s32*)(s0 + 192);
	v0 = $v1(...);
	a0 = *(s32*)(s0 + 168);
	goto loc_000020C0;
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 0) = s0;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	v1 = a0 + 208;
	s1 = v0;
	v0 = v1 + 8;
	v1 = 2;

loc_0000211C:
	v1 = v1 - 1;
	*(s32*)(v0 + 0) = 0;
	v0 = v0 + 12;
	if ((s32)v1 >= 0)
		goto loc_0000211C;
	v1 = 0x00000;
	s0 = v1 + 8324;
	v0 = *(s32*)(s0 + 188);
	*(s8*)(s0 + 176) = 0;
	*(s32*)(s0 + 180) = 0;
	*(s8*)(s0 + 177) = 0;
	if (v0 != 0)
		goto loc_00002170;
	a0 = *(s32*)(s0 + 168);

loc_0000214C:
	a1 = 1;
	v0 = sceKernelSetEventFlag(...);
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002170:
	a1 = *(s32*)(s0 + 192);
	a0 = 1;
	v0 = $v0(...);
	a0 = *(s32*)(s0 + 168);
	goto loc_0000214C;
}
{
	sp = sp - 48;
	v1 = 0x00000;
	*(s32*)(sp + 28) = s3;
	s3 = v1 + 22144;
	a0 = s3;
	*(s32*)(sp + 24) = s2;
	a1 = 1;
	s2 = 0x00000;
	a2 = 256;
	a3 = 2832;
	t0 = 1;
	t1 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = s2 + 8324;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelCreateFpl(...);
	v1 = -1;
	*(s32*)(s1 + 172) = v0;
	if ((s32)v0 < 0)
		goto loc_00002370;
	a0 = v0;
	a1 = sp;
	v0 = sceKernelTryAllocateFpl(...);
	t2 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00002398;
	v1 = 0x00000;
	s0 = v1 + 256;
	v0 = t2 + 2175;
	v0 = ((0 & (0xFFFFFFFF >> (32 - 6))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	t3 = v0 + 192;
	t4 = t3 + 192;
	t5 = t3 + 212;
	t8 = t2 + 1024;
	t7 = t2 + 2048;
	*(s32*)(s1 + 160) = t8;
	t6 = t3 + 228;
	a1 = t4;
	*(s32*)(s1 + 40) = t7;
	a2 = t5;
	a3 = t6;
	*(s32*)(s1 + 156) = t2;
	a0 = 2;
	*(s32*)(s1 + 128) = t3;
	*(s32*)(s0 + 16) = t4;
	*(s32*)(s0 + 20) = t5;
	*(s32*)(s1 + 84) = v0;
	*(s32*)(sp + 0) = t6;
	v0 = sub_00002E38(...);
	t0 = v0 + 20;
	*(s32*)(s0 + 28) = t0;
	t1 = v0 + 36;
	a2 = t0;
	*(s32*)(s0 + 24) = v0;
	a3 = t1;
	a1 = v0;
	a0 = 1;
	*(s32*)(sp + 0) = t1;
	v0 = sub_00002E38(...);
	a0 = s3;
	a1 = 513;
	a2 = 0;
	a3 = 0;
	*(s32*)(sp + 0) = v0;
	v0 = sceKernelCreateEventFlag(...);
	*(s32*)(s1 + 168) = v0;
	if ((s32)v0 < 0)
		goto loc_00002398;
	t3 = *(s32*)(s1 + 40);
	t4 = *(s32*)(s1 + 84);
	t6 = *(s32*)(s1 + 128);
	v0 = 0x00000;
	a2 = v0 + 220;
	t8 = 0x00000;
	t5 = 0x00000;
	t9 = 0x00000;
	a0 = s1 + 44;
	s0 = s1 + 88;
	s3 = 64;
	t1 = a2 + 12;
	t7 = t8 + 11232;
	t0 = t5 + 11304;
	a3 = t9 + 11524;
	*(s32*)(s1 + 4) = t3;
	t2 = 2;
	t3 = a2 - 4;
	*(s32*)(s1 + 16) = t7;
	*(s32*)(a0 + 24) = 0;
	*(s32*)(s0 + 8) = s3;
	*(s32*)(s0 + 32) = s1;
	*(s32*)(s1 + 12) = 0;
	*(s32*)(s1 + 28) = 0;
	*(s32*)(s1 + 20) = 0;
	*(s32*)(a0 + 4) = t4;
	*(s32*)(a0 + 16) = t0;
	*(s32*)(s1 + 88) = t1;
	*(s32*)(s0 + 24) = 0;
	*(s32*)(s2 + 8324) = 0;
	*(s32*)(s1 + 8) = s3;
	*(s32*)(s1 + 32) = s1;
	*(s32*)(a0 + 12) = 0;
	*(s32*)(a0 + 28) = 0;
	*(s32*)(a0 + 20) = 0;
	*(s32*)(s0 + 4) = t6;
	*(s32*)(s0 + 16) = a3;
	*(s32*)(s1 + 24) = 0;
	*(s32*)(s1 + 44) = a2;
	*(s32*)(a0 + 8) = s3;
	*(s32*)(a0 + 32) = s1;
	*(s32*)(s0 + 12) = 0;
	*(s32*)(s0 + 28) = 0;
	*(s32*)(s0 + 20) = 0;

loc_00002340:		
	t2 = t2 - 1;
	*(s32*)(t3 + 0) = 0;
	t3 = t3 + 12;
	if ((s32)t2 >= 0)
		goto loc_00002340;
	s0 = s2 + 8324;
	a1 = *(s32*)(s0 + 40);
	s1 = 4;
	a0 = 4;
	*(s16*)(a1 + 0) = s1;
	v0 = sceUsbAccRegisterType(...);
	v1 = 0;
	if ((s32)v0 < 0)
		goto loc_00002390;

loc_00002370:
	return (v1);

loc_00002390:		
	a0 = *(s32*)(s0 + 168);
	v0 = sceKernelDeleteEventFlag(...);

loc_00002398:		
	t2 = s2 + 8324;
	a0 = *(s32*)(t2 + 172);
	v0 = sceKernelDeleteFpl(...);
	v1 = -1;
	goto loc_00002370;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 4) = ra;
	a0 = 4;
	v0 = sceUsbAccUnregisterType(...);
	v0 = 0x00000;
	s0 = v0 + 8324;
	v1 = *(s32*)(s0 + 168);
	a0 = v1;
	if ((s32)v1 <= 0)
		goto loc_000023E0;
	v0 = sceKernelDeleteEventFlag(...);
	*(s32*)(s0 + 168) = 0;

loc_000023E0:		
	v1 = *(s32*)(s0 + 172);
	a0 = v1;
	if ((s32)v1 <= 0)
		goto loc_000023F4;
	v0 = sceKernelDeleteFpl(...);

loc_000023F4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00002408(...) // at 0x00002408 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	s2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	v1 = s1 + 8324;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 28) = ra;
	a1 = *(u8*)(v1 + 176);
	s0 = a0;
	if (a1 != 0)
		goto loc_00002454;
	s2 = -2;

loc_00002438:		
	v0 = s2;
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00002454:		
	v0 = a0 ^ 0x12C0;
	a3 = a0 ^ 0x2580;
	a1 = (u32)0 < (u32)v0;
	a2 = (u32)0 < (u32)a3;
	a0 = a1 & a2;
	t7 = 4800;
	if (a0 == 0)
		goto loc_000024A0;
	t4 = s0 ^ 0x9600;
	t3 = s0 ^ 0xE100;
	t1 = (u32)0 < (u32)t4;
	t2 = (u32)0 < (u32)t3;
	t0 = t1 & t2;
	t6 = 0x10000;
	if (t0 == 0)
		goto loc_000024A0;
	t5 = t6 | 0xC200;
	if (s0 == t5)
		goto loc_000024A0;

loc_00002498:		
	s2 = -1;
	goto loc_00002438;

loc_000024A0:		
	v0 = 6;
	if (s0 == t7)
		goto loc_000024D4;
	t8 = 9600;
	v0 = 7;
	if (s0 == t8)
		goto loc_000024D4;
	t9 = 0x9600;
	v0 = 10;
	if (s0 == t9)
		goto loc_000024D4;
	a0 = 0x10000;
	v1 = a0 | 0xC200;
	v0 = 12;
	if (s0 == v1)
		goto loc_000024D4;
	v0 = 11;

loc_000024D4:		
	a3 = 64;
	a0 = 4;
	a1 = sp;
	a2 = 8;
	*(s8*)(sp + 0) = v0;
	*(s8*)(sp + 7) = a3;
	*(s8*)(sp + 1) = 0;
	*(s8*)(sp + 2) = 0;
	*(s8*)(sp + 3) = 0;
	*(s8*)(sp + 4) = 0;
	*(s8*)(sp + 5) = 0;
	*(s8*)(sp + 6) = 0;
	v0 = sub_00002B48(...);
	a1 = 4800;
	if ((s32)v0 < 0)
		goto loc_00002498;
	a2 = 9600;
	if (s0 == a1)
		goto loc_00002534;
	t0 = 0x9600;
	if (s0 == a2)
		goto loc_00002534;
	v1 = s1 + 8324;
	v0 = 24000;
	if (s0 == t0)
		goto loc_00002534;

loc_0000252C:		
	*(s32*)(v1 + 184) = v0;
	goto loc_00002438;

loc_00002534:		
	s0 = 0x40000;
	v1 = s1 + 8324;
	v0 = s0 | 0xE200;
	goto loc_0000252C;
}

sub_00002544() // at 0x00002544 
{
	s1 = 0x00000 + 8324;
	v0 = -2;
	if (*(u8*)(s1 + 176))
	{
		v0 = sub_00002B48(1, 0, 0, *(u8*)(s1 + 176));
	
		s0 = 0x00000 + 220;
		a1 = v0;
		s2 = s0 + 12;
		v0 = -1;
		if (a1 >= 0)
		{
			v0 = sceUsbbdReqCancelAll(s0, a1);
			v0 = sceUsbbdClearFIFO(s0);
			v0 = sceUsbbdReqCancelAll(s2);
			v0 = sceUsbbdClearFIFO(s2);
			*(s32*)(s1 + 144) = 0;
			*(s32*)(s1 + 148) = 0;
			*(s32*)(s1 + 152) = 0;
			v0 = sceKernelDcacheInvalidateRange(*(s32*)(s1 + 48), 64);
			v0 = sceUsbbdReqRecv(s1 + 44);
			if (v0 >= 0)
			{
				v0 = sceKernelDcacheInvalidateRange(*(s32*)(s1 + 92), 64);
				v0 = sceUsbbdReqRecv(s1 + 88);
				v0 = (v0 < 0) ? v0 : 0;
			}
		}
	}
	return (v0);
}

sub_00002620(...) // at 0x00002620 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = 0x00000;
	s0 = v1 + 8324;
	*(s32*)(sp + 8) = ra;
	*(s32*)(sp + 4) = s1;
	a0 = *(u8*)(s0 + 176);
	v0 = -2;
	if (a0 == 0)
		goto loc_00002690;
	a0 = s0 + 44;
	v0 = sceUsbbdReqCancel(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3006;
	if (v0 == a0)
	{
		v0 = *(s32*)(s0 + 68);
		goto loc_000026D4;
	}

loc_0000265C:		
	t4 = 0x00000;
	s0 = t4 + 8412;

loc_00002664:		
	a0 = s0;
	v0 = sceUsbbdReqCancel(...);
	t3 = 0x80240000;
	t1 = t3 | 0x3006;
	a0 = s0 - 88;
	if (v0 == t1)
		goto loc_000026A4;

loc_0000267C:		
	a0 = 2;
	a1 = 0;

loc_00002684:		
	a2 = 0;
	v0 = sub_00002B48(...);
	v0 = 0;

loc_00002690:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000026A4:		
	t6 = *(s32*)(a0 + 112);
	t5 = -1;
	s1 = a0;
	if (t6 == t5)
		goto loc_0000267C;
	s0 = -1;

loc_000026B8:		
	a0 = 1000;
	v0 = sceKernelDelayThread(...);
	t7 = *(s32*)(s1 + 112);
	a0 = 2;
	if (t7 != s0)
		goto loc_000026B8;
	a1 = 0;
	goto loc_00002684;

loc_000026D4:		
	a3 = -1;
	s1 = s0;
	if (v0 == a3)
		goto loc_0000265C;
	s0 = -1;

loc_000026E4:		
	a0 = 1000;
	v0 = sceKernelDelayThread(...);
	t0 = *(s32*)(s1 + 68);
	t4 = 0x00000;
	if (t0 != s0)
		goto loc_000026E4;
	s0 = t4 + 8412;
	goto loc_00002664;
}

sub_00002700(...) // at 0x00002700 
{
	sp = sp - 48;
	v1 = 0x00000;
	*(s32*)(sp + 20) = s1;
	s1 = v1 + 8324;
	t0 = a0;
	v0 = *(u8*)(s1 + 176);
	*(s32*)(sp + 28) = s3;
	a3 = a1;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = 0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 0) = 0;
	if (v0 != 0)
		goto loc_00002760;
	s3 = -2;

loc_00002740:		
	v0 = s3;

loc_00002744:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_00002760:		
	*(s32*)(s1 + 136) = 0;
	*(s32*)(s1 + 140) = 0;
	*(s32*)(s1 + 132) = 0;
	a1 = *(s32*)(s1 + 132);
	a0 = (s32)a1 < (s32)1024;
	if (a0 == 0)
	{
		a3 = 0x00000;
		goto loc_000027EC;
	}
	a2 = s1;
	if ((s32)a3 <= 0)
		goto loc_000027E8;

loc_00002784:		
	v1 = *(s32*)(a2 + 140);
	a0 = *(s32*)(a2 + 156);
	a1 = t0 + s2;
	t1 = *(u8*)(a1 + 0);
	t9 = a0 + v1;
	s2 = s2 + 1;
	*(s8*)(t9 + 0) = t1;
	a0 = (s32)s2 < (s32)a3;
	t8 = *(s32*)(a2 + 140);
	t5 = t8 + 1;
	s0 = (s32)t5 >> 31;
	t7 = (u32)s0 >> 22;
	t6 = t5 + t7;
	t6 = ((0 & (0xFFFFFFFF >> (32 - 10))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	t4 = t5 - t6;
	*(s32*)(a2 + 140) = t4;
	t3 = *(s32*)(a2 + 132);
	t2 = t3 + 1;
	*(s32*)(a2 + 132) = t2;
	t1 = *(s32*)(a2 + 132);
	v0 = (s32)t1 < (s32)1024;
	if (v0 == 0)
	{
		a3 = 0x00000;
		goto loc_000027EC;
	}
	if (a0 != 0)
		goto loc_00002784;

loc_000027E8:		
	a3 = 0x00000;

loc_000027EC:		
	a0 = a3 + 8324;
	a2 = *(s32*)(a0 + 132);
	s0 = a0;
	if ((s32)a2 <= 0)
		goto loc_00002868;

loc_000027FC:		
	a0 = s0;
	v0 = sub_00002D54(...);
	a0 = *(s32*)(s0 + 168);
	a1 = -3;
	v0 = sceKernelClearEventFlag(...);
	a0 = s1;
	v0 = sceUsbAcc_internal_2A100C1F(...);
	a0 = *(s32*)(s0 + 168);
	a1 = 3;
	a2 = 33;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	t2 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00002880;
	t0 = t2 & 0x1;
	if (t0 != 0)
	{
		s3 = -2;
		goto loc_00002740;
	}
	t4 = *(u8*)(s0 + 177);
	t3 = (u32)t4 < (u32)22;
	if (t3 != 0)
		goto loc_00002870;

loc_00002854:		
	t5 = *(s32*)(s0 + 132);
	if ((s32)t5 > 0)
		goto loc_000027FC;

loc_00002860:		
	v0 = s3;
	if ((s32)s3 < 0)
		goto loc_00002744;

loc_00002868:		
	s3 = s2;
	goto loc_00002740;

loc_00002870:		
	a0 = *(s32*)(s0 + 184);
	v0 = sceKernelDelayThread(...);
	goto loc_00002854;

loc_00002880:		
	s3 = v0;
	goto loc_00002860;
}

sub_00002888(...) // at 0x00002888 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	*(s32*)(sp + 12) = ra;
	if ((s32)a1 <= 0)
		goto loc_000028D0;
	a1 = s2 - s0;

loc_000028B0:		
	a0 = s1;
	v0 = sub_00002700(...);
	s0 = s0 + v0;
	v1 = (s32)s0 < (s32)s2;
	s1 = s1 + s0;
	if ((s32)v0 < 0)
		goto loc_000028EC;
	a1 = s2 - s0;
	if (v1 != 0)
		goto loc_000028B0;

loc_000028D0:		
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000028EC:		
	s0 = v0;
	goto loc_000028D0;
}

sub_000028F4(...) // at 0x000028F4 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	v1 = 0x00000;
	s3 = a0;
	*(s32*)(sp + 24) = s2;
	a0 = -2;
	s2 = a1;
	*(s32*)(sp + 20) = s1;
	s1 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = v1 + 8324;
	*(s32*)(sp + 32) = ra;
	v0 = *(u8*)(s0 + 176);
	*(s32*)(sp + 4) = 0;
	*(s32*)(sp + 0) = a2;
	if (v0 == 0)
		goto loc_00002968;
	a0 = *(s32*)(s0 + 168);
	t0 = sp;
	if (a2 == 0)
		t0 = 0;
	a1 = 5;
	a2 = 33;
	a3 = sp + 4;
	v0 = sceKernelWaitEventFlag(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00002968;
	a2 = *(s32*)(sp + 4);
	a1 = a2 & 0x1;
	a0 = -2;
	if (a1 == 0)
		goto loc_00002988;

loc_00002968:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 48;
	return (v0);

loc_00002988:		
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = *(s32*)(s0 + 144);
	t0 = v0;
	if (a0 == 0)
		goto loc_00002A04;
	a2 = s0;
	if ((s32)s2 <= 0)
		goto loc_00002A04;

loc_000029A4:		
	a0 = *(s32*)(a2 + 148);
	a1 = *(s32*)(a2 + 160);
	t8 = s3 + s1;
	s1 = s1 + 1;
	a3 = a1 + a0;
	t9 = *(u8*)(a3 + 0);
	a3 = (s32)s1 < (s32)s2;
	*(s8*)(t8 + 0) = t9;
	s0 = *(s32*)(a2 + 148);
	t4 = s0 + 1;
	t7 = (s32)t4 >> 31;
	t6 = (u32)t7 >> 22;
	t5 = t4 + t6;
	t5 = ((0 & (0xFFFFFFFF >> (32 - 10))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	t3 = t4 - t5;
	*(s32*)(a2 + 148) = t3;
	t2 = *(s32*)(a2 + 144);
	t1 = t2 - 1;
	*(s32*)(a2 + 144) = t1;
	v0 = *(s32*)(a2 + 144);
	if (v0 == 0)
		goto loc_00002A04;
	if (a3 != 0)
		goto loc_000029A4;

loc_00002A04:		
	a0 = t0;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = s1;
	goto loc_00002968;
}

sub_00002A14(...) // at 0x00002A14 
{
	v1 = 0x00000;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = v1 + 256;
	v0 = sceUsbbdRegister(...);
	a0 = (s32)v0 < (s32)0;
	a1 = 0x40000;
	t0 = 0x00000;
	a3 = -1;
	ra = *(s32*)(sp + 0);
	a2 = t0 + 8324;
	v0 = a1 | 0xE200;
	if (a0 == 0)
		a3 = 0;
	*(s32*)(a2 + 184) = v0;
	v0 = a3;
	*(s8*)(a2 + 177) = 0;
	*(s32*)(a2 + 188) = 0;
	*(s32*)(a2 + 192) = 0;
	*(s8*)(a2 + 176) = 0;
	*(s32*)(a2 + 180) = 0;
	sp = sp + 16;
	return (v0);
}

sub_00002A6C(...) // at 0x00002A6C 
{
	v0 = 0x00000;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = v0 + 256;
	v0 = sceUsbbdUnregister(...);
	a0 = (s32)v0 < (s32)0;
	ra = *(s32*)(sp + 0);
	v0 = -1;
	if (a0 == 0)
		v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00002A98(...) // at 0x00002A98 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	v0 = -1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 8) = ra;
	if (a0 == 0)
		goto loc_00002ADC;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	a1 = a0 + 8324;
	*(s32*)(a1 + 192) = s1;
	a0 = v0;
	*(s32*)(a1 + 188) = s0;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = 0;

loc_00002ADC:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00002AF0(...) // at 0x00002AF0 
{
	v1 = 0x00000;
	a1 = *(s32*)(v1 + 8504);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
}

sub_00002B04(...) // at 0x00002B04 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = ra;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	v0 = sceKernelCpuSuspendIntr(...);
	a2 = 0x00000;
	a1 = *(u8*)(a2 + 8500);
	a0 = v0;
	v1 = a1 ^ 0x1;
	if (v1 != 0)
		a1 = 0;
	*(s32*)(s0 + 0) = a1;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00002B48(a0, a1, a2) // at 0x00002B48 
{
	s0 = 0x00000 + 8324;
	v1 = *(s32*)(s0 + 40);
	*(s32*)(sp + 0) = 0;
	*(s8*)(v1 + 2) = a0;
	a0 = *(s32*)(s0 + 40);
	*(s8*)(a0 + 3) = a2;
	if (a1)
	{
		v0 = memcpy(*(s32*)(s0 + 40) + 4, a1, a2);
	}
	v0 = sceKernelClearEventFlag(*(s32*)(s0 + 168), -3);
	v0 = sceUsbAcc_internal_2A100C1F(s0);
	v1 = -1;
	if (v0 >= 0)
	{
		v0 = sceKernelWaitEventFlag(*(s32*)(s0 + 168), 3, 33, sp, 0);
		v1 = v0;
		if (v0 >= 0)
		{
			v1 = -2;
			if (*(s32*)(sp + 0) & 0x1 == 0)
				v1 = 0;
		}
	}
	return (v1);
}
{
	v1 = 0x00000;
	a2 = *(u8*)(v1 + 8501);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = (u32)a2 < (u32)22;
	a1 = 2;
	a2 = *(s32*)(a0 + 32);
	if (v0 != 0)
		goto loc_00002C14;
	a0 = *(s32*)(a2 + 40);
	v0 = 3;
	a3 = *(u8*)(a0 + 2);
	ra = *(s32*)(sp + 0);
	if (a3 == v0)
		goto loc_00002C20;

loc_00002C14:		
	a0 = *(s32*)(a2 + 168);
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 0);

loc_00002C20:		
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	a1 = -1;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a3 = 0;
	v0 = *(s32*)(a0 + 24);
	a2 = *(s32*)(a0 + 32);
	a0 = 0;
	if (v0 == a1)
		goto loc_00002CE4;
	t0 = *(s32*)(s0 + 20);

loc_00002C54:		
	a1 = (u32)a3 < (u32)t0;
	if (a1 == 0)
	{
		a3 = 1;
		goto loc_00002CC8;
	}
	t2 = *(s32*)(a2 + 144);
	t1 = (s32)t2 < (s32)1024;
	if (t1 == 0)
	{
		a3 = 1;
		goto loc_00002CC8;
	}
	v1 = *(s32*)(s0 + 4);
	t8 = *(s32*)(a2 + 152);
	a0 = *(s32*)(a2 + 160);
	t9 = v1 + a3;
	t7 = *(u8*)(t9 + 0);
	t6 = a0 + t8;
	a3 = a3 + 1;
	*(s8*)(t6 + 0) = t7;
	a0 = 1;
	t5 = *(s32*)(a2 + 152);
	t1 = t5 + 1;
	t4 = (s32)t1 >> 31;
	t3 = (u32)t4 >> 22;
	t2 = t1 + t3;
	t2 = ((0 & (0xFFFFFFFF >> (32 - 10))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	t0 = t1 - t2;
	*(s32*)(a2 + 152) = t0;
	a1 = *(s32*)(a2 + 144);
	v1 = a1 + 1;
	*(s32*)(a2 + 144) = v1;
	t0 = *(s32*)(s0 + 20);
	goto loc_00002C54;

loc_00002CC8:		
	if (a0 == a3)
	{
		a0 = *(s32*)(a2 + 168);
		goto loc_00002CF4;
	}
	a0 = *(s32*)(s0 + 4);

loc_00002CD4:		
	a1 = 64;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s0;
	v0 = sceUsbbdReqRecv(...);

loc_00002CE4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002CF4:		
	a1 = 4;
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 4);
	goto loc_00002CD4;
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	a2 = -1;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a1 = 2;
	v0 = *(s32*)(a0 + 24);
	a0 = *(s32*)(a0 + 32);
	if (v0 == a2)
		goto loc_00002D44;
	a0 = *(s32*)(a0 + 168);
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 4);
	a1 = 64;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s0;
	v0 = sceUsbbdReqRecv(...);

loc_00002D44:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00002D54(...) // at 0x00002D54 
{
	sp = sp - 80;
	*(s32*)(sp + 64) = ra;
	a1 = 3;
	a3 = a0;
	v0 = *(s32*)(a0 + 40);
	t0 = 0;
	*(s8*)(v0 + 2) = a1;
	a0 = *(s32*)(a0 + 132);
	v1 = (s32)a0 < (s32)60;
	t2 = 1;
	if (v1 != 0)
		goto loc_00002E10;
	a2 = *(s32*)(a3 + 40);
	v1 = 60;
	t1 = 59;
	*(s8*)(sp + 0) = t2;
	*(s8*)(a2 + 3) = v1;
	v1 = (s32)t0 < (s32)t1;

loc_00002D98:		
	if (v1 != 0)
		goto loc_00002DC0;
	t0 = *(s32*)(a3 + 40);

loc_00002DA4:		
	a1 = sp;
	a2 = *(u8*)(t0 + 3);
	a0 = t0 + 4;
	v0 = memcpy(...);
	ra = *(s32*)(sp + 64);
	sp = sp + 80;
	return (v0);

loc_00002DC0:		
	a0 = *(s32*)(a3 + 136);
	v0 = *(s32*)(a3 + 136);
	t4 = *(s32*)(a3 + 156);
	t7 = sp + t0;
	t2 = v0 + 1;
	t5 = (s32)t2 >> 31;
	a1 = (u32)t5 >> 22;
	t3 = t2 + a1;
	t3 = ((0 & (0xFFFFFFFF >> (32 - 10))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	a2 = t4 + a0;
	t9 = t2 - t3;
	t8 = *(u8*)(a2 + 0);
	*(s32*)(a3 + 136) = t9;
	t0 = t0 + 1;
	t6 = *(s32*)(a3 + 132);
	*(s8*)(t7 + 1) = t8;
	t5 = t6 - 1;
	*(s32*)(a3 + 132) = t5;
	v1 = (s32)t0 < (s32)t1;
	goto loc_00002D98;

loc_00002E10:		
	t4 = *(s32*)(a3 + 132);
	t1 = *(s32*)(a3 + 40);
	*(s8*)(sp + 0) = 0;
	t3 = t4 + 1;
	*(s8*)(t1 + 3) = t3;
	t1 = *(s32*)(a3 + 132);
	if ((s32)t1 > 0)
		goto loc_00002DC0;
	t0 = *(s32*)(a3 + 40);
	goto loc_00002DA4;
}

sub_00002E38(...) // at 0x00002E38 
{
	t0 = a3 + 24;
	sp = sp - 16;
	v0 = t0 + 12;
	v1 = 0x00000;
	*(s32*)(sp + 12) = s3;
	t7 = a3;
	s3 = a0;
	*(s32*)(sp + 8) = s2;
	s2 = a1;
	a1 = v0 + 48;
	*(s32*)(a2 + 4) = t0;
	t0 = v1 + 22208;
	t2 = s2 | t0;
	*(s32*)(sp + 4) = s1;
	t1 = t0 + 16;
	v1 = t2 & 0x3;
	*(s32*)(sp + 0) = s0;
	t9 = a1;
	t6 = a1 + 48;
	*(s32*)(a2 + 8) = v0;
	*(s32*)(a2 + 0) = a3;
	a3 = t1;
	*(s32*)(a2 + 12) = a1;
	s0 = *(s32*)(a2 + 4);
	s1 = *(s32*)(a2 + 8);
	a2 = s2;
	if (v1 == 0)
		goto loc_00003028;
	v0 = t1;

loc_00002EA8:		
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
	t0 = t0 + 16;
	a2 = a2 + 16;
	if (t0 != v0)
		goto loc_00002EA8;
	asm("lwl        $v0, 3($t0)");
	asm("lwr        $v0, 0($t0)");
	asm("swl        $v0, 3($a2)");
	asm("swr        $v0, 0($a2)");
	t2 = 0x00000;

loc_00002F08:		
	a3 = 0x00000;
	a1 = t2 + 22228;
	a2 = a3 + 22252;
	t5 = *(s32*)(t2 + 22228);
	t3 = *(s32*)(a3 + 22252);
	t4 = *(s32*)(a2 + 8);
	t8 = *(s32*)(a1 + 4);
	t1 = *(s32*)(a2 + 4);
	t2 = *(s32*)(a1 + 20);
	a0 = *(s32*)(a1 + 8);
	a3 = *(s32*)(a1 + 12);
	t0 = *(s32*)(a1 + 16);
	*(s32*)(t7 + 0) = t5;
	a2 = 0x00000;
	t5 = a2 + 22264;
	*(s32*)(t7 + 4) = t8;
	a2 = s1;
	t8 = t5 + 48;
	*(s32*)(t7 + 8) = a0;
	*(s32*)(t7 + 12) = a3;
	*(s32*)(t7 + 16) = t0;
	*(s32*)(t7 + 20) = t2;
	*(s32*)(s0 + 0) = t3;
	*(s32*)(s0 + 4) = t1;
	*(s32*)(s0 + 8) = t4;

loc_00002F6C:		
	v1 = *(s32*)(t5 + 0);
	t3 = *(s32*)(t5 + 4);
	t1 = *(s32*)(t5 + 8);
	t0 = *(s32*)(t5 + 12);
	*(s32*)(a2 + 0) = v1;
	t5 = t5 + 16;
	a2 = a2 + 16;
	*(s32*)(a2 - 12) = t3;
	*(s32*)(a2 - 8) = t1;
	*(s32*)(a2 - 4) = t0;
	if (t5 != t8)
		goto loc_00002F6C;
	t4 = 0x00000;
	a3 = t4 + 22312;
	a2 = t9;
	t0 = a3 + 48;

loc_00002FA8:		
	a1 = *(s32*)(a3 + 0);
	a0 = *(s32*)(a3 + 4);
	t5 = *(s32*)(a3 + 8);
	t8 = *(s32*)(a3 + 12);
	*(s32*)(a2 + 0) = a1;
	a3 = a3 + 16;
	a2 = a2 + 16;
	*(s32*)(a2 - 12) = a0;
	*(s32*)(a2 - 8) = t5;
	*(s32*)(a2 - 4) = t8;
	if (a3 != t0)
		goto loc_00002FA8;
	*(s32*)(t7 + 12) = s0;
	t7 = 2;
	v1 = 512;
	*(s32*)(s0 + 0) = s1;
	*(s32*)(s1 + 12) = t9;
	if (s3 == t7)
		goto loc_00002FF0;
	v1 = 64;

loc_00002FF0:		
	s0 = t9 + 16;
	s1 = 64;
	*(s8*)(s2 + 7) = s1;
	v0 = t6;
	*(s16*)(t9 + 4) = v1;
	*(s8*)(t9 + 6) = 0;
	*(s16*)(s0 + 4) = v1;
	*(s8*)(s0 + 6) = 0;
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00003028:		
	t5 = *(s32*)(t0 + 0);
	t3 = *(s32*)(t0 + 12);
	a0 = *(s32*)(t0 + 4);
	t4 = *(s32*)(t0 + 8);
	*(s32*)(a2 + 0) = t5;
	a2 = a2 + 16;
	t0 = t1;
	*(s32*)(a2 - 12) = a0;
	*(s32*)(a2 - 8) = t4;
	*(s32*)(a2 - 4) = t3;
	if (t1 == a3)
		goto loc_0000305C;
	t1 = t1 + 16;
	goto loc_00003028;

loc_0000305C:		
	a3 = *(s32*)(t1 + 0);
	*(s32*)(a2 + 0) = a3;
	t2 = 0x00000;
	goto loc_00002F08;
}

sub_0000306C(...) // at 0x0000306C 
{
	asm("mfc1       $v0, $fcr12");
	at = 0x40C90000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr3");
	a0 = (v0 >> 0) & (0xFFFFFFFF >> (32 - 31));;
	asm("mtc1       $a0, $fcr12");
	asm("c.lt.s     $fpr03, $fpr12");
	if (asm("bc1f       loc_000030A8"))
		goto ;
	asm("div.s      $fpr02, $fpr12, $fpr03");
	asm("trunc.w.s  $fpr05, $fpr02");
	asm("cvt.s.w    $fpr04, $fpr05");
	asm("mul.s      $fpr00, $fpr04, $fpr03");
	asm("sub.s      $fpr12, $fpr12, $fpr00");

loc_000030A8:		
	at = 0x40490000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr3");
	asm("c.lt.s     $fpr03, $fpr12");
	if (asm("bc1f       loc_000030CC"))
		goto ;
	asm("sub.s      $fpr12, $fpr12, $fpr03");
	asm("negu       $v0, $v0");

loc_000030CC:		
	at = 0x3FC90000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr2");
	asm("c.lt.s     $fpr02, $fpr12");
	if (asm("bc1tl      loc_000030E8"))
	{
		asm("sub.s      $fpr12, $fpr03, $fpr12");
		goto ;
	}

loc_000030E8:		
	at = 0x3F6A0000;
	at = at | 0xD720;
	asm("mtc1       $at, $fcr3");
	asm("c.lt.s     $fpr03, $fpr12");
	if (asm("bc1fl      loc_0000316C"))
	{
		asm("mul.s      $fpr04, $fpr12, $fpr12");
		goto ;
	}
	asm("sub.s      $fpr16, $fpr02, $fpr12");
	at = 0xBAB30000;
	at = at | 0xD431;
	asm("mtc1       $at, $fcr15");
	at = 0x3D2A0000;
	at = at | 0xA6FB;
	asm("mtc1       $at, $fcr14");
	at = 0xBEFF0000;
	at = at | 0xFFF9;
	asm("mtc1       $at, $fcr11");
	asm("mul.s      $fpr09, $fpr16, $fpr16");
	at = 0x3F800000;
	asm("mtc1       $at, $fcr7");
	asm("mul.s      $fpr13, $fpr09, $fpr15");
	asm("add.s      $fpr12, $fpr13, $fpr14");
	asm("mul.s      $fpr10, $fpr12, $fpr09");
	asm("add.s      $fpr08, $fpr10, $fpr11");
	asm("mul.s      $fpr06, $fpr08, $fpr09");
	asm("add.s      $fpr00, $fpr06, $fpr07");

loc_00003150:		
	asm("mfc1       $v1, $fcr0");
	v0 = ((0 & (0xFFFFFFFF >> (32 - 31))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	if (v1 == 0)
		goto loc_00003164;
	a0 = v1 | v0;
	asm("mtc1       $a0, $fcr0");

loc_00003164:		
	return (v0);

loc_0000316C:		
	at = 0xB94B0000;
	at = at | 0x9F27;
	asm("mtc1       $at, $fcr1");
	at = 0x3C080000;
	at = at | 0x801C;
	asm("mtc1       $at, $fcr7");
	at = 0xBE2A0000;
	at = at | 0xAA98;
	asm("mtc1       $at, $fcr2");
	asm("mul.s      $fpr06, $fpr04, $fpr01");
	asm("add.s      $fpr03, $fpr06, $fpr07");
	asm("mul.s      $fpr05, $fpr03, $fpr04");
	asm("add.s      $fpr19, $fpr05, $fpr02");
	asm("mul.s      $fpr18, $fpr19, $fpr04");
	asm("mul.s      $fpr17, $fpr18, $fpr12");
	asm("add.s      $fpr00, $fpr17, $fpr12");
	goto loc_00003150;
}

sub_000031B0(...) // at 0x000031B0 
{
	asm("abs.s      $fpr12, $fpr12");
	at = 0x40C90000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr4");
	asm("c.lt.s     $fpr04, $fpr12");
	v0 = 1;
	if (asm("bc1f       loc_000031E4"))
		goto ;
	asm("div.s      $fpr02, $fpr12, $fpr04");
	asm("trunc.w.s  $fpr01, $fpr02");
	asm("cvt.s.w    $fpr03, $fpr01");
	asm("mul.s      $fpr00, $fpr03, $fpr04");
	asm("sub.s      $fpr12, $fpr12, $fpr00");

loc_000031E4:		
	at = 0x40490000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr4");
	asm("c.lt.s     $fpr04, $fpr12");
	if (asm("bc1f       loc_00003208"))
		goto ;
	asm("sub.s      $fpr12, $fpr12, $fpr04");
	v0 = -1;

loc_00003208:		
	at = 0x3FC90000;
	at = at | 0xFDB;
	asm("mtc1       $at, $fcr3");
	asm("c.lt.s     $fpr03, $fpr12");
	if (asm("bc1f       loc_0000322C"))
		goto ;
	asm("sub.s      $fpr12, $fpr04, $fpr12");
	asm("negu       $v0, $v0");

loc_0000322C:		
	at = 0x3F270000;
	at = at | 0x4895;
	asm("mtc1       $at, $fcr4");
	asm("c.lt.s     $fpr04, $fpr12");
	if (asm("bc1fl      loc_000032AC"))
	{
		asm("mul.s      $fpr19, $fpr12, $fpr12");
		goto ;
	}
	asm("sub.s      $fpr06, $fpr03, $fpr12");
	at = 0xB94B0000;
	at = at | 0x9F27;
	asm("mtc1       $at, $fcr15");
	at = 0x3C080000;
	at = at | 0x801C;
	asm("mtc1       $at, $fcr14");
	at = 0xBE2A0000;
	at = at | 0xAA98;
	asm("mtc1       $at, $fcr11");
	asm("mul.s      $fpr09, $fpr06, $fpr06");
	asm("mul.s      $fpr13, $fpr09, $fpr15");
	asm("add.s      $fpr12, $fpr13, $fpr14");
	asm("mul.s      $fpr10, $fpr12, $fpr09");
	asm("add.s      $fpr08, $fpr10, $fpr11");
	asm("mul.s      $fpr07, $fpr08, $fpr09");
	asm("mul.s      $fpr05, $fpr07, $fpr06");
	asm("add.s      $fpr00, $fpr05, $fpr06");

loc_00003290:		
	asm("mfc1       $v1, $fcr0");
	v0 = ((0 & (0xFFFFFFFF >> (32 - 31))) << 0) | (%r0 & ~((0xFFFFFFFF >> (32 - %i1)) << %i0));;
	if (v1 == 0)
		goto loc_000032A4;
	a0 = v1 | v0;
	asm("mtc1       $a0, $fcr0");

loc_000032A4:		
	return (v0);

loc_000032AC:		
	at = 0xBAB30000;
	at = at | 0xD431;
	asm("mtc1       $at, $fcr1");
	at = 0x3D2A0000;
	at = at | 0xA6FB;
	asm("mtc1       $at, $fcr6");
	at = 0xBEFF0000;
	at = at | 0xFFF9;
	asm("mtc1       $at, $fcr2");
	asm("mul.s      $fpr05, $fpr19, $fpr01");
	at = 0x3F800000;
	asm("mtc1       $at, $fcr17");
	asm("add.s      $fpr04, $fpr05, $fpr06");
	asm("mul.s      $fpr03, $fpr04, $fpr19");
	asm("add.s      $fpr18, $fpr03, $fpr02");
	asm("mul.s      $fpr16, $fpr18, $fpr19");
	asm("add.s      $fpr00, $fpr16, $fpr17");
	goto loc_00003290;
}

sub_000032F4(...) // at 0x000032F4 
{
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	s2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 0) = 0;
	if (a0 == 0)
		goto loc_00003410;
	v0 = 0x00000;
	a0 = v0 + 22160;
	a1 = 1;
	a2 = 256;
	a3 = 3262;
	t0 = 1;
	t1 = 0;
	v0 = sceKernelCreateFpl(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003418;
	a0 = 0x00000;
	s0 = a0 + 8528;
	*(s32*)(s0 + 444) = v0;
	a0 = v0;
	a1 = sp;
	v0 = sceKernelTryAllocateFpl(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003418;
	t2 = *(s32*)(sp + 0);
	*(s32*)(s0 + 28) = s1;
	v1 = 0x00000;
	t3 = t2 + 2182;
	t1 = t2 + 128;
	v0 = t2 + 1151;
	*(s32*)(s0 + 8) = t1;
	a0 = v1 + 22180;
	a1 = 1;
	*(s32*)(s0 + 12) = v0;
	a2 = 1;
	a3 = 1;
	*(s32*)(s0 + 24) = t3;
	t0 = 0;
	*(s32*)(s0 + 4) = t2;
	*(s32*)(s0 + 448) = 0;
	*(s32*)(sp + 0) = t3;
	v0 = sceKernelCreateSema(...);
	a3 = 0x2D0000;
	if ((s32)v0 <= 0)
		goto loc_00003410;
	a2 = a3 | 0xC6C0;
	a1 = 1;
	*(s32*)(s0 + 456) = a2;
	*(s32*)(s0 + 440) = v0;
	*(s32*)(s0 + 452) = a1;

loc_000033C4:		
	t0 = 0x00000;
	if ((s32)s2 < 0)
		goto loc_000033EC;

loc_000033CC:		
	v0 = s2;

loc_000033D0:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_000033E8:		
	t0 = 0x00000;

loc_000033EC:		
	s0 = t0 + 8528;
	a0 = *(s32*)(s0 + 444);
	v0 = s2;
	if ((s32)a0 < 0)
		goto loc_000033D0;
	v0 = sceKernelDeleteFpl(...);
	t4 = -1;
	*(s32*)(s0 + 444) = t4;
	goto loc_000033CC;

loc_00003410:		
	s2 = -1;
	goto loc_000033E8;

loc_00003418:		
	s2 = v1;
	goto loc_000033C4;
}

sub_00003420(...) // at 0x00003420 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v1 + 8528;
	v0 = *(s32*)(s0 + 440);
	*(s32*)(sp + 4) = ra;
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003450;
	v0 = sceKernelDeleteSema(...);
	v0 = -1;
	*(s32*)(s0 + 440) = v0;

loc_00003450:		
	a1 = *(s32*)(s0 + 444);
	a0 = a1;
	if ((s32)a1 < 0)
		goto loc_0000347C;
	v0 = sceKernelDeleteFpl(...);
	a0 = -1;
	*(s32*)(s0 + 444) = a0;
	*(s32*)(s0 + 24) = 0;
	*(s32*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;

loc_0000347C:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);
}

sub_00003490(...) // at 0x00003490 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	v1 = s1 + 8528;
	*(s32*)(sp + 16) = s0;
	a1 = 1;
	a2 = 0;
	*(s32*)(sp + 24) = ra;
	s0 = 0;
	a0 = *(s32*)(v1 + 440);
	v0 = sceKernelWaitSema(...);
	v1 = v0;
	a0 = sp;
	if ((s32)v0 < 0)
		goto loc_0000350C;
	*(s32*)(sp + 0) = 0;
	v0 = sub_00002AF0(...);
	a0 = 0xE100;
	if ((s32)v0 < 0)
		goto loc_000034F8;
	s0 = -1;
	v0 = sub_00002408(...);
	a2 = s1 + 8528;
	if ((s32)v0 < 0)
		goto loc_000034FC;
	v0 = sub_00002544(...);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s0 = 0;

loc_000034F8:		
	a2 = s1 + 8528;

loc_000034FC:		
	a0 = *(s32*)(a2 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	v1 = s0;

loc_0000350C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);
}

sub_00003524(...) // at 0x00003524 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = v1 + 8528;
	a1 = 1;
	a0 = *(s32*)(s1 + 440);
	a2 = 0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = -1;
	v0 = sceKernelWaitSema(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003578;
	v0 = sub_00002620(...);
	a0 = *(s32*)(s1 + 440);
	v1 = (s32)v0 < (s32)0;
	if (v1 == 0)
		s0 = 0;
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	v1 = s0;

loc_00003578:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_00003590(...) // at 0x00003590 
{
	sp = sp - 64;
	v1 = 0x00000;
	*(s32*)(sp + 48) = s4;
	s4 = v1 + 8528;
	a1 = a0;
	v0 = *(s32*)(s4 + 452);
	*(s32*)(sp + 44) = s3;
	a2 = -2;
	s3 = s4;
	*(s32*)(sp + 40) = s2;
	s2 = 0;
	*(s32*)(sp + 36) = s1;
	s1 = 0;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 32) = s0;
	*(s16*)(sp + 0) = 0;
	*(s32*)(sp + 16) = 0;
	if (v0 == 0)
		goto loc_00003668;
	s0 = 132;
	if (a0 == 0)
		goto loc_00003620;
	a0 = 1;
	s0 = 130;
	if (a1 == a0)
		goto loc_00003620;
	a2 = 2;
	a0 = sp + 8;
	s0 = 192;
	if (a1 == a2)
		goto loc_00003620;
	v0 = sceRtcGetCurrentTick(...);
	a0 = sp + 8;
	a1 = sp;
	a2 = sp + 16;
	if (v0 == 0)
		goto loc_0000368C;
	a1 = *(s32*)(s3 + 28);

loc_00003618:		
	s0 = 193;
	s2 = a1 + 24;

loc_00003620:		
	a0 = *(s32*)(s4 + 440);
	a2 = 0;
	a1 = 1;
	v0 = sceKernelWaitSema(...);
	a2 = v0;
	a0 = s0;
	a3 = s2;
	if ((s32)v0 < 0)
		goto loc_00003668;
	a2 = *(s32*)(sp + 16);
	a1 = *(u16*)(sp + 0);
	v0 = sub_00004BEC(...);
	a0 = *(s32*)(s4 + 440);
	t0 = (s32)v0 < (s32)0;
	a3 = -1;
	if (t0 != 0)
		s1 = a3;
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	a2 = s1;

loc_00003668:		
	ra = *(s32*)(sp + 52);
	s4 = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = a2;
	sp = sp + 64;
	return (v0);

loc_0000368C:		
	v0 = sub_00003AD4(...);
	a1 = *(s32*)(s3 + 28);
	goto loc_00003618;
}

sub_0000369C(...) // at 0x0000369C 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = s3 + 8528;
	v1 = *(s32*)(s1 + 452);
	*(s32*)(sp + 8) = s2;
	s2 = 0;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = -2;
	*(s32*)(sp + 16) = ra;
	if (v1 == 0)
		goto loc_00003754;
	a0 = *(s32*)(s1 + 440);
	a1 = 1;
	a2 = 0;
	v0 = sceKernelWaitSema(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_00003754;
	v0 = s0 ^ 0x1;
	t0 = s0 ^ 0xA;
	a2 = (u32)v0 < (u32)1;
	a3 = (u32)t0 < (u32)1;
	a0 = a2 | a3;
	v1 = 1;
	if (a0 == 0)
		goto loc_00003794;
	t7 = 0x1310000;
	if (s0 == v1)
		goto loc_00003774;
	s0 = 0x00000;
	t5 = s0 + 22360;
	t6 = t7 | 0x2D00;
	*(s32*)(s1 + 456) = t6;
	a1 = *(u16*)(t5 + 42);
	a0 = *(u16*)(t5 + 40);

loc_00003724:		
	v0 = sub_00004D3C(...);
	t8 = -1;
	if (v0 != 0)
		s2 = t8;
	v0 = sub_00004DEC(...);
	if (v0 != 0)
	{
		s2 = -1;
		goto loc_00003740;
	}

loc_00003740:		
	a2 = s3 + 8528;
	a0 = *(s32*)(a2 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	a0 = s2;

loc_00003754:		
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 32;
	return (v0);

loc_00003774:		
	t4 = 0x00000;
	t3 = t4 + 22360;
	a1 = *(u16*)(t3 + 6);
	a0 = *(u16*)(t3 + 4);
	t2 = 0x2D0000;
	t1 = t2 | 0xC6C0;
	*(s32*)(s1 + 456) = t1;
	goto loc_00003724;

loc_00003794:		
	a0 = 300;
	a1 = 0;
	v0 = sub_00004D3C(...);
	s2 = -1;
	if (v0 == 0)
		s2 = 0;
	goto loc_00003740;
}

sub_000037AC(...) // at 0x000037AC 
{
	sp = sp - 48;
	*(s32*)(sp + 40) = s2;
	s2 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 36) = s1;
	s1 = s2 + 8528;
	a2 = 0;
	a0 = *(s32*)(s1 + 440);
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 32) = s0;
	v0 = sceKernelWaitSema(...);
	v1 = v0;
	a0 = sp + 4;
	if ((s32)v0 < 0)
		goto loc_0000385C;
	*(s16*)(sp + 0) = 0;
	s0 = 0;
	*(s32*)(sp + 16) = 0;
	*(s32*)(sp + 4) = 0;
	v0 = sub_00002AF0(...);
	t0 = s2 + 8528;
	if ((s32)v0 < 0)
		goto loc_0000384C;
	v0 = *(s32*)(s1 + 28);
	a1 = *(s32*)(v0 + 0);
	a0 = sp + 8;
	if (a1 != 0)
		goto loc_00003878;

loc_00003810:		
	a3 = s2 + 8528;
	a2 = s0 | 0xC0;
	v1 = *(s32*)(a3 + 28);
	a0 = a2;
	a1 = *(u16*)(sp + 0);
	a2 = *(s32*)(sp + 16);
	a3 = v1 + 24;
	v0 = sub_00004BEC(...);
	t0 = s2 + 8528;
	if ((s32)v0 < 0)
		goto loc_0000384C;
	v0 = sub_00004374(...);
	v0 = sub_00004E28(...);
	t0 = s2 + 8528;

loc_0000384C:		
	a0 = *(s32*)(t0 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	v1 = 0;

loc_0000385C:		
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00003878:		
	v0 = sceRtcGetCurrentTick(...);
	a0 = sp + 8;
	if ((s32)v0 < 0)
		goto loc_00003810;
	a1 = sp;
	a2 = sp + 16;
	v0 = sub_00003AD4(...);
	s0 = 1;
	goto loc_00003810;
}

sub_0000389C(...) // at 0x0000389C 
{
	sp = sp - 64;
	*(s32*)(sp + 36) = s5;
	v0 = 0x00000;
	a3 = v0 + 8528;
	*(s32*)(sp + 52) = ra;
	a1 = 1;
	a2 = 0;
	*(s32*)(sp + 48) = fp;
	s5 = a3;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 4) = a0;
	a0 = *(s32*)(a3 + 440);
	s4 = *(s32*)(a3 + 4);
	v0 = sceKernelWaitSema(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003968;
	a2 = *(s32*)(s5 + 456);
	a0 = s4;
	a1 = 128;
	v0 = sub_000028F4(...);
	a0 = 0x80020000;
	v1 = a0 | 0x1A8;
	s2 = v0;
	if (v0 == v1)
		goto loc_00003A4C;

loc_00003914:		
	s1 = 0;
	if ((s32)s2 <= 0)
		goto loc_00003950;
	s6 = s5 + 448;
	s7 = 41;
	fp = 2;
	a1 = s4 + s1;

loc_0000392C:		
	a0 = *(u8*)(a1 + 0);
	a1 = s6;
	v0 = sub_00004138(...);
	s0 = v0;
	if (v0 != 0)
		goto loc_0000399C;
	s1 = s1 + 1;

loc_00003944:		
	s0 = (s32)s1 < (s32)s2;
	a1 = s4 + s1;
	if (s0 != 0)
		goto loc_0000392C;

loc_00003950:		
	s3 = 0x00000;
	s1 = s3 + 8528;
	a0 = *(s32*)(s1 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	v1 = s2;

loc_00003968:
	return (v1);

loc_0000399C:		
	v0 = sceKernelCpuSuspendIntr(...);
	s3 = v0;
	if (s0 == s7)
		goto loc_00003A3C;
	t7 = 4;
	if (s0 == fp)
		goto loc_000039FC;
	t8 = 18;
	if (s0 == t7)
		goto loc_000039E4;
	if (s0 == t8)
		goto loc_000039D4;

loc_000039C4:		
	a0 = s3;
	v0 = sceKernelCpuResumeIntr(...);
	s1 = s1 + 1;
	goto loc_00003944;

loc_000039D4:		
	a0 = s5 + 452;
	v0 = sub_000049A8(...);
	goto loc_000039C4;

loc_000039E4:		
	a0 = s5 + 116;
	a1 = sp;
	*(s8*)(sp + 0) = 0;
	v0 = sub_000048D4(...);
	goto loc_000039C4;

loc_000039FC:		
	a0 = s5 + 80;
	v0 = sub_00004758(...);
	t3 = 0x00000;
	t2 = t3 + 8528;
	t1 = *(u8*)(t2 + 80);
	t0 = t1 & 0x7;
	a3 = t0 - 1;
	a2 = (u32)a3 < (u32)6;
	t6 = *(s32*)(sp + 4);
	if (a2 == 0)
		goto loc_00003A34;
	t4 = *(s32*)(sp + 4);
	t5 = 1;
	*(s8*)(t4 + 0) = t5;
	goto loc_000039C4;

loc_00003A34:		
	*(s8*)(t6 + 0) = 0;
	goto loc_000039C4;

loc_00003A3C:		
	a0 = s5 + 32;
	v0 = sub_00004540(...);
	goto loc_000039C4;

loc_00003A4C:		
	a0 = 2000;
	v0 = sceUsbRestart(...);
	goto loc_00003914;
}

sub_00003A5C(...) // at 0x00003A5C 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v1 + 8528;
	a1 = 1;
	v0 = *(s32*)(s0 + 452);
	*(s32*)(sp + 8) = ra;
	a2 = 0;
	a0 = -2;
	*(s32*)(sp + 4) = s1;
	if (v0 == 0)
		goto loc_00003ABC;
	a0 = *(s32*)(s0 + 440);
	s1 = -1;
	v0 = sceKernelWaitSema(...);
	a0 = 0;
	if ((s32)v0 < 0)
		goto loc_00003ABC;
	v0 = sub_00003BD0(...);
	a0 = (s32)v0 < (s32)0;
	if (a0 == 0)
		s1 = 0;
	a0 = *(s32*)(s0 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	a0 = s1;

loc_00003ABC:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);
}

sub_00003AD4(...) // at 0x00003AD4 
{
	sp = sp - 64;
	*(s32*)(sp + 56) = s6;
	a3 = 1980;
	s6 = a2;
	*(s32*)(sp + 52) = s5;
	v1 = 1;
	s5 = a1;
	*(s32*)(sp + 48) = s4;
	a1 = sp + 16;
	s4 = a0;
	a2 = 6;
	a0 = sp;
	*(s32*)(sp + 60) = ra;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 40) = s2;
	s2 = 0xD0E30000;
	s2 = s2 | 0xA000;
	s3 = 140;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	*(s16*)(sp + 0) = a3;
	*(s16*)(sp + 2) = v1;
	*(s16*)(sp + 4) = a2;
	*(s16*)(sp + 6) = 0;
	*(s16*)(sp + 8) = 0;
	*(s16*)(sp + 10) = 0;
	*(s32*)(sp + 12) = 0;
	v0 = sceRtcGetTick(...);
	a2 = s2;
	s0 = *(s32*)(s4 + 0);
	s1 = *(s32*)(s4 + 4);
	v0 = *(s32*)(sp + 16);
	v1 = *(s32*)(sp + 20);
	a3 = s3;
	a1 = (u32)s0 < (u32)v0;
	s0 = s0 - v0;
	v0 = s1 - v1;
	s4 = v0 - a1;
	a0 = s0;
	a1 = s4;
	v0 = SysclibForKernel_7DEE14DE(...);
	*(s16*)(s5 + 0) = v0;
	a2 = s2;
	a3 = s3;
	a0 = s0;
	a1 = s4;
	v0 = SysclibForKernel_5E8E5F42(...);
	a0 = v0;
	a3 = 0;
	a2 = 10000;
	a1 = v1;
	v0 = SysclibForKernel_7DEE14DE(...);
	*(s32*)(s6 + 0) = v0;
	return (v0);
}

sub_00003BD0(...) // at 0x00003BD0 
{
	a0 = 0x00000 + 22404;
	a1 = 11;
	fp = 0;
	v0 = sub_00002888(...);
	*(s32*)(sp + 4) = 0;
	if ((s32)v0 < 0)
		goto loc_00003D20;
	v0 = 0x00000;
	a1 = v0 + 8528;
	a0 = *(s32*)(a1 + 24);
	*(s32*)(a1 + 20) = 0;
	s5 = a1;
	*(s8*)(a0 + 3) = 0;
	*(s8*)(a0 + 0) = 0;
	*(s8*)(a0 + 1) = 0;
	*(s8*)(a0 + 2) = 0;
	v0 = sceKernelGetSystemTimeLow(...);
	*(s32*)(sp + 0) = v0;
	a2 = *(s32*)(s5 + 456);

loc_00003C48:		
	a0 = *(s32*)(s5 + 4);
	a1 = 128;
	s2 = 0;
	v0 = sub_000028F4(...);
	a2 = 0x80020000;
	v1 = a2 | 0x1A8;
	s3 = v0;
	s4 = 0;
	if (v0 == v1)
		goto loc_00003F24;

loc_00003C6C:		
	if ((s32)s3 < 0)
	{
		fp = s3;
		goto loc_00003D24;
	}
	s1 = 0;
	if (s3 == 0)
		goto loc_00003CE4;
	t1 = *(s32*)(sp + 4);
	t0 = 90;
	a3 = 0x00000;
	asm("mult       $t1, $t0");
	s0 = a3 + 8528;
	s6 = 15;
	asm("mflo       $s7");
	t3 = *(s32*)(s0 + 4);

loc_00003C9C:		
	a1 = s0 + 448;
	t2 = t3 + s1;
	a0 = *(u8*)(t2 + 0);
	v0 = sub_00004138(...);
	s2 = v0 & 0xFFFF;
	if (s2 == 0)
	{
		s1 = s1 + 1;
		goto loc_00003CD8;
	}
	t5 = 11;
	if (s2 == s6)
		goto loc_00003DE4;
	if (s2 == t5)
	{
		t8 = *(s32*)(s0 + 8);
		goto loc_00003D74;
	}
	a3 = 12;

loc_00003CCC:		
	if (s2 == a3)
	{
		t5 = *(s32*)(s0 + 8);
		goto loc_00003D58;
	}

loc_00003CD4:		
	s1 = s1 + 1;

loc_00003CD8:		
	t6 = (u32)s1 < (u32)s3;
	if (t6 != 0)
	{
		t3 = *(s32*)(s0 + 4);
		goto loc_00003C9C;
	}

loc_00003CE4:		
	s3 = s2 - 11;
	s1 = (u32)s3 < (u32)2;
	s0 = s1 | s4;
	v0 = fp;
	if (s0 != 0)
		goto loc_00003D28;
	v0 = sceKernelGetSystemTimeLow(...);
	t8 = *(s32*)(sp + 0);
	t7 = 0x980000;
	s6 = t7 | 0x9680;
	s7 = v0 - t8;
	s2 = (u32)s6 < (u32)s7;
	if (s2 == 0)
	{
		a2 = *(s32*)(s5 + 456);
		goto loc_00003C48;
	}
	*(s32*)(s5 + 448) = 0;

loc_00003D20:		
	fp = -1;

loc_00003D24:		
	v0 = fp;

loc_00003D28:
	return (v0);

loc_00003D58:		
	t0 = 147;
	t4 = *(u8*)(t5 + 1);
	if (t4 != t0)
	{
		s1 = s1 + 1;
		goto loc_00003CD8;
	}
	fp = -1;
	s4 = 1;
	goto loc_00003CD4;

loc_00003D74:		
	t6 = 147;
	t7 = *(u8*)(t8 + 1);
	a3 = 12;
	if (t7 != t6)
		goto loc_00003CCC;
	a1 = *(s32*)(s0 + 28);
	a2 = *(s32*)(s0 + 20);
	s4 = 2;
	*(s32*)(a1 + 0) = s4;
	t3 = 0x00000;
	t1 = t3 + 8568;
	*(s32*)(a1 + 36) = a2;
	s4 = 1;
	v1 = *(s32*)(s0 + 40);
	fp = *(s32*)(sp + 4);
	*(s32*)(a1 + 8) = *(s32*)(s0 + 40);
	*(s32*)(a1 + 12) = *(s32*)(t1 + 4);
	*(s32*)(a1 + 16) = *(s32*)(t1 + 8);
	*(s32*)(a1 + 20) = *(s32*)(t1 + 12);
	t9 = *(s32*)(s0 + 28);
	a1 = *(s32*)(s0 + 24);
	a2 = *(s32*)(s0 + 20);
	a0 = t9 + 40;
	v0 = memcpy(...);
	s1 = s1 + 1;
	goto loc_00003CD8;

loc_00003DE4:		
	t6 = 0x00000;
	t5 = *(s32*)(t6 + 8528);
	t4 = 92;
	a1 = *(s32*)(sp + 4);
	if (t5 == t4)
		goto loc_00003E00;
	fp = -1;
	goto loc_00003CD4;

loc_00003E00:		
	t7 = (u32)a1 < (u32)32;
	if (t7 == 0)
	{
		fp = -1;
		goto loc_00003CD4;
	}
	t8 = (u32)a1 < (u32)12;
	t4 = *(s32*)(sp + 4);
	if (t8 == 0)
		goto loc_00003EC8;
	a1 = *(s32*)(s0 + 8);
	v0 = *(s32*)(s0 + 24);
	a2 = a1 + 2;
	a3 = s7 + v0;
	a0 = a2 | a3;
	t9 = a0 & 0x3;
	t0 = a1 + 82;
	if (t9 == 0)
		goto loc_00003ED8;
	v0 = t0;

loc_00003E3C:		
	asm("lwl        $t0, 3($a2)");
	asm("lwr        $t0, 0($a2)");
	asm("lwl        $v1, 7($a2)");
	asm("lwr        $v1, 4($a2)");
	asm("lwl        $a0, 11($a2)");
	asm("lwr        $a0, 8($a2)");
	asm("lwl        $a1, 15($a2)");
	asm("lwr        $a1, 12($a2)");
	asm("swl        $t0, 3($a3)");
	asm("swr        $t0, 0($a3)");
	asm("swl        $v1, 7($a3)");
	asm("swr        $v1, 4($a3)");
	asm("swl        $a0, 11($a3)");
	asm("swr        $a0, 8($a3)");
	asm("swl        $a1, 15($a3)");
	asm("swr        $a1, 12($a3)");
	a2 = a2 + 16;
	a3 = a3 + 16;
	if (a2 != v0)
		goto loc_00003E3C;
	asm("lwl        $t0, 3($a2)");
	asm("lwr        $t0, 0($a2)");
	asm("lwl        $v0, 7($a2)");
	asm("lwr        $v0, 4($a2)");
	v1 = *(s8*)(a2 + 8);
	a0 = *(s8*)(a2 + 9);
	asm("swl        $t0, 3($a3)");
	asm("swr        $t0, 0($a3)");
	asm("swl        $v0, 7($a3)");
	asm("swr        $v0, 4($a3)");
	*(s8*)(a3 + 8) = v1;
	*(s8*)(a3 + 9) = a0;
	a3 = *(s32*)(s0 + 20);

loc_00003EBC:		
	a2 = a3 + 90;
	*(s32*)(s0 + 20) = a2;
	t4 = *(s32*)(sp + 4);

loc_00003EC8:		
	s7 = s7 + 90;
	t0 = t4 + 1;
	*(s32*)(sp + 4) = t0;
	goto loc_00003CD4;

loc_00003ED8:		
	v1 = *(s32*)(a2 + 0);
	t3 = *(s32*)(a2 + 4);
	t2 = *(s32*)(a2 + 8);
	t1 = *(s32*)(a2 + 12);
	*(s32*)(a3 + 0) = v1;
	a2 = a2 + 16;
	a3 = a3 + 16;
	*(s32*)(a3 - 12) = t3;
	*(s32*)(a3 - 8) = t2;
	*(s32*)(a3 - 4) = t1;
	if (a2 != t0)
		goto loc_00003ED8;
	*(s32*)(a3 + 0) = *(s32*)(a2 + 0);
	*(s32*)(a3 + 4) = *(s32*)(a2 + 4);
	*(s16*)(a3 + 8) = *(s16*)(a2 + 8);
	a3 = *(s32*)(s0 + 20);
	goto loc_00003EBC;

loc_00003F24:		
	a0 = 2000;
	v0 = sceUsbRestart(...);
	goto loc_00003C6C;
}

sub_00003F34(...) // at 0x00003F34 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a0;
	v0 = sceKernelCpuSuspendIntr(...);
	s2 = v0;
	if (s0 == 0)
		goto loc_0000403C;
	*(s32*)(s0 + 0) = 0;
	t4 = 0x00000;
	t0 = t4 + 8568;
	*(s32*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 12) = 0;
	*(s32*)(s0 + 16) = 0;
	*(s32*)(s0 + 20) = 0;
	*(s32*)(s0 + 24) = 0;
	*(s32*)(s0 + 28) = 0;
	*(s32*)(s0 + 32) = 0;
	*(s32*)(s0 + 36) = 0;
	*(s32*)(s0 + 40) = 0;
	*(s32*)(s0 + 44) = 0;
	*(s32*)(s0 + 0) = *(s32*)(t4 + 8568);
	*(s32*)(s0 + 4) = *(s32*)(t0 + 4);
	*(s32*)(s0 + 8) = *(s32*)(t0 + 8);
	*(s32*)(s0 + 12) = *(s32*)(t0 + 12);
	v1 = *(u8*)(t0 + 40);
	a0 = v1 & 0x7;
	v0 = a0 ^ 0x6;
	a1 = a0 ^ 0x4;
	a2 = (u32)v0 < (u32)1;
	a3 = (u32)a1 < (u32)1;
	a1 = a2 | a3;
	v0 = 2;
	if (a1 != 0)
		goto loc_00003FEC;
	t6 = a0 - 1;
	t5 = (u32)t6 < (u32)5;
	if (t5 == 0)
	{
		*(s8*)(s0 + 21) = 0;
		goto loc_00003FF0;
	}
	v0 = 1;

loc_00003FEC:		
	*(s8*)(s0 + 21) = v0;

loc_00003FF0:		
	a0 = *(u8*)(s0 + 21);
	a1 = 0x00000;
	if (a0 != 0)
		goto loc_0000411C;
	*(s8*)(s0 + 20) = 0;

loc_00004000:		
	a2 = a1 + 8528;
	if (a0 == 0)
		goto loc_00004034;
	t9 = a1 + 8528;
	asm("lwc1       $fpr04, 68($t9)");
	asm("swc1       $fpr04, 40($s0)");
	asm("lwc1       $fpr03, 72($t9)");
	asm("swc1       $fpr03, 44($s0)");
	asm("lwc1       $fpr02, 56($t9)");
	asm("swc1       $fpr02, 24($s0)");
	asm("lwc1       $fpr00, 60($t9)");
	asm("swc1       $fpr00, 28($s0)");
	asm("lwc1       $fpr01, 64($t9)");
	asm("swc1       $fpr01, 32($s0)");

loc_00004034:		
	asm("lwc1       $fpr05, 76($a2)");
	asm("swc1       $fpr05, 16($s0)");

loc_0000403C:		
	a0 = s1;
	if (s1 == 0)
		goto loc_000040EC;
	a1 = 0;
	a2 = 260;
	s0 = 0x00000;
	v0 = memset(...);
	v0 = s0 + 8528;
	t5 = *(u8*)(v0 + 116);
	t6 = 0;
	t2 = 0;
	if (t5 == 0)
		goto loc_000040E8;
	t3 = v0;
	t0 = v0 + 120;
	a2 = s1;

loc_00004074:		
	v0 = *(u8*)(t0 + 0);
	a1 = v0 & 0xFF;
	if (a1 == 0)
	{
		t2 = t2 + 1;
		goto loc_000040DC;
	}
	a3 = *(u8*)(t3 + 81);
	*(s8*)(a2 + 4) = v0;
	t4 = a2 + 4;
	t1 = t3 + 82;
	t7 = *(u8*)(t0 + 1);
	a0 = 0;
	*(s8*)(a2 + 5) = t7;
	v0 = *(u16*)(t0 + 2);
	*(s16*)(a2 + 6) = v0;
	v1 = *(u8*)(t0 + 4);
	*(s8*)(a2 + 8) = v1;
	if (a3 == 0)
		goto loc_000040D0;
	t9 = t1 + a0;

loc_000040B8:		
	t8 = *(u8*)(t9 + 0);
	a0 = a0 + 1;
	v0 = (s32)a0 < (s32)a3;
	if (a1 == t8)
		goto loc_00004110;
	t9 = t1 + a0;
	if (v0 != 0)
		goto loc_000040B8;

loc_000040D0:		
	t6 = t6 + 1;
	a2 = a2 + 8;
	t2 = t2 + 1;

loc_000040DC:		
	a1 = (s32)t2 < (s32)t5;
	t0 = t0 + 10;
	if (a1 != 0)
		goto loc_00004074;

loc_000040E8:		
	*(s8*)(s1 + 0) = t6;

loc_000040EC:		
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = 0;
	sp = sp + 16;
	return (v0);

loc_00004110:		
	a3 = 1;
	*(s8*)(t4 + 5) = a3;
	goto loc_000040D0;

loc_0000411C:		
	t8 = a1 + 8528;
	t7 = *(s8*)(t8 + 80);
	v0 = 2;
	if ((s32)t7 < 0)
		goto loc_00004130;
	v0 = 1;

loc_00004130:		
	*(s8*)(s0 + 20) = v0;
	goto loc_00004000;
}

sub_00004138(...) // at 0x00004138 
{
	v1 = *(s32*)(a1 + 0);
	a2 = a0;
	a0 = (u32)v1 < (u32)9;
	a3 = 0;
	if (a0 == 0)
		goto loc_0000419C;
	t1 = 0x00000;
	t0 = v1 << 2;
	v0 = t1 + 22528;
	a0 = t0 + v0;
	v1 = *(s32*)(a0 + 0);
	v1;
	a0 = 0x00000;
	t6 = 0x00000;
	t5 = 0x00000;
	t4 = 0x00000;
	t3 = 0x00000;
	t2 = 160;
	*(s16*)(0x00000 + 8520) = 0;
	*(s16*)(0x00000 + 8522) = 0;
	*(s16*)(0x00000 + 8524) = 0;
	*(s16*)(0x00000 + 8526) = 0;
	*(s32*)(0x00000 + 8528) = 0;
	if (a2 == t2)
	{
		t7 = -24576;
		goto loc_000041A4;
	}

loc_0000419C:		
	v0 = a3;
	return (v0);

loc_000041A4:		
	a2 = 1;
	*(s16*)(a0 + 8520) = t7;
	*(s32*)(a1 + 0) = a2;
	goto loc_0000419C;
	t8 = 0x00000;
	t9 = *(u16*)(t8 + 8520);
	v1 = 2;
	*(s32*)(a1 + 0) = v1;
	a1 = t9 | a2;
	*(s16*)(t8 + 8520) = a1;
	goto loc_0000419C;
	t1 = a2 & 0xFFFF;
	a0 = 0x00000;
	t0 = t1 << 8;
	*(s16*)(a0 + 8524) = t0;
	a0 = 3;

loc_000041E4:		
	*(s32*)(a1 + 0) = a0;
	goto loc_0000419C;
	t2 = 0x00000;
	t3 = *(u16*)(t2 + 8524);
	t4 = 4;
	*(s32*)(a1 + 0) = t4;
	v0 = t3 | a2;
	*(s16*)(t2 + 8524) = v0;
	goto loc_0000419C;
	a0 = 0x00000;
	t6 = *(u16*)(a0 + 8524);
	t5 = (u32)t6 < (u32)1024;
	t0 = 0x00000;
	if (t5 == 0)
		goto loc_0000423C;
	t8 = *(s32*)(t0 + 8528);
	t7 = (u32)t8 < (u32)1023;
	v1 = t0 + 8528;
	if (t7 == 0)
		goto loc_0000423C;
	t1 = *(s32*)(v1 + 8);
	t2 = *(s32*)(t0 + 8528);
	t9 = t1 + t2;
	*(s8*)(t9 + 0) = a2;

loc_0000423C:		
	t3 = *(s32*)(t0 + 8528);
	v1 = t3 + 1;
	*(s32*)(t0 + 8528) = v1;
	v0 = *(u16*)(a0 + 8524);
	a0 = *(s32*)(t0 + 8528);
	t0 = v0 & 0xFFFF;
	a2 = (u32)a0 < (u32)t0;
	if (a2 != 0)
		goto loc_0000419C;
	t4 = 5;
	*(s32*)(a1 + 0) = t4;
	goto loc_0000419C;
	t7 = a2 & 0xFFFF;
	t6 = t7 << 8;
	t5 = 0x00000;
	a0 = 6;
	*(s16*)(t5 + 8526) = t6;
	*(s32*)(a1 + 0) = a0;
	goto loc_0000419C;
	t8 = 0x00000;
	t9 = *(u16*)(t8 + 8526);
	t1 = 7;
	*(s32*)(a1 + 0) = t1;
	a1 = t9 | a2;
	*(s16*)(t8 + 8526) = a1;
	goto loc_0000419C;
	a0 = a2 & 0xFFFF;
	a2 = a0 << 8;
	t2 = 0x00000;
	*(s16*)(t2 + 8522) = a2;
	a0 = 8;
	goto loc_000041E4;
	a0 = 0x00000;
	t5 = *(u16*)(a0 + 8522);
	v0 = 0x00000;
	t0 = 0xA0A2;
	t4 = t5 | a2;
	*(s16*)(a0 + 8522) = t4;
	t3 = *(u16*)(v0 + 8520);
	v1 = t3 & 0xFFFF;
	*(s32*)(a1 + 0) = 0;
	if (v1 != t0)
		goto loc_0000419C;
	t8 = *(u16*)(a0 + 8522);
	t6 = 0xB0B3;
	t7 = t8 & 0xFFFF;
	if (t7 != t6)
		goto loc_0000419C;
	t1 = 0x00000;
	t9 = *(u16*)(t1 + 8524);
	a1 = (u32)t9 < (u32)1024;
	if (a1 != 0)
	{
		t0 = 0x00000;
		goto loc_00004318;
	}
	t2 = 0x00000;
	*(s32*)(t2 + 8528) = 0;
	goto loc_0000419C;

loc_00004318:		
	t1 = *(s32*)(t0 + 8528);
	a0 = t0 + 8528;
	a2 = *(s32*)(a0 + 8);
	a1 = 0;
	a0 = 0;
	if (t1 == 0)
		goto loc_0000434C;

loc_00004330:		
	v1 = a2 + a1;
	t4 = *(u8*)(v1 + 0);
	a1 = a1 + 1;
	t3 = (u32)a1 < (u32)t1;
	v0 = a0 + t4;
	a0 = v0 & 0xFFFF;
	if (t3 != 0)
		goto loc_00004330;

loc_0000434C:		
	t7 = 0x00000;
	t6 = *(u16*)(t7 + 8526);
	a2 = a0 & 0x7FFF;
	t5 = t6 & 0xFFFF;
	if (t5 != a2)
		goto loc_0000419C;
	a3 = t0 + 8528;
	t0 = *(s32*)(a3 + 8);
	a3 = *(u8*)(t0 + 0);
	goto loc_0000419C;
}

sub_00004374(...) // at 0x00004374 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	v1 = 0x00000;
	a0 = v1 + 8528;
	*(s32*)(sp + 8) = s2;
	v1 = -1;
	s2 = 0;
	*(s32*)(sp + 4) = s1;
	s1 = 0;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 0) = s0;
	v0 = *(s32*)(a0 + 28);
	s0 = *(s32*)(a0 + 12);
	a1 = *(s32*)(v0 + 36);
	s5 = s0 + 4;
	if (a1 == 0)
		goto loc_000044CC;
	a3 = -107;
	*(s8*)(s0 + 4) = a3;
	a2 = *(s32*)(a0 + 28);
	a1 = *(s32*)(a2 + 36);
	s4 = a0;
	if (a1 == 0)
		goto loc_000044C8;
	s3 = s0 + 5;
	t2 = *(s32*)(s4 + 28);

loc_000043DC:		
	a3 = s3;
	t1 = t2 + s1;
	a2 = t1 + 40;
	t0 = a2 | s3;
	a0 = t0 & 0x3;
	t0 = t1 + 120;
	if (a0 == 0)
		goto loc_000044F4;
	v0 = t0;

loc_000043FC:		
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
	if (a2 != v0)
		goto loc_000043FC;
	asm("lwl        $v0, 3($a2)");
	asm("lwr        $v0, 0($a2)");
	asm("lwl        $v1, 7($a2)");
	asm("lwr        $v1, 4($a2)");
	a0 = *(s8*)(a2 + 8);
	a1 = *(s8*)(a2 + 9);
	asm("swl        $v0, 3($a3)");
	asm("swr        $v0, 0($a3)");
	asm("swl        $v1, 7($a3)");
	asm("swr        $v1, 4($a3)");
	*(s8*)(a3 + 8) = a0;
	*(s8*)(a3 + 9) = a1;
	a1 = s5;

loc_0000447C:		
	a0 = s0;
	a2 = 91;
	v0 = sub_00004B60(...);
	a0 = s0;
	a1 = 99;
	v0 = sub_00002888(...);
	if ((s32)v0 < 0)
	{
		s2 = -1;
		goto loc_000044B0;
	}
	a0 = 149;
	v0 = sub_000049D8(...);
	t8 = (s32)v0 < (s32)0;
	t7 = -1;
	if (t8 != 0)
		s2 = t7;

loc_000044B0:		
	v0 = *(s32*)(s4 + 28);
	s1 = s1 + 90;
	a1 = *(s32*)(v0 + 36);
	t9 = (u32)s1 < (u32)a1;
	if (t9 != 0)
	{
		t2 = *(s32*)(s4 + 28);
		goto loc_000043DC;
	}

loc_000044C8:		
	v1 = s2;

loc_000044CC:		
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

loc_000044F4:		
	t6 = *(s32*)(a2 + 0);
	t5 = *(s32*)(a2 + 4);
	t4 = *(s32*)(a2 + 8);
	t3 = *(s32*)(a2 + 12);
	*(s32*)(a3 + 0) = t6;
	a2 = a2 + 16;
	a3 = a3 + 16;
	*(s32*)(a3 - 12) = t5;
	*(s32*)(a3 - 8) = t4;
	*(s32*)(a3 - 4) = t3;
	if (a2 != t0)
		goto loc_000044F4;
	t0 = *(s32*)(a2 + 0);
	v0 = *(s32*)(a2 + 4);
	v1 = *(s16*)(a2 + 8);
	*(s32*)(a3 + 0) = t0;
	*(s32*)(a3 + 4) = v0;
	*(s16*)(a3 + 8) = v1;
	a1 = s5;
	goto loc_0000447C;
}

sub_00004540(...) // at 0x00004540 
{
	a1 = 0x00000;
	v1 = a1 + 8528;
	a3 = *(s32*)(v1 + 8);
	v0 = *(s32*)(a1 + 8528);
	v1 = 91;
	t0 = a0;
	t1 = 0;
	a2 = a3 + 1;
	if (v0 == v1)
		goto loc_00004570;
	t1 = -1;

loc_00004568:		
	v0 = t1;
	return (v0);

loc_00004570:		
	t2 = *(u8*)(a3 + 1);
	t6 = *(u8*)(a2 + 1);
	t5 = 0x10620000;
	t9 = t2 << 8;
	a0 = t6 | t9;
	*(s16*)(t0 + 0) = a0;
	t6 = t5 | 0x4DD3;
	t5 = a3 + 19;
	t8 = *(u8*)(a3 + 11);
	t7 = *(u8*)(a3 + 12);
	at = 0x4B180000;
	at = at | 0x9680;
	asm("mtc1       $at, $fcr19");
	v1 = t8 << 8;
	t4 = t7 | v1;
	*(s16*)(t0 + 8) = t4;
	at = 0x42C80000;
	asm("mtc1       $at, $fcr6");
	at = 0x42100000;
	asm("mtc1       $at, $fcr12");
	t3 = *(u8*)(a3 + 13);
	at = 0x447A0000;
	asm("mtc1       $at, $fcr10");
	at = 0x40A00000;
	asm("mtc1       $at, $fcr0");
	*(s16*)(t0 + 10) = t3;
	*(s16*)(t0 + 12) = *(u8*)(a3 + 14);
	*(s16*)(t0 + 14) = *(u8*)(a3 + 15);
	*(s16*)(t0 + 16) = *(u8*)(a3 + 16);
	v0 = a3 + 23;
	t2 = *(u8*)(a3 + 17);
	t9 = *(u8*)(a3 + 18);
	*(s32*)(t0 + 20) = 0;
	t8 = t2 << 8;
	t7 = t8 | t9;
	asm("mult       $t7, $t6");
	asm("mfhi       $v1");
	a0 = (s32)v1 >> 6;
	*(s16*)(t0 + 18) = a0;
	t3 = *(u8*)(t5 + 1);
	t4 = *(u8*)(a3 + 19);
	t2 = *(u8*)(t5 + 2);
	t7 = *(u8*)(t5 + 3);
	a2 = t4 << 24;
	a1 = t3 << 16;
	t8 = a2 | a1;
	t9 = t2 << 8;
	t6 = t8 | t9;
	t5 = t6 | t7;
	*(s32*)(t0 + 4) = t5;
	t6 = a3 + 27;
	a0 = *(u8*)(v0 + 1);
	v1 = *(u8*)(a3 + 23);
	a1 = *(u8*)(v0 + 2);
	t9 = *(u8*)(v0 + 3);
	t3 = v1 << 24;
	t4 = a0 << 16;
	t2 = t3 | t4;
	a2 = a1 << 8;
	t8 = t2 | a2;
	t7 = t8 | t9;
	asm("mtc1       $t7, $fcr4");
	v0 = a3 + 35;
	asm("cvt.s.w    $fpr02, $fpr04");
	asm("div.s      $fpr03, $fpr02, $fpr19");
	asm("swc1       $fpr03, 24($t0)");
	a0 = *(u8*)(t6 + 1);
	t5 = *(u8*)(a3 + 27);
	a1 = *(u8*)(t6 + 2);
	t2 = *(u8*)(t6 + 3);
	t3 = t5 << 24;
	t4 = a0 << 16;
	a2 = t3 | t4;
	v1 = a1 << 8;
	t9 = a2 | v1;
	t8 = t9 | t2;
	asm("mtc1       $t8, $fcr1");
	asm("cvt.s.w    $fpr18, $fpr01");
	asm("div.s      $fpr17, $fpr18, $fpr19");
	asm("swc1       $fpr17, 28($t0)");
	t7 = *(u8*)(a3 + 35);
	t6 = *(u8*)(v0 + 1);
	t4 = *(u8*)(v0 + 2);
	t2 = *(u8*)(v0 + 3);
	a0 = t7 << 24;
	t5 = t6 << 16;
	a1 = a0 | t5;
	t3 = t4 << 8;
	a2 = a1 | t3;
	v1 = a2 | t2;
	asm("mtc1       $v1, $fcr16");
	asm("cvt.s.w    $fpr15, $fpr16");
	asm("div.s      $fpr14, $fpr15, $fpr06");
	asm("swc1       $fpr14, 32($t0)");
	t9 = *(u8*)(a3 + 40);
	t8 = *(u8*)(a3 + 41);
	t7 = t9 << 8;
	t6 = t7 | t8;
	asm("mtc1       $t6, $fcr13");
	asm("cvt.s.w    $fpr11, $fpr13");
	asm("mul.s      $fpr09, $fpr11, $fpr12");
	asm("div.s      $fpr08, $fpr09, $fpr10");
	asm("swc1       $fpr08, 36($t0)");
	t5 = *(u8*)(a3 + 42);
	t4 = *(u8*)(a3 + 43);
	t3 = t5 << 8;
	t2 = t3 | t4;
	asm("mtc1       $t2, $fcr7");
	asm("cvt.s.w    $fpr05, $fpr07");
	asm("div.s      $fpr04, $fpr05, $fpr06");
	asm("swc1       $fpr04, 40($t0)");
	a2 = *(u8*)(a3 + 88);
	*(s16*)(t0 + 2) = a2;
	a0 = *(u8*)(a3 + 89);
	asm("mtc1       $a0, $fcr2");
	asm("cvt.s.w    $fpr03, $fpr02");
	asm("div.s      $fpr01, $fpr03, $fpr00");
	asm("swc1       $fpr01, 44($t0)");
	goto loc_00004568;
}

sub_00004758(...) // at 0x00004758 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	v1 = 0x00000;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	s2 = v1 + 8528;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	a0 = 41;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(v1 + 8528);
	s0 = *(s32*)(s2 + 8);
	a1 = s0 + 1;
	if (a2 == a0)
		goto loc_000047B8;
	s3 = -1;

loc_00004798:		
	v0 = s3;

loc_0000479C:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000047B8:		
	t2 = *(u8*)(a1 + 1);
	t3 = *(u8*)(s0 + 1);
	t0 = *(u8*)(a1 + 2);
	a2 = *(u8*)(a1 + 3);
	a0 = t3 << 24;
	t1 = t2 << 16;
	a3 = a0 | t1;
	v1 = t0 << 8;
	t9 = a3 | v1;
	t8 = t9 | a2;
	*(s32*)(sp + 0) = t8;
	v0 = s0 + 5;
	v1 = s0 + 9;
	t6 = *(u8*)(v0 + 1);
	t7 = *(u8*)(s0 + 5);
	t3 = *(u8*)(v0 + 2);
	t0 = *(u8*)(v0 + 3);
	t4 = t7 << 24;
	t5 = t6 << 16;
	t1 = t4 | t5;
	t2 = t3 << 8;
	a3 = t1 | t2;
	a0 = a3 | t0;
	*(s32*)(sp + 4) = a0;
	a2 = *(u8*)(s0 + 9);
	t9 = *(u8*)(v1 + 1);
	t6 = *(u8*)(v1 + 2);
	t3 = *(u8*)(v1 + 3);
	t7 = a2 << 24;
	t8 = t9 << 16;
	t4 = t7 | t8;
	t5 = t6 << 8;
	t2 = t4 | t5;
	t1 = t2 | t3;
	*(s32*)(sp + 8) = t1;
	v0 = *(u8*)(s0 + 19);
	*(s8*)(s1 + 0) = v0;
	t0 = *(u8*)(s2 + 80);
	a3 = t0 & 0x7;
	a1 = a3 - 1;
	a0 = (u32)a1 < (u32)6;
	if (a0 != 0)
		goto loc_000048A0;
	t6 = *(u8*)(s0 + 28);

loc_00004868:		
	a1 = s0 + 29;
	a2 = 0;
	*(s8*)(s1 + 1) = t6;
	if (t6 == 0)
		goto loc_00004798;
	a3 = t6;

loc_0000487C:		
	t8 = *(u8*)(a1 + 0);
	t7 = s1 + a2;
	a2 = a2 + 1;
	s0 = (s32)a2 < (s32)a3;
	*(s8*)(t7 + 2) = t8;
	a1 = a1 + 1;
	if (s0 != 0)
		goto loc_0000487C;
	v0 = s3;
	goto loc_0000479C;

loc_000048A0:		
	v0 = sceKernelCpuSuspendIntr(...);
	t4 = *(s32*)(s2 + 28);
	t5 = *(s32*)(sp + 0);
	a0 = v0;
	*(s32*)(t4 + 24) = t5;
	a1 = *(s32*)(sp + 4);
	*(s32*)(t4 + 28) = a1;
	s2 = *(s32*)(sp + 8);
	*(s32*)(t4 + 32) = s2;
	v0 = sceKernelCpuResumeIntr(...);
	t6 = *(u8*)(s0 + 28);
	goto loc_00004868;
}

sub_000048D4(...) // at 0x000048D4 
{
	a2 = 0x00000;
	a3 = *(s32*)(a2 + 8528);
	v1 = a2 + 8528;
	t1 = a0;
	a0 = 188;
	a2 = *(s32*)(v1 + 8);
	t3 = 0;
	*(s8*)(a1 + 0) = 0;
	if (a3 == a0)
		goto loc_00004904;
	t3 = -1;

loc_000048FC:		
	v0 = t3;
	return (v0);

loc_00004904:		
	a0 = *(u8*)(a2 + 7);
	t0 = 0;
	a2 = a2 + 8;
	*(s8*)(t1 + 0) = a0;
	if (a0 == 0)
		goto loc_000048FC;
	t2 = 63;
	t4 = 1;
	a3 = t1;

loc_00004924:		
	a0 = *(u8*)(a2 + 0);
	t9 = a2 + 1;
	t5 = t9 + 1;
	*(s8*)(a3 + 4) = a0;
	t0 = t0 + 1;
	t8 = *(u8*)(t9 + 0);
	t9 = t5 + 1;
	a2 = t9 + 2;
	t7 = t8 << 1;
	t6 = t7 + t8;
	v1 = (s32)t6 >> 1;
	*(s16*)(a3 + 6) = v1;
	v0 = *(u8*)(t5 + 0);
	a0 = (u32)v0 >> 1;
	*(s8*)(a3 + 5) = a0;
	t8 = *(u8*)(t9 + 0);
	t6 = *(u8*)(t9 + 1);
	t7 = t8 << 8;
	t5 = t6 | t7;
	v0 = t5 & 0xFFFF;
	*(s16*)(a3 + 10) = t5;
	if (v0 == t2)
		goto loc_000049A0;

loc_0000497C:		
	t6 = *(u8*)(a2 + 0);
	a2 = a2 + 10;
	*(s8*)(a3 + 8) = t6;
	v1 = *(u8*)(t1 + 0);
	t5 = (s32)t0 < (s32)v1;
	a3 = a3 + 10;
	if (t5 != 0)
		goto loc_00004924;
	goto loc_000048FC;

loc_000049A0:		
	*(s8*)(a1 + 0) = t4;
	goto loc_0000497C;
}

sub_000049A8(...) // at 0x000049A8 
{
	a1 = 0x00000;
	v1 = *(s32*)(a1 + 8528);
	a3 = 2;
	a2 = -1;
	v0 = a1 + 8528;
	if (v1 != a3)
		goto loc_000049D0;
	t0 = *(s32*)(v0 + 8);
	a2 = 0;
	a3 = *(u8*)(t0 + 1);
	*(s32*)(a0 + 0) = a3;

loc_000049D0:		
	v0 = a2;
	return (v0);
}

sub_000049D8(...) // at 0x000049D8 
{
	sp = sp - 64;
	*(s32*)(sp + 48) = fp;
	v0 = 0x00000;
	fp = a0;
	*(s32*)(sp + 20) = s1;
	s1 = v0 + 8528;
	*(s32*)(sp + 52) = ra;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 16) = s0;
	s6 = *(s32*)(s1 + 4);
	v0 = sceKernelGetSystemTimeLow(...);
	a1 = 0x80020000;
	a0 = 0x980000;
	*(s32*)(sp + 4) = v0;
	v1 = a1 | 0x1A8;
	v0 = a0 | 0x9680;
	*(s32*)(s1 + 448) = 0;
	*(s32*)(sp + 0) = 0;
	*(s32*)(sp + 8) = v1;
	*(s32*)(sp + 12) = v0;
	t0 = 0x00000;

loc_00004A40:		
	a3 = t0 + 8528;
	a2 = *(s32*)(a3 + 456);
	a0 = s6;
	a1 = 128;
	v0 = sub_000028F4(...);
	a2 = *(s32*)(sp + 8);
	s2 = v0;
	s1 = 0;
	if (v0 == a2)
		goto loc_00004B50;

loc_00004A64:		
	if ((s32)s2 < 0)
	{
		*(s32*)(sp + 0) = s2;
		goto loc_00004AF0;
	}
	s0 = 0;
	if (s2 == 0)
		goto loc_00004AB8;
	t2 = 0x00000;
	s4 = t2 + 8976;
	s5 = 11;
	s7 = s4 - 448;
	s3 = 12;
	t3 = s6 + s0;

loc_00004A8C:		
	a0 = *(u8*)(t3 + 0);
	a1 = s4;
	s0 = s0 + 1;
	v0 = sub_00004138(...);
	s1 = v0;
	a0 = (u32)s0 < (u32)s2;
	if (v0 == s5)
		goto loc_00004B38;

loc_00004AA8:		
	if (s1 == s3)
	{
		t7 = *(s32*)(s7 + 8);
		goto loc_00004B24;
	}

loc_00004AB0:		
	t3 = s6 + s0;
	if (a0 != 0)
		goto loc_00004A8C;

loc_00004AB8:		
	s2 = s1 - 11;

loc_00004ABC:		
	s0 = (u32)s2 < (u32)2;
	v0 = *(s32*)(sp + 0);
	if (s0 != 0)
		goto loc_00004AF4;
	v0 = sceKernelGetSystemTimeLow(...);
	s7 = *(s32*)(sp + 4);
	s5 = *(s32*)(sp + 12);
	s4 = v0 - s7;
	s3 = (u32)s5 < (u32)s4;
	t0 = 0x00000;
	if (s3 == 0)
		goto loc_00004A40;
	s6 = -1;
	*(s32*)(sp + 0) = s6;

loc_00004AF0:		
	v0 = *(s32*)(sp + 0);

loc_00004AF4:		
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

loc_00004B24:		
	t6 = *(u8*)(t7 + 1);
	t1 = -1;
	if (t6 != fp)
		goto loc_00004AB0;
	*(s32*)(sp + 0) = t1;
	goto loc_00004AB8;

loc_00004B38:		
	t5 = *(s32*)(s7 + 8);
	t4 = *(u8*)(t5 + 1);
	if (t4 != fp)
		goto loc_00004AA8;
	s2 = s1 - 11;
	goto loc_00004ABC;

loc_00004B50:		
	a0 = 2000;
	v0 = sceUsbRestart(...);
	goto loc_00004A64;
}

sub_00004B60(...) // at 0x00004B60 
{
	sp = sp - 16;
	*(s16*)(sp + 2) = a2;
	t1 = a0;
	a3 = -96;
	a0 = *(u8*)(sp + 3);
	t3 = *(u8*)(sp + 2);
	v1 = -94;
	t2 = a2 & 0xFFFF;
	*(s8*)(t1 + 0) = a3;
	t0 = 0;
	a3 = 0;
	*(s8*)(t1 + 1) = v1;
	*(s8*)(t1 + 2) = a0;
	*(s8*)(t1 + 3) = t3;
	if (t2 == 0)
		goto loc_00004BB8;

loc_00004B9C:		
	t5 = a1 + a3;
	t4 = *(u8*)(t5 + 0);
	a3 = a3 + 1;
	t3 = (u32)a3 < (u32)t2;
	v0 = t0 + t4;
	t0 = v0 & 0xFFFF;
	if (t3 != 0)
		goto loc_00004B9C;

loc_00004BB8:		
	t6 = t0 & 0x7FFF;
	*(s16*)(sp + 0) = t6;
	a1 = t1 + a2;
	t1 = -77;
	t2 = *(u8*)(sp + 1);
	a2 = -80;
	*(s8*)(a1 + 4) = t2;
	t0 = *(u8*)(sp + 0);
	*(s8*)(a1 + 7) = t1;
	*(s8*)(a1 + 5) = t0;
	*(s8*)(a1 + 6) = a2;
	sp = sp + 16;
	return (v0);
}

sub_00004BEC(...) // at 0x00004BEC 
{
	sp = sp - 32;
	t1 = 0x00000;
	*(s32*)(sp + 4) = s1;
	t0 = a0;
	v1 = a1;
	s1 = *(s32*)(t1 + 8540);
	*(s32*)(sp + 8) = s2;
	a1 = 0;
	s2 = a2;
	a0 = s1;
	a2 = 25;
	*(s32*)(sp + 16) = s4;
	s4 = t0 & 0xFF;
	*(s32*)(sp + 12) = s3;
	s3 = v1 & 0xFFFF;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = a3;
	v0 = memset(...);
	v1 = -128;
	t0 = s1 + 4;
	a2 = 25;
	a3 = (u32)s2 >> 24;
	t1 = (s2 >> 16) & (0xFFFFFFFF >> (32 - 8));;
	t2 = (s2 >> 8) & (0xFFFFFFFF >> (32 - 8));;
	t3 = (u32)s3 >> 8;
	a0 = s1;
	*(s8*)(s1 + 4) = v1;
	a1 = t0;
	if (s0 == 0)
		goto loc_00004CC4;

	*(s8*)(t0 + 1) = *(u8*)(s0 + 3);
	*(s8*)(t0 + 2) = *(u8*)(s0 + 2);
	*(s8*)(t0 + 3) = *(u8*)(s0 + 1);
	*(s8*)(t0 + 4) = *(u8*)(s0 + 0);
	*(s8*)(t0 + 5) = *(u8*)(s0 + 7);
	*(s8*)(t0 + 6) = *(u8*)(s0 + 6);
	*(s8*)(t0 + 7) = *(u8*)(s0 + 5);
	*(s8*)(t0 + 8) = *(u8*)(s0 + 4);
	*(s8*)(t0 + 9) = *(u8*)(s0 + 11);
	*(s8*)(t0 + 10) = *(u8*)(s0 + 10);
	*(s8*)(t0 + 11) = *(u8*)(s0 + 9);
	*(s8*)(t0 + 12) = *(u8*)(s0 + 8);

loc_00004CC4:		
	*(s8*)(t0 + 17) = a3;
	a3 = 12;
	*(s8*)(t0 + 18) = t1;
	*(s8*)(t0 + 19) = t2;
	*(s8*)(t0 + 21) = t3;
	*(s8*)(t0 + 23) = a3;
	*(s8*)(t0 + 20) = s2;
	*(s8*)(t0 + 22) = s3;
	*(s8*)(t0 + 24) = s4;
	v0 = sub_00004B60(...);
	a0 = s1;
	a1 = 33;
	v0 = sub_00002888(...);
	a0 = 128;
	v1 = -1;
	if ((s32)v0 < 0)
		goto loc_00004D18;
	v0 = sub_000049D8(...);
	a0 = (s32)v0 < (s32)0;
	v1 = -1;
	if (a0 == 0)
		v1 = 0;

loc_00004D18:
	return (v1);
}

sub_00004D3C(...) // at 0x00004D3C 
{
	sp = sp - 16;
	t0 = 0x00000;
	*(s32*)(sp + 4) = s1;
	a2 = 17;
	s1 = *(s32*)(t0 + 8540);
	*(s32*)(sp + 8) = s2;
	s2 = a0 & 0xFFFF;
	a0 = s1;
	*(s32*)(sp + 0) = s0;
	s0 = a1 & 0xFFFF;
	*(s32*)(sp + 12) = ra;
	a1 = 0;
	v0 = memset(...);
	t0 = s1 + 4;
	v1 = (u32)s2 >> 8;
	a3 = (u32)s0 >> 8;
	a0 = -105;
	*(s8*)(s1 + 4) = a0;
	a1 = t0;
	a2 = 9;
	*(s8*)(t0 + 7) = v1;
	a0 = s1;
	*(s8*)(t0 + 3) = a3;
	*(s8*)(t0 + 4) = s0;
	*(s8*)(t0 + 8) = s2;
	v0 = sub_00004B60(...);
	a0 = s1;
	a1 = 17;
	v0 = sub_00002888(...);
	a0 = 151;
	v1 = -1;
	if ((s32)v0 < 0)
		goto loc_00004DD0;
	v0 = sub_000049D8(...);
	a1 = (s32)v0 < (s32)0;
	v1 = -1;
	if (a1 == 0)
		v1 = 0;

loc_00004DD0:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_00004DEC(...) // at 0x00004DEC 
{
	v0 = 0x00000;
	sp = sp - 16;
	a0 = v0 + 22416;
	*(s32*)(sp + 0) = ra;
	a1 = 23;
	v0 = sub_00002888(...);
	a0 = 167;
	if ((s32)v0 < 0)
		goto loc_00004E1C;
	v0 = sub_000049D8(...);
	a0 = 0;
	asm("min        $v0, $v0, $a0");

loc_00004E1C:		
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00004E28(...) // at 0x00004E28 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = ra;
	v1 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = v1 + 22440;
	*(s32*)(sp + 0) = s0;
	s0 = 0;
	a0 = s1;

loc_00004E48:		
	a1 = 16;
	v0 = sub_00002888(...);
	s0 = s0 + 1;
	a0 = 166;
	s1 = s1 + 16;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00004E84;
	v0 = sub_000049D8(...);
	v1 = v0;
	a0 = (s32)s0 < (s32)4;
	if ((s32)v0 < 0)
		goto loc_00004E84;
	cond = (a0 != 0);
	a0 = s1;
	if (cond)
		goto loc_00004E48;
	v1 = 0;

loc_00004E84:
	return (v1);
}

sub_00004E9C(...) // at 0x00004E9C 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 4) = s1;
	s1 = v1 + 8528;
	a1 = 1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = *(s32*)(s1 + 440);
	*(s32*)(sp + 8) = ra;
	a2 = 0;
	v0 = sceKernelWaitSema(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00004EEC;
	v0 = sceUsbGetState(...);
	*(s32*)(s0 + 0) = v0;
	a1 = 1;
	a0 = *(s32*)(s1 + 440);
	v0 = sceKernelSignalSema(...);
	v1 = 0;

loc_00004EEC:
	return (v1);
}

sub_00004F04(...) // at 0x00004F04 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	v1 = s1 + 8528;
	a3 = a0;
	a0 = *(s32*)(v1 + 440);
	a2 = 0;
	a1 = 1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = a3 & 0xFF;
	v0 = sceKernelWaitSema(...);
	a2 = 0x00000;
	a0 = a2 + 22504;
	a1 = 10;
	a2 = v0;
	if ((s32)v0 < 0)
		goto loc_00004F90;
	a2 = 1;
	t0 = 0x00000;
	if (s0 == a2)
		goto loc_00004F58;
	a0 = t0 + 22516;

loc_00004F58:		
	v0 = sub_00002888(...);
	s0 = v0;
	a0 = 143;
	if ((s32)v0 < 0)
		goto loc_00004F7C;
	v0 = sub_000049D8(...);
	a0 = 0;
	asm("min        $s0, $v0, $a0");

loc_00004F7C:		
	t2 = s1 + 8528;
	a0 = *(s32*)(t2 + 440);
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	a2 = s0;

loc_00004F90:		
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 16;
	return (v0);
}
