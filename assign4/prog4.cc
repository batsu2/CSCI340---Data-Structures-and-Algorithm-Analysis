/*********************************************************************
   PROGRAM:    CSCI 340 Assignment 4
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   10/2/2018

   FUNCTION:   This program scans and processes a stream of words,
	       removing any punctuation mark and setting all characters
	       in a string to lowercase.
*********************************************************************/

#include "prog4.h"

int main()
{
	map<string, int> m;

	get_words( m );

	print_words( m );

  return 0;
}

/***************************************************************
Function: get_words

Use: This gets a word from the input stream and removes its punc-
     tuation marks while also setting all letters to lower case

Arguments: 1. m, a refrence to a map of string keys and integer
		 values. Keys represent words in a stream and the
		 values represent their frequency in the stream

Returns: Nothing
***************************************************************/
void get_words( map<string, int>& m )
{
    string s;

	//Fills a map with values from the input stream
	while( cin >> s )
	{
          clean_entry( s, s );

	    if( s.length() != 0 )
	    {
	      m[s]++;

	      inputNum++;
	    }
	}
}

/***************************************************************
Function: clean_entry

Use: This cleans a string from its punctuation marks and changes
     all characters within it to lower case

Arguments: 1. s1, a refrence to a constant string, the original
                  word to be changed
           2. s2, a refrence to a string, the word after cleaning

Returns: Nothing
***************************************************************/
void clean_entry( const string& s1, string& s2 )
{
	size_t i = 0;
	size_t firstChar = 0;
	size_t punct = 0;
	bool foundAlpha = false;
	bool firstCharPnct = false;

	//If punctuation is first in a string
	if( !isalnum(s1[i]) && isalnum(s1[i+1]) )
	{
	  i++;
	  firstCharPnct = true;
	}

	//Loop through s1 until char in s1 is no longer alpha numeric
	while( isalnum(s1[i]) )
	  {
	   if( foundAlpha == false )
	    {
	     firstChar = i;
	     foundAlpha = true;
	    }

	   i++;
          }

	//Accounts for punctuation being first by decrementing index
	if( firstCharPnct == true)
	  --i;

	//When dropped out of loop, i indicates punctuation
	 punct = i;


	 s2 = s1.substr( firstChar, punct );

	//Changes all letter to lower case
	for_each(s2.begin(), s2.end(), [&](char& ch){ch = tolower(ch);});

}

/***************************************************************
Function: print_words

Use: This prints the final list of words and their frequencies
     along with the number of nonempty words and number of distinct
     words in a input stream, 3 per line

Arguments: 1. m, a refrence to a map of string words and integer
		 frequency values of those words to be printed

Returns: Nothing
***************************************************************/
void print_words( const map<string, int>& m )
{
	int j = 0;
	map<string, int>::const_iterator i;

	for( i = m.cbegin(); i != m.cend(); i++ )
	{
	  if( (j % NO_ITEMS) == 0 && j != 0 )    //Checks if 3 pairs have been printed
              cout<<endl;

	  cout<<left<<setw(ITEM_W)<<(*i).first<<": "<<setw(2)<<(*i).second<<"    ";
	  j++;
	}

  cout<<"\n\nno of words in input stream  : "<< inputNum;
  cout<<"\nno of words in output stream : "<< m.size()<<endl;
}
