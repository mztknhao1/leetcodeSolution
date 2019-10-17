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

private:
    void bfs_q637(queue<TreeNode*>*& currentQ, queue<TreeNode*>*&nextQ, vector<double>& result);
    

};

#endif