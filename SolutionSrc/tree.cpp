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

vector<int> TreeSolution::preorderTraversal_q144(TreeNode* root){

    #define __STACK

    #ifdef __DIGUI
    //首先使用递归的方法,这是个简单的想法，接下来试试堆栈
    vector<int> result;
    if(root==nullptr) return result;
    result.push_back(root->val);
    if(root->left!=nullptr){
        vector<int> tmp = preorderTraversal_q144(root->left);
        result.insert(result.end(), tmp.begin(), tmp.end());
    }
    if(root->right!=nullptr){
        vector<int> tmp = preorderTraversal_q144(root->right);
        result.insert(result.end(), tmp.begin(), tmp.end());
    }
    return result;
    #endif

    #ifdef __STACK
    //创建当前指向的节点指针
    TreeNode* current = root;
    //创建堆栈
    std::stack<TreeNode*>* s=new std::stack<TreeNode*>;

    vector<int> result;

    while(current!=nullptr || !s->empty()){
        while(current!=nullptr){
            result.push_back(current->val);
            s->push(current);
            current=current->left;
        }
        current=s->top()->right;
        s->pop();
    }
    return result;

    #endif


}

TreeNode* TreeSolution::invertTree_q266(TreeNode* root){
    #define __QUEUE

    #ifdef __DIGUI
    if(root==nullptr) return root;
    if(root->left==nullptr&&root->right==nullptr){
        return root;
    }
    TreeNode* inversleft = invertTree_q266(root->left);
    TreeNode* inversright = invertTree_q266(root->right);
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
    #endif

    #ifdef __QUEUE
        if(root==nullptr) return root;
        std::queue<TreeNode*>* q=new std::queue<TreeNode*>;
        q->push(root);
        TreeNode* current;
        TreeNode* tmp;
        while(!q->empty()){
            //取出队首的节点，对它的左右孩子做交换
            current = q->front();
            tmp = current->left;
            current->left=current->right;
            current->right=tmp;
            q->pop();
            if(current->left!=nullptr) q->push(current->left);
            if(current->right!=nullptr) q->push(current->right);
        }
        return root;
    #endif

}


//二叉树的层次遍历
vector<vector<int>> TreeSolution::levelOrder_q102(TreeNode* root){
    //当前层队列和下一层队列
    std::queue<TreeNode*>* q_current = new std::queue<TreeNode*>;
    std::queue<TreeNode*>* q_next = new std::queue<TreeNode*>;
    vector<vector<int>> result;
    if(root==nullptr) return result;
    q_current->push(root);
    while(!q_current->empty()){
        TreeNode* p_current;
        vector<int> tmp_vector;
        while(!q_current->empty()){
            p_current = q_current->front();
            tmp_vector.push_back(p_current->val);
            if(p_current->left!=nullptr) q_next->push(p_current->left);
            if(p_current->right!=nullptr) q_next->push(p_current->right);
            q_current->pop(); 
        }
        result.push_back(tmp_vector);
        std::queue<TreeNode*>* tmp;
        tmp = q_next;
        q_next = q_current;
        q_current = tmp;
    }
    return result;
}