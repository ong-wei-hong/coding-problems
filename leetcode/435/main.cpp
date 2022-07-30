#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int eraseOverlapintervals(vector<vector<int>>& intervals) {
			sort(intervals.begin(),intervals.end());
			int currEnd=intervals[0][1],ans=0;
			for(int i=1;i<intervals.size();++i)
				if(intervals[i][0]<currEnd) {
					++ans;
					currEnd=min(currEnd,intervals[i][1]);
				} else currEnd=intervals[i][1];
			return ans;
		}
	// time: O(n log n) where n = intervals.size()
};
