/*********************************************************************
   FILE:    prog4.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   10/2/2018

   FUNCTION:   This program contains the function prototypes and
               global variables used in prog4.cc
*********************************************************************/

#ifndef TEXTSCAN_H
#define TEXTSCAN_H

#include <map>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int NO_ITEMS = 3;
const int ITEM_W = 16;
int inputNum = 0;

void get_words( map<string,int>& );
void print_words( const map<string,int>& );
void clean_entry( const string&, string& );


#endif

