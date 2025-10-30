# Subsets II
Solved on 2025-10-04

class Solution {
public:
    void subsetgen(vector<int>& nums,vector<vector<int>>& res,vector<int> temp,int ind)
    {
        if(ind==pow(2,nums.size())+1)
        return;
        temp.clear();
        for(int i=0;i<nums.size();i++)
        {
            if(ind&(1<<i))
            temp.push_back(nums[i]);
        }
        int find=-1;
        for(int i=0;i<res.size();i++)
        {
            if(temp==res[i])
            {
                find=1;
                break;
            }
        }
        if(find==-1)
        {
            res.push_back(temp);
        }
        subsetgen(nums,res,temp,ind+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        subsetgen(nums,res,temp,0);
        return res;
    }
};