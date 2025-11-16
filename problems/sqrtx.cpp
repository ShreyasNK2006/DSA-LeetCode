# Sqrt(x)
Solved on 2025-07-18

class Solution {
public:
    int mySqrt(int x) {
        int i;
        for(i=0;i<=sqrt(x);i++)
        {
            if(i*i == x)
            return i;
        }
        return i-1;
    }
};