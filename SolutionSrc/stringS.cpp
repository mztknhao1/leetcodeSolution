#include "lib_head.h"
#include "stringS.h"

int longestCommonSubsequence_q1143(string text1, string text2)
{
    int n1 = text1.size(), n2 = text2.size();
    int **dp;
    if (n1 == 0 || n2 == 0)
        return 0;
    dp = (int **)malloc(sizeof(int *) * n1);
    for (int i = 0; i < n1; i++)
    {
        *(dp + i) = (int *)malloc(sizeof(int) * n2);
    }
    if (text1[0] != text2[0])
    {
        dp[0][0] = 0;
    }
    else
    {
        dp[0][0] = 1;
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j > 0)
                dp[i][j] = (text1[0] == text2[j]) ? 1 : dp[0][j - 1];
            if (j == 0 && i > 0)
                dp[i][j] = (text1[i] == text2[0]) ? 1 : dp[i - 1][0];
            if (i != 0 && j != 0)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    int result = dp[n1 - 1][n2 - 1];
    for (int i = 0; i < n1; i++)
    {
        free(*(dp + i));
    }
    return result;
}

int myAtoi_q8(string str)
{
    int result = 0;
    int i = 0;
    int s = str.size();
    while (i < s)
    {
        if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-' && str[i] != '+')
        {
            return 0;
        }else if((str[i] >= '0' && str[i] <= '9')||str[i]=='-'||str[i]=='+'){
            break;
        }
        i++;
    }
    if(i==s) return 0;
    int flag=1;
    if (str[i] == '-')
        flag = 0;
    else if (str[i] == '+')
        flag = 1;
    else
        result = str[i] - '0';
    for (i = i + 1; i < s; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            break;
        if(result>INT32_MAX/10 || (result==INT32_MAX/10&&(str[i]-'0')>7)){
                return flag==0?INT32_MIN:INT32_MAX;
        }
        result = result * 10 + (str[i] - '0');
    }
    if (flag == 0)
        result = -result;
    return result;
}

 string convert_q6(string s, int numRows) {
        if(numRows==1) return s;

        int currentRow = 0;
        vector<string> rows(min(numRows,(int)s.size()));
        
        bool goingDown = false;

        for(char c:s){
            rows[currentRow] += c;
            if(currentRow==0 || currentRow==numRows-1){
                goingDown = !goingDown;
            }
            currentRow += goingDown?1:-1;
        }

        string result;
        for(string str:rows){
            result += str;
        }
        return result;
    }
