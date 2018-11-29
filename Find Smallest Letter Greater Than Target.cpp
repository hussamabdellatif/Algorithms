// //Find Smallest Letter Greater Than Target.cpp
// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target,
// find the smallest element in the list that is larger than the given target.
//
// Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.
//
// Input:
// letters = ["c", "f", "j"]
// target = "a"
// Output: "c"


#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int t = target;
        if(target == 'z') t = 96; //for wrap around
        if(target >= letters[letters.size()-1]) return letters[0];
        int l=0; int r=letters.size(); int mid = (r-l)/2;

        while(l<r && mid > 0){
            if(letters[mid] > t){
                if(mid-1 >= 0 && letters[mid-1] <= t) return letters[mid];
                if(mid-1 == l) return letters[mid-1];
                r = mid;
            }else if(letters[mid] <= t){
                if(mid+1<letters.size() && letters[mid+1] > t) return letters[mid+1];
                l = mid +1;
            }
            mid = (r-l)/2;
            if(mid<r || mid <l){
                for(int i=min(l,r); i<max(l,r); i++) if(letters[i]>t) return letters[i];
            }
        }

        return letters[mid];

    }
};
