/*
 * Problem 1291: Sequential Digits
 * URL     : https://leetcode.com/problems/sequential-digits/
 * Solved  : 2026-07-13
 * Runtime : 2 ms
 * Memory  : 8.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int d1=0,d2=0;
        int cp=low;
        int p=1;
        while(cp)
        {
            cp/=10;
            p*=10;
            d1++;
        }
        p/=10;
        cp=high;
        while(cp)
        {
            cp/=10;
            d2++;
        }
        int f=low/p;
        int temp=0;
        for(int i=0;i<d1;i++)
        {
            temp*=10;
            temp+=f;
            f++;
        }
        while(temp<low && f<10)
        {
            temp%=p;
            temp*=10;
            temp+=f;
            f++;
        }
        if(f<=10 && temp>=low && temp<=high)
        res.push_back(temp);
        while(f<10)
        {
            temp%=p;
            temp*=10;
            temp+=f;
            if(temp<=high && temp>=low)
            res.push_back(temp);
            else
            break;
            f++;
        }
        for(int i=d1+1;i<d2;i++)
        {
            f=1;
            temp=0;
            p*=10;
            for(int j=0;j<i;j++)
            {
                temp*=10;
                temp+=f;
                f++;
            }
            if(f<=10 && d2!=d1)
            res.push_back(temp);
            while(f<10)
            {
                temp%=p;
                temp*=10;
                temp+=f;
                res.push_back(temp);
                f++;
            }
        }
        f=1;
        p*=10;
        temp=0;
        for(int j=0;j<d2;j++)
            {
                temp*=10;
                temp+=f;
                f++;
            }
        if(f<=10 && temp<=high && d1!=d2)
        res.push_back(temp);
        while(f<10 && d1!=d2)
        {
            temp%=p;
            temp*=10;
            temp+=f;
            if(temp<=high)
            res.push_back(temp);
            else 
            break;
            f++;
        }
        return res;
    }
};