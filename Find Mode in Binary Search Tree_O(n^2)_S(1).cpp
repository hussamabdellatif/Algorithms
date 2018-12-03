// // Find Mode in Binary Search Tree_O(n^2)_S(1).cpp
//
// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
// For example:
// Given BST [1,null,2,2],
//
//    1
//     \
//      2
//     /
//    2
//
//
// return [2].
//
// Note: If a tree has more than one mode, you can return them in any order.
//
// Follow up: Could you do that without using any extra space? (Assume that the
// implicit stack space incurred due to recursion does not count).

// Find Mode in Binary Search Tree

#include <vector>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    int max; //stores value of most frequent occurance, globally
    int count; //stores the number of time a value has been repeated
    int local_value; //stores current root->value
    vector<int> to_return;

    vector<int> findMode(TreeNode* root) {
        //initalize global variables to zero
        if(!root) return to_return;
        max = 0;
        count = 0;
        local_value =0;
        //use in order traversal: i.e. traverse BST left->root->right;
        inorder(root);
        //now max contains the max number of frequency
        //so we can traverse the tree again
        //if we find any node that has a frequency equal to the max, then this root->val
        //is a mode, and can be added to the to_return vector.
        count = 0;
        local_value =0;
        inorder2(root);
        return to_return;
    }
    //left->root->right
    void inorder(TreeNode* root){
        //recursive approach
        if(!root) return; //base case
        inorder(root->left);//traverse all the way to left
        if(local_value != root->val){
          count = 1; local_value = root->val; //initalizing a new value to count = 1
        }
        else count++; //counting frequency
        max = std::max(count,max); // if count>max, max will equal count
        inorder(root->right); //traverse right
        return;
    }

    void inorder2(TreeNode* root){
        if(!root) return;
        inorder2(root->left);
        if(root->val != local_value){
          count = 1; local_value = root->val;
        }
        else count++;
        if(count == max) to_return.push_back(local_value);
        inorder2(root->right);
        return;
    }

};
