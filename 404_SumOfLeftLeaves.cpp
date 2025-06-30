/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfTree(TreeNode* node){
        /* right leaf node or single node*/
        if(node->left == nullptr && node->right == nullptr)
            return 0;
        int sum = 0;
        if(node->left){
            /* Add directly when left node is leaf nodes*/
            if(node->left->left == nullptr && node->left->right == nullptr)
                sum += node->left->val;
            else
                sum += sumOfTree(node->left);
        }
        if(node->right)
            sum += sumOfTree(node->right);
        return sum;

    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfTree(root);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        stack<TreeNode*> memory;
        int sum = 0;
        memory.push(root);
        while(!memory.empty()){
            TreeNode* curr = memory.top();
            memory.pop();
            if(curr->left && curr->left->left == nullptr 
                          && curr->left->right == nullptr)
                sum += curr->left->val;
            if(curr->left)
                memory.push(curr->left);
            if(curr->right)
                memory.push(curr->right);
        }
        return sum;
    }
};