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


//这个题就是寻找K临近的点，Top-K问题最有效的方法是BFPRT方法
//可以考虑实际上可以用最简单的快速排序
//也可以用k大小的堆排序，尽量多实现几种方法来对比
vector<vector<int>> kClosest_q973(vector<vector<int>>& points, int K){
    #define _BFPRT
    
    #ifdef _BFPRT
    
    //先计算每个点到原点的距离，作为该坐标点的第三维数据
    for(int i=0;i<points.size();i++){
        points[i].push_back(points[i][0]*points[i][0]+points[i][1]*points[i][1]);
    }
    //使用BFPRT方法对该点的第三维属性值进行Top-k排序
    BFPRT_q973(points,0,points.size()-1,K);

    //将结果保存在result中，返回
    vector<vector<int>> result;
    for(int i=0;i<K;i++){
        vector<int> tmp = {points[i][0],points[i][1]};
        result.push_back(tmp);
    }
    return result;

    #endif   
}

int BFPRT_q973(vector<vector<int>>& points3D, int left, int right, int k){
    int pvoit_index = getPivotIndex_q973(points3D,left,right);
    int divide_index = partition_q973(points3D,left, right,pvoit_index);
    int num = divide_index - left + 1;
    if(num == k) 
        return num;
    else if(num > k)
        return BFPRT_q973(points3D,left,divide_index-1,k);
    else
        return BFPRT_q973(points3D,divide_index+1, right, k-num);    
}


int insertSort_q973(vector<vector<int>>& points3D,int left,int right){
    if(left>right) return 0;
    int j=left+1;
    for(;j<=right;j++){
        vector<int> tmp = points3D[j];      //将第j张牌插入到牌堆中
        int i=j-1;
        while(i>=left&&tmp[2]<points3D[i][2]){
            points3D[i+1] = points3D[i];
            i--;
        }
        points3D[i+1] = tmp;
    }
    int mid = (right-left)/2+left;
    return mid;
}
void swap_q973(vector<vector<int>>& points3D,int a,int b){
    vector<int> tmp = points3D[a];
    points3D[a] = points3D[b];
    points3D[b] = tmp;
}

int getPivotIndex_q973(vector<vector<int>>& points3D, int left, int right){
    if(right-left<5) return insertSort_q973(points3D,left,right);
    int sub_right = left-1;
    for(int i=left;(i+4)<=right;i+=5){
        int index = insertSort_q973(points3D,i,i+4);
        swap_q973(points3D,++sub_right,index);
    }
    int sub_k = (sub_right-left+1)/2 + 1;
    return BFPRT_q973(points3D,left,sub_right,sub_k);
}


int partition_q973(vector<vector<int>>& points3D, int left,int right, int pivotIndex){
    swap_q973(points3D,pivotIndex,right);
    int divide_index = left;
    for(int i=left;i<right;i++){
        if(points3D[i][2]<=points3D[right][2]){
            swap_q973(points3D,i,divide_index++);
        }
    }
    swap_q973(points3D,divide_index,right);
    return divide_index;
}


int lastStoneWeight_q1046(vector<int>& stones){
    int len = stones.size();
    if(len==1) return stones[0];
    sort(stones.begin(),stones.end(), [](int a,int b){return a>b;});
    for(int i=0,j=1;j<len;){
        if(stones[j]==stones[i]){
            if(j+2==len) return stones[len-1];
            if(j+1==len) return 0;
            i = i+2;
            j = j+2; 
        }else{
            int tmp = stones[i] - stones[j];
            int t=j+1;
            if(t==len) stones.push_back(tmp);
            else {
                while(t<len&&tmp<stones[t]){
                    t++;
                }
                if(t==len) stones.push_back(tmp);
                else stones.insert(stones.begin()+t,tmp);
            }
            stones.insert(stones.begin()+t,tmp);
            len++;
            i+=2;
            j+=2;
            if(j==len) return stones[len-1];
        }  
    }
    return 0;
}

int Dijkstra(vector<vector<int>>& edge,int numVertex,int object){
    // 将顶点分为两个集合：一个是已知最短距离的集合，一个是未知最短距离的集合
    // 使用vector<int> book来记录是否已经确定过最短距离
    vector<int> book(numVertex,INT32_MAX);


    // 用numVertex * numVertex大小的二维数组记录两个边之间的距离
    vector<vector<int>> edges(numVertex,vector<int>(numVertex,INT32_MAX));
    // 使用输入的edge来初始化
    for(auto e:edge){
        int i = e[0];
        int j = e[1];
        int d = e[2];
        if(edges[i][j]>d) edges[i][j]=d;
        edges[j][i] = edges[i][j];
    }

    //对所有自己本身赋值为0
    for(int i=0;i<numVertex;i++){
        edges[i][i] = 0;
    }

    // 目前为止只有源节点确定最短路径为0
    book[0] = 1;

    // dist存储的是到达第0个顶点，其他点所需要的距离
    vector<int> dist(numVertex,INT32_MAX);
    for(int i=1;i<numVertex;i++){
        dist[i] = edges[0][i];
    }

    // 好吧，看似懂了，其实没懂，还是要去理解一下算法原理
    // 遍历所有已经确定的节点
    for(int i=0;i<numVertex;i++){
        // 从直接就能到达节点i的顶点中，找到最小的那个加入到book中，并把dist更新一下
        int u;
        int min = INT32_MAX;
        // 这个过程就是找已经确定最短距离的点的下一个最短距离点，第一次进来，那就是源节点0，找下一个点
        for(int j=0;j<numVertex;j++){
            if(!book[u] && dist[j]<min){
                min = dist[j];
                u = j;
            }
        }
        book[u] = 1;
    }

}