// Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.
//
// Return true if and only if we can do this in a way such that the resulting number is a power of 2.
//
//
//
// Example 1:
//
// Input: 1
// Output: true


#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string x = to_string(N);
        vector<int> xx = counter(x);
        vector<int> tt;
        bool ret = false;
        int num = 0;
        for(int i=0;i<31;i++){
           tt = counter(to_string(1<<i));
           for(int i=0;i<tt.size();i++){
               if(xx[i] == tt[i]) num++;
               if(xx[i] != tt[i]) break;
           }
            if(num == xx.size()) return true;
            num = 0;

        }


        return false;
    }

    vector<int> counter(string x){
        vector<int> arr(10,0);
        for(int i=0;i<x.size();i++){
            int temp = x[i] - '0';
            arr[temp]++;
            //cout<<arr[temp]<<endl;
        }
        return arr;
    }

};
