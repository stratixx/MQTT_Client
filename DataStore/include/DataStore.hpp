/*
*
*
*
*/
#ifndef DataStore_H
#define DataStore_H
/*! \file DataStore.hpp
	\brief A header of DataStore class.
*/
#include <boost/smart_ptr.hpp>
#include <string>

#ifdef _WIN32	
    #define filePathSeparator '\\'
#elif __linux__
	#define filePathSeparator '/'
#else
	#error("Unsuportted OS")
#endif

namespace DataStore_NS
{
    using namespace std;
    class DataStore;

    /**********************************************************************************************//**
     * \class	DataStore
     *
     * \brief	A data store.
     *
     * \author	Marcin Dolicher
     * \date	10.06.2019
     **************************************************************************************************/

    class DataStore
    {
        //typedef shared_ptr<DataStore>   PDataStore;
        //typedef weak_ptr<DataStore>     PWDataStore;

    public:
		// zapis oczyt danych z bazy
		void writeData(string&);
		string readData(); 

    private:
        //PDataStore dataStorePtr_;
    };

}

#endif
