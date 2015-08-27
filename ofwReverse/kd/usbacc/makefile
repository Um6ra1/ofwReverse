TARGET	= usbacc
PSP_FW_VERSION = 660
OBJS = usbacc.o Api.o exports.o

BUILD_PRX = 1

INCDIR =
LIBDIR =
LIBS = #-lpspusb
#PRX_EXPORTS=exports.exp

LDFLAGS = 
CFLAGS	= -Os -G0 -Wall -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti 
ASFLAGS = $(CFLAGS)

PSPSDK	= $(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build_prx.mak
