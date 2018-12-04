// //Construct Quad Tree.cpp
// We want to use quad trees to store an N x N boolean grid. Each cell in the grid can only be true or false. The root node represents the whole grid. For each node, it will be subdivided into four children nodes until the values in the region it represents are all the same.
//
// Each node has another two boolean attributes : isLeaf and val. isLeaf is true if and only if the node is a leaf node. The val attribute for a leaf node contains the value of the region it represents.
//
// Your task is to use a quad tree to represent a given grid. The following example may help you understand the problem better:
//
// Given the 8 x 8 grid below, we want to construct the corresponding quad tree:
//
//
//
// It can be divided according to the definition above:
//
//
//
//
//
// The corresponding quad tree should be as following, where each node is represented as a (isLeaf, val) pair.
//
// For the non-leaf nodes, val can be arbitrary, so it is represented as *.
//
//
//
// Note:
//
// N is less than 1000 and guaranteened to be a power of 2.
// If you want to know more about the quad tree, you can refer to its wiki.

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    Node* construct(vector<vector<int>>& grid) {
        return rec(0,grid.size()-1,0,grid[0].size()-1,grid);
    }

    Node* rec(int top, int bottom, int left, int right,vector<vector<int>>& grid){
        if(left>right || top > bottom) return nullptr;
        pair<int,int> one_zero = all_ones(top,bottom,left,right,grid) ;
        if(one_zero.first == 1 || one_zero.second == 1 ){
                Node* root = new Node();
                bool to_cmpr = (one_zero.first == 1) ? true:false;
                root = new Node(to_cmpr,true,NULL,NULL,NULL,NULL);
                return root;
        }
        int horizontal_midpoint = (top+bottom)/2;int column_midpoint = (left+right)/2;
        return new Node(false,false,
                       rec(top                  , horizontal_midpoint, left             , column_midpoint,grid),
                       rec(top                  , horizontal_midpoint, column_midpoint+1, right          ,grid),
                       rec(horizontal_midpoint+1, bottom             , left             , column_midpoint,grid),
                       rec(horizontal_midpoint+1, bottom             , column_midpoint+1, right          ,grid) );
        return nullptr;
    }

    pair<int,int> all_ones(int top,int bottom,int left,int right,vector<vector<int>>&grid){
        int n_zeros = 0; int n_ones = 0; int t_iter = 0; pair<int,int>to_ret;
        to_ret.first =0; to_ret.second =0;
        for(int i=top;i<=bottom;i++){
            for(int j=left;j<=right;j++){
                if(grid[i][j] == 0) n_zeros++;
                if(grid[i][j] == 1) n_ones++;
                t_iter++;
                if(n_zeros > 0 && n_ones > 0) return to_ret;
            }
        }
        if(n_zeros == t_iter) to_ret.second=1;
        else if(n_ones == t_iter) to_ret.first = 1;
        return to_ret;

    }
};
