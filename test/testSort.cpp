#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {11,17,13,12,4,5}; 
    //insertSort(nums);
    heepSort(nums);
    printVector(nums);
    return 0;
}