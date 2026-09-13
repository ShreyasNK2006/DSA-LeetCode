/*
 * Problem 1386: Cinema Seat Allocation
 * URL     : https://leetcode.com/problems/cinema-seat-allocation/
 * Solved  : 2026-08-20
 * Runtime : 743 ms
 * Memory  : 60.4 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int c=n*2;
        sort(rs.begin(),rs.end());
        int lvl =1;
        int prev =1;
        int del1 =0,del2=0,del3=0;
        for(auto it:rs)
        {
            if(lvl==it[0])
            {
                if((it[1]>1 && it[1]<6))
                del1=1;
                if((it[1]>5 && it[1]<10))
                del2=1;
                if((it[1]>3 && it[1]<8))
                del3=1;
            }
            else
            {
                if(del1 && del2 && del3)
                c-=2;
                else
                if(del1 || del2 || del3)
                c-=1;
                lvl=it[0];
                cout<<del1<<del2<<del3<<endl;
                cout<<lvl<<" "<<c<<endl;
                del1=0,del2=0,del3=0;
                if((it[1]>1 && it[1]<6))
                del1=1;
                if((it[1]>5 && it[1]<10))
                del2=1;
                if((it[1]>3 && it[1]<8))
                del3=1; 
            }
        }
        if(del1 && del2 && del3)
            c-=2;
        else if(del1 || del2 || del3)
            c-=1;
        return c;
    }
};