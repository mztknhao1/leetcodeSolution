#include "tree.h"
#include "utils.h"

int main(){
    TreeSolution tree;
    TreeNode root(2);
    TreeNode t1(1);
    TreeNode t2(3);
    root.left = &t1;
    root.right = &t2;
    // TreeNode t3(4);
    // TreeNode t4(5);
    // t2.left = &t1;
    // t2.right = &t4;

    bool b = tree.isValidBST_98(&root);
    cout << b;
    return 0;
}