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
std::list<Data *>::iterator frst;
std::list<Data *>::iterator scnd;
string frstDat, scndDat;
bool compare_nocase (const Data * first, const Data * second);

// fast string2float conversion (naive, but fast)
// things pertaining to negative numbers commented out
// source: http://tinodidriksen.com/uploads/code/cpp/speed-string-to-double.cpp
float fastStr2flt( const char * p ) {
    float r = 0.0;
    // bool neg = false;
    // if (*p == '-') {
    //     neg = true;
    //     ++p;
    // }
    while (*p >= '0' && *p <= '9') {
        r = (r*10.0) + (*p - '0');
        ++p;
    }
    if (*p == '.') {
        float f = 0.0;
        int n = 0;
        ++p;
        while (*p >= '0' && *p <= '9') {
            f = (f*10.0) + (*p - '0');
            ++p;
            ++n;
        }
        r += f / std::pow(10.0, n);
    }
    // if (neg) {
    //     r = -r;
    // }
    return r;
}

// function to determine data case
int determineCase( list<Data *> & l ){
	
	if ( l.size() < 400000 ) // t1 
		return 1;
	
	frst = l.begin(); // iterator to first element (1st number)
	scnd = frst; ++frst; // iterator to second element (2st number)
	frstDat = (*frst)->data;
	scndDat = (*scnd)->data;
	
	if ( frstDat.length() < 8 ){
		if ( scndDat.length() <8 ) // if 2 in a row are 7 or less, can conclude t3
			return 3;
	}

	if ( frstDat[0] == scndDat[0] && frstDat[1] == scndDat[1] && frstDat[2] == scndDat[2] && frstDat[3] == scndDat[3] && frstDat[4] == scndDat[4] && frstDat[5] == scndDat[5] && frstDat[6] == scndDat[6] )
		return 4;
	
	if ( strcmp ( frstDat.substr(0,6).c_str(), scndDat.substr(0,6).c_str() ) == 0)
	 	return 4;

	else return 2;
}

// comparison function to be used with list class's sort
bool compare_nocase (const Data * first, const Data * second){
	if (((first)->data)<((second)->data)) return true;
	else if (((first)->data)>((second)->data)) return false;
}

void sortDataList( list<Data *> & l ) {
	
	int c = determineCase(l); //determine which case
	
	// test out sort provided by list class
	l.sort();
}