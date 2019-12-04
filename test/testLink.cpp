#include "linkList.h"
#include"utils.h"

int main(){
    ListNode L1(1);
    ListNode L2(2);
    ListNode L3(3);
    ListNode L4(4);
    ListNode L5(5);
    ListNode* head=&L1;
    L1.next = &L2;
    L2.next = &L3;
    L3.next = &L4;
    L4.next = &L5;

    linkSolution lS;

    // ListNode* result = lS.rotateRight_q61(head,3);
    ListNode* result_q24 = lS.swapPairs_q24(head);


    return 0;

}