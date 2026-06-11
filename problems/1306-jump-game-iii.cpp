/*
 * Problem 1306: Jump Game III
 * URL     : https://leetcode.com/problems/jump-game-iii/
 * Solved  : 2026-05-17
 * Runtime : 5 ms
 * Memory  : 37.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    void traverse(vector<int> & arr, vector<pair<int,int>> & visited, int start, bool & reach)
    {
        if(reach)
        return;
        if(arr[start]==0)
        {
            reach=true;
            return;
        }
        int rt=start+arr[start];
        int lft=start-arr[start];
        if(lft>=0 && visited[start].first==0)
        {
            visited[start].first=1;
            traverse(arr,visited,lft,reach);
        }
        if(rt<arr.size() && visited[start].second==0)
        {
            visited[start].second=1;
            traverse(arr,visited,rt,reach);
        }
    return;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<pair<int,int>> visited(n,{0,0});
        bool reach=false;
        traverse(arr,visited,start,reach);
        return reach;
    }
};