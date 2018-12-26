#include <iostream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    TreeNode* invertTree(TreeNode* root) {
        rec(&(*root));
        return root;
    }
    void rec(TreeNode* root){
        if(!root) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        rec(root->left);
        rec(root->right);
    }
};
