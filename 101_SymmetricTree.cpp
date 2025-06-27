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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return false;
        stack<TreeNode*> memory;
        memory.push(root->right);
        memory.push(root->left);
        while(!memory.empty()){
            TreeNode* leftNode = memory.top();
            memory.pop();
            TreeNode* rightNode = memory.top();
            memory.pop();
            
            /* Both left and right node are null*/
            if(!leftNode && !rightNode)
                continue;
            /* If one of them is null OR value not symatric*/
            if(!leftNode || !rightNode || leftNode->val != rightNode->val)
                return false;
            
            memory.push(rightNode->left);
            memory.push(leftNode->right);
            memory.push(rightNode->right);
            memory.push(leftNode->left);
        }
    return true;
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
    bool Compare(TreeNode* leftNode, TreeNode* rightNode){
        if(!leftNode && !rightNode)
            return true;
        if(!leftNode && rightNode)
            return false;
        if(leftNode && !rightNode)
            return false;
        if(leftNode->val != rightNode->val)
            return false;
        /* Both leftNode and rightNode are valid*/
        bool outside = Compare(leftNode->left, rightNode->right);
        bool inside = Compare(leftNode->right, rightNode->left);
        return inside && outside;

    }

    bool isSymmetric(TreeNode* root) {
    return Compare(root->left, root->right);
    }
};