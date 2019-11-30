#include"lib_head.h"
#include"stringS.h"

int longestCommonSubsequence_q1143(string text1, string text2){
    int n1 = text1.size(),n2=text2.size();
    int **dp;
    if(n1==0 || n2==0) return 0;
    dp = (int**)malloc(sizeof(int*)*n1);
    for(int i=0;i<n1;i++){
        *(dp+i) = (int*)malloc(sizeof(int)*n2);
    }
    if(text1[0]!=text2[0]){
        dp[0][0] = 0;
    }else{
        dp[0][0] = 1;
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(i==0 && j>0) dp[i][j] = (text1[0] == text2[j])?1:dp[0][j-1];
            if(j==0 && i>0) dp[i][j] = (text1[i] == text2[0])?1:dp[i-1][0];
            if(i!=0 && j!=0){
                if(text1[i]==text2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

                }
            }
        }
    }
    int result = dp[n1-1][n2-1];
    for(int i=0;i<n1;i++){
        free(*(dp+i));
    }
    return result;
}
