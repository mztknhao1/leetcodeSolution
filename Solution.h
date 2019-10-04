#include "lib_head.h"

using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
};