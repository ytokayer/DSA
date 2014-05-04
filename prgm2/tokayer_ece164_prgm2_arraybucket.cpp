// THIS IS THE PROVIDED CODE FOR PROGRAM #2, DSA 1, SPRING 2014

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds one string
class Data {
public:
  string data;
  Data(const string &s) { data = s; }
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l) {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;

  ifstream input(filename.c_str());
  if (!input) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    string line;
    getline(input, line);
    l.push_back(new Data(line));
  }

  input.close();
}

// Output the data to a specified input file
void writeDataList(const list<Data *> &l) {
  string filename;
  cout << "Enter name of output file: ";
  cin >> filename;

  ofstream output(filename.c_str());
  if (!output) {
    cerr << "Error: could not open " << filename << endl;
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << endl;

  // Write the data
  for (list<Data *>::const_iterator ipD = l.begin(); ipD != l.end(); ipD++) {
    output << (*ipD)->data << endl;
  }

  output.close();
}

void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  list<Data *> theList;
  loadDataList(theList);

  cout << "Data loaded.  Executing sort..." << endl;

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds." << endl;

  writeDataList(theList);
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

/**
Yaron Tokayer
DSA Programming Assignment 2

Sorts numbers given by 4 types of input files
*/

// global variables and function declarations
int c, length; int ii, jj;

int determineCase( list<Data *> & l );
std::list<Data *>::iterator frst;
std::list<Data *>::iterator scnd;
string frstDat, scndDat;

void buckIt( list<Data *> & l );
/*
buckets. first index labels bucket: 
first digit(s) represents decimal location minus 10 and last is leading digit of string
*/
string buck[110][200000];
int ind[110] = {0}; // indices for current position of each bucket
int pos, dig;
std::list<Data *>::iterator it;

void sortBucks();

// void listIt( list<Data *> & l );

bool comparestr(const Data * first, const Data * second);

// function to determine data case
int determineCase( list<Data *> & l ){
	if ( l.size() < 400000 ) // t1 
		return 1;
	
	frst = l.begin(); // iterator to first element
	scnd = frst; ++scnd; // iterator to second element
	frstDat = (*frst)->data;
	scndDat = (*scnd)->data;
	
	if ( frstDat.length() < 8 && scndDat.length() <8) 
			return 3; // if 2 in a row are 7 or less, can conclude t3

	if ( strcmp ( frstDat.substr(0,6).c_str(), scndDat.substr(0,6).c_str() ) == 0)
	 	return 4; // check if 6 most significant digits are the same (.1^6 chance if not t4)

	else return 2;
}

// move elements from buckets to given list
void listIt( list<Data *> & l ){
	it = l.begin();
	if( c != 3 ){
		for ( ii = 1; ii < 10 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 11; ii < 20 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 21; ii < 30 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 31; ii < 40 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 41; ii < 50 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 51; ii < 60 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 61; ii < 70 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 71; ii < 80 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 81; ii < 90 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 91; ii < 100 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 101; ii < 110 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
	}
	
	else{
		for ( ii = 10; ii < 20 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 21; ii < 30 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
		for ( ii = 31; ii < 40 ; ++ii ){
			for( jj = 0; jj != ind[ii]; ++jj ){
				(*it)->data = buck[ii][jj];
				++it;
			}
		}
	}
}

// compare function to compare strings representing numbers with same
// number of digits to left of decimal
bool comparestr (const Data * first, const Data * second){
	return (((first)->data)<((second)->data));
}

void buckIt( list<Data *> & l ){
	if ( c != 3 ){
		for ( it = l.begin(); it != l.end(); ++it ){
			pos = (*it)->data.find("."); // position of decimal. range is 10-20
			if ( (*it)->data[0] == '1' )
				dig = 1;
			else if ( (*it)->data[0] == '2' )
				dig = 2;
			else if ( (*it)->data[0] == '3' )
				dig = 3;
			else if ( (*it)->data[0] == '4' )
				dig = 4;
			else if ( (*it)->data[0] == '5' )
				dig = 5;
			else if ( (*it)->data[0] == '6' )
				dig = 6;
			else if ( (*it)->data[0] == '7' )
				dig = 7;
			else if ( (*it)->data[0] == '8' )
				dig = 8;
			else if ( (*it)->data[0] == '9' )
				dig = 9;
			buck[(pos*10) - 100 + dig][ind[(pos*10) - 100 + dig]] = (*it)->data;
			++ind[(pos*10) - 100 + dig];
		}
	}
	
	else{
		for ( it = l.begin(); it != l.end(); ++it ){
			pos = (*it)->data.find("."); // position of decimal. range is 1-4
			if ( (*it)->data[0] == '1' )
				dig = 1;
			else if ( (*it)->data[0] == '2' )
				dig = 2;
			else if ( (*it)->data[0] == '3' )
				dig = 3;
			else if ( (*it)->data[0] == '4' )
				dig = 4;
			else if ( (*it)->data[0] == '5' )
				dig = 5;
			else if ( (*it)->data[0] == '6' )
				dig = 6;
			else if ( (*it)->data[0] == '7' )
				dig = 7;
			else if ( (*it)->data[0] == '8' )
				dig = 8;
			else if ( (*it)->data[0] == '9' )
				dig = 9;
			else if ( (*it)->data[0] == '0' )
				dig = 0;
			buck[(pos*10) + dig][ind[(pos*10) + dig]] = (*it)->data;
			++ind[(pos*10) + dig];
		}	
	}
}

void sortBucks(){
	if ( c != 3 ){
		for ( ii = 1; ii < 10 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 11; ii < 20 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 21; ii < 30 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 31; ii < 40 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 41; ii < 50 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 51; ii < 60 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 61; ii < 70 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 71; ii < 80 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 81; ii < 90 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 91; ii < 100 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 101; ii < 110 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
	}
	else{
		for ( ii = 10; ii < 20 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 21; ii < 30 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
		for ( ii = 31; ii < 40 ; ++ii )
			sort( &buck[ii][0], &buck[ii][ind[ii]]);
	}
}
// strcmp(&str1[14], &str2[14])
void sortDataList( list<Data *> & l ) {
	c = determineCase(l); //determine which case
	
	if ( c == 4){
		l.sort(comparestr);
	}
	
	else{
		buckIt(l);
		sortBucks();
		listIt(l);
	}
}