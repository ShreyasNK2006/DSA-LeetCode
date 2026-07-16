/*
 * Problem 3751: Total Waviness of Numbers in Range I
 * URL     : https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
 * Solved  : 2026-06-04
 * Runtime : 3 ms
 * Memory  : 8.7 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness=0;
        for(int i=num1;i<=num2;i++)
            {
                if(i<100)
                    continue;
                else if(i<1000)
                {
                    int first = i/100;
                    int last = i%10;
                    int mid = (i/10)%10;
                    if((mid-first)*(mid-last)>0)
                        waviness++;
                }
                else if(i<10000)
                {
                    int first = i/1000;
                    int last = i%10;
                    int second = (i/100)%10;
                    int third=(i/10)%10;
                    if((second-first)*(second-third)>0)
                        waviness++;
                    if((third-second)*(third-last)>0)
                        waviness++;
                }
                else
                {
                    int first = i/10000;
                    int last = i%10;
                    int second = (i/1000)%10;
                    int third = (i%1000)/100;
                    int fourth = (i%100)/10;
                    if((second-first)*(second-third)>0)
                    waviness++;
                    if((third-second)*(third-fourth)>0)
                        waviness++;
                    if((fourth-third)*(fourth-last)>0)
                        waviness++;
                }
            }
        return waviness;
    }
};