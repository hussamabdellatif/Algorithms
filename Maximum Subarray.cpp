// //Maximum Subarray.cpp
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// //Jon Bentley (Sep. 1984 Vol. 27 No. 9 Communications of the ACM P885)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxmax = nums[0]; int maxnotsomax =nums[0];
        for(int i=1; i<nums.size();i++){
            maxnotsomax = max(maxnotsomax+nums[i], nums[i]);
            maxmax      = max(maxmax,maxnotsomax);
        }
        return maxmax;
    }
};
