// There are 1000 buckets, one and only one of them contains poison, the rest are filled with water.
// They all look the same. If a pig drinks that poison it will die within 15 minutes.
// What is the minimum amount of pigs you need to figure out which bucket contains the poison within one hour.
//
// Answer this question, and write an algorithm for the follow-up general case.
//
// Follow-up:
// 
// If there are n buckets and a pig drinking poison will die within m minutes,
//  how many pigs (x) you need to figure out the "poison" bucket within p minutes?
//  There is exact one bucket with poison.


#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;




class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //think of it as a 2d matrix
        // one pig checks column
        //one pig checks row
        int pigs = 0 ;
        while(equation(minutesToTest,minutesToDie, pigs) < buckets){
            pigs++;
        }

        return pigs;
    }

    int equation(int t_time, int session, int pigs){
        return  pow(floor(t_time/session) + 1, pigs);
    }
};
