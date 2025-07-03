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
    bool traversal(TreeNode* node, int& count){
        count -= node->val;
        if(node->left == nullptr && node->right == nullptr){
            if(count == 0)
                return true;
            return false;
        }
        if(node->left){
            if (traversal(node->left, count))
                return true;
            else
                count += node->left->val;
        }
        if(node->right){
            if (traversal(node->right, count))
                return true;
            else
                count += node->right->val;
        }
        return false;
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        return traversal(root, targetSum);
    }
};