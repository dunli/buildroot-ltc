#-------------------------------------------------------------------------------
#-                                                                            --
#-       This software is confidential and proprietary and may be used        --
#-        only as expressly authorized by a licensing agreement from          --
#-                                                                            --
#-                            Hantro Products Oy.                             --
#-                                                                            --
#-                   (C) COPYRIGHT 2006 HANTRO PRODUCTS OY                    --
#-                            ALL RIGHTS RESERVED                             --
#-                                                                            --
#-                 The entire notice above must be reproduced                 --
#-                  on all copies and should not be removed.                  --
#-                                                                            --
#-------------------------------------------------------------------------------
#-
#--  Abstract : Makefile for x170 RV decoder control SW
#--
#-------------------------------------------------------------------------------
#--
#--  Version control information, please leave untouched.
#--
#--  $RCSfile: Makefile,v $
#--  $Date: 2010/12/01 12:36:13 $
#--  $Revision: 1.11 $
#--
#-------------------------------------------------------------------------------

# Comment/uncomment the following line to disable/enable debugging
DEBUG = y

# Add your debugging flags (or not) to CFLAGS. Do not change these!
ifeq ($(DEBUG),y)
  DEBFLAGS = -DDEBUG -D_ASSERT_USED
else
  DEBFLAGS = -O3 -DNDEBUG
endif

# Add your debugging flag (or not) to CFLAGS. Enable, if needed
#DEBFLAGS += -D_DWL_DEBUG # for wrapper layer trace
#DEBFLAGS += -D_DEBUG_PRINT -D_ERROR_PRINT # decoder trace
#DEBFLAGS += -DMEMORY_USAGE_TRACE #trace all memory allocations
#DEBFLAGS += -D_X170_DEMO_DEVEL # Enable demo development functionality

#Set up envirinment:

#Output mode can be:
# DEC_X170_OUTPUT_FORMAT_RASTER_SCAN
# DEC_X170_OUTPUT_FORMAT_TILED

#SETTING_FLAGS = -DDEC_X170_OUTPUT_FORMAT=DEC_X170_OUTPUT_FORMAT_TILED
SETTING_FLAGS = -DDEC_X170_OUTPUT_FORMAT=DEC_X170_OUTPUT_FORMAT_RASTER_SCAN

COMMON_SOURCE_DIR = ../../source

# Architecture flags for gcc
ARCH =
CROSS_COMPILER =

# C -compiler name, can be replaced by another compiler(replace gcc)
CC = $(CROSS_COMPILER)gcc

# show the path to compiler, where to find header files and libraries
INCLUDE = -I. -I$(COMMON_SOURCE_DIR)/inc -I$(COMMON_SOURCE_DIR)/dwl \
          -I$(COMMON_SOURCE_DIR)/rv -I$(COMMON_SOURCE_DIR)/config \
          -I$(COMMON_SOURCE_DIR)/common

# compiler switches
CFLAGS  =  -Wall -ansi $(ARCH) -D_GNU_SOURCE $(INCLUDE) $(SETTING_FLAGS) $(M32) 

# list of used sourcefiles
SRC_RV := \
	rvdecapi.c \
	rvdecapi_internal.c \
	rv_strm.c \
	rv_headers.c \
	rv_utils.c \
	rv_rpr.c \
	regdrv.c \
	tiledref.c \
	refbuffer.c \
	on2rvdecapi.c \
	workaround.c \
	bqueue.c

SRCS = $(SRC_RV)

#source search path
vpath %.c
vpath %.c $(COMMON_SOURCE_DIR)/rv $(COMMON_SOURCE_DIR)/common

vpath %.o
vpath %.o obj

# object files will be generated from .c sourcefiles
OBJS    = $(SRCS:.c=.o)

# name of the outputfile (library)
DECLIB = libdecx170rv.a

# MACRO for cleaning object -files
RM  = rm -f

# MACRO for creating library that includes all the object files
#AR  = ar rcv
AR  = $(CROSS_COMPILER)ar rcs


OBJDIR := obj

#Here are rules for building codes and generating object library.
all:
	@echo
	@echo ERROR! run one of:
	@echo "    $$ make integrator"
	@echo "    $$ make versatile"
	@echo "    $$ make pclinux"
	@echo "    $$ make pc_plain_lib"
	@echo "    $$ make ads"
	@echo "    $$ make pclinux_eval"	
	@echo

$(OBJDIR):
	mkdir $@

ads11: CC=armcc
ads11: AR=armar -rcv
ads11: DEBFLAGS =
ads11: CFLAGS = --cpu ARM1136J-S -O2 -Otime $(INCLUDE)
ads11: $(DECLIB)

ads9: CC=armcc
ads9: AR=armar -rcv
ads9: DEBFLAGS =
ads9: CFLAGS = --cpu ARM926EJ-S -O2 -Otime $(INCLUDE)
ads9: $(DECLIB)

coverage: DEBFLAGS += $(ASIC_TRACE_SUPPORT)
coverage: CFLAGS += -DRV_RAW_STREAM_SUPPORT
coverage: CC = covc --abs --retain gcc
coverage: $(DECLIB)

pclinux: DEBFLAGS += $(ASIC_TRACE_SUPPORT)
pclinux: INCLUDE += -I../../test/common/swhw/
pclinux: CFLAGS += -DRV_RAW_STREAM_SUPPORT
pclinux: $(DECLIB)

pclinux_eval: INCLUDE += -I../../test/common/swhw/
pclinux_eval: CFLAGS += -DRV_RAW_STREAM_SUPPORT
pclinux_eval: DEBFLAGS = -O3 -DNDEBUG
pclinux_eval: $(DECLIB)
pclinux_eval: CC=gcc

integrator: CROSS_COMPILER = arm-linux-
integrator: ARCH = -march=armv4 -mtune=arm9tdmi -fpic
integrator: $(DECLIB)

versatile: CROSS_COMPILER = arm-none-linux-gnueabi-
versatile: ARCH = -mtune=arm926ej-s -fpic
versatile: CFLAGS += -DRV_RAW_STREAM_SUPPORT
versatile: $(DECLIB)

versatile_plain_lib: CROSS_COMPILER = arm-linux-
versatile_plain_lib: ARCH = -mtune=arm926ejs -fpic
versatile_plain_lib: $(DECLIB)


$(DECLIB): depend $(OBJDIR) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $(DEBFLAGS) $(ENVSET) $< -o $(OBJDIR)/$@
	$(AR) $(DECLIB) $(OBJDIR)/$@


.PHONY: clean
clean:
	$(RM) $(DECLIB)
	$(RM) .depend
	$(RM) -r $(OBJDIR)

lint: $(SRC_RV)
        # -e537 removes warnings about multiple include
        # -e641 removes warnings about conevrting enum to int
	-lint-nt -w2 -e537 -e641 $(INCLUDE) $^ > pc-lint-report.txt


depend: $(SRCS)
	$(CC) $(CFLAGS) $(DEBFLAGS) -M  $^ > .depend

.PHONY: ads9 ads11 pclinux pclinux_eval integrator versatile clean lint tar

#ifeq (.depend, $(wildcard .depend))
#include .depend
#endif

ifeq (,$(findstring clean, $(MAKECMDGOALS)))
ifeq (.depend, $(wildcard .depend))
include .depend
endif
endif
