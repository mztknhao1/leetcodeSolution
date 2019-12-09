#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {11,17,13,4,5,18,32,64}; 
    //insertSort(nums);
    int pivot = insertSort(nums,0,nums.size()-1);
    // heepSort(nums);
    int index = BFPRT(nums,0,nums.size()-1, 3);
    printVector(nums);
    return 0;
}