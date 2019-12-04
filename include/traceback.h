#include "lib_head.h"


vector<vector<int>> permute_q46(vector<int>& nums);
void traceback_q46(vector<int>& nums, vector<int>& trace, vector<vector<int>>& result);

vector<vector<int>> combinationSum_q39(vector<int>& candidates, int target);
void traceback_q39(vector<int>& candidates, vector<int>& track, int target, vector<vector<int>>& result);


//类似的题还有：17题电话号码的字母组合
vector<string> letterCombinations_q17(string digits);
void trackback_q17(string& digits, std::unordered_map<char,string>& mp, string& track,vector<string>& result);