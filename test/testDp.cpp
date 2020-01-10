#include "lib_head.h"
#include "DP.h"


int main(){
    dpSolution dps;
    vector<int> tmp = {0,1,1,1};
    vector<vector<int>> matrix;
    matrix.push_back(tmp);
    tmp[0] = 1;
    matrix.push_back(tmp);
    tmp[0] = 0;
    matrix.push_back(tmp);
    int ans_1277 = dps.countSquares_q1277(matrix);
    return 0;
}