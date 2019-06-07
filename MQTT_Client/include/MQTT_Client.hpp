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

      /**
       * struktura przechowująca dane do publikowania
       * oraz odebrane z subskrybcji
       */
      typedef struct
      {
        /**
         * enum określający typ danych
         */
        typedef enum
        {
          NONE,
          TEXT, 
          BINARY, 
          JSON

        }data_t;

        string data;
        data_t dataType;
        string topic;
      }MQTT_Data_t;

      typedef bool (*callback_t)(MQTT_Data_t&);
      typedef int port_t;
      typedef std::string address_t;
      typedef std::string topicName_t;

      Connection* connection;
      callback_t callback;
      port_t port;
      address_t address;

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
      bool setConnectionType(std::string);
      
      /**
       * ustawienie callbacka dla danych odbieranych
       */
      void setCallback(callback_t);

      /**
       * ustawienie portu połączenia sieciowego
       */
      void setPort(port_t);

      /**
       * ustawienie adresu połaczenia sieciowego
       */
      void setAddress(std::string&);

      /**
       * ustawienie adresu połaczenia sieciowego
       */
      void setAddress(const char*);

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
      bool subscribe(std::string&);

      /**
       * zasubskrybowanie topicu
       */
      bool subscribe(const char*);

      /**
       * usunięcie subskrybcji topicu
       */
      bool unsubscribe(std::string&);

      /**
       * usunięcie subskrybcji topicu
       */
      bool unsubscribe(const char*);

      /**
       * publikacja wiadomości na topicu
       */
      bool publish(std::string&, MQTT_Data_t&);

      /**
       * publikacja wiadomości na topicu
       */
      bool publish(const char*, MQTT_Data_t&);


      MQTT_Client();
      ~MQTT_Client();
    private:
		//PMQTT_Client mqtt_ClientPtr_;
    };



}

#endif