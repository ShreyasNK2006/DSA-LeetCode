# Minimum Distance Between Three Equal Elements I
Solved on 2025-11-09

class Solution {
public:
    int absdistance(vector<int>& temp)
    {
        int tempd=0;
        int mind=INT_MAX;
        for(int i=0;i<=temp.size()-3;i++)
            {
                tempd=0;
                for(int j=i+1;j<temp.size();j++)
                    {
                        tempd = abs(temp[i]-temp[j]);
                        for(int k=j+1;k<temp.size();k++)
                        {
                            tempd+= abs(temp[i]-temp[k]);
                            tempd+= abs(temp[j]-temp[k]);
                             mind=min(tempd,mind);
                             tempd=abs(temp[i]-temp[j]);
                        }
                    }
                    }
        return mind;
    }
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,int> freqlist;
        unordered_map<int,vector<int>> mp;
        int mindist=INT_MAX,temp=0;
        for(int i=0;i<nums.size();i++)
            {
                freqlist[nums[i]]++;
                mp[nums[i]].push_back(i);
            }
        int counter=0;
        for(int i=0;i<freqlist.size();i++)
            {
                if(freqlist[i]<3)
                    continue;
                else
                {
                    counter++;
                    temp=0;
                    temp=absdistance(mp[i]);
                    mindist=min(temp,mindist);
                }
            }
        if(counter==0)
            return -1;
        else
        return mindist;
    }
};