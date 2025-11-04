# Next Greater Element II
Solved on 2025-10-20

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            int j;
            if(i==nums.size()-1)
            j=0;
            else
            j=i+1;
            for(;j<nums.size();j++)
            {
                if(j==i)
                break;
                if(nums[i]<nums[j])
                {
                    res[i]=nums[j];
                    break;
                }
                if(j==nums.size()-1)
                j=-1;
            }
        }
        return res;
    }
};