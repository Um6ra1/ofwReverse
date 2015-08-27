	.set noreorder

#include "pspstub.s"

	STUB_START	"sceUsbAcc",0x00090000,0x00050005
	
	STUB_FUNC	0x79A1C743,	sceUsbAccGetAuthStat
	STUB_FUNC	0x0CD7D4AA,	sceUsbAccGetInfo
	STUB_FUNC	0x2A100C1F,	sceUsbAcc_internal_2A100C1F
	STUB_FUNC	0x2E251404,		sceUsbAccRegisterType
	STUB_FUNC	0x18B04C82,	sceUsbAccUnregisterType
	STUB_END
