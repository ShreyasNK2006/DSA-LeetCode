# Smallest Number With All Set Bits
Solved on 2025-10-29

class Solution {
public:
    int findnearest(int n){
        int count=0,copy=n;
        while(copy){
            count++;
            copy/=2;
        }
        int res = (int)pow(2,count)-1;
        if(copy==(res+1))
        return pow(2,count+1)-1;
        else
        return res;
    }
    int smallestNumber(int n) {
        int res = findnearest(n);
        return res;
    }
};