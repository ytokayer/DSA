/**
Yaron Tokayer
DSA Programming Assignment 1

Follows commands from an input file to create and modify stacks and queues.
Records runtime to output file.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

// function to create input stream by user input
void inputstrm (fstream *input){
	string infile;
	cout << "Enter name of input file: ";
	cin >> infile;
	input->open(infile.c_str());
}

// function to create output stream by user input
void outputstrm( fstream *output ){
	string outfile;
	cout << "Enter name of output file: ";
	cin >> outfile;
	output->open(outfile.c_str(), ios::out);
}

// base class to provide singly-linked list functionality
template <typename T>
class SimpleList{
	private:
		struct Node{ // nested Node class for SimpleList
			T data; // Node data members
			Node *next;
			
			Node( const T & d, Node *n = NULL ) // Node constructor
				: data( d ), next( n ) {}
		};
		
		string name;
		Node *front; // pointers to front and back of list
		Node *back;
		
	protected:
		SimpleList( string & nn ){ // SimpleList constructor
			name = nn;
			front = NULL;
			back = NULL;
			}
		void push_front( const T & x ){ // method to push at front of list
			Node *newnode =	new Node( x, front );
			front = newnode;
			if ( isempty() ) // list is empty
				back = newnode;
		}
		void push_back( const T & x ){ // method to push at back of list
			Node *newnode = new Node( x );
			back = newnode;
			if( isempty() ) // list is empty
				front = newnode;
		}
		T pop_front( ){ //method to pop from the front of a list and return value
			T d = front->data;
			Node *p = front->next;
			delete front;
			front = p;
			return d;
		}
	public:	
		virtual void push( const T & x ); // pure virtual functions
		virtual T pop();
	
		string getname() const{ // function to return name of stack or queue
			return name;
		}
		bool isempty() const{ // function to check for emptiness
			return front == NULL;
		}
};

// stack as a derived class of SimpleList
template <typename T>
class Stack: public SimpleList<T>{
	public:
		Stack( string & nn ):SimpleList<T>( nn ){ // Stack constructor
		}
		void push( const T & x){
			SimpleList<T>::push_front( x );
		}
		T pop(){
			SimpleList<T>::pop_front();
		}

};

// queue as a derived class of SimpleList
template <typename T>
class Queue: public SimpleList<T>{
	public:
		Queue( string & nn ):SimpleList<T>( nn ){ // Queue constructor
		}
		void push( const T & x){
			SimpleList<T>::push_back( x );
		}
		T pop(){
			SimpleList<T>::pop_front();
		}
};

// function to find list with given name
template <typename T>
SimpleList<T>* findlist( const string & lname, list<SimpleList<T> *> & Tlist){
	typename list<SimpleList<T> *>::iterator SLp;
	for (SLp = Tlist.begin(); SLp != Tlist.end(); ++SLp ){ // check for valid name
		if ( (*SLp)->getname() == lname );
			return *SLp;
	}
	return NULL; // if name doesn't exist, return pointer to NULL
}

// function to proccess each line of input
void procline( const string & ll, list<SimpleList<int> *> & ilist, list<SimpleList<double> *> & dlist, list<SimpleList<string> *> & slist, fstream & output ){
	istringstream iss( ll );
	string cmd; // command
	iss >> cmd;
	string lname; // name of list to be modified
	iss >> lname;
	if ( cmd == "create" ) { // for create command
		if ( lname[1] == 'i' ){	// list to be created is of int type
			if ( findlist( lname, ilist ) == NULL ){ // name doesn't already exist
				string spec; // is list of integers a stack or a queue
				iss >> spec;
				if ( spec == "queue" ){ // create new queue of ints with desired name
					SimpleList<int>* newq = new Queue<int>( lname );
					ilist.push_front( newq );
				}
				else if ( spec == "stack" ){ // create new stack of ints with desired name
					SimpleList<int>* newst = new Stack<int>( lname );
					ilist.push_front( newst );
				}
			}
			else // name already exists
				output << "ERROR: This name already exists!" << '\n';
		}

		else if ( lname[1] == 'd' ){ // list to be created is of double type
			if ( findlist( lname, dlist ) == NULL ){ // name doesn't already exist
				string spec; // is list of strings a stack or a queue
				iss >> spec;
				if ( spec == "queue" ){ // create new queue of doubles with desired name
					SimpleList<double>* newq = new Queue<double>( lname );
					dlist.push_front( newq );
				}
				else if ( spec == "stack" ){ // create new stack of doubles with desired name
					SimpleList<double>* newst = new Stack<double>( lname );
					dlist.push_front( newst );
				}
			}
			else // name already exists
				output << "ERROR: This name already exists!" << '\n';
		}

		else if ( lname[1] == 's' ){ // list to be created is of string type
			if ( findlist( lname, slist ) == NULL ){ // name doesn't already exist
				string spec; // is list of strings a stack or a queue?
				iss >> spec;
				if ( spec == "queue" ){ // create new queue of strings with desired name
					SimpleList<string>* newq = new Queue<string>( lname );
					slist.push_front( newq );
				}
				else if ( spec == "stack" ){ // create new stack of ints with desired name
					SimpleList<string>* newst = new Stack<string>( lname );
					slist.push_front( newst );
				}
			}
			else // name already exists
				output << "ERROR: This name already exists!" << '\n';
		}
	}
	
	else if ( cmd == "push" ) { // for push command
		if ( lname[1] == 'i' ){	// data to be pushed is of int type
			SimpleList<int> *lptr;
			lptr = findlist( lname, ilist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				int pushdata;
				iss >> pushdata;
				lptr->push( pushdata );
			}
		}
		else if ( lname[1] == 'd' ){	// data to be pushed is of double type
			SimpleList<double> *lptr;			
			lptr = findlist( lname, dlist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				double pushdata;
				iss >> pushdata;
				lptr->push( pushdata );
			}
		}
		else if ( lname[1] == 's' ){	// data to be pushed is of string type
			SimpleList<string> *lptr;			
			lptr = findlist( lname, slist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				string pushdata;
				iss >> pushdata;
				lptr->push( pushdata );
			}
		}		
	}

	else if ( cmd == "pop" ) { // for pop command
		if ( lname[1] == 'i' ){ // list to be popped contains ints
			SimpleList<int> *lptr = findlist( lname, ilist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				if ( lptr->isempty() )// list is empty
					output << "ERROR: This list is empty!" << '\n';
				else{
					int val;
					val = lptr->pop();
					output << "Value popped: " << val << '\n';
				}
			}
		}
		else if ( lname[1] == 'd' ){ // list to be popped contains doubles
			SimpleList<double> *lptr = findlist( lname, dlist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				if ( lptr->isempty() )// list is empty
					output << "ERROR: This list is empty!" << '\n';
				else{
					double val;
					val = lptr->pop();
					output << "Value popped: " << val << '\n';
				}
			}
		}
		else if ( lname[1] == 's' ){ // list to be popped contains strings
			SimpleList<string> *lptr = findlist( lname, slist );
			if ( lptr == NULL ) // name doesn't exist
				output << "ERROR: This name does not exist!" << '\n';
			else{ // name exists
				if ( lptr->isempty() )// list is empty
					output << "ERROR: This list is empty!" << '\n';
				else{
					string val;
					val = lptr->pop();
					output << "Value popped: " << val << '\n';
				}
			}
		}
	}
}

int main()
{
	fstream input; // create input stream
	inputstrm( &input );
	
	fstream output; // create output stream
	outputstrm ( &output );
	
	// decalare lists
	list<SimpleList<int> *> listSLi; // all integer stacks and queues
	list<SimpleList<double> *> listSLd; // all double stacks and queues
	list<SimpleList<string> *> listSLs; // all string stacks and queues
	
	int i = 1;
	string currline; // string with current line
	output << "PROCESSING COMMAND: " << currline << '\n';
	while( getline (input, currline) ) // test for existence of line
	{
		procline( currline, listSLi, listSLd, listSLs, output );
	}
	
	// close input and output streams
	input.close();
	output.close();
	
	return 0;
}