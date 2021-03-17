/*********************************************************************
   FILE:    prog1.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   9/6/2018

   FUNCTION:   This program contains the function prototypes and
               constant variables used in prog1.cc
*********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

void genRndNums( vector<int>& );
void printVec( const vector<int>& );

const int VEC_SIZE = 250;
const int LOW = 1;
const int HIGH = 10000;
const int SEED = 1;
const int NO_ITEMS = 12;
const int ITEM_W = 5;


#endif

