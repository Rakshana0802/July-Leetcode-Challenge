typedef pair<int, int> P;
class Solution 
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) 
    {
		unordered_map<int, int> cnt;
		for (int x : nums) 	
            cnt[x] ++;
		priority_queue<P, vector<P>, greater<P> > q;
		for (auto &x : cnt) 
        {
			if (q.size() < k)
				q.push(make_pair(x.second, x.first));
			else 
            {
				if (q.top().first < x.second) 
                {
					q.pop();
					q.push(make_pair(x.second, x.first));
				}
			}
		}
		vector<int> ans;
		while (!q.empty()) 
        {
			ans.push_back(q.top().second);
			q.pop();
		}
		return ans;
	}
};
