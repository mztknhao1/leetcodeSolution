#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {11,17,13,4,5}; 
    //insertSort(nums);
    int pivot = insertSort(nums,1,nums.size()-2);
    // heepSort(nums);
    printVector(nums);
    return 0;
}