/*
 * @Author: your name
 * @Date: 2019-12-16 16:08:50
 * @LastEditTime: 2020-03-15 17:34:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcodeSolution/SolutionSrc/bfs.cpp
 */
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

int maxAreaOfIsland_q695(vector<vector<int>>& grid) {
    if(grid.size()==0) return 0;
    int max_area = 0;
    // 从1出发查看连通的个数，广度优先
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> g_visited(m,vector<bool>(n,false));
    queue<vector<int>> q;

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(g_visited[i][j] == false && grid[i][j]==1){
                vector<int> pos = {0,0};
                pos[0] = i;
                pos[1] = j;
                int tmp=0;
                q.push(pos);
                g_visited[i][j]=true;
                while(!q.empty()){
                    vector<int> p = q.front();
                    int i=p[0],j=p[1];
                    //上
                    if(i-1>=0 && grid[i-1][j]==1 && g_visited[i-1][j]==false)
                     {  p[0]=i-1;p[1]=j;q.push(p);
                        g_visited[i-1][j]=true;}
                    //下
                    if(i+1<m && grid[i+1][j]==1 && g_visited[i+1][j]==false) 
                    {   
                        p[0]=i+1;p[1]=j;q.push(p);
                        g_visited[i+1][j]=true;
                    }
                    //左
                    if(j-1>=0 && grid[i][j-1]==1 && g_visited[i][j-1]==false) 
                    {
                        p[0]=i;p[1]=j-1;q.push(p);
                        g_visited[i][j-1]=true;
                    }
                    //右
                    if(j+1<n && grid[i][j+1]==1 && g_visited[i][j+1]==false) 
                    {
                        p[0]=i;p[1]=j+1;q.push(p);
                        g_visited[i][j+1]=true;}
                    tmp++;                 
                    q.pop();
                }
                max_area = max_area>tmp?max_area:tmp;

            }
            else{
                g_visited[i][j] = true;
                continue;
            }
        }
    }
    return max_area;
}