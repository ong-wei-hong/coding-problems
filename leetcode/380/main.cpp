#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
	private:
		unordered_map<int,int> m;
		vector<int> v;
		mt19937 gen;

	public:
		RandomizedSet() {
			m.clear();
			v.clear();
		}

		bool insert(int val) {
			if(m.find(val)!=m.end()) return false;
			m[val]=v.size();
			v.push_back(val);
			return true;
		}
		// time: O(1)

		bool remove(int val) {
			auto it=m.find(val);
			if(it==m.end()) return false;
			v[it->second]=v.back();
			v.pop_back();
			m[v[it->second]]=it->second;
			m.erase(val);
			return true;
		}
		// time: O(1)

		int getRandom() {
			uniform_int_distribution<> distr(0,v.size()-1);
			return v[distr(gen)];
		}
		// time: O(1)
};
