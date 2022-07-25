#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		void merge(vector<int>& nums1,int m,vector<int>& nums2,int n) {
			vector<int> merged;
			int nums1_p=0,nums2_p=0;

			while(nums1_p<m&&nums2_p<n)
				if(nums1[nums1_p]<nums2[nums2_p]) merged.push_back(nums1[nums1_p++]);
				else merged.push_back(nums2[nums2_p++]);

			while(nums1_p<m) merged.push_back(nums1[nums1_p++]);
			while(nums2_p<n) merged.push_back(nums2[nums2_p++]);

			nums1.assign(merged.begin(),merged.end());
		}
	// time: O(m+n)
};
