# Author: Marcin Dolicher and Konrad Winnicki
# My makefile - type 'make clean' and next 'make all' to create and compile project
###################################################################

# project name
project_name = Application

# compilation cmd
CC = c++ -std=c++11 -g -Wall -static 

# sources directory
s = .

# executable files directory
b = bin

# *.o files directory
o = obj

dependencies = ../MQTT_Client/lib/MQTT_ClientLib.a
#-lboost_unit_test_framework


###################################################################

# make them all
all: MQTT_Client Application

# clean and create required directories
clean: 
	rm -r -f $o $b
	mkdir $o $b
 
object1 = MQTT_Client
$(object1): 
	cd ../MQTT_Client && make MQTT_Client

object2 = Application
$(object2): $s/$(object2).cpp 
	$(CC) $s/$(object2).cpp -o $b/$(object2) $(dependencies)
