# Check Divisibility by Digit Sum and Product
Solved on 2025-07-20

class Solution {
public:
    bool checkDivisibility(int n) {
       int digisum =0,digiprod = 1,sum =0;
        int copy = n;
        while(copy>0)
            {
                digisum += copy%10;
                digiprod *=copy%10;
                copy/=10;
            }
        sum = digisum + digiprod;
        if(n%sum == 0)
            return true;
        else
            return false;
    }
};