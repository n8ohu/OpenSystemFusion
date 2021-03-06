# Makefile-include
#
# Build the ircDDB Gateway software on Linux with settings for Debian (i386)
# 2012-09-07 Hans-J. Barthen, DL5DI 
# Rename this file to settings.mk before you compile the source for the Debian platform
#
	export DATADIR := "/home/opendv/data"
	export LIBS    := $(shell wx-config --libs adv,core)
	export CC      := $(shell wx-config --cxx)
	export LDFLAGS := 
	export BINDIR  := "$(DESTDIR)/usr/bin"
#
# Comment out the first CFLAGS entry and uncomment the second to enable the DExtra Link. For DCS Link you must comment out the first
# CFLAGS entry and uncomment the thrird entrt. You must do a "make clean" before rebuilding the software.
#
	export CFLAGS := -O2 -m32 -Wall -Wno-non-virtual-dtor -Wno-strict-aliasing -DDATA_DIR='$(DATADIR)' -DBIN_DIR='$(BINDIR)' $(shell wx-config --cxxflags)
#	export CFLAGS := -O2 -m32 -Wall -Wno-non-virtual-dtor -Wno-strict-aliasing -DDATA_DIR='$(DATADIR)' -DBIN_DIR='$(BINDIR)' -DDEXTRA_LINK $(shell wx-config --cxxflags)
#	export CFLAGS := -O2 -m32 -Wall -Wno-non-virtual-dtor -Wno-strict-aliasing -DDATA_DIR='$(DATADIR)' -DBIN_DIR='$(BINDIR)' -DDCS_LINK $(shell wx-config --cxxflags)
