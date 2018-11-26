// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
//
// Example 1:
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5


#include<cstdio>
#include<iostream>

using namespace std;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = 0;
        long c_v = (long) c;

        while(true){
            if(c - b*b < 0) return false;
            if(a*a < c - b*b) a++;
            if(a*a > c - b*b){ b++; a--;}
            if(a*a == c - b*b) return true;
        }
        return false;

    }
};
