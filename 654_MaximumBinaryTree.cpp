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
    TreeNode* build(vector<int>::iterator begin, vector<int>::iterator end){
        if(begin == end)
            return nullptr;
        int maxIndex = 0;
        for(int i = 1; i < (end - begin); ++i){
            maxIndex = *(begin + i)> *(begin + maxIndex) ? i:maxIndex;
        }
        TreeNode* node = new TreeNode(*(begin + maxIndex));
        if(begin + 1 == end)
            return node;
        if(maxIndex == 0){
            node->right = build(begin+1, end);
        }
        else if( maxIndex > 0 && maxIndex < (end - begin - 1)){
            node->left = build(begin, begin + maxIndex);
            node->right = build(begin + maxIndex + 1, end);
        }
        else
            node->left = build(begin, end - 1);
        return node;
        }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums.begin(), nums.end());
    }
};