
class Solution {
public:

    bool isAllowed(vector<vector<char>>& board, int row, int col, char n){
        int i,j;
        for( i = 0; i<9; i++){
            if(n == board[row][i]) return false;
        }
        for( j = 0; j<9; j++){
            if(n == board[j][col]) return false;
        }

        int r1 = row/3 * 3;
        int c1 = col/3 * 3;

        for( i = r1; i<r1 + 3; i++){
            for( j = c1; j<c1 + 3; j++){
                if(board[i][j] == n) return false;
            }
        }

        return true;

    }

    bool SUDOKU(vector<vector<char>>& board, int row, int col){

        if(col == 9){
            row++;
            col = 0;
        }  // going to next row

        if(row == 9){
            return true;
        }

        if(board[row][col] != '.'){
            return SUDOKU(board, row, col+1);    // Not a valid place to place
        }

        for(int digit = 1; digit <= 9; digit++){    // which number can we put?
            if(isAllowed(board, row, col, digit + '0')){   // convert to char
                board[row][col] = digit + '0';
                bool res = SUDOKU(board, row, col + 1);
                if(res==true) return true;
                board[row][col] = '.';              // backtrack
            }
        }
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        SUDOKU(board,0,0);
    }
};