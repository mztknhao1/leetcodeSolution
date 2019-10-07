#include"Solution.h"
#include"utils.h"

using std::cout;
using std::endl;

int main(){
    Solution s;
    ListNode* l1=new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2=new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode* m = s.mergeTwoLists_q21(l1,l2);
    //bool pattern = s.find132pattern_q456(nums1);
    printList(m);
    return 0;
}