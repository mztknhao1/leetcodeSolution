#include "Solution.h"

int main(){
    string command = "URR";
    vector<vector<int>> obstacles;
    vector<int> obs = {2,2};
    obstacles.push_back(obs);
    int x = 3,y = 2;
    Solution s;
    bool ans = s.robot_L3(command,obstacles,x,y);
    return 0;
}