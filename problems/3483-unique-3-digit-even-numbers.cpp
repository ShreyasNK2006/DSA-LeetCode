/*
 * Problem 3483: Unique 3-Digit Even Numbers
 * URL     : https://leetcode.com/problems/unique-3-digit-even-numbers/
 * Solved  : 2026-09-11
 * Runtime : 3 ms
 * Memory  : 29.5 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        unordered_set<int> st,st2;
        int n=digits.size();
        int uniq=0;

        if(n<3)
        return 0;
        for(auto it:digits)
        {
            freq[it]++;
            if(it%2==0)
            st.insert(it);
            st2.insert(it);
        }
        uniq=st2.size();
        int c=0;
        int b=1;
        int d=0;
        for(int i=0;i<=9;i++)
        {
            if(freq[i]>1)
            d++;
            
        }
        for(auto it:st)
        {
            int k=0;
            if(freq[it]==1)
            k = (uniq-1)*(uniq-2);
            else
            k = (uniq)*(uniq-1);
            k+=d;
            if(freq[it]==2)
            k--;
            cout<<it<<" "<<k<<endl;
            c+=k;
        }
        if(st.find(0)!=st.end())
        {
            int x = freq[0];
                for(int it:st)
                {
                    if(it==0)
                    {
                        if(x==1)
                        continue;
                        else
                        {
                            c-=uniq;
                            if(x==2)
                            c++;
                        }
                    }
                    else
                    {
                        if(freq[it]==1)
                        c=c+1;
                        if(x==1)
                        c=c+1;
                        c-=uniq; 
                    }
                }
        }
        return c;
    }
};