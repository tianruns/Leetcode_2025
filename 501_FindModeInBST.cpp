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
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> memory;
        vector<int> result;
        TreeNode* curr = root;
        int count = 0;
        int maxCount = 0;
        TreeNode* pre = nullptr;
        if(curr == nullptr)
            return {};
        while(curr != nullptr || !memory.empty()){
            if(curr){
                memory.push(curr);
                curr = curr->left;
                continue;
            }
            curr = memory.top();
            memory.pop();
            /*First node*/
            if(pre == nullptr)
                count = 1;
            /*Same node*/
            else if (pre->val == curr->val)
                ++count;
            /*New node*/
            else
                count = 1;
            /*New maxcount node*/
            if(count > maxCount){
                maxCount = count;
                result.clear();
                result.push_back(curr->val);
            }
            /*Same amount node*/
            else if(count == maxCount)
                result.push_back(curr->val);
            /*Update previous node*/
            pre = curr;
            curr = curr->right;
        }
        return result;

    }
};