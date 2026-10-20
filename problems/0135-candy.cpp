/*
 * Problem 0135: Candy
 * URL     : https://leetcode.com/problems/candy/
 * Solved  : 2026-09-29
 * Runtime : 5 ms
 * Memory  : 71.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 0;
        int n = ratings.size();
        vector<int> score(n,1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                if(score[i]>score[i-1])
                continue;
                else
                score[i]=score[i-1]+1;
            }
            else
            {
                continue;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                if(score[i]>score[i+1])
                continue;
                else
                score[i]=score[i+1]+1;
            }
            else
            {
                continue;
            }
        }
        for(int i=0;i<n;i++)
        total+=score[i];
        return total;
    }
};