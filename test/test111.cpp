#include "tree.h"
#include "utils.h"

int main(){
    TreeSolution tree;
    TreeNode root(1);
    TreeNode t1(2);
    TreeNode t2(3);
    root.left = &t2;
    root.right = &t1;
    TreeNode t3(4);
    TreeNode t4(5);
    t2.left = &t3;
    t2.right = &t4;

    int a;
    a = tree.minDepth_q111(&root);
    cout << a;
    return 0;
}