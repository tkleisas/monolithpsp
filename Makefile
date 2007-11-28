TARGET = psptetris
OBJS = tetrisgame.o tetrisdata.o callbacks.o vram.o controller.o

INCDIR =
CFLAGS = -G0 -Wall -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)
BUILD_PRX=1
LIBDIR =
LDFLAGS =
LIBS= -lpspgum -lpspgu -lm -lstdc++ -lpsprtc

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Tetris Game

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak


