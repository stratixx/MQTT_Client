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

      Connection* connection;
      port_t port;
      address_t address;
	  clientID_t clientID;
	  MQTTCallback* callback;

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


      MQTT_Client();
      ~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
    };



}

#endif
