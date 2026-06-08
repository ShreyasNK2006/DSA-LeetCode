/*
 * Problem 2126: Destroying Asteroids
 * URL     : https://leetcode.com/problems/destroying-asteroids/
 * Solved  : 2026-05-31
 * Runtime : 211 ms
 * Memory  : 137.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        map<long long,int> mp;
        for(int i=0;i<asteroids.size();i++)
        {
            mp[asteroids[i]]++;
        }
        int c=0;
        long long m=mass;
        while(c!=asteroids.size())
        {
            auto it = mp.upper_bound(m);
            if(it==mp.begin())
            return false;
            it--;
            m+=it->first;
            mp[it->first]--;
            if(mp[it->first]==0)
            mp.erase(it->first);
            c++;
        }
        if(!mp.size())
        return true;
        else
        return false;
    }
};