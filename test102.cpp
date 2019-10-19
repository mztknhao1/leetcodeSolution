#include "tree.h"
#include "utils.h"

int main(){
    TreeSolution tree;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(3);
    root.left = &t1;
    root.right = &t2;
    TreeNode t3(4);
    TreeNode t4(5);
    t2.left = &t3;
    t2.right = &t4;

    vector<vector<int>> result = tree.levelOrder_q102(&root);
    printMatrix(result);
    return 0;
}