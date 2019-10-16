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

vector<int> TreeSolution::inorderTraversal_q94(TreeNode* root){
    #define _STACK
    
    #ifdef _DIGUI
    vector<int> result;
    if(root->left != nullptr){
        vector<int> tmp = inorderTraversal_q94(root->left);
        result.insert(result.end(),tmp.begin(),tmp.end());
    }
    result.push_back(root->val);
    if(root->right!=nullptr){
        vector<int> tmp = inorderTraversal_q94(root->right);
        result.insert(result.end(),tmp.begin(),tmp.end());
    }
    return result;
    #endif

    #ifdef _STACK
    std::stack<TreeNode*>* s = new std::stack<TreeNode*>;
    std::vector<int> result;
    TreeNode* curr=root;
    while(curr!=nullptr || !s->empty()){
        //如果当前左子树非空
        while(curr!=nullptr){
            s->push(curr);           
            curr = curr->left;
        }
        if(!s->empty()){
            result.push_back(s->top()->val);
            curr = s->top()->right;
            s->pop();
        }
    }
    return result;
    #endif
}