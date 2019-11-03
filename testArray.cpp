#include"Solution.h"
#include"utils.h"
#include"array.h"

int main(){
    ArraySolution aS;
    int result;

    //第16题测试
    vector<int> nums = {-1,2,1,-4};
    result = aS.threeSumClosest_q16(nums,0);

    //第11题测试
    vector<int> height = {2,3,4,5,18,17,6};
    int maxArea = aS.maxArea_q11(height);

    

    return 0;
}
