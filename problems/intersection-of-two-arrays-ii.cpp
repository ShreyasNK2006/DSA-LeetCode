# Intersection of Two Arrays II
Solved on 2025-10-18

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
      sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int mins = min(nums1.size(),nums2.size());
        int maxs = max(nums1.size(),nums2.size());
    int i=0,j=0;
        vector<int> minv = (nums1.size()>=nums2.size()?nums2:nums1);
        vector<int> maxv = (nums1.size()<nums2.size()?nums2:nums1);
        while(i<mins && j< maxs)
            {
                if(minv[i]==maxv[j])
                {
                    res.push_back(minv[i]);
                    i++;
                    j++;
                }
                else if(minv[i]<maxv[j])
                    i++;
                else 
                    j++;
            }
        return res;
    }
};