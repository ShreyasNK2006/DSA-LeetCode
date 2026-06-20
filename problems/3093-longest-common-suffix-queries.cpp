/*
 * Problem 3093: Longest Common Suffix Queries
 * URL     : https://leetcode.com/problems/longest-common-suffix-queries/
 * Solved  : 2026-05-28
 * Runtime : 344 ms
 * Memory  : 417.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

struct Node {
    int link[26];
    int chrleft = INT_MAX; // storing smallest string left from right to left
    int ind = -1; // storing index of container having smallest left string
                  // after a character
    Node() { fill(begin(link), end(link), -1); }
};
class Solution {
private:
    vector<Node> trie;

public:
    Solution() { trie.emplace_back(); }
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsContainer.size(), m = wordsQuery.size();
        vector<int> ans(m);
        for (int i = 0; i < n; i++) {
            int curr = 0;
            int s = wordsContainer[i].size();
            if (s < trie[curr].chrleft) {
                trie[curr].chrleft = s;
                trie[curr].ind = i;
            }
            for (int j = s - 1; j >= 0; j--) {
                char ch = wordsContainer[i][j];
                if (trie[curr].link[ch - 'a'] == -1) {
                    trie[curr].link[ch - 'a'] = trie.size();
                    trie.emplace_back();
                }
                curr = trie[curr].link[ch - 'a'];
                if (s < trie[curr].chrleft) {
                    trie[curr].chrleft = s;
                    trie[curr].ind = i;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int curr = 0;
            ans[i] = trie[curr].ind;
            for (int j = wordsQuery[i].size() - 1; j >= 0; j--) {
                char ch = wordsQuery[i][j];
                if (trie[curr].link[ch - 'a'] != -1) {
                    curr = trie[curr].link[ch - 'a'];
                } else {
                    break;
                }
            }
            ans[i] = trie[curr].ind;
        }
        return ans;
    }
};