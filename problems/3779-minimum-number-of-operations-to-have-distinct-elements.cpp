/*
 * Problem 3779: Minimum Number of Operations to Have Distinct Elements
 * URL     : https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/
 * Solved  : 2025-12-20
 * Runtime : 374 ms
 * Memory  : 271.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_map<int,int> unq;
        int check=0,count=0;
        for(auto it:nums)
            {
                freq[it]++;
                if(freq[it]>1)
                {
                    if(!(unq.find(it)!=unq.end()))
                    {
                        check++;
                        unq[it]=1;
                    }
                }
            }
        if(check==0)
            return 0;
        for(int j=0;j<nums.size();j+=3)
            {
                freq[nums[j]]--;
                if(freq[nums[j]]>0&&freq[nums[j]]<2)
                    check--;
                if(j+1<nums.size())
                {
                    freq[nums[j+1]]--;
                    if(freq[nums[j+1]]>0&&freq[nums[j+1]]<2)
                    check--;
                }
                if(j+2<nums.size())
                {
                    freq[nums[j+2]]--;
                    if(freq[nums[j+2]]>0&&freq[nums[j+2]]<2)
                    check--;
                }
                count++;
                if(check==0)
                    return count;
            }
            return count;
    }
};