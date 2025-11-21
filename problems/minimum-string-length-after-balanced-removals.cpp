# Minimum String Length After Balanced Removals
Solved on 2025-11-16

class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int l=0,r=0;
        int counta=0,countb=0;
        int minlen;
        while(r<s.size())
            {
                if(s[r]=='a')
                    counta++;
                else
                    countb++;
                if(counta>0 &&countb>0)
                    {
                        s.erase(r+1-2*min(counta,countb),2*min(counta,countb));
                        r-=(2*min(counta,countb)-1);
                        if(counta>=countb)
                        {
                            counta-=countb;
                            countb=0;
                        }
                        else
                        {
                            countb-=counta;
                            counta=0;
                        }
                        continue;
                    }
                r++;
            }
        minlen= s.size();
        return minlen;
    }
};