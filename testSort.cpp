#include "my_sort.h"
#include"utils.h"

using std::vector;

int main(){
    vector<int> nums = {3,5,6,4,3,4,5,9,2,1,0,35,41};
    //insertSort(nums);
    quickSort(nums);
    printVector(nums);

    return 0;
}