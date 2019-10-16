#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;

void printVector(vector<int>& nums){
    int n = nums.size();
    for(int i=0; i<n ; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>>& matrix){
    int rows = matrix.size();
    for(int i=0;i<rows;i++){
        printVector(matrix[i]);
    }
}

void printList(ListNode* l1){
    ListNode* tmp = l1;
    while(tmp!=NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}

