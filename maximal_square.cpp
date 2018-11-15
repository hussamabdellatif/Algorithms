#include <cstdio>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() ) return 0;

        int r = matrix.size() ;
        int c = matrix[0].size();
        int m_area = 0;
        int l_area = 0;

        bool found = true;
        for(int j=0;j<matrix[0].size() -1 ;j++){
            for(int i=0;i<matrix.size() -1;i++){
                if(matrix[i][j] == '1' && m_area == 0) m_area = 1;
                if( (matrix[i][j] == '1')  && (matrix[i+1][j] == '1') ){
                    //found two consecutive ones
                    //is there more consecutive ones?
                    int c_one = 2;
                    for(int x =i+2;x<matrix.size();x++){
                        if(matrix[x][j] == '1') c_one++;
                        if(matrix[x][j] != '1') break;
                    }
                    //check if it forms a square
                    while(c_one >=2){
                        for(int z = i; z<i+c_one; z++){
                            for(int b = j+1; b<j+c_one;b++){
                                if( matrix[z][b] != '1') found = false;
                            }
                        }
                        l_area = c_one * c_one;
                        if(found) m_area = (m_area>l_area) ? m_area:l_area;
                        l_area = 0;
                        c_one --;
                        found = true;
                    }
                }
            }

        }
        if( m_area == 0){
        for(int i=0; i<r && m_area ==0 ;i++){
            for(int j=0;j<c && m_area ==0 ;j++){
                if(matrix[i][j] == '1') m_area = 1;
            }
        }
        }
        return m_area;



    }
};
