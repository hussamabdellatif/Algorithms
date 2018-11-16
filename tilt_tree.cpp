// 
// Given a binary tree, return the tilt of the whole tree.
//
// The tilt of a tree node is defined as the absolute difference between the sum of all left subtree node values and the sum of all right subtree node values. Null node has tilt 0.
//
// The tilt of the whole tree is defined as the sum of all nodes' tilt.
//
// Example:
// Input:
//          1
//        /   \
//       2     3
// Output: 1


#include <cstdio>
#include <cmath>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    int findTilt(TreeNode* root) {
        int t = 0;
        rev(root, &t);
        return t;
    }
    int rev(TreeNode* root, int* sum){
        if(!root) return 0;
        int l = rev(root->left, sum);
        int r = rev(root->right, sum);
        *sum += abs(l-r);
        return l + r + root->val;
    }

};
