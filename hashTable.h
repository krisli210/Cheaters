//Kris Li and William Easterby

/* hashTable.h
   Implementation of templated hash table
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <vector>

using namespace std;

template<class ItemType, int TABLESIZE>
class HASH_TABLE {
	public:
		HASH_TABLE();

		~HASH_TABLE();

		int getKey(const string &value) const;

		void add(int key, const ItemType &item);

		//Return true if item is in table
		bool inTable(int key, const ItemType &item) const;

		//Return all items in a vector in a current key spot
		vector<ItemType> getItemsAtKey(int key) const;

		//Return number of items at key
		int numItemsAtKey(int key) const;

		void remove(int key, const ItemType &item);

		int getTableSize() const;

	private:
		static const int tableSize = TABLESIZE;

		vector<ItemType> items[TABLESIZE];

};

/*************************************
 * Function implementations
*************************************/

template<class ItemType, int TABLESIZE>
HASH_TABLE<ItemType, TABLESIZE>::HASH_TABLE(){

}

template<class ItemType, int TABLESIZE>
HASH_TABLE<ItemType, TABLESIZE>::~HASH_TABLE(){

}

template<class ItemType, int TABLESIZE>
int HASH_TABLE<ItemType, TABLESIZE>::getKey(const string &value) const{

	//Hash Algorithm here

}

template<class ItemType, int TABLESIZE>
void HASH_TABLE<ItemType, TABLESIZE>::add(int key, const ItemType &item){

	//Code to add to table here

}

template<class ItemType, int TABLESIZE>
bool HASH_TABLE<ItemType, TABLESIZE>::inTable(int key, const ItemType &item) const{

	//Code to check for in table here

}

template<class ItemType, int TABLESIZE>
vector<ItemType> HASH_TABLE<ItemType, TABLESIZE>::getItemsAtKey(int key) const{

	//Code to return items at key here

}

template<class ItemType, int TABLESIZE>
int HASH_TABLE<ItemType, TABLESIZE>::numItemsAtKey(int key) const{

	//Code to return num items at key here

}

template<class ItemType, int TABLESIZE>
void HASH_TABLE<ItemType, TABLESIZE>::remove(int key, const ItemType &item){

	//Code to remove item from table here

}

template<class ItemType, int TABLESIZE>
int HASH_TABLE<ItemType, TABLESIZE>::getTableSize() const{

	return tableSize;

}


#endif
