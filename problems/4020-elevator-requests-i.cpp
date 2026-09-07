/*
 * Problem 4020: Elevator Requests I
 * URL     : https://leetcode.com/problems/elevator-requests-i/
 * Solved  : 2026-08-15
 * Runtime : 0 ms
 * Memory  : 30.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans=requests[0];
        for(int i=1;i<requests.size();i++)
            {
                ans+=(abs(requests[i]-requests[i-1]));
            }
        return ans;
    }
};