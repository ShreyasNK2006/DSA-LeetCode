/*
 * Problem 2515: Shortest Distance to Target String in a Circular Array
 * URL     : https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
 * Solved  : 2026-04-15
 * Runtime : 0 ms
 * Memory  : 18.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int mind=INT_MAX;
        for(int i=startIndex;i<words.size();i++)
        {
            if(target==words[i])
            {
                int temp =min(i-startIndex,startIndex+(int)words.size()-i);
                mind=min(mind,temp);
            }
        }
        for(int j=0;j<=startIndex;j++)
        {
            if(target==words[j])
            {
                int temp=min(startIndex-j,j+(int)words.size()-startIndex);
                mind=min(mind,temp);
            }
        }
        return mind!=INT_MAX?mind:-1;
    }
};