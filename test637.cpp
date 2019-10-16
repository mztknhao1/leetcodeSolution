#include "tree.h"
#include "utils.h"

int main(){
    TreeSolution tree;
    TreeNode root(3);
    TreeNode t1(9);
    TreeNode t2(20);
    root.left = &t1;
    root.right = &t2;
    TreeNode t3(15);
    TreeNode t4(17);
    t2.left = &t3;
    t2.right = &t4;

    vector<double> ave = tree.averageOfLevels_q637(&root);
    
    int n=ave.size();
    for(int i=0;i<n;i++){
        cout << ave[i] << " "; 
    }
    return 0;

}