/*
 * Problem 0556: Next Greater Element III
 * URL     : https://leetcode.com/problems/next-greater-element-iii/
 * Solved  : 2026-09-26
 * Runtime : 0 ms
 * Memory  : 8.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int nextGreaterElement(int n) {
        int cp =n;
        int dc =0;
        set<int> st;
        int ind =-1;
        vector<int> temp;
        long long ans=0;
        int up=-1;
        while(cp)
        {
            int d = cp%10;
            dc++;
            if(ind==-1)
            {
                temp.push_back(d);
            }
            if(ind==-1 && st.upper_bound(d)!=st.end())
            {
                ind=dc;
                up=*st.upper_bound(d);
            }
            if(ind==-1)
            {
                st.insert(d);
            }
            cp/=10;
        }
        //cout<<up<<" "<<ind<<" "<<dc;
        cp=n;
        if(ind==-1)
        return -1;
        for(int i=dc;i>ind;i--)
        {
            ans*=10;
            ans+=(cp/(int)pow(10,i-1));
            cp%=(int)pow(10,i-1);
        }
        ans*=10;
        ans+=up;
        int c=0;
        sort(temp.begin(),temp.end());
        for(auto it:temp)
        {
            if(it==up && c==0)
            {
                c++;
                continue;
            }
            ans*=10;
            ans+=it;
        }
        if(ans> ((1LL<<31)-1))
        return -1;
        return ans;
    }
};