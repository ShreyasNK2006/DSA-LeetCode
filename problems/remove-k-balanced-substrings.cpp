# Remove K-Balanced Substrings
Solved on 2025-10-05

class Solution {
public:
    string removeSubstring(string s, int k) {
        string st;
        for(auto c:s)
        {
            st.push_back(c);
            if(st.size()>=2*k)
            {
                bool valid=true;

                if(valid)
                {
                    for(int i= st.size()-2*k;i<st.size()-k;i++)
                    {
                        if(st[i]!='(')
                        {
                            valid=false;
                            break;
                        }
                    }
                }
                if(valid)
                {
                    for(int i=st.size()-k;i<st.size();i++)
                    {
                        if(st[i]!=')')
                        {
                            valid=false;
                            break;
                        }
                    }
                }
                if(valid)
                {
                    st.erase(st.end()-2*k,st.end());
                }
            }
        }
        return st;
    }
};