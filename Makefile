# Makefile
#
# Build the ircDDB Gateway software on Linux
#

include settings.mk

all:	SystemFusionReflector/SFRemote/sfremote SystemFusionReflector/SFReflector/sfreflector # DExtraBridge/DExtraBridge

# DExtraBridge/DExtraBridge:	DVCommon/Common.a
#				make -C DExtraBridge

SystemFusionReflector/SFRemote/sfremote:	Common/Common.a
		make -C SystemFusionReflector/SFRemote

SystemFusionReflector/SFReflector/sfreflector:	ircDDB/libircDDB.a Common/Common.a
		make -C SystemFusionReflector/SFReflector

DVCommon/Common.a:
		make -C DVCommon

Common/Common.a:
		make -C Common

ircDDB/libircDDB.a:
		make -C ircDDB

install:	all
		make -C SystemFusionReflector/SFRemote install
		make -C SystemFusionReflector/SFReflector install
		make -C Data install

clean:
		rm -f core *~ *.bak
		make -C Common clean
		make -C SystemFusionReflector/SFRemote clean
		make -C SystemFusionReflector/SFReflector clean
#		make -C DExtraBridge clean
		
include package.mk
