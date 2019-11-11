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