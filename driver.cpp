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
#include "hashTable.h"

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
   string result = "" ;
   for (int i = 0 ; i < vec.size() ; i++) {
	temp = vec[i] ;
	for (int j = 0 ; j < temp.length() ; j++) {
	    temp[j] = tolower(temp[j]) ;
	    if(ispunct(temp[j]))
		temp.erase(j,1) ;   	
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

    int key ; 
    string squeezed ;


    const int ts = 500009 ; 
    HASH_TABLE<int, ts> ht ;
    vector<int> collisions ;

    int chnk_s = atoi(argv[2]); // Chunk size 
    int threshold = atoi(argv[3]) ; // amount of words for a match   

    for (unsigned int i = 0;i < files.size();i++) {
        //cout << i << files[i] << endl;
	ifstream myfile;

	if (i > 1) {//skip . and .. 
            myfile.open((dir + "/" + files[i]).c_str());

	    if(!myfile.is_open())
		cout << "file not opened" << endl;

	    while(myfile >> temp) {
		sequence.push_back(temp);
		if (sequence.size() == chnk_s) {
		    squeezed = vecToString(sequence) ;
		    //cout << squeezed << endl ;
		    key = ht.getKey(squeezed);
		    //cout << key << endl ;
		    if(!ht.inTable(key,i)) {
		        ht.add(key,i) ; //add index of file to vector
		        if (ht.numItemsAtKey(key) == 2) //setting boolean variable if there are 2 things
		   	    collisions.push_back(key) ;
                    }    
		    //here we hash the vector

		    sequence.erase(sequence.begin());
		}
	    }
	sequence.clear() ;
	myfile.close(); 	    
	}
    }
//cout << collisions.size() << endl ; 

    //int matches[files.size()][files.size()] ;
    int** matches = new int*[files.size()] ;
    for (int i = 0 ; i < files.size() ; ++i) //dynamically allocate memory  
	matches[i] = new int[files.size()] ; 
    for (int i = 0 ; i < files.size(); i++) { //initialize 2d array to 0
	for (int j = 0 ; j < files.size(); j++) {
	    matches[i][j] = 0 ; 
        }
    }	 
    vector<int> comparisons ; 
    for (int i = 0 ; i < collisions.size() ; i++) { //outer loop for each key
	comparisons = ht.getItemsAtKey(collisions[i]) ;
	     
	for (int j = 0 ; j < comparisons.size() ; j++) {//nested for loop for finding pairs
	    int compare = comparisons[j] ;
	    for (int k = j+1 ; k < comparisons.size() ; k++) {
	    int against = comparisons[k] ; 
		if (compare != against) { // comparing file indeces to see if there's a match
		    if (compare < against) //we want an upper triangular
			matches[compare][against]++ ;
		    else
			matches[against][compare]++ ;
		} 
	    }
	    
	}	

    } 
    int matchAmount = 0 ; 
    for (int i = 0 ; i < files.size(); i++) { //outputs matches
	
	for (int j = 0 ; j < files.size() ; j++) {
	    if (matches[i][j] > threshold) {
		cout << matches[i][j] << ": " << files[i] << ", " << files[j] << endl ;
		matchAmount++ ; 
	    }
	}
    }	
    cout << "Amount of matches: " << matchAmount << endl;
    for (int i = 0 ; i < files.size() ; ++i) //frees memory  
	delete [] matches[i] ;
    delete matches;  
    return 0;
}
