#include "my_sort.h"

void quickSort(vector<int>& nums){
    quickSortSub(nums,0,nums.size()-1);
}

void quickSortSub(vector<int>& nums, int begin, int end){
    if((end-begin)<1) return;
    int i=begin,j=end;
    int base = nums[begin];
        while(i<j){
        //从右边开始移动
        while(j>i){
            //如果右指针指向的数大于base则移动
            if(nums[j] > base){
                j--;
            }
            else{
                //如果遇到小于等于基准数，则
                nums[i] = nums[j];
                i++;
                break;
            }
        }
        //从左到右移动
        while(j>i){
            if(nums[i]<=base){
                i++;
            }
            else{
                nums[j] = nums[i];
                j--;
                break;
            }
        }
    }
    //这个时候，已经将数组分为了两组，从开始到第i-1个都小于等于base
    //第i个等于base
    //从i+1到最后一个都大于
    //递归调用quickSort
    quickSortSub(nums,begin,i-1);
    nums[i] = base;
    quickSortSub(nums,i+1,end);
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