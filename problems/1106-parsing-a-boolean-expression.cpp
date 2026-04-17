/*
 * Problem 1106: Parsing A Boolean Expression
 * URL     : https://leetcode.com/problems/parsing-a-boolean-expression/
 * Solved  : 2026-04-06
 * Runtime : 0 ms
 * Memory  : 11.2 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    char funceval(string &exp,char &opr)
    {
        if(opr=='!')
        {
            return exp=="f"?'t':'f';
        }
        else if(opr=='&')
        {
            for(int i=0;i<exp.size();i++)
            {
                if(exp[i]=='f')
                return 'f';
            }
            return 't';
        }
        else
        {
            for(int i=0;i<exp.size();i++)
            {
                if(exp[i]=='t')
                return 't';
            }
            return 'f';
        }
    }
    bool parseBoolExpr(string expression) {
        stack<char> st;
        unordered_set<char> op;
        op.insert({'&','|','!'});
        int n=expression.size();
        for(int i=0;i<n;i++)
        {
            if(expression[i]=='(')
            continue;
            else if(expression[i]!=')')
            {
                st.push(expression[i]);
            }
            else
            {
                string exp;
                while(op.find(st.top())==op.end())
                {
                    exp.push_back(st.top());
                    st.pop();
                }
                char opr=st.top();
                st.pop();
                st.push(funceval(exp,opr));
            }
        }
        if(st.top()=='t')
        return true;
        else
        return false;
    }
};