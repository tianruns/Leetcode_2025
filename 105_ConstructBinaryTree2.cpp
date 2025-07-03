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
    TreeNode* build(vector<int>::iterator preBegin, vector<int>::iterator preEnd,
                    vector<int>::iterator inBegin, vector<int>::iterator inEnd){
                        /* No node in the tree*/
                        if(preBegin == preEnd)
                            return nullptr;
                        TreeNode* node = new TreeNode(*preBegin);
                        /*Only one node in the tree*/
                        if(preBegin + 1 == preEnd)
                            return node;
                        /* Find seperate point in InOrder*/
                        int rootIndex = 0;
                        while(inBegin + rootIndex < inEnd){
                            /* Find the root node in the inOrder vector*/
                            if(*(inBegin + rootIndex) == node->val)
                                break;
                            ++rootIndex;
                        }
                        /* Left tree */
                        node->left = build(preBegin + 1, preBegin + 1 + rootIndex, inBegin, inBegin + rootIndex);
                        /* Right tree*/
                        node->right = build(preBegin + 1 + rootIndex, preEnd, inBegin + rootIndex + 1, inEnd);
                        return node;
                    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty())
            return nullptr;
        TreeNode* root = build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
        return root;
    }
};