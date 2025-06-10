class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(empty())
            return -1;
        /* Keep the last-in element in queue1
           Push others in queue2*/
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.pop();
        /* Push queue2's elements back to queue1*/
        while(q2.size() > 0){
            q1.push(q2.front());
            q2.pop();
        }
        return val;

    }
    
    int top() {
        int size = q1.size();
        /* Move the front element to back except the last-in element*/
        while(size-- > 1){
            q1.push(q1.front());
            q1.pop();
        }
        int val = q1.front();
        q1.push(val);
        q1.pop();
        return val;

    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */