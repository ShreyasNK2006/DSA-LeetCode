/*
 * Problem 2273: Find Resultant Array After Removing Anagrams
 * URL     : https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/
 * Solved  : 2026-07-13
 * Runtime : 0 ms
 * Memory  : 16.1 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        res.push_back(words[0]);
        int arr[26]={0};
                for(int j=0;j<words[0].size();j++)
                    arr[words[0][j]-'a']++;
                
                bool match=true;
                int i=1;
                while(i<words.size())
                    {
                        int arr2[26]={0};
                        match=true;
                        for(int j=0;j<words[i].size();j++)
                        arr2[words[i][j]-'a']++;
                        for(int j=0;j<26;j++)
                            {
                                if(arr[j]!=arr2[j])
                                {
                                    match=false;
                                }
                                arr[j]=arr2[j];
                            }
                        if(!match)
                            res.push_back(words[i]);
                        i++;
                        
                    }
            return res;
    }
};