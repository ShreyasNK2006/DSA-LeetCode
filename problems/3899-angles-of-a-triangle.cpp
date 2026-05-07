/*
 * Problem 3899: Angles of a Triangle
 * URL     : https://leetcode.com/problems/angles-of-a-triangle/
 * Solved  : 2026-04-29
 * Runtime : 0 ms
 * Memory  : 28.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

double pi = 22/7;
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int s1=sides[0]+sides[1],s2=sides[1]+sides[2],s3=sides[0]+sides[2];
        if(s1<=sides[2] || s2<=sides[0]|| s3<=sides[1])
            return {};
        double a=sides[0],b=sides[1],c=sides[2];
        double PI = acos(-1.0);
        double a1=1.0*180*acos((b*b+c*c-a*a)/(2*b*c))/PI,a2=1.0*180*acos((a*a+c*c-b*b)/(2*a*c))/PI,a3=1.0*180*acos((b*b+a*a-c*c)/(2*b*a))/PI;
        vector<double> res={a1,a2,a3};
        sort(res.begin(),res.end());
        return res;
        
    }
};