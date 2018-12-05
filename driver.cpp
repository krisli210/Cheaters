//Kris Li and William Easterby
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*function... might want it in some class?*/
int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

string vecToString(vector<string> &vec)
{
   string temp ;
   string::iterator it; 
   string result = "" ;
   for (int i = 0 ; i < vec.size() ; i++) {
	temp = vec[i] ;
	for (int j = 0 ; j < temp.length() ; j++) {
	    temp[j] = tolower(temp[j]) ;
	    if(ispunct(temp[j]))
		temp.erase(j) ;   	
	}
	result += temp ;
	  	
    }
   return result ; 
}

int main(int argc, char* argv[])
{
    cout << argv[1] << endl ; 
    string dir = string(argv[1]);
    vector<string> files = vector<string>();

    getdir(dir,files);
    
    vector<string> sequence;
    string temp ; 
    string squeezed ;

    int chnk_s = atoi(argv[2]); // Chunk size 
    cout << "Chunk Size " << chnk_s << endl;

    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << files[i] << endl;
	ifstream myfile;

	if (i > 1) {//skip . and .. 
            myfile.open((dir + "/" + files[i]).c_str());
	    if(!myfile.is_open())
		cout << "file not opened" << endl;
	    while(myfile >> temp) {
		sequence.push_back(temp);

		if (sequence.size() == chnk_s) {
		    squeezed = vecToString(sequence) ;
		    cout << squeezed << endl ; 
		    //here we hash the vector

		    sequence.erase(sequence.begin());
		}
	    }
	sequence.clear() ;
	myfile.close(); 	    
	//cout << "get here" << endl;
	//return 0 ;
	}
    }
    return 0;
}
