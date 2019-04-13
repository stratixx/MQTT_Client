cmake_minimum_required(VERSION 3.1.0)

#stworzenie projektu
project(MQTT_Sniffer VERSION 1.0.0 DESCRIPTION "MQTT Sniffer project")

#składowe projektu
add_subdirectory(DataStore)
add_subdirectory(MQTT_Client) 
add_subdirectory(Publisher) 
add_subdirectory(Subscriber) 
