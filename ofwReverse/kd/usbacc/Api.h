#pragma once

int sceUsbBus_driver_8A3EB5D2();
int sceUsbBus_driver_48CCE3C1();
int sceUsbBus_driver_FBA2072B();
int sceUsbBus_driver_90B82F55();
int sceUsbBus_driver_7B87815D();

int sceUsbbdRegister(struct UsbDriver *drv);
int sceUsbbdUnregister(struct UsbDriver *drv);
int sceUsbbdReqSend(struct UsbdDeviceReq *req);
int sceUsbbdReqRecv(struct UsbdDeviceReq *req);
