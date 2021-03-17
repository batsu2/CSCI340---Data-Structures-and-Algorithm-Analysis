/*********************************************************************
   FILE:    prog2.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   9/14/2018

   FUNCTION:   This file contains the global variables and function
               prototypes used in sub2.cc and prog2.cc
*********************************************************************/

#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int ARR_SIZE = 200;
const int TEST_ARR_SIZE = 100;
const int SEED1 = 1;
const int SEED2 = 3;
const int LOW = 1;
const int HIGH = 1000;
const int NO_ITEMS = 16;
const int ITEM_W = 4;

void Vectors( vector<int>& v1, vector<int>& v2, int s1, int s2 );
bool linearSearch( const vector<int>& v, int x );
bool binarySearch( const vector<int>& v, int x );
int search( const vector<int>& v1, const vector<int>& v2, bool (*p)(const vector<int>&, int ));
void sortVector( vector<int>& v );
void printVector(const vector<int>& v);
void printStat( int totalSucCnt, int vectorSz );

#endif

