#include "lib_head.h"
#include "stringS.h"
#include <hash_set>

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


string longestDupSubString_q1044(string S){
    int M = 26;
    string ans = "";
    int min = 1,max=S.size();
    int mid = (max-min)/2 + min;
    while(min<max){
        string tmp = Robin_Karp_q1044(S,mid);
        if(tmp!=""){
            ans = tmp;
            min = mid+1;
        }else{
            max = mid;
        }
        mid = (max-min)/2 + min;
    }
    return ans;
}

string Robin_Karp_q1044(string S, int len){
    int M = 26;
    using namespace __gnu_cxx;
    hash_set<long> hs;
    long pow = 1;
    for(int i=1;i<len;i++){
        pow = pow*M;
    }
    long tmp = 0;
    for(int i=0;i<len;i++){
        tmp = tmp*M + S[i]-'a';
    }
    hs.insert(tmp);
    for(int i=1;i<S.size()-len+1;i++){
        tmp = (tmp - (S[i-1] - 'a')*pow) * M + S[i+len-1] - 'a';
        if(hs.find(tmp)!=hs.end()){
            string st = S.substr(i,len);
            return st;
        }
        else{
            hs.insert(tmp);
        }
    }
    return "";
}

string defangIPaddr_q1108(string address){
    string ans;
    int i=0;
    while(i<address.size()){
        if(address[i]=='.'){
            ans += "[.]";
            i++;
        }else{
            ans += address[i];
            i++;
        }
    }
    return ans;
} 


int numDistinct_q115(string s, string t){
    int res = 0;
    int tNum = t.size();
    int sNum = s.size();
    if(tNum>sNum) return 0;
    if(tNum==sNum && tNum==1 && s[0]==t[0]) return 1;
    for(int i=0;i<tNum;i++){
        for(int j=0;j<sNum;j++){
            if((sNum-i-1)>=tNum){
                if(s[j]==t[i]){
                    string tmps;
                    string tmpt;
                    tmps.insert(tmps.end(),s.begin()+j+1,s.end());
                    tmpt.insert(tmpt.end(),t.begin()+i+1,t.end());
                    res += numDistinct_q115(tmps,tmpt);
                }
                else continue;
            }
            else break;
        }
    }
    return res;    
}


vector<string> generateParenthesis_q22(int n){
    vector<int> path;
    int left = 0;
    int right = 0;
    vector<string> res;
    stack<int> check;
    traceback_q22(path, res, left, right, n, check);
    return  res;
}

void traceback_q22(vector<int> path,vector<string>& res,int left, int right,int n,stack<int> check){
    if(left==n&&right==n&&check.empty()){
        string tmp = decodePath_q22(path);
        if(std::count(res.begin(),res.end(),tmp)==0) res.push_back(tmp);
        return;
    }

    if(left<n){
        left++;
        check.push(1);
        path.push_back(1);
        traceback_q22(path,res,left,right,n,check);
    }
    
    if(right<n){
        right++; 

        if(check.top()==1) check.pop();
        else check.push(2);

        path.push_back(2);
        traceback_q22(path,res,left,right,n,check);
    }

}

string decodePath_q22(vector<int>& path){
    string s;
    for(auto i:path){
        s += (i==1?'(':')');
    }
    return s;
}

int minimumLengthEncoding_q820(vector<string>& words){
    int res=1;
    // 暴力法
    vector<string> uniqueString;
    uniqueString.push_back(words[0]);
    res += words[0].size();
    for(int i=1;i<words.size();i++){
        string tmp = words[i];
        std::cout << "tmp = " << tmp << std::endl;
        bool flag = false;
        for(int m=0;m<uniqueString.size();m++){
            string s = uniqueString[m];
            std::cout << "s=" << s << std::endl;
            if(s.size()>=tmp.size()){
                if(isSubString_q820(s,tmp)){
                    flag=true;
                    continue;
                }
            }else if(s.size()<tmp.size()){
                if(isSubString_q820(tmp,s)){
                    flag=true;
                    res -= s.size();
                    res += tmp.size();
                    uniqueString.push_back(s);
                }
            }
        }
        if(flag==false){
            uniqueString.push_back(tmp);
            res += tmp.size();
            res += 1;
        } 
    }
    return res ;
}

bool isSubString_q820(string a,string b){
    int i=a.size(),j=b.size();
    int k = 0;
    for(int m = i-j;m<a.size();m++,++k){
        if(a[m]!=b[k]) return false;
    }
    return true;
}