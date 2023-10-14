/*
Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.

https://leetcode.com/problems/subtree-of-another-tree/description/
*/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) {
            return false; // If the main tree is empty, there's no subtree.
        }
        
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (!s && !t) {
            return true; // Both trees are empty, so they are the same.
        }
        if (!s || !t) {
            return false; // One tree is empty while the other is not, so they are different.
        }
        
        return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
};
