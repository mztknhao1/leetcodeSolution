#include "queueS.h"
#include "utils.h"
#include "lib_head.h"
#include <algorithm>

vector<int> queueSolution::pancakeSort_q969(vector<int>& A){
    //煎饼翻转，进行每步两次翻转
    int N = A.size();
    vector<int> result;
    for(int i=N-1;i>0;i--){
        int j = std::max_element(A.begin(),A.begin() + i + 1) - A.begin();
        if(j>0){
            std::reverse(A.begin(), A.begin()+j+1);
            result.push_back(j+1);
        }
        std::reverse(A.begin(),A.begin()+i+1);
        result.push_back(i+1);
        
    }
    return result;
}