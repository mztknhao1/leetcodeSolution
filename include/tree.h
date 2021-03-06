#ifndef __TREE
#define __TREE

#include"dataStruct.h"
#include"lib_head.h"

using std::queue;
using std::vector;
using std::pair;
using std::stack;
using std::make_pair;
using std::min;
using std::max;
using std::string;

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
    int minDepth_q111(TreeNode* root);
    void flatten_q114(TreeNode* root);
    vector<string> letterCasePermutation_q784(string S);
    TreeNode* lowestCommonAncestor_q236(TreeNode* root, TreeNode* p, TreeNode* q);
    stack<TreeNode*> findPath_q236(TreeNode* root, int val);

private:
    void bfs_q637(queue<TreeNode*>*& currentQ, queue<TreeNode*>*&nextQ, vector<double>& result);
    bool balance(TreeNode* root, int& h);
    bool isBST_98(TreeNode* root, int upper, int lower);
    void dfs_q784(string S,int index, int len, vector<string>& res);
};

vector<int> findMode_q501(TreeNode* root);
void inorder(TreeNode* root,TreeNode*& pre,vector<int>& res,int& maxTimes,int& currTimes);
int findBottemLeftValue_q513(TreeNode* root);
vector<vector<int>> zigzagLevelOrder_q103(TreeNode* root);

TreeNode* buildTree_q105(vector<int>& preorder, vector<int>& inorder);
TreeNode* helpfun_q105(vector<int>& preorder,int& pos, vector<int>& inorder,int left, int right);

TreeNode* buildTree_q106(vector<int>& inorder,vector<int>& postorder);
TreeNode* helpfun_q106(vector<int>& inorder, int left, int right, vector<int>& postorder, int & pos);

vector<vector<int>> pathSum_q113(TreeNode* root, int sum);
void helpfun_q113(TreeNode* root, int sum,vector<vector<int>>& pathVec,vector<int> path);

#endif