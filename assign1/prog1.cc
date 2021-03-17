/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 1
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   9/6/2018

   FUNCTION:   This program genrates a vector of VEC_SIZE, sorts the
               vector in ascending order, then prints the vector
*********************************************************************/

#include "prog1.h"

int main()
{
	vector<int> v(VEC_SIZE);

	genRndNums( v );

	sort( v.begin(), v.end() );

	printVec( v );

	return 0;
}


/***************************************************************
Function:  genRndNums

Use: This fills a vector of VEC_SIZE with random integers

Arguments: 1. v, a refrence to a vector of integers to be filled
              with random values

Returns: Nothing
***************************************************************/
void genRndNums( vector<int>& v )
{
	srand( SEED );

	for( unsigned i = 0; i < VEC_SIZE; i++ )
	    v[i] = rand() % (HIGH - LOW + 1) + LOW;   //Generates a number between 1 and 10000
}

/***************************************************************
Function:  printVec

Use: This prints the vector of integers, 12 per line

Arguments: 1. v, a constant refrence to a vector of integers to
              be printed

Returns: Nothing
***************************************************************/
void printVec( const vector<int>& v )
{
	for( unsigned i = 0; i < v.size(); i++ )
        {
             if( (i % NO_ITEMS) == 0 && i != 0 )    //Checks if 12 values have been printed
              cout<<endl;

            cout<<right<<setw( ITEM_W )<<v[i]<<" ";
        }

   cout<<endl;
}
