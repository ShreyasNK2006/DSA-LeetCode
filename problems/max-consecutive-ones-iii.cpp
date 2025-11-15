# Max Consecutive Ones III
Solved on 2025-11-12

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int st=0,end = nums.size()-1;
        int maxlen=0;
        int zeros=0;
        int left=0,right=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
            zeros++;
            while(zeros>k)
            {
                if(nums[left]==0)
                zeros--;
                left++;
            }
            maxlen= max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};