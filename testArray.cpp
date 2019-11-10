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

    //第56题测试
    vector<int> qujian = {2,3};
    vector<vector<int>> qujians;
    qujians.push_back(qujian);
    qujian[0] = 4;
    qujian[1] = 5;
    qujians.push_back(qujian);
    qujian[0] = 6;
    qujian[1] = 7;
    qujians.push_back(qujian);
    qujian[0] = 8;
    qujian[1] = 9;
    qujians.push_back(qujian);
    qujian[0] = 1;
    qujian[1] = 10;
    qujians.push_back(qujian);
    
    vector<vector<int>> result_q56 = aS.merge_q56(qujians);
    printMatrix(result_q56);

    //第217题测试
    vector<int> nums_q217 = {3,3};
    bool re = aS.containDuplicate_q217(nums_q217);

    return 0;
}
