/*

130 typedef struct PspUsbCamSetupStillParam {
132         int size;
134         int resolution;
136         int     jpegsize;
138         int reverseflags;
140         int delay;
143         int complevel;
144 } PspUsbCamSetupStillParam;
145
147 typedef struct PspUsbCamSetupStillExParam {
149         int size;
151         u32 unk;
153         int resolution;
155         int jpegsize;
158         int complevel;
160         u32 unk2;
162         u32 unk3;
164         int flip;
166         int mirror;
168         int delay;
170         u32 unk4[5];
171 } PspUsbCamSetupStillExParam;
172
173 typedef struct PspUsbCamSetupVideoParam {
175         int size;
177         int resolution;
179         int framerate;
181         int wb;
183         int saturation;
185         int brightness;
187         int contrast;
189         int sharpness;
191         int effectmode;
193         int framesize;
195         u32 unk;
197         int evlevel;
198 } PspUsbCamSetupVideoParam;
199
200 typedef struct PspUsbCamSetupVideoExParam {
202         int size;
203 // Unknown. Set it to 9 at the moment.
204         u32 unk;
206         int resolution;
208         int framerate;
210         u32 unk2;
212         u32 unk3;
214         int wb;
216         int saturation;
218         int brightness;
220         int contrast;
222         int sharpness;
224         u32 unk4;
226         u32 unk5;
228         u32 unk6[3];
230         int effectmode;
232         u32 unk7;
234         u32 unk8;
236         u32 unk9;
238         u32 unk10;
240         u32 unk11;
242         int framesize;
244         u32 unk12;
246         int evlevel;
247 } PspUsbCamSetupVideoExParam;
248
*/

typedef struct
{
	void	*ctx;
	void	*unk1;
	int	unk2;
	int	unk3;
	void	*onSuspend;
	void	*onResume;
	int	event;
	short	state;
	short	unk15s;
	int	unk8;
	int	unk9;
	int	unk10;
	int	unk11;
	int	unk12;
	short	unk26;
	short	unk27;
	int	unk14;
	int	unk15;
} DmaOp;

sub_00000000(...) // at 0x00000000 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	v1 = 0x00000;
	v0 = 0x80240000;
	*(s32*)(sp + 16) = s4;
	s5 = a3;
	s4 = a2;
	*(s32*)(sp + 12) = s3;
	a2 = 0;
	s3 = a1;
	*(s32*)(sp + 8) = s2;
	a1 = 1;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	s1 = v1 + 1312;
	*(s32*)(sp + 0) = s0;
	s0 = s1 - 68;
	*(s32*)(sp + 24) = ra;
	v1 = *(s8*)(s0 + 2);
	t0 = v0 | 0x3902;
	if (v1 == 0)
		goto loc_000000B8;
	a0 = *(s32*)(s0 + 404);
	v0 = sceKernelWaitSema(...);
	a1 = 0x80020000;
	a0 = a1 | 0x1A9;
	t0 = 0;
	if (v0 == a0)
		goto loc_000000B8;
	t0 = v0;
	if ((s32)v0 < 0)
		goto loc_000000B8;
	a2 = *(s32*)(s1 + 24);
	a1 = 1;
	if ((s32)a2 > 0)
	{
		a0 = *(s32*)(s0 + 404);
		v0 = sceKernelSignalSema(...);
		a3 = 0x80240000;
		t0 = a3 | 0x3006;
		goto loc_000000B8;
	}
	t1 = *(s32*)(s0 + 108);
	a1 = s4;
	a2 = s5;
	*(s8*)(t1 + 2) = s2;
	t0 = *(s32*)(s0 + 108);
	*(s16*)(t1 + 0) = s3;
	*(s8*)(t0 + 3) = s5;
	if (s4 == 0)
		goto loc_000000AC;
	t2 = *(s32*)(s0 + 108);
	a0 = t2 + 4;
	v0 = memcpy(...);

loc_000000AC:		
	a0 = s1;
	v0 = sceUsbAcc_internal_2A100C1F(...);
	t0 = v0;

loc_000000B8:
	return (t0);
}

sub_000000F4(...) // at 0x000000F4 
{
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 8) = s2;
	s2 = v1 + 1244;
	a1 = 1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	a0 = *(s32*)(s2 + 408);
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 12) = ra;
	a2 = 0;
	v0 = sceKernelLockMutex(...);
	s1 = v0;
	a2 = s0;
	a0 = 171;
	a1 = 2;
	a3 = 2;
	if ((s32)v0 < 0)
		goto loc_00000154;
	v0 = sub_00000000(...);
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	s1 = v0;
	v0 = sceKernelUnlockMutex(...);

loc_00000154:
	return (s1);
}

sub_00000170(...) // at 0x00000170 
{
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	a2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = s3 + 1244;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(s1 + 408);
	v0 = sceKernelLockMutex(...);
	a2 = 0x7FFD0000;
	a0 = a2 | 0xFE57;
	v1 = v0 + a0;
	a0 = (u32)v1 < (u32)2;
	a1 = 0x80240000;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_00000244;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00000244;
	a0 = *(s32*)(s1 + 400);
	v0 = 0xFFFE0000;
	a1 = v0 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	a0 = 43;
	a1 = 2;
	a2 = 0;
	a3 = 0;
	v0 = sub_00000000(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00000230;
	a0 = *(s32*)(s1 + 400);
	a3 = 0x10000;
	a1 = a3 | 0x400;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00000230;
	t1 = *(s32*)(sp + 0);
	t0 = t1 & 0x400;
	if (t0 == 0)
	{
		t4 = *(s32*)(s1 + 108);
		goto loc_00000264;
	}
	t2 = 0x80240000;
	s0 = t2 | 0x3902;

loc_00000230:
	v1 = s3 + 1244;
	a0 = *(s32*)(v1 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;

loc_00000244:
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00000264:
	a0 = 0x10000;
	asm("lwl        $v1, 7($t4)");
	asm("lwr        $v1, 4($t4)");
	asm("swl        $v1, 3($s2)");
	asm("swr        $v1, 0($s2)");
	v1 = *(s32*)(s2 + 0);
	NONE;
	t3 = v1 & a0;
	*(s32*)(s2 + 0) = v1;
	if (t3 == 0)
		goto loc_00000314;
	NONE;
	*(s32*)(s2 + 0) = v1;

loc_00000294:
	t7 = *(s32*)(s2 + 0);
	t6 = t7 & 0x1;
	v1 = s3 + 1244;
	if (t6 == 0)
		goto loc_00000308;
	s1 = *(s32*)(v1 + 8);
	v0 = s1 | 0x200;

loc_000002AC:
	*(s32*)(v1 + 8) = v0;
	t9 = *(s32*)(s2 + 0);
	t8 = t9 & 0x100;
	v1 = s3 + 1244;
	if (t8 == 0)
		goto loc_000002FC;
	a1 = *(s32*)(v1 + 8);
	v0 = a1 | 0x100;

loc_000002C8:
	*(s32*)(v1 + 8) = v0;
	a2 = 0x10000;
	a0 = *(s32*)(s2 + 0);
	s2 = a0 & a2;
	v1 = s3 + 1244;
	if (s2 == 0)
		goto loc_000002F0;
	a3 = *(s32*)(v1 + 8);
	v0 = a3 | 0x400;

loc_000002E8:
	*(s32*)(v1 + 8) = v0;
	goto loc_00000230;

loc_000002F0:
	v0 = *(s32*)(v1 + 8);
	NONE;
	goto loc_000002E8;

loc_000002FC:
	v0 = *(s32*)(v1 + 8);
	NONE;
	goto loc_000002C8;

loc_00000308:
	v0 = *(s32*)(v1 + 8);
	NONE;
	goto loc_000002AC;

loc_00000314:
	t5 = v1 | a0;
	*(s32*)(s2 + 0) = t5;
	goto loc_00000294;
}

sub_320()
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	if (a0 != 0)
		goto loc_00000384;
	t1 = 1;
	if (a1 != 0)
		goto loc_0000040C;
	s2 = 0x00000;
	s0 = s2 + 1244;
	v0 = *(s8*)(s0 + 3);
	a0 = 1;
	if (v0 == a0)
	{
		a0 = *(s32*)(s0 + 8);
		goto loc_000003B8;
	}
	a0 = *(s32*)(s0 + 400);
	a1 = -12545;
	v0 = sceKernelClearEventFlag(...);
	t0 = *(s32*)(s0 + 436);
	*(s32*)(s0 + 364) = 0;
	a3 = (u32)t0 < (u32)1280;
	*(s32*)(s0 + 368) = 0;
	if (a3 != 0)
		goto loc_0000039C;

loc_0000037C:
	t4 = s2 + 1244;

loc_00000380:
	*(s8*)(t4 + 3) = s1;

loc_00000384:
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_0000039C:
	a0 = *(s32*)(s0 + 292);
	a1 = 128;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s0 + 252;
	v0 = sceUsbbdReqRecv(...);
	t4 = s2 + 1244;
	goto loc_00000380;

loc_000003B8:
	v1 = a0 & 0x18;
	a0 = *(s32*)(s0 + 400);
	if (v1 == 0)
		goto loc_000003EC;
	a2 = 0xFFF70000;
	a1 = a2 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 256;
	v0 = sceKernelSetEventFlag(...);
	a1 = *(s32*)(s0 + 8);
	NONE;
	*(s32*)(s0 + 8) = a1;
	goto loc_0000037C;

loc_000003EC:
	*(s8*)(s0 + 5) = 0;
	a1 = -17;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 256;
	v0 = sceKernelSetEventFlag(...);
	t4 = s2 + 1244;
	goto loc_00000380;

loc_0000040C:
	s2 = 0x00000;
	if (a1 != t1)
		goto loc_0000037C;
	s0 = s2 + 1244;
	a0 = *(s32*)(s0 + 400);
	a1 = -263;
	v0 = sceKernelClearEventFlag(...);
	t3 = *(s32*)(s0 + 8);
	t2 = t3 & 0x8;
	a0 = *(s32*)(s0 + 400);
	if (t2 == 0)
		goto loc_00000458;
	a1 = 0x80000;
	*(s32*)(s0 + 364) = 0;
	*(s32*)(s0 + 368) = 0;

loc_00000440:
	v0 = sceKernelSetEventFlag(...);
	v0 = sub_00004164(...);
	t4 = s2 + 1244;
	goto loc_00000380;

loc_00000458:
	a1 = 16;
	goto loc_00000440;
}

{
	sp = sp - 32;
	v1 = 1;
	*(s32*)(sp + 16) = s4;
	s4 = a1;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s6;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	if (a0 == v1)
		goto loc_000004B8;

loc_00000490:
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

loc_000004B8:
	s6 = 0x00000;
	if (a1 == 0)
		goto loc_00000548;
	s0 = s6 + 944;
	a0 = *(s32*)(s0 + 276);
	a1 = -34;
	s3 = s0;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 276);
	a1 = 16;
	s2 = 0;
	v0 = sceKernelSetEventFlag(...);
	s5 = s0 + 140;
	s1 = 0;

loc_000004EC:
	a0 = *(s32*)(s0 + 260);
	a1 = 0;
	a2 = 256;
	v0 = memset(...);
	a0 = *(s32*)(s0 + 260);
	a1 = 256;
	s2 = s2 + 1;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s1 + s3;
	v1 = s1 + s5;
	a1 = (s32)s2 < (s32)4;
	*(s32*)(a0 + 128) = v1;
	s0 = s0 + 4;
	s1 = s1 + 40;
	if (a1 != 0)
		goto loc_000004EC;
	*(s32*)(s3 + 248) = 0;
	a0 = s3 + 100;
	v0 = sceUsbbdReqRecv(...);
	v0 = 1;
	*(s8*)(s3 + 4) = v0;

loc_0000053C:
	a2 = s6 + 944;
	*(s8*)(a2 + 3) = s4;
	goto loc_00000490;

loc_00000548:
	s1 = s6 + 944;
	a0 = *(s32*)(s1 + 276);
	a1 = -17;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s1 + 276);
	a1 = 32;
	v0 = sceKernelSetEventFlag(...);
	*(s8*)(s1 + 4) = 0;
	goto loc_0000053C;
}
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	a0 = s0 + 1244;
	*(s32*)(sp + 4) = ra;
	v1 = *(s8*)(a0 + 2);
	ra = *(s32*)(sp + 4);
	if (v1 == 0)
		goto loc_00000604;
	a2 = 2;
	a1 = 0x00000;
	*(s8*)(a0 + 4) = a2;
	v1 = a1 + 304;
	v0 = v1 + 8;
	*(s8*)(a0 + 1) = 0;
	v1 = 2;
	*(s8*)(a0 + 2) = 0;
	*(s8*)(a0 + 3) = 0;
	*(s32*)(a0 + 8) = 0;

loc_000005B4:
	v1 = v1 - 1;
	*(s32*)(v0 + 0) = 0;
	v0 = v0 + 12;
	if ((s32)v1 >= 0)
		goto loc_000005B4;
	s0 = s0 + 1244;
	a0 = *(s32*)(s0 + 400);
	a1 = 0;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 1024;
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 404);
	a1 = 1;
	a2 = 0;
	v0 = sceKernelCancelSema(...);
	a0 = *(s32*)(s0 + 408);
	a1 = 0;
	a2 = 0;
	v0 = sceKernelCancelMutex(...);
	ra = *(s32*)(sp + 4);

loc_00000604:
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	a0 = s0 + 944;
	*(s32*)(sp + 4) = ra;
	v1 = *(s8*)(a0 + 2);
	ra = *(s32*)(sp + 4);
	if (v1 == 0)
		goto loc_00000688;
	a2 = 5;
	a1 = 0x00000;
	*(s8*)(a0 + 4) = a2;
	v1 = a1 + 824;
	v0 = v1 + 8;
	*(s8*)(a0 + 2) = 0;
	v1 = 1;
	*(s8*)(a0 + 3) = 0;

loc_00000650:
	v1 = v1 - 1;
	*(s32*)(v0 + 0) = 0;
	v0 = v0 + 12;
	if ((s32)v1 >= 0)
		goto loc_00000650;
	s0 = s0 + 944;
	a0 = *(s32*)(s0 + 276);
	a1 = 0;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 276);
	a1 = 256;
	v0 = sceKernelSetEventFlag(...);
	v0 = 0x00000;
	*(s32*)(v0 + 1240) = 0;
	ra = *(s32*)(sp + 4);

loc_00000688:
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_694()
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	v1 = 0x00000;
	a3 = a2;
	*(s32*)(sp + 4) = ra;
	s0 = v1 + 1364;
	asm("lwl        $v0, 3($a3)");
	asm("lwr        $v0, 0($a3)");
	asm("lwl        $v1, 7($a3)");
	asm("lwr        $v1, 4($a3)");
	asm("swl        $v0, -5($s0)");
	asm("swr        $v0, -8($s0)");
	asm("swl        $v1, -1($s0)");
	asm("swr        $v1, -4($s0)");
	v0 = -1;
	if ((s32)a1 < 0)
		goto loc_00000748;
	t0 = *(u8*)(a3 + 0);
	v1 = 0x10000;
	a0 = v1 - 28964;
	a1 = 0;
	a2 = t0 & 0xFF;

loc_000006E8:
	t1 = *(u8*)(a0 + 0);
	if (a2 == t1)
	{
		t2 = *(u8*)(a0 + 1);
		goto loc_00000858;
	}
	a1 = a1 + 1;

loc_000006F8:
	t4 = (u32)a1 < (u32)6;
	a0 = a0 + 8;
	if (t4 != 0)
		goto loc_000006E8;
	a0 = 6;

loc_00000708:
	v0 = -1;
	if (a1 == a0)
		goto loc_00000748;
	a1 = (s8)t0;
	if ((s32)a1 < 0)
	{
		a2 = *(u8*)(a3 + 1);
		goto loc_0000079C;
	}
	a0 = *(u8*)(a3 + 1);
	v0 = a0 ^ 0x7;
	t4 = a0 ^ 0x9;
	t2 = (u32)v0 < (u32)1;
	t3 = (u32)t4 < (u32)1;
	t1 = t2 | t3;
	a1 = 10;
	if (t1 != 0)
		goto loc_00000768;
	cond = (a0 == a1);
	a0 = 0x00000;
	if (cond)
		goto loc_00000758;
	v0 = 0;

loc_00000748:
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00000758:
	t0 = *(u16*)(a0 + 1358);
	a2 = 16;
	if (t0 != a2)
	{
		v0 = 0;
		goto loc_00000748;
	}

loc_00000768:
	t7 = 0x00000;
	t5 = *(s32*)(t7 + 1404);
	t6 = *(u16*)(a3 + 6);
	*(s32*)(s0 + 24) = 0;
	a0 = t5;
	a1 = 128;
	*(s32*)(s0 + 8) = t6;
	*(s32*)(s0 + 4) = t5;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s0;
	v0 = sceUsbbdReqRecv(...);
	v0 = 0;
	goto loc_00000748;

loc_0000079C:
	a3 = 3;
	t5 = 0x00000;
	if (a2 == a3)
		goto loc_0000082C;
	a0 = 8;
	v0 = 0;
	if (a2 != a0)
		goto loc_00000748;
	t8 = 0x00000;
	t6 = *(s32*)(t8 + 1404);
	t7 = 1;
	*(s32*)(s0 + 4) = t6;
	*(s8*)(t6 + 0) = t7;
	*(s8*)(t6 + 1) = 0;
	*(s8*)(t6 + 2) = 0;
	*(s8*)(t6 + 3) = 0;
	*(s8*)(t6 + 4) = 0;
	*(s8*)(t6 + 5) = 0;
	*(s8*)(t6 + 6) = 0;
	*(s8*)(t6 + 7) = 0;
	*(s32*)(s0 + 8) = a2;

loc_000007E8:
	a0 = *(s32*)(s0 + 4);
	a1 = *(s32*)(s0 + 8);
	v0 = sceKernelDcacheWritebackRange(...);
	a0 = s0;
	v0 = sceUsbbdReqSend(...);
	if ((s32)v0 >= 0)
	{
		v0 = 0;
		goto loc_00000748;
	}
	v1 = 0x10000;
	t9 = 0x10000;
	s0 = 0x10000;
	a0 = v1 - 29648;
	a1 = t9 - 29600;
	a2 = s0 - 29596;
	a3 = v0;
	v0 = Kprintf(...);
	v0 = 0;
	goto loc_00000748;

loc_0000082C:
	a2 = *(s32*)(t5 + 1404);
	t0 = 2;
	*(s32*)(s0 + 4) = a2;
	*(s8*)(a2 + 4) = t0;
	*(s8*)(a2 + 5) = 0;
	*(s8*)(a2 + 0) = 0;
	*(s8*)(a2 + 1) = 0;
	*(s8*)(a2 + 2) = 0;
	*(s8*)(a2 + 3) = 0;
	*(s32*)(s0 + 8) = a0;
	goto loc_000007E8;

loc_00000858:
	t3 = *(u8*)(a3 + 1);
	if (t3 != t2)
	{
		a1 = a1 + 1;
		goto loc_000006F8;
	}
	a0 = 6;
	goto loc_00000708;
}

sub_86C()
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = 0x10000;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	s2 = 0x00000;
	*(s32*)(sp + 16) = s0;
	v0 = sceKernelGetSystemTimeLow(...);
	v0 = sceKernelCreateFpl("SceUsbCam", 1, 256, 5696, 1, 0);
	s0 = s2 + 1244;
	*(s32*)(s0 + 396) = v0;
	if ((s32)v0 < 0)
		goto loc_00000C6C;
	a0 = v0;
	a1 = sp;
	v0 = sceKernelTryAllocateFpl(...);
	cond = ((s32)v0 < 0);
	v0 = *(s32*)(sp + 0);
	if (cond)
		goto loc_00000B8C;
	a1 = s0 + 244;
	t3 = 1;
	a3 = v0 + 128;
	*(s32*)(s0 + 160) = v0;
	v1 = a3;
	*(s32*)(sp + 0) = a3;

loc_000008E0:
	t3 = t3 - 1;
	*(s32*)(a1 + 0) = v1;
	v1 = v1 + 1792;
	a1 = a1 + 4;
	if ((s32)t3 >= 0)
		goto loc_000008E0;
	t2 = 0x00000;
	t0 = t2 + 1244;
	a3 = v1 + 192;
	t1 = v1 + 128;
	*(s32*)(t0 + 108) = t1;
	a1 = t0;
	t3 = 0;
	*(s32*)(t0 + 292) = v1;
	a2 = t0 + 320;
	t2 = a3;
	*(s32*)(sp + 0) = a3;

loc_00000920:
	t7 = t3 << 4;
	t3 = t3 + 1;
	t5 = t7 + a1;
	t6 = t7 + a2;
	t4 = (s32)t3 < (s32)2;
	*(s32*)(t5 + 304) = t2;
	t2 = t2 + 896;
	*(s32*)(t5 + 316) = t6;
	*(s32*)(t5 + 308) = 0;
	if (t4 != 0)
		goto loc_00000920;
	s0 = a1;
	t3 = s0 + 304;
	*(s32*)(s0 + 332) = t3;
	t9 = 0x100000;
	v1 = 0x00000;
	s1 = s1 - 29584;
	t8 = a3 + 1792;
	a1 = v1 + 14004;
	a0 = s1;
	a2 = 17;
	a3 = 1024;
	t0 = t9 | 0x1;
	t1 = 0;
	*(s32*)(sp + 0) = t8;
	v0 = sceKernelCreateThread(...);
	*(s32*)(s0 + 412) = v0;
	if ((s32)v0 < 0)
		goto loc_00000B8C;
	v0 = sceKernelCreateThread("SceUsbCamCopyWorker", sub_3AA0, 0x11, 0x400, 0x100001);
	*(s32*)(s0 + 416) = v0;
	if ((s32)v0 < 0)
		goto loc_00000C60;
	a0 = s1;
	a1 = 513;
	a2 = 1024;
	a3 = 0;
	v0 = sceKernelCreateEventFlag(...);
	*(s32*)(s0 + 400) = v0;
	if ((s32)v0 < 0)
		goto loc_00000C54;
	s1 = 0x10000;
	a0 = s1 - 29552;
	a1 = 0;
	a2 = 1;
	a3 = 1;
	t0 = 0;
	v0 = sceKernelCreateSema(...);
	*(s32*)(s0 + 404) = v0;
	if ((s32)v0 < 0)
		goto loc_00000C48;
	a3 = 0x10000;
	a0 = a3 - 29532;
	a1 = 256;
	a2 = 0;
	a3 = 0;
	v0 = sceKernelCreateMutex(...);
	*(s32*)(s0 + 408) = v0;
	if ((s32)v0 < 0)
		goto loc_00000C3C;
	s1 = *(s32*)(s0 + 160);
	t8 = *(s32*)(s0 + 108);
	t0 = s0 + 120;
	a1 = s0 + 68;
	*(s32*)(t0 + 4) = s1;
	v0 = 0x00000;
	t9 = s0 + 252;
	*(s32*)(a1 + 4) = t8;
	a0 = v0 + 304;
	t1 = a0 + 12;
	t2 = *(s32*)(s0 + 292);
	t7 = 0x00000;
	v1 = 0x00000;
	*(s32*)(t9 + 4) = t2;
	t2 = 0x00000;
	a2 = 64;
	t6 = t7 + 16020;
	t3 = 1;
	t4 = v1 + 12452;
	*(s32*)(s0 + 252) = t1;
	t1 = t2 + 16364;
	t5 = 0x00000;
	*(s32*)(t0 + 12) = t3;
	t7 = t5 + 12496;
	t8 = a0 + 24;
	*(s32*)(t0 + 16) = t6;
	t5 = s0 + 244;
	t3 = 0;
	*(s32*)(t0 + 24) = 0;
	t6 = 896;
	s1 = 1;
	*(s32*)(a1 + 16) = t4;
	t4 = s0 + 164;
	*(s32*)(t9 + 8) = a2;
	*(s32*)(t0 + 28) = 0;
	*(s32*)(t0 + 32) = 0;
	*(s32*)(t0 + 20) = 0;
	*(s32*)(a1 + 24) = 0;
	*(s32*)(t0 + 8) = a2;
	*(s32*)(a1 + 12) = 0;
	*(s32*)(a1 + 28) = 0;
	*(s32*)(a1 + 32) = 0;
	*(s32*)(a1 + 20) = 0;
	*(s32*)(t9 + 16) = t1;
	*(s32*)(t9 + 24) = 0;
	*(s32*)(s0 + 120) = a0;
	*(s32*)(s0 + 68) = 0;
	*(s32*)(a1 + 8) = a2;
	*(s32*)(t9 + 12) = 0;
	*(s32*)(t9 + 28) = 0;
	*(s32*)(t9 + 32) = 0;
	*(s32*)(t9 + 20) = 0;

loc_00000AEC:
	a3 = *(s32*)(t5 + 0);
	t3 = t3 + 1;
	s0 = (s32)t3 < (s32)2;
	*(s32*)(t4 + 4) = a3;
	t5 = t5 + 4;
	*(s32*)(t4 + 0) = t8;
	*(s32*)(t4 + 8) = t6;
	*(s32*)(t4 + 12) = s1;
	*(s32*)(t4 + 16) = t7;
	*(s32*)(t4 + 28) = 0;
	*(s32*)(t4 + 32) = 0;
	*(s32*)(t4 + 20) = 0;
	*(s32*)(t4 + 24) = 0;
	t4 = t4 + 40;
	if (s0 != 0)
		goto loc_00000AEC;
	a0 = 2;
	v0 = sceUsbAccRegisterType(...);
	s0 = s2 + 1244;
	if ((s32)v0 < 0)
		goto loc_00000B8C;
	t9 = -1;
	a0 = *(s32*)(s0 + 412);
	*(s32*)(s0 + 420) = t9;
	a1 = 0;
	a2 = 0;
	v0 = sceKernelStartThread(...);
	a0 = *(s32*)(s0 + 416);
	a1 = 0;
	a2 = 0;
	v0 = sceKernelStartThread(...);
	*(s8*)(s2 + 1244) = s1;
	v0 = sceKernelDmaOpAlloc();
	v1 = 0;
	*(s32*)(s0 + 392) = v0;

loc_00000B70:
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00000B8C:
	s0 = s2 + 1244;
	a0 = *(s32*)(s0 + 408);
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 404);
		goto loc_00000BAC;
	}
	s2 = -1;
	v0 = sceKernelDeleteMutex(...);
	*(s32*)(s0 + 408) = s2;
	a0 = *(s32*)(s0 + 404);

loc_00000BAC:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 400);
		goto loc_00000BC8;
	}
	v0 = sceKernelDeleteSema(...);
	a1 = -1;
	*(s32*)(s0 + 404) = a1;
	a0 = *(s32*)(s0 + 400);

loc_00000BC8:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 416);
		goto loc_00000BE4;
	}
	v0 = sceKernelDeleteEventFlag(...);
	a2 = -1;
	*(s32*)(s0 + 400) = a2;
	a0 = *(s32*)(s0 + 416);

loc_00000BE4:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 412);
		goto loc_00000C00;
	}
	v0 = sceKernelDeleteThread(...);
	t0 = -1;
	*(s32*)(s0 + 416) = t0;
	a0 = *(s32*)(s0 + 412);

loc_00000C00:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 396);
		goto loc_00000C1C;
	}
	v0 = sceKernelDeleteThread(...);
	a0 = -1;
	*(s32*)(s0 + 412) = a0;
	a0 = *(s32*)(s0 + 396);

loc_00000C1C:
	if ((s32)a0 <= 0)
	{
		v1 = -1;
		goto loc_00000B70;
	}
	v0 = sceKernelDeleteFpl(...);
	t1 = -1;
	*(s32*)(s0 + 396) = t1;
	v1 = -1;
	goto loc_00000B70;

loc_00000C3C:
	a2 = -1;
	*(s32*)(s0 + 408) = a2;
	goto loc_00000B8C;

loc_00000C48:
	a1 = -1;
	*(s32*)(s0 + 404) = a1;
	goto loc_00000B8C;

loc_00000C54:
	a0 = -1;
	*(s32*)(s0 + 400) = a0;
	goto loc_00000B8C;

loc_00000C60:
	v1 = -1;
	*(s32*)(s0 + 416) = v1;
	goto loc_00000B8C;

loc_00000C6C:
	a0 = -1;
	v1 = -1;
	*(s32*)(s0 + 396) = a0;
	goto loc_00000B70;
}

sub_C7C()
{
	s0 = s2 + 944;
	*(s32*)(sp + 0) = 0;
	v0 = sceKernelCreateFpl("SceUsbMic", 1, 0x100, 1088, 1, 0);
	v1 = -1;
	*(s32*)(s0 + 280) = v0;
	if ((s32)v0 < 0)
		goto loc_00000EB0;
	a0 = v0;
	a1 = sp;
	v0 = sceKernelTryAllocateFpl(...);
	a1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00000EA0;
	s1 = s0;
	v1 = s0 + 260;
	a0 = a1 + 64;
	*(s32*)(s0 + 96) = a1;
	v0 = a0;
	a2 = 3;
	*(s32*)(sp + 0) = a0;

loc_00000CFC:
	a2 = a2 - 1;
	*(s32*)(v1 + 0) = v0;
	v0 = v0 + 256;
	v1 = v1 + 4;
	if ((s32)a2 >= 0)
		goto loc_00000CFC;

	*(s32*)(sp + 0) = a0 + 1024;
	v0 = sceKernelCreateThread("SceUsbMicCopyWorker", sub_3CD4, 16, 1024, 0x100001, 0);
	*(s32*)(s1 + 284) = v0;
	if ((s32)v0 < 0)
		goto loc_00000EA0;
	a0 = s3 - 29248;
	a1 = 513;
	a2 = 256;
	a3 = 0;
	v0 = sceKernelCreateEventFlag(...);
	*(s32*)(s1 + 276) = v0;
	if ((s32)v0 < 0)
		goto loc_00000E94;
	t0 = 0x00000;
	t3 = s1 + 56;
	t2 = *(s32*)(s1 + 96);
	a0 = t0 + 12488;
	*(s32*)(s1 + 56) = 0;
	t1 = 0x00000;
	a3 = 64;
	*(s32*)(t3 + 16) = a0;
	t4 = 0x00000;
	a2 = 0;
	*(s32*)(t3 + 12) = 0;
	t0 = 128;
	a1 = t3 + 44;
	*(s32*)(t3 + 28) = 0;
	*(s32*)(t3 + 32) = 0;
	*(s32*)(t3 + 20) = 0;
	*(s32*)(t3 + 24) = 0;
	*(s32*)(t3 + 4) = t2;
	t2 = t1 + 836;
	t1 = t4 + 31920;
	*(s32*)(t3 + 8) = a3;
	a3 = t3 + 204;

loc_00000DBC:
	t6 = *(s32*)(a3 + 0);
	a2 = a2 + 1;
	t5 = (s32)a2 < (s32)4;
	*(s32*)(a1 + 4) = t6;
	a3 = a3 + 4;
	*(s32*)(a1 + 0) = t2;
	*(s32*)(a1 + 8) = t0;
	*(s32*)(a1 + 12) = 0;
	*(s32*)(a1 + 16) = t1;
	*(s32*)(a1 + 28) = 0;
	*(s32*)(a1 + 32) = 0;
	*(s32*)(a1 + 20) = 0;
	*(s32*)(a1 + 24) = 0;
	a1 = a1 + 40;
	if (t5 != 0)
		goto loc_00000DBC;
	s0 = s2 + 944;
	t7 = s0 + 8;
	t8 = 5;
	*(s8*)(s0 + 4) = t8;
	s3 = 0x00000;
	s1 = s3 + 824;
	*(s32*)(s0 + 8) = 0;
	v0 = s1 + 8;
	a2 = 1;
	*(s16*)(t7 + 12) = 0;
	*(s8*)(s0 + 1) = 0;
	*(s8*)(s0 + 2) = 0;
	*(s8*)(s0 + 3) = 0;
	*(s8*)(s0 + 5) = 0;
	*(s32*)(t7 + 4) = 0;
	*(s32*)(t7 + 8) = 0;

loc_00000E38:
	a2 = a2 - 1;
	*(s32*)(v0 + 0) = 0;
	v0 = v0 + 12;
	if ((s32)a2 >= 0)
		goto loc_00000E38;
	s0 = s2 + 944;
	t9 = *(s32*)(s0 + 96);
	s1 = 1;
	a0 = 1;
	*(s16*)(t9 + 0) = s1;
	v0 = sceUsbAccRegisterType(...);
	v1 = 0x00000;
	if ((s32)v0 < 0)
		goto loc_00000E88;
	a0 = *(s32*)(s0 + 284);
	a1 = 0;
	a2 = 0;
	*(s32*)(v1 + 1240) = 0;
	*(s8*)(s2 + 944) = s1;
	v0 = sceKernelStartThread(...);
	v1 = 0;
	if (v0 == 0)
		goto loc_00000EB0;

loc_00000E88:
	a2 = s2 + 944;
	a0 = *(s32*)(a2 + 276);
	v0 = sceKernelDeleteEventFlag(...);

loc_00000E94:
	a1 = s2 + 944;
	a0 = *(s32*)(a1 + 284);
	v0 = sceKernelDeleteThread(...);

loc_00000EA0:
	t3 = s2 + 944;
	a0 = *(s32*)(t3 + 280);
	v0 = sceKernelDeleteFpl(...);
	v1 = -1;

loc_00000EB0:
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	a0 = 2;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = s1 + 1244;
	v0 = sceUsbAccUnregisterType(...);
	a1 = 16384;
	a0 = *(s32*)(s0 + 400);
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 416);
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 412);
		goto loc_00000F24;
	}
	a1 = 0;
	v0 = sceKernelWaitThreadEnd(...);
	a0 = *(s32*)(s0 + 416);
	v0 = sceKernelDeleteThread(...);
	v0 = -1;
	*(s32*)(s0 + 416) = v0;
	a0 = *(s32*)(s0 + 412);

loc_00000F24:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 400);
		goto loc_00000F48;
	}
	a1 = 0;
	v0 = sceKernelWaitThreadEnd(...);
	a0 = *(s32*)(s0 + 412);
	v0 = sceKernelDeleteThread(...);
	v0 = -1;
	*(s32*)(s0 + 412) = v0;
	a0 = *(s32*)(s0 + 400);

loc_00000F48:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 404);
		goto loc_00000F64;
	}
	v0 = sceKernelDeleteEventFlag(...);
	a0 = -1;
	*(s32*)(s0 + 400) = a0;
	a0 = *(s32*)(s0 + 404);

loc_00000F64:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 408);
		goto loc_00000F80;
	}
	v0 = sceKernelDeleteSema(...);
	a1 = -1;
	*(s32*)(s0 + 404) = a1;
	a0 = *(s32*)(s0 + 408);

loc_00000F80:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 396);
		goto loc_00000F9C;
	}
	v0 = sceKernelDeleteMutex(...);
	a2 = -1;
	*(s32*)(s0 + 408) = a2;
	a0 = *(s32*)(s0 + 396);

loc_00000F9C:
	if ((s32)a0 <= 0)
	{
		a0 = *(s32*)(s0 + 392);
		goto loc_00000FB8;
	}
	v0 = sceKernelDeleteFpl(...);
	a3 = -1;
	*(s32*)(s0 + 396) = a3;
	a0 = *(s32*)(s0 + 392);

loc_00000FB8:
	if (a0 != 0)
		goto loc_00000FDC;
	*(s8*)(s1 + 1244) = 0;

loc_00000FC4:
	v0 = 0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00000FDC:
	v0 = sceKernelDmaOpFree(...);
	*(s8*)(s1 + 1244) = 0;
	goto loc_00000FC4;
}
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = 0x00000;
	a0 = 1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	s0 = s1 + 944;
	v0 = sceUsbAccUnregisterType(...);
	a1 = 512;
	a0 = *(s32*)(s0 + 276);
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s0 + 284);
	a1 = 0;
	v0 = sceKernelWaitThreadEnd(...);
	a0 = *(s32*)(s0 + 284);
	v0 = sceKernelDeleteThread(...);
	a0 = *(s32*)(s0 + 276);
	v0 = sceKernelDeleteEventFlag(...);
	a0 = *(s32*)(s0 + 280);
	v0 = sceKernelDeleteFpl(...);
	*(s8*)(s1 + 944) = 0;
	v0 = 0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sub_00001058(...) // at 0x00001058 
{
	v0 = a0 + 128;
	a0 = v0 & 0xFF;
	a1 = (s8)a0;
	v1 = ~(0 | a0);
	if ((s32)a1 < 0)
		goto loc_00001074;

loc_0000106C:		
	v0 = a0;
	return (v0);

loc_00001074:		
	a0 = -128;
	a1 = v1 | a0;
	a0 = a1 & 0xFF;
	goto loc_0000106C;
}

sub_00001084(...) // at 0x00001084 
{
	a1 = (s32)a0 < (s32)256;
	v1 = 42;
	v0 = 0;
	if ((s32)a0 < 0)
		goto loc_000010B0;
	v0 = 5;
	if (a1 == 0)
		goto loc_000010B0;
	asm("div        $a0, $v1");
	if (v1 == 0)
	{
		asm("break      0x7");
		goto loc_000010A8;
	}

loc_000010A8:		
	asm("mflo       $a0");
	v0 = a0 & 0xFF;

loc_000010B0:		
	return (v0);
}

sub_000010B8(...) // at 0x000010B8 
{
	v1 = 0x10000;
	t1 = v1 - 29512;
	sp = sp - 16;
	asm("lwl        $v1, 3($t1)");
	asm("lwr        $v1, 0($t1)");
	asm("swl        $v1, 3($sp)");
	asm("swr        $v1, 0($sp)");
	a1 = (s32)a0 < (s32)256;
	v0 = 0;
	v1 = 64;
	if ((s32)a0 < 0)
		goto loc_00001100;
	v0 = 2;
	if (a1 == 0)
		goto loc_00001100;
	asm("div        $a0, $v1");
	if (v1 == 0)
	{
		asm("break      0x7");
		goto loc_000010F8;
	}

loc_000010F8:		
	asm("mflo       $a0");
	v0 = a0 & 0xFF;

loc_00001100:		
	a1 = sp + v0;
	v0 = *(u8*)(a1 + 0);
	sp = sp + 16;
	return (v0);
}

sub_00001110(...) // at 0x00001110 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29216;
	a0 = 0;
	v1 = a0 + a2;

loc_00001124:		
	a3 = *(u8*)(v1 + 0);
	if (a1 == a3)
	{
		a1 = (s32)a0 < (s32)10;
		goto loc_0000114C;
	}
	a0 = a0 + 1;
	t0 = (s32)a0 < (s32)10;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00001124;
	a0 = 0;

loc_00001144:		
	v0 = a0;
	return (v0);

loc_0000114C:		
	if (a1 != 0)
		goto loc_00001144;
	a0 = 0;
	goto loc_00001144;
}

sub_0000115C(...) // at 0x0000115C 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29204;
	a0 = 0;
	v1 = a0 + a2;

loc_00001170:		
	a3 = *(u8*)(v1 + 0);
	if (a1 == a3)
	{
		a1 = (s32)a0 < (s32)10;
		goto loc_00001198;
	}
	a0 = a0 + 1;
	t0 = (s32)a0 < (s32)10;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00001170;
	a0 = 0;

loc_00001190:		
	v0 = a0;
	return (v0);

loc_00001198:		
	if (a1 != 0)
		goto loc_00001190;
	a0 = 0;
	goto loc_00001190;
}

sub_000011A8(...) // at 0x000011A8 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29144;
	a0 = 0;
	v1 = a0 + a2;

loc_000011BC:		
	a3 = *(u8*)(v1 + 0);
	if (a1 == a3)
	{
		a1 = (s32)a0 < (s32)17;
		goto loc_000011E4;
	}
	a0 = a0 + 1;
	t0 = (s32)a0 < (s32)17;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_000011BC;
	a0 = 0;

loc_000011DC:		
	v0 = a0;
	return (v0);

loc_000011E4:		
	if (a1 != 0)
		goto loc_000011DC;
	a0 = 0;
	goto loc_000011DC;
}

sub_000011F4(...) // at 0x000011F4 
{
	a3 = (s32)a0 < (s32)10;
	v1 = (s32)a1 < (s32)10;
	t0 = 0;
	if (a3 == 0)
		goto loc_00001250;
	if (v1 == 0)
		goto loc_00001250;
	v1 = a2 - 10;
	a3 = (u32)v1 < (u32)71;
	if (a2 == 0)
		goto loc_0000124C;
	t5 = a0 << 2;
	t4 = t5 + a0;
	t3 = 0x10000;
	t1 = t4 << 1;
	t2 = t3 - 29064;
	a0 = t1 + t2;
	v0 = a0 + a1;
	if (a3 == 0)
		goto loc_00001250;
	a1 = *(s8*)(v0 + 0);
	a2 = (s32)a1 < (s32)a2;
	if ((s32)a1 < 0)
		goto loc_00001250;
	if (a2 != 0)
		goto loc_00001250;

loc_0000124C:		
	t0 = 1;

loc_00001250:		
	v0 = t0;
	return (v0);
}

sceUsbCamSetupVideo(PspUsbCamSetupVideoParam *param, void *workarea, int wasize) // at 0x00001258 
{
	s4 = 0x00000;
	a3 = 0x80243908;
	s2 = k1;
	k1 = k1 << 11;

	if (*(s8*)(0x00000 + 1244))
	{
		v0 = sceUsbAccGetAuthStat(...);
		v1 = 0x80240000;
		a3 = 0x80243902;
		if ((s32)v0 < 0)
			goto loc_0000129C;
		a0 = 0x80240000;
		a3 = 0x80243907;
		if (param == 0)
			goto loc_0000129C;
		t0 = param + 52;
		a3 = t0 | param;
		a1 = a3 & k1;
		a2 = 0x80240000;
		a3 = 0x80243904;
		if ((s32)a1 < 0)
			goto loc_0000129C;
		t5 = workarea + wasize;
		t4 = t5 | workarea;
		t3 = t4 | wasize;
		t2 = 0x80240000;
		t1 = k1 & t3;
		a3 = 0x80243904;
		if ((s32)t1 < 0)
			goto loc_0000129C;
		t7 = 0x80240000;
		t6 = wasize & 0x3F;
		a3 = 0x80243903;
		if (t6 != 0)
			goto loc_0000129C;
		t2 = param.framerate
		t8 = (s32)t2 < (s32)5;
		v0 = 6;
		if (t8)
		{
			v0 = 9;
		}
		*(s32*)(sp + 36) = v0;

		t6 = 0x10000 - 29124;
		t8 = param.resolusion;
		t5 = t8 << 1;
		t3 = t5 + t6;
		a1 = *(s8*)(t3 + 1);
		t3 = 0x10000 - 29172;
		*(s32*)(sp + 40) = a1;
		*(s32*)(sp + 48) = 2;
		*(s32*)(sp + 52) = 3;
		*(s32*)(sp + 56) = param.wb;
		*(s32*)(sp + 60) = param.saturation;
		*(s32*)(sp + 64) = param.brightness;
		*(s32*)(sp + 68) = param.contrast;
		*(s32*)(sp + 72) = param.sharpness;
		a0 = *(u8*)(0x00000 + 1266);
		*(s32*)(sp + 44) = t2;

		t2 = 0;
		t4 = t2 + t3;
		do
		{
			if (a0 == *(u8*)(t4 + 0))
			{
				t3 = param.effectmode;
				break;
			}
			t2++;
			t4 = t2 + t3;
		} while (t2 < 3);

		a2 = param.size;

		t5 = t2 ^ 0x3;
		if (t5 == 0)
			t2 = 2;
		*(s32*)(sp + 76) = t2;

		*(s32*)(sp + 80) = 1;
		*(s32*)(sp + 96) = param.effectmode;
		*(s32*)(sp + 108) = 2;
		*(s32*)(sp + 112) = 1000;
		*(s32*)(sp + 116) = 500;
		*(s32*)(sp + 120) = param.framesize;
		*(s32*)(sp + 84) = 0;
		*(s32*)(sp + 88) = 0;
		*(s32*)(sp + 92) = 0;
		*(s32*)(sp + 100) = 0;
		if (a2 == 40)
		{
			a2 = 8;
			s0 = 10;
			*(s32*)(sp + 128) = 8;
			*(s32*)(sp + 104) = 10;
			*(s32*)(sp + 124) = 0;
			goto loc_00001454;
		}
		t6 = 48;
		v0 = 0x80240000;
		if (a2 == t6)
		{
			t9 = param.unk;
			t8 = param.evlevel;
			t7 = 10;
			*(s32*)(sp + 124) = param.unk;
			*(s32*)(sp + 128) = param.evlevel;
			*(s32*)(sp + 104) = 10;
			goto loc_00001454;
		}
		t4 = 52;
		a3 = 0x80243907;
		if (a2 != t4)
			goto loc_0000129C;
		t0 = (&param + 1).size;//*(s32*)(s0 + 48);
		t2 = param.evlevel;
		t1 = param.unk;
		*(s32*)(sp + 104) = t0;
		*(s32*)(sp + 128) = t2;
		*(s32*)(sp + 124) = t1;

	loc_00001454:
		a1 = sp + 32;
		a0 = sp;
		v0 = sub_00004298(...);
		a3 = v0;
		if (v0 >= 0)
		{
			a0 = 0x00000;
			t3 = a0 + 1256;
			asm("lwl        $a0, 3($sp)");
			asm("lwr        $a0, 0($sp)");
			asm("lwl        $a1, 7($sp)");
			asm("lwr        $a1, 4($sp)");
			asm("lwl        $a2, 11($sp)");
			asm("lwr        $a2, 8($sp)");
			asm("lwl        $a3, 15($sp)");
			asm("lwr        $a3, 12($sp)");
			asm("swl        $a0, 3($t3)");
			asm("swr        $a0, 0($t3)");
			asm("swl        $a1, 7($t3)");
			asm("swr        $a1, 4($t3)");
			asm("swl        $a2, 11($t3)");
			asm("swr        $a2, 8($t3)");
			asm("swl        $a3, 15($t3)");
			asm("swr        $a3, 12($t3)");
			asm("lwl        $a0, 19($sp)");
			asm("lwr        $a0, 16($sp)");
			asm("lwl        $a1, 23($sp)");
			asm("lwr        $a1, 20($sp)");
			asm("lwl        $a2, 27($sp)");
			asm("lwr        $a2, 24($sp)");
			asm("lwl        $a3, 31($sp)");
			asm("lwr        $a3, 28($sp)");
			asm("swl        $a0, 19($t3)");
			asm("swr        $a0, 16($t3)");
			asm("swl        $a1, 23($t3)");
			asm("swr        $a1, 20($t3)");
			asm("swl        $a2, 27($t3)");
			asm("swr        $a2, 24($t3)");
			asm("swl        $a3, 31($t3)");
			asm("swr        $a3, 28($t3)");
			a3 = t3 - 12;
			a0 = t3 + 38;
			a1 = *(s32*)(a3 + 8);
			s0 = t3;
			NONE;
			*(s32*)(a3 + 8) = a1;
			v0 = sub_00001110(...);
			v1 = (s32)v0 < (s32)7;
			a3 = 0;
			if (v1)
			{
				a0 = *(u8*)(s0 + 2);
				t5 = 0x10000;
				a2 = t5 - 29192;

				a1 = 0;
				t6 = a1 + a2;
				do
				{
					s0 = *(u8*)(t6 + 0);
					if (a0 == s0)
					{
						a0 = a1 ^ 0x8;
						break;
					}
					a1 = a1 + 1;
					t6 = a1 + a2;
				} while (a1 < 8);
				a0 = a1 ^ 0x8;

				t3 = 7;
				if (a0 == 0)
					a1 = t3;
				t0 = (s32)a1 < (s32)5;
				t4 = 6;
				v0 = 9;
				t2 = 0x10000;
				if (t0 != 0)
					t4 = v0;
				t1 = t2 - 29216;
				t9 = t4 + t1;
				t8 = *(u8*)(t9 + 0);
				a2 = s4 + 1244;
				*(s8*)(a2 + 50) = t8;
			}
			t5 = s4 + 1244;
			s0 = *(u8*)(t5 + 1);
			s4 = (u32)wasize >> 1;
			s1 = workarea + s4;
			a1 = s0 | 0x1;
			*(s8*)(t5 + 1) = a1;
			*(s32*)(t5 + 352) = s1;
			*(s32*)(t5 + 336) = workarea;
			*(s32*)(t5 + 340) = s4;
			*(s32*)(t5 + 344) = workarea;
			*(s32*)(t5 + 348) = 0;
			*(s32*)(t5 + 356) = 0;
		}
	}

loc_0000129C:		
	k1 = s2;
	return (a3);
}

sceUsbCamSetupVideoEx(PspUsbCamSetupVideoExParam *param, void *workarea, int wasize) // at 0x000015E4 
{
	a3 = 0x00000;
	t0 = *(s8*)(a3 + 1244);
	sp = sp - 64;
	v1 = 0x80240000;
	*(s32*)(sp + 48) = s4;
	s4 = a3 + 1244;
	a3 = v1 | 0x3908;
	*(s32*)(sp + 44) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 40) = s2;
	s2 = a1;
	*(s32*)(sp + 36) = s1;
	s1 = a2;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 52) = ra;
	if (t0 != 0)
	{
	loc_00001654:
		v0 = sceUsbAccGetAuthStat(...);
		a0 = 0x80240000;
		a3 = a0 | 0x3902;
		if ((s32)v0 < 0)
			goto loc_0000162C;
		a2 = s0 + 100;
		v0 = 0x80240000;
		a1 = a2 | s0;
		a3 = v0 | 0x3907;
		v1 = a1 & k1;
		if (s0 == 0)
			goto loc_0000162C;
		t2 = s2 + s1;
		t1 = t2 | s2;
		t3 = 0x80240000;
		t0 = t1 | s1;
		a3 = t3 | 0x3904;
		v0 = k1 & t0;
		if ((s32)v1 < 0)
			goto loc_0000162C;
		t4 = 0x80240000;
		v1 = s1 & 0x3F;
		a3 = t4 | 0x3904;
		if ((s32)v0 < 0)
			goto loc_0000162C;
		t5 = 0x80240000;
		a1 = s0;
		a0 = sp;
		a3 = t5 | 0x3903;
		if (v1 != 0)
			goto loc_0000162C;
		v0 = sub_00004298(...);
		a3 = v0;
		if (v0 >= 0)
		{
			asm("lwl        $v0, 3($sp)");
			asm("lwr        $v0, 0($sp)");
			asm("lwl        $v1, 7($sp)");
			asm("lwr        $v1, 4($sp)");
			asm("lwl        $a0, 11($sp)");
			asm("lwr        $a0, 8($sp)");
			asm("lwl        $a1, 15($sp)");
			asm("lwr        $a1, 12($sp)");
			asm("swl        $v0, 15($s4)");
			asm("swr        $v0, 12($s4)");
			asm("swl        $v1, 19($s4)");
			asm("swr        $v1, 16($s4)");
			asm("swl        $a0, 23($s4)");
			asm("swr        $a0, 20($s4)");
			asm("swl        $a1, 27($s4)");
			asm("swr        $a1, 24($s4)");
			asm("lwl        $v0, 19($sp)");
			asm("lwr        $v0, 16($sp)");
			asm("lwl        $v1, 23($sp)");
			asm("lwr        $v1, 20($sp)");
			asm("lwl        $a0, 27($sp)");
			asm("lwr        $a0, 24($sp)");
			asm("lwl        $a1, 31($sp)");
			asm("lwr        $a1, 28($sp)");
			asm("swl        $v0, 31($s4)");
			asm("swr        $v0, 28($s4)");
			asm("swl        $v1, 35($s4)");
			asm("swr        $v1, 32($s4)");
			asm("swl        $a0, 39($s4)");
			asm("swr        $a0, 36($s4)");
			asm("swl        $a1, 43($s4)");
			asm("swr        $a1, 40($s4)");
			t6 = (u32)s1 >> 1;
			t8 = s2 + t6;
			t7 = *(s32*)(s4 + 8);
			s1 = *(u8*)(s4 + 1);
			*(s32*)(s4 + 352) = t8;
			NONE;
			s0 = s1 | 0x1;
			*(s8*)(s4 + 1) = s0;
			a3 = 0;
			*(s32*)(s4 + 8) = t7;
			*(s32*)(s4 + 336) = s2;
			*(s32*)(s4 + 340) = t6;
			*(s32*)(s4 + 344) = s2;
			*(s32*)(s4 + 348) = 0;
			*(s32*)(s4 + 356) = 0;
		}
	}

loc_0000162C:		
	k1 = s3;
	return (a3);
}

sceUsbCamReadVideoFrame(u8 *buf, SceSize size) // at 0x00001790 
{
	s1 = k1;
	k1 = k1 << 11;
	s0 = 0x00000 + 1244;
	a2 = 0x80243908;
	if (*(s8*)(0x00000 + 1244))
	{
		a0 = *(s8*)(s0 + 2);
		a2 = 0x80243902;
		if (a0 != 0)
		{
			v0 = sceUsbAccGetAuthStat();
			a2 = 0x80243902;
			if (v0 >= 0)
			{
				t0 = *(u8*)(s0 + 1);
				a3 = t0 & 0x1;
				a2 = 0x80243901;
				if (a3)
				{
					t2 = ((buf + size) | buf) | size;
					a2 = 0x80243907;
					v0 = k1 & t2;
					if (buf)
					{
						a2 = 0x80243904;
						if (v0 >= 0)
						{
							t7 = *(s8*)(s0 + 4);
							a2 = 0x8024390C;
							if (t7)
							{
								a2 = *(s32*)(s0 + 8);
								t9 = a2 & 0x4;
								v1 = a2 | 0x4;
								a2 = 0x80243909;
								if (!t9)
								{
									*(s32*)(s0 + 8) = v1;
									v0 = sceKernelClearEventFlag(*(s32*)(s0 + 400), -129);
									*(s32*)(s0 + 428) = size;
									*(s32*)(s0 + 432) = buf;
									a2 = sceKernelSetEventFlag(*(s32*)(s0 + 400), 64);
								}
							}
						}
					}
				}
			}
		}
	}
loc_000017E0:		
	k1 = s1;
	return (a2);
}

sceUsbCamWaitReadVideoFrameEnd(...) // at 0x000018A8 
{
	s2 = k1;
	k1 = k1 << 11;
	s1 = 0x00000 + 1244;
	s0 = 0x80243908;
	if (*(s8*)(0x00000 + 1244))
	{
		s0 = 0x80243902;
		if (*(s8*)(s1 + 2))
		{
			s0 = 0x80243902;
			if (sceUsbAccGetAuthStat() >= 0)
			{
				s0 = 0x80243901;
				if (*(u8*)(s1 + 1) & 0x01)
				{
					s0 = 0x8024390C;
					if (*(s32*)(s1 + 8) & 0x4)
					{
						*(s32*)(sp + 4) = 0x2DC6C0;
						v0 = sceKernelWaitEventFlag(*(s32*)(s1 + 400), 1152, 1, sp, sp + 4);
						s0 = v0;
						if ((s32)v0 < 0)
						{
							t7 = 0x800201A8;
							if (v0 == t7)
							{
								s0 = 0x80243902;
								v0 = sceUsbRestart(0xF4240);
							}
						}
						else
						{
							a0 = *(s32*)(s1 + 8);
							v1 = *(s32*)(sp + 0);
							a1 = 0x80240000;
							NONE;
							t9 = v1 & 0x400;
							*(s32*)(s1 + 8) = a0;
							s0 = 0x80243902;
							if (!t9)
							{
								s0 = *(s32*)(s1 + 384);
							}
						}
					}
				}
			}
		}
	}
	k1 = s2;
	return (s0);
}

sceUsbCamPollReadVideoFrameEnd(...) // at 0x000019C8 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 1244);
	sp = sp - 32;
	v1 = 0x80240000;
	*(s32*)(sp + 20) = s1;
	s1 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 16) = s0;
	s0 = a0 + 1244;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 24) = ra;
	if (a1 == 0)
		goto loc_00001A08;
	a1 = *(s8*)(s0 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 != 0)
		goto loc_00001A24;

loc_00001A08:		
	k1 = s1;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 32;
	return (v0);

loc_00001A24:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00001A08;
	t0 = *(u8*)(s0 + 1);
	t1 = 0x80240000;
	a3 = t0 & 0x1;
	a0 = t1 | 0x3901;
	if (a3 == 0)
		goto loc_00001A08;
	t3 = *(s32*)(s0 + 8);
	t4 = 0x80240000;
	t2 = t3 & 0x4;
	a0 = t4 | 0x390C;
	if (t2 == 0)
		goto loc_00001A08;
	a0 = *(s32*)(s0 + 400);
	a1 = 1152;
	a2 = 1;
	a3 = sp;
	v0 = sceKernelPollEventFlag(...);
	t6 = 0x80020000;
	t5 = t6 | 0x1AF;
	a0 = v0;
	if (v0 == t5)
		goto loc_00001AB0;
	v1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00001A08;
	a0 = *(s32*)(s0 + 8);
	t9 = 0x80240000;
	NONE;
	t8 = v1 & 0x400;
	*(s32*)(s0 + 8) = a0;
	a0 = t9 | 0x3902;
	if (t8 != 0)
		goto loc_00001A08;
	a0 = *(s32*)(s0 + 384);
	goto loc_00001A08;

loc_00001AB0:		
	t7 = 0x80240000;
	a0 = t7 | 0x390E;
	goto loc_00001A08;
}

sceUsbCamReadVideoFrameBlocking(u8 *buf, SceSize size) // at 0x00001ABC 
{
	a3 = *(s8*)(0x00000 + 1244);

	s3 = k1;
	k1 = k1 << 11;
	s2 = 0x00000 + 1244;
	a2 = 0x80243908;
	s1 = a1;
	s0 = a0;
	if (a3)
	{
		a0 = *(s8*)(s2 + 2);
		a2 = 0x80243902;
		if (a0 != 0)
			goto loc_00001B30;
	}
loc_00001B0C:		
	k1 = s3;
	return (a2);

loc_00001B30:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80243902;
	if ((s32)v0 < 0)
		goto loc_00001B0C;
	t0 = *(u8*)(s2 + 1);
	a3 = t0 & 0x1;
	a2 = 0x80243901;
	if (a3 == 0)
		goto loc_00001B0C;
	a2 = 0x80243907;
	if (s0 == 0)
		goto loc_00001B0C;
	t7 = s0 + s1;
	t6 = t7 | s0;
	t5 = t6 | s1;
	t3 = k1 & t5;
	a2 = 0x80243904;
	if ((s32)t3 < 0)
		goto loc_00001B0C;
	v1 = *(s32*)(s2 + 8);
	t9 = 0x80240000;
	t8 = v1 & 0x4;
	a2 = t9 | 0x3909;
	if (t8 != 0)
		goto loc_00001B0C;
	a0 = *(s32*)(s2 + 400);
	a2 = v1 | 0x4;
	a1 = -129;
	*(s32*)(s2 + 8) = a2;
	v0 = sceKernelClearEventFlag(...);
	a1 = 64;
	a0 = *(s32*)(s2 + 400);
	*(s32*)(s2 + 432) = s0;
	*(s32*)(s2 + 428) = s1;
	v0 = sceKernelSetEventFlag(...);
	a2 = 1;
	a0 = *(s32*)(s2 + 400);
	a1 = 1152;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	a2 = v0;
	if ((s32)v0 < 0)
		goto loc_00001B0C;
	a0 = *(s32*)(s2 + 8);
	v1 = *(s32*)(sp + 0);
	s1 = 0x80240000;
	NONE;
	s0 = v1 & 0x400;
	*(s32*)(s2 + 8) = a0;
	a2 = s1 | 0x3902;
	if (s0 != 0)
		goto loc_00001B0C;
	a2 = *(s32*)(s2 + 384);
	goto loc_00001B0C;
}

sceUsbCamGetReadVideoFrameSize(...) // at 0x00001C04 
{
	s2 = 0x00000 + 1244;
	s1 = k1;
	k1 = k1 << 11;
	s0 = 0x80243908;
	if (*(s8*)(0x00000 + 1244))
	{
		s0 = 0x80243902;
		if (*(s8*)(s2 + 2))
		{
			s0 = 0x80243902;
			if (sceUsbAccGetAuthStat() >= 0)
			{
				s0 = 0x80243901;
				if (*(u8*)(s2 + 1) & 0x1)
				{
					v0 = sceKernelCpuSuspendIntr();
					s0 = *(s32*)(s2 + 388);
					v0 = sceKernelCpuResumeIntr(v0);
				}
			}
		}
	}

	k1 = s1;
	return (s0);
}

sceUsbCamSetupStill(...) // at 0x00001CAC 
{
	a1 = 0x00000;
	a2 = *(s8*)(a1 + 1244);
	sp = sp - 112;
	v1 = 0x80240000;
	*(s32*)(sp + 104) = s2;
	s2 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 100) = s1;
	s1 = a1 + 1244;
	a1 = v1 | 0x3908;
	*(s32*)(sp + 96) = s0;
	s0 = a0;
	*(s32*)(sp + 108) = ra;
	if (a2 == 0)
		goto loc_00001CF4;
	a0 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	a1 = v0 | 0x3902;
	if (a0 != 0)
		goto loc_00001D14;

loc_00001CF4:		
	k1 = s2;
	ra = *(s32*)(sp + 108);
	s2 = *(s32*)(sp + 104);
	s1 = *(s32*)(sp + 100);
	s0 = *(s32*)(sp + 96);
	v0 = a1;
	sp = sp + 112;
	return (v0);

loc_00001D14:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a1 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00001CF4;
	a3 = 0x80240000;
	a1 = a3 | 0x3907;
	if (s0 == 0)
		goto loc_00001CF4;
	t3 = s0 + 24;
	t2 = t3 | s0;
	t1 = 0x80240000;
	t0 = t2 & k1;
	a1 = t1 | 0x3904;
	if ((s32)t0 < 0)
		goto loc_00001CF4;
	t0 = *(s32*)(s0 + 0);
	t6 = 0x80240000;
	t5 = t0 - 20;
	t4 = (u32)t5 < (u32)5;
	a1 = t6 | 0x3907;
	if (t4 == 0)
		goto loc_00001CF4;
	a1 = *(u8*)(s1 + 14);
	t7 = 0x10000;
	a2 = t7 - 29192;
	a0 = 0;
	t8 = a0 + a2;

loc_00001D78:		
	s1 = *(u8*)(t8 + 0);
	if (a1 == s1)
	{
		a2 = a0 ^ 0x8;
		goto loc_00001D98;
	}
	a0 = a0 + 1;
	t9 = (u32)a0 < (u32)8;
	t8 = a0 + a2;
	if (t9 != 0)
		goto loc_00001D78;
	a2 = a0 ^ 0x8;

loc_00001D98:		
	a1 = 7;
	if (a2 == 0)
		a0 = a1;
	v1 = (s32)a0 < (s32)5;
	v0 = 6;
	if (v1 == 0)
		goto loc_00001DB0;
	v0 = 9;

loc_00001DB0:		
	*(s32*)(sp + 4) = v0;
	a1 = 0x10000;
	t9 = a1 - 29124;
	a2 = *(s32*)(s0 + 4);
	v0 = *(s32*)(s0 + 12);
	t6 = *(s32*)(s0 + 8);
	t8 = a2 << 1;
	s1 = t8 + t9;
	t3 = *(s32*)(s0 + 16);
	t7 = *(s8*)(s1 + 1);
	NONE;
	t2 = 2;
	t5 = v0 & 0x1;
	a3 = 500;
	a0 = 250;
	t1 = (s32)t0 < (s32)24;
	*(s32*)(sp + 8) = t7;
	v0 = 10;
	*(s32*)(sp + 12) = t6;
	*(s32*)(sp + 28) = t5;
	*(s32*)(sp + 32) = t4;
	*(s32*)(sp + 36) = t3;
	*(s32*)(sp + 40) = t2;
	*(s32*)(sp + 44) = a3;
	*(s32*)(sp + 48) = a0;
	*(s32*)(sp + 24) = t2;
	*(s32*)(sp + 52) = 0;
	if (t1 != 0)
		goto loc_00001E24;
	v0 = *(s32*)(s0 + 20);

loc_00001E24:		
	a1 = sp;
	a0 = sp + 64;
	*(s32*)(sp + 16) = v0;
	*(s32*)(sp + 56) = 0;
	v0 = sub_00004680(...);
	a1 = v0;
	if ((s32)v0 < 0)
		goto loc_00001CF4;
	a0 = 0x00000;
	t3 = a0 + 1288;
	asm("lwl        $a0, 67($sp)");
	asm("lwr        $a0, 64($sp)");
	asm("lwl        $a1, 71($sp)");
	asm("lwr        $a1, 68($sp)");
	asm("lwl        $a2, 75($sp)");
	asm("lwr        $a2, 72($sp)");
	asm("lwl        $a3, 79($sp)");
	asm("lwr        $a3, 76($sp)");
	asm("swl        $a0, 3($t3)");
	asm("swr        $a0, 0($t3)");
	asm("swl        $a1, 7($t3)");
	asm("swr        $a1, 4($t3)");
	asm("swl        $a2, 11($t3)");
	asm("swr        $a2, 8($t3)");
	asm("swl        $a3, 15($t3)");
	asm("swr        $a3, 12($t3)");
	asm("lwl        $a0, 83($sp)");
	asm("lwr        $a0, 80($sp)");
	asm("swl        $a0, 19($t3)");
	asm("swr        $a0, 16($t3)");
	s0 = t3 - 44;
	a1 = 0;
	v1 = *(u8*)(s0 + 1);
	t1 = *(s32*)(s0 + 8);
	t0 = v1 | 0x2;
	NONE;
	*(s32*)(s0 + 8) = t1;
	*(s8*)(s0 + 1) = t0;
	goto loc_00001CF4;
}

sceUsbCamSetupStillEx(...) // at 0x00001EBC 
{
	a2 = 0x00000;
	a1 = *(s8*)(a2 + 1244);
	sp = sp - 48;
	v1 = 0x80240000;
	*(s32*)(sp + 40) = s2;
	s2 = a2 + 1244;
	a2 = v1 | 0x3908;
	*(s32*)(sp + 36) = s1;
	s1 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 32) = s0;
	s0 = a0;
	*(s32*)(sp + 44) = ra;
	if (a1 == 0)
		goto loc_00001F04;
	a0 = *(s8*)(s2 + 2);
	v0 = 0x80240000;
	a2 = v0 | 0x3902;
	if (a0 != 0)
		goto loc_00001F24;

loc_00001F04:		
	k1 = s1;
	ra = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = a2;
	sp = sp + 48;
	return (v0);

loc_00001F24:		
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x80240000;
	a2 = a1 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00001F04;
	t0 = s0 + 60;
	t1 = 0x80240000;
	a3 = t0 | s0;
	a2 = t1 | 0x3907;
	v0 = a3 & k1;
	if (s0 == 0)
		goto loc_00001F04;
	t2 = 0x80240000;
	a1 = s0;
	a0 = sp;
	a2 = t2 | 0x3904;
	if ((s32)v0 < 0)
		goto loc_00001F04;
	v0 = sub_00004680(...);
	a2 = v0;
	if ((s32)v0 < 0)
		goto loc_00001F04;
	asm("lwl        $v0, 3($sp)");
	asm("lwr        $v0, 0($sp)");
	asm("lwl        $v1, 7($sp)");
	asm("lwr        $v1, 4($sp)");
	asm("lwl        $a0, 11($sp)");
	asm("lwr        $a0, 8($sp)");
	asm("lwl        $a1, 15($sp)");
	asm("lwr        $a1, 12($sp)");
	asm("swl        $v0, 47($s2)");
	asm("swr        $v0, 44($s2)");
	asm("swl        $v1, 51($s2)");
	asm("swr        $v1, 48($s2)");
	asm("swl        $a0, 55($s2)");
	asm("swr        $a0, 52($s2)");
	asm("swl        $a1, 59($s2)");
	asm("swr        $a1, 56($s2)");
	asm("lwl        $v0, 19($sp)");
	asm("lwr        $v0, 16($sp)");
	asm("swl        $v0, 63($s2)");
	asm("swr        $v0, 60($s2)");
	a2 = 0;
	t5 = *(u8*)(s2 + 1);
	t4 = *(s32*)(s2 + 8);
	t3 = t5 | 0x2;
	NONE;
	*(s32*)(s2 + 8) = t4;
	*(s8*)(s2 + 1) = t3;
	goto loc_00001F04;
}

sceUsbCamStillInput(...) // at 0x00001FE4 
{
	a2 = 0x00000;
	a3 = *(s8*)(a2 + 1244);
	sp = sp - 32;
	v1 = 0x80240000;
	*(s32*)(sp + 16) = s4;
	s4 = a2 + 1244;
	a2 = v1 | 0x3908;
	*(s32*)(sp + 12) = s3;
	s3 = a0;
	*(s32*)(sp + 8) = s2;
	s2 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 20) = ra;
	*(s32*)(sp + 0) = s0;
	if (a3 == 0)
		goto loc_00002038;
	a0 = *(s8*)(s4 + 2);
	v0 = 0x80240000;
	a2 = v0 | 0x3902;
	if (a0 != 0)
		goto loc_00002060;

loc_00002038:		
	k1 = s2;
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 32;
	return (v0);

loc_00002060:		
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x80240000;
	a2 = a1 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00002038;
	t0 = 0x80240000;
	a3 = (u32)s1 < (u32)64;
	v1 = s3 + s1;
	a2 = t0 | 0x3903;
	if (a3 != 0)
		goto loc_00002038;
	t3 = v1 | s3;
	t2 = t3 | s1;
	t4 = 0x80240000;
	t1 = k1 & t2;
	a2 = t4 | 0x3904;
	if ((s32)t1 < 0)
		goto loc_00002038;
	t6 = *(u8*)(s4 + 1);
	t7 = 0x80240000;
	a0 = s4 + 51;
	t5 = t6 & 0x2;
	a2 = t7 | 0x3901;
	if (t5 == 0)
		goto loc_00002038;
	v0 = sub_0000115C(...);
	a0 = s4 + 50;
	s0 = v0;
	v0 = sub_00001110(...);
	t8 = (s32)v0 < (s32)s0;
	s0 = 0x80240000;
	a1 = -12289;
	a2 = s0 | 0x3905;
	if (t8 != 0)
		goto loc_00002038;
	a0 = *(s32*)(s4 + 400);
	v0 = sceKernelClearEventFlag(...);
	a0 = s3;
	a1 = s1;
	v0 = sub_000035F4(...);
	a2 = v0;
	goto loc_00002038;
}

sceUsbCamStillPollInputEnd(...) // at 0x000020FC 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = k1 << 11;
	v0 = sub_00004858(...);
	a0 = 1;
	if ((s32)v0 < 0)
		goto loc_00002124;
	v0 = sub_000048DC(...);

loc_00002124:		
	k1 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sceUsbCamStillWaitInputEnd(...) // at 0x00002138 
{
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = k1 << 11;
	v0 = sub_00004858(...);
	a0 = 0;
	if ((s32)v0 < 0)
		goto loc_00002160;
	v0 = sub_000048DC(...);

loc_00002160:		
	k1 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
}

sceUsbCamStillInputBlocking(...) // at 0x00002174 
{
	a2 = 0x00000;
	a3 = *(s8*)(a2 + 1244);
	sp = sp - 32;
	v1 = 0x80240000;
	*(s32*)(sp + 12) = s3;
	s3 = a2 + 1244;
	a2 = v1 | 0x3908;
	*(s32*)(sp + 8) = s2;
	s2 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	s0 = a1;
	*(s32*)(sp + 16) = ra;
	if (a3 == 0)
		goto loc_000021C4;
	a0 = *(s8*)(s3 + 2);
	v0 = 0x80240000;
	a2 = v0 | 0x3902;
	if (a0 != 0)
		goto loc_000021E8;

loc_000021C4:		
	k1 = s2;
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 32;
	return (v0);

loc_000021E8:		
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x80240000;
	a2 = a1 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_000021C4;
	t0 = 0x80240000;
	a3 = (u32)s0 < (u32)64;
	v1 = s1 + s0;
	a2 = t0 | 0x3903;
	if (a3 != 0)
		goto loc_000021C4;
	t3 = v1 | s1;
	t2 = t3 | s0;
	t4 = 0x80240000;
	t1 = k1 & t2;
	a2 = t4 | 0x3904;
	if ((s32)t1 < 0)
		goto loc_000021C4;
	t7 = *(u8*)(s3 + 1);
	t6 = 0x80240000;
	a1 = -12289;
	t5 = t7 & 0x2;
	a2 = t6 | 0x3901;
	if (t5 == 0)
		goto loc_000021C4;
	a0 = *(s32*)(s3 + 400);
	v0 = sceKernelClearEventFlag(...);
	a0 = s1;
	a1 = s0;
	v0 = sub_000035F4(...);
	a2 = v0;
	a0 = 0;
	if ((s32)v0 < 0)
		goto loc_000021C4;
	v0 = sub_000048DC(...);
	a2 = v0;
	goto loc_000021C4;
}

sceUsbCamStillGetInputLength(...) // at 0x00002270 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 1244);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 4) = s1;
	s1 = a0 + 1244;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 0) = s0;
	s0 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 8) = ra;
	if (a1 == 0)
		goto loc_000022B0;
	a1 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 != 0)
		goto loc_000022CC;

loc_000022B0:		
	k1 = s0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);

loc_000022CC:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_000022B0;
	t0 = *(u8*)(s1 + 1);
	t1 = 0x80240000;
	a3 = t0 & 0x2;
	a0 = t1 | 0x3901;
	if (a3 == 0)
		goto loc_000022B0;
	t4 = *(s32*)(s1 + 372);
	t2 = *(s32*)(s1 + 368);
	a0 = t4;
	t3 = (u32)t4 < (u32)t2;
	if (t3 == 0)
		a0 = t2;
	goto loc_000022B0;
}

sceUsbCamStillCancelInput(...) // at 0x0000230C 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 16) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v0 = sub_00004858(...);
	s2 = v0;
	if ((s32)v0 < 0)
		goto loc_00002390;
	v0 = sceKernelCpuSuspendIntr(...);
	v1 = 0x00000;
	s1 = v1 + 1244;
	a0 = *(s32*)(s1 + 400);
	a1 = 8192;
	s0 = v0;
	*(s32*)(s1 + 372) = 0;
	*(s32*)(s1 + 376) = 0;
	*(s32*)(s1 + 380) = 0;
	v0 = sceKernelSetEventFlag(...);
	a1 = *(s32*)(s1 + 436);
	v1 = (u32)a1 < (u32)1280;
	a0 = s0;
	if (v1 != 0)
		goto loc_00002380;
	a3 = *(s32*)(s1 + 8);
	a2 = a3 | 0x10;
	*(s32*)(s1 + 8) = a2;

loc_00002380:		
	t0 = *(s32*)(s1 + 8);
	NONE;
	*(s32*)(s1 + 8) = t0;
	v0 = sceKernelCpuResumeIntr(...);

loc_00002390:		
	v0 = s2;
	k1 = s3;
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);
}

sceUsbCamGetSaturation(...) // at 0x000023B4 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x3;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002404;
	k1 = s0;

loc_000023F4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002404:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_000023F4;
}

sceUsbCamGetBrightness(...) // at 0x00002414 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x1;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002464;
	k1 = s0;

loc_00002454:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002464:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_00002454;
}

sceUsbCamGetContrast(...) // at 0x00002474 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x2;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_000024C4;
	k1 = s0;

loc_000024B4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000024C4:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_000024B4;
}

sceUsbCamGetSharpness(...) // at 0x000024D4 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x4;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002524;
	k1 = s0;

loc_00002514:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002524:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_00002514;
}

sceUsbCamGetZoom(...) // at 0x00002534 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x5;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002584;
	k1 = s0;

loc_00002574:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002584:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_00002574;
}

sceUsbCamGetAntiFlicker(...) // at 0x00002594 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x10;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_000025E4;
	k1 = s0;

loc_000025D4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000025E4:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_000025D4;
}

sceUsbCamGetEvLevel(...) // at 0x000025F4 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x14;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002644;
	k1 = s0;

loc_00002634:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002644:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_00002634;
}

sceUsbCamGetReverseMode(...) // at 0x00002654 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x6;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_000026A4;
	k1 = s0;

loc_00002694:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000026A4:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_00002694;
}

sceUsbCamGetImageEffectMode(...) // at 0x000026B4 
{
	a2 = a0 + 4;
	v1 = k1 << 11;
	a1 = a0;
	a0 = a2 | a0;
	sp = sp - 16;
	v0 = 0x80000000;
	a2 = a0 & v1;
	a3 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	a0 = v0 | 0x7;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = v1;
	v0 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00002704;
	k1 = s0;

loc_000026F4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002704:		
	v0 = sub_000055AC(...);
	k1 = s0;
	goto loc_000026F4;
}

sceUsbCam_00631D06(...) // at 0x00002714 - Aliases: sceUsbCam_driver_00631D06
{
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 1680);
	v1 = 0x80240000;
	a1 = a0 - 1;
	v0 = (u32)a1 < (u32)1279;
	a1 = v1 | 0x3902;
	if (a0 == 0)
		goto loc_00002744;
	v1 = (u32)a0 < (u32)1280;
	a1 = 1;
	if (v0 != 0)
		goto loc_00002744;
	a1 = 2;
	if (v1 != 0)
		a1 = 0;

loc_00002744:		
	v0 = a1;
	return (v0);
}

sceUsbCamGetLensDirection(...) // at 0x0000274C 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	a1 = 1024;
	s1 = k1;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	v1 = s0 + 1244;
	*(s32*)(sp + 24) = ra;
	k1 = k1 << 11;
	a2 = 1;
	a0 = *(s32*)(v1 + 400);
	a3 = sp;
	s0 = s0 + 1244;
	v0 = sceKernelPollEventFlag(...);
	v1 = v0;
	a0 = 0x80020000;
	v0 = a0 | 0x1AF;
	if ((s32)v1 < 0)
		goto loc_000027E0;
	a2 = *(s32*)(sp + 0);
	a1 = 0x80240000;
	a0 = a2 & 0x400;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_000027C4;
	t1 = *(s32*)(s0 + 8);

loc_000027AC:		
	t0 = t1 ^ 0x400;
	a3 = t1 & 0x2000;
	NONE;
	if (a3 != 0)
		goto loc_000027C4;
	v0 = 0x80240000;
	v1 = v0 | 0x3901;

loc_000027C4:		
	k1 = s1;

loc_000027C8:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_000027E0:		
	k1 = s1;
	if (v1 != v0)
		goto loc_000027C8;
	t1 = *(s32*)(s0 + 8);
	goto loc_000027AC;
}

sceUsbCamRegisterLensRotationCallback(...) // at 0x000027F0 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = 0;
	v0 = sceKernelGetThreadmanIdType();
	a0 = 8;
	cond = (v0 == a0);
	v0 = 0x80240000;
	if (cond)
		goto loc_00002848;
	s0 = v0 | 0x3905;
	v0 = s0;

loc_0000282C:		
	k1 = s1;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002848:		
	v0 = sceKernelCpuSuspendIntr(...);
	v1 = 0x00000;
	a1 = v1 + 1244;
	a2 = *(s32*)(a1 + 420);
	a0 = v0;
	if ((s32)a2 <= 0)
		goto loc_00002884;
	t0 = 0x80240000;
	a3 = -1;
	s0 = t0 | 0x3910;
	*(s32*)(a1 + 420) = a3;

loc_00002874:		
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	goto loc_0000282C;

loc_00002884:		
	*(s32*)(a1 + 420) = s2;
	goto loc_00002874;
}

module_start() // at 0x0000288C 
{
	v0 = sub_00007C54(0, 0);

	a0 = 0x00000 + 368;
	v0 = sceUsbbdRegister(...);
	v1 = 0x00000 + 1244;
	a0 = -1;
	a2 = 1;
	if (v0 >= 0)
	{
		*(s8*)(0x00000 + 1244) = 0;
		*(s32*)(v1 + 416) = a0;
		*(s32*)(v1 + 436) = 0;
		*(s32*)(v1 + 396) = a0;
		*(s32*)(v1 + 400) = a0;
		*(s32*)(v1 + 404) = a0;
		*(s32*)(v1 + 412) = a0;
		a2 = 0;
	}
	return (a2);
}

module_stop(...) // at 0x000028F0 
{
	v0 = 0x00000;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = v0 + 368;
	v0 = sceUsbbdUnregister(...);
	a0 = 0;
	a1 = 0;
	v1 = 1;
	if ((s32)v0 < 0)
		goto loc_00002920;
	v0 = sub_00007C8C(...);
	v1 = 0;

loc_00002920:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_00002930(...) // at 0x00002930 
{
	v1 = 0x10000;
	a1 = v1 - 29168;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_00002944(...) // at 0x00002944 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29168;
	a0 = 0;
	v1 = a0 + a2;

loc_00002958:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x7;
	if (a1 == a3)
		goto loc_00002978;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)7;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00002958;
	v0 = a0 ^ 0x7;

loc_00002978:		
	a1 = 6;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_00002988(...) // at 0x00002988 
{
	v1 = 0x10000;
	a1 = v1 - 29192;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_0000299C(...) // at 0x0000299C 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29192;
	a0 = 0;
	v1 = a0 + a2;

loc_000029B0:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x8;
	if (a1 == a3)
		goto loc_000029D0;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)8;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_000029B0;
	v0 = a0 ^ 0x8;

loc_000029D0:		
	a1 = 7;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_000029E0(...) // at 0x000029E0 
{
	v1 = 0x10000;
	a1 = v1 - 29184;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_000029F4(...) // at 0x000029F4 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29184;
	a0 = 0;
	v1 = a0 + a2;

loc_00002A08:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x4;
	if (a1 == a3)
		goto loc_00002A28;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)4;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00002A08;
	v0 = a0 ^ 0x4;

loc_00002A28:		
	a1 = 3;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_00002A38(...) // at 0x00002A38 
{
	v1 = 0x10000;
	a1 = v1 - 29180;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_00002A4C(...) // at 0x00002A4C 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29180;
	a0 = 0;
	v1 = a0 + a2;

loc_00002A60:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x4;
	if (a1 == a3)
		goto loc_00002A80;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)4;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00002A60;
	v0 = a0 ^ 0x4;

loc_00002A80:		
	a1 = 3;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_00002A90(...) // at 0x00002A90 
{
	v1 = 0x10000;
	a1 = v1 - 29172;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_00002AA4(...) // at 0x00002AA4 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29172;
	a0 = 0;
	v1 = a0 + a2;

loc_00002AB8:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x3;
	if (a1 == a3)
		goto loc_00002AD8;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)3;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00002AB8;
	v0 = a0 ^ 0x3;

loc_00002AD8:		
	a1 = 2;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_00002AE8(...) // at 0x00002AE8 
{
	v1 = 0x10000;
	a1 = v1 - 29176;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sub_00002AFC(...) // at 0x00002AFC 
{
	v1 = 0x10000;
	a1 = *(u8*)(a0 + 0);
	a2 = v1 - 29176;
	a0 = 0;
	v1 = a0 + a2;

loc_00002B10:		
	a3 = *(u8*)(v1 + 0);
	v0 = a0 ^ 0x3;
	if (a1 == a3)
		goto loc_00002B30;
	a0 = a0 + 1;
	t0 = (u32)a0 < (u32)3;
	v1 = a0 + a2;
	if (t0 != 0)
		goto loc_00002B10;
	v0 = a0 ^ 0x3;

loc_00002B30:		
	a1 = 2;
	if (v0 == 0)
		a0 = a1;
	v0 = a0;
	return (v0);
}

sub_00002B40(...) // at 0x00002B40 
{
	v1 = 0x10000;
	a3 = a0 << 1;
	t1 = v1 - 29124;
	v1 = a3 + t1;
	t0 = 0x80240000;
	a3 = (u32)a0 < (u32)9;
	v0 = t0 | 0x3905;
	if (a3 == 0)
		goto loc_00002B74;
	a0 = *(u8*)(v1 + 1);
	t2 = 9;
	*(s8*)(a1 + 0) = t2;
	v0 = 0;
	*(s8*)(a2 + 0) = a0;

loc_00002B74:		
	return (v0);
}

sub_00002B7C(...) // at 0x00002B7C 
{
	t0 = 0x10000;
	t5 = t0 - 29104;
	t4 = a0 << 2;
	t6 = a1 << 2;
	t3 = t4 + t5;
	t9 = t6 + t5;
	t8 = *(s32*)(t3 + 0);
	t7 = *(s32*)(t9 + 0);
	sp = sp - 32;
	*(s32*)(sp + 16) = t8;
	t1 = 0x10000;
	t2 = 0x10000;
	*(s32*)(sp + 0) = t7;
	v1 = t1 - 29216;
	t6 = t2 - 29204;
	t1 = a0 + v1;
	t2 = a1 + t6;
	a0 = *(u16*)(sp + 0);
	a1 = *(u16*)(sp + 16);
	t5 = *(u16*)(sp + 18);
	v0 = *(u16*)(sp + 2);
	t4 = a1 - a0;
	t3 = 0x80240000;
	t0 = t5 - v0;
	v1 = t0 | t4;
	t0 = t3 | 0x3905;
	if ((s32)v1 < 0)
		goto loc_00002BFC;
	a0 = *(u8*)(t1 + 0);
	a1 = *(u8*)(t2 + 0);
	t0 = 0;
	*(s8*)(a2 + 0) = a0;
	*(s8*)(a3 + 0) = a1;

loc_00002BFC:		
	v0 = t0;
	sp = sp + 32;
	return (v0);
}

sub_00002C08(...) // at 0x00002C08 
{
	v1 = 0x10000;
	a1 = v1 - 29144;
	v1 = a0 + a1;
	v0 = *(u8*)(v1 + 0);
	return (v0);
}

sceUsbCamStartVideo() // at 0x00002C1C 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000033E8();
	k1 = s0;
	return (v0);
}

int sceUsbCamStopVideo() // at 0x00002C48 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000034B8();
	k1 = s0;
	return (v0);
}

sceUsbCamSetSaturation(int sat) // at 0x00002C74 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(3, &sat);
	k1 = s0;
	return (v0);
}

sceUsbCamSetBrightness(int brightness) // at 0x00002CB0 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(1, &brightness);
	k1 = s0;
	return (v0);
}

sceUsbCamSetContrast(int contrast) // at 0x00002CEC 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(2, &contrast);
	k1 = s0;
	return (v0);
}

sceUsbCamSetSharpness(int sharpness) // at 0x00002D28 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(4, &sharpness);
	k1 = s0;
	return (v0);
}

sceUsbCamSetZoom(int zoom) // at 0x00002D64 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(5, &zoom);
	k1 = s0;
	return (v0);
}

sceUsbCamSetAntiFlicker(int antiFlicker) // at 0x00002DA0 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(16, &antiFlicker);
	k1 = s0;
	return (v0);
}

sceUsbCamSetReverseMode(int reverseMode) // at 0x00002DDC 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(6, &reverseMode);
	k1 = s0;
	return (v0);
}

sceUsbCamSetEvLevel(int evlevel) // at 0x00002E18 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(20, &evlevel);
	k1 = s0;
	return (v0);
}

sceUsbCamSetImageEffectMode(int effectmode) // at 0x00002E54 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(7, &effectmode);
	k1 = s0;
	return (v0);
}

sceUsbCamSetResolution(int resolution) // at 0x00002E90 
{
	s0 = k1;
	k1 = k1 << 11;
	v0 = sub_000055AC(9, &resolution);
	k1 = s0;
	return (v0);
}

sceUsbCamAutoImageReverseSW(...) // at 0x00002ECC 
{
	v1 = 0x00000;
	a1 = v1 + 1244;
	v1 = a1;
	if (a0 == 0)
	{
	loc_00002EF0:
		v1 = *(s32*)(a1 + 8);
		NONE;
		*(s32*)(a1 + 8) = v1;
		goto loc_00002EE8;
	}
	else
	{
		a1 = *(s32*)(a1 + 8);
		a0 = a1 | 0x1000;
		*(s32*)(v1 + 8) = a0;
	}
loc_00002EE8:		
	v0 = 0;
	return (v0);
}

sceUsbCamGetAutoImageReverseState(...) // at 0x00002F00 
{
	v0 = 0x00000;
	a0 = *(s32*)(v0 + 1252);
	NONE;
	return (v0);
}

sceUsbCamUnregisterLensRotationCallback(...) // at 0x00002F10 
{
	sp = sp - 16;
	*(s32*)(sp + 4) = s1;
	s1 = k1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = ra;
	k1 = k1 << 11;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = 0x00000;
	v1 = a0 + 1244;
	a1 = *(s32*)(v1 + 420);
	a0 = v0;
	v0 = 0x80240000;
	s0 = v0 | 0x390F;
	if ((s32)a1 < 0)
		goto loc_00002F54;
	a2 = -1;
	*(s32*)(v1 + 420) = a2;
	s0 = a1;

loc_00002F54:		
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	k1 = s1;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 16;
	v1 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v1 + 1244;
	v0 = *(s8*)(s0 + 2);
	*(s32*)(sp + 4) = ra;
	if (v0 == 0)
		goto loc_00002FA4;
	ra = *(s32*)(sp + 4);

loc_00002F98:		
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00002FA4:		
	a0 = 1;
	*(s8*)(s0 + 2) = a0;
	*(s8*)(s0 + 4) = 0;
	*(s32*)(s0 + 8) = 0;
	*(s32*)(s0 + 436) = 0;
	v0 = sub_00003324(...);
	a1 = 0;
	a0 = *(s32*)(s0 + 400);
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 768;
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 4);
	goto loc_00002F98;
	sp = sp - 32;
	v1 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = v1 + 944;
	a1 = 0;
	v0 = *(s8*)(s0 + 2);
	*(s32*)(sp + 20) = ra;
	if (v0 == 0)
		goto loc_0000300C;

loc_00002FFC:		
	ra = *(s32*)(sp + 20);

loc_00003000:		
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000300C:		
	a0 = *(s32*)(s0 + 276);
	a2 = 1;
	*(s8*)(s0 + 2) = a2;
	*(s8*)(s0 + 4) = 0;
	v0 = sceKernelClearEventFlag(...);
	a1 = 32;
	a0 = *(s32*)(s0 + 276);
	v0 = sceKernelSetEventFlag(...);
	a0 = sp;
	v0 = sceUsbAccGetInfo(...);
	a0 = 0x10000;
	a1 = a0 - 28652;
	a2 = 8;
	a0 = sp;
	if (v0 != 0)
		goto loc_00002FFC;
	v0 = memcmp(...);
	t0 = 0x10000;
	a3 = 0x10000;
	a1 = t0 - 29284;
	a0 = a3 - 29272;
	if (v0 != 0)
		goto loc_00002FFC;
	v0 = 1;
	t1 = 0x00000;
	*(s32*)(t1 + 1240) = v0;
	v0 = Kprintf(...);
	ra = *(s32*)(sp + 20);
	goto loc_00003000;
	return (v0);
	a1 = *(s32*)(a2 + 0);
	a2 = 0x00000;
	a3 = *(u8*)(a2 + 852);
	a2 = *(s32*)(a1 + 16);
	a0 = *(u8*)(a2 + 8);
	v1 = a0 + a3;
	*(s8*)(a2 + 8) = v1;
	return (v0);
	v1 = 0x00000;
	a0 = *(s32*)(v1 + 1648);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a1 = 1;
	v0 = sceKernelSignalSema(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 24) = s6;
	s6 = 0x00000;
	a1 = s6 + 1244;
	*(s32*)(sp + 16) = s4;
	s4 = a0;
	a0 = 2;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 32) = fp;
	*(s32*)(sp + 28) = s7;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v0 = *(s8*)(a1 + 4);
	cond = (v0 == a0);
	a0 = 0;
	if (cond)
		goto loc_000032E4;
	a0 = *(s32*)(s4 + 24);
	if ((s32)a0 < 0)
	{
		t1 = *(s8*)(a1 + 5);
		goto loc_000032C0;
	}
	s1 = *(s32*)(a1 + 296);
	a1 = 1;
	t2 = *(s32*)(s1 + 8);
	a0 = s1;
	if (t2 == a1)
		goto loc_00003174;
	s1 = *(s32*)(s1 + 12);
	t5 = s6 + 1244;
	if (a0 == s1)
		goto loc_00003168;
	v1 = a0;
	a0 = 1;
	t3 = *(s32*)(s1 + 8);

loc_00003150:		
	t5 = s6 + 1244;
	if (t3 != a0)
		goto loc_00003168;
	s1 = *(s32*)(s1 + 12);
	if (v1 != s1)
	{
		t3 = *(s32*)(s1 + 8);
		goto loc_00003150;
	}
	t5 = s6 + 1244;

loc_00003168:		
	t4 = *(s32*)(t5 + 296);
	ra = *(s32*)(sp + 36);
	if (t4 == s1)
		goto loc_0000324C;

loc_00003174:		
	t6 = *(s32*)(s4 + 20);
	s3 = *(s32*)(s4 + 4);
	s2 = t6;
	if (t6 == 0)
		goto loc_00003218;
	t7 = 0x00000;
	s7 = t7 + 1244;
	s5 = 896;
	fp = 1;
	t0 = *(s32*)(s1 + 4);

loc_00003198:		
	a3 = *(s32*)(s1 + 0);
	a1 = s3;
	v1 = s5 - t0;
	a2 = (u32)v1 < (u32)s2;
	s0 = v1;
	if (a2 == 0)
		s0 = s2;
	a2 = s0;
	a0 = a3 + t0;
	v0 = memcpy(...);
	t9 = *(s32*)(s1 + 4);
	s2 = s2 - s0;
	s3 = s3 + s0;
	t8 = t9 + s0;
	s0 = (u32)t8 < (u32)896;
	a1 = 4;
	*(s32*)(s1 + 4) = t8;
	if (s0 == 0)
		goto loc_00003294;

loc_000031DC:		
	if (s2 != 0)
	{
		t0 = *(s32*)(s1 + 4);
		goto loc_00003198;
	}
	a1 = *(s32*)(s4 + 20);

loc_000031E8:		
	if (a1 == 0)
	{
		*(s32*)(s1 + 8) = 0;
		goto loc_0000321C;
	}
	t2 = 0x24920000;
	v0 = (u32)a1 >> 7;
	fp = t2 | 0x4936;
	asm("multu      $v0, $fp");
	asm("mfhi       $s7");
	s5 = s7 << 3;
	s3 = s5 - s7;
	s2 = s3 << 7;
	cond = (a1 == s2);
	a1 = s6 + 1244;
	if (cond)
		goto loc_00003238;

loc_00003218:		
	*(s32*)(s1 + 8) = 0;

loc_0000321C:		
	t3 = s6 + 1244;
	a1 = 4;
	t4 = *(s32*)(s1 + 12);
	a0 = *(s32*)(t3 + 400);
	*(s32*)(t3 + 296) = t4;
	v0 = sceKernelSetEventFlag(...);
	a1 = s6 + 1244;

loc_00003238:		
	s6 = *(u8*)(a1 + 4);
	s1 = (u32)s6 < (u32)2;
	if (s1 != 0)
	{
		a0 = *(s32*)(s4 + 4);
		goto loc_00003278;
	}
	ra = *(s32*)(sp + 36);

loc_0000324C:		
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

loc_00003278:		
	a1 = 1792;
	v0 = sceKernelDcacheInvalidateRange(...);
	*(s32*)(s4 + 28) = 0;
	a0 = s4;
	v0 = sceUsbbdReqRecv(...);
	ra = *(s32*)(sp + 36);
	goto loc_0000324C;

loc_00003294:		
	*(s32*)(s1 + 8) = 0;
	t1 = *(s32*)(s1 + 12);
	a0 = *(s32*)(s7 + 400);
	*(s32*)(s7 + 296) = t1;
	v0 = sceKernelSetEventFlag(...);
	v1 = *(s32*)(s1 + 12);
	a0 = *(s32*)(v1 + 8);
	if (a0 != fp)
	{
		a1 = *(s32*)(s4 + 20);
		goto loc_000031E8;
	}
	s1 = v1;
	goto loc_000031DC;

loc_000032C0:		
	t0 = 1;
	if (t1 != t0)
	{
		ra = *(s32*)(sp + 36);
		goto loc_0000324C;
	}
	a0 = *(s32*)(a1 + 400);
	a1 = 0x8000;

loc_000032D4:		
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 36);
	goto loc_0000324C;

loc_000032E4:		
	v1 = a1 + 188;
	a2 = *(s32*)(v1 + 0);

loc_000032EC:		
	v1 = v1 + 40;
	if ((s32)a2 > 0)
		goto loc_00003310;
	a0 = a0 + 1;
	a3 = (s32)a0 < (s32)2;
	if (a3 != 0)
	{
		a2 = *(s32*)(v1 + 0);
		goto loc_000032EC;
	}
	a0 = *(s32*)(a1 + 400);

loc_00003308:		
	a1 = 2;
	goto loc_000032D4;

loc_00003310:		
	v1 = (s32)a0 < (s32)2;
	if (v1 != 0)
	{
		ra = *(s32*)(sp + 36);
		goto loc_0000324C;
	}
	a0 = *(s32*)(a1 + 400);
	goto loc_00003308;
}

sub_00003324(...) // at 0x00003324 
{
	t9 = 0x00000;
	a3 = t9 + 1256;
	v1 = 2;
	t8 = 7;
	t7 = 6;
	t6 = 125;
	t5 = -128;
	t4 = 64;
	t3 = 1;
	t2 = 10;
	t1 = -24;
	t0 = 3;
	a2 = -12;
	a0 = 1;
	a1 = -128;
	v0 = 0;
	*(s8*)(t9 + 1256) = v1;
	*(s8*)(a3 + 1) = t8;
	*(s8*)(a3 + 2) = t7;
	*(s8*)(a3 + 6) = t6;
	*(s8*)(a3 + 7) = t5;
	*(s8*)(a3 + 8) = t4;
	*(s8*)(a3 + 11) = t3;
	*(s8*)(a3 + 20) = t2;
	*(s8*)(a3 + 21) = v1;
	*(s8*)(a3 + 22) = t1;
	*(s8*)(a3 + 23) = t0;
	*(s8*)(a3 + 24) = a2;
	*(s8*)(a3 + 25) = a0;
	*(s8*)(a3 + 27) = a1;
	*(s8*)(a3 + 53) = 0;
	*(s8*)(a3 + 3) = v1;
	*(s8*)(a3 + 4) = 0;
	*(s8*)(a3 + 5) = 0;
	*(s8*)(a3 + 9) = 0;
	*(s8*)(a3 + 10) = 0;
	*(s8*)(a3 + 12) = 0;
	*(s8*)(a3 + 13) = 0;
	*(s8*)(a3 + 14) = 0;
	*(s8*)(a3 + 15) = 0;
	*(s8*)(a3 + 16) = 0;
	*(s8*)(a3 + 17) = 0;
	*(s8*)(a3 + 18) = 0;
	*(s8*)(a3 + 19) = 0;
	*(s8*)(a3 + 26) = 0;
	*(s8*)(a3 + 28) = 0;
	*(s8*)(a3 + 29) = 0;
	*(s8*)(a3 + 52) = 0;
	return (v0);
}

// from sceUsbCamStartVideo
sub_000033E8() // at 0x000033E8 
{
	s0 = 0;
	v0 = sceKernelCpuSuspendIntr();
	s2 = v0;
	s1 = 0x00000 + 1244;
	if (*(s8*)(v1 + 1244))
	{
		if (*(s8*)(s1 + 2))
		{
			v0 = sceUsbAccGetAuthStat(...);
			if ((s32)v0 < 0)
				goto loc_00003450;
			a2 = *(u8*)(s1 + 1) &0x1;
			if (a2 != 0)
			{
				t1 = *(s8*)(s1 + 4);
				if (t1 == 0)
				{
					v0 = sceKernelClearEventFlag(*(s32*)(s1 + 400). - 9);
					v0 = sceKernelSetEventFlag(*(s32*)(s1 + 400), 1);
					*(s8*)(s1 + 4) = 1;
					goto loc_00003420;
				}
				s0 = 0x80243909;
				goto loc_00003420;
			}
			s0 = 0x80243901;
			goto loc_00003420;
		}

	loc_00003450:
		s0 = 0x80243902;
	}
	else
	{
		s0 = 0x80243908;
	}
loc_00003420:
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	return (s0);
}

//from sceUsbCamStopVideo
sub_000034B8() // at 0x000034B8 
{
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	v0 = 0x80240000;
	*(s32*)(sp + 16) = s0;
	a0 = v0 | 0x3908;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	v1 = *(s8*)(s1 + 1244);
	s0 = s1 + 1244;
	if (v1 == 0)
		goto loc_00003538;
	v1 = *(s8*)(s0 + 2);
	a1 = 0x80240000;
	a0 = a1 | 0x3902;
	if (v1 == 0)
		goto loc_00003538;
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00003538;
	t0 = *(u8*)(s0 + 1);
	t1 = 0x80240000;
	a3 = t0 & 0x1;
	a0 = t1 | 0x3901;
	if (a3 == 0)
		goto loc_00003538;
	t5 = *(s8*)(s0 + 4);
	t6 = t5 ^ 0x2;
	t3 = (u32)t6 < (u32)1;
	t4 = (u32)t5 < (u32)1;
	t2 = t3 | t4;
	a0 = 0;
	if (t2 == 0)
	{
		v0 = sceKernelCpuSuspendIntr(...);
		t7 = *(s8*)(s0 + 4);
		a0 = 3;
		s2 = v0;
		a1 = 4;
		if (t7 == a0)
		{
			t8 = *(s32*)(s0 + 8);
			NONE;
			*(s32*)(s0 + 8) = t8;
		}
		else
		{
			t9 = *(s32*)(s0 + 8);
			v1 = 2;
			a0 = *(s32*)(s0 + 400);
			NONE;
			*(s8*)(s0 + 4) = v1;
			*(s32*)(s0 + 8) = t9;
			v0 = sceKernelSetEventFlag(...);
		}

		s0 = s1 + 1244;
		v0 = sceKernelCpuResumeIntr(s2);
		v0 = sceKernelWaitEventFlag(*(s32*)(s0 + 400), 1032, 1, sp, 0);
		v0 = sceKernelWaitEventFlag(*(s32*)(s0 + 400), 1152, 1, sp, 0);
		v0 = memset(*(s32*)(s0 + 336), 0, *(s32*)(s0 + 340) << 1);
		a0 = 0;
	}

loc_00003538:
	return (a0);
}

sub_000035F4(...) // at 0x000035F4 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 8) = s2;
	s2 = a0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 20) = ra;
	s0 = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	v1 = 0x00000;
	s1 = v1 + 1244;
	s4 = v0;
	v0 = *(s8*)(s1 + 4);
	cond = (v0 != 0);
	v0 = 0x80240000;
	if (cond)
		goto loc_00003648;
	a1 = *(s32*)(s1 + 8);
	a0 = a1 & 0x8;
	if (a0 == 0)
	{
		*(s32*)(s1 + 376) = s3;
		goto loc_00003678;
	}

loc_00003648:
	s0 = v0 | 0x3909;

loc_0000364C:
	a0 = s4;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00003678:
	*(s32*)(s1 + 380) = s2;
	*(s32*)(s1 + 372) = s3;
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 2048;
	if (v0 == 0)
		goto loc_00003698;
	t0 = 0x80240000;
	s0 = t0 | 0x3902;
	goto loc_0000364C;

loc_00003698:
	a3 = *(s32*)(s1 + 8);
	a0 = *(s32*)(s1 + 400);
	a2 = a3 | 0x8;
	*(s32*)(s1 + 8) = a2;
	v0 = sceKernelSetEventFlag(...);
	goto loc_0000364C;
	sp = sp - 80;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 56) = s2;
	*(s32*)(sp + 48) = s0;
	*(s32*)(sp + 60) = s3;
	s3 = 0x00000;
	*(s32*)(sp + 64) = s4;
	s4 = 2;
	*(s32*)(sp + 52) = s1;
	s1 = s3 + 1244;
	a0 = *(s32*)(s1 + 400);

loc_000036E0:
	a1 = 16896;
	a2 = 1;
	a3 = sp + 36;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	ra = *(s32*)(sp + 68);
	if ((s32)v0 < 0)
		goto loc_000038D8;
	a0 = *(s32*)(sp + 36);
	v1 = a0 & 0x4000;
	if (v1 != 0)
	{
		s4 = *(s32*)(sp + 64);
		goto loc_000038DC;
	}
	a0 = sp + 40;
	v0 = sub_00000170(...);
	if ((s32)v0 < 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}
	t0 = *(s32*)(s1 + 8);
	a2 = *(s32*)(s1 + 436);
	a3 = t0 | 0x2000;
	*(s32*)(s1 + 8) = a3;
	if (a2 != 0)
		goto loc_00003748;
	v0 = 0xC0000000;
	a0 = v0 | 0x3;
	a1 = s1 + 436;
	v0 = sub_000055AC(...);
	if ((s32)v0 < 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}

loc_00003748:
	a0 = *(s32*)(s1 + 400);
	a1 = 19457;
	a2 = 1;
	a3 = sp + 36;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000038D4;
	v1 = *(s32*)(sp + 36);
	t2 = v1 & 0x4000;
	t3 = v1 & 0x400;
	if (t2 != 0)
		goto loc_000038D4;
	if (t3 != 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}
	t4 = v1 & 0x800;
	a2 = v1 & 0x1;
	if (t4 == 0)
		goto loc_00003950;
	t5 = *(s8*)(s1 + 2);
	if (t5 == 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}
	v0 = sceUsbAccGetAuthStat(...);
	if (v0 != 0)
	{
		t2 = *(s32*)(s1 + 436);
		goto loc_00003808;
	}
	t7 = *(s32*)(s1 + 436);
	t6 = (u32)t7 < (u32)1280;
	s2 = s3 + 1244;
	if (t6 != 0)
		goto loc_000037DC;
	s2 = *(u8*)(s1 + 50);
	s0 = (u32)s2 < (u32)2;
	if (s0 != 0)
	{
		*(s8*)(s1 + 50) = s4;
		goto loc_000037C8;
	}

loc_000037C8:
	t9 = *(u8*)(s1 + 51);
	t8 = (u32)t9 < (u32)2;
	if (t8 != 0)
	{
		*(s8*)(s1 + 51) = s4;
		goto loc_000037D8;
	}

loc_000037D8:
	s2 = s3 + 1244;

loc_000037DC:
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	a2 = 0;
	v0 = sceKernelLockMutex(...);
	a0 = 3;
	if (v0 == 0)
		goto loc_0000392C;
	a1 = *(s32*)(s2 + 436);

loc_000037F8:
	a0 = (u32)a1 < (u32)1280;
	if (a0 != 0)
	{
		a0 = *(s32*)(s2 + 400);
		goto loc_0000391C;
	}
	t2 = *(s32*)(s1 + 436);

loc_00003808:
	s2 = s3 + 1244;
	t1 = 0x80000;
	a0 = *(s32*)(s2 + 400);
	t0 = (u32)t2 < (u32)1280;
	a3 = t1 | 0x410;
	a1 = 1040;
	if (t0 == 0)
		a1 = a3;
	a2 = 1;
	a3 = sp + 36;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_0000384C;
	t4 = *(s32*)(sp + 36);
	t3 = t4 & 0x400;
	if (t3 != 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}

loc_0000384C:
	t6 = *(s8*)(s2 + 4);
	t5 = 2;
	v1 = *(s32*)(sp + 36);
	if (t6 == t5)
		goto loc_00003908;
	a0 = 0x80000;
	t9 = a0 | 0x10;
	t8 = v1 & t9;
	a1 = v1 & 0x10;
	if (t8 == 0)
		goto loc_000038B4;
	a0 = *(s32*)(s2 + 8);
	s2 = a0 & 0x1000;
	if (s2 == 0)
		goto loc_000038B4;
	v1 = a0 & 0x400;
	v0 = 257;
	if (v1 != 0)
		goto loc_00003890;
	v0 = 256;

loc_00003890:
	a0 = sp + 32;
	*(s16*)(sp + 32) = v0;
	v0 = sub_000000F4(...);
	v0 = 0xFFFD0000;
	a0 = *(s32*)(s1 + 400);
	a1 = v0 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	v1 = *(s32*)(sp + 36);
	a1 = v1 & 0x10;

loc_000038B4:
	a0 = 0;
	if (a1 != 0)
		goto loc_000038F8;
	a3 = 0x80000;
	a2 = v1 & a3;
	if (a2 != 0)
	{
		a0 = 1;
		goto loc_000038F8;
	}

loc_000038CC:
	if ((s32)s0 >= 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_000036E0;
	}

loc_000038D4:
	ra = *(s32*)(sp + 68);

loc_000038D8:
	s4 = *(s32*)(sp + 64);

loc_000038DC:
	s3 = *(s32*)(sp + 60);
	s2 = *(s32*)(sp + 56);
	s1 = *(s32*)(sp + 52);
	s0 = *(s32*)(sp + 48);
	v0 = 0;
	sp = sp + 80;
	return (v0);

loc_000038F8:
	v0 = sub_00004F04(...);
	s0 = v0;
	goto loc_000038CC;

loc_00003908:
	t7 = *(s32*)(s2 + 8);
	NONE;
	v0 = sub_00004C00(...);
	goto loc_000038CC;

loc_0000391C:
	a1 = -2049;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s1 + 400);
	goto loc_000036E0;

loc_0000392C:
	a1 = 2;
	a2 = s2 + 44;
	a3 = 20;
	v0 = sub_00000000(...);
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	a1 = *(s32*)(s2 + 436);
	goto loc_000037F8;

loc_00003950:
	if (a2 == 0)
	{
		t2 = *(s32*)(s1 + 436);
		goto loc_00003808;
	}
	v0 = sceKernelCpuSuspendIntr(...);
	a3 = *(s8*)(s1 + 2);
	s2 = v0;
	if (a3 != 0)
		goto loc_00003988;
	s0 = -1;

loc_00003970:
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	if ((s32)s0 >= 0)
	{
		t2 = *(s32*)(s1 + 436);
		goto loc_00003808;
	}
	a0 = *(s32*)(s1 + 400);
	goto loc_000036E0;

loc_00003988:
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x10000;
	if (v0 != 0)
		goto loc_00003A88;
	t8 = *(s32*)(s1 + 16);
	t7 = *(s32*)(s1 + 20);
	t6 = *(s32*)(s1 + 24);
	*(s32*)(sp + 4) = t8;
	t5 = *(s32*)(s1 + 28);
	t4 = *(s32*)(s1 + 32);
	t3 = *(s32*)(s1 + 36);
	t2 = *(s32*)(s1 + 40);
	s0 = *(s32*)(s1 + 12);
	a0 = *(u8*)(sp + 6);
	*(s32*)(sp + 8) = t7;
	*(s32*)(sp + 12) = t6;
	*(s32*)(sp + 16) = t5;
	*(s32*)(sp + 20) = t4;
	*(s32*)(sp + 24) = t3;
	*(s32*)(sp + 28) = t2;
	*(s32*)(sp + 0) = s0;
	v0 = sub_00001084(...);
	a0 = *(u8*)(sp + 7);
	*(s8*)(sp + 6) = v0;
	v0 = sub_00001058(...);
	a0 = *(u8*)(sp + 9);
	*(s8*)(sp + 7) = v0;
	v0 = sub_000010B8(...);
	t1 = *(s32*)(s1 + 436);
	t0 = (u32)t1 < (u32)1280;
	*(s8*)(sp + 9) = v0;
	if (t0 != 0)
		goto loc_00003A28;
	v1 = *(u8*)(sp + 0);
	t9 = (u32)v1 < (u32)2;
	if (t9 != 0)
	{
		*(s8*)(sp + 0) = s4;
		goto loc_00003A18;
	}

loc_00003A18:
	a1 = *(u8*)(sp + 1);
	a0 = (u32)a1 < (u32)2;
	if (a0 != 0)
	{
		*(s8*)(sp + 1) = s4;
		goto loc_00003A28;
	}

loc_00003A28:
	a0 = s2;
	s2 = s3 + 1244;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	a2 = 0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	if (v0 == 0)
		goto loc_00003A5C;

loc_00003A4C:
	v0 = sceKernelCpuSuspendIntr(...);
	s2 = v0;
	goto loc_00003970;

loc_00003A5C:
	a0 = 1;
	a1 = 2;
	a2 = sp;
	a3 = 32;
	v0 = sub_00000000(...);
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	s0 = v0;
	v0 = sceKernelUnlockMutex(...);
	goto loc_00003A4C;

loc_00003A88:
	v0 = 0x10000;
	a0 = a2 - 29508;
	a1 = v0 - 29600;
	v0 = Kprintf(...);
	goto loc_00003970;
}

SceUsbCamCopyWorker()	// 3AA0
{
	sp = sp - 64;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 36) = s5;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 44) = s7;
	s7 = 0x00000;
	*(s32*)(sp + 40) = s6;
	s6 = s7 + 1244;

loc_00003AD0:
	a0 = *(s32*)(s6 + 400);

loc_00003AD4:
	a1 = 16448;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	a0 = *(s32*)(s6 + 400);
	s0 = v0;
	a1 = -65;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(sp + 0);
	if ((s32)s0 < 0)
		goto loc_00003B0C;
	v1 = a0 & 0x4000;
	if (v1 == 0)
		goto loc_00003B18;

loc_00003B0C:
	a0 = *(s32*)(s6 + 400);
	a1 = 128;
	v0 = sceKernelSetEventFlag(...);

loc_00003B18:
	if ((s32)s0 < 0)
	{
		*(s32*)(s6 + 384) = s0;
		goto loc_00003AD0;
	}
	a1 = *(s32*)(sp + 0);
	v1 = a1 & 0x4000;
	s1 = s7 + 1244;
	if (v1 != 0)
		goto loc_00003C9C;
	a2 = *(s8*)(s1 + 7);
	v1 = *(s8*)(s1 + 6);
	s5 = *(s32*)(s1 + 432);
	s4 = *(s32*)(s1 + 428);
	if (a2 == v1)
		goto loc_00003B58;
	t1 = v1 << 3;
	t0 = t1 + s1;
	a3 = *(s32*)(t0 + 348);
	if (a3 != 0)
	{
		s1 = *(s8*)(s6 + 6);
		goto loc_00003B90;
	}

loc_00003B58:
	a0 = *(s32*)(s1 + 400);
	a1 = 1064;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00003C8C;
	t2 = v1 & 0x400;
	t5 = v1 & 0x8;
	if (t2 != 0)
		goto loc_00003C74;
	if (t5 != 0)
	{
		a0 = *(s32*)(s1 + 400);
		goto loc_00003C5C;
	}
	s1 = *(s8*)(s6 + 6);

loc_00003B90:
	s2 = 0;
	s0 = s1 << 3;
	t7 = s0 + s6;
	t6 = *(s32*)(t7 + 348);
	s1 = s4;
	v0 = (u32)s4 < (u32)t6;
	if (v0 == 0)
		s1 = t6;
	s3 = *(s32*)(t7 + 344);
	if (s1 == 0)
		goto loc_00003BDC;

loc_00003BB4:
	t8 = (u32)s1 < (u32)16380;
	s0 = 16380;
	if (t8 != 0)
		s0 = s1;
	a0 = s5 + s2;
	a1 = s3 + s2;
	a2 = s0;
	s1 = s1 - s0;
	v0 = sub_00004A24(...);
	s2 = s2 + s0;
	if (s1 != 0)
		goto loc_00003BB4;

loc_00003BDC:
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = s7 + 1244;
	t9 = *(s8*)(a0 + 6);
	s1 = v0;
	s5 = t9 << 3;
	s3 = s5 + a0;
	v0 = *(s32*)(s3 + 348);
	s2 = (u32)s4 < (u32)v0;
	cond = (s2 == 0);
	s2 = s7 + 1244;
	if (cond)
		goto loc_00003C10;
	s4 = 0x80240000;
	v0 = s4 | 0x390A;

loc_00003C10:
	t0 = *(s8*)(s2 + 6);
	*(s32*)(a0 + 384) = v0;
	a1 = -33;
	a3 = t0 << 3;
	a0 = a3 + s2;
	*(s32*)(a0 + 348) = 0;
	a0 = *(s32*)(s2 + 400);
	v0 = sceKernelClearEventFlag(...);
	a1 = *(s32*)(s2 + 384);
	v1 = 0;
	a0 = *(s32*)(s6 + 400);
	asm("max        $a2, $a1, $v1");
	*(s32*)(s2 + 388) = a2;
	a1 = 128;
	v0 = sceKernelSetEventFlag(...);
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s6 + 400);
	goto loc_00003AD4;

loc_00003C5C:
	*(s32*)(s1 + 384) = 0;
	a1 = 128;

loc_00003C64:
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s6 + 400);
	goto loc_00003AD4;

loc_00003C74:
	a0 = *(s32*)(s1 + 400);
	t4 = 0x80240000;
	t3 = t4 | 0x3902;
	a1 = 128;
	*(s32*)(s1 + 384) = t3;
	goto loc_00003C64;

loc_00003C8C:
	a0 = *(s32*)(s1 + 400);
	a1 = 128;
	*(s32*)(s1 + 384) = v0;
	goto loc_00003C64;

loc_00003C9C:
	s6 = s7 + 1244;
	*(s32*)(s6 + 384) = 0;
	v0 = 0;
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
}

SceUsbMicCopyWorker()	//3CD4
{
	sp = sp - 64;
	*(s32*)(sp + 36) = s5;
	s5 = 0x00000;
	v1 = s5 + 944;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 32) = s4;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 16) = s0;
	*(s32*)(v1 + 52) = 0;
	*(s32*)(sp + 44) = s7;
	s7 = 1;
	*(s32*)(sp + 40) = s6;
	s6 = 4;
	*(s32*)(sp + 20) = s1;
	s1 = v1;
	a0 = *(s32*)(s1 + 276);

loc_00003D18:		
	a1 = 516;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	a1 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_00003E64;
	v1 = a1 & 0x200;
	a1 = 272;
	if (v1 != 0)
		goto loc_00003E64;
	a0 = *(s32*)(s1 + 276);
	a2 = 1;
	a3 = sp;
	t0 = 0;
	s2 = *(s32*)(s1 + 292);
	s0 = *(s32*)(s1 + 288);
	v0 = sceKernelWaitEventFlag(...);
	v1 = v0;
	cond = ((s32)v0 < 0);
	s3 = 0;
	if (cond)
		goto loc_00003DE8;
	a3 = *(s32*)(sp + 0);
	a2 = a3 & 0x100;
	if (a2 != 0)
	{
		v0 = 0x80240000;
		goto loc_00003E5C;
	}
	if (s2 == 0)
	{
		s0 = s5 + 944;
		goto loc_00003DEC;
	}
	t0 = *(s8*)(s1 + 6);
	s4 = 132;
	if (t0 != 0)
		goto loc_00003DDC;
	s4 = 0;
	if (s0 == 0)
		goto loc_00003DE8;
	a0 = *(s32*)(s1 + 276);

loc_00003D98:		
	a1 = 289;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003DE8;
	a0 = *(s32*)(sp + 0);
	t1 = a0 & 0x100;
	if (t1 != 0)
	{
		v0 = 0x80240000;
		goto loc_00003E5C;
	}
	t2 = a0 & 0x1;
	if (t2 != 0)
	{
		a0 = s2 + s3;
		goto loc_00003E38;
	}

loc_00003DD0:		
	t3 = a0 & 0x20;
	if (t3 != 0)
	{
		s0 = s5 + 944;
		goto loc_00003DEC;
	}

loc_00003DDC:		
	t4 = (u32)s4 < (u32)s0;
	if (t4 != 0)
	{
		a0 = *(s32*)(s1 + 276);
		goto loc_00003D98;
	}

loc_00003DE8:		
	s0 = s5 + 944;

loc_00003DEC:		
	*(s32*)(s0 + 52) = v1;
	v0 = sceKernelCpuSuspendIntr(...);
	t5 = *(s8*)(s0 + 4);
	a0 = v0;
	if (t5 == s6)
		goto loc_00003E30;

loc_00003E00:		
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s0 + 276);
	*(s32*)(s0 + 292) = 0;
	a1 = -5;
	*(s32*)(s0 + 288) = 0;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 276);
	a1 = 2;
	v0 = sceKernelSetEventFlag(...);
	a0 = *(s32*)(s1 + 276);
	goto loc_00003D18;

loc_00003E30:		
	*(s8*)(s0 + 4) = s7;
	goto loc_00003E00;

loc_00003E38:		
	a1 = s0;
	v0 = sub_000080F8(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00003DE8;
	a0 = *(s32*)(sp + 0);
	v1 = s3 + v0;
	s0 = s0 - v0;
	s3 = v1;
	goto loc_00003DD0;

loc_00003E5C:		
	v1 = v0 | 0x3902;
	goto loc_00003DE8;

loc_00003E64:		
	ra = *(s32*)(sp + 48);
	s7 = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = 0;
	sp = sp + 64;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	v1 = *(s32*)(a0 + 24);
	s0 = a0;
	if (v1 != 0)
		goto loc_00003EDC;
	s2 = 0x00000;
	s1 = s2 + 1244;
	v1 = *(s8*)(s1 + 112);
	a0 = 9;
	if ((s32)v1 < 0)
		goto loc_00003EDC;
	v1 = *(u8*)(s1 + 113);
	a1 = 10;
	if (v1 == a0)
		goto loc_00003F7C;
	if (v1 == a1)
	{
		t7 = *(u16*)(s1 + 114);
		goto loc_00003EF4;
	}

loc_00003EDC:		
	ra = *(s32*)(sp + 28);

loc_00003EE0:		
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00003EF4:		
	t6 = 16;
	ra = *(s32*)(sp + 28);
	if (t7 != t6)
		goto loc_00003EE0;
	t9 = *(s32*)(s0 + 4);
	s0 = 1;
	v1 = *(s8*)(t9 + 0);
	a0 = *(s8*)(t9 + 1);
	*(s8*)(sp + 0) = v1;
	*(s8*)(sp + 1) = a0;
	t8 = *(s16*)(sp + 0);
	if (t8 == s0)
	{
		v0 = *(s32*)(s1 + 8);
		goto loc_00003F70;
	}
	v1 = *(s32*)(s1 + 8);
	a1 = 0;
	v0 = v1 | 0x400;

loc_00003F30:		
	s0 = s2 + 1244;
	a0 = *(s32*)(s0 + 420);
	*(s32*)(s1 + 8) = v0;
	if ((s32)a0 <= 0)
		goto loc_00003F48;
	v0 = sceKernelNotifyCallback(...);

loc_00003F48:		
	s2 = *(s32*)(s0 + 8);
	s1 = s2 & 0x1000;
	if (s1 == 0)
	{
		ra = *(s32*)(sp + 28);
		goto loc_00003EE0;
	}
	a0 = *(s32*)(s0 + 400);
	a1 = 0x20000;

loc_00003F60:		
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 28);
	goto loc_00003EE0;

loc_00003F70:		
	a1 = 1;
	NONE;
	goto loc_00003F30;

loc_00003F7C:		
	a0 = *(s32*)(s1 + 108);
	a2 = *(u8*)(s1 + 114);
	a3 = *(u8*)(a0 + 2);
	t4 = -1;
	if (a3 == a2)
		goto loc_00003FA4;
	*(s32*)(s1 + 424) = t4;
	t5 = s2 + 1244;

loc_00003F98:		
	a0 = *(s32*)(t5 + 400);
	a1 = 0x10000;
	goto loc_00003F60;

loc_00003FA4:		
	*(s32*)(s1 + 424) = 0;
	a1 = 0;
	a2 = 60;
	t3 = *(u8*)(s0 + 20);
	*(s8*)(a0 + 3) = t3;
	t2 = *(s32*)(s1 + 108);
	a0 = t2 + 4;
	v0 = memset(...);
	a2 = *(s32*)(s0 + 20);
	t0 = *(s32*)(s1 + 108);
	a1 = *(s32*)(s0 + 4);
	v0 = (u32)a2 < (u32)61;
	t1 = 60;
	if (v0 == 0)
		a2 = t1;
	a0 = t0 + 4;
	v0 = memcpy(...);
	t5 = s2 + 1244;
	goto loc_00003F98;
	sp = sp - 32;
	*(s32*)(sp + 20) = s5;
	s5 = 0x00000;
	a1 = s5 + 1244;
	*(s32*)(sp + 16) = s4;
	s4 = 0;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 0) = s0;
	a2 = *(s32*)(a1 + 436);
	v1 = (u32)a2 < (u32)1280;
	s1 = a0;
	if (v1 == 0)
		goto loc_0000406C;
	v1 = *(s32*)(a0 + 24);
	if ((s32)v1 < 0)
	{
		ra = *(s32*)(sp + 24);
		goto loc_00004070;
	}
	a0 = *(s32*)(a1 + 364);
	if (a0 != 0)
	{
		t1 = *(s32*)(a1 + 376);
		goto loc_000040A8;
	}
	v0 = *(s32*)(s1 + 20);
	a3 = 6;
	if (v0 == a3)
	{
		t0 = *(s32*)(s1 + 4);
		goto loc_00004090;
	}
	s5 = 64;

loc_00004054:		
	a0 = *(s32*)(s1 + 4);
	*(s32*)(s1 + 8) = s5;
	a1 = 128;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s1;
	v0 = sceUsbbdReqRecv(...);

loc_0000406C:		
	ra = *(s32*)(sp + 24);

loc_00004070:		
	s5 = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00004090:		
	asm("lwl        $v1, 3($t0)");
	asm("lwr        $v1, 0($t0)");
	asm("swl        $v1, 367($a1)");
	asm("swr        $v1, 364($a1)");
	s5 = 64;
	goto loc_00004054;

loc_000040A8:		
	v1 = *(s32*)(s1 + 20);
	if (t1 == 0)
		goto loc_00004118;
	t2 = *(s32*)(a1 + 380);
	if (t2 == 0)
		goto loc_00004118;
	s3 = a1;
	s2 = v1;
	if (v1 == 0)
		goto loc_00004118;

loc_000040C8:		
	s0 = *(s32*)(s3 + 376);
	t6 = *(s32*)(s1 + 4);
	a0 = *(s32*)(s3 + 380);
	t7 = (u32)v1 < (u32)s0;
	if (t7 != 0)
		s0 = v1;
	a1 = t6 + s4;
	a2 = s0;
	v0 = memcpy(...);
	t5 = *(s32*)(s3 + 380);
	t4 = *(s32*)(s3 + 376);
	s2 = s2 - s0;
	a1 = t5 + s0;
	t3 = t4 - s0;
	*(s32*)(s3 + 376) = t3;
	s4 = s4 + s0;
	*(s32*)(s3 + 380) = a1;
	if (s2 == 0)
		goto loc_00004114;
	v1 = *(s32*)(s1 + 20);
	goto loc_000040C8;

loc_00004114:		
	v1 = *(s32*)(s1 + 20);

loc_00004118:		
	a0 = s5 + 1244;
	s0 = *(s32*)(a0 + 368);
	v1 = s0 + v1;
	*(s32*)(a0 + 368) = v1;
	if (s4 == 0)
		goto loc_00004148;
	s2 = s4 & 0x3F;
	if (s2 != 0)
	{
		s1 = s5 + 1244;
		goto loc_0000414C;
	}
	s4 = *(s32*)(a0 + 364);
	s3 = (u32)s4 < (u32)v1;
	if (s3 == 0)
	{
		s5 = 64;
		goto loc_00004054;
	}

loc_00004148:		
	s1 = s5 + 1244;

loc_0000414C:		
	a0 = *(s32*)(s1 + 400);
	*(s32*)(s1 + 380) = 0;
	a1 = 4096;
	v0 = sceKernelSetEventFlag(...);
	ra = *(s32*)(sp + 24);
	goto loc_00004070;
}

sub_00004164(...) // at 0x00004164 
{
	sp = sp - 32;
	*(s32*)(sp + 0) = s0;
	v1 = 0x00000;
	a1 = v1 + 1244;
	*(s32*)(sp + 20) = ra;
	a0 = a1;
	s0 = 0;
	*(s32*)(sp + 16) = s4;
	v1 = a0;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	a3 = *(s32*)(a1 + 8);
	*(s32*)(a1 + 360) = 0;
	a2 = a3 | 0x1;
	NONE;
	*(s32*)(a1 + 8) = a2;
	a1 = 1;

loc_000041AC:		
	s0 = s0 + 1;
	t0 = (u32)s0 < (u32)2;
	*(s32*)(v1 + 308) = 0;
	*(s32*)(v1 + 312) = a1;
	v1 = v1 + 16;
	if (t0 != 0)
		goto loc_000041AC;
	a1 = a0 + 304;
	*(s32*)(a0 + 300) = a1;
	v1 = a1 + 44;
	s0 = 0;
	*(s32*)(a0 + 296) = a1;
	a0 = a1 - 304;

loc_000041DC:		
	s0 = s0 + 1;
	t1 = (u32)s0 < (u32)2;
	*(s32*)(v1 + 0) = 0;
	v1 = v1 + 8;
	if (t1 != 0)
		goto loc_000041DC;
	t2 = 1;
	v0 = 0x00000;
	*(s8*)(a0 + 6) = t2;
	s3 = v0 + 1244;
	s0 = 0;
	*(s8*)(a0 + 7) = 0;
	s4 = s3 + 204;
	s2 = 0;
	s1 = s3;

loc_00004214:		
	a0 = *(s32*)(s1 + 244);
	a1 = 0;
	a2 = 1792;
	v0 = memset(...);
	a0 = *(s32*)(s1 + 244);
	a1 = 1792;
	s0 = s0 + 1;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s2 + s3;
	t4 = s2 + s4;
	t3 = (u32)s0 < (u32)2;
	*(s32*)(a0 + 192) = t4;
	s1 = s1 + 4;
	s2 = s2 + 40;
	if (t3 != 0)
		goto loc_00004214;
	a0 = s3 + 164;
	*(s32*)(s3 + 232) = 0;
	v0 = sceUsbbdReqRecv(...);
	if ((s32)v0 < 0)
	{
		t5 = *(s32*)(s3 + 188);
		goto loc_00004284;
	}
	ra = *(s32*)(sp + 20);

loc_00004268:		
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00004284:		
	ra = *(s32*)(sp + 20);
	if ((s32)t5 >= 0)
		goto loc_00004268;
	t6 = 1;
	*(s8*)(s3 + 5) = t6;
	goto loc_00004268;
}

sub_00004298(...) // at 0x00004298 
{
	sp = sp - 64;
	*(s32*)(sp + 36) = s1;
	v0 = 0x80240000;
	s1 = a0;
	*(s32*)(sp + 32) = s0;
	a2 = v0 | 0x3905;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 40) = s2;
	s2 = *(s32*)(a1 + 4);
	v1 = (u32)s2 < (u32)10;
	s0 = a1;
	if (v1 == 0)
		goto loc_00004408;
	a3 = *(s32*)(a1 + 8);
	a0 = 0x80240000;
	v1 = (s32)s2 < (s32)a3;
	a2 = a0 | 0x3905;
	if (v1 != 0)
		goto loc_00004408;
	s3 = *(s32*)(a1 + 12);
	t0 = 0x80240000;
	a1 = (u32)s3 < (u32)8;
	a2 = t0 | 0x3905;
	if (a1 == 0)
		goto loc_00004408;
	t2 = *(s32*)(s0 + 16);
	t3 = 0x80240000;
	t1 = (u32)t2 < (u32)3;
	a2 = t3 | 0x3905;
	if (t1 == 0)
		goto loc_00004408;
	t5 = *(s32*)(s0 + 20);
	t6 = 0x80240000;
	t4 = (u32)t5 < (u32)4;
	a2 = t6 | 0x3905;
	if (t4 == 0)
		goto loc_00004408;
	t8 = *(s32*)(s0 + 24);
	t9 = 0x80240000;
	t7 = (u32)t8 < (u32)4;
	a2 = t9 | 0x3905;
	if (t7 == 0)
		goto loc_00004408;
	a0 = *(s32*)(s0 + 28);
	v0 = 0x80240000;
	v1 = (u32)a0 < (u32)256;
	a2 = v0 | 0x3906;
	if (v1 == 0)
		goto loc_00004408;
	t0 = *(s32*)(s0 + 32);
	t1 = 0x80240000;
	a1 = (u32)t0 < (u32)256;
	a2 = t1 | 0x3906;
	if (a1 == 0)
		goto loc_00004408;
	t3 = *(s32*)(s0 + 36);
	t4 = 0x80240000;
	t2 = (u32)t3 < (u32)256;
	a2 = t4 | 0x3906;
	if (t2 == 0)
		goto loc_00004408;
	t6 = *(s32*)(s0 + 40);
	t7 = 0x80240000;
	t5 = (u32)t6 < (u32)256;
	a2 = t7 | 0x3906;
	if (t5 == 0)
		goto loc_00004408;
	t9 = *(s32*)(s0 + 44);
	v1 = 0x80240000;
	t8 = (u32)t9 < (u32)3;
	a2 = v1 | 0x3905;
	if (t8 == 0)
		goto loc_00004408;
	t8 = 0x10000;
	t6 = t8 - 29104;
	t5 = s2 << 2;
	t7 = a3 << 2;
	a1 = t7 + t6;
	t4 = t5 + t6;
	t3 = *(s32*)(a1 + 0);
	v0 = *(s32*)(t4 + 0);
	*(s32*)(sp + 0) = t3;
	*(s32*)(sp + 16) = v0;
	t2 = *(u16*)(sp + 0);
	a0 = *(u16*)(sp + 16);
	t0 = *(u16*)(sp + 18);
	t1 = *(u16*)(sp + 2);
	a1 = a0 - t2;
	a0 = t0 - t1;
	a2 = a0 | a1;
	if ((s32)a2 < 0)
	{
		a3 = 0x80240000;
		goto loc_00004404;
	}
	v1 = *(s32*)(s0 + 56);
	t9 = (s32)a1 < (s32)v1;
	if (t9 != 0)
	{
		a3 = 0x80240000;
		goto loc_00004404;
	}
	t0 = *(s32*)(s0 + 60);
	a2 = (s32)a0 < (s32)t0;
	if (a2 == 0)
	{
		a0 = *(s32*)(s0 + 64);
		goto loc_00004428;
	}
	a3 = 0x80240000;

loc_00004404:		
	a2 = a3 | 0x3905;

loc_00004408:		
	ra = *(s32*)(sp + 48);
	s3 = *(s32*)(sp + 44);
	s2 = *(s32*)(sp + 40);
	s1 = *(s32*)(sp + 36);
	s0 = *(s32*)(sp + 32);
	v0 = a2;
	sp = sp + 64;
	return (v0);

loc_00004428:		
	t2 = 0x80240000;
	t1 = (u32)a0 < (u32)7;
	a2 = t2 | 0x3905;
	if (t1 == 0)
		goto loc_00004408;
	a2 = *(s32*)(s0 + 72);
	a1 = a3;
	a0 = s2;
	v0 = sub_000011F4(...);
	t3 = 0x80240000;
	a2 = t3 | 0x3905;
	if (v0 == 0)
		goto loc_00004408;
	a1 = (s32)s3 < (s32)5;
	if (a1 != 0)
	{
		t7 = *(s32*)(s0 + 76);
		goto loc_00004478;
	}
	t5 = s2 - 7;
	t4 = 0x80240000;
	s3 = (u32)t5 < (u32)3;
	a2 = t4 | 0x3905;
	if (s3 != 0)
		goto loc_00004408;
	t7 = *(s32*)(s0 + 76);

loc_00004478:		
	v0 = 0x80240000;
	t6 = (s32)t7 < (s32)3;
	a2 = v0 | 0x3907;
	if (t6 == 0)
		goto loc_00004408;
	a3 = *(s32*)(s0 + 88);
	a2 = 0x87FF;
	t9 = 0x80240000;
	t0 = a3 - 1;
	t8 = (u32)a2 < (u32)t0;
	a2 = t9 | 0x3907;
	if (t8 != 0)
		goto loc_00004408;
	t1 = *(s32*)(s0 + 92);
	a0 = 0x80240000;
	v1 = (u32)t1 < (u32)3;
	a2 = a0 | 0x3907;
	if (v1 == 0)
		goto loc_00004408;
	a2 = 0x10000;
	t8 = a2 - 29216;
	t7 = s2 + t8;
	t6 = *(u8*)(t7 + 0);
	t5 = 0x10000;
	t4 = t5 - 29204;
	*(s8*)(s1 + 0) = t6;
	t2 = 0x10000;
	a0 = t2 - 29192;
	s3 = *(s32*)(s0 + 8);
	v1 = 0x10000;
	a3 = v1 - 29176;
	a1 = s3 + t4;
	t3 = *(u8*)(a1 + 0);
	t8 = 0x10000;
	t7 = t8 - 29184;
	*(s8*)(s1 + 1) = t3;
	s3 = 0x10000;
	a1 = s3 - 29180;
	s2 = *(s32*)(s0 + 12);
	t1 = s2 + a0;
	v0 = *(u8*)(t1 + 0);
	*(s8*)(s1 + 2) = v0;
	t0 = *(s32*)(s0 + 16);
	t9 = t0 + a3;
	a2 = *(u8*)(t9 + 0);
	t0 = 0x10000;
	t9 = t0 - 29172;
	*(s8*)(s1 + 3) = a2;
	a2 = 0;
	t6 = *(s32*)(s0 + 20);
	t5 = t6 + t7;
	t4 = *(u8*)(t5 + 0);
	*(s8*)(s1 + 4) = t4;
	t4 = 0xFFFF;
	t3 = *(s32*)(s0 + 24);
	t2 = t3 + a1;
	s2 = *(u8*)(t2 + 0);
	*(s8*)(s1 + 5) = s2;
	a0 = *(u8*)(s0 + 28);
	*(s8*)(s1 + 6) = a0;
	t1 = *(u8*)(s0 + 32);
	*(s8*)(s1 + 7) = t1;
	v1 = *(u8*)(s0 + 36);
	*(s8*)(s1 + 8) = v1;
	a3 = *(u8*)(s0 + 40);
	*(s8*)(s1 + 9) = a3;
	a3 = 0x10000;
	t0 = a3 - 29168;
	t8 = *(s32*)(s0 + 44);
	t7 = t8 + t9;
	v0 = *(u8*)(t7 + 0);
	*(s8*)(s1 + 10) = v0;
	t6 = *(s32*)(s0 + 48);
	t5 = (u32)0 < (u32)t6;
	*(s8*)(s1 + 11) = t5;
	s3 = *(s32*)(s0 + 52);
	asm("min        $a1, $s3, $t4");
	t2 = a1 & 0xFFFF;
	t3 = (u32)t2 >> 8;
	*(s8*)(s1 + 13) = t3;
	s3 = 0x10000;
	a1 = s3 - 29160;
	*(s8*)(s1 + 12) = t2;
	s2 = *(u16*)(s0 + 56);
	a0 = (u32)s2 >> 8;
	*(s8*)(s1 + 14) = s2;
	*(s8*)(s1 + 15) = a0;
	v1 = *(u16*)(s0 + 60);
	t1 = (u32)v1 >> 8;
	*(s8*)(s1 + 16) = v1;
	*(s8*)(s1 + 17) = t1;
	t9 = *(s32*)(s0 + 64);
	t8 = t9 + t0;
	t7 = *(u8*)(t8 + 0);
	*(s8*)(s1 + 18) = t7;
	t7 = 0x10000;
	t6 = *(s32*)(s0 + 68);
	t5 = (u32)0 < (u32)t6;
	*(s8*)(s1 + 19) = t5;
	t6 = t7 - 29148;
	t4 = *(u8*)(s0 + 72);
	*(s8*)(s1 + 20) = t4;
	t3 = *(s32*)(s0 + 76);
	t2 = t3 + a1;
	s2 = *(u8*)(t2 + 0);
	a1 = 0x10000;
	t3 = a1 - 29144;
	*(s8*)(s1 + 21) = s2;
	t1 = *(u16*)(s0 + 80);
	a0 = (u32)t1 >> 8;
	*(s8*)(s1 + 23) = a0;
	*(s8*)(s1 + 22) = t1;
	a3 = *(u16*)(s0 + 84);
	v1 = (u32)a3 >> 8;
	*(s8*)(s1 + 25) = v1;
	*(s8*)(s1 + 24) = a3;
	t8 = *(s32*)(s0 + 88);
	v0 = (u32)t8 >> 24;
	NONE;
	NONE;
	*(s8*)(s1 + 27) = t0;
	*(s8*)(s1 + 28) = t9;
	*(s8*)(s1 + 29) = v0;
	*(s8*)(s1 + 26) = t8;
	t5 = *(s32*)(s0 + 92);
	t4 = t5 + t6;
	s3 = *(u8*)(t4 + 0);
	*(s8*)(s1 + 30) = s3;
	t2 = *(s32*)(s0 + 96);
	s2 = t2 + t3;
	s0 = *(u8*)(s2 + 0);
	*(s8*)(s1 + 31) = s0;
	goto loc_00004408;
}

sub_00004680(...) // at 0x00004680 
{
	a2 = a1;
	a1 = *(s32*)(a1 + 12);
	a3 = 0x80000;
	t1 = 0x80240000;
	v1 = (u32)a3 < (u32)a1;
	t0 = a0;
	a3 = t1 | 0x3907;
	if (v1 != 0)
		goto loc_000046D8;
	a0 = *(s32*)(a2 + 4);
	v0 = 0x80240000;
	v1 = (s32)a0 < (s32)10;
	a3 = v0 | 0x3905;
	if (v1 == 0)
		goto loc_000046D8;
	v1 = *(s32*)(a2 + 8);
	t2 = (s32)v1 < (s32)10;
	if (t2 == 0)
	{
		a0 = 0x80240000;
		goto loc_000046D4;
	}
	t3 = (s32)a0 < (s32)v1;
	if (t3 == 0)
	{
		t5 = *(s32*)(a2 + 24);
		goto loc_000046E0;
	}
	a0 = 0x80240000;

loc_000046D4:		
	a3 = a0 | 0x3905;

loc_000046D8:		
	v0 = a3;
	return (v0);

loc_000046E0:		
	t6 = 0x80240000;
	t4 = (s32)t5 < (s32)3;
	a3 = t6 | 0x3905;
	if (t4 == 0)
		goto loc_000046D8;
	t9 = *(s32*)(a2 + 16);
	t1 = 0x80240000;
	t8 = t9 - 1;
	t7 = (u32)t8 < (u32)63;
	a3 = t1 | 0x3907;
	if (t7 == 0)
		goto loc_000046D8;
	t2 = *(s32*)(a2 + 36);
	v0 = 0x80240000;
	v1 = (u32)t2 < (u32)4;
	a3 = v0 | 0x3905;
	if (v1 == 0)
		goto loc_000046D8;
	a0 = *(s32*)(a2 + 52);
	t4 = 0x80240000;
	t3 = (u32)a0 < (u32)7;
	a3 = t4 | 0x3905;
	if (t3 == 0)
		goto loc_000046D8;
	t6 = *(s32*)(a2 + 56);
	t7 = 0x80240000;
	t5 = (u32)t6 < (u32)3;
	a3 = t7 | 0x3907;
	if (t5 == 0)
		goto loc_000046D8;
	t3 = (u32)a1 >> 24;
	NONE;
	NONE;
	*(s8*)(t0 + 1) = a0;
	t2 = 1;
	t9 = 0x10000;
	*(s8*)(t0 + 2) = t4;
	t8 = t9 - 29216;
	t6 = 0x10000;
	*(s8*)(t0 + 3) = t3;
	v1 = t6 - 29204;
	t3 = 0x10000;
	*(s8*)(t0 + 0) = a1;
	t1 = *(u8*)(a2 + 16);
	*(s8*)(t0 + 5) = t2;
	t2 = t3 - 29176;
	*(s8*)(t0 + 4) = t1;
	a1 = *(s32*)(a2 + 4);
	a3 = a1 + t8;
	t7 = *(u8*)(a3 + 0);
	a3 = 0;
	*(s8*)(t0 + 6) = t7;
	t5 = *(s32*)(a2 + 8);
	a0 = t5 + v1;
	t4 = *(u8*)(a0 + 0);
	t5 = 0x10000;
	a0 = t5 - 29152;
	*(s8*)(t0 + 7) = t4;
	t1 = *(s32*)(a2 + 24);
	t9 = t1 + t2;
	v0 = *(u8*)(t9 + 0);
	t2 = 0x10000;
	t1 = t2 - 29160;
	*(s8*)(t0 + 8) = v0;
	t8 = *(s32*)(a2 + 28);
	a1 = (u32)0 < (u32)t8;
	*(s8*)(t0 + 9) = a1;
	t7 = *(s32*)(a2 + 32);
	t6 = (u32)0 < (u32)t7;
	*(s8*)(t0 + 10) = t6;
	t4 = *(s32*)(a2 + 36);
	v1 = t4 + a0;
	t3 = *(u8*)(v1 + 0);
	t4 = 0x10000;
	v1 = t4 - 29168;
	*(s8*)(t0 + 11) = t3;
	t9 = *(s32*)(a2 + 40);
	t8 = t9 + t1;
	v0 = *(u8*)(t8 + 0);
	t1 = 0x10000;
	t9 = t1 - 29148;
	*(s8*)(t0 + 12) = v0;
	t7 = *(u16*)(a2 + 44);
	a1 = (u32)t7 >> 8;
	*(s8*)(t0 + 14) = a1;
	*(s8*)(t0 + 13) = t7;
	t5 = *(u16*)(a2 + 48);
	t6 = (u32)t5 >> 8;
	*(s8*)(t0 + 16) = t6;
	*(s8*)(t0 + 15) = t5;
	a0 = *(s32*)(a2 + 52);
	t3 = a0 + v1;
	t2 = *(u8*)(t3 + 0);
	*(s8*)(t0 + 17) = t2;
	t8 = *(s32*)(a2 + 56);
	a2 = t8 + t9;
	a1 = *(u8*)(a2 + 0);
	*(s8*)(t0 + 18) = a1;
	goto loc_000046D8;
}

sub_00004858(...) // at 0x00004858 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 1244);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	s0 = a0 + 1244;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 4) = ra;
	if (a1 == 0)
		goto loc_000048C8;
	a1 = *(s8*)(s0 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 == 0)
		goto loc_000048C8;
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_000048C8;
	t0 = *(u8*)(s0 + 1);
	t1 = 0x80240000;
	a3 = t0 & 0x2;
	a0 = t1 | 0x3901;
	if (a3 == 0)
		goto loc_000048C8;
	t3 = *(s32*)(s0 + 8);
	t4 = 0x80240000;
	a0 = t4 | 0x390C;
	t2 = t3 & 0x8;
	if (t2 != 0)
		a0 = 0;

loc_000048C8:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);
}

sub_000048DC(...) // at 0x000048DC 
{
	sp = sp - 32;
	*(s32*)(sp + 28) = ra;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	if (a0 == 0)
		goto loc_000049F4;
	s2 = 0x00000;
	s1 = s2 + 1244;
	a0 = *(s32*)(s1 + 400);
	a1 = 13312;
	a2 = 1;
	a3 = sp;
	v0 = sceKernelPollEventFlag(...);
	v1 = 0x80020000;
	a1 = 0x80240000;
	a0 = v1 | 0x1AF;
	s0 = v0;
	v1 = a1 | 0x390E;
	if (v0 == a0)
		goto loc_00004984;
	if ((s32)v0 < 0)
	{
		t9 = *(s32*)(s1 + 8);
		goto loc_00004978;
	}

loc_00004930:		
	v1 = *(s32*)(sp + 0);
	a3 = v1 & 0x2400;
	if (a3 == 0)
	{
		v1 = s2 + 1244;
		goto loc_000049CC;
	}
	a0 = s2 + 1244;
	t3 = *(s32*)(a0 + 436);
	t2 = 0x80240000;
	t1 = v1 & 0x400;
	s0 = t2 | 0x3902;
	t0 = (u32)t3 < (u32)1280;
	if (t1 == 0)
		s0 = 0;
	if (t0 != 0)
		goto loc_000049BC;

loc_00004960:		
	s1 = s2 + 1244;

loc_00004964:		
	t7 = *(s32*)(s1 + 436);
	t6 = (u32)t7 < (u32)1280;
	if (t6 == 0)
	{
		t8 = *(s32*)(s1 + 8);
		goto loc_000049A0;
	}
	t9 = *(s32*)(s1 + 8);

loc_00004978:		
	v1 = s0;
	NONE;
	*(s32*)(s1 + 8) = t9;

loc_00004984:		
	ra = *(s32*)(sp + 28);

loc_00004988:		
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_000049A0:		
	a0 = *(s32*)(s1 + 400);
	a1 = 0x100000;
	s2 = t8 | 0x10;
	*(s32*)(s1 + 8) = s2;
	v0 = sceKernelSetEventFlag(...);
	t9 = *(s32*)(s1 + 8);
	goto loc_00004978;

loc_000049BC:		
	a0 = a0 + 252;
	v0 = sceUsbbdReqCancel(...);
	s1 = s2 + 1244;
	goto loc_00004964;

loc_000049CC:		
	a1 = *(s32*)(v1 + 368);
	a0 = *(s32*)(v1 + 372);
	v0 = 0x80240000;
	t4 = (u32)a0 < (u32)a1;
	s0 = v0 | 0x390A;
	if (t4 != 0)
		goto loc_00004960;
	t5 = *(s32*)(v1 + 376);
	s0 = a0;
	if (t5 != 0)
		s0 = a1;
	goto loc_00004960;

loc_000049F4:		
	s2 = 0x00000;
	a2 = s2 + 1244;
	a0 = *(s32*)(a2 + 400);
	a1 = 13312;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = v0;
	if ((s32)v0 >= 0)
		goto loc_00004930;
	ra = *(s32*)(sp + 28);
	goto loc_00004988;
}

sub_00004A24(...) // at 0x00004A24 
{
	v1 = 0x220000;
	t0 = v1 | 0x202;
	NONE;
	a3 = (s32)t0 >> t1;
	sp = sp - 32;
	v1 = a3 & 0x1;
	*(s32*)(sp + 16) = s4;
	s4 = a2;
	*(s32*)(sp + 12) = s3;
	s3 = a1;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	if (v1)
	{
		t2 = 0x00000;
		s5 = t2 + 1244;
		v0 = *(s32*)(s5 + 392);
		if (v0 != 0)
		{
			a0 = v0;
			goto loc_00004AB0;
		}
	}
loc_00004A80:		
	v0 = SysMemForKernel_181065AB(...);

loc_00004A88:
	return (v0);

loc_00004AB0:		
	a1 = 255;
	a2 = 255;
	a3 = 0;
	t0 = 0;
	v0 = sceKernelDmaOpAssign();
	s0 = v0;
	s6 = s4 & 0x3;
	s2 = (u32)s4 >> 2;
	if ((s32)v0 < 0)
	{
		a1 = 0x10000;
		v0 = 0x10000;
		a0 = a1 - 29400;
		a2 = s0;
		a1 = v0 - 29600;
		v0 = Kprintf(...);
	}
	t5 = (u32)s3 >> 31;

loc_00004AD8:		
	a0 = t5 ^ 0x1;
	t6 = (u32)s1 >> 31;
	a2 = t6 ^ 0x1;
	t3 = a0 << 30;
	a0 = *(s32*)(s5 + 392);	// _DmaOp
	t4 = a2 << 30;
	a1 = t4;
	asm("ins     $a1, $s1, 0, 0x1D");
	a2 = t3;
	asm("ins     $a2, $s3, 0, 0x1D");
	a3 = s2;
	v0 = sceKernelDmaOpSetupMemcpy(...);
	t8 = 0x10000;
	if ((s32)v0 < 0)
		goto loc_00004BC4;
	s2 = s2 << 2;

loc_00004B14:		
	a0 = s1;
	a1 = s2;
	v0 = sceKernelDcacheInvalidateRange(...);
	a0 = s3;
	a1 = s2;
	v0 = sceKernelDcacheWritebackInvalidateRange(...);
	a0 = 0;
	v0 = sceKernelPowerLock(...);
	a0 = *(s32*)(s5 + 392);
	v0 = sceKernelDmaOpEnQueue(...);
	a1 = s3;
	if ((s32)v0 < 0)
		goto loc_00004BB0;
	a1 = s2 + s3;
	if (s6 != 0)
		goto loc_00004B9C;
	a0 = *(s32*)(s5 + 392);

loc_00004B50:		
	a1 = 1;
	a2 = 0;
	v0 = sceKernelDmaOpSync(...);
	s0 = v0;
	a0 = 1;
	v0 = sceDdrFlush(...);
	cond = ((s32)s0 < 0);
	s3 = 0x10000;
	if (cond)
		goto loc_00004B80;

loc_00004B70:		
	a0 = 0;
	v0 = sceKernelPowerUnlock(...);
	v0 = s1;
	goto loc_00004A88;

loc_00004B80:		
	s2 = 0x10000;
	a0 = s3 - 29444;
	a1 = s2 - 29600;
	a2 = s0;
	v0 = Kprintf("%serror - Fail to transrate by DMA. 0x%");
	goto loc_00004B70;

loc_00004B9C:		
	a0 = s2 + s1;
	a2 = s6;
	v0 = memcpy(...);
	a0 = *(s32*)(s5 + 392);
	goto loc_00004B50;

loc_00004BB0:		
	a2 = s4;
	a0 = s1;
	v0 = memcpy(...);
	goto loc_00004B70;

loc_00004BC4:		
	t7 = 0x10000;
	a0 = t8 - 29480;
	a1 = t7 - 29600;
	a2 = v0;
	v0 = Kprintf("%serror - Fail to setup DMA 0x%08x\n");
	s2 = s2 << 2;
	goto loc_00004B14;
}

sub_00004C00(...) // at 0x00004C00 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	s5 = 0x00000;
	*(s32*)(sp + 16) = s0;
	s0 = s5 + 1244;
	*(s32*)(sp + 32) = s4;
	s4 = a0;
	*(s32*)(sp + 28) = s3;
	s3 = 0;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 40) = ra;
	s2 = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	v1 = *(s8*)(s0 + 2);
	s1 = v0;
	if (v1 != 0)
		goto loc_00004D98;

loc_00004C44:		
	s2 = 1;

loc_00004C48:		
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	v1 = s3;
	if (s2 == 0)
		goto loc_00004C80;

loc_00004C58:		
	ra = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00004C80:		
	s0 = s5 + 1244;
	a0 = *(s32*)(s0 + 400);
	a1 = 1280;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s3 = v0;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00004C58;
	t3 = *(s32*)(sp + 0);
	t2 = t3 & 0x400;
	v1 = 0;
	if (t2 != 0)
		goto loc_00004C58;
	v0 = sceKernelCpuSuspendIntr(...);
	t5 = *(s8*)(s0 + 4);
	t4 = 2;
	s1 = v0;
	if (t5 == t4)
		goto loc_00004D58;
	s0 = s5 + 1244;
	s2 = *(s8*)(s0 + 4);
	t7 = 3;
	if (s2 == t7)
	{
		a0 = *(s32*)(s0 + 400);
		goto loc_00004D14;
	}
	*(s8*)(s0 + 4) = 0;

loc_00004CE8:		
	a0 = s1;

loc_00004CEC:		
	s1 = s5 + 1244;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s1 + 400);
	a1 = 1152;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = s3;
	goto loc_00004C58;

loc_00004D14:		
	a1 = -2050;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 8;
	v0 = sceKernelSetEventFlag(...);
	a0 = s0;
	v0 = s0 + 348;
	v1 = 1;

loc_00004D34:		
	v1 = v1 - 1;
	*(s32*)(v0 + 0) = 0;
	v0 = v0 + 8;
	if ((s32)v1 >= 0)
		goto loc_00004D34;
	s4 = 0x80240000;
	s0 = s4 | 0x390A;
	*(s32*)(a0 + 384) = s0;
	*(s8*)(a0 + 4) = 0;
	goto loc_00004CE8;

loc_00004D58:		
	a0 = *(s32*)(s0 + 400);
	a1 = -2050;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	*(s8*)(s0 + 4) = 0;
	a1 = 8;
	v0 = sceKernelSetEventFlag(...);
	a0 = s0 + 348;
	v1 = 0;

loc_00004D7C:		
	v1 = v1 + 1;
	t6 = (s32)v1 < (s32)2;
	*(s32*)(a0 + 0) = 0;
	a0 = a0 + 8;
	if (t6 != 0)
		goto loc_00004D7C;
	a0 = s1;
	goto loc_00004CEC;

loc_00004D98:		
	v0 = sceUsbAccGetAuthStat(...);
	if (v0 != 0)
	{
		a0 = *(s32*)(s0 + 400);
		goto loc_00004E9C;
	}
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s0 + 400);
	a1 = 1026;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	cond = ((s32)v0 < 0);
	s3 = v0;
	if (cond)
		goto loc_00004DE8;
	a1 = *(s32*)(sp + 0);
	if (s4 != 0)
		goto loc_00004E60;

loc_00004DD8:		
	a0 = a1 & 0x400;
	if (a0 == 0)
	{
		a0 = *(s32*)(s0 + 408);
		goto loc_00004E14;
	}
	s2 = 1;

loc_00004DE8:		
	v0 = sceKernelCpuSuspendIntr(...);
	s1 = v0;
	if ((s32)s3 >= 0)
		goto loc_00004C48;
	a3 = s5 + 1244;
	a0 = *(s32*)(a3 + 408);
	a1 = 1;
	s2 = 1;
	v0 = sceKernelUnlockMutex(...);
	goto loc_00004C48;

loc_00004E14:		
	a1 = 1;
	a2 = 0;
	v0 = sceKernelLockMutex(...);

loc_00004E20:		
	s3 = v0;
	if (v0 != 0)
		goto loc_00004DE8;
	a0 = 4;
	if (s4 != 0)
		goto loc_00004E34;
	a0 = 2;

loc_00004E34:		
	a1 = 2;
	a2 = 0;
	a3 = 0;
	v0 = sub_00000000(...);
	a2 = s5 + 1244;
	a0 = *(s32*)(a2 + 408);
	a1 = 1;
	s3 = v0;
	v0 = sceKernelUnlockMutex(...);
	goto loc_00004DE8;

loc_00004E60:		
	a0 = *(s32*)(s0 + 400);
	v0 = 0x100000;
	a1 = v0 | 0x400;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	cond = ((s32)v0 < 0);
	s3 = v0;
	if (cond)
		goto loc_00004DE8;
	a0 = *(s32*)(s0 + 400);
	v1 = 0xFFEF0000;
	a1 = v1 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	a1 = *(s32*)(sp + 0);
	goto loc_00004DD8;

loc_00004E9C:		
	a1 = -5;
	v0 = sceKernelClearEventFlag(...);
	a0 = s0;
	a1 = 1;
	v0 = s0;
	v1 = 1;

loc_00004EB4:		
	v1 = v1 - 1;
	*(s32*)(v0 + 312) = a1;
	*(s32*)(v0 + 308) = 0;
	v0 = v0 + 16;
	if ((s32)v1 >= 0)
		goto loc_00004EB4;
	t1 = *(s8*)(a0 + 4);
	t0 = 2;
	s0 = a0;
	if (t1 == t0)
		goto loc_00004EE0;
	*(s8*)(a0 + 4) = 0;
	goto loc_00004C44;

loc_00004EE0:		
	a0 = *(s32*)(a0 + 400);
	a1 = -2050;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 400);
	*(s8*)(s0 + 4) = 0;
	a1 = 8;
	v0 = sceKernelSetEventFlag(...);
	s2 = 1;
	goto loc_00004C48;
}

sub_00004F04(...) // at 0x00004F04 
{
	sp = sp - 80;
	*(s32*)(sp + 68) = ra;
	*(s32*)(sp + 60) = s7;
	*(s32*)(sp + 56) = s6;
	*(s32*)(sp + 52) = s5;
	*(s32*)(sp + 44) = s3;
	*(s32*)(sp + 40) = s2;
	*(s32*)(sp + 36) = s1;
	*(s32*)(sp + 32) = s0;
	*(s32*)(sp + 8) = a0;
	*(s32*)(sp + 12) = 0;
	*(s32*)(sp + 16) = 0;
	*(s32*)(sp + 20) = 0;
	*(s32*)(sp + 64) = fp;
	fp = 0x00000;
	*(s32*)(sp + 48) = s4;
	s4 = fp + 1244;
	a0 = *(s32*)(s4 + 400);

loc_00004F4C:		
	a1 = 1028;
	a2 = 1;
	a3 = sp + 4;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_0000553C;
	v1 = *(s32*)(sp + 4);
	a0 = v1 & 0x400;
	a1 = 0x20000;
	if (a0 != 0)
		goto loc_0000553C;
	a0 = v1 & a1;
	s0 = fp + 1244;
	if (a0 == 0)
		goto loc_00004FB8;
	a2 = *(s32*)(s4 + 8);
	v1 = a2 & 0x400;
	v0 = 257;
	if (v1 != 0)
		goto loc_00004F98;
	v0 = 256;

loc_00004F98:		
	a0 = sp;
	*(s16*)(sp + 0) = v0;
	v0 = sub_000000F4(...);
	v0 = 0xFFFD0000;
	a0 = *(s32*)(s4 + 400);
	a1 = v0 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	s0 = fp + 1244;

loc_00004FB8:		
	t0 = *(s8*)(s0 + 5);
	a3 = 1;
	if (t0 == a3)
	{
		a0 = *(s32*)(s0 + 400);
		goto loc_00005578;
	}
	t6 = *(u8*)(s0 + 4);

loc_00004FCC:		
	t5 = t6 - 2;
	t4 = t5 & 0xFF;
	t3 = (u32)t4 < (u32)2;
	if (t3 != 0)
		goto loc_0000553C;
	s1 = 0;
	v0 = sceKernelCpuSuspendIntr(...);
	s0 = *(s32*)(s0 + 300);
	s6 = v0;
	v0 = *(s32*)(s0 + 8);
	if (v0 == 0)
	{
		t8 = *(s8*)(s4 + 7);
		goto loc_00005038;
	}

loc_00004FFC:		
	s5 = (s32)s1 < (s32)2;
	if (v0 == 0)
		goto loc_0000502C;
	s1 = s1 + 1;
	s3 = (s32)s1 < (s32)2;
	s0 = *(s32*)(s0 + 12);
	if (s3 == 0)
		goto loc_0000501C;
	v0 = *(s32*)(s0 + 8);
	goto loc_00004FFC;

loc_0000501C:		
	a0 = s6;
	v0 = sceKernelCpuResumeIntr(...);
	a0 = *(s32*)(s4 + 400);
	goto loc_00004F4C;

loc_0000502C:		
	if (s5 == 0)
		goto loc_0000501C;
	t8 = *(s8*)(s4 + 7);

loc_00005038:		
	a0 = *(s32*)(s4 + 400);
	a1 = -5;
	s7 = t8 << 3;
	s1 = s4 + 344;
	s3 = s7 + s1;
	v0 = sceKernelClearEventFlag(...);
	v0 = sceUsbAccGetAuthStat(...);
	s7 = s1 - 344;
	if (v0 != 0)
		goto loc_0000501C;
	s1 = 0;

loc_00005064:		
	a0 = *(s32*)(s0 + 0);
	t9 = 0xD8FF;
	a1 = *(s8*)(a0 + 0);
	a2 = *(s8*)(a0 + 1);
	*(s8*)(sp + 2) = a1;
	*(s8*)(sp + 3) = a2;
	a1 = *(u16*)(sp + 2);
	cond = (a1 == t9);
	a1 = fp + 1244;
	if (cond)
		goto loc_000054A4;

loc_00005088:		
	s2 = fp + 1244;

loc_0000508C:		
	s5 = *(s32*)(s2 + 8);
	t7 = s5 & 0x2;
	if (t7 != 0)
	{
		s5 = *(s32*)(s0 + 12);
		goto loc_0000513C;
	}
	t9 = *(s32*)(s2 + 436);
	t8 = (u32)t9 < (u32)1280;
	a1 = *(s32*)(sp + 8);
	if (t8 == 0)
		goto loc_000051B8;
	t2 = *(s32*)(s3 + 4);
	v0 = *(s32*)(s2 + 340);
	a0 = *(s32*)(s0 + 4);
	t1 = *(s32*)(s3 + 0);
	a2 = v0 - t2;
	a1 = *(s32*)(s0 + 0);
	t3 = (u32)a2 < (u32)a0;
	if (t3 == 0)
		a2 = a0;
	a0 = t1 + t2;
	v0 = SysMemForKernel_181065AB(...);
	a3 = *(s32*)(s3 + 4);
	v1 = *(s32*)(s0 + 4);
	t0 = a3 + v1;
	*(s32*)(s3 + 4) = t0;
	a2 = *(s32*)(s2 + 340);
	a1 = (u32)a2 < (u32)t0;
	if (a1 != 0)
	{
		s0 = *(s32*)(s2 + 8);
		goto loc_000051A8;
	}
	t5 = *(s32*)(s0 + 4);
	t4 = (u32)t5 < (u32)896;
	if (t4 == 0)
	{
		s5 = *(s32*)(s0 + 12);
		goto loc_0000513C;
	}
	s5 = *(s32*)(s2 + 8);
	a2 = *(u8*)(s2 + 7);
	a1 = *(u8*)(s2 + 6);
	t7 = s5 | 0x1;
	t6 = (s8)a2;
	a0 = (s8)a1;
	*(s32*)(s2 + 8) = t7;
	if (t6 == a0)
		goto loc_00005134;
	t9 = *(s32*)(s2 + 360);
	t8 = *(s32*)(s3 + 4);
	v1 = a0 << 3;
	if (t9 == t8)
		goto loc_00005170;

loc_00005134:		
	*(s32*)(s3 + 4) = 0;

loc_00005138:		
	s5 = *(s32*)(s0 + 12);

loc_0000513C:		
	v1 = 1;
	*(s32*)(s0 + 8) = v1;
	*(s32*)(s7 + 300) = s5;
	v1 = *(s32*)(s0 + 12);
	*(s32*)(s0 + 4) = 0;
	s0 = *(s32*)(v1 + 8);
	s1 = s1 + 1;
	if (s0 != 0)
		goto loc_0000501C;
	a0 = (s32)s1 < (s32)2;
	s0 = v1;
	if (a0 != 0)
		goto loc_00005064;
	goto loc_0000501C;

loc_00005170:		
	a3 = v1 + s2;
	t0 = *(s32*)(a3 + 348);
	if (t0 != 0)
	{
		*(s32*)(s3 + 4) = 0;
		goto loc_00005138;
	}
	a0 = *(s32*)(s2 + 400);
	t2 = a1 ^ 0x1;
	t1 = a2 ^ 0x1;
	a1 = 32;
	*(s8*)(s2 + 6) = t2;
	*(s8*)(s2 + 7) = t1;

loc_00005198:		
	v0 = sceKernelSetEventFlag(...);
	s5 = *(s32*)(s0 + 12);
	goto loc_0000513C;

loc_000051A8:		
	t7 = s0 | 0x3;
	*(s32*)(s2 + 8) = t7;
	*(s32*)(s3 + 4) = 0;
	goto loc_0000501C;

loc_000051B8:		
	if (a1 == 0)
	{
		v1 = *(s32*)(s2 + 340);
		goto loc_000051C4;
	}
	v1 = *(s32*)(s2 + 372);

loc_000051C4:		
	t3 = *(s32*)(s3 + 4);
	a2 = *(s32*)(s0 + 4);
	a0 = t3 + a2;
	s2 = (u32)v1 < (u32)a0;
	t4 = 0xD9FF;
	if (s2 != 0)
		goto loc_00005494;
	a1 = *(s32*)(s0 + 0);
	t5 = a1 + a2;
	a3 = *(s8*)(t5 - 2);
	t0 = *(s8*)(t5 - 1);
	*(s8*)(sp + 2) = a3;
	*(s8*)(sp + 3) = t0;
	v0 = *(u16*)(sp + 2);
	t6 = 0xFEFF;
	if (v0 == t4)
		goto loc_000052BC;
	a0 = *(s32*)(sp + 8);

loc_00005204:		
	a3 = 0x00000;

loc_00005208:		
	s2 = a3 + 1624;
	s5 = s2 - 12;
	if (a0 != 0)
		goto loc_0000521C;
	s2 = s3;
	s5 = s3 + 4;

loc_0000521C:		
	t5 = *(s32*)(s7 + 8);
	t1 = t5 & 0x1;
	t6 = *(s32*)(sp + 8);
	if (t1 == 0)
		goto loc_0000529C;
	if (t6 == 0)
	{
		t9 = *(s32*)(s2 + 0);
		goto loc_00005264;
	}
	a0 = *(s32*)(s2 + 0);
	a1 = *(s32*)(s0 + 0);
	a2 = *(s32*)(s0 + 4);
	v0 = SysMemForKernel_181065AB(...);

loc_00005244:		
	t2 = *(s32*)(s7 + 8);
	NONE;
	*(s32*)(s7 + 8) = t2;
	v0 = *(s32*)(s0 + 4);

loc_00005254:		
	t4 = *(s32*)(s5 + 0);
	t3 = t4 + v0;
	*(s32*)(s5 + 0) = t3;
	goto loc_00005138;

loc_00005264:		
	a1 = a1 + 2;
	a2 = a2 - 2;
	a0 = t9 + 14;
	v0 = SysMemForKernel_181065AB(...);
	t7 = *(s32*)(s2 + 0);
	t8 = *(s32*)(s0 + 0);
	t1 = *(s8*)(t8 + 0);
	v0 = *(s8*)(t8 + 1);
	*(s8*)(t7 + 0) = t1;
	*(s8*)(t7 + 1) = v0;
	a1 = *(s32*)(s5 + 0);
	a2 = a1 + 12;
	*(s32*)(s5 + 0) = a2;
	goto loc_00005244;

loc_0000529C:		
	t0 = *(s32*)(s2 + 0);
	s2 = *(s32*)(s5 + 0);
	a1 = *(s32*)(s0 + 0);
	a2 = *(s32*)(s0 + 4);
	a0 = t0 + s2;
	v0 = SysMemForKernel_181065AB(...);
	v0 = *(s32*)(s0 + 4);
	goto loc_00005254;

loc_000052BC:		
	a0 = *(s8*)(a1 + 0);
	a3 = *(s8*)(a1 + 1);
	*(s8*)(sp + 2) = a0;
	*(s8*)(sp + 3) = a3;
	t7 = *(u16*)(sp + 2);
	a0 = *(s32*)(sp + 8);
	if (t7 != t6)
		goto loc_00005204;
	s5 = 16;
	a3 = 0x00000;
	if (a2 != s5)
		goto loc_00005208;
	a2 = *(s32*)(sp + 8);
	if (a2 == 0)
	{
		t7 = 0x00000;
		goto loc_000053E4;
	}
	t0 = 0x00000;
	t2 = t0 + 1608;
	asm("lwl        $a3, 7($a1)");
	asm("lwr        $a3, 4($a1)");
	asm("swl        $a3, 3($t2)");
	asm("swr        $a3, 0($t2)");
	v1 = t2 - 364;
	a2 = *(s32*)(v1 + 364);
	t8 = *(s32*)(v1 + 368);
	if (a2 == t8)
	{
		a1 = *(s32*)(v1 + 44);
		goto loc_00005328;
	}
	*(s32*)(v1 + 368) = 0;
	*(s32*)(v1 + 364) = 0;
	goto loc_00005138;

loc_00005328:		
	t0 = *(s32*)(s0 + 0);
	t1 = 0xFC00;
	v1 = *(s32*)(sp + 12);
	t4 = (u32)t1 < (u32)a1;
	a3 = *(u8*)(t0 + 9);
	if (t4 != 0)
		a1 = t1;
	t3 = a1 - a2;
	a0 = (u32)a1 < (u32)a2;
	s2 = v1 + 1;
	a2 = a2 - a1;
	if (a0 == 0)
		a2 = t3;
	if (s2 == a3)
		goto loc_000053C4;

loc_00005358:		
	t2 = *(s32*)(sp + 20);
	s5 = *(s32*)(sp + 12);
	t9 = t2 + 1;
	t8 = t9 & 0xFF;
	*(s32*)(sp + 20) = t8;
	if (a3 == s5)
		goto loc_00005374;
	*(s32*)(sp + 20) = 0;

loc_00005374:		
	a0 = *(s32*)(sp + 16);
	s2 = (u32)a2 < (u32)1024;
	t3 = (u32)0 < (u32)a0;
	a3 = s2 | t3;
	v1 = *(s32*)(sp + 20);
	if (a3 != 0)
		goto loc_000053A8;
	a2 = (u32)v1 < (u32)3;
	if (a2 == 0)
	{
		a0 = *(s32*)(s7 + 400);
		goto loc_000053AC;
	}
	t1 = *(u8*)(t0 + 9);
	*(s32*)(s7 + 368) = 0;
	*(s32*)(sp + 12) = t1;
	goto loc_00005138;

loc_000053A8:		
	a0 = *(s32*)(s7 + 400);

loc_000053AC:		
	*(s32*)(s7 + 380) = 0;
	a1 = 4100;
	s0 = 2;
	v0 = sceKernelSetEventFlag(...);
	*(s8*)(s7 + 4) = s0;
	goto loc_0000501C;

loc_000053C4:		
	t7 = *(s32*)(s7 + 364);
	v0 = a1 + 1024;
	a1 = *(s32*)(sp + 16);
	t6 = (u32)t7 < (u32)v0;
	t5 = 1;
	if (t6 != 0)
		a1 = t5;
	*(s32*)(sp + 16) = a1;
	goto loc_00005358;

loc_000053E4:		
	t0 = t7 + 1604;
	asm("lwl        $t1, 7($a1)");
	asm("lwr        $t1, 4($a1)");
	asm("swl        $t1, 3($t0)");
	asm("swr        $t1, 0($t0)");
	a3 = t0 - 360;
	t5 = *(s32*)(a3 + 360);
	a1 = t5 + 12;
	*(s32*)(a3 + 360) = a1;
	t4 = *(s32*)(s3 + 4);
	t6 = t0;
	if (a1 != t4)
		goto loc_00005134;
	t2 = *(s8*)(a3 + 6);
	t9 = t2 << 3;
	t8 = t9 + a3;
	s5 = *(s32*)(t8 + 348);
	if (s5 != 0)
	{
		*(s32*)(s3 + 4) = 0;
		goto loc_00005138;
	}
	t4 = *(s32*)(s0 + 0);
	a1 = 32;
	asm("lwl        $t0, 3($t6)");
	asm("lwr        $t0, 0($t6)");
	asm("swl        $t0, 7($t4)");
	asm("swr        $t0, 4($t4)");
	t3 = *(s32*)(s3 + 0);
	v1 = *(s32*)(s0 + 0);
	asm("lwl        $t0, 3($v1)");
	asm("lwr        $t0, 0($v1)");
	asm("lwl        $t1, 7($v1)");
	asm("lwr        $t1, 4($v1)");
	asm("lwl        $a0, 11($v1)");
	asm("lwr        $a0, 8($v1)");
	asm("swl        $t0, 5($t3)");
	asm("swr        $t0, 2($t3)");
	asm("swl        $t1, 9($t3)");
	asm("swr        $t1, 6($t3)");
	asm("swl        $a0, 13($t3)");
	asm("swr        $a0, 10($t3)");
	t0 = *(u8*)(a3 + 7);
	a0 = *(s32*)(a3 + 400);
	s2 = t0 ^ 0x1;
	*(s8*)(a3 + 7) = s2;
	*(s8*)(a3 + 6) = t0;
	goto loc_00005198;

loc_00005494:		
	s2 = *(s32*)(s4 + 8);
	s1 = s2 | 0x2;
	*(s32*)(s4 + 8) = s1;
	goto loc_0000501C;

loc_000054A4:		
	a2 = *(s32*)(a1 + 436);
	v1 = (u32)a2 < (u32)1280;
	if (v1 == 0)
	{
		*(s32*)(s3 + 4) = 0;
		goto loc_0000552C;
	}
	t1 = *(s8*)(a0 + 2);
	v0 = *(s8*)(a0 + 3);
	*(s8*)(sp + 2) = t1;
	*(s8*)(sp + 3) = v0;
	t0 = 0xFEFF;
	a3 = *(u16*)(sp + 2);
	if (a3 == t0)
	{
		v1 = *(s32*)(a1 + 8);
		goto loc_000054E4;
	}
	t5 = *(s32*)(a1 + 8);
	v0 = t5 | 0x2;

loc_000054DC:		
	*(s32*)(a1 + 8) = v0;
	goto loc_00005088;

loc_000054E4:		
	t1 = v1 & 0x1;
	t2 = v1;
	if (t1 == 0)
		goto loc_000054F8;
	NONE;
	*(s32*)(a1 + 8) = t2;

loc_000054F8:		
	asm("lwl        $t0, 9($a0)");
	asm("lwr        $t0, 6($a0)");
	asm("swl        $t0, 363($a1)");
	asm("swr        $t0, 360($a1)");
	*(s32*)(s3 + 4) = 0;
	v0 = *(s32*)(a1 + 360);
	t3 = *(s32*)(a1 + 340);
	a0 = (u32)t3 < (u32)v0;
	s2 = fp + 1244;
	if (a0 == 0)
		goto loc_0000508C;
	t4 = *(s32*)(a1 + 8);
	v0 = t4 | 0x3;
	goto loc_000054DC;

loc_0000552C:		
	t6 = *(s32*)(a1 + 8);
	NONE;
	v0 = t6 | 0x1;
	goto loc_000054DC;

loc_0000553C:		
	a0 = *(s32*)(sp + 8);
	v0 = sub_00004C00(...);
	v0 = s1;
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

loc_00005578:		
	a1 = 0x8400;
	a2 = 1;
	a3 = sp + 4;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_0000553C;
	t2 = *(s32*)(sp + 4);
	t1 = t2 & 0x400;
	if (t1 == 0)
	{
		t6 = *(u8*)(s0 + 4);
		goto loc_00004FCC;
	}
	goto loc_0000553C;
}

sub_000055AC(int idx, int *param) // at 0x000055AC 
{
	a2 = 0x00000;
	a3 = *(s8*)(0x00000 + 1244);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 8) = s2;
	v0 = a2 + 1244;
	s2 = a1;
	*(s32*)(sp + 4) = s1;
	a2 = 0x80243908;
	s1 = a0;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 0) = s0;
	if (a3 == 0)
		goto loc_00005648;
	a0 = *(s8*)(v0 + 2);
	a1 = 0x80240000;
	a2 = 0x80243902;
	if (a0 == 0)
		goto loc_00005648;
	v0 = sceUsbAccGetAuthStat(...);
	a3 = 0x80240000;
	a2 = 0x80243902;
	if ((s32)v0 < 0)
		goto loc_00005648;
	t0 = 0x8001;
	t1 = 0x10000;
	if (s1 == t0)
	{
		a0 = s2;
		v0 = sub_00006DA4(...);
		a2 = v0;
		goto loc_00005648;
	}
	a1 = s1;
	a0 = t1 - 28916;
	s0 = 0;
	NONE;

loc_00005620:		
	t2 = *(s32*)(a0 + 0);
	if (a1 == t2)
	{
		if ((s32)s1 < 0)
		{
			a1 = *(s32*)(a0 + 8);
		}
		else
		{
			a1 = *(s32*)(a0 + 4);
		}
		v0 = 0x8024390D;
		v1 = (u32)s0 < (u32)22;
		if (a1 != 0)
		{
			a0 = s2;
			v0 = $a1(...);
			v1 = (u32)s0 < (u32)22;
		}

		a2 = v0;
		if (v1 != 0)
			goto loc_00005648;
		t4 = 0x80240000;
	}
	else
	{
		s0 = s0 + 1;
		v0 = (u32)s0 < (u32)22;
		a0 = a0 + 12;
		if (v0 != 0)
			goto loc_00005620;
		t4 = 0x80240000;
	}
	v0 = 0x8024390D;
	a2 = v0;

loc_00005648:
	return (a2);
}

sceUsbCamIoctl(...) // at 0x000056B0 
{
	sp = sp - 16;
	v0 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	v1 = v0 | 0x3907;
	s0 = k1;
	*(s32*)(sp + 4) = ra;
	k1 = k1 << 11;
	if (a1 == 0)
		goto loc_00005740;
	a3 = 0x40000000;
	a2 = a3 | 0x2;
	v1 = (u32)a2 < (u32)a0;
	t0 = 0x80000000;
	if (v1 != 0)
		goto loc_000057BC;
	t2 = 0x40000000;
	t1 = t2 | 0x1;
	t0 = (u32)a0 < (u32)t1;
	if (t0 == 0)
	{
		v0 = 8;
		goto loc_00005728;
	}
	t3 = (u32)a0 < (u32)13;
	t7 = 17;
	if (t3 == 0)
		goto loc_0000578C;
	t4 = (u32)a0 < (u32)11;
	if (t4 == 0)
	{
		v0 = 8;
		goto loc_00005728;
	}
	t5 = 9;
	t6 = (u32)a0 < (u32)10;
	if (a0 == t5)
		goto loc_00005774;
	v0 = a0 - 1;
	if (t6 != 0)
		goto loc_00005768;

loc_00005724:		
	v0 = 12;

loc_00005728:		
	t0 = a1 + v0;

loc_0000572C:		
	v1 = t0 | a1;
	a2 = v1 & k1;
	a3 = 0x80240000;
	v1 = a3 | 0x3904;
	if ((s32)a2 >= 0)
		goto loc_00005758;

loc_00005740:		
	k1 = s0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);

loc_00005758:		
	v0 = sub_000055AC(...);
	v1 = v0;
	goto loc_00005740;

loc_00005768:		
	t8 = (u32)v0 < (u32)7;
	if (t8 == 0)
	{
		v0 = 0x80240000;
		goto loc_0000577C;
	}

loc_00005774:		
	v0 = 4;
	goto loc_00005728;

loc_0000577C:		
	v1 = v0 | 0x390D;
	goto loc_00005740;

loc_00005784:		
	v0 = 8;
	goto loc_00005728;

loc_0000578C:		
	t8 = (u32)a0 < (u32)17;
	if (a0 == t7)
		goto loc_00005784;
	v0 = 4;
	if (t8 != 0)
		goto loc_00005728;
	t9 = (u32)a0 < (u32)21;
	t0 = a1 + v0;
	if (t9 != 0)
		goto loc_0000572C;
	v1 = 0x8001;
	if (a0 != v1)
	{
		v0 = 0x80240000;
		goto loc_0000577C;
	}
	v0 = 144;
	goto loc_00005728;

loc_000057BC:		
	a3 = t0 | 0x10;
	a2 = (u32)a3 < (u32)a0;
	if (a2 != 0)
	{
		a2 = 0x80000000;
		goto loc_00005808;
	}
	t3 = 0x80000000;
	t2 = t3 | 0xD;
	t1 = (u32)a0 < (u32)t2;
	v0 = 4;
	if (t1 == 0)
		goto loc_00005728;
	t4 = 0x80000000;
	v0 = t4 | 0xA;
	t5 = (u32)v0 < (u32)a0;
	if (a0 == v0)
		goto loc_00005724;
	if (t5 != 0)
	{
		v0 = 8;
		goto loc_00005728;
	}
	t7 = 0x7FFF0000;
	t6 = t7 | 0xFFFF;
	v0 = a0 + t6;
	goto loc_00005768;

loc_00005808:		
	v1 = a2 | 0x14;
	t9 = (u32)v1 < (u32)a0;
	t4 = 0xC0000000;
	if (t9 != 0)
		goto loc_00005834;
	t1 = 0x80000000;
	t0 = t1 | 0x12;
	a3 = (u32)a0 < (u32)t0;
	if (a3 == 0)
	{
		v0 = 4;
		goto loc_00005728;
	}
	v0 = 8;
	goto loc_00005728;

loc_00005834:		
	t3 = t4 | 0x1;
	t2 = (u32)a0 < (u32)t3;
	v0 = 0x80240000;
	if (t2 != 0)
		goto loc_0000577C;
	t7 = 0xC0000000;
	t6 = t7 | 0x2;
	t5 = (u32)t6 < (u32)a0;
	v0 = 8;
	if (t5 == 0)
		goto loc_00005728;
	t9 = 0xC0000000;
	t8 = t9 | 0x3;
	if (a0 != t8)
	{
		v0 = 0x80240000;
		goto loc_0000577C;
	}
	v0 = 4;
	goto loc_00005728;
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a1 = *(s32*)(a0 + 0);
	a2 = (s32)a1 < (s32)10;
	v1 = v0 | 0x3905;
	if (a2 == 0)
		goto loc_000058FC;
	v1 = *(s32*)(a0 + 4);
	t1 = 0x80240000;
	a0 = a1;
	t0 = (s32)v1 < (s32)10;
	a1 = v1;
	a3 = sp + 1;
	a2 = sp;
	v1 = t1 | 0x3905;
	if (t0 == 0)
		goto loc_000058FC;
	v0 = sub_00002B7C(...);
	a1 = 0x00000;
	s1 = a1 + 1244;
	a2 = 0;
	a1 = 1;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_000058FC;
	a0 = *(s32*)(s1 + 408);
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 160;
	a1 = 2;
	a2 = sp;
	a3 = 2;
	if (v0 == 0)
		goto loc_00005914;
	v1 = s0;

loc_000058FC:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00005914:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_000058FC;
	a3 = *(u8*)(sp + 1);
	a2 = *(u8*)(sp + 0);
	*(s8*)(s1 + 13) = a3;
	*(s8*)(s1 + 12) = a2;
	goto loc_000058FC;
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	v0 = 0x80240000;
	s0 = a0;
	*(s32*)(sp + 20) = ra;
	v1 = v0 | 0x3906;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)256;
	a0 = a2;
	if (a1 == 0)
		goto loc_000059A8;
	v0 = sub_00001084(...);
	a1 = 2;
	a2 = sp;
	a3 = 1;
	a0 = 164;
	*(s8*)(sp + 0) = v0;
	v0 = sub_00000000(...);
	a1 = v0;
	if (v0 != 0)
		goto loc_000059A4;
	a3 = *(u8*)(s0 + 0);
	a0 = 0x00000;
	*(s8*)(a0 + 1262) = a3;

loc_000059A4:		
	v1 = a1;

loc_000059A8:		
	ra = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1262);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	v0 = 0x80240000;
	s2 = a0;
	*(s32*)(sp + 28) = ra;
	v1 = v0 | 0x3906;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)256;
	a0 = a2;
	if (a1 == 0)
		goto loc_00005A40;
	v0 = sub_00001058(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 165;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00005A5C;

loc_00005A3C:		
	v1 = s0;

loc_00005A40:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00005A5C:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_00005A40;
	v1 = *(u8*)(s2 + 0);
	*(s8*)(s1 + 19) = v1;
	goto loc_00005A3C;
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1263);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	v0 = 0x00000;
	a3 = 0x80240000;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	s2 = v0 + 1244;
	*(s32*)(sp + 28) = ra;
	a1 = 1;
	a2 = 0;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(a0 + 0);
	a0 = (u32)v1 < (u32)256;
	v1 = a3 | 0x3906;
	if (a0 == 0)
		goto loc_00005B04;
	t0 = *(u8*)(s1 + 0);
	a0 = *(s32*)(s2 + 408);
	*(s8*)(sp + 0) = t0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 166;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00005B20;
	v1 = s0;

loc_00005B04:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00005B20:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s2 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_00005B04;
	a0 = *(u8*)(s1 + 0);
	*(s8*)(s2 + 20) = a0;
	goto loc_00005B04;
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1264);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = s2;
	v0 = 0x80240000;
	s2 = a0;
	*(s32*)(sp + 28) = ra;
	v1 = v0 | 0x3906;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)256;
	a0 = a2;
	if (a1 == 0)
		goto loc_00005BD0;
	v0 = sub_000010B8(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 167;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00005BEC;

loc_00005BCC:		
	v1 = s0;

loc_00005BD0:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00005BEC:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_00005BD0;
	v1 = *(u8*)(s2 + 0);
	*(s8*)(s1 + 21) = v1;
	goto loc_00005BCC;
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1265);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	v0 = 0x80240000;
	*(s32*)(sp + 28) = ra;
	a2 = v0 | 0x3905;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	a0 = *(s32*)(a0 + 0);
	v1 = a0 - 10;
	a1 = (u32)v1 < (u32)71;
	if (a0 == 0)
		goto loc_00005CC0;
	a0 = 0x00000;
	s1 = a0 + 1256;
	a0 = s1;
	if (a1 == 0)
		goto loc_00005CFC;
	v0 = sub_00001110(...);
	a0 = s1 + 1;
	s2 = v0;
	v0 = sub_0000115C(...);
	a2 = *(s32*)(s0 + 0);
	a1 = v0;
	a0 = s2;
	v0 = sub_000011F4(...);
	a1 = 0x80240000;
	a2 = a1 | 0x3905;
	if (v0 == 0)
		goto loc_00005CFC;
	t1 = *(u8*)(s1 + 2);
	a2 = s2 - 7;
	t0 = 0x80240000;
	a3 = (u32)t1 < (u32)5;
	v1 = (u32)a2 < (u32)3;
	a2 = t0 | 0x3905;
	if (a3 != 0)
		goto loc_00005CC0;
	ra = *(s32*)(sp + 28);
	if (v1 != 0)
		goto loc_00005D00;

loc_00005CC0:		
	t3 = 0x00000;
	s1 = t3 + 1244;
	t2 = *(u8*)(s0 + 0);
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = t2;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 5;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00005D18;
	a2 = s0;

loc_00005CFC:		
	ra = *(s32*)(sp + 28);

loc_00005D00:		
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a2;
	sp = sp + 32;
	return (v0);

loc_00005D18:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	a2 = s0;
	if (s0 != 0)
		goto loc_00005CFC;
	t4 = *(u8*)(sp + 0);
	*(s8*)(s1 + 32) = t4;
	goto loc_00005CFC;
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1276);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	v1 = *(u16*)(a0 + 0);
	a0 = sp;
	*(s16*)(sp + 0) = v1;
	v0 = sub_000000F4(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	v0 = sub_00000170(...);
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(a0 + 0);
	v0 = sub_00002930(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 172;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00005DFC;
	v0 = s0;

loc_00005DE8:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00005DFC:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v0 = s0;
	if (s0 != 0)
		goto loc_00005DE8;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 30) = v1;
	goto loc_00005DE8;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1274;
	v0 = sub_00002944(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	a2 = sp + 1;
	a1 = sp;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 24) = ra;
	a0 = *(s32*)(a0 + 0);
	v0 = sub_00002B40(...);
	v1 = 0x00000;
	s0 = v0;
	s1 = v1 + 1244;
	a1 = 1;
	a2 = 0;
	if ((s32)v0 < 0)
		goto loc_00005EB4;
	a0 = *(s32*)(s1 + 408);
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 160;
	a1 = 2;
	a2 = sp;
	a3 = 2;
	if (v0 == 0)
		goto loc_00005ECC;

loc_00005EB4:		
	v0 = s0;

loc_00005EB8:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00005ECC:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v0 = s0;
	if (s0 != 0)
		goto loc_00005EB8;
	v1 = *(u8*)(sp + 1);
	v0 = *(u8*)(sp + 0);
	*(s8*)(s1 + 13) = v1;
	*(s8*)(s1 + 12) = v0;
	goto loc_00005EB4;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = v0 + 1256;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 8) = ra;
	a0 = s0;
	v0 = sub_00001110(...);
	*(s32*)(s1 + 0) = v0;
	v0 = s0 + 1;
	a0 = v0;
	v0 = sub_0000115C(...);
	*(s32*)(s1 + 4) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 28) = ra;
	a1 = 1;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	v1 = *(s32*)(a0 + 0);
	if (v1 == a1)
	{
		*(s8*)(sp + 0) = v1;
		goto loc_00005F78;
	}
	*(s8*)(sp + 0) = 0;

loc_00005F78:		
	s2 = 0x00000;
	v0 = *(u16*)(a0 + 4);
	s1 = s2 + 1244;
	a0 = *(s32*)(s1 + 408);
	a3 = *(s32*)(sp + 0);
	a1 = 1;
	NONE;
	a2 = 0;
	*(s32*)(sp + 0) = a3;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 168;
	a1 = 2;
	a2 = sp;
	a3 = 3;
	if (v0 == 0)
		goto loc_00005FD4;

loc_00005FB8:		
	v0 = s0;

loc_00005FBC:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_00005FD4:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v0 = s0;
	if (s0 != 0)
		goto loc_00005FBC;
	v1 = *(u8*)(sp + 0);
	if (v1 != 0)
	{
		a0 = 1;
		goto loc_00006018;
	}
	*(s8*)(s1 + 23) = 0;

loc_00006004:		
	t0 = *(s32*)(sp + 0);
	a1 = s2 + 1244;
	a2 = (u32)t0 >> 8;
	*(s16*)(a1 + 24) = a2;
	goto loc_00005FB8;

loc_00006018:		
	*(s8*)(s1 + 23) = a0;
	goto loc_00006004;
	v1 = 0x00000;
	a1 = v1 + 1244;
	v1 = *(u8*)(a1 + 23);
	a2 = 1;
	if (v1 == a2)
	{
		*(s32*)(a0 + 0) = v1;
		goto loc_0000604C;
	}
	a2 = *(u16*)(a1 + 24);
	*(s32*)(a0 + 0) = 0;
	*(s16*)(a0 + 4) = a2;

loc_00006044:		
	v0 = 0;
	return (v0);

loc_0000604C:		
	*(s16*)(a0 + 4) = 0;
	goto loc_00006044;
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)8;
	a0 = a2;
	if (a1 == 0)
		goto loc_000060BC;
	v0 = sub_00002988(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 161;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_000060D4;

loc_000060B8:		
	v1 = s0;

loc_000060BC:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_000060D4:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_000060BC;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 14) = v1;
	goto loc_000060B8;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1258;
	v0 = sub_0000299C(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)4;
	a0 = a2;
	if (a1 == 0)
		goto loc_0000619C;
	v0 = sub_000029E0(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 162;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_000061B4;

loc_00006198:		
	v1 = s0;

loc_0000619C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_000061B4:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_0000619C;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 16) = v1;
	goto loc_00006198;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1260;
	v0 = sub_000029F4(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)4;
	a0 = a2;
	if (a1 == 0)
		goto loc_0000627C;
	v0 = sub_00002A38(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 163;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00006294;

loc_00006278:		
	v1 = s0;

loc_0000627C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00006294:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_0000627C;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 17) = v1;
	goto loc_00006278;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1261;
	v0 = sub_00002A4C(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)3;
	a0 = a2;
	if (a1 == 0)
		goto loc_0000635C;
	v0 = sub_00002A90(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 169;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00006374;

loc_00006358:		
	v1 = s0;

loc_0000635C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00006374:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_0000635C;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 22) = v1;
	goto loc_00006358;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1266;
	v0 = sub_00002AA4(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	a2 = 0x8013;
	*(s32*)(sp + 28) = ra;
	v1 = 0x10000;
	a3 = v1 | 0x26;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	a0 = *(s32*)(a0 + 0);
	t0 = a0 + a2;
	a1 = (u32)a3 < (u32)t0;
	t3 = 0xFFFF0000;
	if (a1 != 0)
		goto loc_0000642C;
	a1 = *(s32*)(s0 + 4);
	t2 = t3 | 0x7FED;
	t1 = (s32)a1 < (s32)t2;
	if (t1 != 0)
	{
		a0 = 0x80240000;
		goto loc_00006430;
	}
	t4 = (s32)a2 < (s32)a1;
	if (t4 == 0)
		goto loc_0000644C;

loc_0000642C:		
	a0 = 0x80240000;

loc_00006430:		
	v0 = a0 | 0x3907;

loc_00006434:		
	ra = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_0000644C:		
	t6 = a0 | 0x8000;
	if ((s32)a0 < 0)
		goto loc_000064E8;
	t7 = *(u16*)(s0 + 0);
	*(s16*)(sp + 0) = t7;

loc_0000645C:		
	t8 = a1 | 0x8000;
	if ((s32)a1 < 0)
		goto loc_000064D4;
	a1 = *(u16*)(s0 + 4);
	*(s16*)(sp + 2) = a1;

loc_0000646C:		
	t9 = 0x00000;
	s2 = t9 + 1244;
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	a2 = 0;
	v0 = sceKernelLockMutex(...);
	s1 = v0;
	if (v0 == 0)
		goto loc_00006494;

loc_0000648C:		
	v0 = s1;
	goto loc_00006434;

loc_00006494:		
	a0 = 170;
	a1 = 2;
	a2 = sp;
	a3 = 4;
	v0 = sub_00000000(...);
	a0 = *(s32*)(s2 + 408);
	s1 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	if (s1 != 0)
	{
		v0 = s1;
		goto loc_00006434;
	}
	t0 = *(u16*)(s0 + 4);
	a3 = *(u16*)(s0 + 0);
	*(s16*)(s2 + 28) = t0;
	*(s16*)(s2 + 26) = a3;
	goto loc_0000648C;

loc_000064D4:		
	s1 = t8 + 1;
	asm("negu       $s2, $a1");
	*(s16*)(sp + 2) = s2;
	*(s32*)(s0 + 4) = s1;
	goto loc_0000646C;

loc_000064E8:		
	a2 = t6 + 1;
	asm("negu       $t5, $a0");
	*(s16*)(sp + 0) = t5;
	*(s32*)(s0 + 0) = a2;
	goto loc_0000645C;
	a2 = 0x00000;
	a3 = a2 + 1244;
	t0 = *(u16*)(a3 + 26);
	a1 = t0 & 0x7FFF;
	v1 = a1 - 1;
	a3 = (s16)t0;
	asm("negu       $v0, $v1");
	a1 = t0 & 0xFFFF;
	if ((s32)a3 < 0)
		goto loc_00006558;
	*(s32*)(a0 + 0) = a1;

loc_00006524:		
	t4 = a2 + 1244;
	t1 = *(u16*)(t4 + 28);
	t3 = t1 & 0x7FFF;
	t2 = t3 - 1;
	a2 = (s16)t1;
	a1 = t1 & 0xFFFF;
	cond = ((s32)a2 < 0);
	asm("negu       $v0, $t2");
	if (cond)
		goto loc_00006550;
	*(s32*)(a0 + 4) = a1;

loc_00006548:		
	v0 = 0;
	return (v0);

loc_00006550:		
	*(s32*)(a0 + 4) = v0;
	goto loc_00006548;

loc_00006558:		
	*(s32*)(a0 + 0) = v0;
	goto loc_00006524;
	sp = sp - 32;
	*(s32*)(sp + 20) = s1;
	v1 = 0x00000;
	s1 = v1 + 1244;
	*(s32*)(sp + 16) = s0;
	a1 = 1;
	*(s32*)(sp + 24) = ra;
	a2 = *(s32*)(a0 + 0);
	a0 = *(s32*)(s1 + 408);
	v0 = (u32)0 < (u32)a2;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 173;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_000065C4;
	v0 = s0;

loc_000065B0:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);

loc_000065C4:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v0 = s0;
	if (s0 != 0)
		goto loc_000065B0;
	a0 = *(u8*)(sp + 0);
	*(s8*)(s1 + 31) = a0;
	goto loc_000065B0;
	v1 = 0x00000;
	a1 = *(u8*)(v1 + 1275);
	v0 = 0;
	*(s32*)(a0 + 0) = a1;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)3;
	a0 = a2;
	if (a1 == 0)
		goto loc_0000666C;
	v0 = sub_00002AE8(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 174;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00006684;

loc_00006668:		
	v1 = s0;

loc_0000666C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00006684:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_0000666C;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 15) = v1;
	goto loc_00006668;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1259;
	v0 = sub_00002AFC(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	v1 = v0 | 0x3905;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	a2 = *(s32*)(a0 + 0);
	a1 = (u32)a2 < (u32)17;
	a0 = a2;
	if (a1 == 0)
		goto loc_0000674C;
	v0 = sub_00002C08(...);
	a0 = 0x00000;
	s1 = a0 + 1244;
	a0 = *(s32*)(s1 + 408);
	a1 = 1;
	a2 = 0;
	*(s8*)(sp + 0) = v0;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 175;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	if (v0 == 0)
		goto loc_00006764;

loc_00006748:		
	v1 = s0;

loc_0000674C:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00006764:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_0000674C;
	v1 = *(u8*)(sp + 0);
	*(s8*)(s1 + 43) = v1;
	goto loc_00006748;
	sp = sp - 16;
	v0 = 0x00000;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	a0 = v0 + 1287;
	v0 = sub_000011A8(...);
	*(s32*)(s0 + 0) = v0;
	v0 = 0;
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	a1 = 3;
	a2 = sp;
	v1 = *(u16*)(a0 + 0);
	t0 = *(u8*)(a0 + 4);
	a3 = 3;
	a0 = 68;
	*(s16*)(sp + 0) = v1;
	*(s8*)(sp + 2) = t0;
	v0 = sub_00000000(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 24) = s2;
	s2 = s3 + 1244;
	a2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(s2 + 408);
	v0 = sceKernelLockMutex(...);
	a2 = 0x7FFD0000;
	a0 = a2 | 0xFE57;
	v1 = v0 + a0;
	a0 = (u32)v1 < (u32)2;
	a1 = 0x80240000;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_000068D8;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_000068D8;
	a3 = *(u16*)(s1 + 0);
	a0 = *(s32*)(s2 + 400);
	v0 = 0xFFFE0000;
	a1 = v0 | 0xFFFF;
	*(s16*)(sp + 0) = a3;
	v0 = sceKernelClearEventFlag(...);
	a0 = 67;
	a1 = 3;
	a2 = sp;
	a3 = 2;
	v0 = sub_00000000(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000068C4;
	a0 = *(s32*)(s2 + 400);
	t0 = 0x10000;
	a1 = t0 | 0x400;
	a2 = 1;
	a3 = sp + 4;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00006928;
	t4 = *(s32*)(sp + 4);
	t3 = t4 & 0x400;
	if (t3 == 0)
	{
		t6 = *(s32*)(s2 + 424);
		goto loc_000068F8;
	}
	t5 = 0x80240000;
	s0 = t5 | 0x3902;

loc_000068C4:		
	s2 = s3 + 1244;

loc_000068C8:		
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;

loc_000068D8:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_000068F8:		
	if (t6 == 0)
	{
		t7 = *(s32*)(s2 + 108);
		goto loc_0000690C;
	}
	s1 = 0x80240000;
	s0 = s1 | 0x3913;
	goto loc_000068C4;

loc_0000690C:		
	*(s32*)(s1 + 4) = 0;
	a0 = s1 + 4;
	a1 = t7 + 4;
	a2 = *(u8*)(t7 + 3);
	v0 = memcpy(...);
	s2 = s3 + 1244;
	goto loc_000068C8;

loc_00006928:		
	a3 = *(s32*)(sp + 4);
	t2 = 0x10000;
	t1 = 0x10000;
	a0 = t2 - 29356;
	a1 = t1 - 29304;
	a2 = 793;
	v0 = Kprintf(...);
	s2 = s3 + 1244;
	goto loc_000068C8;
	sp = sp - 32;
	*(s32*)(sp + 16) = ra;
	a1 = 2;
	a2 = sp;
	t0 = *(u8*)(a0 + 4);
	v1 = *(u8*)(a0 + 0);
	a3 = 2;
	a0 = 65;
	*(s8*)(sp + 0) = v1;
	*(s8*)(sp + 1) = t0;
	v0 = sub_00000000(...);
	ra = *(s32*)(sp + 16);
	sp = sp + 32;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 24) = s2;
	s2 = s3 + 1244;
	a2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 16) = s0;
	a0 = *(s32*)(s2 + 408);
	v0 = sceKernelLockMutex(...);
	a2 = 0x7FFD0000;
	a0 = a2 | 0xFE57;
	v1 = v0 + a0;
	a0 = (u32)v1 < (u32)2;
	a1 = 0x80240000;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_00006A60;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00006A60;
	a3 = *(u8*)(s1 + 0);
	a0 = *(s32*)(s2 + 400);
	v0 = 0xFFFE0000;
	a1 = v0 | 0xFFFF;
	*(s8*)(sp + 0) = a3;
	v0 = sceKernelClearEventFlag(...);
	a0 = 64;
	a1 = 2;
	a2 = sp;
	a3 = 1;
	v0 = sub_00000000(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00006A4C;
	a0 = *(s32*)(s2 + 400);
	t0 = 0x10000;
	a1 = t0 | 0x400;
	a2 = 1;
	a3 = sp + 4;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00006AB0;
	t4 = *(s32*)(sp + 4);
	t3 = t4 & 0x400;
	if (t3 == 0)
	{
		t6 = *(s32*)(s2 + 424);
		goto loc_00006A80;
	}
	t5 = 0x80240000;
	s0 = t5 | 0x3902;

loc_00006A4C:		
	s2 = s3 + 1244;

loc_00006A50:		
	a0 = *(s32*)(s2 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;

loc_00006A60:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00006A80:		
	if (t6 == 0)
	{
		t7 = *(s32*)(s2 + 108);
		goto loc_00006A94;
	}
	s1 = 0x80240000;
	s0 = s1 | 0x3913;
	goto loc_00006A4C;

loc_00006A94:		
	*(s32*)(s1 + 4) = 0;
	a0 = s1 + 4;
	a1 = t7 + 4;
	a2 = *(u8*)(t7 + 3);
	v0 = memcpy(...);
	s2 = s3 + 1244;
	goto loc_00006A50;

loc_00006AB0:		
	a3 = *(s32*)(sp + 4);
	t2 = 0x10000;
	t1 = 0x10000;
	a0 = t2 - 29356;
	a1 = t1 - 29304;
	a2 = 866;
	v0 = Kprintf(...);
	s2 = s3 + 1244;
	goto loc_00006A50;
	sp = sp - 48;
	*(s32*)(sp + 28) = s3;
	s3 = 0x00000;
	a2 = 0;
	*(s32*)(sp + 20) = s1;
	s1 = s3 + 1244;
	*(s32*)(sp + 24) = s2;
	s2 = a0;
	a0 = *(s32*)(s1 + 408);
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	a1 = 1;
	v0 = sceKernelLockMutex(...);
	a2 = 0x7FFD0000;
	a0 = a2 | 0xFE57;
	v1 = v0 + a0;
	a0 = (u32)v1 < (u32)2;
	a1 = 0x80240000;
	s0 = v0;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_00006BC0;
	v0 = 0xFFFE0000;
	a1 = v0 | 0xFFFF;
	v1 = s0;
	if ((s32)s0 < 0)
		goto loc_00006BC0;
	a0 = *(s32*)(s1 + 400);
	v0 = sceKernelClearEventFlag(...);
	a1 = 3;
	a2 = 0;
	a3 = 0;
	a0 = 9;
	v0 = sub_00000000(...);
	t1 = 0x10000;
	s0 = v0;
	a3 = sp;
	t0 = 0;
	a1 = t1 | 0x400;
	a2 = 1;
	if ((s32)v0 < 0)
		goto loc_00006BAC;
	a0 = *(s32*)(s1 + 400);
	v0 = sceKernelWaitEventFlag(...);
	t0 = 0x10000;
	a3 = 0x10000;
	s0 = v0;
	a0 = t0 - 29356;
	a1 = a3 - 29304;
	a2 = 917;
	if ((s32)v0 < 0)
		goto loc_00006BFC;
	t3 = *(s32*)(sp + 0);
	t2 = t3 & 0x400;
	if (t2 == 0)
	{
		t6 = *(s32*)(s1 + 108);
		goto loc_00006BE0;
	}
	t4 = 0x80240000;
	s0 = t4 | 0x3902;

loc_00006BAC:		
	t7 = s3 + 1244;

loc_00006BB0:		
	a0 = *(s32*)(t7 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;

loc_00006BC0:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00006BE0:		
	asm("lwl        $v1, 7($t6)");
	asm("lwr        $v1, 4($t6)");
	asm("swl        $v1, 3($s2)");
	asm("swr        $v1, 0($s2)");
	t5 = *(u16*)(s2 + 0);
	*(s32*)(s2 + 0) = t5;
	goto loc_00006BAC;

loc_00006BFC:		
	a3 = *(s32*)(sp + 0);
	v0 = Kprintf(...);
	t7 = s3 + 1244;
	goto loc_00006BB0;
	sp = sp - 32;
	*(s32*)(sp + 24) = ra;
	v0 = 0x80240000;
	a3 = 0xFFFF;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	t0 = *(s32*)(a0 + 0);
	a1 = (u32)t0 < (u32)3;
	v1 = v0 | 0x3905;
	if (a1 == 0)
		goto loc_00006CD8;
	a2 = *(s32*)(a0 + 4);
	t1 = 0x80240000;
	a1 = (u32)a3 < (u32)a2;
	v1 = t1 | 0x3907;
	if (a1 != 0)
		goto loc_00006CD8;
	v1 = *(s32*)(a0 + 8);
	t4 = 0x10000;
	t5 = 0x00000;
	t2 = (u32)a3 < (u32)v1;
	t3 = t4 - 29156;
	a3 = 0x80240000;
	s1 = t5 + 1244;
	t0 = t0 + t3;
	a1 = 1;
	a2 = 0;
	v1 = a3 | 0x3907;
	if (t2 != 0)
		goto loc_00006CD8;
	t9 = *(u8*)(t0 + 0);
	v0 = *(u16*)(a0 + 8);
	t8 = *(u16*)(a0 + 4);
	*(s8*)(sp + 0) = t9;
	s0 = v0 << 24;
	t2 = (u32)v0 >> 8;
	t1 = *(s32*)(sp + 4);
	t7 = *(s32*)(sp + 0);
	a0 = *(s32*)(s1 + 408);
	NONE;
	NONE;
	NONE;
	t0 = t7 | s0;
	t6 = t1 | t2;
	*(s32*)(sp + 0) = t0;
	*(s32*)(sp + 4) = t6;
	v0 = sceKernelLockMutex(...);
	s0 = v0;
	a0 = 6;
	a1 = 2;
	a2 = sp;
	a3 = 5;
	if (v0 == 0)
		goto loc_00006CF0;

loc_00006CD4:		
	v1 = s0;

loc_00006CD8:		
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00006CF0:		
	v0 = sub_00000000(...);
	a0 = *(s32*)(s1 + 408);
	s0 = v0;
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s0;
	if (s0 != 0)
		goto loc_00006CD8;
	t3 = *(s32*)(sp + 0);
	v1 = *(u8*)(sp + 4);
	a2 = *(u8*)(sp + 0);
	t4 = (u32)t3 >> 24;
	a0 = v1 << 8;
	a3 = a0 | t4;
	a1 = (u32)t3 >> 8;
	*(s16*)(s1 + 36) = a3;
	*(s8*)(s1 + 33) = a2;
	*(s16*)(s1 + 34) = a1;
	goto loc_00006CD4;
	v1 = 0x00000;
	t0 = v1 + 1244;
	a2 = *(u8*)(t0 + 33);
	v1 = 0x10000;
	a3 = v1 - 29156;
	a1 = 0;
	t2 = a1 + a3;

loc_00006D58:		
	t1 = *(u8*)(t2 + 0);
	v0 = 0x80240000;
	if (a2 == t1)
		goto loc_00006D78;
	a1 = a1 + 1;
	t3 = (u32)a1 < (u32)3;
	t2 = a1 + a3;
	if (t3 != 0)
		goto loc_00006D58;
	v0 = 0x80240000;

loc_00006D78:		
	a3 = 3;
	a2 = v0 | 0x3905;
	if (a1 == a3)
		goto loc_00006D9C;
	t5 = *(u16*)(t0 + 36);
	t4 = *(u16*)(t0 + 34);
	*(s32*)(a0 + 0) = a1;
	a2 = 0;
	*(s32*)(a0 + 8) = t5;
	*(s32*)(a0 + 4) = t4;

loc_00006D9C:		
	v0 = a2;
	return (v0);
}

sub_00006DA4(...) // at 0x00006DA4 
{
	sp = sp - 48;
	*(s32*)(sp + 32) = s4;
	s4 = 0x00000;
	a1 = 1;
	*(s32*)(sp + 24) = s2;
	s2 = s4 + 1244;
	a2 = 0;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 36) = ra;
	*(s32*)(sp + 28) = s3;
	*(s32*)(sp + 20) = s1;
	a0 = *(s32*)(s2 + 408);
	v0 = sceKernelLockMutex(...);
	a2 = 0x7FFD0000;
	a0 = a2 | 0xFE57;
	v1 = v0 + a0;
	a0 = (u32)v1 < (u32)2;
	a1 = 0x80240000;
	v1 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_00006E50;
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00006E50;
	a0 = *(s32*)(s2 + 400);
	v0 = 0xFFFE0000;
	a1 = v0 | 0xFFFF;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s0 + 4);
	a1 = *(s32*)(s0 + 8);
	a3 = *(s32*)(s0 + 12);
	s3 = s0 + 16;
	a2 = s3;
	v0 = sub_00000000(...);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00006E3C;
	a3 = *(s32*)(s0 + 0);
	if (a3 != 0)
	{
		a0 = *(s32*)(s2 + 400);
		goto loc_00006E74;
	}

loc_00006E3C:		
	a1 = s4 + 1244;

loc_00006E40:		
	a0 = *(s32*)(a1 + 408);
	a1 = 1;
	v0 = sceKernelUnlockMutex(...);
	v1 = s1;

loc_00006E50:		
	ra = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 48;
	return (v0);

loc_00006E74:		
	t0 = 0x10000;
	a1 = t0 | 0x400;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s1 = v0;
	if ((s32)v0 < 0)
		goto loc_00006F54;
	t4 = *(s32*)(sp + 0);
	t3 = t4 & 0x400;
	if (t3 == 0)
	{
		t7 = *(s32*)(s2 + 108);
		goto loc_00006EB0;
	}
	t5 = 0x80240000;
	s1 = t5 | 0x3902;
	goto loc_00006E3C;

loc_00006EB0:		
	a2 = s3;
	a3 = t7 + 4;
	s0 = a3 | s3;
	t6 = s0 & 0x3;
	t0 = t7 + 68;
	if (t6 == 0)
		goto loc_00006F20;
	v0 = t0;

loc_00006ECC:		
	asm("lwl        $v1, 3($a3)");
	asm("lwr        $v1, 0($a3)");
	asm("lwl        $a0, 7($a3)");
	asm("lwr        $a0, 4($a3)");
	asm("lwl        $a1, 11($a3)");
	asm("lwr        $a1, 8($a3)");
	asm("lwl        $t0, 15($a3)");
	asm("lwr        $t0, 12($a3)");
	asm("swl        $v1, 3($a2)");
	asm("swr        $v1, 0($a2)");
	asm("swl        $a0, 7($a2)");
	asm("swr        $a0, 4($a2)");
	asm("swl        $a1, 11($a2)");
	asm("swr        $a1, 8($a2)");
	asm("swl        $t0, 15($a2)");
	asm("swr        $t0, 12($a2)");
	a3 = a3 + 16;
	a2 = a2 + 16;
	if (a3 != v0)
		goto loc_00006ECC;
	a1 = s4 + 1244;
	goto loc_00006E40;

loc_00006F20:		
	t9 = *(s32*)(a3 + 0);
	t8 = *(s32*)(a3 + 4);
	s3 = *(s32*)(a3 + 8);
	s2 = *(s32*)(a3 + 12);
	*(s32*)(a2 + 0) = t9;
	a3 = a3 + 16;
	a2 = a2 + 16;
	*(s32*)(a2 - 12) = t8;
	*(s32*)(a2 - 8) = s3;
	*(s32*)(a2 - 4) = s2;
	if (a3 != t0)
		goto loc_00006F20;
	a1 = s4 + 1244;
	goto loc_00006E40;

loc_00006F54:		
	a3 = *(s32*)(sp + 0);
	t2 = 0x10000;
	t1 = 0x10000;
	a0 = t2 - 29356;
	a1 = t1 - 29304;
	a2 = 1030;
	v0 = Kprintf(...);
	a1 = s4 + 1244;
	goto loc_00006E40;
}

sceUsbCamSetupMicEx(...) // at 0x00006F78 
{
	a3 = 0x00000;
	t0 = *(s8*)(a3 + 944);
	sp = sp - 48;
	v1 = 0x80240000;
	*(s32*)(sp + 24) = s2;
	v0 = a3 + 944;
	s2 = a1;
	*(s32*)(sp + 20) = s1;
	a3 = v1 | 0x3908;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	if (t0 == 0)
		goto loc_00007040;
	a0 = *(s8*)(v0 + 2);
	a1 = 0x80240000;
	a3 = a1 | 0x3902;
	if (a0 == 0)
		goto loc_00007040;
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a3 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00007040;
	v0 = 0x80240000;
	t0 = (u32)s1 < (u32)264;
	a3 = v0 | 0x390A;
	if (t0 != 0)
		goto loc_00007040;
	t1 = 0x80240000;
	a3 = t1 | 0x3904;
	if (s0 == 0)
		goto loc_00007040;
	t4 = s0 + 36;
	t5 = k1 << 11;
	t3 = t4 | s0;
	t2 = t3 & t5;
	s3 = k1;
	v1 = a3;
	k1 = t5;
	if ((s32)t2 < 0)
		goto loc_00007038;
	t9 = s2 + s1;
	if (s2 == 0)
		goto loc_00007030;
	t8 = t9 | s2;
	t7 = t8 | s1;
	t6 = t5 & t7;
	if ((s32)t6 >= 0)
	{
		a0 = *(s32*)(s0 + 28);
		goto loc_00007060;
	}

loc_00007030:		
	s0 = 0x80240000;
	v1 = s0 | 0x3904;

loc_00007038:		
	k1 = s3;
	a3 = v1;

loc_00007040:		
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a3;
	sp = sp + 48;
	return (v0);

loc_00007060:		
	v0 = a0 ^ 0xBB80;
	t0 = a0 ^ 0xAC44;
	a1 = (u32)0 < (u32)v0;
	a2 = (u32)0 < (u32)t0;
	a3 = a1 & a2;
	if (a3 == 0)
	{
		t0 = 0x10620000;
		goto loc_00007098;
	}
	v1 = 22050;
	t2 = 0x80240000;
	if (a0 == v1)
		goto loc_00007094;
	t1 = 11025;
	a3 = t2 | 0x390B;
	if (a0 != t1)
		goto loc_00007040;

loc_00007094:		
	t0 = 0x10620000;

loc_00007098:		
	a1 = t0 | 0x4DD3;
	asm("mult       $a0, $a1");
	t9 = *(u16*)(s0 + 4);
	t8 = *(u16*)(s0 + 8);
	t3 = *(u16*)(s0 + 12);
	t4 = *(u16*)(s0 + 16);
	asm("mfhi       $a2");
	t5 = *(u16*)(s0 + 20);
	t7 = *(u16*)(s0 + 24);
	a1 = *(s32*)(s0 + 32);
	a3 = (s32)a0 >> 31;
	s0 = (s32)a2 >> 6;
	t6 = s0 - a3;
	a2 = s2;
	a3 = s1;
	a0 = sp;
	*(s16*)(sp + 0) = t9;
	*(s16*)(sp + 2) = t8;
	*(s16*)(sp + 4) = t3;
	*(s16*)(sp + 6) = t4;
	*(s16*)(sp + 8) = t5;
	*(s16*)(sp + 10) = t7;
	*(s16*)(sp + 12) = t6;
	v0 = sub_000078A0(...);
	v1 = v0;
	goto loc_00007038;
}

sceUsbCamSetupMic(...) // at 0x00007100 
{
	a3 = 0x00000;
	t0 = *(s8*)(a3 + 944);
	sp = sp - 48;
	v1 = 0x80240000;
	*(s32*)(sp + 28) = s3;
	v0 = a3 + 944;
	s3 = k1;
	*(s32*)(sp + 24) = s2;
	k1 = k1 << 11;
	s2 = a1;
	*(s32*)(sp + 20) = s1;
	a3 = v1 | 0x3908;
	s1 = a2;
	*(s32*)(sp + 16) = s0;
	s0 = a0;
	*(s32*)(sp + 32) = ra;
	if (t0 == 0)
		goto loc_00007154;
	a0 = *(s8*)(v0 + 2);
	a1 = 0x80240000;
	a3 = a1 | 0x3902;
	if (a0 != 0)
		goto loc_00007178;

loc_00007154:		
	k1 = s3;
	ra = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a3;
	sp = sp + 48;
	return (v0);

loc_00007178:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a3 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00007154;
	v0 = 0x80240000;
	t0 = (u32)s1 < (u32)264;
	a3 = v0 | 0x390A;
	if (t0 != 0)
		goto loc_00007154;
	t1 = 0x80240000;
	a3 = t1 | 0x3904;
	if (s0 == 0)
		goto loc_00007154;
	t5 = s0 + 20;
	t4 = t5 | s0;
	t3 = 0x80240000;
	t2 = t4 & k1;
	a3 = t3 | 0x3904;
	if ((s32)t2 < 0)
		goto loc_00007154;
	t9 = s2 + s1;
	if (s2 == 0)
		goto loc_000071DC;
	t8 = t9 | s2;
	t7 = t8 | s1;
	t6 = k1 & t7;
	if ((s32)t6 >= 0)
	{
		a0 = *(s32*)(s0 + 16);
		goto loc_000071E8;
	}

loc_000071DC:		
	s0 = 0x80240000;
	a3 = s0 | 0x3904;
	goto loc_00007154;

loc_000071E8:		
	v0 = a0 ^ 0xAC44;
	t0 = a0 ^ 0x5622;
	a1 = (u32)0 < (u32)v0;
	a2 = (u32)0 < (u32)t0;
	a3 = a1 & a2;
	t1 = 0x80240000;
	if (a3 == 0)
		goto loc_00007210;
	v1 = 11025;
	a3 = t1 | 0x390B;
	if (a0 != v1)
		goto loc_00007154;

loc_00007210:		
	t9 = 0x10620000;
	t8 = t9 | 0x4DD3;
	asm("mult       $a0, $t8");
	t4 = *(u16*)(s0 + 12);
	t5 = *(u16*)(s0 + 4);
	t2 = *(u16*)(s0 + 8);
	t6 = (s32)a0 >> 31;
	asm("mfhi       $t7");
	a0 = (s32)t7 >> 6;
	t3 = a0 - t6;
	a3 = s1;
	a2 = s2;
	a0 = sp;
	a1 = 0;
	s2 = 3;
	s1 = 2;
	*(s16*)(sp + 0) = t5;
	*(s16*)(sp + 2) = t2;
	*(s16*)(sp + 4) = t4;
	*(s16*)(sp + 12) = t3;
	*(s16*)(sp + 8) = s2;
	*(s16*)(sp + 10) = s1;
	*(s16*)(sp + 6) = 0;
	v0 = sub_000078A0(...);
	a3 = v0;
	goto loc_00007154;
}

sceUsbCamStopMic(...) // at 0x00007278 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 944);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 0) = s0;
	s0 = a0 + 944;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 4) = ra;
	if (a1 == 0)
		goto loc_000072E4;
	a1 = *(s8*)(s0 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 == 0)
		goto loc_000072E4;
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_000072E4;
	a3 = *(s8*)(s0 + 1);
	t0 = 0x80240000;
	s0 = k1;
	a0 = t0 | 0x3901;
	if (a3 == 0)
		goto loc_000072E4;
	k1 = k1 << 11;
	v0 = sub_000079A0(...);
	a0 = v0;
	k1 = s0;

loc_000072E4:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);
}

sceUsbCamReadMic(...) // at 0x000072F8 
{
	sp = sp - 48;
	*(s32*)(sp + 36) = s5;
	v0 = 0x80240000;
	s5 = a0;
	*(s32*)(sp + 32) = s4;
	s4 = a1;
	*(s32*)(sp + 28) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	s1 = 0x00000;
	s2 = s1 + 944;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 44) = ra;
	*(s32*)(sp + 40) = s6;
	v1 = *(s8*)(s1 + 944);
	s0 = v0 | 0x3908;
	if (v1 == 0)
		goto loc_00007384;
	v1 = *(s8*)(s2 + 5);
	a2 = 1;
	a3 = sp;
	t0 = 0;
	a1 = 1280;
	if (v1 == 0)
		goto loc_000073BC;
	a0 = *(s32*)(s2 + 276);
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007384;
	a2 = *(s32*)(sp + 0);
	a3 = 0x80240000;
	a1 = -1025;
	a0 = a2 & 0x100;
	s0 = a3 | 0x3902;
	if (a0 == 0)
		goto loc_000073B4;

loc_00007384:		
	v0 = s0;

loc_00007388:		
	k1 = s3;
	ra = *(s32*)(sp + 44);
	s6 = *(s32*)(sp + 40);
	s5 = *(s32*)(sp + 36);
	s4 = *(s32*)(sp + 32);
	s3 = *(s32*)(sp + 28);
	s2 = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	sp = sp + 48;
	return (v0);

loc_000073B4:		
	a0 = *(s32*)(s2 + 276);
	v0 = sceKernelClearEventFlag(...);

loc_000073BC:		
	s1 = s1 + 944;
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = s5;
	a1 = s4;
	s2 = v0;
	v0 = sub_00007AF8(...);
	s6 = 4;
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007418;
	t0 = *(s8*)(s1 + 4);
	t1 = 0x80240000;
	a1 = -3;
	s0 = t1 | 0x3909;
	if (t0 == s6)
		goto loc_00007418;
	a0 = *(s32*)(s1 + 276);
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s1 + 276);
	*(s32*)(s1 + 288) = s4;
	a1 = 4;
	*(s32*)(s1 + 292) = s5;
	*(s8*)(s1 + 4) = s6;
	v0 = sceKernelSetEventFlag(...);
	s0 = v0;

loc_00007418:		
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	goto loc_00007388;
}

sceUsbCamReadMicBlocking(...) // at 0x00007428 
{
	sp = sp - 64;
	*(s32*)(sp + 24) = s2;
	s2 = 0x00000;
	v0 = 0x80240000;
	v1 = *(s8*)(s2 + 944);
	*(s32*)(sp + 36) = s5;
	s5 = a0;
	*(s32*)(sp + 32) = s4;
	s4 = a1;
	*(s32*)(sp + 28) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 20) = s1;
	s1 = s2 + 944;
	*(s32*)(sp + 16) = s0;
	s0 = v0 | 0x3908;
	*(s32*)(sp + 48) = ra;
	*(s32*)(sp + 44) = s7;
	*(s32*)(sp + 40) = s6;
	if (v1 == 0)
		goto loc_000074B4;
	v1 = *(s8*)(s1 + 5);
	a1 = 1280;
	if (v1 == 0)
		goto loc_000074F4;
	a0 = *(s32*)(s1 + 276);
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000074B4;
	a1 = *(s32*)(sp + 0);
	a2 = 0x80240000;
	a0 = a1 & 0x100;
	s0 = a2 | 0x3902;
	if (a0 == 0)
		goto loc_000074E8;

loc_000074B4:		
	v0 = s0;
	k1 = s3;
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

loc_000074E8:		
	a0 = *(s32*)(s1 + 276);
	a1 = -1025;
	v0 = sceKernelClearEventFlag(...);

loc_000074F4:		
	v0 = sceKernelCpuSuspendIntr(...);
	a0 = s5;
	a1 = s4;
	s7 = v0;
	v0 = sub_00007AF8(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007554;
	s1 = s2 + 944;
	a3 = *(s8*)(s1 + 4);
	t0 = 0x80240000;
	s6 = 4;
	s0 = t0 | 0x3909;
	if (a3 == s6)
		goto loc_000074B4;
	a0 = *(s32*)(s1 + 276);
	a1 = -3;
	v0 = sceKernelClearEventFlag(...);
	a0 = *(s32*)(s1 + 276);
	*(s32*)(s1 + 288) = s4;
	a1 = 4;
	*(s32*)(s1 + 292) = s5;
	*(s8*)(s1 + 4) = s6;
	v0 = sceKernelSetEventFlag(...);
	s0 = v0;

loc_00007554:		
	a0 = s7;
	v0 = sceKernelCpuResumeIntr(...);
	s1 = s2 + 944;
	if ((s32)s0 < 0)
		goto loc_000074B4;
	a0 = *(s32*)(s1 + 276);
	a1 = 258;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000074B4;
	t2 = *(s32*)(sp + 0);
	t3 = 0x80240000;
	t1 = t2 & 0x100;
	s0 = t3 | 0x3902;
	if (t1 != 0)
		goto loc_000074B4;
	s0 = *(s32*)(s1 + 52);
	goto loc_000074B4;
}

sceUsbCamWaitReadMicEnd(...) // at 0x000075A0 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 944);
	sp = sp - 32;
	v1 = 0x80240000;
	*(s32*)(sp + 20) = s1;
	s1 = a0 + 944;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 16) = s0;
	s0 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 24) = ra;
	if (a1 == 0)
		goto loc_000075E0;
	a1 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 != 0)
		goto loc_000075FC;

loc_000075E0:		
	k1 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 32;
	return (v0);

loc_000075FC:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_000075E0;
	t1 = *(s8*)(s1 + 1);
	t2 = 0x80240000;
	a1 = 258;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	a0 = t2 | 0x3901;
	if (t1 == 0)
		goto loc_000075E0;
	a0 = *(s32*)(s1 + 276);
	v0 = sceKernelWaitEventFlag(...);
	a0 = v0;
	if ((s32)v0 < 0)
		goto loc_000075E0;
	t3 = *(s32*)(sp + 0);
	t0 = 0x80240000;
	a3 = t3 & 0x100;
	a0 = t0 | 0x3902;
	if (a3 != 0)
		goto loc_000075E0;
	a0 = *(s32*)(s1 + 52);
	goto loc_000075E0;
}

sceUsbCamPollReadMicEnd(...) // at 0x0000765C 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 944);
	sp = sp - 32;
	v1 = 0x80240000;
	*(s32*)(sp + 20) = s1;
	s1 = a0 + 944;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 16) = s0;
	s0 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 24) = ra;
	if (a1 == 0)
		goto loc_0000769C;
	a1 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 != 0)
		goto loc_000076B8;

loc_0000769C:		
	k1 = s0;
	ra = *(s32*)(sp + 24);
	s1 = *(s32*)(sp + 20);
	s0 = *(s32*)(sp + 16);
	v0 = a0;
	sp = sp + 32;
	return (v0);

loc_000076B8:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_0000769C;
	t0 = *(s8*)(s1 + 1);
	t1 = 0x80240000;
	a1 = 258;
	a2 = 1;
	a3 = sp;
	a0 = t1 | 0x3901;
	if (t0 == 0)
		goto loc_0000769C;
	a0 = *(s32*)(s1 + 276);
	v0 = sceKernelPollEventFlag(...);
	t2 = 0x80020000;
	a3 = t2 | 0x1AF;
	a0 = v0;
	if (v0 == a3)
		goto loc_00007720;
	t6 = *(s32*)(sp + 0);
	if ((s32)v0 < 0)
		goto loc_0000769C;
	t5 = 0x80240000;
	t4 = t6 & 0x100;
	a0 = t5 | 0x3902;
	if (t4 != 0)
		goto loc_0000769C;
	a0 = *(s32*)(s1 + 52);
	goto loc_0000769C;

loc_00007720:		
	t3 = 0x80240000;
	a0 = t3 | 0x390E;
	goto loc_0000769C;
}

sceUsbCamGetMicDataLength(...) // at 0x0000772C 
{
	a0 = 0x00000;
	a1 = *(s8*)(a0 + 944);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 4) = s1;
	s1 = a0 + 944;
	a0 = v1 | 0x3908;
	*(s32*)(sp + 0) = s0;
	s0 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 8) = ra;
	if (a1 == 0)
		goto loc_0000776C;
	a1 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	a0 = v0 | 0x3902;
	if (a1 != 0)
		goto loc_00007788;

loc_0000776C:		
	k1 = s0;
	ra = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a0;
	sp = sp + 16;
	return (v0);

loc_00007788:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	a0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_0000776C;
	a3 = *(s8*)(s1 + 1);
	t0 = 0x80240000;
	a0 = t0 | 0x3901;
	if (a3 == 0)
		goto loc_0000776C;
	a0 = *(s32*)(s1 + 52);
	goto loc_0000776C;
}

sceUsbCamSetMicGain(...) // at 0x000077B4 
{
	sp = sp - 32;
	*(s32*)(sp + 0) = s0;
	s0 = 0x00000;
	v1 = 1;
	*(s32*)(sp + 8) = s2;
	s2 = s0 + 944;
	a1 = -1025;
	*(s32*)(sp + 16) = s4;
	s4 = a0;
	a0 = *(s32*)(s2 + 276);
	*(s32*)(sp + 12) = s3;
	s3 = k1;
	k1 = k1 << 11;
	*(s32*)(sp + 4) = s1;
	*(s8*)(s2 + 5) = v1;
	*(s32*)(sp + 20) = ra;
	s1 = 0;
	v0 = sceKernelClearEventFlag(...);
	v1 = *(s8*)(s0 + 944);
	if (v1 != 0)
	{
		a0 = *(s8*)(s2 + 2);
		goto loc_00007838;
	}
	v0 = 0x80240000;
	s1 = v0 | 0x3908;

loc_00007810:		
	v0 = s1;

loc_00007814:		
	k1 = s3;
	ra = *(s32*)(sp + 20);
	s4 = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 32;
	return (v0);

loc_00007838:		
	a1 = 0x80240000;
	if (a0 != 0)
		goto loc_00007848;

loc_00007840:		
	s1 = a1 | 0x3902;
	goto loc_00007810;

loc_00007848:		
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x80240000;
	if ((s32)v0 < 0)
		goto loc_00007840;
	a2 = *(s8*)(s2 + 1);
	if (a2 != 0)
	{
		t0 = *(s16*)(s2 + 10);
		goto loc_00007870;
	}
	a3 = 0x80240000;
	s1 = a3 | 0x3901;
	goto loc_00007810;

loc_00007870:		
	a0 = (s16)s4;
	if (t0 == a0)
	{
		v0 = s1;
		goto loc_00007814;
	}
	*(s16*)(s2 + 10) = a0;
	v0 = sub_00007A3C(...);
	a1 = 1024;
	a0 = *(s32*)(s2 + 276);
	s1 = v0;
	*(s8*)(s2 + 5) = 0;
	v0 = sceKernelSetEventFlag(...);
	v0 = s1;
	goto loc_00007814;
}

sub_000078A0(...) // at 0x000078A0 
{
	sp = sp - 32;
	*(s32*)(sp + 12) = s3;
	s3 = a3;
	*(s32*)(sp + 8) = s2;
	s2 = a2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 16) = ra;
	s0 = a1;
	v0 = sceKernelCpuSuspendIntr(...);
	a2 = v0;
	v0 = 0x00000;
	t0 = v0 + 952;
	a1 = t0 - 8;
	v1 = 0x3E0F0000;
	a0 = (u32)0 < (u32)s0;
	t4 = t0;
	asm("lwl        $v0, 3($s1)");
	asm("lwr        $v0, 0($s1)");
	asm("lwl        $t0, 7($s1)");
	asm("lwr        $t0, 4($s1)");
	asm("lwl        $t1, 11($s1)");
	asm("lwr        $t1, 8($s1)");
	t2 = *(s16*)(s1 + 12);
	asm("swl        $v0, 3($t4)");
	asm("swr        $v0, 0($t4)");
	asm("swl        $t0, 7($t4)");
	asm("swr        $t0, 4($t4)");
	asm("swl        $t1, 11($t4)");
	asm("swr        $t1, 8($t4)");
	*(s16*)(t4 + 12) = t2;
	a3 = v1 | 0x83E1;
	*(s32*)(a1 + 28) = s3;
	*(s32*)(a1 + 24) = s2;
	*(s8*)(a1 + 6) = a0;
	if (a0 == 0)
		goto loc_00007988;
	asm("multu      $s3, $a3");
	*(s32*)(a1 + 48) = s2;
	*(s32*)(a1 + 36) = 0;
	asm("mfhi       $t1");
	a3 = (u32)t1 >> 5;
	*(s32*)(a1 + 40) = 0;
	*(s32*)(a1 + 44) = 0;
	*(s32*)(a1 + 32) = a3;

loc_00007954:		
	a0 = a2;
	v0 = sceKernelCpuResumeIntr(...);
	ra = *(s32*)(sp + 16);
	s3 = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	a2 = 1;
	a1 = 0x00000;
	v0 = 0;
	*(s8*)(a1 + 945) = a2;
	sp = sp + 32;
	return (v0);

loc_00007988:		
	*(s32*)(a1 + 48) = s2;
	*(s32*)(a1 + 32) = s3;
	*(s32*)(a1 + 36) = 0;
	*(s32*)(a1 + 40) = s2;
	*(s32*)(a1 + 44) = s2;
	goto loc_00007954;
}

sub_000079A0(...) // at 0x000079A0 
{
	sp = sp - 16;
	*(s32*)(sp + 12) = ra;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 8) = s2;
	v0 = sceKernelCpuSuspendIntr(...);
	s1 = v0;
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x00000;
	v1 = 0x80240000;
	a0 = a1 + 1000;
	s0 = v1 | 0x3902;
	if (v0 != 0)
		goto loc_000079E8;
	v1 = *(s32*)(a0 + 24);
	v0 = 0x80240000;
	s2 = a0 - 56;
	s0 = v0 | 0x3006;
	if ((s32)v1 <= 0)
		goto loc_00007A0C;

loc_000079E8:		
	a0 = s1;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00007A0C:		
	a3 = *(s32*)(s2 + 96);
	t0 = 2;
	*(s8*)(a3 + 2) = t0;
	a2 = *(s32*)(s2 + 96);
	*(s8*)(a2 + 3) = 0;
	v0 = sceUsbAcc_internal_2A100C1F(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_000079E8;
	a0 = 2;
	*(s8*)(s2 + 4) = a0;
	s0 = 0;
	goto loc_000079E8;
}

sub_00007A3C(...) // at 0x00007A3C 
{
	sp = sp - 32;
	*(s32*)(sp + 16) = s0;
	s0 = 0x00000;
	a0 = s0 + 944;
	*(s32*)(sp + 20) = ra;
	t1 = 4;
	a1 = 258;
	v0 = *(s8*)(a0 + 4);
	a2 = 1;
	a3 = sp;
	t0 = 0;
	if (v0 == t1)
		goto loc_00007ACC;

loc_00007A6C:		
	v0 = sub_000079A0(...);
	a2 = s0 + 944;
	a0 = *(s32*)(a2 + 276);
	a1 = 288;
	a2 = 1;
	a3 = sp;
	t0 = 0;
	v0 = sceKernelWaitEventFlag(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00007AB8;
	t1 = *(s32*)(sp + 0);
	t0 = 0x80240000;
	a3 = t1 & 0x100;
	v1 = t0 | 0x3902;
	if (a3 != 0)
		goto loc_00007AB8;
	v0 = sub_00007F0C(...);
	v1 = v0;

loc_00007AB8:		
	ra = *(s32*)(sp + 20);

loc_00007ABC:		
	s0 = *(s32*)(sp + 16);
	v0 = v1;
	sp = sp + 32;
	return (v0);

loc_00007ACC:		
	a0 = *(s32*)(a0 + 276);
	v0 = sceKernelWaitEventFlag(...);
	v1 = v0;
	if ((s32)v0 < 0)
		goto loc_00007AB8;
	v1 = *(s32*)(sp + 0);
	a1 = 0x80240000;
	a0 = v1 & 0x100;
	v1 = a1 | 0x3902;
	if (a0 == 0)
		goto loc_00007A6C;
	ra = *(s32*)(sp + 20);
	goto loc_00007ABC;
}

sub_00007AF8(...) // at 0x00007AF8 
{
	a2 = 0x00000;
	a3 = *(s8*)(a2 + 944);
	sp = sp - 16;
	v1 = 0x80240000;
	*(s32*)(sp + 8) = s2;
	s2 = a2 + 944;
	a2 = v1 | 0x3908;
	*(s32*)(sp + 4) = s1;
	s1 = a1;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 12) = ra;
	if (a3 == 0)
		goto loc_00007BD8;
	a0 = *(s8*)(s2 + 2);
	v0 = 0x80240000;
	a2 = v0 | 0x3902;
	if (a0 == 0)
		goto loc_00007BD8;
	v0 = sceUsbAccGetAuthStat(...);
	a1 = 0x80240000;
	a2 = a1 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00007BD8;
	a3 = *(s8*)(s2 + 1);
	t0 = 0x80240000;
	a2 = t0 | 0x3901;
	if (a3 == 0)
		goto loc_00007BD8;
	t4 = *(s8*)(s2 + 4);
	t6 = 0x80240000;
	t5 = t4 ^ 0x2;
	t3 = (u32)t5 < (u32)1;
	t2 = (u32)t4 < (u32)1;
	t1 = t2 | t3;
	a2 = t6 | 0x3912;
	if (t1 != 0)
		goto loc_00007BD8;
	t7 = 0x80240000;
	a2 = t7 | 0x3907;
	if (s0 == 0)
		goto loc_00007BD8;
	a2 = s0 + s1;
	v1 = a2 | s0;
	t9 = v1 | s1;
	t8 = 0x80240000;
	s0 = k1 & t9;
	a2 = t8 | 0x3904;
	if ((s32)s0 < 0)
		goto loc_00007BD8;
	a0 = *(s8*)(s2 + 6);
	v0 = (u32)s1 < (u32)132;
	if (a0 != 0)
		goto loc_00007BC8;
	v0 = 0x80240000;
	s2 = (u32)s1 < (u32)2;
	a2 = v0 | 0x3903;
	if (s2 != 0)
		goto loc_00007BD8;
	v0 = s1 & 0x1;

loc_00007BC8:		
	s1 = 0x80240000;
	a2 = s1 | 0x3903;
	if (v0 != 0)
		goto loc_00007BD8;
	a2 = 0;

loc_00007BD8:		
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	v0 = a2;
	sp = sp + 16;
	return (v0);
}

sceUsbCamStartMic(...) // at 0x00007BF4 
{
	a0 = 0x00000 + 944;
	s0 = k1;
	k1 = k1 << 11;
	if (*(s8*)(a0 + 6); == 0)
	{
		a1 = *(s32*)(a0 + 48);
		*(s32*)(a0 + 36) = 0;
		*(s32*)(a0 + 40) = a1;
		*(s32*)(a0 + 44) = a1;
	}
	else
	{
		*(s32*)(a0 + 44) = 0;
		*(s32*)(a0 + 36) = 0;
		*(s32*)(a0 + 40) = 0;
	}

	v0 = sub_00007F0C();
	k1 = s0;
	return (v0);
}

sub_00007C54(...) // at 0x00007C54 
{
	v0 = 0x00000;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = v0 + 876;
	v0 = sceUsbbdRegister(...);
	v1 = 1;
	if ((s32)v0 < 0)
		goto loc_00007C7C;
	v1 = 0x00000;
	*(s8*)(v1 + 944) = 0;
	v1 = 0;

loc_00007C7C:		
	ra = *(s32*)(sp + 0);
	v0 = v1;
	sp = sp + 16;
	return (v0);
}

sub_00007C8C(...) // at 0x00007C8C 
{
	v0 = 0x00000;
	sp = sp - 16;
	*(s32*)(sp + 0) = ra;
	a0 = v0 + 876;
	v0 = sceUsbbdUnregister(...);
	v0 = (s32)v0 < (s32)0;
	ra = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);
	sp = sp - 48;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s7;
	*(s32*)(sp + 24) = s6;
	*(s32*)(sp + 20) = s5;
	*(s32*)(sp + 16) = s4;
	*(s32*)(sp + 12) = s3;
	*(s32*)(sp + 4) = s1;
	*(s32*)(sp + 0) = s0;
	v1 = *(s32*)(a0 + 24);
	s2 = a0;
	if ((s32)v1 < 0)
		goto loc_00007DDC;
	s7 = 0x00000;
	s1 = s7 + 944;
	a3 = *(s8*)(s1 + 4);
	s5 = *(s32*)(a0 + 4);
	s3 = *(s32*)(a0 + 20);
	v1 = a3 ^ 0x2;
	a1 = (u32)v1 < (u32)1;
	a2 = (u32)a3 < (u32)1;
	a0 = a1 | a2;
	if (a0 != 0)
	{
		ra = *(s32*)(sp + 32);
		goto loc_00007DE0;
	}
	t0 = *(s32*)(s1 + 24);
	if (t0 == 0)
	{
		a1 = *(s8*)(s1 + 4);
		goto loc_00007DC0;
	}
	t1 = *(s8*)(s1 + 6);
	s4 = s1 + 32;
	if (t1 != 0)
		goto loc_00007E70;
	t0 = *(s32*)(s1 + 32);
	a2 = *(s32*)(s4 + 16);
	a0 = *(s32*)(s4 + 12);
	s0 = s3;
	NONE;
	NONE;
	v1 = a2 + t0;
	a2 = a0 + s0;
	a3 = (u32)v1 < (u32)a2;
	a1 = s5;
	if (a3 == 0)
		goto loc_00007E40;
	s6 = a2 - v1;
	s0 = s3 - s6;
	a2 = s0;
	v0 = sub_0000808C(...);
	a0 = *(s32*)(s4 + 16);
	v1 = s5 + s0;
	a1 = v1;
	a2 = s6;
	v0 = sub_0000808C(...);
	v0 = *(s32*)(s4 + 4);
	a0 = *(s32*)(s1 + 32);
	t2 = v0 + s3;
	t1 = (u32)a0 < (u32)t2;
	*(s32*)(s4 + 4) = t2;
	if (t1 == 0)
		goto loc_00007D94;
	*(s32*)(s4 + 4) = a0;

loc_00007D94:		
	t3 = *(s32*)(s4 + 16);
	NONE;
	v0 = t3 + s6;

loc_00007DA0:		
	s3 = *(s32*)(s4 + 0);
	v1 = *(s32*)(s4 + 4);
	*(s32*)(s4 + 12) = v0;
	if (s3 == v1)
		goto loc_00007E34;

loc_00007DB0:		
	s4 = s7 + 944;
	if (v1 != 0)
		goto loc_00007E20;
	s1 = s7 + 944;

loc_00007DBC:		
	a1 = *(s8*)(s1 + 4);

loc_00007DC0:		
	t9 = a1 ^ 0x1;
	a0 = a1 ^ 0x4;
	t8 = (u32)a0 < (u32)1;
	s0 = (u32)t9 < (u32)1;
	s7 = t8 | s0;
	if (s7 != 0)
	{
		v0 = sceKernelDcacheInvalidateRange(*(s32*)(s2 + 4), 256);
		v0 = sceUsbbdReqRecv(s2);
		ra = *(s32*)(sp + 32);
		goto loc_00007DE0;
	}

loc_00007DDC:		
	ra = *(s32*)(sp + 32);

loc_00007DE0:		
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

loc_00007E20:		
	a0 = *(s32*)(s4 + 276);
	a1 = 1;
	v0 = sceKernelSetEventFlag(...);
	s1 = s7 + 944;
	goto loc_00007DBC;

loc_00007E34:		
	s6 = *(s32*)(s4 + 12);

loc_00007E38:		
	*(s32*)(s4 + 8) = s6;
	goto loc_00007DB0;

loc_00007E40:		
	a2 = s3;
	v0 = sub_0000808C(...);
	t6 = *(s32*)(s4 + 4);
	a0 = *(s32*)(s1 + 32);
	t5 = t6 + s3;
	t4 = (u32)a0 < (u32)t5;
	*(s32*)(s4 + 4) = t5;
	if (t4 == 0)
		goto loc_00007E64;
	*(s32*)(s4 + 4) = a0;

loc_00007E64:		
	t7 = *(s32*)(s4 + 12);
	v0 = t7 + s0;
	goto loc_00007DA0;

loc_00007E70:		
	a1 = *(s32*)(s4 + 12);
	t8 = *(s32*)(s4 + 16);
	s6 = s3 - 2;
	a0 = a1 << 5;
	t9 = a0 + a1;
	s0 = t9 << 2;
	s3 = t8 + s0;
	v0 = *(s8*)(s5 + 0);
	v1 = *(s8*)(s5 + 1);
	*(s8*)(s3 + 0) = v0;
	*(s8*)(s3 + 1) = v1;
	a0 = s3 + 4;
	a2 = s6 & 0xFFFF;
	*(s16*)(s3 + 2) = s6;
	a1 = s5 + 2;
	v0 = memcpy(...);
	t7 = *(u16*)(s3 + 2);
	t6 = 128;
	a1 = 0;
	t5 = s3 + t7;
	t4 = t5 + 4;
	a0 = t4;
	a2 = t6 - t7;
	v0 = memset(...);
	t3 = *(s32*)(s4 + 12);
	a0 = *(s32*)(s1 + 32);
	v0 = t3 + 1;
	t2 = (u32)v0 < (u32)a0;
	*(s32*)(s4 + 12) = v0;
	if (t2 != 0)
		goto loc_00007EEC;
	*(s32*)(s4 + 12) = 0;

loc_00007EEC:		
	v1 = *(s32*)(s4 + 4);
	s1 = (u32)v1 < (u32)a0;
	if (s1 == 0)
	{
		s6 = *(s32*)(s4 + 12);
		goto loc_00007E38;
	}
	s5 = v1 + 1;
	v1 = s5;
	*(s32*)(s4 + 4) = s5;
	goto loc_00007DB0;
}

sub_00007F0C(...) // at 0x00007F0C 
{
	sp = sp - 48;
	*(s32*)(sp + 24) = s2;
	*(s32*)(sp + 20) = s1;
	*(s32*)(sp + 16) = s0;
	*(s32*)(sp + 32) = ra;
	*(s32*)(sp + 28) = s3;
	v0 = sceKernelCpuSuspendIntr(...);
	a1 = 0x00000;
	a0 = *(s8*)(a1 + 944);
	v1 = 0x80240000;
	s2 = v0;
	s1 = a1 + 944;
	s0 = v1 | 0x3908;
	if (a0 == 0)
		goto loc_00007F54;
	a0 = *(s8*)(s1 + 2);
	v0 = 0x80240000;
	s0 = v0 | 0x3902;
	if (a0 != 0)
		goto loc_00007F7C;

loc_00007F54:
	sceKernelCpuResumeIntr(s2);
	return (s0);

loc_00007F7C:		
	v0 = sceUsbAccGetAuthStat(...);
	a2 = 0x80240000;
	s0 = a2 | 0x3902;
	if ((s32)v0 < 0)
		goto loc_00007F54;
	a3 = *(s8*)(s1 + 1);
	t0 = 0x80240000;
	s0 = t0 | 0x3901;
	if (a3 == 0)
		goto loc_00007F54;
	t1 = *(s32*)(s1 + 24);
	t2 = 0x80240000;
	s0 = t2 | 0x3911;
	if (t1 == 0)
		goto loc_00007F54;
	t3 = *(s8*)(s1 + 4);
	t4 = 0x80240000;
	s0 = t4 | 0x3909;
	if (t3 != 0)
		goto loc_00007F54;
	t0 = *(s8*)(s1 + 6);
	t4 = 1;
	t3 = s1 + 8;
	t2 = 14;
	if (t0 == 0)
		goto loc_00008020;
	t6 = *(u16*)(s1 + 20);
	v1 = *(u16*)(s1 + 8);
	t9 = *(u16*)(s1 + 10);
	t8 = *(u16*)(s1 + 12);
	s3 = *(u16*)(s1 + 14);
	s0 = *(u16*)(s1 + 16);
	t7 = *(u16*)(s1 + 18);
	t5 = (u32)0 < (u32)t0;
	*(s16*)(sp + 0) = v1;
	t4 = 3;
	t3 = sp;
	*(s16*)(sp + 2) = t9;
	t2 = 15;
	*(s16*)(sp + 4) = t8;
	*(s16*)(sp + 6) = s3;
	*(s16*)(sp + 8) = s0;
	*(s16*)(sp + 10) = t7;
	*(s16*)(sp + 12) = t6;
	*(s8*)(sp + 14) = t5;

loc_00008020:		
	a2 = 0x00000;
	s1 = a2 + 1000;
	a1 = *(s32*)(s1 + 24);
	a0 = 0x80240000;
	s0 = a0 | 0x3006;
	if ((s32)a1 > 0)
		goto loc_00007F54;
	s3 = s1 - 56;
	a3 = *(s32*)(s3 + 96);
	*(s8*)(a3 + 2) = t4;
	v0 = *(s32*)(s3 + 96);
	*(s8*)(v0 + 3) = t2;
	if (t3 == 0)
		goto loc_00008064;
	t0 = *(s32*)(s3 + 96);
	a1 = t3;
	a2 = t2;
	a0 = t0 + 4;
	v0 = memcpy(...);

loc_00008064:		
	a0 = s1;
	v0 = sceUsbAcc_internal_2A100C1F(...);
	s0 = v0;
	if ((s32)v0 < 0)
		goto loc_00007F54;
	t1 = 3;
	s1 = 1;
	*(s8*)(s3 + 4) = t1;
	s0 = 0;
	*(s8*)(s3 + 3) = s1;
	goto loc_00007F54;
}

sub_0000808C(...) // at 0x0000808C 
{
	v1 = 0x00000;
	a3 = *(s32*)(v1 + 1240);
	sp = sp - 16;
	*(s32*)(sp + 0) = s0;
	s0 = a0;
	*(s32*)(sp + 4) = ra;
	if (a3 == 0)
		goto loc_000080E8;
	a2 = (u32)a2 >> 2;
	a3 = 0;
	if (a2 == 0)
		goto loc_000080D4;

loc_000080B4:		
	t2 = *(s32*)(a1 + 0);
	a3 = a3 + 1;
	t0 = (u32)a3 < (u32)a2;
	asm("wsbh       $t1, $t2");
	*(s32*)(a0 + 0) = t1;
	a1 = a1 + 4;
	a0 = a0 + 4;
	if (t0 != 0)
		goto loc_000080B4;

loc_000080D4:		
	v0 = s0;

loc_000080D8:		
	ra = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_000080E8:		
	v0 = memcpy(...);
	v0 = s0;
	goto loc_000080D8;
}

sub_000080F8(...) // at 0x000080F8 
{
	sp = sp - 16;
	*(s32*)(sp + 8) = s2;
	*(s32*)(sp + 4) = s1;
	s1 = a0;
	*(s32*)(sp + 0) = s0;
	*(s32*)(sp + 12) = ra;
	s0 = a1;
	v0 = sceKernelCpuSuspendIntr(...);
	t5 = 0x00000;
	v1 = t5 + 944;
	a0 = *(s8*)(v1 + 6);
	s2 = v0;
	if (a0 == 0)
		goto loc_000082B4;
	a2 = 0x3E0F0000;
	a1 = a2 | 0x83E1;
	asm("multu      $s0, $a1");
	t3 = s1;
	t1 = v1 + 32;
	asm("mfhi       $a0");
	s1 = (u32)a0 >> 5;
	s0 = 0;
	if (s1 == 0)
		goto loc_00008240;
	v1 = *(s32*)(t1 + 4);
	a3 = (u32)v1 < (u32)s1;
	if (a3 != 0)
		s1 = v1;
	t2 = 0;
	if (s1 == 0)
		goto loc_0000822C;

loc_00008164:		
	s0 = *(s32*)(t1 + 8);
	t4 = *(s32*)(t1 + 16);
	a3 = t3;
	t7 = s0 << 5;
	t6 = t7 + s0;
	v1 = t6 << 2;
	a2 = v1 + t4;
	t0 = a2 | t3;
	v0 = t0 & 0x3;
	t0 = a2 + 128;
	if (v0 == 0)
		goto loc_00008278;
	v0 = t0;

loc_00008194:		
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
		goto loc_00008194;
	asm("lwl        $v0, 3($a2)");
	asm("lwr        $v0, 0($a2)");
	asm("swl        $v0, 3($a3)");
	asm("swr        $v0, 0($a3)");
	t4 = *(s32*)(t1 + 8);

loc_000081F4:		
	t0 = *(s32*)(t1 + 0);
	t3 = t3 + 132;
	a3 = t4 + 1;
	a2 = (u32)a3 < (u32)t0;
	*(s32*)(t1 + 8) = a3;
	if (a2 != 0)
		goto loc_00008210;
	*(s32*)(t1 + 8) = 0;

loc_00008210:		
	v1 = *(s32*)(t1 + 4);
	t2 = t2 + 1;
	t6 = (u32)t2 < (u32)s1;
	v0 = v1 - 1;
	*(s32*)(t1 + 4) = v0;
	if (t6 != 0)
		goto loc_00008164;
	v1 = v0;

loc_0000822C:		
	t1 = t5 + 944;
	if (v1 == 0)
		goto loc_00008264;
	t3 = s1 << 5;

loc_00008238:		
	t2 = t3 + s1;
	s0 = t2 << 2;

loc_00008240:		
	a0 = s2;
	v0 = sceKernelCpuResumeIntr(...);
	v0 = s0;
	ra = *(s32*)(sp + 12);
	s2 = *(s32*)(sp + 8);
	s1 = *(s32*)(sp + 4);
	s0 = *(s32*)(sp + 0);
	sp = sp + 16;
	return (v0);

loc_00008264:		
	a0 = *(s32*)(t1 + 276);
	a1 = -2;
	v0 = sceKernelClearEventFlag(...);
	t3 = s1 << 5;
	goto loc_00008238;

loc_00008278:		
	a1 = *(s32*)(a2 + 0);
	a0 = *(s32*)(a2 + 4);
	t9 = *(s32*)(a2 + 8);
	t8 = *(s32*)(a2 + 12);
	*(s32*)(a3 + 0) = a1;
	a2 = a2 + 16;
	a3 = a3 + 16;
	*(s32*)(a3 - 12) = a0;
	*(s32*)(a3 - 8) = t9;
	*(s32*)(a3 - 4) = t8;
	if (a2 != t0)
		goto loc_00008278;
	t0 = *(s32*)(a2 + 0);
	*(s32*)(a3 + 0) = t0;
	t4 = *(s32*)(t1 + 8);
	goto loc_000081F4;

loc_000082B4:		
	t4 = v1 + 32;
	t3 = *(s32*)(t4 + 4);
	a2 = s1;
	a1 = *(s32*)(t4 + 8);
	s1 = (u32)t3 < (u32)s0;
	if (s1 != 0)
		s0 = t3;
	t1 = (u32)s0 >> 1;
	t2 = 0;
	if (t1 == 0)
		goto loc_0000830C;
	t7 = *(s32*)(v1 + 32);
	t0 = *(s32*)(t4 + 16);
	NONE;
	a3 = t0 + t7;

loc_000082E8:		
	a0 = *(u16*)(a1 + 0);
	t2 = t2 + 1;
	a1 = a1 + 2;
	t9 = (u32)a1 < (u32)a3;
	t8 = (u32)t2 < (u32)t1;
	*(s16*)(a2 + 0) = a0;
	if (t9 == 0)
		a1 = t0;
	a2 = a2 + 2;
	if (t8 != 0)
		goto loc_000082E8;

loc_0000830C:		
	a2 = t3 - s0;
	*(s32*)(t4 + 8) = a1;
	*(s32*)(t4 + 4) = a2;
	if (a2 != 0)
		goto loc_00008240;
	a1 = t5 + 944;
	a0 = *(s32*)(a1 + 276);
	a1 = -2;
	v0 = sceKernelClearEventFlag(...);
	goto loc_00008240;
}
