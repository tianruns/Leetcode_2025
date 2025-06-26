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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int level = 0;
        queue<TreeNode*> memory;
        memory.push(root);
        while(!memory.empty()){
            int size = memory.size();
            ++level;
            for(int i = 0; i < size; ++i){
                TreeNode* curr = memory.front();
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
                memory.pop();
            }
        }
        return level;
    }
};