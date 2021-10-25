TARGET = Plants_vs_Zombies
OBJS = source/main.o 		\
source/image.o 				\
source/graphics.o 			\
source/vram.o 				\
source/audioController.o 	\
source/imageLoader.o 		\
source/load.o				\
source/menu.o 				\
source/gameStateChecker.o 	\
source/about.o 				\
source/more.o 				\
source/almanac.o 			\
source/settings.o			\
source/saveGame.o			\
source/level.o				\
source/plant.o				\
source/zombie.o


CFLAGS = -O2 -G0 -Wall -g -gdwarf-2
CXXFLAGS = $(CFLAGS) -std=c++14 -fno-rtti
ASFLAGS = $(CFLAGS)

# PSP stuff
BUILD_PRX = 1
#PSP_FW_VERSION = 500
#PSP_LARGE_MEMORY = 1

LIBDIR = ./ include lib $(PSPSDK)/../lib

LIBS += -lpng -lz -ljpeg -lpspgum_vfpu -lpspgu -lpspgum -lpspvfpu -lpspvram -lm	-losl -lpspaudiolib -lpspaudio -lpspaudiocodec -lpspmp3 -lstdc++

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Plants vs. Zombies 
PSP_EBOOT_ICON = ICON0.PNG

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak