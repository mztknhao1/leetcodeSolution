/*
 * @Author: your name
 * @Date: 2020-01-07 15:58:32
 * @LastEditTime: 2020-03-28 17:59:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcodeSolution/test/testString.cpp
 */
#include "stringS.h"

int main(){
    //820题测试
    vector<string> s_q820 = {"time"};
    s_q820.push_back("atime");
    s_q820.push_back("btime");
    int res_q820 = minimumLengthEncoding_q820(s_q820);


    // 第22题测试
    vector<string> s_q22 = generateParenthesis_q22(3);

    //  第115题测试
    string s_115 = "rabbbit";
    string t_115 = "rabbit";
    int ans_115 = numDistinct_q115(s_115,t_115);


    string str="banana";
    string ans_q1044 = longestDupSubString_q1044(str);
    int result = myAtoi_q8(str);
    return  0;
}