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