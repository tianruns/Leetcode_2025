#include <iostream>
#include "ListNode.h"


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while(curr && curr -> next != nullptr){
            ListNode* follow = curr -> next;
            /* If next value is target, move curr node points to next next*/
            if((follow -> val) == val){
                curr -> next = follow -> next;
                delete follow;
            }
            /*Otherwise, move curr node forward*/
            else  
                 curr = curr -> next;
        }

        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};