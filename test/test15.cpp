#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;

int main(){
    vector<int> nums{-1,0,1,2,-1,-4};
    Solution s;
    vector<vector<int>> test = s.threeSum_q15(nums);
    printMatrix(test);
    return 0;
}