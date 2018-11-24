// Given a Binary Search Tree and a target number, 
// return true if there exist two elements in the BST such that their sum is equal to the given target.

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        rec(root, &vec);

        int l = 0;
        int r = vec.size() -1;

        while(l<r){
            if(vec[l] > k && vec[r] < k ) return false;
            int sum = vec[l] + vec[r];
            if(sum == k) return true;
            if(sum<k) l++;
            if(sum>k) r--;
        }
        return false;

    }


    void rec(TreeNode* root, vector<int>* vec){
        if(!root) return;
        rec(root->left, vec);
        vec->push_back(root->val);
        rec(root->right, vec);
    }

};
