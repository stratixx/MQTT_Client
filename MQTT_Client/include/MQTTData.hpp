/**
* Author: Dolicher Marcin & Winnicki Konrad
* 
*
*/

#ifndef MQTT_DATA_H 
#define MQTT_DATA_H

#include <string>
#include <vector>

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

    typedef vector<char> dataVector_t;
    string data;
	dataVector_t dataVector;
    
    data_t dataType;
    std::string topic;
  }MQTT_Data_t;

#endif
