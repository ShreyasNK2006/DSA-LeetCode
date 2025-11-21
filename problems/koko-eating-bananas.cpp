# Koko Eating Bananas
Solved on 2025-09-16

class Solution {
public:
long long timecalc(vector<int> &piles ,int mid)
{
    long long time=0;
    for(int i=0;i<piles.size();i++)
    {
        time+=(long long)((piles[i]+mid-1)/mid);
    }
    return time;
}
    int findk(vector<int> & piles,int high,int h)
    {
        int mid;
        long long time;
        int low=1;
        while(low<=high)
        {
            mid=(low+high)/2;
            time=timecalc(piles,mid);
            if(time<=h)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=piles[0],high=piles[0];
        for(int i=1;i<piles.size();i++)
        {
            high=max(high,piles[i]);
        }
        return findk(piles,high,h);
    }
};