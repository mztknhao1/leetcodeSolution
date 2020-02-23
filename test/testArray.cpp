#include"Solution.h"
#include"utils.h"
#include"array.h"

int main(){
    ArraySolution aS;
    int result;

    //第120题测试
    vector<vector<int>> triagulate_120 = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res_120 = minimumTotal_q120(triagulate_120);

    //第1337题测试
    vector<vector<int>> mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    vector<int> result_q1337 = kWeakestRows_q1337(mat,3);
    
    //第447题测试题
    vector<vector<int>> points_q447 = {{0,0},{1,0},{2,0}};
    int res_447 = numberOfBoomerangs_q447(points_q447);

    //第1260题测试
    vector<vector<int>> grid = {{1},{2},{3},{4},{7},{6},{5}};
    vector<vector<int>> ans_q1260;
    ans_q1260 = shiftGrid_q1260(grid,23);
    printMatrix(ans_q1260);

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

    //第1232题测试
    vector<int> q1232={1,2};
    vector<vector<int>> qnums;
    qnums.push_back(q1232);
    q1232[0] = 2;
    q1232[1] = 3;
    qnums.push_back(q1232);
    q1232[0] = 3;
    q1232[1] = 4;
    qnums.push_back(q1232);    
    q1232[0] = 4;
    q1232[1] = 5;
    qnums.push_back(q1232);
    Solution ss;
    bool resultq1232 = ss.checkStraightLine_q1232(qnums);
    
    

    return 0;
}