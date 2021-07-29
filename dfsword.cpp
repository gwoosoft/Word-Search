class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word, int r,int c,int start){
        if(start == word.size()) return true; 
        if(r<0||c<0||r>board.size()-1||c>board[0].size()-1) return false;
        if(board[r][c]!=word[start]) return false;
        board[r][c]='*'; //to avoid
        bool res=dfs(board,word,r+1,c,start+1)||dfs(board,word,r,c+1,start+1)||dfs(board,word,r-1,c,start+1)||dfs(board,word,r,c-1,start+1);
        board[r][c]=word[start]; //bring it back 
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int start=0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(dfs(board,word, i, j, start)) return true;
            }
        }
        return false;
    }
};
