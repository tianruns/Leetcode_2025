#include "ListNode.h"
class Solution {
public:
    // ListNode* swapPairs(ListNode* head) {
        
    //     if (!head || !(head -> next))
    //         return head;

    //     ListNode* curr = head;
    //     head = head -> next;

    //     ListNode* temp = nullptr;
    //     ListNode* next;

    //     while(curr && curr -> next){
    //         if(temp){
    //             temp -> next = temp -> next -> next;
    //         }
    //         next = curr -> next;
    //         curr -> next = next -> next;
    //         next -> next = curr;
    //         temp = curr;
    //         curr = curr -> next;
    //     }

    //     return head;

        
    // }

    // ListNode* swapPairs(ListNode* head){
    //     ListNode* dummyNode = new ListNode(0);
    //     dummyNode -> next = head;
    //     ListNode* curr = dummyNode;
    //     while(curr->next != nullptr && curr -> next -> next != nullptr){
    //         ListNode* next = curr -> next;
    //         ListNode* afterNext = next -> next;
    //         curr -> next = afterNext;
    //         next -> next = afterNext -> next;
    //         afterNext -> next = next;
    //         curr = curr -> next ->next;
    //     }
    //     ListNode* result = dummyNode -> next;
    //     delete dummyNode;
    //     return result;

    // }

    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* curr = head;
        ListNode* prev = dummyNode;
        ListNode* temp;
        /* Loop is there are equal or more than 2 nodes*/
        while(curr && curr -> next){
            /* Save fourth node*/
            temp = curr -> next -> next;
            /* First node points to third node */
            prev -> next = curr -> next;
            /* Third node points to second node*/
            curr -> next -> next = curr;
            /* Second node points to fourth node*/
            curr -> next = temp;
            prev = curr;
            curr = temp;
        }
        ListNode* result = dummyNode -> next;
        delete dummyNode;
        dummyNode = nullptr;
        return result;
    }


};