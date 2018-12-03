//Kris Li and William Easterby

/* hashTable.h
   Implementation of templated hash table
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstdlib>
#include <vector>

using namespace std;

template<class ItemType, int size>
class HASH_TABLE {
	public:
		HASH_TABLE();

		~HASH_TABLE();

		int getKey(const string &value) const;

		//Return true on collision
		bool add(int key, const ItemType &item);

		//Return true if item is in table
		bool inTable(int key, const ItemType &item) const;

		//Return all items in a vector in a current key spot
		vector<ItemType> getAll(int key) const;

		void remove(int key, const ItemType &item);

	private:
		const int tableSize = size;

		vector<ItemType> items[size];

};


#endif
