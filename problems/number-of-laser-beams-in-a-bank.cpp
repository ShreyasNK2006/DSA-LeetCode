# Number of Laser Beams in a Bank
Solved on 2025-10-27

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0,count=0,prevcount=0;
        for(int i=0;i<bank.size();i++)
        {
            if(count!=0)
            prevcount=count;
            count=0;
            for(int j=0;j<bank[0].size();j++)
            {
                if(bank[i][j]=='1')
                count++;
                if(j==bank[0].size()-1)
                res+=(count*prevcount);
            }
        }
        return res;
    }
};