# Subsets
Solved on 2025-10-03

class Solution {
public:
    void genset(vector<vector<int>>& res,vector<int> nums,int i)
    {
        vector<int> temp;
        if(i==pow(2,nums.size()))
        {
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            if((i&(1<<j))!=0)
            temp.push_back(nums[j]);
        }
        res.push_back(temp);
        genset(res,nums,++i);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        genset(res,nums,0);
        return res;
    }
};