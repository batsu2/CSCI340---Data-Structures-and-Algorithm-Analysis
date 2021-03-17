/*********************************************************************
   FILE:    prog8.cc
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   11/17/2018

   FUNCTION:   This program pulls data from several input files and
	       using the heapsort technique, sorts and prints them
*********************************************************************/

#ifndef PROG8
#define PROG8


#include "/home/cs340/progs/18f/p8/prog8.h"

using namespace std;


int main ( )
{
    vector < int >    v1;   // heap of integers
    vector < float >  v2;   // heap of floating-pt nums
    vector < string > v3;   // heap of strings

    // print header message
    cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

    // first heap

    cout << "first heap - ascending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, less < int > ( ) );
    print_list < int > print1 ( v1.size ( ), INT_SZ, INT_LN );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    cout << "first heap - descending order:\n\n";
    get_list ( v1, D1 );
    construct_heap ( v1, greater < int > ( ) );
    for_each ( v1.begin ( ), v1.end ( ), print1 );

    // second heap

    cout << "second heap - ascending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, less < float > ( ) );
    print_list < float > print2 ( v2.size ( ), FLT_SZ, FLT_LN );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    cout << "second heap - descending order:\n\n";
    get_list ( v2, D2 );
    construct_heap ( v2, greater < float > ( ) );
    for_each ( v2.begin ( ), v2.end ( ), print2 );

    // third heap

    cout << "third heap - ascending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, less < string > ( ) );
    print_list < string > print3 ( v3.size ( ), STR_SZ, STR_LN );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    cout << "third heap - descending order:\n\n";
    get_list ( v3, D3 );
    construct_heap ( v3, greater < string > ( ) );
    for_each ( v3.begin ( ), v3.end ( ), print3 );

    // print termination message
    cout << "\t\t\t*** end of program execution ***\n\n";
    return 0;
}

/***************************************************************
Method: get_list

Use: This function opens an input file for reading then reads
     the item from the file and inserts them into a vector.

Arguments: 1. v, a refrence to a vector of template data types
		 to have values inserted into
	   2. path, a pointer to a constant character data
		    containing the full path name of the input file

Returns: Nothing
***************************************************************/
template <class T>
void get_list ( vector <T>& v, const char* path )
{
	v.clear();
	T temp;                     // Temp data to read into
	ifstream inFile;
	inFile.open( path );        // Open file

	if (!inFile)
	{
	  cout << "Error, Unable to open file." << endl;
	  exit(1);
	}

	inFile >> temp;             // Read first entry

	while (!inFile.eof())       //read in until end of file
	{
	  v.push_back(temp);      // Insert in vector
	  inFile >> temp;         // read next entry
	}

	inFile.close();
}

/***************************************************************
Method: construct_heap

Use: This function constructs a heap structure from thr items of
     vector v and uses the predicate pred to compare the items
     while building.

Arguments: 1. v, a refrence to a vector of template data types to
	         be created and sorted
	   2. pred, a predicate to be used with make_heap() and
		    sort_heap()

Returns: Nothing
***************************************************************/
template <class T, class P>
void construct_heap ( vector <T>& v, P pred )
{
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}

/***************************************************************
Method: operator()

Use: This function overloads the perenthesis operator "()" to
     print the item x of a heap on stdout.

Arguments: x, a refrence to a constant template data type to be
	      printed.

Returns: Nothing
***************************************************************/
template <class T>
void print_list <T>::operator()( const T& x )
{
	cout.width( wid ); cout.precision( 2 );
	cout<<fixed<<showpoint;

	if ( cnt <= sz )
	{
		if (cnt % len == 0)
		{
	         cout << endl;
		}

		cout << x << " ";
		cnt++;
	}

	if (cnt == sz)
		cout << endl << endl;
}

/***************************************************************
Method: print_list()

Use: This is the default constructor for the print_list class

Arguments: 1. s, a refrence to a constant unsigned value to represent
		 the heap's size
	   1. w, a refrence to a constant unsigned value to represent
                 the minimum number of chars written in printout
	   1. l, a refrence to a constant unsigned value to represent
                 the maximum number of items printed in a single line
	   1. c, a refrence to a constant unsigned value to represent
                 a counter (with default value of 0) used to insert
	         the newline characters in printout.

Returns: Nothing
***************************************************************/
template < class T>
print_list<T>::print_list ( const unsigned& s, const unsigned& w, const unsigned & l, const unsigned& c )
{
	cnt = c;
	sz = s;
	wid = w; // min num of chars in output
	len = l; // max num of items printed on a single line
}

#endif
