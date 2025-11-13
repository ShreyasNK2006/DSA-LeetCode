# 3Sum
Solved on 2025-11-06

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     vector<vector<int>> res;
     vector<int> target(3);
     int j,k,i,sum;
     sort(nums.begin(),nums.end());
     for(int i=0;i<nums.size();i++)
     {
        if(i!=0 && nums[i-1]==nums[i])
        continue;
        j=i+1;
        k= nums.size()-1;
        while(j<k)
        {
            sum = nums[i]+nums[j]+nums[k];
            if(sum>0)
            k--;
            else if(sum<0)
            j++;
            else
            {
                target = { nums[i],nums[j],nums[k]};
                res.push_back(target);
                j++;
                k--;
                while(j<k && nums[j-1]==nums[j])
                j++;
                while(j<k && nums[k]==nums[k+1])
                k--;
            }
        }
     }
     return res;   
    }
};