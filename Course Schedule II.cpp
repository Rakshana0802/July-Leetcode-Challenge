class Solution 
{
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) 
    {
        map<int,vector<int>>mp;
        for(int i=0 ; i<pr.size() ; i++) 
            mp[pr[i][1]].push_back(pr[i][0]);    
        vector<int>indegree(n,0);                                             
        for(auto x:mp)
            for(auto y:x.second) 
                indegree[y]++;                             
        
        queue<int>q;
        for(int i=0 ; i<n ; i++) 
            if(indegree[i]==0) 
                q.push(i);            
        vector<int>res;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto x:mp[node])
            {
                indegree[x]--;                                  
                if(indegree[x]==0) q.push(x);                  
            }
        }
        if(res.size()!=n) return {};         
        return res;                        
    }
};
