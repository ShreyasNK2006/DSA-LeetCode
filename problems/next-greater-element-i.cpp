# Next Greater Element I
Solved on 2025-10-20

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
        for(int i=0;i<nums1.size();i++)
        {
            int j,temp;
            for(j=0;j<nums2.size();j++)
            {
                if(nums1[i]==nums2[j])
                {
                    temp = nums2[j];
                    break;
                }
            }
            j++;
            for(;j<nums2.size();j++)
            {
                if(temp<nums2[j])
                {
                    ans[i]=nums2[j];
                    break;
                }
            }
        }
        return ans;
    }
};