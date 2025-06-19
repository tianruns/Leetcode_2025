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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()){
            vector<int> curr;
            int size = level.size();
            for(int i = 0; i < size; ++i){
                /* Read the top element from queue and pop it*/
                TreeNode* node = level.front();
                curr.push_back(node->val);
                level.pop();
                /* And the node's left and right child */
                if(node->left)
                    level.push(node->left);
                if(node->right)
                    level.push(node->right);
            }
            result.push_back(curr);
        }
        return result;
    }
};