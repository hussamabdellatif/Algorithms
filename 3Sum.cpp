// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]


#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;


auto io_speed_up =[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>to_ret;

        for(int i=0;i<nums.size();i++){
            //if(nums[i] > 0) break;
            if(i > 0){
                if(nums[i] == nums[i-1]) continue;
            }
            int left_index = i+1;
            int right_index = nums.size()-1;
            while(left_index<right_index){
                int sum = nums[i] + nums[left_index] + nums[right_index];
                if(!sum){
                    vector<int> temp = {nums[i],nums[left_index],nums[right_index] };
                    to_ret.push_back(temp);
                    while(nums[left_index] == nums[left_index+1]) left_index++;
                    while(nums[right_index] == nums[right_index-1]) right_index--;
                    left_index++;right_index--;
                }
                if(sum > 0) right_index--;
                if(sum < 0) left_index++;
            }


        }

        return to_ret;

    }
};
