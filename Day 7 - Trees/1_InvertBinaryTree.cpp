/*
Given the root of a binary tree, invert the tree, and return its root.

https://leetcode.com/problems/invert-binary-tree/description/
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return nullptr;

        TreeNode* r1 = root->left;
        root->left = root->right;
        root->right = r1; 

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};