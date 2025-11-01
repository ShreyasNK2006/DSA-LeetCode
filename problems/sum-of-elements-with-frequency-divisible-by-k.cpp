# Sum of Elements With Frequency Divisible by K
Solved on 2025-10-12

class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map <int,int> freq;
        vector<int> arr;
        for(int x:nums)
            {
                freq[x]++;
                if(find(arr.begin(),arr.end(),x)==arr.end())
                arr.push_back(x);                
            }
        int sum =0;
        for(int x:arr)
            {
                if(freq[x]%k==0)
                    sum+=(x*freq[x]);
            }
        return sum;
    }
};