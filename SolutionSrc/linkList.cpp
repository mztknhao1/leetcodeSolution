#include "linkList.h"
#include "utils.h"
#include "lib_head.h"

ListNode* linkSolution::rotateRight_q61(ListNode* head, int k){
    if(k==0) return head;
    if(head==NULL) return head;
    ListNode* tail=head;
    int size = 1;
    while(tail->next!=NULL){
        tail = tail->next;
        size++;
    }
    k = size - k%size;
    if(k==0) return head;
    for(int i=k;i>0;i--){
        tail->next = head;
        tail = head;
        head = head->next;
    }
    tail->next = NULL;
    return head;
}

ListNode* linkSolution::swapPairs_q24(ListNode* head){
    if(head==NULL) return head;
    ListNode* tmp1,*tmp2;
    ListNode  root(0);
    root.next = head;
    ListNode* p1 = &root;

    while(p1->next!=NULL && p1->next->next!=NULL){
        tmp1 = p1->next;
        tmp2 = p1->next->next->next;
        p1->next = p1->next->next;
        p1->next->next = tmp1;
        p1->next->next->next = tmp2;
        p1=p1->next->next;
    }
    head = root.next;
    return head;
}

ListNode* linkSolution::partition_q86(ListNode* head, int x){
    //初始化两个哑指针
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    auto node1 = dummy1;
    auto node2 = dummy2;
    while(head!=NULL){
        if(head->val < x){
            node1->next = head;
            node1 = node1->next;
        }
        else{
            node2->next = head;
            node2 = node2->next;
        }
        head = head->next;
    }
    node1->next = dummy2->next;
    //这句话千万别忘了写
    node2->next = NULL;
    return dummy1->next;
}

TreeNode* sortedListToBST_q109(ListNode* head){
    if(head==NULL) return 0;
    if(head->next==NULL) return new TreeNode(head->val);
    ListNode* fast_ptr = head;
    ListNode* slow_ptr = head;
    ListNode* pre_ptr = head;
    while(fast_ptr!=NULL && fast_ptr->next!=NULL){
        pre_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;  
    }
    pre_ptr->next = NULL;
    TreeNode* root = new TreeNode(slow_ptr->val);
    root->left = sortedListToBST_q109(head);
    root->right = sortedListToBST_q109(slow_ptr->next);
    return root;
}