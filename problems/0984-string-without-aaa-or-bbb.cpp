/*
 * Problem 0984: String Without AAA or BBB
 * URL     : https://leetcode.com/problems/string-without-aaa-or-bbb/
 * Solved  : 2026-07-25
 * Runtime : 0 ms
 * Memory  : 8.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res;
        if(a>=b)
        {
            while(a>0 && b>0)
            {int sep =a/2;
            if(a%2==0)
            sep--;
            int j=0;
            while(j<2 && a)
            {
                res+='a';
                j++;
                a--;
            }
            if((2*sep)>b)
            {
                res+='b';
                b--;
            }
            else
            {
                j=0;
                while(j<2 && b)
                {
                    res+='b';
                    b--;
                    j++;
                }
            }
            }
            while(a--)
            res+='a';
            while(b--)
            res+='b';
        }
        else
        {
            while(a>0 && b>0)
            {
                int sep =b/2;
                if(b%2==0)
                sep--;
                int j=0;
                while(j<2 && b)
                {
                    res+='b';
                    j++;
                    b--;
                }
                if((2*sep)>a)
                {
                    res+='a';
                    a--;
                }
                else
                {
                    j=0;
                    while(j<2 && a)
                    {
                        res+='a';
                        a--;
                        j++;
                    }
                } 
            }  
            while(b--)
            res+='b';
            while(a--)
            res+='a';
            }
        return res;
    }
};