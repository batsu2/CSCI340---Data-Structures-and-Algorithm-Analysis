/*********************************************************************
   FILE:    binTree.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   10/30/2018

   FUNCTION:   This program contains the definition and implementations
	       of the binTree class, a template for a binary tree
*********************************************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include "/home/cs340/progs/18f/p6/Node.h"

using namespace std;

template<class T> class binTree
{
	public:
	  binTree();
	  unsigned height() const;
	  virtual void insert( const T& );
	  void inorder( void ( * )(const T& ));

	  //RNG
	  typedef enum { left_side, right_side } SIDE;
  	  SIDE rnd ( ) { return rand ( ) % 2 ? right_side : left_side; }

	protected:
	  Node<T>* root;

	private:
	  unsigned height( Node<T>* ) const;
	  void insert( Node<T>*&, const T& );
	  void inorder( Node<T>*, void ( * ) ( const T& ) );

};

/***************************************************************
Method: binTree()

Use: This is the default constructor for the binTree class

Arguments: None

Returns: Nothing
***************************************************************/
template<class T>
binTree<T>::binTree()
{
	root = NULL;
}

/***************************************************************
Method: insert

Use: This is the public version of the insert method which call
     it's private method counterpart

Arguments: 1. newData, a constant refrence to a template data which
	      will be inserted into the binary tree

Returns: Nothing
***************************************************************/
template<class T>
void binTree<T>::insert( const T& newData )
{
	insert( root, newData );
}

/***************************************************************
Method: insert

Use: This is the private version of the insert method which
     randomly inserts dataVal into either the right or left node
     of the root. The value is inserted as the root if the root
     is NULL(empty).

Arguments: 1. N, a pointer to a refrence to a Node template object
	   2. dataVal, a constant refrence to a template data to
	      be inserted into the binary tree

Returns: Nothing
***************************************************************/
template<class T>
void binTree<T>::insert( Node<T>*& N, const T& dataVal)
{
	if( N == NULL ) // If tree is empty
	{
		Node<T>* newNode;
		newNode = new Node<T>( dataVal );
		N = newNode;
	}
	else
	{
		SIDE s = rnd();

	   //Randomly choose which side to insert into
		if( s == left_side )
		  insert( N->left, dataVal );
		else
		  insert( N->right, dataVal );
	}

}

/***************************************************************
Method: inorder

Use: This is the public version of the inorder method which calls
     it's private method counterpart

Arguments: 1. (*func)(const T& ), a pointer to a function to be
              passed to the private inorder method

Returns: Nothing
***************************************************************/
template<class T>
void binTree<T>::inorder( void ( *func )( const T& ))
{
	inorder( root, func );
}

/***************************************************************
Method: inorder

Use: This is the private version of the inorder method. It traverses
     through a binary tree in the 'inorder' style

Arguments: 1. root, a pointer to a Node template object to act as
	      the starting point of the inorder traversal
	   2. (*func)(const T& ), a pointer to a function used
	      to instantiate upon a binary tree's data

Returns: Nothing
***************************************************************/
template<class T>
void binTree<T>::inorder( Node<T>* N, void (*func)( const T& ))
{
	if ( N != NULL )
	 {
           inorder(N->left, func );
	   func(N->data);
           inorder(N->right, func );
         }
}

/***************************************************************
Method: height

Use: This is the public version of the height method which calls
     its private method counterpart

Arguments: None

Returns: An unsigned value representing the max depth or "height"
         of the tree
***************************************************************/
template<class T>
unsigned binTree<T>::height()const
{
	return height( root );
}

/***************************************************************
Method: height

Use: This method recursevely travels through a binary tree to
     count the "height" of the tree

Arguments: 1. N, a pointer to a Node template object which acts
	      as an initial starting point of the tree

Returns: unsigned values lDepth+1 if the left subtree is larger or
         rDepth+1 if the right subtree is larger
***************************************************************/
template<class T>
unsigned binTree<T>::height( Node<T>* N )const
{
   if ( N == NULL ) // If tree is empty
       return 0;
   else
   {
       // count depth of each subtree
       unsigned lDepth = height(N->left);
       unsigned rDepth = height(N->right);

       // use the larger one, adding 1 (because of root)
       if (lDepth > rDepth)
           return(lDepth+1);
       else
	   return(rDepth+1);
   }
}


#endif

