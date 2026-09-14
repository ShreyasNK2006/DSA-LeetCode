/*
 * Problem 3069: Distribute Elements Into Two Arrays I
 * URL     : https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
 * Solved  : 2026-08-20
 * Runtime : 0 ms
 * Memory  : 23.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1,arr2;
        arr1.push_back(nums[0]),arr2.push_back(nums[1]);
        int i=2;
        int j1=0,j2=0;
        while(i<n)
        {
            if(arr1[j1]>arr2[j2])
            {
                arr1.push_back(nums[i]);
                j1++;
            }
            else
            {
                arr2.push_back(nums[i]);
                j2++;
            }
            i++;
        }
        j2=0;
        while(j2<arr2.size())
        {
            arr1.push_back(arr2[j2]);
            j2++;
        }
        return arr1;
    }
};