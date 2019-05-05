# MQTT_Client

Poszczególne commity zawierają informację o wyniku testów CircleCI

[![CircleCI](https://circleci.com/gh/stratixx/MQTT_Client.svg?style=svg)](https://circleci.com/gh/stratixx/MQTT_Client)

Przygotowanie:
 - W głównym katalogu projektu stwórz katalog `build/` i przejdź do niego,
 
 - W konsoli wywołaj komendę `cmake ..`,
 
 - Jeśli pracujesz w systemie Linux, wywołaj komendę `make`,
 
 - Jeśli pracujesz w systemie Windows, uruchom Visual Studio i wywołaj kompilację.


Uruchomienie:
 - w katalogu `build/MQTT_Client` znajduje się skompilowana biblioteka MQTT_Client,

 - w katalogu `build/DataStore` znajduje się skompilowana biblioteka DataStore,

 - w katalogu `build/Subscriber`, `build/Publisher` znajdują się pliki wykonywalne projektów `Subscriber` i `Publisher`.


Testy:
 - Aby wywołać testy biblioteki `MQTT_Client` lub `DataStore`, w katalogu `build/MQTT_Client` lub `build/DataStore` wywołaj komendę ctest
   
 - Aby wywołać testy `Subscriber` lub `Publisher`, w katalogu `build/Subscriber` lub `build/Publisher` wywołaj komendę ctest
 
 - Możliwe jest wykonanie konkretnego testu poprzez uruchomienie pliku wykonywalnego z podkatalogu `testBin`
