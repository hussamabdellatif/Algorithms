//card_flipping_game.cpp

// On a table are N cards, with a positive integer printed on the front and back of each card (possibly different).
//
// We flip any number of cards, and after we choose one card.
//
// If the number X on the back of the chosen card is not on the front of any card, then this number X is good.
//
// What is the smallest number that is good?  If no number is good, output 0.
//
// Here, fronts[i] and backs[i] represent the number on the front and back of card i.
//
// A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa.
//
// Example:
//
// Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3]
// Output: 2
// Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3].
// We choose the second card, which has number 2 on the back, and it isn't on the front of any card, so 2 is good.



#include<cstdio>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>

using namespace std;

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_map<int,int>common;
        for(int i=0;i<fronts.size();i++) if(fronts[i] == backs[i]) common[fronts[i]] = -1;
        int min = INT_MAX;
        for(int i=0; i<fronts.size();i++) if(common[fronts[i]]!=-1) min = (min<fronts[i]) ? min:fronts[i];
        for(int j=0; j<backs.size();j++) if(common[backs[j]]!=-1) min = (min<backs[j]) ? min:backs[j];
        if(min == INT_MAX) return 0;
        return min;

    }
};
