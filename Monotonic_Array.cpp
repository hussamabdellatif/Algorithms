// An array is monotonic if it is either monotone increasing or monotone decreasing.
//
// An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].
//
// Return true if and only if the given array A is monotonic.


#include <vector>
#include <iostream>

using namespace std;


static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    bool isMonotonic(vector<int>& A) {

        for(int i=0; i<A.size()-1;i++){
            if(A[i+1] > A[i]){
                for(int j=i;j<A.size()-1;j++){
                    if(A[j+1] < A[j]) return false;
                }
                break;
            }
            if(A[i+1] < A[i]){
               for(int j=i;j<A.size()-1;j++){
                    if(A[j+1] > A[j]) return false;
                }
                break;
            }
        }
        return true;
    }
};
