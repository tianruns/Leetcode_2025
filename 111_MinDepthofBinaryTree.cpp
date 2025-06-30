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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> memory;
        int level = 0;
        memory.push(root);
        while(!memory.empty()){
            int size = memory.size();
            ++level;
            /* Loop each layer */
            for(int i = 0; i < size; ++i){
                TreeNode* curr = memory.front();
                int origin = memory.size();
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
                /* No left or right node is added, root reaches end */
                if(origin == memory.size())
                    return level;
                memory.pop();
            }
        }
        return level;
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
    int height(TreeNode* root) {
        if(!root)
            return 0;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return (leftH * rightH == 0)? 1 + max(leftH, rightH): 1 + min(leftH, rightH);
    }
    int minDepth(TreeNode* root) {
        return height(root);
    }
};