#
# Makefile for the Synopsys HDMI driver
#

obj-y	+= bitOperation.o
obj-y	+= error.o
obj-y	+= log.o

HDMI_LIB := drivers/infotm/common/display2/controller/synopsys_hdmi_tx_1.4a
EXTRA_CFLAGS += -I$(HDMI_LIB)/api
EXTRA_CFLAGS += -I$(HDMI_LIB)/bsp
EXTRA_CFLAGS += -I$(HDMI_LIB)/core
EXTRA_CFLAGS += -I$(HDMI_LIB)/edid
EXTRA_CFLAGS += -I$(HDMI_LIB)/hdcp
EXTRA_CFLAGS += -I$(HDMI_LIB)/phy
EXTRA_CFLAGS += -I$(HDMI_LIB)/util

