#include "my_sort.h"

void quickSort(vector<int>& nums){
    
}

void insertSort(vector<int>& nums){
    int size = nums.size();
    if(size<=1) return;
    for(int j=1;j<size;j++){
        //插入排序，左边总是排好序的
        //这次插入第j张牌
        int key = nums[j];
        //从0...j-1已经排好序的数组
        int i = j-1;
        while(i>=0 && key<nums[i]){
            nums[i+1] = nums[i];
            i--;
        }
        nums[i+1] = key;
    }
}