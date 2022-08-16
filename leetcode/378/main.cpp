#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix,int k) {
			priority_queue<int> pq;
			for(auto& v: matrix) for(auto i: v) {
				pq.push(i);
				if(pq.size()>k) pq.pop();
			}
			return pq.top();
		}
	// time: O(n ** 2 * log k) where n = matrix.size()
	// space: O(k)
};
