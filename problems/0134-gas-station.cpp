/*
 * Problem 0134: Gas Station
 * URL     : https://leetcode.com/problems/gas-station/
 * Solved  : 2026-09-28
 * Runtime : 3 ms
 * Memory  : 112.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i=0;i<n;i++)
        {
            gas[i]-=cost[i];
        }
        int ind =-1;
        long long cs=0;
        for(int i=0;i<n;)
        {
            //cout<<cs;
            cs=0;
            if(gas[i]<0)
            {
                i++;
                continue;
            }
            else
            {
                //int temp=i;
                int j=i;
                bool valid=false;
                while((cs+gas[j])>=0)
                {
                    cs+=gas[j];
                    j = (j+1)%n;
                    valid=true;
                    if(j==i)
                    break;
                }
                //cout<<cs<<j<<i<<valid<<endl;
                if(cs>=0 && j==i && valid)
                {
                    //cout<<'a';
                    return i;
                }
                if(i>j)
                {
                    //cout<<i;
                    return -1;
                }
                i=j+1;
            }
        }
        return ind;
    }
};