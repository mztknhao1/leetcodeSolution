#include "lib_head.h"

int dpSolution::maxProfit_q121(vector<int> &prices)
{
    //记录当前可以获得的最佳收益
    int maxProfit = -1;
    int size = prices.size();
    if (size < 2)
        return 0;
    //记录之前最小的股票价格
    int minStock = prices[0] > prices[1] ? prices[1] : prices[0];
    for (int i = 1; i < size; i++)
    {
        maxProfit = std::max(maxProfit, prices[i] - minStock);
        minStock = minStock > prices[i] ? prices[i] : minStock;
    }
    return maxProfit;
}

int dpSolution::longestPalindrome_q409(string s)
{

#define _HASH

#ifdef _SET
    std::set<char> myset;
    int result = 0;
    for (int i = 0; i < s.size(); i++)
    {
        auto iter = myset.find(s[i]);
        if (iter == myset.end())
        {
            myset.insert(s[i]);
        }
        else
        {
            myset.erase(iter);
            result += 2;
        }
    }
    if (!myset.empty())
    {
        result += 1;
    }
    return result;
#endif

#ifdef _HASH
    std::unordered_map<char, int> myMap;
    for (char c : s)
    {
        myMap[c] += 1;
    }
    int result = 0;
    for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
    {
        result += (iter->second % 2 == 0) ? iter->second : (iter->second - 1);
    }
    if (result < s.size())
        result += 1;
    return result;
#endif
}

bool dpSolution::divisorGame_1025(int N)
{
    if (N == 1)
        return false;
    vector<int> dp;
    dp.push_back(1);
    dp.push_back(0);
    for (int i = 3; i < N; i++)
    {
        for (int k = 1; k < i / 2; k++)
        {
            if (i % k == 0 && dp[k - 1] == 1)
            {
                dp.push_back(0);
                break;
            }
        }
        dp.push_back(1);
    }
    return dp[N - 2];
}


vector<int> dpSolution::sortArrayByParity_q905(vector<int>& A){
    //这个题好像可以不用动态规划做，先按自己的想法试试吧
    //经过测试，这个方法时间比别人多，但是内存消耗还行
    int sizeA = A.size();
    if(sizeA <= 1){
        return A;
    }

    vector<int> even,odd;

    for(auto num :A){
        if(num%2==0){
            even.emplace_back(num);
        }else{
            odd.emplace_back(num);
        }
    }
    even.insert(even.end(),odd.begin(),odd.end());
    return even;

    //看了答案可以借鉴快速排序的思想，方法是使用双指针，这里就尝试了，想做一个中等难度的快速排序
}


int dpSolution::numDecodings_q91(string s){
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}

int dpSolution::countSquares_q1277(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n] = {0};
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0) dp[i][j] = matrix[i][j];
            else if(matrix[i][j]==0) dp[i][j] = 0;
            else{
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            } 
            for(int ii=0;ii<=i;ii++){
                for(int jj=0;jj<=j;jj++){
                    std::cout<<dp[ii][jj]<< " ";
                }
                std::cout<<endl;
            }
            ans += dp[i][j];
        }
    }
    return ans;
}