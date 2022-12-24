#pragma once
#include<utility>
#include"mymultimap.hpp"

template<class K, class V>
class mymap {
	mymultimap<K, V> mmp;
	struct SetCompare
	{
		const K& operator()(const pair<K, V>& key)
		{
			return key.first;
		}
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename mymultimap<K,V>::iterator iterator;

	mymap() {}
	mymap(mymap<K,V> & s) {
		for (auto it = s.begin(); it != s.end(); ++it) {
			insert(*it);
		}
	}

	V& operator[](K k) {
		iterator it = mmp.find(k);
		V rv;
		if (it == mmp.end()) {
			mmp.insert(make_pair(k, rv));
			it = mmp.find(k);
		}
		return it->second;
		
	}

	pair<iterator, bool> insert(const pair<K, V>& k)
	{
		if (mmp.find(k.first) != mmp.end()) {
			return make_pair(iterator(nullptr), false);
		}

		return mmp.insert(k);
	}
	iterator begin()
	{
		return mmp.begin();
	}
	iterator end()
	{
		return mmp.end();
	}
	void erease(iterator it) {
		mmp.erease(it);
	}
	void erease(iterator beg, iterator end) {
		mmp.erease(beg, end);
	}
	void clear() {
		mmp.erease(mmp.begin(), mmp.end());
	}

	bool empty() {
		return mmp.empty();
	}

	iterator find(K x) {
		return mmp.find(x);
	}
	iterator upper_bound(K x) {
		return mmp.upper_bound(x);
	}

	iterator lower_bound(K x) {
		return mmp.lower_bound(x);
	}
};