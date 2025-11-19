# Count Number of Nice Subarrays
Solved on 2025-11-14

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count =0;
        int oddcount=0;
        unordered_map<int,int> countpos;
        countpos[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            oddcount++;
            if(countpos.find(oddcount-k)!=countpos.end())
            count+=countpos[oddcount-k];
            countpos[oddcount]++;
        }
        return count;
    }
};