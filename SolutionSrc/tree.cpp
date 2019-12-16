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

//判断是否是平衡二叉树
bool TreeSolution::isBalanced_q110(TreeNode* root){
    int h = 0;
    return balance(root,h);
}

bool TreeSolution::balance(TreeNode* root, int& h){
    int hr,hl;
    if(root==NULL) {
        h = 0;    
        return true;
    }
    if(root->left==nullptr && root->right==nullptr){
        h = 1;
        return true;
    }
    bool bl =  balance(root->left, hl);
    bool br =  balance(root->right, hr);
    h = (hl>hr?hl:hr)+ 1;
    if(abs(hl-hr)<2) return br&bl;
    else return false;
}


//验证二叉搜索树
bool TreeSolution::isValidBST_98(TreeNode* root){
    //这里应用递归的方法试试
    int upper = INT32_MAX;
    int lower = INT32_MIN;
    return isBST_98(root,lower,upper);
}

bool TreeSolution::isBST_98(TreeNode* root, int lower, int upper){
    if(root==nullptr) return true;
    
    int val = root->val;
    if(val >= upper) return false;
    if(val <= lower) return false;

    if(isBST_98(root->left, lower, val)==false) return false;
    if(isBST_98(root->right, val, upper)==false) return false;
    return true;
}

int TreeSolution::numTrees_q96(int n){
    int dp[n+1];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        //第dp[i] = dp[j]*dp[i-j] j<i
        dp[i] = 0;
        for(int j=1;j<i;j++){
            dp[i] += dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}

//二叉树的最小深度
int TreeSolution::minDepth_q111(TreeNode* root){
    //先试试用深度优先搜索吧,广度优先搜索类似，使用队列
    //把当前节点和所在深度绑定
    stack<pair<TreeNode*,int>>* s = new stack<pair<TreeNode*,int>>;
    if(root==nullptr) return 0;
    s->push(make_pair(root,1));
    int minDeep = INT32_MAX;
    int currentDeep = 0;
    TreeNode* currentNode;
    while(!s->empty()){
        //如果遇到叶子节点则更新最小深度
        currentNode = s->top().first;
        currentDeep = s->top().second;
        if(currentNode->left==nullptr&&currentNode->right==nullptr){
            minDeep = min(minDeep,currentDeep);
        }
        s->pop();
        if(currentNode->left!=nullptr) s->push(make_pair(currentNode->left, currentDeep+1));
        if(currentNode->right!=nullptr) s->push(make_pair(currentNode->right,currentDeep+1));
    }
    return minDeep;
}

//原地将二叉树展开成链表
void TreeSolution::flatten_q114(TreeNode* root){
    //先尝试用递归的方法实现
    #define _INPLACE

    #ifdef _DIGUI
        if(root==nullptr) return;
        flatten_q114(root->left);
        flatten_q114(root->right);
        TreeNode* tmp=root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* tmp2 = root;
        while(tmp2->right!=nullptr){
            tmp2 = tmp2->right;
        }
        tmp2->right = tmp;
    #endif

    #ifdef _INPLACE
        while (root != nullptr) {
            if (root->left != nullptr) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将跟的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候跟的右孩子可以释放, 因此我令左孩子放到右孩子上
                root->left = nullptr; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        
        return;
    #endif

}

vector<string> TreeSolution::letterCasePermutation_q784(string S){
    // 这个题用回溯法，深度优先搜索解
    vector<string> res;
    int len = S.length();
    dfs_q784(S,0,len,res);
    return res;
}

void TreeSolution::dfs_q784(string S,int index, int len, vector<string>& res){
   if(index != len){
       //小写字母
       if(S[index]>='a' && S[index]<='z'){
           dfs_q784(S,index+1,len,res);
           S[index] = S[index] - 'a' + 'A';
           dfs_q784(S,index+1,len,res);
       }
       else if(S[index]>='A' && S[index]<='Z'){
           dfs_q784(S,index+1,len,res);
           S[index] = S[index] - 'A' + 'a';
           dfs_q784(S,index+1,len,res);
       }else{
           dfs_q784(S,index+1,len,res);
       }
   }
   else{
       res.push_back(S);
   }
}

TreeNode* TreeSolution::lowestCommonAncestor_q236(TreeNode* root, TreeNode* p, TreeNode* q){
    stack<TreeNode*> path1 = findPath_q236(root, p->val);
    stack<TreeNode*> path2 = findPath_q236(root, q->val);
    int s1 = path1.size();
    int s2 = path2.size();
    while(s1>s2){
        path1.pop();
        s1--;
    }
    while(s1<s2){
        path2.pop();
        s2--;
    }
    while(path1.top()->val != path2.top()->val){
        path1.pop();
        path2.pop();
    }
    return path1.top();
}

stack<TreeNode*> TreeSolution::findPath_q236(TreeNode* root, int val){
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* curr = s.top();
    TreeNode* has_visted = NULL;
    if(curr->val == val){
        s.push(curr);
        return s;
    }
    while(!s.empty()){
        while(curr->val!=val && curr->left!=nullptr){
            s.push(curr->left);
            curr = s.top();
            if(curr->val == val){
                s.push(curr);
                return s;
            }
        }
        if(curr->right==nullptr || curr == has_visted)
        {
            s.pop();
            curr = s.top()->right;
        }else{
            has_visted = s.top();
            s.push(curr->right);
            curr = s.top();
        }
        if(curr->val == val){
            s.push(curr);
            return s;
        }
    }
}
