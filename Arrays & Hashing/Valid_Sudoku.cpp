// Implementation Idea
// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
   public:
    bool validRow(vector<vector<char>>& board, int row) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.') continue;
            mp[board[row][i]]++;
            if (mp[board[row][i]] > 1) return false;
        }
        return true;
    }
    bool validCol(vector<vector<char>>& board, int col) {
        unordered_map<char, int> mp;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.') continue;
            mp[board[i][col]]++;
            if (mp[board[i][col]] > 1) return false;
        }
        return true;
    }
    bool validBox(vector<vector<char>>& board, int row, int col) {
        unordered_map<char, int> mp;
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if (mp[board[i][j]] > 1) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!validRow(board, i)) return false;
            if (!validCol(board, i)) return false;
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!validBox(board, i, j)) return false;
            }
        }
        return true;
    }
};

// Implementation Idea Enhanced check one time
// Time Complexity : O(1)
// Space Complexity : O(1)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false)),
            cols(9, vector<bool>(9, false)), boxes(9, vector<bool>(9, false));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    
                    if (rows[i][num] or cols[j][num] or boxes[boxIndex][num])
                        return false;
                    rows[i][num] = cols[j][num] = boxes[boxIndex][num] = true;
                }
            }
        }
        return true;
    }
};

