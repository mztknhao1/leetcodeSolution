

#include "myTraceback.h"

bool findinnums(vector<int>& nums,int num){
    for(int i : nums){
        if(i==num){
            return true;
        }
    }
    return false;
}

vector<vector<int>> permute_q46(vector<int>& nums){
    //这是一个典型的回溯法的例题，路径，选择和结束条件（记住撤销选择）
    vector<int> trace;
    vector<vector<int>> result;
    traceback_q46(nums, trace,  result);
    return result;
}

void traceback_q46(vector<int>& nums, vector<int>& trace, vector<vector<int>>& result){

    //到了树的叶子节点，终止回溯
    if(trace.size()==nums.size()){
        result.push_back(trace);
    }
    for(int i=0;i<nums.size();i++){
        if(findinnums(trace,nums[i])){
            continue;
        }
        trace.push_back(nums[i]);
        traceback_q46(nums,trace,result);
        trace.pop_back();
    }
}

//其实也可用动态规划或者深度优先搜索算法的，这个回溯类似于深度优先算法
vector<vector<int>> combinationSum_q39(vector<int>& candidates, int target){
    std::sort(candidates.begin(),candidates.end());
    vector<vector<int>> result;
    if(candidates.size()==0) return result;
    if(candidates[0]>target) return result;

    vector<int> track;
    traceback_q39(candidates,track,target,result);
    return result;
}

void traceback_q39(vector<int>& candidates, vector<int>& track, int target,vector<vector<int>>& result){
    //终止回溯
    if(target==0) result.push_back(track);
    if(candidates[0]>target) return;

    //这里需要注意的是为了防止重复，需要减枝，后面选取的数不应该比前面选取的数要小
    for(int i:candidates){
        if(track.size()!=0 && i<track[track.size()-1]) continue;
        track.push_back(i);
        traceback_q39(candidates,track,target-i,result);
        track.pop_back();
    }
}

vector<string> letterCombinations_q17(string digits){
    std::unordered_map<char,string> mp;
    mp['2'] = "abc",mp['3'] = "def",mp['4']="ghi",mp['5']="jkl";
    mp['6'] = "mno",mp['7'] = "pqrs",mp['8']="tuv",mp['9']="wxyz";
    vector<string> result;
    if(digits.size()==0) return result;
    string track;
    trackback_q17(digits,mp,track,result);
    return result;
}


void trackback_q17(string& digits, std::unordered_map<char,string>& mp, string& track,vector<string>& result){
    if(track.size()==digits.size()){
        result.push_back(track);
    }

    for(char c:mp[digits[track.size()]]){
        track.push_back(c);
        trackback_q17(digits,mp,track,result);
        track.pop_back();
    }
}

vector<string> generateParenthesis_gP(int n) {
    vector<string> res;
    traceback_gP("", res, 0, 0, n);
    return  res;   
}

void traceback_gP(string path,vector<string>& res,int left, int right,int n){
    if(left>n || right>n || right>left) return;
    if(left==n&&right==n){
        res.push_back(path);
        return;
    }
    traceback_gP(path+'(',res,left+1,right,n);  
    traceback_gP(path+')',res,left,right+1,n);
}
