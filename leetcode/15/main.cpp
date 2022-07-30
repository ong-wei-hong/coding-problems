#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int>> result;
			for(int i=0;i<nums.size();++i) {
				if(i>0&&nums[i]==nums[i-1]) continue;
				int l=i+1,r=nums.size()-1;
				while(l<r) {
					int a=nums[i]+nums[l]+nums[r];
					if(a<0) ++l;
					else if(a>0) --r;
					else {
						vector<int> v{nums[i],nums[l],nums[r]};
						result.push_back(v);

						do ++l; while(l<r&&nums[l]==nums[l-1]);
					}
				}
			}
			return result;
		}
	// time: O(n**2) where n = nums.size()
};
