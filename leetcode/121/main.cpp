#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int lowest=10000,profit=0;
			for(auto i: prices) lowest=min(lowest,i),profit=max(profit,i-lowest);
			return profit;
		}
	// time: O(prices.size())
};
