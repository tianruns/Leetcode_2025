/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* point): val(x), next(point){}
};


class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* curr){
        if(!curr)
            return curr;
        ListNode* temp = curr ->next;
        curr -> next = pre;
        if(temp)
            return reverse(curr, temp);
        else
            return curr;
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode* curr = head;
        // ListNode* pre = nullptr;
        // ListNode* temp;

        // while(curr){
        //     temp = curr -> next;
        //     curr -> next = pre;
        //     pre = curr;
        //     curr = temp;
        // }
        // return pre;
        return reverse(nullptr, head);

        
    }

};
