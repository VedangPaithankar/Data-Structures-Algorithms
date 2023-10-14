/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

https://leetcode.com/problems/same-tree/description/
*/

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        vector<int> result;
        if (root) {
            // Process the current node (e.g., add its value to the result vector).
            result.push_back(root->val);

            // Recursively visit the left and right subtrees.
            vector<int> leftValues = dfs(root->left);
            vector<int> rightValues = dfs(root->right);

            // Append the values from the left and right subtrees to the result vector.
            result.insert(result.end(), leftValues.begin(), leftValues.end());
            result.insert(result.end(), rightValues.begin(), rightValues.end());
        } else {
            // If the node is nullptr, you can add a special value (e.g., -1) to represent the absence.
            result.push_back(-1);
        }
        return result;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p)==dfs(q);
    }
};