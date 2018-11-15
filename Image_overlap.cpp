#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:


    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {



        vector<int> flat_A;
        vector<int> flat_B;
        for(int i =0 ;i<B.size(); i++){
            for(int j=0;j<B[0].size();j++){
                flat_A.push_back(A[i][j]);
                flat_B.push_back(B[i][j]);
            }
        }

        bool condition = true;
       // std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
        int max = 0;
        int l_max = 0;

       for(int i=0; i<flat_A.size();i++){
           for(int j=0;j<flat_A.size();j++){
               if(flat_A[j] & flat_B[j] == 1) l_max++;
           }
           max = (max > l_max) ? max:l_max;
           l_max = 0;
           rotate(flat_A.begin(), flat_A.begin() +1 , flat_A.end());

       }


        return max;


    }

};
