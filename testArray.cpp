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

    //第31题测试
    vector<int> nums_31 = {1,2,5,5,4};
    aS.nextPermutation_q31(nums_31);
    printVector(nums_31);

    

    return 0;
}
