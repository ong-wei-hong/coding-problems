#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> dailyTemperatures(vector<int>& temperatures) {
			vector<int> result(temperatures.size(),0); 
			stack<pair<int,int>> prevTemp;
			for(int i=temperatures.size()-1;i>=0;--i) {
				while(!prevTemp.empty()) {
					if(prevTemp.top().first>temperatures[i]) {
						result[i]=prevTemp.top().second-i;
						break;
					}
					prevTemp.pop();
				}
				prevTemp.emplace(temperatures[i],i);
			}
			return result;
		}
	// time: O(temperatures.size())
};
