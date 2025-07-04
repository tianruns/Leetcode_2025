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
    void iterate(TreeNode* root, vector<int>& tree){
        if(root == nullptr)
            return;
        stack<TreeNode*>memory;
        while(root || !memory.empty()){
            if(root){
                memory.push(root);
                root = root->left;
                continue;
            }
            root = memory.top();
            tree.emplace_back(root->val);
            memory.pop();
            root = root->right;
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int>tree;
        iterate(root, tree);
        for(int i = 0; i < tree.size() - 1; ++i){
            if(tree[i] >= tree[i + 1])
                return false;
        }
        return true;
    }
};