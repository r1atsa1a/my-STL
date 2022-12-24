#pragma once
//#ifndef _SET_HPP_
//#define _SET_HPP_

#include"RBTree.hpp"

template<class K, class V>
class mymultimap
{
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
	RBTree<K, pair<K,V>, SetCompare> rbtree;
public:
	typedef typename RBTree<K, pair<K, V>, SetCompare>::iterator iterator;
	mymultimap(){}
	mymultimap(mymultimap<K,V>& mmp) {
		for (auto it = mmp.begin(); it != mmp.end(); ++it) {
			insert(*it);
		}
	}
	pair<iterator, bool> insert(const pair<K, V>& k)
	{
		return rbtree.insert(k);
	}
	iterator begin()
	{
		return rbtree.begin();
	}
	iterator end()
	{
		return rbtree.end();
	}
	void erease(iterator it) {
		rbtree.erease(it);
	}
	void erease(iterator beg, iterator end) {
		rbtree.erease(beg, end);
	}
	void clear() {
		rbtree.erease(rbtree.begin(), rbtree.end());
	}

	bool empty() {
		return rbtree.empty();
	}

	iterator find(K x) {
		return rbtree.find(x);
	}
	iterator upper_bound(K x) {
		return rbtree.upper_bound(x);
	}

	iterator lower_bound(K x) {
		return rbtree.lower_bound(x);
	}
};
//#endif // !_SET_HPP_

