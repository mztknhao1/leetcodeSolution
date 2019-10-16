#include "tree.h"


//这个题需要求解树的每一层平均值，采用广度优先搜索算法
//考虑使用两个辅助队列，其一指向当前层节点，其二指向下一层节点
std::vector<double> TreeSolution::averageOfLevels_q637(TreeNode* root){
    std::vector<double> result;
    std::queue<TreeNode*>* currentQ=new std::queue<TreeNode*>; //辅助队列，存储当前层的树节点
    currentQ->push(root);   //根节点入队
    std::queue<TreeNode*>* nextQ = new std::queue<TreeNode*>;
    do{
        bfs_q637(currentQ, nextQ, result);   //遍历每一层的值
    }while(!currentQ->empty());
    return result;
}

void TreeSolution::bfs_q637(queue<TreeNode*>*& currentQ, queue<TreeNode*>*&nextQ, vector<double>& result){
    double sum=0; //记录当前的树节点的值的和
    int count = 0;//记录当前树节点的个数
    while(!currentQ->empty()){
        TreeNode* x=currentQ->front();
        sum+=x->val;
        count++;
        if(x->left) nextQ->push(x->left);
        if(x->right) nextQ->push(x->right);
        currentQ->pop();
    }
    result.push_back(sum/count);

    //将下一个辅助队列和前辅助队列交换
    queue<TreeNode*>* tmpQ=currentQ;
    currentQ = nextQ;
    nextQ = tmpQ;
}