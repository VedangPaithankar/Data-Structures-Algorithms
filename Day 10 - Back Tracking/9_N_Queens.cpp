/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

https://leetcode.com/problems/n-queens/description/
*/

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.')); // Initialize the chessboard

        solveNQueensHelper(0, n, board, result);
        return result;
    }

private:
    void solveNQueensHelper(int row, int n, std::vector<std::string>& board, std::vector<std::vector<std::string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                solveNQueensHelper(row + 1, n, board, result);
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(int row, int col, int n, const std::vector<std::string>& board) {
        // Check the same column above
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check the left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
};
