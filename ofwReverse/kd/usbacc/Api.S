	.set noreorder

#include "pspstub.s"

	STUB_START	"sceUsbbd",0x00090000,0x00090005
	STUB_FUNC	0x8A3EB5D2,	sceUsbBus_driver_8A3EB5D2
	STUB_FUNC	0x48CCE3C1,	sceUsbBus_driver_48CCE3C1
	STUB_FUNC	0xFBA2072B,	sceUsbBus_driver_FBA2072B
	STUB_FUNC	0x90B82F55,	sceUsbBus_driver_90B82F55
	STUB_FUNC	0x7B87815D,	sceUsbBus_driver_7B87815D
	STUB_FUNC	0xB1644BE7,	sceUsbbdRegister
	STUB_FUNC	0xC1E2A540,	sceUsbbdUnregister
	STUB_FUNC	0x23E51D8F,	sceUsbbdReqSend
	STUB_FUNC	0x913EC15D,	sceUsbbdReqRecv
	STUB_END
