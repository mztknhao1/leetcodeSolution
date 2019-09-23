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
};