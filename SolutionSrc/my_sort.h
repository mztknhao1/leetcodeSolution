#ifndef __MYSORT
#define __MYSORT

#include"utils.h"
#include"lib_head.h"

using std::vector;

//首先完成快速排序算法
void quickSort(vector<int>& nums);
void quickSortSub(vector<int>& nums,int begin,int end);
void insertSort(vector<int>& nums);


#endif