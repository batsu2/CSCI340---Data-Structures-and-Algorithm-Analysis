/*********************************************************************
   FILE:    hTable.cc
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   11/27/2018

   FUNCTION:   This holds the hash table methods that create, search,
	       print, and sort an item inventory
*********************************************************************/

#ifndef H_TABLE
#define H_TABLE


#include "/home/cs340/progs/18f/p9/hTable.h"

using namespace std;

void ptr_sort( vector <Entry*>& , unsigned );

/***************************************************************
Function: HT

Use: This is the default constructor for the HT class

Arguments: 1. s, a refrence to a constant unsigned value

Returns: Nothing
***************************************************************/
HT::HT( const unsigned& s )
{
	hTable.resize(s);
	pTable.resize(s);
	psize = 0;
	hsize = SZ_TBL;

	for (unsigned int i = 0; i != s; i++)
	{
	  hTable[i].key = FREE;
	}
}

/***************************************************************
Function: ~HT

Use: This is the default destructor for the HT class

Arguments: None

Returns: Nothing
***************************************************************/
HT::~HT()
{
}

/***************************************************************
Function: insert

Use: This inserts entries into a hash table. If the key already
     exists, print an error message. If the Table is full, print
     an error message. Otherwise prints the index value of inserted
     value and inserts the address of the record into pTable.

Arguments: 1. e, a refrence to a constant Entry object

Returns: Nothing
***************************************************************/
void HT::insert ( const Entry& e )
{
	int index = hash(e.key);
	unsigned int i;
	for (i = 0; i < hsize; i++)
	{
	  if (hTable[(index+i)%hsize].key == FREE)
	  {
	   // use linear probing for collision resolution
	    cout << " entry = " << (index + i) % hsize << endl;
	    hTable[(index+i)%hsize] = e;
	    pTable[psize] = &hTable[(index+i)%hsize];
	    psize++;
	    break;
	  }
	  if (hTable[(index+i)%hsize].key == e.key)
	  {
	    cout << " not inserted - duplicate key!!!" << endl;
	    break;
	  }
 	}

	if (i == hsize)
	  cout << " not inserted - table full!!!" << endl;
}

/***************************************************************
Function: search

Use: This searches the hash table for a record with a given value.
     If search is successful, print the item information otherwise
     print an error message.

Arguments: 1. s, a refrence to a constant string type

Returns: Nothing
***************************************************************/
void HT::search( const string& s )
{
	int index = hash(s);
	unsigned int i;
	for (i = 0; i < hsize; i++)
	{
	  if (hTable[(index+i)%hsize].key == s)
	  {
	    cout << " ==> number: "
	    << setw(4) << hTable[(index+i)%hsize].num
	    << " - item: " << hTable[(index+i)%hsize].desc
	    << endl;
	    break;
	  }
	}
	// if serched value is not in table
	if (hTable[(index+i)%hsize].key != s)
	cout << " not in table!!" << endl;
}

/***************************************************************
Function: hTable_print

Use: This prints all the elements of a hash table

Arguments: None

Returns: Nothing
***************************************************************/
void HT::hTable_print()
{
	bool lastEmpty = false;
	for ( unsigned int i = 0; i < hsize; i++ )
	{
	  if ( hTable[i].key != FREE )
	  {
	    if ( lastEmpty ) cout << endl;
	     cout << setw(4) << i << ":  " << hTable[i].key << "  -  "
	     << setw(5) << hTable[i].num << "  -  " << hTable[i].desc << endl;
	     lastEmpty = false;
	  }
	  else lastEmpty = true;
	}

	cout << endl;
}

/***************************************************************
Function: pTable_print

Use: This sorts and prints the elements of a table filled with
     pointers to elements in a hash table

Arguments: None

Returns: Nothing
***************************************************************/
void HT::pTable_print()
{
	ptr_sort( pTable, psize );
	for (unsigned int i = 0; i < psize; i++ )
	{
	  cout << "   " << pTable[i]->key
	  << "  -  " << right << setw(4) << pTable[i]->num
	  << "  -  " << left << pTable[i]->desc << endl;
	}

	cout << endl;
}

/***************************************************************
Function: prt_sort

Use: This sorts the elements of a table of pointers

Arguments: 1. pTable, a refrence to a vector of Entry pointers
	   2. psize, an unsigned value to represent the size of
	             the pointer table

Returns: Nothing
***************************************************************/
void ptr_sort( vector <Entry*>& pTable, unsigned psize )
{
	unsigned int i, j;
	Entry* bucket;

	for (i = 1; i < psize; i++)
	{
	  bucket = pTable[i];
	  for (j = i; (j > 0) && (pTable[j-1]->key > bucket->key); j--)
	  	pTable[j] = pTable[j-1];

	  pTable[j] = bucket;
	}
}


#endif
