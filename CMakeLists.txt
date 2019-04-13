cmake_minimum_required(VERSION 3.1.0)

project(MQTT_Sniffer VERSION 1.0.0 DESCRIPTION "MQTT Sniffer project")


add_subdirectory(DataStore)
add_subdirectory(MQTT_Client) 
add_subdirectory(Publisher) 
add_subdirectory(Subscriber) 
