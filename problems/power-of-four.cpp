# Power of Four
Solved on 2025-10-18

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        double res = (log(n)/log(4));
        long long temp = (long long)res;
        if(temp==res)
            return true;
        return false;
    }
};