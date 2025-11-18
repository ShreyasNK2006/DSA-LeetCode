# Partition to K Equal Sum Subsets
Solved on 2025-11-13

class Solution {
public:
    bool partitioncheck(vector<int>& nums,vector<bool> & used,int k,int ind,int curr_sum,int & sum)
    {
        if(k == 1)
        return true;
        if(curr_sum == sum)
        return partitioncheck(nums,used,k-1,0,0,sum);
        for(int i=ind;i<nums.size();i++)
        {
            if(used[i])
            continue;
            if(nums[i]+curr_sum>sum)
            continue;
            used[i]=true;
            if(partitioncheck(nums,used,k,ind+1,curr_sum+nums[i],sum))
            return true;
            used[i]=false;
            if(curr_sum==0)
            return false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum =0;
        for(int num: nums)
        {
            sum+=num;
        }
        if(sum%k!=0)
        return false;
        sum/=k;
        sort(nums.rbegin(),nums.rend());
        vector<bool> used(nums.size(),false);
        return partitioncheck(nums, used,k,0,0,sum);
    }
};