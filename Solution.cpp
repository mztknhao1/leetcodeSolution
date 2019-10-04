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

bool Solution::isOneBitCharacter_q717(vector<int>& bits) {
    int bits_len = bits.size();
    int count = 0;
    for(vector<int>::iterator it=bits.end()-2;it >= bits.begin();it--){
        if(*it == 1) count++;
        else break;
    }
    return count%2==0?true:false;
}

vector<int> Solution::addToArrayForm_q989(vector<int>& A, int K) {
    vector<int> result;
    int num = 0;
    int sum;
    int flag=0;
    for(vector<int>::iterator it = A.end()-1;it>=A.begin();it--){
        if(K != 0){
            num = K%10;
            K = (K - num)/10;
        }else{
            num = 0;
        }
        sum = num + *it + flag;
        if(sum>9){
            result.push_back(sum%10);
            flag = 1;
        }else{
            result.push_back(sum);
            flag = 0;
        }
    }
    while(K!=0 | flag ==1){
        num = K%10;
        K = (K-num)/10;
        sum = num + flag;
        if(sum > 9){
            result.push_back(sum%10);
            flag = 1;
        }else{
            result.push_back(sum);
            flag = 0;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}

//这个题的解题思路是利用二分查找的方法求得最接近m(m+1)<n的m
int Solution::arrangeCoins_q441(int n){
    int little = 0;
    int big = n/2 + 1;
    int median = (big - little)/2 + little;

    while(little<big){
        median = (big-little)>>1 + little;  
        if(median*(median+1)/2 < n-median){
            little = little + 1;
        }else
        {
            big = median;
        }
    }
    return little;
};

vector<int> Solution::findDuplicates_q442(vector<int>& nums){
    vector<int> result;
    int temp;
    for(int i=0;i<nums.size();i++){    
        nums[i]>0?temp=nums[i]:temp=nums[i]*(-1);
        if(nums[temp-1] > 0){
            nums[temp-1] = (-1)*nums[temp-1];
        }
        else result.push_back(temp);
    }
    return result;
}