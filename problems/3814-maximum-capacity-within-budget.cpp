/*
 * Problem 3814: Maximum Capacity Within Budget
 * URL     : https://leetcode.com/problems/maximum-capacity-within-budget/
 * Solved  : 2026-05-16
 * Runtime : 263 ms
 * Memory  : 295.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int score=0;
        int n=costs.size();
        vector<pair<int,int>> pr(n);
        for(int i=0;i<n;i++)
            {
                pr[i]={costs[i],capacity[i]};
            }
        sort(pr.begin(),pr.end());
        vector<int> maxcap(n,0);
        int cap=pr[0].second;
        map<int,int> mp;
        for(int i=0;i<n;i++)
            {
                if(pr[i].first>=budget)
                    break;
                else
                {
                    int s=pr[i].second;
                    int r= budget-pr[i].first-1;
                    auto it = mp.lower_bound(r);
                    if(it->first==r)
                        s+=it->second;
                    else if(it!=mp.begin())
                        s+=prev(it)->second;
                    cap=max(cap,pr[i].second);
                    mp[pr[i].first]=cap;
                    score=max(score,s);
                }
            }
        return score;
    }
};