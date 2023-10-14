/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result; // Corrected the data type
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }

        while (!q.empty()) { // Use !q.empty() instead of q.size() > 0
            int qLen = q.size();
            vector<int> level; // Corrected the variable name
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front(); // Use q.front() to get the front element
                q.pop(); // Use q.pop() to remove the front element
                if (node) {
                    level.push_back(node->val); // Assuming the TreeNode has a 'val' member
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            if (!level.empty()) { // Check if the level is not empty
                result.push_back(level);
            }
        }
        return result; // Return the result at the end
    }
};
