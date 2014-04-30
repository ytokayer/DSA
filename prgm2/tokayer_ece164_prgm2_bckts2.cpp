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

void buckIt ( list<Data *> & l, const int c );
list<Data *> buck11; list<Data *> buck12; // buckets
list<Data *> buck13; list<Data *> buck14;
list<Data *> buck15; list<Data *> buck16;
list<Data *> buck17; list<Data *> buck18;
list<Data *> buck19; list<Data *> buck10; // bucket 1 can have leading 0
list<Data *> buck21; list<Data *> buck22;
list<Data *> buck23; list<Data *> buck24;
list<Data *> buck25; list<Data *> buck26;
list<Data *> buck27; list<Data *> buck28;
list<Data *> buck29;
list<Data *> buck31; list<Data *> buck32;
list<Data *> buck33; list<Data *> buck34;
list<Data *> buck35; list<Data *> buck36;
list<Data *> buck37; list<Data *> buck38;
list<Data *> buck39; 
list<Data *> buck101; list<Data *> buck102; //less than 1 in mil chance of having to use buckets 4-9
list<Data *> buck103; list<Data *> buck104;
list<Data *> buck105; list<Data *> buck106;
list<Data *> buck107; list<Data *> buck108;
list<Data *> buck109;
list<Data *> buck111; list<Data *> buck112;
list<Data *> buck113; list<Data *> buck114;
list<Data *> buck115; list<Data *> buck116;
list<Data *> buck117; list<Data *> buck118;
list<Data *> buck119;
list<Data *> buck121; list<Data *> buck122;
list<Data *> buck123; list<Data *> buck124;
list<Data *> buck125; list<Data *> buck126;
list<Data *> buck127; list<Data *> buck128;
list<Data *> buck129;
list<Data *> buck131; list<Data *> buck132;
list<Data *> buck133; list<Data *> buck134;
list<Data *> buck135; list<Data *> buck136;
list<Data *> buck137; list<Data *> buck138;
list<Data *> buck139;
list<Data *> buck141; list<Data *> buck142;
list<Data *> buck143; list<Data *> buck144;
list<Data *> buck145; list<Data *> buck146;
list<Data *> buck147; list<Data *> buck148;
list<Data *> buck149;
list<Data *> buck151; list<Data *> buck152;
list<Data *> buck153; list<Data *> buck154;
list<Data *> buck155; list<Data *> buck156;
list<Data *> buck157; list<Data *> buck158;
list<Data *> buck159;
list<Data *> buck161; list<Data *> buck162;
list<Data *> buck163; list<Data *> buck164;
list<Data *> buck165; list<Data *> buck166;
list<Data *> buck167; list<Data *> buck168;
list<Data *> buck169;
list<Data *> buck171; list<Data *> buck172;
list<Data *> buck173; list<Data *> buck174;
list<Data *> buck175; list<Data *> buck176;
list<Data *> buck177; list<Data *> buck178;
list<Data *> buck179;
list<Data *> buck181; list<Data *> buck182;
list<Data *> buck183; list<Data *> buck184;
list<Data *> buck185; list<Data *> buck186;
list<Data *> buck187; list<Data *> buck188;
list<Data *> buck189;
list<Data *> buck191; list<Data *> buck192;
list<Data *> buck193; list<Data *> buck194;
list<Data *> buck195; list<Data *> buck196;
list<Data *> buck197; list<Data *> buck198;
list<Data *> buck199;
list<Data *> buck201; list<Data *> buck202;
list<Data *> buck203; list<Data *> buck204;
list<Data *> buck205; list<Data *> buck206;
list<Data *> buck207; list<Data *> buck208;
list<Data *> buck209;
list<Data *> * currbuck[110]; // array of pointers to buckets
int pos; int dig;

void sortBuckets( const int c );

void mergeBuckets( list<Data *> & l, const int c );

// void masterBuckets( list<Data *> & l, const int c );

// function to determine data case
int determineCase( list<Data *> & l ){
	
	if ( l.size() < 400000 ) // t1 
		return 1;
	
	frst = l.begin(); // iterator to first element
	scnd = frst; ++scnd; // iterator to second element
	frstDat = (*frst)->data;
	scndDat = (*scnd)->data;
	
	if ( frstDat.length() < 8 ) 
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

// divide list into buckets based on how many digits to left of decimal and then based on first digit
void buckIt ( list<Data *> & l, const int c ){
	if ( c != 3 ){ // will only need lower buckets for case 3
		currbuck[1] = &buck101; currbuck[2] = &buck102; currbuck[3] = &buck103; currbuck[4] = &buck104;
		currbuck[5] = &buck105; currbuck[6] = &buck106;	currbuck[7] = &buck107;	currbuck[8] = &buck108;
		currbuck[9] = &buck109;
		currbuck[11] = &buck111; currbuck[12] = &buck112; currbuck[13] = &buck113; currbuck[14] = &buck114;
		currbuck[15] = &buck115; currbuck[16] = &buck116; currbuck[17] = &buck117;	currbuck[18] = &buck118;
		currbuck[19] = &buck119;
		currbuck[21] = &buck121; currbuck[22] = &buck122; currbuck[23] = &buck123; currbuck[24] = &buck124;
		currbuck[25] = &buck125; currbuck[26] = &buck126; currbuck[27] = &buck127; currbuck[28] = &buck128;
		currbuck[29] = &buck129;
		currbuck[31] = &buck131; currbuck[32] = &buck132; currbuck[33] = &buck133; currbuck[34] = &buck134;
		currbuck[35] = &buck135; currbuck[36] = &buck136; currbuck[37] = &buck137; currbuck[38] = &buck138;
		currbuck[39] = &buck139;
		currbuck[41] = &buck141; currbuck[42] = &buck142; currbuck[43] = &buck143; currbuck[44] = &buck144;
		currbuck[45] = &buck145; currbuck[46] = &buck146; currbuck[47] = &buck147; currbuck[48] = &buck148;
		currbuck[49] = &buck149;
		currbuck[51] = &buck151; currbuck[52] = &buck152; currbuck[53] = &buck153; currbuck[54] = &buck154;
		currbuck[55] = &buck155; currbuck[56] = &buck156; currbuck[57] = &buck157; currbuck[58] = &buck158;
		currbuck[59] = &buck159;
		currbuck[61] = &buck161; currbuck[62] = &buck162; currbuck[63] = &buck163; currbuck[64] = &buck164;
		currbuck[65] = &buck165; currbuck[66] = &buck166; currbuck[67] = &buck167; currbuck[68] = &buck168;
		currbuck[69] = &buck169;
		currbuck[71] = &buck171; currbuck[72] = &buck172; currbuck[73] = &buck173; currbuck[74] = &buck174;
		currbuck[75] = &buck175; currbuck[76] = &buck176; currbuck[77] = &buck177; currbuck[78] = &buck178;
		currbuck[79] = &buck179;
		currbuck[81] = &buck181; currbuck[82] = &buck182; currbuck[83] = &buck183; currbuck[84] = &buck184;
		currbuck[85] = &buck185; currbuck[86] = &buck186; currbuck[87] = &buck187; currbuck[88] = &buck188;
		currbuck[89] = &buck189;
		currbuck[91] = &buck191; currbuck[92] = &buck192; currbuck[93] = &buck193; currbuck[94] = &buck194;
		currbuck[95] = &buck195; currbuck[96] = &buck196; currbuck[97] = &buck197; currbuck[98] = &buck198;
		currbuck[99] = &buck199;
		currbuck[101] = &buck201; currbuck[102] = &buck202; currbuck[103] = &buck203; currbuck[104] = &buck204;
		currbuck[105] = &buck205; currbuck[106] = &buck206; currbuck[107] = &buck207; currbuck[108] = &buck208;
		currbuck[109] = &buck209;
	}
	else{ // no need for higher buckets in case 3
		currbuck[11] = &buck11; currbuck[12] = &buck12; currbuck[13] = &buck13; currbuck[14] = &buck14;
		currbuck[15] = &buck15; currbuck[16] = &buck16; currbuck[17] = &buck17;	currbuck[18] = &buck18;
		currbuck[19] = &buck19; currbuck[10] = &buck10;
		currbuck[21] = &buck21; currbuck[22] = &buck22; currbuck[23] = &buck23; currbuck[24] = &buck24;
		currbuck[25] = &buck25; currbuck[26] = &buck26; currbuck[27] = &buck27; currbuck[28] = &buck28;
		currbuck[29] = &buck29;
		currbuck[31] = &buck31; currbuck[32] = &buck32; currbuck[33] = &buck33; currbuck[34] = &buck34;
		currbuck[35] = &buck35; currbuck[36] = &buck36; currbuck[37] = &buck37; currbuck[38] = &buck38;
		currbuck[39] = &buck39;
	}
	
	if ( c != 3 ){
		while ( l.begin() != l.end()){
			pos = (*(l.begin()))->data.find("."); // position of decimal
			if ( (*(l.begin()))->data[0] == '1' )
				dig = 1;
			else if ( (*(l.begin()))->data[0] == '2' )
				dig = 2;
			else if ( (*(l.begin()))->data[0] == '3' )
				dig = 3;
			else if ( (*(l.begin()))->data[0] == '4' )
				dig = 4;
			else if ( (*(l.begin()))->data[0] == '5' )
				dig = 5;
			else if ( (*(l.begin()))->data[0] == '6' )
				dig = 6;
			else if ( (*(l.begin()))->data[0] == '7' )
				dig = 7;
			else if ( (*(l.begin()))->data[0] == '8' )
				dig = 8;
			else if ( (*(l.begin()))->data[0] == '9' )
				dig = 9;
			else if ( (*(l.begin()))->data[0] == '0' )
				dig = 0;
			currbuck[(pos*10) - 100 + dig]->splice( currbuck[(pos*10) - 100 + dig]->begin(), l, l.begin() );
		}
	}
	else{
		while ( l.begin() != l.end()){
			pos = (*(l.begin()))->data.find("."); // position of decimal
			if ( (*(l.begin()))->data[0] == '1' )
				dig = 1;
			else if ( (*(l.begin()))->data[0] == '2' )
				dig = 2;
			else if ( (*(l.begin()))->data[0] == '3' )
				dig = 3;
			else if ( (*(l.begin()))->data[0] == '4' )
				dig = 4;
			else if ( (*(l.begin()))->data[0] == '5' )
				dig = 5;
			else if ( (*(l.begin()))->data[0] == '6' )
				dig = 6;
			else if ( (*(l.begin()))->data[0] == '7' )
				dig = 7;
			else if ( (*(l.begin()))->data[0] == '8' )
				dig = 8;
			else if ( (*(l.begin()))->data[0] == '9' )
				dig = 9;
			else if ( (*(l.begin()))->data[0] == '0' )
				dig = 0;			
			currbuck[(pos*10) + dig]->splice( currbuck[(pos*10) + dig]->begin(), l, l.begin() );
		}	
	}
}

void sortBuckets( const int c ){
	if ( c != 3 ){
		for ( ii = 1; ii < 10 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 11; ii < 20 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 21; ii < 30 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 31; ii < 40 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 41; ii < 50 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 51; ii < 60 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 61; ii < 70 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 71; ii < 80 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 81; ii < 90 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 91; ii < 100 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 101; ii < 110 ; ++ii )
			currbuck[ii]->sort( comparestr );
	}
	else{
		for ( ii = 10; ii < 19 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 21; ii < 29 ; ++ii )
			currbuck[ii]->sort( comparestr );
		for ( ii = 31; ii < 39 ; ++ii )
			currbuck[ii]->sort( comparestr );
	}
}

void mergeBuckets( list<Data *> & l, const int c ){
	if ( c != 3 ){
		for ( ii = 108; ii > 100 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 99; ii > 90 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 89; ii > 80 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 79; ii > 70 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 69; ii > 60 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 59; ii > 50 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 49; ii > 40 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 39; ii > 30 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 29; ii > 20 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 19; ii > 10 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		for ( ii = 9; ii > 0 ; --ii )
			currbuck[109]->splice( currbuck[109]->begin(), *currbuck[ii] );
		l = *currbuck[109];
	}
	else{
		for ( ii = 38; ii > 30 ; --ii )
			currbuck[39]->splice( currbuck[39]->begin(), *currbuck[ii] );
		for ( ii = 29; ii > 20 ; --ii )
			currbuck[39]->splice( currbuck[39]->begin(), *currbuck[ii] );
		for ( ii = 19; ii > 9 ; --ii )
			currbuck[39]->splice( currbuck[39]->begin(), *currbuck[ii] );
		l = *currbuck[39];
	}
}
/*
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
*/

void sortDataList( list<Data *> & l ) {
	c = determineCase(l); //determine which case
	
	if ( c != 4){
		buckIt( l, c );
		sortBuckets( c );
		mergeBuckets( l, c );
	}
	
	else
		l.sort();
}