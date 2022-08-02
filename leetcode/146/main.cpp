#include <bits/stdc++.h>
using namespace std;

class LRUCache {
	private:
		size_t m_capacity;
		unordered_map<int,list<pair<int,int>>::iterator> m_map;
		list<pair<int,int>> m_list;
	public:
		LRUCache(int capacity): m_capacity(capacity) {
		}

		int get(int key) {
			auto it=m_map.find(key);
			if(it==m_map.end()) return -1;
			m_list.splice(m_list.begin(),m_list,it->second);
			return it->second->second;
		}
		// time: O(1)

		void put(int key,int value) {
			auto it=m_map.find(key);
			if(it!=m_map.end()) {
				m_list.splice(m_list.begin(),m_list,it->second);
				it->second->second=value;
				return;
			}
			if(m_map.size()==m_capacity) {
				m_map.erase(m_list.back().first);
				m_list.pop_back();
			}
			m_list.emplace_front(key,value);
			m_map[key]=m_list.begin();
		}
		// time: O(1)
};
