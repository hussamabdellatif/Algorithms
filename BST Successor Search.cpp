// BST Successor Search
// In a Binary Search Tree (BST), an Inorder Successor of a node is defined as the node with the
// smallest key greater than the key of the input node (see examples below).
// Given a node inputNode in a BST, you’re asked to write a function findInOrderSuccessor
// that returns the Inorder Successor of inputNode. If inputNode has no Inorder Successor, return null.



#include <iostream>

using namespace std;

struct Node
{
   int key;
   Node *left;
   Node *right;
   Node *parent;
};

// Helper function that allocates a new Node
Node* newNode( int key )
{
   Node* n = new Node;
   n->key = key;
   n->left = nullptr;
   n->right = nullptr;
   n->parent = nullptr;

   return n;
}

//  Given a binary search tree and a number, inserts a new Node with
//  the given number in the correct place in the tree. Returns the new
//  root pointer which the caller should then use
Node *insert( Node *root, int key )
{
   // 1) If the tree is empty, return a new single Node
   if( root == nullptr )
      return newNode( key );

   Node *temp;

   // 2) Otherwise, recur down the tree
   if( key < root->key )
   {
      temp = insert( root->left, key );
      root->left = temp;
      temp->parent = root;
   } else
   {
      temp = insert( root->right, key );
      root->right = temp;
      temp->parent = root;
   }

   // Return the (unchanged) Node pointer
   return root;
}

// Return a pointer to a Node in the BST by its key.
// Use this fuction when you need a Node to test your
// findInOrderSuccessor function on
Node *getNodeByKey( Node *root, int key )
{
   Node *currentNode = root;

   while( currentNode )
   {
      if( key == currentNode->key )
         return currentNode;

      if( key < currentNode->key )
         currentNode = currentNode->left;
      else
         currentNode = currentNode->right;
   }

   return nullptr;
}

Node* find_min_right(Node *cur){
// return the node with minimum key in the right subtree
  Node* temp = cur;
  while(temp->left != NULL){temp = temp->left;}
  return temp;
}

Node* findInOrderSuccessor( Node *inputNode )
{

  if(inputNode->right != NULL) return find_min_right(inputNode->right);

  Node* ancestor = inputNode->parent;
  Node* child = inputNode;

  while(ancestor != NULL && child==ancestor->right){
    child = ancestor;
    ancestor = child->parent;
  }

  return ancestor;


}





int main() {
  Node* root = newNode(20);
  insert(root, 25);
  insert(root, 9);
  insert(root, 12);
  insert(root, 14);
  insert(root, 11);
  insert(root, 5);


 Node* temp = getNodeByKey( root, 14);
 cout<<findInOrderSuccessor(temp)->key<<endl;


}
