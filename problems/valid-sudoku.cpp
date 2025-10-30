# Valid Sudoku
Solved on 2025-10-11

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         int row=0;
         unordered_map<char,int> check;
         for(int i=0;row!=board.size();i++)//row wise check
         {
            if(board[row][i]>='1' && board[row][i]<='9')
            check[board[row][i]]++;
            if(check[board[row][i]]>1)
            return false;
            if(i==board[0].size()-1)
            {
                i=-1;
                row++;
                check.clear();
            }
         }
         row=0;
         check.clear();
         for(int i=0;row!=board.size();i++)//column wise check
         {
            if(board[i][row]>='1' && board[i][row]<='9')
            check[board[i][row]]++;
            if(check[board[i][row]]>1)
            return false;
            if(i==board.size()-1)
            {
                i=-1;
                row++;
                check.clear();
            }
         }
        check.clear();
        int rowboundary=1;
        while(rowboundary<=3)
        {
            int rowend = 3*rowboundary;
            int col=3;
            while(col<=9)
            {
            for(int i=col-3;i<col;i++)
            {
                for(int j=rowend-3;j<rowend;j++)
                {
                    if(board[j][i]>='1' && board[j][i]<='9')
                    check[board[j][i]]++;
                    if(check[board[j][i]]>1)
                    return false;
                }

            }
            check.clear();
            col+=3;
            }
            rowboundary++;
        }
        return true;
    }
};