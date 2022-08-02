#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		bool canConstruct(string ransomNote,string magazine) {
			vector<int> m(26,0);
			for(auto c: magazine) ++m[c-'a'];
			for(auto c: ransomNote) --m[c-'a'];
			for(auto i: m) if(i<0) return false;
			return true;
		}
	// time: O(ransomNote.size()+magazine.size())
};
