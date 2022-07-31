#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int longestPalindromicSubseq(string s) {
			vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
			for(int i=s.size()-1;i>=0;--i) {
				dp[i][i]=1;
				for(int j=i+1;j<s.size();++j) {
					dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
					if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
				}
			}
			return dp[0][s.size()-1];
		}
	// time: O(n**2) where n=s.size()
};
