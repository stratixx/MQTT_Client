# Author: Marcin Dolicher and Konrad Winnicki
# My makefile - type 'make clean' and next 'make all' to create and compile project
###################################################################

# project name
project_name = MQTT_ClientLib

# compilation cmd
CC = c++ -std=c++11 -g -Wall -static 

# sources directory
s = .

# executable files directory
b = lib

# *.o files directory
o = obj

dependencies = -lboost_system -lboost_chrono -pthread -lpthread  -lboost_thread 
#-lboost_unit_test_framework


###################################################################

# make them all
all: MQTT_Client

# clean and create required directories
clean: 
	rm -r -f $o $b
	mkdir $o $b


# 
object1 = MQTT_Client
$(object1): $s/$(object1).cpp 
	$(CC) $s/$(object1).cpp -c  -o $o/$(object1).o $(dependencies)
	ar rvs $b/$(project_name).a $o/$(object1).o