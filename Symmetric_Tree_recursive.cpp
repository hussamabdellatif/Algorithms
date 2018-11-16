// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following [1,2,2,null,3,null,3] is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3
// Note:
// Bonus points if you could solve it both recursively and iteratively.
#include <cstdio>
#include <vector>
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

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        vector<int> v1;
        vector<int> v2;
        v1.push_back(root->val);
        v2.push_back(root->val);
        rec_left(root->left, &v1);
        rec_right(root->right, &v2);
        for(int i=0;i<v1.size();i++){
           cout<<v1[i]<< " ";
        }
        cout<<"\n"<<endl;
        for(int i=0;i<v1.size();i++){
            cout<<v2[i]<< " ";
        }
        if(v1.size() != v2.size()) return false;
        for(int i=0;i<v1.size();i++){
            if(v1[i] != v2[i]) return false;
        }


        return true;
    }

    void rec_left(TreeNode* root, vector<int>* vec){
        if(!root){
            vec->push_back(NULL);
            return;
        }
        vec->push_back(root->val);
        rec_left(root->left, vec);
        rec_left(root->right, vec);
    }
    void rec_right(TreeNode* root, vector<int>* vec){
        if(!root){
            vec->push_back(NULL);
            return;
        }
        vec->push_back(root->val);
        rec_right(root->right, vec);
        rec_right(root->left, vec);
    }

};
