#include "ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* fast = dummyNode;
        ListNode* slow = dummyNode;
        for(int i = n + 1; i > 0; i--){
             fast = fast -> next;
        }

        while(fast != nullptr){
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode* temp = slow -> next;
        slow -> next = temp -> next;
        delete temp;
        ListNode* result = dummyNode -> next;
        delete dummyNode;
        return result; 
    }
};