#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> canSeePersonsCount(vector<int>& heights) {
			vector<int> result(heights.size(),0);
			stack<int> currHeights;
			currHeights.push(heights[heights.size()-1]);
			for(int i=heights.size()-2;i>=0;--i) {
				while(!currHeights.empty()&&heights[i]>currHeights.top()) ++result[i],currHeights.pop();
				result[i]+=(!currHeights.empty());
				currHeights.push(heights[i]);
			}
			return result;
		}
	// time: O(heights.size())
};
