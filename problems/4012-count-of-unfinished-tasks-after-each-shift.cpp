/*
 * Problem 4012: Count of Unfinished Tasks After Each Shift
 * URL     : https://leetcode.com/problems/count-of-unfinished-tasks-after-each-shift/
 * Solved  : 2026-08-12
 * Runtime : 150 ms
 * Memory  : 188.6 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        int m=shifts.size();
        vector<int> res(m,0);
        map<long long,int> mp;
        long long sum=0;
        for(int i=n-1;i>=0;i--)
            {
                sum+=1LL*tasks[i];
                mp[sum]=i;
            }
        long long t=sum;
        int ind=n;
        for(int i=0;i<m;i++)
            {
                if(t==0)
                 t=sum;
                if(t>shifts[i])
                {
                    t-=shifts[i];
                    ind = mp.lower_bound(t)->second;
                }
                else
                {
                    t=0;
                    ind=n;
                }
                res[i]=(n-ind);
            }
        return res;
    }
};