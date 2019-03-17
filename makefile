# Author: Marcin Dolicher and Konrad Winnicki
# My makefile - type 'make clean' and next 'make all' to create and compile project
###################################################################

# project name
project_name = MQTT_Client

# compilation cmd
CC = c++11

# sources directory
s = MQTT_Client

# executable files directory
b = UbuntuRelease

# *.o files directory
o = MQTT_Client/UbuntuRelease

###################################################################

# make them all
all: pch MQTT_Client

# clean and create required directories
clean: 
	rm -r -f $o $b
	mkdir $o $b


# 
object0 = pch
$(object0): $s/$(object0).cpp
	$(CC) $s/$(object0).cpp  -c -o $o/$(object0).o

object1 = MQTT_Client
$(object1): pch $s/$(object1).cpp 
	$(CC) $o/pch.o $s/$(object1).cpp     -o $b/$(object1)

