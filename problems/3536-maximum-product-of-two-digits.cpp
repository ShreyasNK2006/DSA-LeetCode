/*
 * Problem 3536: Maximum Product of Two Digits
 * URL     : https://leetcode.com/problems/maximum-product-of-two-digits/
 * Solved  : 2026-07-25
 * Runtime : 0 ms
 * Memory  : 9.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxProduct(int n) {
        unordered_map<int,int> mp;
        while(n)
        {
            int d=n%10;
            mp[d]++;
            n/=10;
        }
        int g=0,sg=0;
        for(auto x:mp)
        {
            int f=x.second;
            while(f--)
            {
                if(x.first>=g)
                {
                    sg=g;
                }
                else
                sg=max(sg,x.first);
                g=max(g,x.first);
            }
        }
        return sg*g;
    }
};