# Find Peak Element
Solved on 2025-09-15

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0,high=nums.size()-1,mid;
        mid = (low+high)/2;
        while(low<high)
        {
            mid = (low+high)/2;
            if(nums[mid]<nums[mid+1])
            {
                low = mid+1;
            }
            else
            {
                high =mid;
            }
        }
        return high;
    }
};