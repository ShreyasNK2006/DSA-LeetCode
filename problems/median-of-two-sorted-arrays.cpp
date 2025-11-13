# Median of Two Sorted Arrays
Solved on 2025-11-05

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
        return findMedianSortedArrays(nums2,nums1);
        int low = 0,high =nums1.size();
        int mid1,mid2,l1,l2,r1,r2;
        int left = (nums1.size()+nums2.size()+1)/2;
        int n = (nums1.size()+nums2.size());
        while(low<=high)
        {
            mid1=(low+high)>>1;
            mid2 = left-mid1;
            l1 = INT_MIN,l2=INT_MIN;
            r1=INT_MAX,r2=INT_MAX;
            if(mid1<nums1.size())
            r1 = nums1[mid1];
            if(mid2<nums2.size())
            r2= nums2[mid2];
            if(mid1-1>=0)
            l1 = nums1[mid1-1];
            if(mid2-1>=0)
            l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1)
            {
                if(n%2==0)
                return ((double)max(l1,l2)+min(r1,r2))/2;
                else
                return (double)max(l1,l2);
            }
            else if(l1>r2)
            high=mid1-1;
            else
            low=mid1+1;
        }
        return 0.0;
    }
};