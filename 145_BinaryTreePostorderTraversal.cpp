class Solution {
public:
    void traversal(TreeNode* root, vector<int>& result){
        if(!root)
            return;
        traversal(root -> left, result);
        traversal(root -> right, result);
        result.push_back(root -> val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
        
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return{};
        stack<TreeNode*> memory; 
        vector<int> result;
        memory.push(root);
        while(!memory.empty()){
            /* Read the top element's value and remove it*/
            TreeNode* curr = memory.top();
            result.push_back(curr -> val);
            memory.pop();
            /* Read the left child first*/
            if(curr->left)
                memory.push(curr->left);
            /* Push the right child on the top of left child*/
            if(curr->right)
                memory.push(curr->right);
        }
        for(int i = 0; i < result.size()/2; ++i){
            swap(result[i], result[result.size() - 1 - i]);
        }
        return result;
        
    }
};