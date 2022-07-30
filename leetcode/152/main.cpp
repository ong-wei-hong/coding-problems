#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			int highest=nums[0],currHighest=nums[0],currLowest=nums[0];
			for(int i=1;i<nums.size();++i) {
				int a=nums[i],b=max(a,currLowest*a),c=min(a,currHighest*a);
				currHighest=max(b,currHighest*a);
				currLowest=min(c,currLowest*a);
				highest=max(highest,currHighest);
			}
			return highest;
		}
	// time: O(nums.size())
};
