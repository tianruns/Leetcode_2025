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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        vector<double> average;
        queue<TreeNode*> memory;
        memory.push(root);
        while(!memory.empty()){
            int size = memory.size();
            double sum = 0;
            for(int i = 0; i < size; ++i){
                /* Loop each element in the queue(layer)*/
                TreeNode* curr = memory.front();
                sum += curr->val;
                /* Remove old element*/
                memory.pop();
                /* Add new element next level*/
                if(curr->left)
                    memory.push(curr->left);
                if(curr->right)
                    memory.push(curr->right);
            }
            average.push_back(sum/(double)size);
        }
        return average;
    }
};