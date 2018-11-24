// You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.
//
// Given n, find the total number of full staircase rows that can be formed.
//
// n is a non-negative integer and fits within the range of a 32-bit signed integer.
//
// Example 1:
//
// n = 5
//
// The coins can form the following rows:
// ¤
// ¤ ¤
// ¤ ¤
//
// Because the 3rd row is incomplete, we return 2.



#include <cstdio>
#include <algorithm>
#include<iostream>
#include <cmath>
using namespace std;


static int x = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    int arrangeCoins(int n) {

        /*
        int rows = 0;

        while(n>0){
            if(n - (rows) > 0){
                rows++;
                n = n-rows;
            }else{
                break;
            }

        }
        */

        if(n<=0) return 0;
        return floor(0.5*(sqrt(1+8*(long)n)-1));

    }


};
