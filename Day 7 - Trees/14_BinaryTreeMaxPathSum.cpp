/*
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
*/

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible value
        findMaxPathSum(root, maxSum);
        return maxSum;
    }

    int findMaxPathSum(TreeNode* node, int &maxSum) {
        if (!node) {
            return 0;
        }

        // Calculate the maximum path sum in the left and right subtrees
        int leftMax = max(0, findMaxPathSum(node->left, maxSum));
        int rightMax = max(0, findMaxPathSum(node->right, maxSum));

        // Calculate the maximum path sum passing through the current node
        int nodeMax = node->val + leftMax + rightMax;

        // Update maxSum with the maximum path sum found so far
        maxSum = max(maxSum, nodeMax);

        // Return the maximum path sum that can be extended from the current node
        return node->val + max(leftMax, rightMax);
    }
};
