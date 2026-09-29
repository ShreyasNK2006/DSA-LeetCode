/*
 * Problem 4053: Minimum Operations to Make Every Element Palindromic
 * URL     : https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/
 * Solved  : 2026-09-13
 * Runtime : 78 ms
 * Memory  : 139.3 MB
 *
 * Explanation: (AI generation failed – check your GEMINI_API_KEY and quota.)
*/

static bool initialised = false;
static vector<long long> oddst,evenst;
class Solution {
public:
    int lb(long long n,int e)
    {
        int ans=-1;
        if(e==1)
        {
            int l=0,r=evenst.size()-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(evenst[mid]<=n)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        else
        {
            int l=0,r=oddst.size()-1;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(oddst[mid]<=n)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return ans;
    }
    void compute()
    {
        if(initialised)
        return;
        for(int i=1;i<10;i++)
        {
            if(i%2==0)
            evenst.push_back(i);
            else
            oddst.push_back(i);
        }
        long long prod=1;
        for(int i=1;i<=1e5;i++)
        {
            prod =i;
            long long temp =i;
            while(temp)
            { 
                prod*=10;
                prod+=(temp%10);
                temp/=10;
            }
            if(prod%2==0)
            evenst.push_back(prod);
            else
            oddst.push_back(prod);
            prod=i;
            temp=i;
            temp/=10;
            while(temp)
            {
                prod*=10;
                prod+=(temp%10);
                temp/=10;
            }
            if(prod%2==0)
            evenst.push_back(prod);
            else
            oddst.push_back(prod);
            //if(i==12)
            //cout<<prod<<endl;
        }
        sort(evenst.begin(), evenst.end());
        evenst.erase(unique(evenst.begin(), evenst.end()), evenst.end());
        sort(oddst.begin(), oddst.end());
        oddst.erase(unique(oddst.begin(), oddst.end()), oddst.end());
        initialised =true;
    }
    long long minOperations(vector<int>& nums) {
        compute();
        long long ans=0;
        //cout<< oddst.size() << " " << evenst.size() << endl;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                long long diff = LLONG_MAX;
                int it = lb(nums[i],1);
                if(it!=-1)
                diff=nums[i]-evenst[it];
                if(it!=evenst.size()-1)
                diff=min(diff,evenst[it+1]-nums[i]);
                ans = ans + diff/2;
            }
            else
            {
                long long diff = LLONG_MAX;
                int it = lb(nums[i],0);
                if(it!=-1)
                diff=nums[i]-oddst[it];
                if(it!=oddst.size()-1)
                diff=min(diff,oddst[it+1]-nums[i]);
                ans = ans + diff/2;
            }
        }
        return ans;
    }
};