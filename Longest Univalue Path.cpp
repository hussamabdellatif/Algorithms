// Given a binary tree, find the length of the longest path where each node in the path has the same value.
// This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.



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
    int ans;

    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        rev(root);
        return ans;

    }

    int rev(TreeNode* root){

        if(!root) return 0;
        int l = rev(root->left);
        int r = rev(root->right);
        int l_max = 0 ; int r_max = 0;
        if(root->left != NULL  && root->left->val  == root->val) l_max = (l+1);
        if(root->right != NULL && root->right->val == root->val) r_max = (r+1);
        ans = max(ans, l_max+r_max);
        return max(l_max,r_max);


    }
};
