/*********************************************************************
   FILE:    prog3.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   9/24/2018

   FUNCTION:   This program contains the function prototypes and
               constant variables used in prog3.cc
*********************************************************************/

#ifndef SIEVE_H
#define SIEVE_H

#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int NO_ITEMS = 16;
const int ITEM_W = 4;

void sieve( set<int>& s, int n );
void print_primes(const set<int>& s );


#endif
