#include "traceback.h"


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