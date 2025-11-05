# Asteroid Collision
Solved on 2025-10-22

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=asteroids.size()-1;i>=0;i--)
        {
            if(st.empty())
            st.push(asteroids[i]);
            else if(st.top()<0 && asteroids[i]>0)
            {
                if(abs(st.top())>asteroids[i])
                continue;
                else if(abs(st.top())==asteroids[i])
                {
                    st.pop();
                }
                else
                {
                    st.pop();
                    i++;
                }
            }
            else 
            st.push(asteroids[i]);
        }
        asteroids.clear();
        while(!st.empty())
        {
            asteroids.push_back(st.top());
            st.pop();
        }
        return asteroids;
    }
};