# Makefile
#
# Build the ircDDB Gateway software on Linux
#

include settings.mk

all:	ircDDBGateway/ircddbgateway ircDDBGatewayConfig/ircddbgatewayconfig RemoteControl/remotecontrol StarNetServer/starnetserver TimerControl/timercontrol \
			TimeServer/timeserver

ircDDBGateway/ircddbgateway:	ircDDB/libircDDB.a Common/Common.a
		make -C ircDDBGateway

ircDDBGatewayConfig/ircddbgatewayconfig:	Common/Common.a
		make -C ircDDBGatewayConfig

RemoteControl/remotecontrol:	Common/Common.a
		make -C RemoteControl

StarNetServer/starnetserver:	ircDDB/libircDDB.a Common/Common.a
		make -C StarNetServer

TimerControl/timercontrol:	Common/Common.a
		make -C TimerControl

TimeServer/timeserver:	Common/Common.a
		make -C TimeServer

Common/Common.a:
		make -C Common

ircDDB/libircDDB.a:
		make -C ircDDB

install:	all
		make -C ircDDBGateway install
		make -C ircDDBGatewayConfig install
		make -C RemoteControl install
		make -C StarNetServer install
		make -C TimerControl install
		make -C TimeServer install
		make -C Data install

clean:
		rm -f core *~ *.bak
		make -C ircDDB clean
		make -C Common clean
		make -C ircDDBGateway clean
		make -C ircDDBGatewayConfig clean
		make -C RemoteControl clean
		make -C StarNetServer clean
		make -C TimerControl clean
		make -C TimeServer clean
		
include package.mk
