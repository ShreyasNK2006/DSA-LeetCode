# Sum of Subarray Minimums
Solved on 2025-10-20

class Solution {
public:
    vector<int> findNSE(vector<int> & arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i= arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            ans[i]= !st.empty()? st.top():arr.size();
            st.push(i);
        }
        return ans;
    }
    vector<int> findPSE(vector<int> & arr)
    {
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
            {
                st.pop();
            }
            ans[i]= !st.empty()? st.top():-1;
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> NSE = findNSE(arr);
        vector<int>PSE = findPSE(arr);
        int sum=0;
        int mod = 1e9 + 7;
        for(int i=0;i<arr.size();i++)
        {
            int left = i-PSE[i];
            int right = NSE[i]-i;
            long long freq = left*right*1LL;
            int val = (freq*arr[i]*1LL)%mod;
            sum = (sum+val)%mod;
        }
        return sum;
    }
};