/*
 * Problem 2161: Partition Array According to Given Pivot
 * URL     : https://leetcode.com/problems/partition-array-according-to-given-pivot/
 * Solved  : 2026-06-08
 * Runtime : 8 ms
 * Memory  : 135.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        queue<int>q;
        int c=0;
        for(int x:nums)
        {
            if(x<pivot)
            res.push_back(x);
            else if(x>pivot)
            q.push(x);
            else c++;
        }
        while(c)
        {
            res.push_back(pivot);
            c--;
        }
        while(!q.empty())
        {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};