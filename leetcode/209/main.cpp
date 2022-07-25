#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minSubArrayLen(int target, vector<int>& nums) {
			int ans=nums.size()+1, start=0, rolling_sum=0;
			for(int end=0;end<nums.size();++end) {
				rolling_sum += nums[end];
				while(rolling_sum >= target) {
					ans = min(ans, end-start+1);
					rolling_sum -= nums[start++];
				}
			}
			if(ans==nums.size()+1) return 0;
			return ans;
		}
	// time: O(nums.size())
};

