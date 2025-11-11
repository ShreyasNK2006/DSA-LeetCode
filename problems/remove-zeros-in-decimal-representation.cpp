# Remove Zeros in Decimal Representation
Solved on 2025-10-26

class Solution {
public:
    long long removeZeros(long long n) {
        long long res =0;
        while(n)
            {
                if(n%10!=0)
                {
                     res*=10;
                    res+=(n%10);
                }
                n/=10;
            }
        n=0;
        while(res)
            {
                n*=10;
                n+=(res%10);
                res/=10;
            }
        return n;
    }
};