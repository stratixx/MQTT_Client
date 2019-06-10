/**
* Author: Dolicher Marcin & Winnicki Konrad
* Klasa implementująca protokół klienta MQTT
*
*/

#ifndef MQTT_CLIENT_H 
#define MQTT_CLIENT_H
/*! 
* \file MQTT_CLIENT.hpp
* \brief Header of client MQTT Protocol
*/
#include <boost/smart_ptr.hpp>
#include <string>
#include "../../paho.mqtt.c/src/MQTTClient.h"
#include "../include/MQTTCallback.hpp"
#include "MQTTData.hpp"
#include <map>


namespace MQTT_Client_NS
{
	using namespace std;
	using namespace boost;

    /**********************************************************************************************//**
     * \class	MQTT_Client
     *
     * \brief	Klasa obsługująca protokół MQTT
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     **************************************************************************************************/

    class MQTT_Client
    {
    public:
      //typedef std::shared_ptr<MQTT_Client*>   PMQTT_Client;
      //typedef std::weak_ptr<MQTT_Client*>     PWMQTT_Client;

		/**********************************************************************************************//**
		 * \typedef	int port_t
		 *
		 * \brief	Defines an alias representing the port
		 **************************************************************************************************/

		typedef int port_t;

		/**********************************************************************************************//**
		 * \typedef	std::string address_t
		 *
		 * \brief	Defines an alias representing the address t
		 **************************************************************************************************/

		typedef std::string address_t;

		/**********************************************************************************************//**
		 * \typedef	std::string topicName_t
		 *
		 * \brief	Defines an alias representing the topic name t
		 **************************************************************************************************/

		typedef std::string topicName_t;

		/**********************************************************************************************//**
		 * \typedef	std::string clientID_t
		 *
		 * \brief	Defines an alias representing the client identifier t
		 **************************************************************************************************/

		typedef std::string clientID_t;

		/**********************************************************************************************//**
		 * \typedef	int MQTTClientContext_t
		 *
		 * \brief	Defines an alias representing context for the mqtt client
		 **************************************************************************************************/

		typedef int MQTTClientContext_t;

		/**********************************************************************************************//**
		 * \typedef	std::map<MQTTClientContext_t, MQTT_Client*> clients_t
		 *
		 * \brief	Defines an alias representing the clients t
		 **************************************************************************************************/

		typedef std::map<MQTTClientContext_t, MQTT_Client*> clients_t;

		/**********************************************************************************************//**
		 * \typedef	MQTTClient libraryClient_t
		 *
		 * \brief	Defines an alias representing the library client
		 **************************************************************************************************/

		typedef MQTTClient libraryClient_t;

		/**********************************************************************************************//**
		 * \typedef	enum MQTT_QOS
		 *
		 * \brief	Defines an enum representing the QOS option
		 **************************************************************************************************/
		typedef enum 
		{
			FireAndForget = 0, 
			AtLeastOnce = 1,
			OnceAndOneOnly = 2
		}MQTT_QOS;

    /**********************************************************************************************//**
     * \typedef	MQTTClient_connectOptions connectOptions_t
     *
     * \brief	Defines an alias representing the connect options t
     **************************************************************************************************/

    typedef MQTTClient_connectOptions connectOptions_t;

		/** \brief	The port */
		port_t port;
		/** \brief	The address */
		address_t address;
		/** \brief	Identifier for the client */
		clientID_t clientID;
		/** \brief	The callback */
		MQTTCallback* callback;
		/** \brief	The context */
		MQTTClientContext_t context;
		/** \brief	The library client */
		libraryClient_t libraryClient;
    /** \brief	Options for controlling the connect */
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
		bool subscribe(const std::string&, const MQTT_QOS&);

		/**
		* zasubskrybowanie topicu
		*/
		bool subscribe(const char*, const MQTT_QOS&);

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
