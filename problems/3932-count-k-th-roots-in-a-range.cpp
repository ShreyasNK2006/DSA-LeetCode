/*
 * Problem 3932: Count K-th Roots in a Range
 * URL     : https://leetcode.com/problems/count-k-th-roots-in-a-range/
 * Solved  : 2026-05-17
 * Runtime : 5 ms
 * Memory  : 9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        int c=0;
        int x= round(pow(l,1.0/k));
        int st=x;
        if((int)pow(x,k)>=l)
            st--;
        int end=round(pow(r,1.0/k));
        if((int)pow(end,k)>r)
            end--;
        cout<<st<<endl<<end;
        return end-st;
    }
};