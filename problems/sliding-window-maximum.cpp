/*
 * Problem: Sliding Window Maximum
 * Solved on: 2025-11-01
 * Runtime: 17 ms
 * Memory: 139.2 MB
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front()==i-k)
            dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};