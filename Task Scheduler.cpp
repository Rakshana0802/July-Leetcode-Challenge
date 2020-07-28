class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
         unordered_map<char,int>m;
         int maxN = -1;
         for(auto i: tasks)
        {
            m[i]++;
            maxN = max(maxN,m[i]);
        }
        int ans = (n+1)*(maxN-1);
        for(auto itr: m) 
            if(itr.second == maxN) 
                ans++;  
        
        return max(ans,(int)tasks.size());
    }
};
