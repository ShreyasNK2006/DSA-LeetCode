/*
 * Problem 1552: Magnetic Force Between Two Balls
 * URL     : https://leetcode.com/problems/magnetic-force-between-two-balls/
 * Solved  : 2026-05-02
 * Runtime : 51 ms
 * Memory  : 61.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    bool checkforce(vector<int>& position,int &mid,int &m,int &n)
    {
        int countballs=1;
        for(int i=0;i<n;)
        {
            int j=i+1;
            while(j<n && position[i]+mid>position[j])
            j++;
            if(j<n && position[i]+mid<=position[j])
            countballs++;
            else
            break;
            i=j;
        }
        if(countballs>=m)
        return true;
        else
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int l=1,n=position.size();
        sort(position.begin(),position.end());
        int h=(position[n-1]-position[0])/(m-1);
        int ans=1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(checkforce(position,mid,m,n))
            {
                l=mid+1;
                ans=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};