#include"Solution.h"

using std::cout;
using std::endl;

void printVector(vector<int>& nums){
    for(vector<int>::iterator it=nums.begin();it<nums.end();it++){
        cout << (*it) << " ";
    }
    cout << endl;
}


int main(){
    Solution s;
    vector<int> nums1{-1,3,2,0};
    vector<int> m = s.findDuplicates_q442(nums1);
    //bool pattern = s.find132pattern_q456(nums1);
    printVector(m);
    return 0;
}