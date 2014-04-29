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
int c; int ii;

int determineCase( list<Data *> & l );
std::list<Data *>::iterator frst;
std::list<Data *>::iterator scnd;
string frstDat, scndDat;

bool comparestr (const Data * first, const Data * second);

// void buckIt ( list<Data *> & l, const int c );
list<Data *> buck1; list<Data *> buck2; // buckets
list<Data *> buck3; list<Data *> buck10; //less than 1 in mil chance of having to use buckets 4-9
list<Data *> buck11; list<Data *> buck12;
list<Data *> buck13; list<Data *> buck14;
list<Data *> buck15; list<Data *> buck16;
list<Data *> buck17; list<Data *> buck18;
list<Data *> buck19; list<Data *> buck20;
list<Data *> * currbuck[20]; // array of pointers to buckets
int pos;

// void sortBuckets( const int c );

// void mergeBuckets( list<Data *> & l, const int c );

void masterBuckets( list<Data *> & l, const int c );

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

// compare function to compare strings representing numbers with same
// number of digits to left of decimal

bool comparestr (const Data * first, const Data * second){
	return (((first)->data)<((second)->data));
  }

/*
// divide list into buckets based on how many digits to left of decimal
void buckIt ( list<Data *> & l, const int c ){
	if ( c != 3 ){ // will only need lower buckets for case 3
		currbuck[9] = &buck10; currbuck[10] = &buck11;
		currbuck[11] = &buck12; currbuck[12] = &buck13;
		currbuck[13] = &buck14; currbuck[14] = &buck15;
		currbuck[15] = &buck16;	currbuck[16] = &buck17;
		currbuck[17] = &buck18; currbuck[18] = &buck19;
		currbuck[19] = &buck20;
	}
	else{ // no need for higher buckets in case 3
		currbuck[0] = &buck1; currbuck[1] = &buck2;
		currbuck[2] = &buck3;
	}
	
	while ( l.begin() != l.end()){
		pos = (*(l.begin()))->data.find("."); // position of decimal
		currbuck[(pos - 1)]->splice( currbuck[(pos - 1)]->begin(), l, l.begin() );
	}
}

void sortBuckets( const int c ){
	if ( c != 3 ){
		for ( ii = 9; ii < 20 ; ++ii )
			currbuck[ii]->sort( comparestr );
	}
	else{
		for ( ii = 0; ii < 3 ; ++ii )
			currbuck[ii]->sort( comparestr );
	}
}

void mergeBuckets( list<Data *> & l, const int c ){
	if ( c != 3 ){
		for ( ii = 18; ii > 8 ; --ii )
			currbuck[19]->splice( currbuck[19]->begin(), *currbuck[ii] );
		l = *currbuck[19];
	}
	else{
		for ( ii = 1; ii >= 0 ; --ii )
			currbuck[2]->splice( currbuck[2]->begin(), *currbuck[ii] );
		l = *currbuck[2];
	}
}
*/
void masterBuckets( list<Data *> & l, const int c ){
	if ( c != 3 ){ // will only need lower buckets for case 3
		currbuck[9] = &buck10; currbuck[10] = &buck11;
		currbuck[11] = &buck12; currbuck[12] = &buck13;
		currbuck[13] = &buck14; currbuck[14] = &buck15;
		currbuck[15] = &buck16;	currbuck[16] = &buck17;
		currbuck[17] = &buck18; currbuck[18] = &buck19;
		currbuck[19] = &buck20;
		
		while ( l.begin() != l.end()){
			pos = (*(l.begin()))->data.find("."); // position of decimal
			currbuck[(pos - 1)]->splice( currbuck[(pos - 1)]->begin(), l, l.begin() );
		}

		for ( ii = 9; ii < 20 ; ++ii )
			currbuck[ii]->sort(comparestr);
			
		for ( ii = 18; ii > 8 ; --ii )
			currbuck[19]->splice( currbuck[19]->begin(), *currbuck[ii] );
		l = *currbuck[19];
	}

	else{ // no need for higher buckets in case 3
		currbuck[0] = &buck1; currbuck[1] = &buck2;
		currbuck[2] = &buck3;
		
		while ( l.begin() != l.end()){
			pos = (*(l.begin()))->data.find("."); // position of decimal
			currbuck[(pos - 1)]->splice( currbuck[(pos - 1)]->begin(), l, l.begin() );
		}
		
		for ( ii = 0; ii < 3 ; ++ii )
			currbuck[ii]->sort(comparestr);

		for ( ii = 1; ii >= 0 ; --ii )
			currbuck[2]->splice( currbuck[2]->begin(), *currbuck[ii] );
		l = *currbuck[2];
	}	
}

void sortDataList( list<Data *> & l ) {
	c = determineCase(l); //determine which case
	
	if ( c != 4){
		// buckIt( l, c );
		// sortBuckets( c );
		masterBuckets( l, c );
	}
	
	else
		l.sort();
}