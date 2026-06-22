class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Rows
        for(int i = 0;i< 9;i++){
            unordered_map<int,int>mp;
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(mp.find(board[i][j]) != mp.end()){
                    return false;
                }
                mp[board[i][j]] = 1;
            }
        }
        // Columns
        for(int i = 0;i<9;i++){
            unordered_map<int,int>mp;
            for(int j = 0;j<9;j++){
                if(board[j][i] == '.'){
                    continue;
                }
                if(mp.find(board[j][i]) != mp.end()){
                    return false;
                }
                mp[board[j][i]] = 1;
            }
        }
        // 3x3
        for(int i = 0;i<9;i+=3){
            for(int j = 0;j<9;j+=3){
                unordered_map<int,int> mp;
                for(int k = i;k<i+3;k++){
                    for(int l = j;l<j+3;l++){
                        if(board[k][l] == '.'){
                            continue;
                        }
                        if(mp.find(board[k][l])!= mp.end()){
                            return false;
                        }
                        mp[board[k][l]] = 1;
                    }
                }
            }
        }
        return true;
    }
};