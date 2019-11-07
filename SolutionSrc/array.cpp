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


int ArraySolution::threeSumClosest_q16(vector<int>& nums, int target){
    //先给数组排个序
    std::sort(nums.begin(), nums.end());
    int size = nums.size();

    //记录结果
    int result = nums[0] + nums[size-1] + nums[1];  //先记录这几个数吧

    //固定下C位以后，还是使用双指针寻找这个时候最接近的两个数
    for(int i=1;i<size-1;i++)             
    {
        int left = 0,right = size-1;    //选取的第二个和第三个数的指针
        int localBest;                              //记录当前最优解
        int localres;                               //记录当前残差
        localBest = nums[left] + nums[right] + nums[i];
        while(left<right && left<i && right>i){
            localres = nums[left] + nums[right] + nums[i] - target;

            //如果当前残差小于局部最优解残差，更新当前最优解
            if(abs(localres)<abs(localBest-target)){
                localBest = nums[left] + nums[right] + nums[i];
            }

            //如果局部残差为0，直接返回，找到了最优解
            if(localres == 0){
                return target;
            }

            //如果残差小于0，即代表当前三个数的和小于target，则将左边的指针右移，否则左移右指针
            (localres>0)?right--:left++;
        }
        //如果局部最优值小于前值最优值，则更新当前最优值
        if(abs(localBest-target)<abs(result-target)){
            result = localBest;
        }
    }
    return result;
}

void ArraySolution::nextPermutation_q31(vector<int>& nums){
    //基本思路是从最后一个找起，找到第一个大于小于前面所有数的那个数，
    int size = nums.size();
    if(size==0 || size==1) return;
    int max = nums[size-1];
    int i=size-2;
    //找到第一个a[i-1]<a[i]的数
    for(;i>=0;i--){
        if(nums[i]>=max) max = nums[i];
        else {
            //如果找到了，则交换a[i-1]与a[j]其中，a[j]>a[i-1],且
            //j的范围是(i-1,size-1]
            int j = size-1;
            while(nums[j]<=nums[i] && j>=0){
                j--;
            }
            swap(nums[j],nums[i]);
            break;
        } 
    }
    reverse(nums,i+1);
}

void ArraySolution::swap(int& a, int& b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void ArraySolution::reverse(vector<int> & nums, int start){
    int i=start;
    int j = nums.size()-1;
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}

vector<vector<int>> ArraySolution::merge_q56(vector<vector<int>>& intervals){
    //这个题主要思路在于先排序再合并，
    //排完序后，只要前一个后一个区间的最小值小于等于前一个区间的最大值
    //就可以将这两个区间合并
    
    //先试试内置函数进行排序，接下来尽量自己实现一些排序算法
    sort(intervals.begin(),intervals.end(),comp_q56);
}

bool ArraySolution::comp_q56(const vector<int>&a, const vector<int>&b){
    if(a[0]<=b[0]) return true;
    if(a[0]> b[0]) return false;
}