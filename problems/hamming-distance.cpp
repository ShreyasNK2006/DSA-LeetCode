# Hamming Distance
Solved on 2025-10-23

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        int ind=0;
        while(x!=0 || y!=0)
        {
            if((x%2)!=(y%2))
            count++;
            x/=(2);
            y/=(2);
            ind++;
        }
        return count;
    }
};