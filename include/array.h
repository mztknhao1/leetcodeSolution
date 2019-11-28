#ifndef __ARRAY
#define __ARRAY

#include"utils.h"
#include"lib_head.h"

using std::vector;

class ArraySolution{
public:
    double findMedianSortedArrays_q4(vector<int> nums1, vector<int> nums2);
    int maxArea_q11(vector<int>& height);
    int threeSumClosest_q16(vector<int>& nums, int target);
    void nextPermutation_q31(vector<int>& nums);
    vector<vector<int>> merge_q56(vector<vector<int>>& intervals);
    bool containDuplicate_q217(vector<int>& nums);

private:
    void swap(int& a, int& b);
    void reverse(vector<int>& nums, int start);
  
};

#endif