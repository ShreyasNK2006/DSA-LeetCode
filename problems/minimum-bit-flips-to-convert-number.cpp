# Minimum Bit Flips to Convert Number
Solved on 2025-10-10

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp = start^goal;
        int count=0;
        while(temp)
        {
            count+=(temp&1);
            temp>>=1;
        }
        return count;
    }
};