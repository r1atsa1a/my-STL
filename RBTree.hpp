#pragma once
//#ifndef _RBTREE_HPP_
//#define _RBTREE_HPP_
#include<utility>//��ȡpair���壬��֪��Ϊʲô�Լ�д��mypair�ܸ�ֵ����initializer list����ת��

using namespace std;
//ö�ٺ����ɫ
enum Color
{
	RED,
	BLACK
};

//���������Ľڵ�
template<class T>
struct RBTreeNode
{

	RBTreeNode<T>* left;//��ڵ�
	RBTreeNode<T>* right;//�ҽڵ�
	RBTreeNode<T>* parent;//���ڵ�
	Color color;//��ɫ
	T data;//����
	//��ʼ��
	RBTreeNode(const T& data) :left(nullptr), right(nullptr), parent(nullptr), data(data), color(BLACK) {}
};

//����������ĵ�����(����ɾ���Ľڵ�λ�ñ仯�������������
template<class T, class Ref, class Ptr>
struct IteratorRBTree
{
	typedef RBTreeNode<T> Node;
	typedef IteratorRBTree<T, Ref, Ptr> it;
	Node* node;

	//��ʼ��
	IteratorRBTree(Node* node = nullptr) :node(node) {}


	//���������
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

	//�ڵ�ָ��Ƚ�
	bool operator!=(const it& r) const
	{
		return node != r.node;
	}
	bool operator==(const it& r) const
	{
		return node == r.node;
	}

	//�ı������λ��
	it& operator++()
	{
		if (node == nullptr) {
			return *this;
		}
		if (node->right != nullptr)//���������������������������ڵ�
		{
			Node* left = node->right;
			while (left != nullptr && left->left != nullptr)
			{
				left = left->left;
			}
			node = left;
		}
		else//�Ҳ���������ʱ���Һ��Ӳ��Ǹ��ڵ����ӽڵ���Ǹ����ڵ�
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
		if (node->right != nullptr)//���������������������������ڵ�
		{
			Node* left = node->right;
			while (left != nullptr && left->left != nullptr)
			{
				left = left->left;
			}
			node = left;
		}
		else//�Ҳ���������ʱ���Һ��Ӳ��Ǹ��ڵ����ӽڵ���Ǹ����ڵ�
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
		if (node->left)//����������������������������ҽڵ�
		{
			Node* right = node->left;
			while (right->right)
			{
				right = right->right;
			}
			node = right;
		}
		else//������Ϊ��ʱ���Ҹ��ڵ��д˵㲻���������ĸ��ڵ�
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
	typedef RBTreeNode<T> Node;//�ڵ�
	typedef IteratorRBTree<T, T&, T*> iterator;//������

	void erease(iterator beg, iterator end) {
		for (auto it = beg; it != end;) {
			erease(it++);
		}
	}

	iterator begin()//���������һ��Ԫ���������Ԫ��
	{
		Node* beg = root;
		while (beg != nullptr && beg->left != nullptr)
		{
			beg = beg->left;
		}
		return iterator(beg);
	}

	iterator end()//endλ�������һ���ڵ����һ��λ�ã�ֱ��Ϊ�ռ���
	{
		return iterator(nullptr);
	}

	pair<iterator, bool> insert(const T& data)
	{
		Compare cop;
		if (root == nullptr)//��Ϊ��ʱ��ȷ�����ڽڵ�
		{
			root = new Node(data);
			root->color = BLACK;
			return make_pair(iterator(root), true);
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)//ȷ������ڵ��λ��
		{
			if (cop(cur->data) > cop(data))//�����������ݴ��ڸýڵ�����ݣ�������������
			{
				parent = cur;
				cur = cur->left;
			}
			else//���������������
			{
				parent = cur;
				cur = cur->right;
			}
		}

		//����Ҫ��������ݽڵ�
		cur = new Node(data);
		Node* newnode = cur;
		cur->color = RED;

		//����ڵ�
		if (cop(parent->data) > cop(data))
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		cur->parent = parent;

		//whileѭ���жϸ��ڵ��Ƿ���Ϻ�ڹ���
		while (parent && parent->color == RED)
		{
			Node* grandfather = parent->parent;

			if (grandfather->left == parent)//������үү���
			{
				Node* uncle = grandfather->right;

				if (uncle && uncle->color == RED)//���һ���������Ϊ�죬����Ҫ��ת
				{
					uncle->color = BLACK; //����ڵ���
					parent->color = BLACK;//���ڵ���
					grandfather->color = RED;//үү�ڵ���

					//��ɫ��������ϴ���
					cur = grandfather;
					parent = cur->parent;
				}
				else//����ڵ㲻���ڻ����Ϊ��
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
			else//������үү�ұ�ͬ����һ��ԭ��,������ת
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
		//���parent�����ڣ�˵��grandfather�Ǹ�
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

		if (ernode->left != nullptr && ernode->right != nullptr)//��Ҫɾ���Ľڵ�
		{
			ernode = ernode->left;
			while (ernode->right != nullptr)
			{
				ernode = ernode->right;
			}
			node->data = ernode->data;//����node��ֵ���滻��
		}

		Node* parent = ernode->parent;//��ɾ�����ĸ����
		Node* cnode = (ernode->right) ? ernode->right : ernode->left;//�ú����滻
		if (cnode != nullptr)//����к��ӣ����滻�߲�Ϊ��
		{
			cnode->parent = parent;//���º��ӵĸ����
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
					ereasenode(ernode);//�����ɾ������Ǻ�ɫ�͵���
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
		while (cur)//ȷ������ڵ��λ��
		{
			if (cop(cur->data) > cop(data))//�����������ݴ��ڸýڵ�����ݣ�������������
			{
				cur = cur->left;
			}
			else if (cop(cur->data) < cop(data))//���������������
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
		while (cur)//ȷ������ڵ��λ��
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
		while (cur)//ȷ������ڵ��λ��
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
	Node* root = nullptr;//ָ�����ڽڵ�

	void ereasenode(Node* node)
	{
		while (node != root && node->color == BLACK) {
			if (node->parent->left == node) {
				// ��ɾ���ĺ�ɫ�ڵ���������
				Node* brother = node->parent->right;
				if (col(brother) == RED) {
					// ���4
					node->parent->color = RED;		// �Ѹ���Ⱦ��
					brother->color = BLACK;			// ���ֵ�Ⱦ��
					RotaL(node->parent);			// �������ڵ�
					brother = node->parent->right;	// �����ֵ�
				}
				if (col(brother->left) == BLACK && col(brother->right) == BLACK) {
					brother->color = RED;
					node = node->parent;
				}
				else {
					// ���1��2 �������� ִ����ͻ��˳�
					if (col(brother->left) == RED && col(brother->right) == BLACK) {
						brother->color = RED;
						brother->left->color = BLACK;
						RotaR(brother);
						brother = node->parent->right;
					}

					//���1
					brother->color = node->parent->color;
					node->parent->color = BLACK;
					brother->right->color = BLACK;
					RotaL(node->parent);
					break;
				}
			}
			else {
				// ��ɾ���ĺ�ɫ�ڵ��������� �������漰����Ĳ�������һ�¾���
				Node* brother = node->parent->left;
				if (col(brother) == RED) {
					// ���4
					node->parent->color = RED;		// �Ѹ���Ⱦ��
					brother->color = BLACK;			// ���ֵ�Ⱦ��
					RotaR(node->parent);			// �������ڵ�
					brother = node->parent->left;	// �����ֵ�
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

		// �������nodeָ��Ľڵ��Ǻ�ɫ��ֱ��Ϳ�ɺ�ɫ����������
		node->color = BLACK;
	}

	Color col(Node* node) {
		return nullptr == node ? BLACK : node->color;
	}
	//����
	void RotaL(Node* node)
	{
		Node* child = node->right;
		child->parent = node->parent;
		if (node->parent == nullptr) {
			// node�����Ǹ��ڵ� �ӽڵ�ת��ȥ�ͻ��ɸ��ڵ�
			root = child;
		}
		else {
			if (node->parent->left == node) {
				// node�Ǹ��ڵ������
				node->parent->left = child;
			}
			else {
				// node�Ǹ��ڵ���Һ���
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

	//����
	void RotaR(Node* node)
	{
		Node* child = node->left;
		child->parent = node->parent;
		if (node->parent == nullptr) {
			// node�Ǹ��ڵ�
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
