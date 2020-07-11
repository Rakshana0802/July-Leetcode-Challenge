class Solution 
{
public:
    vector<vector<int> > result;
    vector<vector<int> > subsets(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i;
        for(i=0; i<=n; i++)
        {
            vector<int> subset;
            dfs(nums, subset, 0, i);
        }
        return result;
    }
    
    void dfs(vector<int>& nums, vector<int> subset, int pos, int m)
    {
        if(subset.size() == m)
        {
            result.push_back(subset);
            return ;
        }   
        int i;
        int n = nums.size();
        for(i=pos; i<n; i++)
        {
            subset.push_back(nums[i]);
            dfs(nums, subset, i+1, m);
            subset.pop_back();
        }
    }
};
