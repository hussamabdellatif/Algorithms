// //Construct Binary Tree from Preorder and Inorder Traversal.cpp
//
// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7


#include<vector>
#include<iostream>
#include<unordered_map>
#include<cstdio>

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
    vector<int> p;
    vector<int> i;
    unordered_map<int,int> dic;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        p = preorder;
        i = inorder;
        for(int i=0;i<inorder.size();i++) dic[inorder[i]] = i;
        return rec(0,0,preorder.size() -1);
    }
    TreeNode* rec(int id, int start, int end){
        //id is used to look up location of root in inorder;
        if(id > i.size()-1 || start > end) return nullptr;
        int value = p[id];
        int index = dic[value]; //now index has the location of root corresponding to inorder vector
        TreeNode* cur = new TreeNode(value);
        cur->left  = rec(id + 1,start,index-1);
        cur->right = rec(id + index-start + 1, index+1, end);
        return cur;



    }




};
