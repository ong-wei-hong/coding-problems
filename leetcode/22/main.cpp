#include <bits/stdc++.h>
using namespace std;

class Solution {
	private:
		void r(int n,int open,int close,string& s,vector<string>& result) {
			if(n==open&&n==close) {
				result.push_back(s);
				return;
			}
			if(open<n) {
				s.push_back('(');
				r(n,open+1,close,s,result);
				s.pop_back();
			}
			if(close<open) {
				s.push_back(')');
				r(n,open,close+1,s,result);
				s.pop_back();
			}
		}
	public:
		vector<string> generateParenthesis(int n) {
			string s="";
			vector<string> result;
			r(n,0,0,s,result);
			return result;
		}
	// time: O(n) where n is the number of output (which i think is 3**n)
	// space: O(n) where n is the number of output (see above)
};
