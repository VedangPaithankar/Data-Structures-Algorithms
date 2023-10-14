/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

https://leetcode.com/problems/diameter-of-binary-tree/description/
*/

class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int diameter = 0;
            dfs(root, diameter);
            return diameter;
        }

    private:
        int dfs(TreeNode* node, int& diameter) {
            if (!node) {
                return 0;
            }
            
            int left_depth = dfs(node->left, diameter);
            int right_depth = dfs(node->right, diameter);
            
            diameter = std::max(diameter, left_depth + right_depth);
            
            return 1 + std::max(left_depth, right_depth);
        }
};