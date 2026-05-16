/*
 * Problem 1539: Kth Missing Positive Number
 * URL     : https://leetcode.com/problems/kth-missing-positive-number/
 * Solved  : 2026-05-01
 * Runtime : 0 ms
 * Memory  : 13.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),j=1;
        int m=0;
        int res=0;
        int i=0;
        while(m<k)
        {
            if(i<n && j!=arr[i])
            {
                res=j;
                m++;
                j++;
                continue;
            }
            else if(i<n && j==arr[i])
            {
                i++;
                j++;
            }
            else
            {
                res=j;
                m++;
                j++;
            }
        }
        return res;
    }
};