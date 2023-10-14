/*
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

https://leetcode.com/problems/binary-tree-right-side-view/description/
*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> q;

        if (root) {
            q.push(root);
        }

        while (!q.empty()) {
            int qLen = q.size();
            TreeNode* rightSide = nullptr; // Initialize rightSide to nullptr
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node) {
                    rightSide = node; // Update rightSide with the rightmost node
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
            }
            if (rightSide) {
                result.push_back(rightSide->val); // Assuming the TreeNode has a 'val' member
            }
        }
        return result;
    }
};
