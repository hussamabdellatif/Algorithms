// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:
//
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
// Follow up:
//
// What if the given array is already sorted? How would you optimize your algorithm?
// ANSWER: I would iterate on a tight bound rather than the entier array
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// Answer: I would check only if nums1's values exist in nums2.




#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return intersect(nums2, nums1);
        vector<int>inter;
        if(nums1.empty() || nums2.empty()) return inter;
        int garbage = INT_MIN/1000;
        for(int i=0;i<nums1.size();i++){
           for(int j=0;j<nums2.size();j++){
               if(nums1[i] == nums2[j]){
                   nums2[j] = garbage;
                   inter.push_back(nums1[i]);
                   break;
               }
               if(inter.size() == nums1.size()) break;
           }
        }
        return inter;
    }
};
