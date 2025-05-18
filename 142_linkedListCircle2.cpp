#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        /* Fast moves steps, slow moves 1 step, they meet when there is a circle*/
        while(true){
            if(!fast || !(fast -> next))
                return nullptr;
            fast = fast -> next -> next;
            slow = slow -> next;
            /* No circle, fast reaches end or shall reach end*/
            if(fast == slow)
                break;
            
        }
        ListNode* nodeA = head;
        ListNode* nodeB = fast;
        /* nodeA and nodeB shall meet at intersection node*/
        while(nodeA != nodeB){
            nodeA = nodeA -> next;
            nodeB = nodeB -> next;
        }
        return nodeB;

    }
};