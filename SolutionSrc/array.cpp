#include "array.h"
#include "utils.h"

double ArraySolution::findMedianSortedArrays_q4(vector<int> nums1, vector<int> nums2){
    int m = nums1.size();
    int n = nums2.size();
    if(m>n){                        //如果n<m则交换nums1和nums2;
        return findMedianSortedArrays_q4(nums2, nums1);
    }

    //接下来开始检索i
    //二分查找
    int iMin = 0,iMax=m,halfLen=(m+n+1)/2;
    while(iMin<=iMax){
        int i = (iMin + iMax) / 2;
        int j = halfLen - i;
        if(i<iMax && nums2[j-1]>nums1[i])  iMin = i + 1;    
        else if(i>iMin && nums1[i-1]>nums2[j])  iMax = i - 1;
        else{
            int maxLeft = 0;
            if(i==0) {maxLeft = nums2[j-1];}
            else if(j==0) {maxLeft = nums1[i-1];}   
            else{maxLeft = std::max(nums1[i-1],nums2[j-1]);}
            if((m+n)%2==1) {return maxLeft;}

            int minRight = 0;
            if(i==m) {minRight = nums2[j];}
            else if(j==n) {minRight = nums1[i];}
            else {minRight = std::min(nums2[j],nums1[i]);}

            return (maxLeft + minRight) / 2.0;
        }
    }

   return 0.0;
}

int ArraySolution::maxArea_q11(vector<int>& height){
    //寻找能盛水最多的两个柱子组成的容器，使用双指针
    int left,right;
    int size = height.size();
    left = 0;
    right = size-1;
    int result=(right-left)*std::min(height[left],height[right]);
    int now=0;
    while(left<right){
        if(height[left]<height[right]){
            now = (right - left)*height[left];
            result = now>result?now:result;
            left++;
        }else{
            now = (right-left)*height[right];
            result = now>result?now:result;
            right--;
        }
    }
    return result;
}