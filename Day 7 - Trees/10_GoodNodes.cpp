/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
*/

class Solution {
public:
    int dfs (TreeNode* node, int maxVal){
        if(!node)
            return 0;
        int res = node->val >= maxVal ? 1 : 0;
        maxVal = max(maxVal, node->val);
        res += dfs (node->left, maxVal);
        res += dfs (node->right, maxVal);
        return res;
    }

    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};