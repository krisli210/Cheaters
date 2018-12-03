#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "hashTable.h"

using namespace std;

int main() {

	HASH_TABLE<int, 100> ht;

	cout << ht.getTableSize() << endl;

	return 0;

}
