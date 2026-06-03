/*
 * Problem 0299: Bulls and Cows
 * URL     : https://leetcode.com/problems/bulls-and-cows/
 * Solved  : 2026-04-27
 * Runtime : 0 ms
 * Memory  : 8.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10,0);
        int n=secret.size();
        for(int i=0;i<n;i++)
        {
            freq[secret[i]-'0']++;
        }
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                x++;
                freq[secret[i]-'0']--;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i] && freq[guess[i]-'0']>0)
            {
                y++;
                freq[guess[i]-'0']--;
            }
        }
        string res=to_string(x)+"A"+to_string(y)+"B";
        return res;
    }
};