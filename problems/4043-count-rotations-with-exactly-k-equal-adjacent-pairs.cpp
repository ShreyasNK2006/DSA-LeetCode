/*
 * Problem 4043: Count Rotations With Exactly K Equal Adjacent Pairs
 * URL     : https://leetcode.com/problems/count-rotations-with-exactly-k-equal-adjacent-pairs/
 * Solved  : 2026-09-06
 * Runtime : 30 ms
 * Memory  : 40.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int countRotations(string s, int k) {
        int c=0;
        queue<char> q;
        for(int i=0;i<s.size();i++)
        {
            q.push(s[i]);
        }
        for(int i=0;i<q.size();i++)
        {
            queue<char> cp=q;
            char t = cp.front();
            cp.pop();
            int s=0;
            while(!cp.empty())
            {
                if(t==cp.front())
                s++;
                t=cp.front();
                cp.pop();
            }
            if(s==k)
            c++;
            t=q.front();
            q.pop();
            q.push(t);
        }
        return c;
    }
};