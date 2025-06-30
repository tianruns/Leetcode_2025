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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> memory;
        int count = 0;
        memory.push(root);
        while(!memory.empty()){
            int size = memory.size();
            for(int i = 0; i < size; ++i){
                TreeNode* curr = memory.front();
                memory.pop();
                ++count;
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
            }
        }
        return count;
    }
};