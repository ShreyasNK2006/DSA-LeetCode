# Max Consecutive Ones
Solved on 2025-09-01

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m =0;
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if((i-j)>m)
                m = i-j;
                j=i+1;
            }
            if(i== nums.size()-1)
            {
                if((i-j+1)>m)
                m=(i+1-j);
            }
        }
        return m;
    }
};