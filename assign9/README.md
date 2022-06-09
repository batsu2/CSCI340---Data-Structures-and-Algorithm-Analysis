LINEAR PROBING & HASH TABLES

For this computer assignment, I wrote a C++ program to create, search, print, and sort an item inventory. 
The item inventory information is kept in a sequentially allocated table with a given size of entries (default 
size is TBL_SZ = 31).

The key field is the item identifier, which is two uppercase letters followed by a decimal digit (e.g., AD5 or XR8). 
The desc field contains the item description, and the num field contains the number of items in the inventory. The item 
table can be accessed directly using the linear probing technique to resolve collisions. The private hash function expects
the key of an item as the input argument and returns an integer in the range: 0 … (TBL_SZ − 1), and it has the following
prototype: int HT :: hash ( const string& ). The object file hash.o, which is in the same directory with the header file 
Entry.h, contains the implementation of this function.
