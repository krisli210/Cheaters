#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char*  argv[]) {

	cout << "Hello, world" << endl;

	cout << "Reading from: " << argv[1] << endl;

	ifstream file;
	file.open(argv[1]);
	const int n = 6;
	vector<string> sequence;
	while(file){
		string temp;
		file >> temp;
		sequence.push_back(temp);

		if(sequence.size() == n) {
			cout << sequence[0] << " " << sequence[1] << " " << sequence[2] << " " << sequence[3] << " " << sequence[4] << " " << sequence[5] <<  "\n";
			sequence.erase(sequence.begin());
		}
	}
	file.close();

	return 0;

}
