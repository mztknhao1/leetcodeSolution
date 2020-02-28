#ifndef __STRINGS
#define __STRINGS

#include "lib_head.h"

int longestCommonSubsequence_q1143(string text1, string text2);
int myAtoi_q8(string str);
string convert_q6(string s, int numRows);
string longestDupSubString_q1044(string S);
string Robin_Karp_q1044(string S, int len);
string defangIPaddr_q1108(string address);
int numDistinct_q115(string s, string t);


vector<string> generateParenthesis_q22(int n);
void traceback_q22(vector<int> path,vector<string>& res,int left, int right,int n,stack<int> check);
string decodePath_q22(vector<int>& path);

#endif