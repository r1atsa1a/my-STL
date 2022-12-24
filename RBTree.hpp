#pragma once
//#ifndef _RBTREE_HPP_
//#define _RBTREE_HPP_
#include<utility>//获取pair定义，不知道为什么自己写的mypair总赋值错误，initializer list不能转化

using namespace std;
//枚举红黑颜色
enum Color
{
	RED,
	BLACK
};

//定义红黑树的节点
template<class T>
struct RBTreeNode
{

	RBTreeNode<T>* left;//左节点
	RBTreeNode<T>* right;//右节点
	RBTreeNode<T>* parent;//父节点
	Color color;//颜色
	T data;//数据
	//初始化
	RBTreeNode(const T& data) :left(nullptr), right(nullptr), parent(nullptr), data(data), color(BLACK) {}
};

//建立红黑树的迭代器(插入删除的节点位置变化）（中序遍历）
template<class T, class Ref, class Ptr>
struct IteratorRBTree
{
	typedef RBTreeNode<T> Node;
	typedef IteratorRBTree<T, Ref, Ptr> it;
	Node* node;

	//初始化
	IteratorRBTree(Node* node = nullptr) :node(node) {}


	//重载运算符
	Ref operator*()
	{
		if (node == nullptr) {
			exit(0);
		}
		return node->data;
	}
	Ptr operator->()
	{
		if (node == nullptr) {
			exit(0);
		}
		return &node->data;
	}

	//节点指针比较
	bool operator!=(const it& r) const
	{
		return node != r.node;
	}
	bool operator==(const it& r) const
	{
		return node == r.node;
	}

	//改变迭代器位置
	it& operator++()
	{
		if (node == nullptr) {
			return *this;
		}
		if (node->right != nullptr)//如果有右子树，找右子树的最左节点
		{
			Node* left = node->right;
			while (left != nullptr && left->left != nullptr)
			{
				left = left->left;
			}
			node = left;
		}
		else//找不到右子树时，找孩子不是父节点右子节点的那个父节点
		{
			Node* parent = node->parent;
			Node* cur = node;

			while (parent && parent->right == cur)
			{
				parent = parent->parent;
				cur = cur->parent;
			}
			node = parent;
		}

		return *this;
	}

	it operator++(int a)
	{
		Node* res = node;
		if (node == nullptr) {
			return *this;
		}
		if (node->right != nullptr)//如果有右子树，找右子树的最左节点
		{
			Node* left = node->right;
			while (left != nullptr && left->left != nullptr)
			{
				left = left->left;
			}
			node = left;
		}
		else//找不到右子树时，找孩子不是父节点右子节点的那个父节点
		{
			Node* parent = node->parent;
			Node* cur = node;

			while (parent && parent->right == cur)
			{
				parent = parent->parent;
				cur = cur->parent;
			}
			node = parent;
		}

		return IteratorRBTree(res);
	}

	it& operator--()
	{
		if (node->left)//如果存在左子树，找左子树的最右节点
		{
			Node* right = node->left;
			while (right->right)
			{
				right = right->right;
			}
			node = right;
		}
		else//左子树为空时，找父节点中此点不是左子树的父节点
		{
			Node* parent = node->parent;
			Node* cur = node;

			while (parent && parent->left == cur)
			{
				parent = parent->parent;
				cur = cur->parent;
			}
			node = parent;
		}
		return *this;
	}
};

template<class K, class T, class Compare>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;//节点
	typedef IteratorRBTree<T, T&, T*> iterator;//迭代器

	void erease(iterator beg, iterator end) {
		for (auto it = beg; it != end;) {
			erease(it++);
		}
	}

	iterator begin()//中序遍历第一个元素是最左端元素
	{
		Node* beg = root;
		while (beg != nullptr && beg->left != nullptr)
		{
			beg = beg->left;
		}
		return iterator(beg);
	}

	iterator end()//end位置是最后一个节点的下一个位置，直接为空即可
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> insert(const T& data)
	{
		Compare cop;
		if (root == nullptr)//树为空时，确定祖宗节点
		{
			root = new Node(data);
			root->color = BLACK;
			return make_pair(iterator(root), true);
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)//确定插入节点的位置
		{
			if (cop(cur->data) > cop(data))//如果插入的数据大于该节点的数据，插入在右子树
			{
				parent = cur;
				cur = cur->left;
			}
			else//否则插入在左子树
			{
				parent = cur;
				cur = cur->right;
			}
		}

		//建立要插入的数据节点
		cur = new Node(data);
		Node* newnode = cur;
		cur->color = RED;

		//插入节点
		if (cop(parent->data) > cop(data))
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		cur->parent = parent;

		//while循环判断父节点是否符合红黑规则
		while (parent && parent->color == RED)
		{
			Node* grandfather = parent->parent;

			if (grandfather->left == parent)//父亲在爷爷左边
			{
				Node* uncle = grandfather->right;

				if (uncle && uncle->color == RED)//情况一叔叔存在且为红，不需要旋转
				{
					uncle->color = BLACK; //叔叔节点变黑
					parent->color = BLACK;//父节点变黑
					grandfather->color = RED;//爷爷节点变红

					//变色后继续向上处理
					cur = grandfather;
					parent = cur->parent;
				}
				else//叔叔节点不存在或存在为黑
				{
					if (cur == parent->right)
					{
						RotaL(parent);
					}
					parent->color = BLACK;
					grandfather->color = RED;
					RotaR(grandfather);
				}
			}
			else//父亲在爷爷右边同上面一样原理,镜像旋转
			{
				Node* uncle = grandfather->left;
				if (uncle && uncle->color == RED)
				{
					uncle->color = BLACK;
					parent->color = BLACK;
					grandfather->color = RED;

					cur = grandfather;
					parent = cur->parent;
				}
				else
				{
					if (cur == parent->left)
					{
						RotaR(parent);
					}
					parent->color = BLACK;
					grandfather->color = RED;
					RotaL(grandfather);
				}
			}
		}
		//如果parent不存在，说明grandfather是根
		root->color = BLACK;
		return make_pair(iterator(newnode), true);
	}

	void erease(iterator replace)
	{
		if (replace == nullptr || root == nullptr) {
			return;
		}
		Node* node = replace.node;
		Node* ernode = node;

		if (ernode->left != nullptr && ernode->right != nullptr)//找要删除的节点
		{
			ernode = ernode->left;
			while (ernode->right != nullptr)
			{
				ernode = ernode->right;
			}
			node->data = ernode->data;//更新node的值（替换）
		}

		Node* parent = ernode->parent;//待删除结点的父结点
		Node* cnode = (ernode->right) ? ernode->right : ernode->left;//用孩子替换
		if (cnode != nullptr)//如果有孩子，即替换者不为空
		{
			cnode->parent = parent;//更新孩子的父结点
			if (parent == nullptr) {
				root = cnode;
			}
			else {
				if (parent->left == ernode) {
					parent->left = cnode;
				}
				else {
					parent->right = cnode;
				}
			}
			if (ernode->color == BLACK) {
				ereasenode(cnode);
			}
			delete ernode;
			ernode = nullptr;
		}
		else {
			if (parent == nullptr) {
				delete ernode;
				ernode = nullptr;
				root = nullptr;
				return;
			}
			else {
				if (ernode->color == BLACK)
				{
					ereasenode(ernode);//如果待删除结点是黑色就调整
				}
				if (parent->left == ernode) {
					parent->left = nullptr;
				}
				else {
					parent->right = nullptr;
				}
			}
		}
	}

	bool empty() {
		return root == nullptr;
	}

	iterator find(K data) {
		Compare cop;
		Node* cur = root;
		while (cur)//确定插入节点的位置
		{
			if (cop(cur->data) > cop(data))//如果插入的数据大于该节点的数据，插入在右子树
			{
				cur = cur->left;
			}
			else if (cop(cur->data) < cop(data))//否则插入在左子树
			{
				cur = cur->right;
			}
			else {
				return (lower_bound(data));
			}
		}
		return iterator(nullptr);
	}

	iterator upper_bound(K data) {
		Compare cop;
		Node* cur = root;
		Node* res = root;
		while (cur)//确定插入节点的位置
		{
			res = cur;
			if (cop(cur->data) > cop(data))
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
		if (cop(res->data) == cop(data)) {
			return ++iterator(res);
		}
		return iterator(res);
	}

	iterator lower_bound(K data) {
		Compare cop;
		Node* cur = root;
		Node* res = root;
		while (cur)//确定插入节点的位置
		{
			res = cur;
			if (cop(cur->data) >= cop(data))
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
		if (cop(res->data) != cop(data)) {
			return ++iterator(res);
		}
		return iterator(res);
	}

private:
	Node* root = nullptr;//指向祖宗节点

	void ereasenode(Node* node)
	{
		while (node != root && node->color == BLACK) {
			if (node->parent->left == node) {
				// 待删除的黑色节点在左子树
				Node* brother = node->parent->right;
				if (col(brother) == RED) {
					// 情况4
					node->parent->color = RED;		// 把父亲染红
					brother->color = BLACK;			// 把兄弟染黑
					RotaL(node->parent);			// 左旋父节点
					brother = node->parent->right;	// 重置兄弟
				}
				if (col(brother->left) == BLACK && col(brother->right) == BLACK) {
					brother->color = RED;
					node = node->parent;
				}
				else {
					// 情况1、2 进入这里 执行完就会退出
					if (col(brother->left) == RED && col(brother->right) == BLACK) {
						brother->color = RED;
						brother->left->color = BLACK;
						RotaR(brother);
						brother = node->parent->right;
					}

					//情况1
					brother->color = node->parent->color;
					node->parent->color = BLACK;
					brother->right->color = BLACK;
					RotaL(node->parent);
					break;
				}
			}
			else {
				// 待删除的黑色节点在右子树 把上面涉及方向的操作都反一下就行
				Node* brother = node->parent->left;
				if (col(brother) == RED) {
					// 情况4
					node->parent->color = RED;		// 把父亲染红
					brother->color = BLACK;			// 把兄弟染黑
					RotaR(node->parent);			// 左旋父节点
					brother = node->parent->left;	// 重置兄弟
				}
				if (col(brother->left) == BLACK && col(brother->right) == BLACK) {
					brother->color = RED;
					node = node->parent;
				}
				else {
					if (col(brother->left) == RED && col(brother->right) == BLACK) {
						brother->color = RED;
						brother->right->color = BLACK;
						RotaL(brother);
						brother = node->parent->left;
					}
					brother->color = node->parent->color;
					node->parent->color = BLACK;
					brother->left->color = BLACK;
					RotaR(node->parent);
					break;
				}
			}
		}

		// 如果发现node指向的节点是红色，直接涂成黑色，调整结束
		node->color = BLACK;
	}

	Color col(Node* node) {
		return nullptr == node ? BLACK : node->color;
	}
	//左旋
	void RotaL(Node* node)
	{
		Node* child = node->right;
		child->parent = node->parent;
		if (node->parent == nullptr) {
			// node本身是根节点 子节点转上去就会变成根节点
			root = child;
		}
		else {
			if (node->parent->left == node) {
				// node是父节点的左孩子
				node->parent->left = child;
			}
			else {
				// node是父节点的右孩子
				node->parent->right = child;
			}
		}

		node->right = child->left;
		if (child->left != nullptr) {
			child->left->parent = node;
		}

		child->left = node;
		node->parent = child;
	}

	//右旋
	void RotaR(Node* node)
	{
		Node* child = node->left;
		child->parent = node->parent;
		if (node->parent == nullptr) {
			// node是根节点
			root = child;
		}
		else {
			if (node->parent->left == node) {
				node->parent->left = child;
			}
			else {
				node->parent->right = child;
			}
		}

		node->left = child->right;
		if (child->right != nullptr) {
			child->right->parent = node;
		}

		child->right = node;
		node->parent = child;

	}
};

//#endif // !_RBTREE_HPP_
