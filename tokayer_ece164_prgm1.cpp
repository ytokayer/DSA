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
		}
		
		string name;
		Node *front; // pointers to front and back of list
		Node *back;
		
	protected:
		SimpleList( string & nn ){ // SimpleList constructor
			this.name = nn;
			front = NULL;
			back = NULL;
			}
		void push_front( const T & x ){ // method to push at front of list
			Node *newnode =	new Node( x, front );
			front = newnode;
		}
		void push_back( const T & x ){ // method to push at back of list
			Node *newnode = new Node( x );
			back = newnode;
		}
		T pop_front( ){ //method to pop from the front of a list and return value
			T tmp1 = front.data;
			Node *tmp2 = front.next;
			delete front;
			front = ptr;
			return data;
		}
		
		virtual void push( const T & x ) // pure virtual functions
		virtual T pop() 
	
	public:
		string getname() const{ // function to return name of stack or queue
			return name;
		}
}

// stack as a derived class of SimpleList
template <typename T>
class Stack: public SimpleList{
	public:
		Stack( string & nn ):SimpleList<T>( nn ){ // Stack constructor
		}
		void push( const T & x){
			push_front( x );
		}
		T pop(){
			pop_front();
		}

}

// queue as a derived class of SimpleList
template <typename T>
class Queue: public SimpleList{
	public:
		Queue( string & nn ):SimpleList<T>( nn ){ // Queue constructor
		}
		void push( const T & x){
			push_back( x );
		}
		T pop(){
			pop_front();
		}
}

// function to find list with given name
template <typename T>
SimpleList<T>* findlist( const string & lname, list<SimpleList<T> *> & Tlist){
	for (list<SimpleList<T> *>::iterator SLp=Tlist.begin(); SLp != Tlist.end(); ++SLp){ // check for valid name
		if ( SLp->getname() == lname );
			return SLp;
	}
	return NULL; // if name doesn't exist, return pointer to NULL
}

// function to proccess each line of input
void procline( const string & ll, list & ilist, list & dlist, list & slist, fstream & output ){
	istringstream iss( ll );
	string cmd;
	iss >> cmd;
	if ( cmd == "create" ) { // for create command
		string lname; // name of list to be created
		iss >> lname;
		if ( lname[1] == "i" ){	// list to be created is of int type
			if ( findlist( lname, ilist ) == NULL )// name doesn't already exist
				string spec; // is list of integers a stack or a queue
				iss >> spec;
				if ( spec == "queue" )
					SimpleList<int>* newq = new Queue( lname );
					ilist.push_front( newq );
				else if ( spec == "stack" )
					SimpleList<int>* newst = new Stack( lname );
					ilist.push_front( newst );
			else // name already exists
				output << "ERROR: This name already exists!";
		}

		else if ( lname[1] == "d" ){ // list to be created is of double type
			if ( findlist( lname, dlist ) == NULL )// name doesn't already exist
				string spec; // is list of strings a stack or a queue
				iss >> spec;
				if ( spec == "queue" )
					SimpleList<double>* newq = new Queue( lname );
					ilist.push_front( newq );
				else if ( spec == "stack" )
					SimpleList<double>* newst = new Stack( lname );
					ilist.push_front( newst );
			else // name already exists
				output << "ERROR: This name already exists!";
		}

		else if ( lname[1] == "s" ){ // list to be created is of string type
			if ( findlist( lname, slist ) == NULL )// name doesn't already exist
				string spec; // is list of strings a stack or a queue
				iss >> spec;
				if ( spec == "queue" )
					SimpleList<string>* newq = new Queue( lname );
					ilist.push_front( newq );
				else if ( spec == "stack" )
					SimpleList<string>* newst = new Stack( lname );
					ilist.push_front( newst );
			else // name already exists
				output << "ERROR: This name already exists!";
		}
	}
	
else if ( cmd == "push" ) { // for push command
}

else if ( cmd == "pop" ) { // for pop command
}

int main()
{
	fstream input; // create input stream
	inputstrm( &input );
	
	fstream output; // create output stream
	outputstrm ( &output );
	
	// decalare lists
	list<SimpleList<int> *> listSLi // all integer stacks and queues
	list<SimpleList<double> *> listSLd // all double stacks and queues
	list<SimpleList<string> *> listSLs // all string stacks and queues
	
	int i = 1;
	string currline; // string with current line
	output << "PROCESSING COMMAND: " << currline;
	while( getline (input, currline) ) // test for existence of line
	{
		/* output << currline << '\n';
		++i; */
	}
	
	// close input and output streams
	input.close();
	output.close();
	
	return 0;
}