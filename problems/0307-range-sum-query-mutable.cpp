/*
 * Problem 0307: Range Sum Query - Mutable
 * URL     : https://leetcode.com/problems/range-sum-query-mutable/
 * Solved  : 2026-06-10
 * Runtime : 56 ms
 * Memory  : 185.9 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

class NumArray {
public:
vector<long long> segment;
int n;
    void build(vector<int>&nums,int ind,int l,int h)
    {
        if(l==h)
        {
            segment[ind]=nums[l];
            return;
        }
        int mid=(l+h)/2;
        build(nums,2*ind+1,l,mid);
        build(nums,2*ind+2,mid+1,h);
        segment[ind]=segment[2*ind+1]+segment[2*ind+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segment.resize(4*n);
        build(nums,0,0,n-1);
    }
    void updatetree(int index,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            segment[index]=val;
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)
        updatetree(2*index+1,l,mid,pos,val);
        else
        updatetree(2*index+2,mid+1,r,pos,val);
        segment[index]=segment[2*index+1]+segment[2*index+2];
    }
    void update(int index, int val) {
        updatetree(0,0,n-1,index,val);
        
        
    }
    int query(int ind,int l,int r,int left,int right)
    {
        if(left>r || right<l)
        return 0;
        if(left<=l && right>=r)
        return segment[ind];
        int mid=(l+r)/2;
        int ls=query(2*ind+1,l,mid,left,right);
        int rs=query(2*ind+2,mid+1,r,left,right);
        return ls+rs;
    }
    int sumRange(int left, int right) {
        int sum= query(0,0,n-1,left,right);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */