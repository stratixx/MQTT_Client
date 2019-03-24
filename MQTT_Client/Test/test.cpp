// MQTT_Client.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

//#define BOOST_TEST_MODULE MyTest
//#include <boost/test/unit_test.hpp>

//#include "pch.h"
#include <iostream>
#include <boost/any.hpp>
#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <algorithm>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

#include "../MQTT_Package/MQTT_Client.hpp"

using namespace std;

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{ seconds });
}

void thread()
{
	for (int i = 0; i < 5; ++i)
	{
		wait(1);
		std::cout << i << '\n';
	}
}

/*
BOOST_AUTO_TEST_CASE( my_test )
{
    MQTT_Client client;
    
    BOOST_CHECK( client.add( 2,2 ) == 4 );        // #1 continues on error

}
*/
int main()
{
    std::cout << "Hello World!\n"; 
    MQTT_Client client;

    cout<<"ClientState: "<<client.getState()<<endl;
    if( client.add(5,6)==11 )
        return 0;
    else
        return -1;

	//boost::thread t{ thread };
	//t.join();

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
