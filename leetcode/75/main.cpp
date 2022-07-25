#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			vector<int> freq(3,0);
			for(int i:nums) ++freq[i];
			int index=0;
			for(int i=0;i<3;++i) for(int j=0;j<freq[i];++j) nums[index++]=i;
		}
	// time: O(nums.size())
};
