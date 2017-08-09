

void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int count =0;
                if(i!=0 ){
                    if(j!=0)
                        count += (board[i-1][j-1]&1);
                    if(j!=board[0].size()-1){
                        count += (board[i-1][j+1]&1);
                    }
                    count += (board[i-1][j]&1);
                }
                if(i!=board.size()-1){
                    if(j!=0)
                        count += (board[i+1][j-1]&1);
                    if(j!=board[0].size()-1)
                        count += (board[i+1][j+1]&1);
                    count += (board[i+1][j]&1);
                }
                if(j!=0)
                    count += (board[i][j-1]&1);
                if(j!=board[0].size()-1)
                    count += (board[i][j+1]&1);
                if(board[i][j]&1==1){
                    //initially alive
                    if(count <2 || count >3){
                        board[i][j] &= (0x1);//next state should be dead
                    }else{
                        board[i][j] |= (0x2);//next state alive;
                    }
                }else{
                    //initially dead
                    if(count ==3){
                        board[i][j] |= (0x2);//next state alive
                    }else{
                        board[i][j] &= (0x1);
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                board[i][j] = board[i][j]>>1;
            }
        }
    }
