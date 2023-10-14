/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
*/

class Codec {
public:
    // Encodes a tree to a string.
    string serialize(TreeNode* root) {
        if (!root) {
            return "X"; // Represent null nodes
        }

        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);

        return to_string(root->val) + "," + leftStr + "," + rightStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        string token;
        queue<string> tokens;

        while (getline(iss, token, ',')) {
            tokens.push(token);
        }

        return buildTree(tokens);
    }

private:
    TreeNode* buildTree(queue<string>& tokens) {
        string token = tokens.front();
        tokens.pop();

        if (token == "X") {
            return NULL; // Null node
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = buildTree(tokens);
        root->right = buildTree(tokens);

        return root;
    }
};