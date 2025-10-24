# Count Good Numbers
Solved on 2025-10-01

class Solution {
public:
long long const mod=1000000007;
long long countcalc(long long base,long long expo)
{
    long long res=1;
    while(expo>0)
    {
        if(expo%2==1)
        res =(res*base)%mod;
        base=(base*base)%mod;
        expo/=2;
    }
    return res;

}
    int countGoodNumbers(long long n) {
        long long odd = (n/2);
        long long even =(n+1)/2;
        return (countcalc(4,odd)*countcalc(5,even))%mod;
    }
};