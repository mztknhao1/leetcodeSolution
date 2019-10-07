#include "lib_head.h"

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{

public:
    void merge_q88(vector<int>& nums1, int m, vector<int>& nums2, int n);
    ListNode* addTwoNumbers_q2(ListNode* l1, ListNode* l2);
    vector<vector<int>> generate_q118(int numRows);
    bool isOneBitCharacter_q717(vector<int>& bits);
    vector<int> addToArrayForm_q989(vector<int>& A, int K);
    int arrangeCoins_q441(int n);
    vector<int> findDuplicates_q442(vector<int>& nums); 
    bool find132pattern_q456(vector<int>& nums);
    int minMoves_q453(vector<int>& nums);
    int minSteps_q650(int n);
    TreeNode* sortedArrayToBST_q108(vector<int>& nums);  

    //这里给出连个题解，根据宏定义不同来选择
    vector<vector<int>> updateMatrix_q542(vector<vector<int>>& matrix);

    int add(int a,int b);
};