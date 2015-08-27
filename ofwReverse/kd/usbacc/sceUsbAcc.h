/*================================
 * ---- sceUsb1Seg.h
 *--------------------------------
 *
 *
 *
 * Copyright (c) 2012 NULL
 *================================*/

#ifndef __SCE_USB1SEG_H__
#define __SCE_USB1SEG_H__

#ifdef __cplusplus
extern "C"
{
#endif

	int sceUsbAccGetAuthStat();
	int sceUsbAccGetInfo(u64 *lpDst);
	int sceUsbAcc_internal_2A100C1F(struct UsbdDeviceReq *lpReq);
	int sceUsbAccRegisterType(int a0);
	int sceUsbAccUnregisterType(int a0);

#ifdef __cplusplus
}
#endif

#endif