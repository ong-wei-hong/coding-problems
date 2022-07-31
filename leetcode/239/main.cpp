#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> maxSlidingWindow(vector<int>& nums,int k) {
			vector<int> result;
			deque<int> q;
			for(int i=0;i<nums.size();++i) {
				while(!q.empty()&&nums[q.back()]<=nums[i]) q.pop_back();
				q.push_back(i);
				if(i-k>=q.front()) q.pop_front();
				if(i+1>=k) result.push_back(nums[q.front()]);
			}
			return result;
		}
	// time: O(nums.size())
};
