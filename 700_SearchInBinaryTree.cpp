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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        TreeNode* result = nullptr;
        while(root != nullptr){
            /* Compare curr node with target*/
            if(root->val == val){
                result = root;
                break;
            }
            else if(root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        return result;
    }
};