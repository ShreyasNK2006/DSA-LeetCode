/*
 * Problem: Kth Largest Element in an Array
 * Solved on: 2025-11-16
 * Runtime: 40 ms
 * Memory: 64.8 MB
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        while(k-1)
        {
            pq.pop();
            k--;
        }
        return pq.top();
    }
};