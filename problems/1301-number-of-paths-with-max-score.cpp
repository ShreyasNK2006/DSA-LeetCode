/*
 * Problem 1301: Number of Paths with Max Score
 * URL     : https://leetcode.com/problems/number-of-paths-with-max-score/
 * Solved  : 2026-07-05
 * Runtime : 10 ms
 * Memory  : 11.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

#define MOD 1000000007
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{0,0}));
        dp[0][0]={0,1};
        for(int i=1;i<n;i++)
        {
            if(dp[0][i-1].second!=0 && board[0][i]!='X')
            {
                dp[0][i].second =1;
                dp[0][i].first=dp[0][i-1].first+(board[0][i]-'0');
            }
            else
            break;
        }
        for(int i=1;i<n;i++)
        {
            if(dp[i-1][0].second!=0 && board[i][0]!='X')
            {
                dp[i][0].second =1;
                dp[i][0].first+=dp[i-1][0].first+(board[i][0]-'0');
            }
            else
            break;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(i==n-1 && j==n-1)
                break;
                int l=dp[i][j-1].first;
                int t=dp[i-1][j].first;
                int d=dp[i-1][j-1].first;
                int maxd=max({l,t,d});
                if(board[i][j]!='X' &&maxd!=0)
               {
                    dp[i][j].first=(maxd+(board[i][j]-'0'))%MOD;
                    if(dp[i][j-1].first==maxd)
                    dp[i][j].second=(dp[i][j].second+dp[i][j-1].second)%MOD;
                    if(dp[i-1][j-1].first==maxd)
                    dp[i][j].second=(dp[i][j].second+dp[i-1][j-1].second)%MOD;
                    if(dp[i-1][j].first==maxd)
                    dp[i][j].second=(dp[i][j].second+dp[i-1][j].second)%MOD;
               }
            }
        }
        int maxs= max({dp[n-1][n-2].first,dp[n-2][n-2].first,dp[n-2][n-1].first});
        int f=0;
        //cout<<dp[n-1][n-2].first<<endl<<dp[n-2][n-2].first<<endl<<dp[n-2][n-1].first;
        if(maxs==dp[n-1][n-2].first)
        f=(f+dp[n-1][n-2].second)%MOD;
        if(maxs==dp[n-2][n-2].first)
        f=(f+dp[n-2][n-2].second)%MOD;
        if(maxs==dp[n-2][n-1].first)
        f=(f+dp[n-2][n-1].second)%MOD;
        return {maxs,f};
    }
};