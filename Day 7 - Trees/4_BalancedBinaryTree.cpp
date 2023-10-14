/*
Given a binary tree, determine if it is 
height-balanced.

https://leetcode.com/problems/balanced-binary-tree/description/
*/

class Solution {
public:
    pair<bool, int> dfs(TreeNode* root) {
        if (!root)
            return {true, 0};
        pair<bool, int> left = dfs(root->left);
        pair<bool, int> right = dfs(root->right);
        
        bool balanced = (left.first && right.first && abs(left.second - right.second) <= 1);
        
        return {balanced, 1 + max(left.second, right.second)};
    }
    
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};