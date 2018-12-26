// 423. Reconstruct Original Digits from English
// Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
//
// Note:
// Input contains only lowercase English letters.
// Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
// Input length is less than 50,000.
// Example 1:
// Input: "owoztneoer"
//
// Output: "012"
// Example 2:
// Input: "fviefuro"
//
// Output: "45"

#include <cstdio>
#include<iostream>
#include <vector>
using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string originalDigits(string s) {
        vector<string> strnum = {"zero","one","two","three",
                                 "four","five","six",
                                 "seven","eight","nine"};
        string to_ret;
        int counter = 0;
        std::size_t it; int count = 0; int size = s.size();
        while(count < size && counter < 10){
            string temp = strnum[counter];
            bool found = true;
            for(int i=0;i<temp.size();i++){
                it = s.find_first_of(temp[i]);
                if(it != std::string::npos){
                    s[it] = '*'; size--;
                }else{
                    found = false;
                    s += temp.substr(0,i);
                    break;
                }
            }
            if(found){
                count += temp.size(); size += temp.size();
                to_ret += to_string(counter);
            }else{
                counter++;
            }
            if(count<s.size() && counter == 10) counter =0;
        }
        return to_ret;
    }


};
