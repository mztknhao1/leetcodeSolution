#include "Solution.h"
#include "utils.h"


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

bool Solution::find132pattern_q456(vector<int>& nums){
    int one = INT32_MAX;
    if(nums.size()<3) return false;
    for(int i=0;i<nums.size();++i){
        one = std::min(nums[i],one);
        if(one == nums[i]) continue;
        for(int j=nums.size()-1;j>i;--j){
            if(nums[j]>one && nums[j]<nums[i]){
                return true;
            }
        }
    }
    return false;
}

int Solution::minMoves_q453(vector<int>& nums) {
    int minNum = *min_element(nums.begin(),nums.end());
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum = nums[i]-minNum + sum;
    }
    return sum;
}

int Solution::minSteps_q650(int n){
    if(n == 1) return 0;
    int res=n;
    int num = 2;
    int total = 0;
    while(res != 1){
        if(res%num != 0){
            num++;
            continue;
        }
        res = res/num;
        total += num;
    }
    return total;
}


TreeNode* sortedArrayToBST_q108(vector<int>& nums){
    if(nums.empty()) return NULL;
    if(nums.size()==1) return new TreeNode(nums[0]);
    int begin = 0;
    int end = nums.size() - 1;
    int middel = (begin+end)>>1;
    TreeNode *root = new TreeNode(nums[middel]);
    vector<int> leftTree(nums.begin(),nums.begin()+middel);
    vector<int> rightTree(nums.begin()+middel+1,nums.end());
    root->left = sortedArrayToBST_q108(leftTree);
    root->right = sortedArrayToBST_q108(rightTree);
    return root;
}

vector<vector<int>> Solution::updateMatrix_q542(vector<vector<int>>& matrix){
    #define DP_Q542

    int rows=matrix.size();
    if(rows==0) return matrix;
    int cols=matrix[0].size();

    
    //广度优先搜索
    #ifdef BFS_Q542
     //初始化距离矩阵
    vector<vector<int>> dist(rows, vector<int>(cols, INT32_MAX));
    

   //维护一个队列，存放0所在位置
    std::queue<std::pair<int,int>> q;
    //第一次循环，放入所有的0的位置在队列中，把0的位置距离矩阵置为9
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j] == 0){
                dist[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};  //上下左右四个方向
    //对每个0作广度优先搜索
    while(!q.empty()){
        std::pair<int,int> curr=q.front();  //把队首取出来
        q.pop();
        for(int i=0;i<4;i++){
            //确定新的点的位置，即新的行和列
            int new_r=curr.first + dir[i][0];
            int new_c=curr.second + dir[i][1];
            //判断这是否是一个有效的点
            if(new_r>=0 && new_c>=0 && new_r<rows && new_c<cols){
                //更新，如果这个点在距离矩阵中的位置大于当前0的位置+1
                if(dist[new_r][new_c]>dist[curr.first][curr.second]+1){
                    dist[new_r][new_c] = dist[curr.first][curr.second]+1;
                    q.push({new_r,new_c});
                }
            }
        }
    }
    

    #endif

    //动态规划算法
    #ifdef DP_Q542

     //初始化距离矩阵
    vector<vector<int>> dist(rows, vector<int>(cols, INT32_MAX-100000));
    
   //第一次循环，检查左边和上边
   for(int i=0;i<rows;i++){
       for(int j=0;j<cols;j++){
            if(matrix[i][j] == 0)
                dist[i][j] = 0;
            else{
                if(i>0)
                    dist[i][j] = std::min(dist[i][j],dist[i-1][j] + 1);
                if(j>0)
                    dist[i][j] = std::min(dist[i][j],dist[i][j-1]+1);
            }
       }
   }

   //第二次循环，检查底边和右边
   for(int i=rows-1;i>=0;i--){
       for(int j=cols-1;j>=0;j--){
            if(i<rows-1)
                dist[i][j] = std::min(dist[i][j],dist[i+1][j] + 1);
            if(j<cols-1)
                    dist[i][j] = std::min(dist[i][j],dist[i][j+1]+1);
       }
   }
    #endif

    return dist;
}

ListNode* Solution::mergeTwoLists_q21(ListNode* l1, ListNode* l2){
    //递归的方法
    if(l1==NULL) return l2;
    else if(l2==NULL) return l1;
    else if(l1->val < l2->val){
        l1->next = mergeTwoLists_q21(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists_q21(l2->next,l1);
        return l2;
    }
}

std::string Solution::longestCommonPrefix_q14(vector<std::string>& strs){
    std::string result;
    int size = strs.size();
    if(size==0) return "";
    int minLong = INT8_MAX;   
    for(int i=0;i<size;i++){
        if(strs[i].size() < minLong){
            minLong = strs[i].size();
        }
    }
    for(int j=0;j<minLong;j++){
        char tmp = strs[0][j];
        for(int i=0;i<size;i++){
            if(strs[i][j]!=tmp){
                return result;
            }
        }
        result.push_back(tmp);
    }
    return result;
}

int Solution::lengthOfLongestSubstring_q3(std::string s){
    int len = 1;
    if(s.empty()) return 0;
    int start;
    std::string substr;
    substr.push_back(s[0]);
    for(int i=1;i<s.size();i++){
        int pos = substr.find(s[i]);
        //如果没找到那么
        if(pos==-1){
            substr.push_back(s[i]);
        }else{
         //删掉前面的串，在后面加上当前的字符
            start = start+pos;
            substr.erase(0,pos+1);
            substr.push_back(s[i]);
        }
        std::cout<<substr<<std::endl;
        len = std::max(len,int(substr.length()));
        if(s.size()-start < len) break;
    }
    return len;
}

vector<vector<int>> Solution::threeSum_q15(vector<int>& nums){
    
    vector<vector<int>> result;
    int n=nums.size();
    if(n<3) return result;    

    //首先对数组进行排序
    std::sort(nums.begin(), nums.end());
    printVector(nums);
    //然后遍历，由于经过了排序，则可以简化遍历过程
    for(int first=0;first<n-2;first++){
        if(first>0 && nums[first] == nums[first-1]) continue;
        int second=first+1;
        int last = n-1;
        while(second<last){
            int value=nums[first]+nums[second]+nums[last];
            if(value==0){
                vector<int> temp{nums[first],nums[second],nums[last]};
                result.push_back(temp);
                second++;
                last--;
                //主要为了防止记录到重复的
                while(second<n && nums[second]==nums[second-1]) second++;
                while(last>second && nums[last+1]==nums[last]) last--;
            }
            else if(value<0){
                second++;
                while(second<n && nums[second]==nums[second-1]) second++;
            }else{
                last--;
                //跳过重复复的
                while(last>second && nums[last+1]==nums[last]) last--;
            }
        }
    }
    return result;
}