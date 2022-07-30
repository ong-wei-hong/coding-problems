#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> productExceptSelf(vector<int>& nums) {
			vector<int> result(nums.size());
			int p=1;
			for(int i=0;i<nums.size();++i) result[i]=p,p*=nums[i];
			p=1;
			for(int i=nums.size()-1;i>=0;--i) result[i]*=p,p*=nums[i];
			return result;
		}
	// time: O(nums.size());
};
