#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int highest=-10000,currHighest=-10000;
			for(int i:nums) currHighest=max(currHighest+i,i),highest=max(highest,currHighest);
			return highest;
		}
	// time: O(nums.size())
};
