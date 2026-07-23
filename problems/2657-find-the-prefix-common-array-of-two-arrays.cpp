/*
 * Problem 2657: Find the Prefix Common Array of Two Arrays
 * URL     : https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
 * Solved  : 2026-05-20
 * Runtime : 4 ms
 * Memory  : 88.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        if(A.size()==0)
        return { };
        vector<int> prefixarr(A.size(),0);
        unordered_map<int,int> mp;
        if(A[0]==B[0])
        prefixarr[0]++;
        mp[A[0]]++;
        mp[B[0]]++;
        for(int i=1;i<A.size();i++)
        {
            prefixarr[i]=prefixarr[i-1];
            if(mp.find(A[i])!=mp.end())
            prefixarr[i]++;
            else
            mp[A[i]]++;
            if(mp.find(B[i])!=mp.end())
            prefixarr[i]++;
            else
            mp[B[i]]++;
        }
        return prefixarr;
    }
};