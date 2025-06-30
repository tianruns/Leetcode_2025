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
    void walk(TreeNode* node, vector<int>& backWay, vector<string>& result){
        /*Add node to the path*/
        backWay.push_back(node->val);
        /* End condition : leaf node reached*/
        if(node->left == nullptr && node->right == nullptr){
            /* Add a new path to result*/
            string path;
            for(int i = 0; i < backWay.size() - 1; ++i){
                path += to_string(backWay[i]);
                path += "->";
            }
            path += to_string(backWay.back());
            result.push_back(path);
            return;
        }
        if(node->left){
            /* After walk, clear the backWay so new path can be record*/
            walk(node->left, backWay, result);
            backWay.pop_back();
        }
        if(node->right){
            walk(node->right, backWay, result);
            backWay.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr)
            return{};
        vector<int> backWay;
        vector<string> paths;
        walk(root, backWay, paths);
        return paths;
    }
};