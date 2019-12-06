#include "greedy.h"
#include "utils.h"

using std::min;

int twoCitySchedCost_q1029(vector<vector<int>>& costs){
    //先对cost进行排序，根据该人去A城-去B城费用最小者排序
    std::sort(costs.begin(),costs.end(),[](vector<int> a, vector<int> b){return a[0]-a[1]<b[0]-b[1];});
    // printMatrix(costs);

    int totalCost=0;
    int N = costs.size()/2;
    for(int i=0;i<N;i++){
        totalCost += costs[i][0];
    }
    for(int i=N;i<2*N;i++){
        totalCost += costs[i][1];
    }
    
    return totalCost;    
}