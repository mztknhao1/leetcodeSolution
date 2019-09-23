#include "Solution.h"

void Solution::merge_q88(vector<int>& nums1,int m, vector<int>& nums2, int n){
    if(m == 0) {swap(nums1,nums2); return;}
    int p1 = m-1,p2=n-1;
    int p = m+n-1;
    while(p1>=0 && p2>=0){
        nums1[p1] > nums2[p2] ?nums1[p--] = nums1[p1--]:nums1[p--] = nums2[p2--];
    }
    while(p1 >= 0) nums1[p--] = nums1[p1--];
    while(p2 >= 0) nums1[p--] = nums2[p2--]; 
}

ListNode* Solution::addTwoNumbers_q2(ListNode* l1, ListNode* l2) {
        //将计算结果保存在l1中，本地操作
        ListNode* result = l1;
        ListNode* pre;              //记录前一个节点
        int flag = 0;               //进位标志
        while(l1||l2){
            int sum;
            l1? (pre=l1,l1=l1->next,sum = flag+pre->val):(pre->next = l2,pre = l2,sum=flag);
            l2? (sum = l2->val + sum,l2 = l2->next):(pre->next=l1);
            pre->val = sum%10;
            sum>9?flag=1:flag=0;
        }
        if(l1==nullptr && l2==nullptr && flag==1){
            pre->next = new ListNode(1);
        }
        return result;
}

vector<vector<int>> Solution::generate_q118(int numRows) {
        vector<vector<int>> result;
        if(numRows==0) return result;

        vector<int> now;
        now.push_back(1);
        result.push_back(now);

        int pre_j=1,pre_j_=1; 
        for(int i=1;i<numRows;i++)
        {
            //根据上一行的数据计算下一行的数据,仍然存在now中
            now.at(0) = 1;
            for(int j=1;j<i;j++){
                pre_j_ = now.at(j);
                now.at(j) = now.at(j) + pre_j;     
                pre_j = pre_j_;  
            }
            now.push_back(1);
            result.push_back(now);
        }

        return result;

    }