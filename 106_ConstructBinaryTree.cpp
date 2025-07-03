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
    TreeNode* build(const vector<int>::iterator inBegin, const vector<int>::iterator inEnd, 
                    const vector<int>::iterator postBegin, const vector<int>::iterator postEnd){
        if(inBegin == inEnd)
            return nullptr;
        
        /* Create a TreeNode on heap*/
        TreeNode* node = new TreeNode(*(postEnd - 1));
        if(inBegin + 1 == inEnd)
            return node;
        int rootIndex = 0;
        /* Seperate left tree and right tree*/
        for(auto i = inBegin; i < inEnd; ++i, ++rootIndex){
            /* find the number of left tree elements*/
            if(*i == node->val)
                break;
        }
        // vector<int>leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        // vector<int>rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        // /* create subvector*/
        // vector<int>leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // vector<int>rightPostorder(postorder.begin() + leftInorder.size(), 
        //                           postorder.begin() + leftInorder.size() + rightInorder.size());
        node->left = build(inBegin, inBegin+rootIndex, postBegin, postBegin+rootIndex);
        node->right= build(inBegin+rootIndex+1, inEnd, postBegin+rootIndex, postEnd-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode();
        root = build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        return root;
    }
};