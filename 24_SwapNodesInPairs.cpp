struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (!head || !(head -> next))
            return head;

        ListNode* curr = head;
        head = head -> next;

        ListNode* temp = nullptr;
        ListNode* next;

        while(curr && curr -> next){
            if(temp){
                temp -> next = temp -> next -> next;
            }
            next = curr -> next;
            curr -> next = next -> next;
            next -> next = curr;
            temp = curr;
            curr = curr -> next;
        }

        return head;

        
    }
};