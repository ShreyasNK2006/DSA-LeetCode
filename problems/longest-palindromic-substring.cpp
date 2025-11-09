# Longest Palindromic Substring
Solved on 2025-11-04

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
        return "";
        int start=0,maxLen=1;
        auto expand =[&](int left,int right){
            while(left>=0 && right<(int)s.length()&& s[left]==s[right]){
                if(right-left+1>maxLen){
                    maxLen = right-left+1;
                    start=left;
                }
                left--;
                right++;
            }
        };
        for(int i=0;i<s.size();i++)
        {
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxLen);
        
    }
};