// //Word Search.cpp
//
// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are
// those horizontally or vertically neighboring. The same letter cell may not be used more than once.
//
// Example:
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

#include<string>
#include<cstdio>
#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<char>> board;
    string word;
    int char_next;

    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        this->word = word;
        char_next=0;
        for(int row = 0 ; row<board.size();row++){
            for(int column =0; column<board[0].size();column++){
                if(board[row][column] == word[0]){
                    if(rec(row,column,0)) return true;
                }
            }
        }
        return false;
    }

    bool rec(int i, int j, int index){
        if(index == word.size()) return true;
        if(i<0 || j<0 || i>= board.size() || j>=board[0].size() ) return false;
        if(board[i][j] != word[index]) return false;
        char temp = board[i][j];
        board[i][j] = '*';
        bool checker = rec(i,j+1,index+1) ||
                       rec(i,j-1,index+1) ||
                       rec(i+1,j,index+1) ||
                       rec(i-1,j,index+1);
        board[i][j] = word[index];
        return checker;





    }

};
