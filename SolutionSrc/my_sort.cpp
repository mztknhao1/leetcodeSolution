#include "my_sort.h"

void quickSort(vector<int>& nums){
    quickSortSub(nums,0,nums.size()-1);
}

void quickSortSub(vector<int>& nums, int begin, int end){
    if((end-begin)<1) return;
    int i=begin,j=end;
    int base = nums[begin];
        while(i<j){
        //从右边开始移动
        while(j>i){
            //如果右指针指向的数大于base则移动
            if(nums[j] > base){
                j--;
            }
            else{
                //如果遇到小于等于基准数，则
                nums[i] = nums[j];
                i++;
                break;
            }
        }
        //从左到右移动
        while(j>i){
            if(nums[i]<=base){
                i++;
            }
            else{
                nums[j] = nums[i];
                j--;
                break;
            }
        }
    }
    //这个时候，已经将数组分为了两组，从开始到第i-1个都小于等于base
    //第i个等于base
    //从i+1到最后一个都大于
    //递归调用quickSort
    quickSortSub(nums,begin,i-1);
    nums[i] = base;
    quickSortSub(nums,i+1,end);
}

void insertSort(vector<int>& nums){
    int size = nums.size();
    if(size<=1) return;
    for(int j=1;j<size;j++){
        //插入排序，左边总是排好序的
        //这次插入第j张牌
        int key = nums[j];
        //从0...j-1已经排好序的数组
        int i = j-1;
        while(i>=0 && key<nums[i]){
            nums[i+1] = nums[i];
            i--;
        }
        nums[i+1] = key;
    }
}


void heepSort(vector<int>& nums){
    #define _BIG_HEEP

    int size = nums.size();
    if(size<=1) return;

    //首先建堆,先建个大堆用于升序排序
    #ifdef _BIG_HEEP

    //构造一个有序堆
    //其实size/2-1表示的是第一个非叶子节点(堆结构中，有size/2个叶子节点)
    //遍历所有非叶子节点
    for(int i=size/2-1;i>=0;i--){
        sink(nums,i,size);
    }
    // printVector(nums);
    size = size-1;
    
    while(size>0){
        swap(nums,0,size--);
        sink(nums,0,size);
    }

    #endif
}

//k为下沉开始的位置，N为下沉结束的位置
void sink(vector<int>& nums, int k, int N){
    int tmp = nums[k];      //取出当前元素k
    //满足向下移动条件
    while(2*k+1<=N){
        //从最后一个非叶子节点开始调整
        int j=2*k+1;
        if(j<N-1 && nums[j+1] > nums[j]){ //j+1 和 j 其实是非叶子节点k下面的两个节点,如果nums[j+1]>nums[j]将指针指向j+1
            j++;
        }
        //如果子节点大于父节点，将子节点的值赋给父节点，不交换
        if(nums[j]>tmp){
            nums[k] = nums[j];
            k = j;
        }else{
            break;
        }
    }
    nums[k] = tmp;
}

//辅助函数，交换数组中下表为a和b的元素
void swap(vector<int>& nums,int a, int b){
    int tmp=nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}


int BFPRT(vector<int>& nums,int left,int right, int k){
    int pivot_index = getPivotIndex(nums,left,right);       //得到中位数的中位数索引
    int divide_index = partition(nums,left,right,pivot_index);
    int num = divide_index - left + 1;
    if(num==k)
        return divide_index;
    else if(num>k)
        return BFPRT(nums,left,divide_index-1,k);
    else
        return BFPRT(nums,divide_index+1,right,k-num);
}

//插入排序，返回中位数索引
int insertSort(vector<int>& nums, int left, int right){
    //插入第j张牌，从牌堆最上面开始比较
    for(int j=left+1;j<=right;j++){
        int i=j-1;
        int numsj = nums[j]; 
        while(i>=left&&numsj<nums[i]){
            nums[i+1] = nums[i];
            i--;
        }
        nums[i+1] = numsj;
    }
    int mid = (right-left)/2+left;
    return mid;
}     

//寻找nums[left]-nums[right]的中位数的中位数下标
int getPivotIndex(vector<int>& nums, int left, int right){
    if(right-left<5) return insertSort(nums,left,right);
    int sub_right = left-1;
    for(int i=left;i+4<=right;i+=5){
        int index = insertSort(nums,left,left+4);   //找到5个数的中位数
        swap(nums,++sub_right,index);        //将找到的中位数放到数组左侧
    }
    int sub_k = (sub_right-left+1)/2+1;
    return BFPRT(nums,left,sub_right,sub_k);
}  

//利用中位数的下标进行排序，返回分界的下标
int partition(vector<int>& nums, int left, int right, int pivotIndex){
    swap(nums,pivotIndex,right);        //将基准放在末尾
    int divide_index = left;            //跟踪划分的分界线
    for(int i=left;i<right;i++){
        if(nums[i]<nums[right])
            swap(nums,divide_index++,i);    //比基准小的都放在左侧
    }
    swap(nums,divide_index,right);          //最后把基准调回来
    return divide_index;
}  