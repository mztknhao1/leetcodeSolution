#ifndef _TRACEBACK_
#define _TRACEBACK_

/*
 * @Author: your name
 * @Date: 2019-12-08 13:14:45
 * @LastEditTime: 2020-04-09 08:42:37
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcodeSolution/include/traceback.h
 */
#include "lib_head.h"
#include <vector>


vector<vector<int>> permute_q46(vector<int>& nums);
void traceback_q46(vector<int>& nums, vector<int>& trace, vector<vector<int>>& result);

vector<vector<int>> combinationSum_q39(vector<int>& candidates, int target);
void traceback_q39(vector<int>& candidates, vector<int>& track, int target, vector<vector<int>>& result);


//类似的题还有：17题电话号码的字母组合
vector<string> letterCombinations_q17(string digits);
void trackback_q17(string& digits, std::unordered_map<char,string>& mp, string& track,vector<string>& result);

// 括号生成
vector<string> generateParenthesis_gP(int n);
void traceback_gP(string path,vector<string>& res,int left, int right,int n);

#endif