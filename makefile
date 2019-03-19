# Author: Marcin Dolicher and Konrad Winnicki
# My makefile - type 'make clean' and next 'make all' to create and compile project
###################################################################

# project name
project_name = MQTT_ClientTest

# compilation cmd
CC = c++ -std=c++11 -g -Wall -static 

# sources directory
s = MQTT_Client

# executable files directory
b = UbuntuRelease

# *.o files directory
o = MQTT_Client/UbuntuRelease

dependencies = -lboost_system -lboost_chrono -pthread -lpthread  -lboost_thread -lboost_unit_test_framework


###################################################################

# make them all
all: pch MQTT_Client test

# clean and create required directories
clean: 
	rm -r -f $o $b
	mkdir $o $b


# 
object0 = pch
$(object0): $s/$(object0).cpp
	$(CC) $s/$(object0).cpp  -c -o $o/$(object0).o $(dependencies)

object1 = MQTT_Client
$(object1): pch $s/$(object1).cpp 
	$(CC) $o/pch.o $s/$(object1).cpp -c  -o $o/$(object1).o $(dependencies)

object2 = test
$(object2): pch MQTT_Client $s/$(object2).cpp 
	$(CC) $o/pch.o $o/MQTT_Client.o $s/$(object2).cpp  -o $b/$(object2) $(dependencies)

