#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxArea(vector<int>& height) {
			int l=0,r=height.size()-1,ans=0;
			while(l<r)
				if(height[l]>height[r]) {
					ans=max(ans,height[l]*(r-l));
					int i=l+1;
					while(i<r&&height[i]<=height[l]) ++i;
					l=i;
				} else {
					ans=max(ans,height[r]*(r-l));
					int i=r-1;
					while(i>l&&height[i]<=height[r]) --i;
					r=i;
				}
			return ans;
		}
	// time: O(height.size())
};

