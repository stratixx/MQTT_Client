/*
*
*
*
*/
#ifndef DataStore_H
#define DataStore_H

//#include <boost/smart_ptr.hpp>

namespace DataStore_NS
{
    class DataStore;

    class DataStore
    {
        //typedef shared_ptr<DataStore>   PDataStore;
        //typedef weak_ptr<DataStore>     PWDataStore;

    public:
        int add(int, int);
		// zapis oczyt danych z bazy
		void writeData();
		void readData(); 

    private:
        //PDataStore dataStorePtr_;
    };

}

#endif
