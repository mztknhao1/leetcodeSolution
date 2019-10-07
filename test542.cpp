#include"Solution.h"

using std::cout;
using std::endl;

void printVector(vector<int>& nums){
    for(vector<int>::iterator it=nums.begin();it<nums.end();it++){
        cout << (*it) << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>>& matrix){
    int rows = matrix.size();
    for(int i=0;i<rows;i++){
        printVector(matrix[i]);
    }
}


int main(){
    Solution s;
    vector<vector<int>> matrix{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    //vector<int> m = s.findDuplicates_q442(nums1);
    vector<vector<int>> dist = s.updateMatrix_q542(matrix);
    printMatrix(dist);
    return 0;
}