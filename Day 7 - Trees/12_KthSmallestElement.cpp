/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
*/

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;

        while (currentNode || !nodeStack.empty()) {
            while (currentNode) {
                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = nodeStack.top();
            nodeStack.pop();

            if (currentNode) {
                result.push_back(currentNode->val);
            } else {
                result.push_back(-1); // Insert -1 for null nodes
            }

            currentNode = currentNode->right;
        }

        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root)[k-1];
    }
};