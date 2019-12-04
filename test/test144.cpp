#include "tree.h"
#include "utils.h"

int main(){
    TreeSolution tree;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(3);
    root.left = &t1;
    root.right = &t2;

    vector<int> result = tree.preorderTraversal_q144(&root);
    printVector(result);
    return 0;
}