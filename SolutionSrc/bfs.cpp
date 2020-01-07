#include "bfs.h"

char nextGreatestLetter_744(vector<char>& letters, char target){
    int min = 60;
    int flag = 0;
    for(auto c:letters){
        int tmp;
        if(c-target>0){
            if(c-target<min){
                min = c-target;
                flag = 0;
            }
        }else if(c-target<0){
            if(c-target+26<min){
                min = c-target+26;
                flag=1;
            }
        }
    }
    return flag?target+min-26:target+min;
}


//找到所有陆地从陆地出发，BFS找到最近的海洋，将路过的海洋标记为1
int maxDistance_q1162(vector<vector<int>>& grid){
    const int dire[5] = {0,1,0,-1,0};

    //找到所有的陆地放进队列中
    queue<pair<int,int>> q;
    int N = grid.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==1){

            }
        }
    }     
}