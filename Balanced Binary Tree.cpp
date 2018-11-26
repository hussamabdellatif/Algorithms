// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
// a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


#include<iostream>
#include<cmath>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

static int x = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(height(root) > -1) return true;
        return false;
    }

    int height(TreeNode* root){
        if(!root) return 0;
        int l = height(root->left);
        int r = height(root->right);

        if(l==-1 || r==-1) return -1;
        if(abs(l-r) > 1) return -1;

        return max(l,r) +1;
    }

};
