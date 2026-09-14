/*
 * Problem 0464: Can I Win
 * URL     : https://leetcode.com/problems/can-i-win/
 * Solved  : 2026-08-21
 * Runtime : 771 ms
 * Memory  : 91.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    unordered_map<int,bool> mp;
    vector<bool> used;
    bool canIWin(int mc, int dt) {
        int sum = (mc*(mc+1))/2;
        if(sum<dt)
        return false;
        if(dt==0)
        return true;
        used.resize(mc+1,false);
        return permute(dt);
    }
    bool permute(int dt)
    {
        if(dt<=0)
        return false;
        int key =bitmask();
        if(mp.count(key)==0){
        for(int i=1;i<used.size();i++)
        {
            if(!used[i])
            {
                used[i]=true;
                if(!permute(dt-i))
                {
                    mp[key]=true;
                    used[i]=false;
                    return true;
                }
                used[i]=false;
            }
        }
        mp[key]=false;
    }
    return mp[key];
    }
    int bitmask()
    {
        int k=0;
        for(bool x:used)
        {
            k<<=1;
            if(x)
            k|=1;
        }
        return k;
    }
};