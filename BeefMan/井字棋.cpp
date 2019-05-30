// 井字棋就是 3 ✖️ 3 的 格子
// 类似与三子棋

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        int sum_row = 0;
        int sum_cow = 0;
        for(int i = 0; i < row; i++){
            sum_row = 0;
            sum_cow = 0;
            for(int j = 0; j < row; j++){
                sum_row += board[i][j];
                sum_cow += board[j][i];
            }
            if(sum_row == 3)
                return true;
            if(sum_cow == 3)
                return true;
        }
        
        int first_diagonal = 0;
        int final_diagonal = 0;
        
        for(int i = 0; i < row; i++){
            first_diagonal += board[i][i];
            final_diagonal += board[i][row - i - 1];
            if(first_diagonal == 3)
                return true;
            if(final_diagonal == 3)
                return true;
        }
        
        return false;
        
        
    }
};