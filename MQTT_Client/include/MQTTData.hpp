/**
* Author: Dolicher Marcin & Winnicki Konrad
* 
*
*/

#ifndef MQTT_DATA_H 
#define MQTT_DATA_H

#include <string>

using namespace std;


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
      STRING, 
      BINARY, 
      HEX, 

    }data_t;

    string data;
    data_t dataType;
    string topic;
  }MQTT_Data_t;

#endif
