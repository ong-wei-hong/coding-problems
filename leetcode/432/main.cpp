#include <bits/stdc++.h>
using namespace std;

class AllOne {
	private:
		list<pair<int,unordered_set<string>>> m_freqToKey;
		unordered_map<string,list<pair<int,unordered_set<string>>>::iterator> m_keyToSet;
	
	public:
		AllOne() {
		}

		void inc(string key) {
			auto keyToSetItr=m_keyToSet.find(key);
			if(keyToSetItr==m_keyToSet.end()) {
				if(m_freqToKey.empty()||m_freqToKey.front().first!=1) {
					unordered_set<string> s;
					m_freqToKey.emplace_front(1,s);
				}
				m_freqToKey.front().second.insert(key);
				m_keyToSet[key]=m_freqToKey.begin();
				return;
			}

			auto freqToKeyItr=keyToSetItr->second;
			int prevFreq=freqToKeyItr->first;
			++freqToKeyItr;
			if(freqToKeyItr==m_freqToKey.end()||freqToKeyItr->first!=prevFreq+1) {
				unordered_set<string> s;
				m_freqToKey.insert(freqToKeyItr,make_pair(prevFreq+1,s));
				--freqToKeyItr;
			}
			freqToKeyItr->second.insert(key);
			m_keyToSet[key]=freqToKeyItr;
			--freqToKeyItr;
			freqToKeyItr->second.erase(key);
			if(freqToKeyItr->second.empty()) m_freqToKey.erase(freqToKeyItr);
		}

		// time: O(1) amortized
		// space: O(1)

		void dec(string key) {
			auto freqToKeyItr=m_keyToSet[key];
			if(freqToKeyItr->first==1) {
				freqToKeyItr->second.erase(key);
				m_keyToSet.erase(key);
				if(freqToKeyItr->second.empty()) m_freqToKey.erase(freqToKeyItr);
				return;
			}
			int newFreq=(freqToKeyItr->first)-1;
			if(freqToKeyItr==m_freqToKey.begin()) {
				unordered_set<string> s;
				m_freqToKey.emplace_front(newFreq,s);
			}
			--freqToKeyItr;
			if(freqToKeyItr->first!=newFreq) {
				++freqToKeyItr;
				unordered_set<string> s;
				m_freqToKey.insert(freqToKeyItr,make_pair(newFreq,s));
				--freqToKeyItr;
			}
			freqToKeyItr->second.insert(key);
			m_keyToSet[key]=freqToKeyItr;
			++freqToKeyItr;
			freqToKeyItr->second.erase(key);
			if(freqToKeyItr->second.empty()) m_freqToKey.erase(freqToKeyItr);
		}

		// time: O(1) amotized
		// space: O(1)

		string getMaxKey() {
			if(m_freqToKey.empty()) return "";
			return *(m_freqToKey.rbegin()->second.begin());
		}

		// time: O(1)
		// space: O(1)

		string getMinKey() {
			if(m_freqToKey.empty()) return "";
			return *(m_freqToKey.begin()->second.begin());
		}

		// time: O(1)
		// space: O(1)
	
		// total space: O(n) where n is the number of unique strings inserted
};
