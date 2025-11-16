# Add Digits
Solved on 2025-11-12

class Solution {
public:
    int digisum(int num)
    {
        int sum=0;
        while(num)
        {
            sum+=(num%10);
            num/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>9)
        {
            num = digisum(num);
        }
        return num;
    }
};