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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> memory;
        vector<int> result;
        
        while(root || !memory.empty()){
            if(root){
                memory.push(root);
                root = root->left;
            }
            else{
                root = memory.top();
                memory.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};