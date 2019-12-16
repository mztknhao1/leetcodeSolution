#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {11,17,13,4,5,6,56,29}; 
    //insertSort(nums);
    // int pivot = insertSort(nums,0,nums.size()-1);
    // heepSort(nums);
    int index = BFPRT(nums,1,nums.size()-2,2);
    printVector(nums);
    return 0;
}