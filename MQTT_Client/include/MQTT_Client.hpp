/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#ifndef MQTT_CLIENT_H 
#define MQTT_CLIENT_H

#include <boost/smart_ptr.hpp>
#include <string>
#include "Connection.h"
#include "SocketHandle.hpp"
#include "../../paho.mqtt.c/src/MQTTClient.h"
#include "../include/MQTTCallback.hpp"
#include "MQTTData.hpp"
#include <map>


namespace MQTT_Client_NS
{
	using namespace std;
	using namespace boost;

    /**
     * Klasa obsługująca protokół MQTT
    */
    class MQTT_Client
    {
    public:
      //typedef std::shared_ptr<MQTT_Client*>   PMQTT_Client;
      //typedef std::weak_ptr<MQTT_Client*>     PWMQTT_Client;
			   		 

		typedef int port_t;
		typedef std::string address_t;
		typedef std::string topicName_t;
		typedef std::string clientID_t;
		typedef int MQTTClientContext_t;
		typedef std::map<MQTTClientContext_t, MQTT_Client*> clients_t;
		typedef MQTTClient libraryClient_t;
    typedef MQTTClient_connectOptions connectOptions_t;

		Connection* connection;
		port_t port;
		address_t address;
		clientID_t clientID;
		MQTTCallback* callback;
		MQTTClientContext_t context;
		libraryClient_t libraryClient;
    connectOptions_t connectOptions;


		/**
		* jednokrotny przebieg pętli odświeżania 
		*/
		bool spinOnce();
		/**
		* wielokrotny przebieg pętli odświeżania
		*/
		bool spin();

		/**
		* wybranie typu połączenia
		*/
		bool setConnectionType(const std::string&);
      
		/**
		* ustawienie callbacka dla danych odbieranych
		*/
		void setCallback(MQTTCallback*);

		/**
		* ustawienie portu połączenia sieciowego
		*/
		void setPort(const port_t&);

		/**
		* ustawienie adresu połaczenia sieciowego
		*/
		void setAddress(const std::string&);

		/**
		* ustawienie adresu połaczenia sieciowego
		*/
		void setAddress(const char*);


		/**
		* ustawienie nazwy klienta
		*/
		void setClientID(const std::string&);

		/**
		* ustawienie nazwy klienta
		*/
		void setClientID(const char*);

		/**
		* próba nawiązania połaczenia sieciowego
		*/
		bool connect();

		/**
		* zakończenie połączenia sieciowego
		*/
		void disconnect();

		/**
		* zasubskrybowanie topicu
		*/
		bool subscribe(const std::string&);

		/**
		* zasubskrybowanie topicu
		*/
		bool subscribe(const char*);

		/**
		* usunięcie subskrybcji topicu
		*/
		bool unsubscribe(const std::string&);

		/**
		* usunięcie subskrybcji topicu
		*/
		bool unsubscribe(const char*);

		/**
		* publikacja wiadomości na topicu
		*/
		bool publish(const std::string&, const MQTT_Data_t&);

		/**
		* publikacja wiadomości na topicu
		*/
		bool publish(const char*, const MQTT_Data_t&);


		MQTT_Client(const address_t&, const clientID_t&);
		MQTT_Client();
		~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
		static MQTTClientContext_t getNewContext();
		static clients_t clients;

		static void delivered(void *context, MQTTClient_deliveryToken dt);
		static int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message);
		static void connlost(void *context, char *cause);
    };



}

#endif
