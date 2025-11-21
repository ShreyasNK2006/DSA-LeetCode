/*
 * Problem: Maximum Points You Can Obtain from Cards
 * Solved on: 2025-11-15
 * Runtime: 0 ms
 * Memory: 46.3 MB
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalsum=0;
        int windowsum=0;
        for(int i=0;i<cardPoints.size();i++)
        {
            totalsum+=cardPoints[i];
            if(i<cardPoints.size()-k)
            windowsum+=cardPoints[i];
        }
        int maxsum=0;
        maxsum=max(maxsum,totalsum-windowsum);
        for(int j=cardPoints.size()-k;j<cardPoints.size();j++)
        {
            windowsum-=cardPoints[j-(cardPoints.size()-k)];
            windowsum+=cardPoints[j];
            maxsum=max(maxsum,totalsum-windowsum);
        }
        return maxsum;
    }
};