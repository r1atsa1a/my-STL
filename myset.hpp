#pragma once

#include"mymultiset.hpp"

template<class K>
class myset {
	mymultiset<K> mset;
	struct SetCompare
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
public:
	typedef typename mymultiset<K>::iterator iterator;

	myset() {}
	myset(myset<K>& s) {
		for (auto it = s.begin(); it != s.end(); ++it) {
			insert(*it);
		}
	}

	pair<iterator, bool> insert(const K& k)
	{
		if (mset.find(k) != mset.end()) {
			return make_pair(iterator(nullptr), false);
		}
		
		return mset.insert(k);
	}
	iterator begin()
	{
		return mset.begin();
	}
	iterator end()
	{
		return mset.end();
	}
	void erease(iterator it) {
		mset.erease(it);
	}
	void erease(iterator beg, iterator end) {
		mset.erease(beg, end);
	}
	void clear() {
		mset.erease(mset.begin(), mset.end());
	}

	bool empty() {
		return mset.empty();
	}

	iterator find(K x) {
		return mset.find(x);
	}
	iterator upper_bound(K x) {
		return mset.upper_bound(x);
	}

	iterator lower_bound(K x) {
		return mset.lower_bound(x);
	}
};