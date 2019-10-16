#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;



int main(){
    Solution s;
    vector<vector<int>> matrix{{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    //vector<int> m = s.findDuplicates_q442(nums1);
    vector<vector<int>> dist = s.updateMatrix_q542(matrix);
    printMatrix(dist);
    return 0;
}