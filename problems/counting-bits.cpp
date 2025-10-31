# Counting Bits
Solved on 2025-10-08

class Solution {
public:
int bitcount(int i)
{
    int count=0;
    if(i==0)
    return 0;
    while(i>0)
    {
        if(i%2!=0)
        count++;
        i=i/2;
    }
    return count;

}
    vector<int> countBits(int n) {
        vector<int> arr(n+1);
        for(int i=0;i<n+1;i++)
        {
            arr[i]=bitcount(i);
        }
        return arr;
    }
};