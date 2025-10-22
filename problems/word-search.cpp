# Word Search
Solved on 2025-10-07

class Solution {
public:
    bool find(vector<vector<char>> & board,string word,int wind,int indr,int indc)
    {
        if(wind==word.length())
        return true;
        if(indr==board.size() || indc == board[0].size() || indr<0 || indc <0)
        return false;
        if(word[wind]!=board[indr][indc])
        return false;
        char temp = board[indr][indc];
        board[indr][indc]='#';
        bool res = find(board,word,wind+1,indr+1,indc)|| find(board,word,wind+1,indr-1,indc)|| find(board,word,wind+1,indr,indc+1)||find(board,word,wind+1,indr,indc-1);
        board[indr][indc]=temp;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res;
        res= find(board,word,0,0,0);
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0] && find(board,word,0,i,j))
                return true;
            }
        }
        return false;
    }
};