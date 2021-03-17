/*********************************************************************
   FILE:    binSTree.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   11/8/2018

   FUNCTION:   This program contains the definition and implementations
               of the binSTree class, a template for a binary search tree
	       as a subclass of binTree, a binary tree
*********************************************************************/

#ifndef BINSTREE_H
#define BINSTREE_H


#include "./binTree.h"

using namespace std;

template <class T>
class binSTree : public binTree<T>
{
	public:
	  void insert ( const T& x ); // inserts node with value x
	  bool search ( const T& x ) const; // searches leaf with value x
	  bool remove ( const T& x ); // removes leaf with value x

	private:
	  void insert ( Node<T>*&, const T& ); // private version of insert
	  bool search ( Node<T>*, const T& ) const;// private version of search
	  void remove ( Node<T>*&, const T& ); // private version of remove
	  bool leaf ( Node<T>* node ) const; // checks if node is leaf
};

/***************************************************************
Method: insert

Use: This is the public version of the insert method for a binary
     search tree which calls its private method counterpart

Arguments: x, A constant refrence to a template type to be inserted

Returns: Nothing
***************************************************************/
template <class T>
void binSTree<T>::insert ( const T& x )
{
	insert( this->root, x );
}

/***************************************************************
Method: search

Use: This is the public version of the search method which calls
     its private method counterpart

Arguments: x, a constant refrence to a template type to be searched
              for within the binary search tree

Returns: A bool value of true if x is found and false if it is
         not found.
***************************************************************/
template <class T>
bool binSTree<T>::search ( const T& x ) const
{
	return search( this->root, x );
}

/***************************************************************
Method: remove

Use: This is the public version of the remove method which checks
     the binary search tree's size and then calls it's private method
     counterpart.

Arguments: x, a constant refrence to a template type value to be
	      removed from the binary search tree

Returns: a bool value of true if the value is removed and false
         if the value was not removed
***************************************************************/
template <class T>
bool binSTree<T>::remove( const T& x )
{

	// Remove lowest value leaf
	if( this->size() >= 1 )
        {
	   if( search( x ) )
	      remove( this->root, x );

	  return true;
	}
	else if( this->size() == 0 )// Remove last leaf
	{
	   this->root = NULL;

	   return false;
	}
	else
	{
	   return false;
	}

}

/***************************************************************
Method: insert

Use: This is the private version of the insert method which inserts
     a template value, v, into a binary search tree

Arguments: n, a refrence to a pointer to a Node template type
	   v, a refrence to a constant template type to be
	      inserted into the tree

Returns: Nothing
***************************************************************/
template <class T>
void binSTree<T>::insert( Node<T>*& n, const T& v )
{
	if(n == NULL) // Tree is empty
	 {
           n = new Node<T>( v );
	 }
    	else if( v < n->data)
	 {
           insert( n->left, v );
	 }
        else if( v > n->data )
	 {
           insert( n->right, v );
	 }
       else
	 {
           return; // duplicate value
	 }
}

/***************************************************************
Method: search

Use: This is the private version of the search method which searches
     through a binary search tree for the leaf value of v

Arguments: n, a pointer to a Node template type
	   v, a refrence to a constant template type value to be
              searched for

Returns: A bool value of true if the search is sucessful and false
         if the search could not find the value v
***************************************************************/
template <class T>
bool binSTree<T>::search( Node <T>* n, const T& v )const
{
    if( n == NULL )
	 return false;
    else
    {
	 // If v is found and is also a leaf
        if( v == n->data )
	{
		if( leaf( n ) )
		    return true;
		else
		   return false;
	}
        else if( v < n->data ) //Recursive call to repeat
	    return search( n->left, v );
        else
            return search( n->right, v );
    }
}

/***************************************************************
Method: remove

Use: This is the private version of the remove method which
     removes the lowest point in the binary search tree when
     called

Arguments: n, a pointer to a Node template type
           v, a refrence to a constant template type value to be
              searched for and removed

Returns: Nothing
***************************************************************/
template <class T>
void binSTree<T>::remove( Node<T>*& n, const T& v )
{

    Node<T>* index;
    Node<T>* parent;
    index = n;

    while( index != NULL )
    {
         if( index->data == v )
         {
            break;
         }
         else
         {
             parent = index;

             if( v > index->data )   //Compare index data with passed in data
		 index = index->right;
             else
		 index = index->left;
         }
    }


	if( n != NULL )
	{
		//Check right and left values of parent
		if( parent->right == index )
		  parent->right = NULL;
		else
		   parent->left = NULL;

		delete index;
		index = NULL;
	}

}

/***************************************************************
Method: leaf

Use: This method returns if a node is a leaf or not.

Arguments: p, a pointer to a Node template type

Returns: A bool value of true if the node is a leaf and false
	 if it is not a leaf
***************************************************************/
template <class T>
bool binSTree<T>::leaf( Node<T>* p )const
{
	if( p->left == NULL && p->right == NULL )
	{
	  return true; // node is a leaf
	}
	else
	{
	  return false; // node is not a leaf
	}
}


#endif
