#ifndef __TREE
#define __TREE

#include"dataStruct.h"
#include"lib_head.h"

using std::queue;
using std::vector;

class TreeSolution{
public:
    std::vector<double> averageOfLevels_q637(TreeNode* root);
    vector<int> inorderTraversal_q94(TreeNode* root);
    vector<int> preorderTraversal_q144(TreeNode* root);
    TreeNode* invertTree_q266(TreeNode* root);
    vector<vector<int>> levelOrder_q102(TreeNode* root);
    bool isBalanced_q110(TreeNode* root);
    bool isValidBST_98(TreeNode* root);
    int numTrees_q96(int n);

private:
    void bfs_q637(queue<TreeNode*>*& currentQ, queue<TreeNode*>*&nextQ, vector<double>& result);
    bool balance(TreeNode* root, int& h);
    bool isBST_98(TreeNode* root, int upper, int lower);

};

#endif