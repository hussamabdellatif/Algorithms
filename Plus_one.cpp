// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Example 2:
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int size = digits.size() -1;
        for(int i = size;i>=0;i--){
            if( (digits[i] + 1) > 9){
                 digits[i] = 0;
                 carry = 1;
            }else{
                digits[i] = digits[i] +1;
                carry = 0;
                break;
            }
        }
        if(carry){
            vector<int>digit;
            digit.push_back(1);
            int counter = 0;
            vector<int>::iterator it = digits.begin();
            while(it != digits.end()){
                digit.push_back(digits[counter]);
                counter++;it++;
            }
            return digit;

        }
        return digits;
    }
};
