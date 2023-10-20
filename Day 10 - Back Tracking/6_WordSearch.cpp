/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

https://leetcode.com/problems/word-search/description/
*/

class Solution {
public:
    bool dfs(int r, int c, int i, vector<vector<char>>& board, string word) {
        if (i == word.size()) {
            return true; // The entire word is found
        }

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]) {
            return false; // Out of bounds or character doesn't match
        }

        char originalChar = board[r][c]; // Store the original character
        board[r][c] = ' '; // Mark the cell as visited

        bool res = dfs(r + 1, c, i + 1, board, word) ||
                   dfs(r - 1, c, i + 1, board, word) ||
                   dfs(r, c + 1, i + 1, board, word) ||
                   dfs(r, c - 1, i + 1, board, word);

        board[r][c] = originalChar; // Restore the original character

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true; // If a valid path is found, return true
                }
            }
        }
        return false; // If no valid path is found, return false
    }
};