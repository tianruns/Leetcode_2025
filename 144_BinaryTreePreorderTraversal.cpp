/* Recursive */
class Solution {
public:
    void traversal(TreeNode* root, vector<int>& result){
        if(!root)
            return;
        result.push_back(root -> val);
        traversal(root -> left, result);
        traversal(root -> right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};
 /* Iteration */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return{};
        stack<TreeNode*> memory;
        memory.push(root);
        vector<int> result;
        /* Continue when memory not empry or root is not nullptr*/
        while(!memory.empty()){
            /* Read top element and push it to result*/
            TreeNode* curr = memory.top();
            result.push_back(curr->val);
            memory.pop();
            /* Save right node first*/
            if(curr->right)
                memory.push(curr->right);
            /* Put left child on top of right child, read left first in next round*/
            if(curr->left)
                memory.push(curr->left);
        }
        return result;
    }
};