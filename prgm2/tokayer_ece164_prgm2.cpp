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
int c;

int determineCase( list<Data *> & l );
std::list<Data *>::iterator frst;
std::list<Data *>::iterator scnd;
string frstDat, scndDat;

bool comparestr (const Data * first, const Data * second);

void addLeadingZeroes( list<Data *> & l, const int c );
std::list<Data *>::iterator it;
string strDat; int missZeroes; int ii; int cc;

void remLeadingZeroes( list<Data *> & l, const int c );

// function to determine data case
int determineCase( list<Data *> & l ){
	
	if ( l.size() < 400000 ) // t1 
		return 1;
	
	frst = l.begin(); // iterator to first element (1st number)
	scnd = frst; ++frst; // iterator to second element (2st number)
	frstDat = (*frst)->data;
	scndDat = (*scnd)->data;
	
	if ( frstDat.length() < 8 && scndDat.length() <8) 
			return 3; // if 2 in a row are 7 or less, can conclude t3

	if ( strcmp ( frstDat.substr(0,6).c_str(), scndDat.substr(0,6).c_str() ) == 0)
	 	return 4; // check if 6 most significant digits are the same (.1^6 chance if not t4)

	else return 2;
}

bool comparestr (const Data * first, const Data * second){
	return (((first)->data)<((second)->data));
  }

void addLeadingZeroes( list<Data *> & l, const int c ){
	if ( c == 1 || c == 2 )
		cc = 20;
	else
		cc = 3;
	for ( it=l.begin(); it != l.end(); ++it){
		strDat = (*it)->data;
		missZeroes = cc - strDat.find("."); // number of zeroes to add
		for ( ii = missZeroes; ii != 0; --ii )
			(*it)->data = "0" + (*it)->data; // add appropriate # of 0's
	}
}

void remLeadingZeroes( list<Data *> & l, const int c ){
	if ( c == 1 || c == 2 ){
		for ( it=l.begin(); it != l.end(); ++it){
			while( (*it)->data[0] == 48 ) // remove appropriate number of zeroes
				(*it)->data.erase((*it)->data.begin());
		}
	}
	else{
		for ( it=l.begin(); it != l.end(); ++it){
			while( (*it)->data[0] == 48 && (*it)->data[1] != 46 ) // remove appropriate number of zeroes
				(*it)->data.erase((*it)->data.begin());
		}
	}
}

void sortDataList( list<Data *> & l ) {
	c = determineCase(l); //determine which case
	
	if ( c != 4){
		addLeadingZeroes( l, c );
		l.sort(comparestr);
		remLeadingZeroes( l, c );
	}
	
	else
		l.sort(comparestr);
}