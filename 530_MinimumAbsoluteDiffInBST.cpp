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
    void traversal(TreeNode* curr, int& result){
        stack<TreeNode*> memory;   
        TreeNode* pre = nullptr;
        
        while(curr != nullptr || !memory.empty()){
            /*Iterate till the most left -> smallest value*/
            if(curr != nullptr){
                memory.push(curr);
                curr = curr->left;
                continue;
            }
            curr = memory.top();
            memory.pop();
            if(pre != nullptr)
                result = min(result, abs(curr->val-pre->val));
            pre = curr;
            /* After putting root node, go to right*/
            curr = curr->right;
        }
    }
    int getMinimumDifference(TreeNode* root) {
        
        int minDiff = INT_MAX;
        traversal(root, minDiff);
        
        return minDiff;
    }
};