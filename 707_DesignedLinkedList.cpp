struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode(int x): val(x), next(nullptr){} 
    };

class MyLinkedList {
    int _size;
    LinkNode* _dummyNode;
public:
    MyLinkedList(): _size(0), _dummyNode(new LinkNode(0)) {}
    
    int get(int index) {
        /* If index is out of range, return -1*/
        if(index  + 1 > _size)
            return -1;
        LinkNode* curr = _dummyNode -> next;
        /* Continue moving curr, until reach target*/
        while(index--)
            curr = curr -> next;
        return curr -> val;
    }
    
    void addAtHead(int val) {
        LinkNode* newNode = new LinkNode(val);
        /* New node points to current head node*/
        newNode -> next = _dummyNode -> next;
        /* dummyNode points to new node*/
        _dummyNode -> next = newNode;
        /* Increase size*/
        _size++;
    }
    
    void addAtTail(int val) {
        LinkNode* newNode = new LinkNode(val);
        LinkNode* curr = _dummyNode;
        /*Stop when curr points to nullptr, only end node points to nullptr*/
        while(curr -> next != nullptr)
            curr = curr -> next;
        curr -> next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        /* If index is larger than the size, return 0*/
        if(index > _size)
            return ;
        LinkNode* newNode = new LinkNode(val);
        LinkNode* curr = _dummyNode;
        while(index--)
            curr = curr -> next;
        newNode -> next = curr -> next;
        curr -> next = newNode;
        _size++;
        
    }
    
    void deleteAtIndex(int index) {
        /* If index is out of range, return -1*/
        if(index  + 1 > _size)
            return ;
        LinkNode* curr = _dummyNode;
        while(index--> 0)
            curr = curr -> next;
        LinkNode* target = curr -> next;
        curr -> next = target -> next;
        delete target;
        /* target's memory is cleared, which does not mean target points to nullptr
           terget now points to unknown variable, which is a risk*/
        target = nullptr;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */