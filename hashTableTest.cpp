#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "hashTable.h"

using namespace std;

int main() {

	HASH_TABLE<int, 100> ht;

	cout << ht.getTableSize() << endl;

	int keys[] = {0, 1, 47, 99, 100, -1, 1, 3};  //8 Keys
	int values[] = {42, 42, 42, 42, 42, 42, 56}; //7 Values

	for(int i = 0; i < 7; i++){

		ht.add(keys[i], values[i]);

	}

	for(int i = 0; i <8; i++){
		
		cout << "Key " << keys[i] << ": ";
		vector<int> results = ht.getItemsAtKey(keys[i]);
		for(int j = 0; j < results.size(); j++) {
			cout << results[j] << ", ";
		}

		cout << "(size " << ht.numItemsAtKey(i) << endl;
	
	}

	cout << ht.inTable(1, 32) << endl;
	for(int i = 0; i <8; i++){
		
		cout << "Key " << keys[i] << ": " << ht.inTable(keys[i], values[i]) << endl;
	
	}

	ht.remove(1, 42);

	int i = 1;
	vector<int> results = ht.getItemsAtKey(keys[i]);
	for(int j = 0; j < results.size(); j++) {
		cout << results[j] << ", ";
	}

	cout << "(size " << ht.numItemsAtKey(i) << endl;

	for(int i = 0; i < 8; i++) {
		ht.remove(keys[i], values[i]);
	}
	
	for(int i = 0; i <8; i++){
		
		cout << "Key " << keys[i] << ": ";
		vector<int> results = ht.getItemsAtKey(keys[i]);
		for(int j = 0; j < results.size(); j++) {
			cout << results[j] << ", ";
		}

		cout << "(size " << ht.numItemsAtKey(i) << endl;
	
	}

	ht.remove(1, 32);

	return 0;

}
