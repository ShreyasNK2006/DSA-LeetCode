/*
 * Problem 4007: Widest Possible Fence
 * URL     : https://leetcode.com/problems/widest-possible-fence/
 * Solved  : 2026-08-13
 * Runtime : 2944 ms
 * Memory  : 520.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maximumWidth(vector<int>& planks) {
         unordered_map<long long,int> mp,mp2;
        unordered_set<int> mp3;
        int n=planks.size();
        int ans=1;
        vector<int> temp;
        for(auto it:planks)
            {
                mp[it]++;
                mp2[it]++;
                if(mp[it]==1)
            temp.push_back(it);
                ans =max(ans,mp[it]);
            }
        //unordered_map<int,unordered_set<int>> st;
        int m= temp.size();
        for(int i=0;i<m;i++)
            {
                if(mp3.find(temp[i])!=mp3.end())
                    continue;
                mp3.insert(temp[i]);
                unordered_set<int> st2;
                for(int j=i;j<m;j++)
                    {
                        if(st2.find(temp[j])!=st2.end())
                            continue;
                        st2.insert(temp[j]);
                        if(temp[i]==temp[j])
                        {
                            mp2[1LL*2*temp[i]]+=(mp[temp[i]]/2);
                        }
                        else
                        {
                            mp2[1LL*temp[i]+temp[j]]+=min(mp[temp[i]],mp[temp[j]]);
                        }
                        ans=max(ans,mp2[1LL*temp[i]+temp[j]]);
                        //cout<<it.first<<" "<<it.second<<endl;
                        //cout<<mp2[it.first+it2.first]<<endl;
                    }
            }
        return ans;
    }
};