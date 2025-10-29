# Combination Sum
Solved on 2025-10-03

class Solution {
public:
void calcpermutation(vector<vector<int>>& res,vector<int>candidates,int index,int target,vector<int> temp)
{
    if(index==candidates.size())
    {
        if(target==0)
        {
            res.push_back(temp);
        }
     return;
    }
    if(candidates[index]<=target)
    {
        temp.push_back(candidates[index]);
        calcpermutation(res,candidates,index,target-candidates[index],temp);
        temp.pop_back();
    }
    calcpermutation(res,candidates,index+1,target,temp);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        calcpermutation(res,candidates,0,target,temp);
        return res;
    }
};