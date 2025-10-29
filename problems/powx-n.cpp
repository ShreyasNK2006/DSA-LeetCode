# Pow(x, n)
Solved on 2025-09-30

class Solution {
public:
    double myPowf(double x, long long  n)
    {
        if(n==0)
        return 1.0;
            if(n%2==0)
            return myPowf(x*x,n/2);
            else 
            return x * myPowf(x*x,n/2);
    }
    double myPow(double x, int n) {
        if(n==0 || x==1)
        return 1.0;
        if(x==0)
        return 0.0;
        if(x==-1)
        {
            if(n%2==0)
            return 1.0;
            else
            return -1.0;
        }
        double ans;
        if(n>=0)
        ans=myPowf(x,n);
        else
        ans=myPowf(1/x,(long long)-1*n);
        return ans;
    }
};