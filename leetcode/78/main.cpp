#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>> result;
			vector<int> curr;
			result.push_back(curr);
			for(int i: nums) {
				int l=result.size();
				for(int j=0;j<l;++j) result.push_back(result[j]),result.back().push_back(i);
			}
			return result;
		}
	// time: O(n * 2 ** n) where n=nums.size()
	// space: O(2 ** n)
};
