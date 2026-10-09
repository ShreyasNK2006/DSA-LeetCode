/*
 * Problem 4014: Minimum Total Price After Applying Discounts
 * URL     : https://leetcode.com/problems/minimum-total-price-after-applying-discounts/
 * Solved  : 2026-08-10
 * Runtime : 181 ms
 * Memory  : 225.8 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(),prices.rend());
        sort(discounts.rbegin(),discounts.rend());
        int i=0,j=0;
        int m=prices.size(), n=discounts.size();
        double sum=0;
        while(j<n && i<m)
            {
                sum = sum + ((1.0*prices[i])*(100.0-discounts[j]))/100;
                i++;
                j++;
            }
        while(i<m)
            {
                sum+=prices[i];
                i++;
            }
        return sum;
    }
};