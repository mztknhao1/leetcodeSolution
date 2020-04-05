/*
 * @Author: your name
 * @Date: 2019-12-08 13:15:04
 * @LastEditTime: 2020-03-29 21:05:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcodeSolution/include/greedy.h
 */
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

int lastStoneWeight_q1046(vector<int>& stones);

/**
 * @description: Dijkstra算法，解决最短路问题
 * @param edge,每个vector<int>都含有i,j,weight
 * @param numVertex,代表总共有多少个顶点
 * @param object, 代表目标的顶点编号，这里默认从编号0的顶点开始
 * @return: 返回从顶点0到object的最短路径长度
 */
int Dijkstra(vector<vector<int>>& edge,int numVertex,int object);
#endif