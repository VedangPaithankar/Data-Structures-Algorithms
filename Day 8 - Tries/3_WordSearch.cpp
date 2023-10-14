/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

https://leetcode.com/problems/word-search-ii/description/
*/

class TrieNode {
public:
    TrieNode() {
        is_end_of_word = false;
        children = std::vector<TrieNode*>(26, nullptr);
    }

    bool is_end_of_word;
    std::vector<TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(std::string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->is_end_of_word = true;
    }

    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        Trie trie;
        for (const std::string& word : words) {
            trie.insert(word);
        }

        std::vector<std::string> result;
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, m, n, trie.getRoot(), "", result);
            }
        }

        return result;
    }

private:
    void dfs(std::vector<std::vector<char>>& board, int i, int j, int m, int n, TrieNode* node, std::string current, std::vector<std::string>& result) {
        char ch = board[i][j];
        if (ch == '#' || node->children[ch - 'a'] == nullptr) {
            return;
        }

        node = node->children[ch - 'a'];
        current += ch;
        board[i][j] = '#';

        if (node->is_end_of_word) {
            result.push_back(current);
            node->is_end_of_word = false; // Avoid duplicate results
        }

        static const std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto& dir : directions) {
            int ni = i + dir.first;
            int nj = j + dir.second;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                dfs(board, ni, nj, m, n, node, current, result);
            }
        }

        board[i][j] = ch; // Restore the original character
    }
};