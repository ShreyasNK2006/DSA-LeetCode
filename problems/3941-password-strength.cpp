/*
 * Problem 3941: Password Strength
 * URL     : https://leetcode.com/problems/password-strength/
 * Solved  : 2026-05-30
 * Runtime : 18 ms
 * Memory  : 18 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int passwordStrength(string password) {
        int s=0;
        unordered_set<char> special={'!','@','#','$'};
        unordered_set<char> stl,stu,stn;
        for(char c:password)
            {
                if(c>='a' && c<='z' && stl.find(c)==stl.end())
                {
                    s+=1;
                    stl.insert(c);
                }
                else if(c>='A' && c<='Z' && stu.find(c)==stu.end())
                {
                    s+=2;
                    stu.insert(c);
                }
                else if(c>='0' && c<='9' && stn.find(c)==stn.end())
                {
                    s+=3;
                    stn.insert(c);
                }
                else if(special.find(c)!=special.end())
                {
                    s+=5;
                    special.erase(c);
                }
            }
        return s;
    }
};