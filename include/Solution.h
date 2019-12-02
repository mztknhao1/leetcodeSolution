#include "lib_head.h"
#include "dataStruct.h"

using std::vector;

#ifndef _SOLUTION
#define _SOLUTION
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

    ListNode* mergeTwoLists_q21(ListNode* l1, ListNode* l2);
    std::string longestCommonPrefix_q14(vector<std::string>& strs);
    int lengthOfLongestSubstring_q3(std::string s);

    vector<vector<int>> threeSum_q15(vector<int>& nums);

    std::string addString_q415(std::string& s1,std::string& s2);
    std::string addBinary_q67(std::string a, std::string b);

    vector<vector<std::string>> acountsMerge_q721(vector<vector<std::string>>& acounts);

    bool checkStraightLine_q1232(vector<vector<int>>& coordinates);


private:
    bool compAcounts(vector<std::string>& acount1,vector<std::string>& acount2);
    void mergeAcounts(vector<std::string>& dstAcount,vector<std::string>& srcAcount);
};

#endif