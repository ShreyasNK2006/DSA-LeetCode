# Combination Sum II
Solved on 2025-10-03

class Solution {
public:
    void calcpermutations(vector<vector<int>>& res, vector<int> & arr,int target,int ind,vector<int> & temp)    
    {
            if(target==0)
            {
                res.push_back(temp);
                return;
            }
            for(int i=ind;i<arr.size();i++)
            {
                if(i>ind && arr[i-1]==arr[i])
                continue;
                if(arr[i]>target)
                break;
                temp.push_back(arr[i]);
                calcpermutations(res,arr,target-arr[i],i+1,temp);
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        calcpermutations(res,candidates,target,0,temp);
        return res;
    }
};