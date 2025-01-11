// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            // Check row and column
            if (board[row][i] == val) return false;
            if (board[i][col] == val) return false;

            // Check 3x3 sub-grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row][col] == '.') continue;
                char val = board[row][col];
                board[row][col] = '.';
                if (!isSafe(row, col, board, val)) return false;
                board[row][col] = val;
            }
        }
        return true; 
    }
};