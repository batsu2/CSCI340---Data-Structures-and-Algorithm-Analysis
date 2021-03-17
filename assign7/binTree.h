/*********************************************************************
   FILE:    binTree.h
   PROGRAMMER: Bryan Butz
   LOGON ID:   z1836033
   DUE DATE:   11/8/2018

   FUNCTION:   This program contains the definition and implementations
	       of the binTree class, a template for a binary tree
*********************************************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include "/home/cs340/progs/18f/p7/Node.h"

using namespace std;

template<class T> class binTree
{
	public:
	  binTree();
	  unsigned height()const;
	  virtual void insert( const T& );
	  int size ( ) const; // returns no of nodes
	  void inorder( void ( * )( T& ));

	protected:
	  Node<T>* root;

	private:
	  unsigned height( Node<T>* )const;
	  void insert( Node<T>*&, const T& );
	  int size( Node <T>* )const;
	  void inorder( Node<T>*, void ( * ) ( T& ) );

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
     inserts dataVal into either the right or left node of the
     root. The value is inserted as the root if the root is NULL(empty).

Arguments: 1. N, a pointer to a refrence to a Node template object
	   2. dataVal, a constant refrence to a template data to
	      be inserted into the binary tree

Returns: Nothing
***************************************************************/
template<class T>
void binTree<T>::insert( Node<T>*& p, const T& dataVal)
{
		if( p == 0 )
	{
		Node<T>* newNode;
		newNode = new Node<T>( dataVal ); // new node with new value
		p = newNode; // set ptr to new node
	}
	else
	{
		int lHeight = height( p->left );
		int rHeight = height( p->right );

		if( lHeight <= rHeight )
		{
			insert( p->left, dataVal );
		}
		else
		{
			insert( p->right, dataVal );
		}
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
void binTree<T>::inorder( void ( *func )( T& ))
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
void binTree<T>::inorder( Node<T>* node, void (*func)( T& ))
{
	if ( node != NULL )
	 {
           inorder(node->left, func );
	   func(node->data);
           inorder(node->right, func );
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
unsigned binTree<T>::height( Node<T>* Node )const
{
   if ( Node == NULL ) // If tree is empty
       return 0;
   else
   {
       // count depth of each subtree
       unsigned lDepth = height(Node->left);
       unsigned rDepth = height(Node->right);

       // use the larger one, adding 1 (because of root)
       if (lDepth > rDepth)
           return(lDepth+1);
       else
	   return(rDepth+1);
   }
}

// returns no of nodes
template <class T>
int binTree <T>::size( ) const
{
    return size( root ); // call recursive
}

// private version of size
template <class T>
int binTree <T>::size( Node <T>* ptr ) const
{
	if( ptr != 0 ) // if not empty
	{
	  return 1 + size( ptr->left ) + size( ptr->right );
	}
	else
	{
	  return 0; // emtpy tree
	}
}


#endif

