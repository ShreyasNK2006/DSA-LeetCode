# Equal Score Substrings
Solved on 2025-10-11

class Solution {
public:
    int sumcalc(string subs)
    {
        int sum =0;
        for(auto c: subs)
            sum+=(c-96);
        return sum;
    }
    bool scoreBalance(string s) {
        int sum1,sum2;
        for(int i=1;i<=s.length()-1;i++)
            {
                sum1 = sumcalc(s.substr(0,i));
                sum2 = sumcalc(s.substr(i));
                if(sum1==sum2)
                    return true;
            }
        return false;
    }
};