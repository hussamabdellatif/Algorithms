// //Word Break.cpp
//
// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can
// be segmented into a space-separated sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<bool> dic(s.length()-1, false);
        dic[0] = true; //to begin checking with a string of size 1
        vector<string>::iterator it;
        for(int i=1;i<s.length()+1;i++){//here i is used as size of sub_string
            for(int j=0;j<i;j++){//here j acts as starting point of substr
                if(dic[j]){
                    it = find(wordDict.begin(),wordDict.end(),s.substr(j,i-j));
                    if(it != wordDict.end()){
                        //found match
                        dic[i] = true; //update table, so that we shrink or search size
                        break;
                    }
                }
            }
        }
        return dic[s.length()];
    }


};
