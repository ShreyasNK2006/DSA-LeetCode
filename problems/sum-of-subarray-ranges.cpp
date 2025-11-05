# Sum of Subarray Ranges
Solved on 2025-10-22

class Solution {
public:
    vector<int> findNSE(vector<int> arr)
    {
        vector<int> NSE(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            NSE[i]=!st.empty()?st.top():arr.size();
            st.push(i);
        }
        return NSE;
    }
    vector<int> findPSE(vector<int> arr)
    {
        vector<int> PSE(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            PSE[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        return PSE;
    }
    vector<int> findNGE(vector<int> arr)
    {
        vector<int> NGE(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            NGE[i]=!st.empty()?st.top():arr.size();
            st.push(i);
        }
        return NGE;
    }
    vector<int> findPGE(vector<int> arr)
    {
        vector<int> PGE(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
            {
                st.pop();
            }
            PGE[i]=!st.empty()?st.top():-1;
            st.push(i);
        }
        return PGE;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> NSE = findNSE(nums);
        vector<int> PSE = findPSE(nums);
        vector<int> NGE = findNGE(nums);
        vector<int> PGE = findPGE(nums);
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int left = i-PSE[i];
            int right = NSE[i]-i;
            long long fact = (left*right*1LL);
            long long mins = nums[i]*fact*1LL;
            left = i-PGE[i];
            right = NGE[i]-i;
            fact = left*right*1LL;
            long long  maxs = nums[i]*fact*1LL;
            sum+=(maxs-mins);
        }
        return sum;
    }
};