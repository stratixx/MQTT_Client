/*
*
*
*
*/
#ifndef DataStore_H
#define DataStore_H

#include <boost/smart_ptr.hpp>
#include <string>

namespace DataStore_NS
{
    using namespace std;
    class DataStore;

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
