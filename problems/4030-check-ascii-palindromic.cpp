/*
 * Problem 4030: Check ASCII Palindromic
 * URL     : https://leetcode.com/problems/check-ascii-palindromic/
 * Solved  : 2026-08-23
 * Runtime : 0 ms
 * Memory  : 9.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    string to_binary(int x)
    {
        string temp;
        while(x)
            {
                if(x%2==0)
                    temp+='0';
                else
                    temp+='1';
                x/=2;
            }
        int n =temp.size();
        while(n<8)
            {
                temp.push_back('0');
                n++;
            }
        //cout<<temp<<endl;
        reverse(temp.begin(),temp.end());
        return temp;
    }
    bool isPalindromic(string s) {
        string temp;
        for(auto c:s)
            {
                int x = c;
                temp+=(to_binary(x));
            }
        //cout<<temp;
        for(int i=0;i<temp.size();i++)
            {
                if(temp[i]==temp[temp.size()-1-i])
                    continue;
                else 
                    return false;
            }
        return true;
    }
};