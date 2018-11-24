
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int height_left = 0; int height_right = 0;
        TreeNode* left; TreeNode* right;
        left = root; right = root;
        while(left){height_left++; left = left->left;}
        while(right){height_right++; right = right->right;}
        if(height_left == height_right) return pow(2,height_left) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
        //return rec(root, temp);
    }


};
