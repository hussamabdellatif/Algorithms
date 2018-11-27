// //Divide Two Integers.cpp
//
//
// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
// Input: dividend = 10, divisor = 3
// Output: 3
// Example 2:
//
// Input: dividend = 7, divisor = -3
// Output: -2
// Note:
//
// Both dividend and divisor will be 32-bit signed integers.
// The divisor will never be 0.
// Assume we are dealing with an environment which could only store integers
// within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 231 − 1
// when the division result overflows.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor || (dividend == INT_MIN && divisor == -1))return INT_MAX;
        bool neg = false;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0 ){ neg = true; cout<<"hell";}
        long long n = (long) labs(dividend);
        long long d = (long) labs(divisor);
        int temp = 0;
        while(n > 0 && d!=1){
            n = n - d;
            if(n >= 0)temp++;
        }
        if(d==1 && n!=0 ){
            if(neg) return n-(n+n);
            return n;
        }
        if(neg) temp = (temp) - (temp + temp);
        return temp;


    }
};
