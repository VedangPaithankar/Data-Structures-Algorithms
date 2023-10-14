/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

https://leetcode.com/problems/validate-binary-search-tree/description/
*/

class Solution {
public:
    bool dfs(TreeNode* node, long long minVal, long long maxVal) {
        if (node == nullptr) {
            return true; // An empty subtree is a valid BST.
        }

        if (node->val <= minVal || node->val >= maxVal) {
            return false; // Node's value is out of the valid range.
        }

        // Check the left and right subtrees with updated min and max values.
        bool leftValid = dfs(node->left, minVal, node->val);
        bool rightValid = dfs(node->right, node->val, maxVal);

        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX); // Use long long to handle edge cases.
    }
};