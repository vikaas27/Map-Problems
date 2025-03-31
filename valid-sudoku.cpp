#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<map<char, bool>> rows(9), cols(9), boxes(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                
                if (c == '.') {
                    continue;
                }
                
                if (rows[i].count(c) > 0) {
                    return false;
                }
                rows[i][c] = true;
              
                if (cols[j].count(c) > 0) {
                    return false;
                }
                cols[j][c] = true;
               
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(c) > 0) {
                    return false;
                }
                boxes[boxIndex][c] = true;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
  
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    cout << "Board is " << (sol.isValidSudoku(board)? "valid" : "invalid") << endl;
    return 0;
}
