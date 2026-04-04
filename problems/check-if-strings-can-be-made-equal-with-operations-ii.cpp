/*
 * Problem: Check if Strings Can be Made Equal With Operations II
 * Solved on: 2026-03-30
 * Runtime: 31 ms
 * Memory: 20.8 MB
 * 
 * Explanation: (AI generation failed)
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<s1.size();i++)
        {
            if(i%2==0)
            mp1[s1[i]]++;
            else
            mp2[s1[i]]++;
        }
        for(int i=0;i<s1.size();i++)
        {
            if(i%2==0)
            {
                if(mp1[s2[i]]>0)
                {
                    mp1[s2[i]]--;
                }
                else
                return false;
            }
            else
            {
                if(mp2[s2[i]]>0)
                {
                    mp2[s2[i]]--;
                }
                else 
                return false;
            }
        }
        return true;
    }
};