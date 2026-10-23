/*
 * Problem 4048: Count Values With Equally Spaced Occurrences I
 * URL     : https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-i/
 * Solved  : 2026-09-12
 * Runtime : 12 ms
 * Memory  : 32.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int c=0;
        unordered_map<int,pair<int,int>> mp;
        unordered_map<int,int> fq;
        unordered_map<int,bool> valid;
        for(int i=0;i<nums.size();i++)
        {
            fq[nums[i]]++;
            if(fq[nums[i]]==3)
            {
                if((i-mp[nums[i]].second)==mp[nums[i]].first)
                {
                    c++;
                    valid[nums[i]]=true;
                }
                //cout<<i<<endl;
                
            }
            else if(fq[nums[i]]<3)
            {
                if(mp.find(nums[i])!=mp.end())
                {
                    mp[nums[i]].first = i-mp[nums[i]].second;
                    mp[nums[i]].second= i;
                }
                else
                {
                    mp[nums[i]].second =i;
                    mp[nums[i]].first=0;
                }
            }
            else
            {
                if(valid[nums[i]])
                {
                    c--;
                    valid[nums[i]]=false;
                }
                
                //cout<<i<<endl;
            }
        }
        
        return c;
    }
};