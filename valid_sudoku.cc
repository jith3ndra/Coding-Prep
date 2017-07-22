

 bool check_row(vector<vector<char>>& board ,int row,int size){
        vector<int> vect(10,1);
        for(int i=0;i<size;i++){
            if(board[row][i]!='.') 
                vect[board[row][i]-'0']--;
        }
        for(int i=0;i<10;i++){
            if(vect[i]<0){
                return false;
            }
        }
        return true;
    }
    bool check_col(vector<vector<char>>& board ,int col,int size){
        vector<int> vect(10,1);
        for(int i=0;i<size;i++){
            if(board[i][col]!='.') 
                vect[board[i][col]-'0']--;
        }
        for(int i=0;i<10;i++){
            if(vect[i]<0){
                return false;
            }
        }
        return true;
    }
    bool check_sqr(vector<vector<char>>& board ,int idx,int size){
        vector<int> vect(10,1);
        int col = (idx*3)%9 ;
        int row = (idx*3)/9 ;
        row *=3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++)
            if(board[i][j]!='.') 
                vect[board[i][j]-'0']--;
        }
        for(int i=0;i<10;i++){
            if(vect[i]<0){
                return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        for(int i=0;i<size;i++){
            if( !check_row(board,i,size) || !check_col(board,i,size) || !check_sqr(board,i,size)){
                return false;
            }
        }
        return true;
    }
