# Ones and Zeroes
Solved on 2025-11-12

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(string s: strs)
        {
            int ones=0,zeroes =0;
            for(char c:s)
            {
                if(c=='0')
                zeroes++;
                else
                ones++;
            }
            for(int i=m;i>=zeroes;i--)
            {
                for(int j=n;j>=ones;j--)
                {
                    dp[i][j] = max(dp[i][j],1+dp[i-zeroes][j-ones]);
                }
            }
        }
        return dp[m][n];
    }
};