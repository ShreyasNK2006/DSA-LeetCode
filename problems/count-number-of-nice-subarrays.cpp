# Count Number of Nice Subarrays
Solved on 2025-11-14

class Solution {
public:
    int findsub(vector<int>& nums, int goal)
    {
        if(goal<0)
        return 0;
        int l =0,r=0,sum=0,cnt=0;
        while(r<nums.size())
        {
            sum+=nums[r];
                while(sum>goal)
                {
                    sum-=nums[l];
                    l++;
                }
            
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=(nums[i]%2);
        }
        int cnt =0;
        cnt = (findsub(nums,k)-findsub(nums,k-1));
        return cnt;
    }
};