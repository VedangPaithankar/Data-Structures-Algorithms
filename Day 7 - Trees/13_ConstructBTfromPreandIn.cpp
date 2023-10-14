/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return nullptr; // Return nullptr for empty input arrays
        }

        TreeNode* root = new TreeNode(preorder[0]); // Create the root node

        int mid = 0;
        while (inorder[mid] != preorder[0]) {
            mid++;
        }

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);

        vector<int> rightPreorder(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};