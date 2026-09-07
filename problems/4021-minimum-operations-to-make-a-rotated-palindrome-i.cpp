/*
 * Problem 4021: Minimum Operations to Make a Rotated Palindrome I
 * URL     : https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
 * Solved  : 2026-08-15
 * Runtime : 419 ms
 * Memory  : 183.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int n;
    int minOperations(string s) {
        int minop =INT_MAX;
        n=s.size();
        deque<char> dq;
        for(auto c:s)
            dq.push_back(c);
        for(int i=0;i<n;i++)
            {
                {
                    deque<char> cp =dq;
                    int op=0;
                    while(cp.size()>1)
                        {
                            int x=abs(cp.front()-cp.back());
                            op+=min(x,26-x);
                            cp.pop_front();
                            cp.pop_back();
                        }
                    minop=min(minop,op+i);
                }
                char c=dq.front();
                dq.pop_front();
                dq.push_back(c);
            }
        
        return minop;
    }
};