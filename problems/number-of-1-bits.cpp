# Number of 1 Bits
Solved on 2025-10-15

class Solution {
public:
    int hammingWeight(int n) {
        int res =0;
        while(n!=0)
            {
                if(n%2==1)
                    res++;
                n/=2;
            }
        return res;
    }
};