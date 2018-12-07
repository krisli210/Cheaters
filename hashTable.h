//Kris Li and William Easterby

/* hashTable.h
   Implementation of templated hash table
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

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
		
	long unsigned int key  = 0 ;
	
	int numTimes = (value.length() / 3);
	for (int i = 0 ; i < numTimes ; i++) {
	    
	    key += value[value.length()-(i*3)-1] * pow(37, i) ; 

	} 
	return key%tableSize ;

}

template<class ItemType, int TABLESIZE>
void HASH_TABLE<ItemType, TABLESIZE>::add(int key, const ItemType &item){

	if((key >= 0) && (key < tableSize))
	    items[key].push_back(item);
	
}

template<class ItemType, int TABLESIZE>
bool HASH_TABLE<ItemType, TABLESIZE>::inTable(int key, const ItemType &item) const{

	bool result = false;

	if((key >= 0) && (key < tableSize)) {		
		int size = items[key].size();
		for(int i = 0; (i < size) && (!result); i++) {
			if(items[key].at(i) == item)
				result = true;
		}
	}

	return result;

}

template<class ItemType, int TABLESIZE>
vector<ItemType> HASH_TABLE<ItemType, TABLESIZE>::getItemsAtKey(int key) const{

	vector<ItemType> result;

	if((key >= 0) && (key < tableSize))
		result = items[key];

	return result;

}

template<class ItemType, int TABLESIZE>
int HASH_TABLE<ItemType, TABLESIZE>::numItemsAtKey(int key) const{

	int result = 0;

	if((key >= 0 ) && (key < tableSize))
		result = items[key].size();

	return result;

}

template<class ItemType, int TABLESIZE>
void HASH_TABLE<ItemType, TABLESIZE>::remove(int key, const ItemType &item){

	bool found = false;

	if((key >= 0) && (key < tableSize)) {		
		int size = items[key].size();
		for(int i = 0; (i < size) && (!found); i++) {
			if(items[key].at(i) == item){
				found = true;
				items[key].erase(items[key].begin() + i);
			}
		}
	}

}

template<class ItemType, int TABLESIZE>
int HASH_TABLE<ItemType, TABLESIZE>::getTableSize() const{

	return tableSize;

}


#endif
