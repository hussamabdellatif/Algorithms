//Given a binary tree, you need to compute the length of the diameter of the tree.
//The diameter of a binary tree is the length of the longest path between any
//two nodes in a tree. This path may or may not pass through the root.

#include<cstdio>
#include<cmath>

using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int di = 0;
        rev(root,&di);
        return di;
    }

    int rev(TreeNode* root, int* d){
        if(root == NULL)return 0;
        int l = rev(root->left,d);
        int r = rev(root->right,d);
        *d = (l+r > *d) ? l+r : *d;
        return max(l,r)+1;
    }



};
