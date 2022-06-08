For this computer assignment, I wrote and implement an interactive C++ program to scan and process a stream of words of a plain text.

The program starts with an empty list of words. (Combinations of blanks, tabs, and newline characters to separate words.) After reading 
each word from the input stream, the program does the following:

Checks the word for punctuation marks. If the first letter of the word is preceded or its last letter is followed by punctuation marks, deletes them from 
the word; however, if a word contains punctuation marks in the middle, ignores the letters beyond these punctuation marks. 

For example, if the word is fish, then the resulting word should be fish; however, if the word is fish_net then the resulting word should still be fish.
