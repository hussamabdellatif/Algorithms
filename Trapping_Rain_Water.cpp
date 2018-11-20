// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
// 
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6



#include <vector>
#include <cstdio>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int index = 0;
        int temp_finder;
        bool found_bigger = false;
        bool found_less = false;
        int my_height = 0;
        int area = 0;
        //bool first_find = false;
        int next_next = 0;
        int height_next = 0;
        while(index<size){
            if(height[index] == 0){
                index++;
                continue;
            }
            my_height = height[index];
            temp_finder = index+1;
            found_bigger = false;
            found_less = false;
            next_next = 0;
            height_next =0;

            while(!found_bigger && temp_finder<size){
                if(height[temp_finder] >= my_height){
                    found_bigger = true;
                    int temp_area = (my_height*(temp_finder-index-1));
                    if(temp_area <0) {found_bigger = false; temp_finder++; continue;}
                    area+= temp_area;
                    for(int i=index+1;i<temp_finder;i++){
                        area -= height[i];
                    }
                    if(found_bigger){
                        index = temp_finder;
                        break;
                    }
                }
                if(height_next < height[temp_finder]) {
                    height_next = height[temp_finder];
                    next_next = temp_finder;
                }
                temp_finder++;
            }
            if(found_bigger) continue;

            temp_finder = next_next;
            if(!found_bigger && !found_less && temp_finder<size){
                if(height[temp_finder] < my_height){
                    found_less = true;
                    int temp_area = (height[temp_finder]*(temp_finder-index-1));
                    for(int i = index+1;i<temp_finder; i++){
                        temp_area -= height[i];
                        if(temp_area <= 0) break;
                    }
                    if(temp_area > 0){
                        area += temp_area;
                        found_less = true;
                        index = temp_finder;
                    }else{
                        found_less = false;
                    }
                }
            }

            if(found_less) continue;
            index++;
        }
        return area;

    }
};
