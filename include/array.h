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
bool cmp_q1337(vector<int>& a,vector<int>& b);
vector<vector<int>> shiftGrid_q1260(vector<vector<int>>& grid,int k);
vector<int> kWeakestRows_q1337(vector<vector<int>>& mat, int k);


int numberOfBoomerangs_q447(vector<vector<int>>& points);

int minimumTotal_q120(vector<vector<int>>& triangle);

#endif