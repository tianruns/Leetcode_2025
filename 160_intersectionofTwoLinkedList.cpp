#include"ListNode.h"

class Solution {
public:
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     int lengthA = 0;
    //     int lengthB = 0;
    //     ListNode* startA = headA;
    //     ListNode* startB = headB;
    //     while(startA){
    //         lengthA++;
    //         startA = startA -> next;
    //     }
    //     while(startB){
    //         lengthB++;
    //         startB = startB -> next;
    //     }
    //     while(lengthA > lengthB){
    //         headA = headA -> next;
    //         lengthA--;
    //     }
    //     while(lengthA < lengthB){
    //         headB = headB -> next;
    //         lengthB--;
    //     }
    //     while(headA){
    //         if(headA == headB)
    //             return headA;
    //         headA = headA -> next;
    //         headB = headB -> next;
    //     }
    //     return nullptr;
    // }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* startA = headA;
        ListNode* startB = headB;
        while(startA != startB){
            startA = startA? startA -> next: headB;
            startB = startB? startB -> next: headA;
        }
        return startA;

    }
};