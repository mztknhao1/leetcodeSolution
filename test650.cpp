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
    int n = 30;
    int min = s.minSteps_q650(n);
    cout << min << endl;
    return 0;
}