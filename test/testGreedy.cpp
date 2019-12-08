#include "greedy.h"

int main(){
    vector<int> cost = {259,770};
    vector<vector<int>> costs;
    costs.push_back(cost);
    cost[0] = 448;
    cost[1] = 54;
    costs.push_back(cost);
    cost[0] = 926;
    cost[1] = 667;
    costs.push_back(cost);
    cost[0] = 184;
    cost[1] = 139;
    costs.push_back(cost);
    cost[0] = 840;
    cost[1] = 118;
    costs.push_back(cost);
    cost[0] = 577;
    cost[1] = 469;
    costs.push_back(cost);
    int result = twoCitySchedCost_q1029(costs);
    return 0;
}