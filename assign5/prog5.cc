/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 5
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   10/11/2018

   FUNCTION:   This program constructs a list of "names" of size N to
	       represent the josephus circle, eliminates every Mth name
	       within the circle, and prints after every Kth elimination
*********************************************************************/

#include "/home/cs340/progs/18f/p5/prog5.h"


int main()
{
	args argu;

	cout<<"Number of people? ";
	cin>> argu.N; //Number of people

	cout<<"Index for elimination? ";
	cin>> argu.M; //Elimate Value

	cout<<"Index for printing? ";
	cin>> argu.K; //Print after every Kth elimination


	list<string> L ( argu.N );

	//Fill list with names
	init_vals( L, argu );

	unsigned cnt = 0;

	print_list( L, cnt );


	int j;
	list<string>::iterator p = L.begin();


	//Eliminate every Mth element until 1 is left
	for( int i = 0; L.size() != 1; i = j )
	{
	  if( (cnt % argu.K ) == 0 && cnt != 0 ) //Checks if K values have been erased
	   {
	    print_list( L, cnt );
	   }

	  j = ( i + argu.M - 1 ) % L.size();
          advance( p, j );
          L.erase( p );
	  p = L.begin();

	 cnt++;
	}

	print_list( L, cnt );

  return 0;
}

/***************************************************************
Function: init_vals

Use: This reads in the args object and uses N to fill a list of
     strings with names.

Arguments: 1. L, a refrence to a list of strings to be filled
		 with names.
	   2. in, a refrence to an args object where N is used
		  to generate names to fill the list

Returns: Nothing
***************************************************************/
void init_vals( list<string>& L, args& in )
{
	generate( L.begin(), L.end(), SEQ( in.N ) );
}

/***************************************************************
Function: print_list

Use: This prints the elements of a list of strings containing
     the "names" of those within the josephus circle.

Arguments: 1. L, a refrence to a constant list of strings to be
		 printed
	   2. cnt, an unsigned value to represent the number of
		   elements eliminated

Returns: Nothing
***************************************************************/
void print_list( const list<string>& L, const unsigned& cnt )
{
	int j = 0;
	list<string>::const_iterator i;

	if( cnt == 0 )
		cout<<"\nInitial group of people\n-----------------------\n";
	else
		cout<<"After eliminating "<<cnt<<"th person\n-----------------------------\n";


	for( i = L.cbegin(); i != L.cend(); i++ )
	{
	  if( (j % NO_ITEMS ) == 0 && j != 0 )    //Checks if 12 elements have been printed
              cout<<endl;

	  cout<< *i <<" ";
	  j++;
	}

 cout<<"\n\n";
}
