class Solution {
public:
    void Invert(TreeNode* Node){
        /* End condition */
        if(!Node)
            return ;
        /* Swap left node and right node*/
        TreeNode* curr = Node->left;
        Node->left  = Node->right;
        Node->right = curr;
        /* Iterate left node and right node*/
        Invert(Node->left);
        Invert(Node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        Invert(root);
        return root;
    }
};