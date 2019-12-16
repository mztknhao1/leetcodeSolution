#ifndef __GREEDY
#define __GREEDY

#include "lib_head.h"

int twoCitySchedCost_q1029(vector<vector<int>>& costs);


int BFPRT_q973(vector<vector<int>>& points3D, int left, int right, int k);
int insertSort_q973(vector<vector<int>>& points3D,int left,int right);
void swap_q973(vector<vector<int>>& points3D,int a,int b);
int getPivotIndex_q973(vector<vector<int>>& points3D, int left, int right);
int partition_q973(vector<vector<int>>& points3D, int left,int right, int pivotIndex);
vector<vector<int>> kClosest_q973(vector<vector<int>>& points, int K);

#endif