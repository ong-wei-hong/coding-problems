#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
			sort(intervals.begin(),intervals.end());
			vector<vector<int>> result;
			for(auto& i: result) 
				if (result.size()==0||result[result.size()-1][1]<i[0]) {
					vector<int> v;
					v.push_back(i[0]); v.push_back(i[1]);
					result.push_back(v);
				} else result[result.size()-1][1] = max(result[result.size()-1][1], i[1]);
			return result;
		}
	// time: O(n log n) where n = intervals.size();
};
