#include<unordered_map>
#include"ListNode.h"

using std::unordered_map;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* startA = headA;
        ListNode* startB = headB;
        while(startA){
            lengthA++;
            startA = startA -> next;
        }
        while(startB){
            lengthB++;
            startB = startB -> next;
        }
        while(lengthA > lengthB){
            headA = headA -> next;
            lengthA--;
        }
        while(lengthA < lengthB){
            headB = headB -> next;
            lengthB--;
        }
        while(headA){
            if(headA == headB)
                return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};