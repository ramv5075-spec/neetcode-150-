// NeetCode 150 - Arrays & Hashing
// Problem: Valid Sudoku
// Difficulty: Medium
// Approach: Track counts for rows, cols, and 3x3 boxes
// Time Complexity: O(1)  (board size is fixed 9x9)
// Space Complexity: O(1)

#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0};
        int col[9][9] = {0};
        int block[3][3][9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int number = board[r][c] - '1';  // 0..8
                if (row[r][number]++) return false;
                if (col[c][number]++) return false;
                if (block[r / 3][c / 3][number]++) return false;
            }
        }
        return true;
    }
};
