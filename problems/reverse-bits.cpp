# Reverse Bits
Solved on 2025-10-24

class Solution {
public:
    int reverseBits(int n) {
        stack<int> st;
        int i=0,ans=0;
        while(i<32)
        {
            st.push(n%2);
            n/=2;
            i++;
        }
        i=0;
        while(!st.empty())
        {
            ans+=(st.top()*(1<<i));
            st.pop();
            i++;
        }
        return ans;
    }
};