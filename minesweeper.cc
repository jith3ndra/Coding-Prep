
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        if(board[click[0]][click[1]]=='B' || board[click[0]][click[1]]<='8' && board[click[0]][click[1]]>='1'){
            return board;
        }
        if(board[click[0]][click[1]]=='M') {
            board[click[0]][click[1]] ='X';
            return board;
        }else{
            int count=0;
            if(click[0]!=0){
                count+=board[click[0]-1][click[1]]=='M'?1:0;
                if(click[1]!=0){
                    count+=board[click[0]-1][click[1]-1]=='M'?1:0;
                }
                if(click[1]!=board[0].size()-1){
                    count+=board[click[0]-1][click[1]+1]=='M'?1:0;
                }
            }
            if(click[0]!=board.size()-1){
                count+=board[click[0]+1][click[1]]=='M'?1:0;
                if(click[1]!=0){
                    count+=board[click[0]+1][click[1]-1]=='M'?1:0;
                }
                if(click[1]!=board[0].size()-1){
                    count+=board[click[0]+1][click[1]+1]=='M'?1:0;
                }
            }
            if(click[1]!=0){
                count+=board[click[0]][click[1]-1]=='M'?1:0;
            }
            if(click[1]!=board[0].size()-1){
                count+= board[click[0]][click[1]+1]=='M'?1:0;
            }
            if(count==0){
                board[click[0]][click[1]]='B';
                if(click[0]!=0){
                    click[0]--;
                    updateBoard(board,click);
                    if(click[1]!=0){
                        click[1]--;
                        updateBoard(board,click);  
                        click[1]++;
                    }
                    if(click[1]!=board[0].size()-1){
                        click[1]++;
                        updateBoard(board,click);
                        click[1]--;
                    }
                    
                    click[0]++;
                }
                if(click[0]!=board.size()-1){
                    click[0]++;
                    updateBoard(board,click);
                    
                    if(click[1]!=0){
                        click[1]--;
                        updateBoard(board,click);
                        click[1]++;
                    }
                    
                    
                    if(click[1]!=board[0].size()-1){
                        click[1]++;
                        updateBoard(board,click);
                        click[1]--;
                    }
                    
                    click[0]--;
                }
                if(click[1]!=0){
                    click[1]--;
                    updateBoard(board,click);
                    click[1]++;
                }
                if(click[1]!=board[0].size()-1){
                    click[1]++;
                    updateBoard(board,click);
                    click[1]--;
                }
                return board;
            }else{
                board[click[0]][click[1]]='0'+count;
                return board;
            }
        }
    }
