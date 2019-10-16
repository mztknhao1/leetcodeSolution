#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;


int main(){
    Solution s;
    vector<int> nums1{-1,3,2,0};
    vector<int> m = s.findDuplicates_q442(nums1);
    //bool pattern = s.find132pattern_q456(nums1);
    printVector(m);
    return 0;
}