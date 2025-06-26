/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        Node* init = root;
        queue<Node*> memory;
        memory.push(root);
        while(!memory.empty()){
            int size = memory.size();
            for(int i = 0; i < size; ++i){
                Node* curr = memory.front();
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
                memory.pop();
                if(i < size - 1)
                    curr->next = memory.front();
            }
        }
        return init;
    }
};