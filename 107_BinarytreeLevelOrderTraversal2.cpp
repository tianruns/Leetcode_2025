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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> memory;
        memory.push(root);
        while(!memory.empty()){
            vector<int>level;
            int size = memory.size();
            for(int i = 0; i < size; ++i){
                TreeNode* curr = memory.front();
                memory.pop();
                level.push_back(curr->val);
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
            }
            result.push_back(level);
        }
        int left = 0, right = result.size() - 1;
        while(left < right)
            swap(result[left++], result[right--]);
        return result;
    }
};