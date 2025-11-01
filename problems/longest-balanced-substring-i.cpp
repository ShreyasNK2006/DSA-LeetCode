# Longest Balanced Substring I
Solved on 2025-10-12

class Solution {
public:
    int longestBalanced(string s) {
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            vector<int> freq(26,0);
            for (int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;
                int common = 0;
                bool balanced = true;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        if (common == 0)
                            common = freq[k];
                        else if (freq[k] != common) {
                            balanced = false;
                            break;
                        }
                    }
                }
                if(balanced)
                    len = max(len,j-i+1);
            }
        }
        return len;
    }
};