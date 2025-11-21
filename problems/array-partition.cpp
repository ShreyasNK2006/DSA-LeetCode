/*
 * Problem: Array Partition
 * Solved on: 2025-10-30
 * Runtime: 9 ms
 * Memory: 32 MB
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            sum+=(nums[i]);
        }
        return sum;
    }
};