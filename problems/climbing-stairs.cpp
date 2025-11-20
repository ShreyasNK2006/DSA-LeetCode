# Climbing Stairs
Solved on 2025-07-25

class Solution {
public:
    long long fact(int top,int bottom)
    {
        long long res =1;
        for(int i=1;i<=bottom;i++)
        {
            res*= (top-bottom+i);
            res/=i;
        }
        return res;
    }
    int climbStairs(int n) {
        int y=0;
        long long count =0;
        if(n%2==1)
        y=1;
        else
        y=0;
        int k=0;
        while(k<=(n-y)/2)
        {
            count +=fact((n+y+2*k)/2,y+2*k);
            k++;
        }
        return count;
    }
};