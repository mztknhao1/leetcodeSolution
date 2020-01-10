#include "Solution.h"
#include "utils.h"
#include "lib_head.h"
#include <sstream>
#include <hash_map>
#include <unordered_set>

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

std::string Solution::addString_q415(std::string& s1,std::string& s2){
    std::string result;
    int num1=s1.size();
    int num2=s2.size();
    int carry = 0;
    for(int i=num1-1,j=num2-1;i>=0||j>=0;i--,j--){
        int sum=carry;
        sum += (i>=0? s1[i]-'0':0);
        sum += (j>=0? s2[j]-'0':0);
        result.insert(result.begin(), '0'+sum%10);
        carry = sum>9?1:0;
    }
    if (carry==1) result.insert(result.begin(),'1');
    return result;
}

std::string Solution::addBinary_q67(std::string a, std::string b) {
        int na = a.size();
        int nb = b.size();
        int carry = 0;
        std::string result;
        for(int i=na-1,j=nb-1;i>=0||j>=0;i--,j--){
            int sum=carry;
            sum += i>=0? a[i]-'0':0;
            sum += j>=0? b[j]-'0':0;
            result.insert(result.begin(),'0' + sum%2);
            if(sum>=2){
                carry = 1;
            }else{
                carry=0;
            }
        }
        if(carry==1){
            result.insert(result.begin(),'1');
        }
        return result;
}


vector<vector<std::string>> Solution::acountsMerge_q721(vector<vector<std::string>>& acounts){
    vector<vector<std::string>> result;
    vector<std::string> tmpAcount;
    int numCounts = acounts.size();
    if(numCounts == 0) return result;
    if(numCounts == 1) {
        result.push_back(acounts[0]);
        return result;
    }
    //遍历每一个vector
    //保存flag，对已经融合的vector，falg=1
    vector<int> flag(numCounts,0);
    for(int i=0;i<numCounts;i++){
        for(int j=i+1;j<numCounts;j++){
            //如果该账户没有被融合则进行比较
            if(flag[j]==0&&compAcounts(acounts[i],acounts[j])){
                //将账户融合到第[i]个账户中
                mergeAcounts(acounts[i],acounts[j]);
                flag[j] = 1;
            }
        }
    }
    for(int m=0;m<numCounts;m++){
        if(flag[m]==0){
            //std::sort(acounts[m].begin()+1,acounts[m].end(),std::greater<std::string>());
            result.push_back(acounts[m]);
        }
    }
    return result;
}

bool Solution::compAcounts(vector<std::string>& acount1,vector<std::string>& acount2){
    int num1 = acount1.size()-1;
    int num2 = acount2.size()-1;
    int n=std::min(num1,num2);
    int flag = 0;
    if(n==num1){
        for(int i=0;i<n;i++){
            vector<std::string>::iterator iter = find(acount2.begin()+1,acount2.end(),acount1[i+1]);  
            if(iter!=acount2.end()){
                flag = 1;
                acount2.erase(iter);
            }
        }
    }else if(n==num2){
         for(int i=0;i<n;i++){
            vector<std::string>::iterator iter = find(acount1.begin()+1,acount1.end(),acount2[i+1]);
            if(iter!=acount1.end()){
                flag = 1;
                acount1.erase(iter);
            }
        }   
    }
    return flag==1?true:false;
}

void Solution::mergeAcounts(vector<std::string>& dstAcount,vector<std::string>& srcAcount){
    dstAcount.insert(dstAcount.end(),srcAcount.begin()+1,srcAcount.end());
}


bool Solution::checkStraightLine_q1232(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2){
            return true;
        }
        double x1 = coordinates[0][0],x2=coordinates[1][0],x3=coordinates[2][0];
        double y1 = coordinates[0][1],y2=coordinates[1][1],y3=coordinates[2][0];
        if((x1==x2 && x2!=x3)||(x1!=x2&&x2==x3)) return false;
        if(x1==x2 && x2==x3){
            for(int i=3;i<coordinates.size();i++){
                if(coordinates[i][0]!=x1){
                    return false;
                }
            }
            return true;
        }
        for(int i=0;i<coordinates.size()-2;i++){
            x1 = coordinates[i][0],x2=coordinates[i+1][0],x3=coordinates[i+2][0];
            y1 = coordinates[i][1],y2=coordinates[i+1][1],y3=coordinates[i+2][1];
            if(x1==x2 || x2==x3){
                return false;
            }
            if((y3-y2)/(x3-x2)!=(y2-y1)/(x2-x1)){
                return false;
            }
        }
        return true;
    }

int gcd(int x,int y){
    return x==0?y:gcd(y%x,x);
}

bool Solution::robot_L3(string command, vector<vector<int>>& obstacles, int x, int y) {

    #define _BITOP

    #ifdef _SMALLSIZE
    if(command.size()==0) return false;
    oprator o(command[0]);
    oprator* head = &o;
    oprator* tail = &o;
    for(int i=1;i<command.size();i++){
        oprator* op = new oprator(command[i]);
        tail->next = op;
        tail = tail->next;
    }
    int now_x=0,now_y=0;
    while(now_x!=x||now_y!=y){
        if(meet_obstacles(obstacles, now_x,now_y)) return false;
        if(head->op_val == 'U') {now_y++;}
        else if(head->op_val == 'R') {now_x++;}
        tail->next = head;
        tail = tail->next;
        head = head->next;
    }
    #endif

    #ifdef _BITOP
    std::unordered_set<long> s;
    int xx = 0,yy = 0;
    s.insert(0);
    for(auto c : command){
        if(c == 'U') yy++;
        else if(c == 'R')xx++;
        long tmp = (long)xx<<30 | yy;
        s.insert(((long)xx << 30) | yy);
    }
      
    int circle = min(x/xx,y/yy);
    if(s.count(((long)(x-circle*xx) << 30) | (y-circle*yy)) == 0) return false;
    
    for(auto v: obstacles){
        if(v.size() != 2) continue;
        if(v[0] > x || v[1] > y) continue;
        circle = min(v[0]/xx,v[1]/yy);
        if(s.count(((long)(v[0]-circle*xx) << 30) | (v[1]-circle * yy))) return false;
    }

    #endif


    return true;
}

bool hasGroupsSizeX_q914(vector<int>& deck){
    if(deck.size()==0) return false;
    std::unordered_map<int,int> mp;
    for(int i:deck){
        mp[i] += 1;
    }
    int g=-1;        
    for(auto m:mp){
        if(g==-1) g=m.second;
        else g=gcd(g,m.second);
    }
    return g>=2;
}

bool wordPattern_q290(string pattern, string str){
    std::unordered_map<char,string> mp;
    std::unordered_map<string,int> used;
    vector<string> s;
    for(int i=0;i<str.size();i++){
        string tmp;
        while(str[i]==' '){
            if(i>=str.size()) break;
            i++;
        }
        while(str[i]!=' '){
            if(i>=str.size()) break;
            tmp += str[i];
            i++;
        }
        s.push_back(tmp);
    }
    if(pattern.size()!=s.size()) return false;
    for(int i=0;i<s.size();i++){
        if(mp.find(pattern[i])!=mp.end()){
            if(mp[pattern[i]]!=s[i]) return false;
        }else{
            if(used[s[i]]==1) return false;
            mp[pattern[i]] = s[i];
            used[s[i]] = 1;
        }
    }
    
    return true;
}

int hammingDistance_q461(int x, int y){
    int ans = 0;
    while(x!=0 || y!=0){
        if(x%2!=y%2) ans++; 
        x = x/2;
        y = y/2;
    }
    while(x!=0){
        if(x%2==1) ans++;
        x = x/2;
    }
    while(y!=0){
        if(y%2==1) ans++;
        y = y/2;
    }
    return ans;
}
