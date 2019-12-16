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

//寻找最近的k个数
int BFPRT(vector<int>& nums,int left,int right, int k);   //求第k小，返回其下标
int getPivotIndex(vector<int>& nums, int left, int right);  //寻找nums[left]-nums[right]的中位数，返回索引
int insertSort(vector<int>& nums, int left, int right);     //插入排序，返回中位数索引
int partition(vector<int>& nums, int left, int right, int pivotIndex);  //利用中位数的下表进行排序，返回分界的下标

//原地对代表三种颜色的数组排序
void sortColor_q75(vector<int>& nums);


#endif