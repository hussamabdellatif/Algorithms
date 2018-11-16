//Binary_Tree_Level_Order_Traversal_store_in_multidimensional_array.cpp
#include<cstdio>
#include<vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> x;
        if(!root) return x;
        int index =0;
        rec(root, &x, index);
        for(int i=x.size()-1;i>0;i--){
            if(!x[i].empty()) break;
            x.erase(x.begin()+i);
        }
        return x;
    }

    void rec(TreeNode* root, vector<vector<int>>* vec, int index){
        if(!root) return;
        index++;
        rec(root->left, vec, index);
        rec(root->right, vec, index);
        if(index > vec->size()){
            for(int i=0; i<index;i++){
                vec->push_back(vector<int>());
            }
        }
        vec[0][index-1].push_back(root->val);
        index--;
    }

};
