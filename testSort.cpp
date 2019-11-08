#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {1,3,2,5,9,2};
    insertSort(nums);
    printVector(nums);

    return 0;
}