// //Group Anagrams.cpp
//
// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:
//
// All inputs will be in lowercase.
// The order of your output does not matter.

#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:

    //You can speed it up by using hashing i.e. each string in strs will have a unique        //hash iff the two words are not an anagram.and the hashing function should return a     //unique id that you will use as a key for the map. that way you dont need to sort.
 //

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string> > cache;
        string temp1;
        for(int i=0; i<strs.size();i++){
            temp1 = strs[i];
            sort(temp1.begin(),temp1.end());
            cache[temp1].push_back(strs[i]);
        }
        unordered_map<string,vector<string>>::iterator it = cache.begin();
        vector<vector<string>> to_ret;
        while(it != cache.end()){
            to_ret.push_back(it->second); it++;
        }

        return to_ret;
    }


    // solution below is too slow...
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> to_ret;
        string t1; string t2;
        for(int i=0;i<strs.size();i++){
            t1 = strs[i]; if(t1 == "*") continue;
            vector<string>temp;
            for(int j=i;j<strs.size();j++){
                t2 = strs[j];
                if(t2 == "*") continue;
                if(ana(t1,t2)){
                    temp.push_back(t2);
                    if(j == strs.size()-1) strs.pop_back();
                    strs[i] = "*"; strs[j] = "*";
                }
            }
            to_ret.push_back(temp);
        }
        return to_ret;



    }

    bool ana(string s1, string s2){
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1==s2) return true;
        return false;
    }


    bool ana(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int size = s2.size();
        char temp1;
        for(int i=0;i<s1.size();i++){
            temp1 = s1[i];
            if(s2.size() ==0) return false;
            for(int j=0;j<s2.size();j++){
                if(temp1 == s2[j]){
                    if(j == s2.size()-1){size--;s2.pop_back();break;}
                    s2[j] = '*';size--;break;
                }
                if(j==s2.size()-1) return false;
            }
        }
        if(size ==0) return true;
        return false;
    }
    */
};
