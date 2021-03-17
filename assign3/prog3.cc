/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 3
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   9/24/2018

   FUNCTION:   This program generates a set of n integers and applies
	       the sieve of eratosthenes algorithm to remove non-prime
	       integers from the set. Then prints the set.
*********************************************************************/

#include "prog3.h"

int main()
{
	set<int> s;

	int upper;

	cout<<"Enter an upper limit: ";
	cin>>upper;
	cout<<endl;

	sieve( s, upper );

	print_primes( s );
}

/***************************************************************
Function: sieve

Use: This function fills an empty set with integers then applies
     the sieve of eratosthenes algorithm to remove all non-prime
     numbers from the set

Arguments: 1. s, a refrence to a set of integers to be filled and
		 filtered through
	   2. n, an integer used to represent the upper bound of
		 the set

Returns: Nothing
***************************************************************/
void sieve( set<int>& s, int n )
{
        //Fills a set with n amount of values
	for( int i = 2; i <= n; i++ )
	{
	  s.insert(i);
	}

	//Removes non prime numbers from set
	for ( int i = 2; i <= n; i++ )
        {
          for ( int j = i * i; j <= n; j+=i )
           {
             s.erase(j);
           }
        }
}

/***************************************************************
Function: print_primes

Use: This prints a set of prime numbers, 16 per line

Arguments: 1. s, a refrence to a set of integers to be printed

Returns: Nothing
***************************************************************/
void print_primes( const set<int>& s )
{
	int i = 0;
	set<int>::const_iterator j = s.begin();

	for( j = s.begin(); j != s.end(); j++ )
	{
		if( (i % NO_ITEMS) == 0 && i != 0 )    //Checks if 16 values have been printed
              cout<<endl;

		 cout<<right<<setw( ITEM_W )<<fixed<<*j<<" ";
		 i++;
	}
  cout<<endl;
}
