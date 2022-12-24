#pragma once
//#ifndef _SET_HPP_
//#define _SET_HPP_

#include"RBTree.hpp"

template<class K>
class mymultiset
{
	struct SetCompare
	{
		const K& operator()(const K& key)
		{
			return key;
		}
	};
	RBTree<K, K, SetCompare> rbtree;
public:
	typedef typename RBTree<K, K, SetCompare>::iterator iterator;

	mymultiset() {}
	mymultiset(mymultiset<K>& mst) {
		for (auto it = mst.begin(); it != mst.end(); ++it) {
			insert(*it);
		}
	}

	pair<iterator, bool> insert(const K& k)
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

