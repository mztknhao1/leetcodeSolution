#ifndef __MYSORT
#define __MYSORT

#include"utils.h"
#include"lib_head.h"

using std::vector;

//快速排序算法
void quickSort(vector<int>& nums);
void quickSortSub(vector<int>& nums,int begin,int end);

//插入排序
void insertSort(vector<int>& nums);

//堆排序
void heepSort(vector<int>& nums);
void sink(vector<int>& nums,int begin, int end);

//帮助函数
void swap(vector<int>& nums, int a, int b);

#endif