#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;

void printVector(vector<int>& nums){
    for(vector<int>::iterator it=nums.begin();it<nums.end();it++){
        cout << (*it) << " ";
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

