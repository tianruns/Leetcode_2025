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
    void traversal(TreeNode* node, vector<int>& path, vector<vector<int>>& result, int& count){
        /* Update the value of new node*/
        count -= node->val;
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            if(count == 0){
                result.push_back(path);
            }
            return;
        }
        if(node->left){
            traversal(node->left, path, result, count);
            count += node->left->val;
            path.pop_back();
        }
        if(node->right){
            traversal(node->right, path, result, count);
            count += node->right->val;
            path.pop_back();
        }
        //return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return {};
        vector<int>path;
        vector<vector<int>>result;
        traversal(root, path, result, targetSum);
        return result;
    }
};