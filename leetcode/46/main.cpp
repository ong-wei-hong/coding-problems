#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> permute(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			vector<vector<int>> result;
			do result.push_back(nums); while(next_permutation(nums.begin(),nums.end()));
			return result;
		}
	// time: O(n * n!) where n = nums.size()
};
