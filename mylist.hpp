#pragma once
// #include <iostream>
// using namespace std;
template <typename T> // 设置链表节点的模版类
class list_node       // 一个双端指针的链表节点
{
public:
    list_node<T> *next; // 指向下一个元素的指针
    list_node<T> *prev; // 指向上一个元素的指针
    T data;             // 数据
    list_node(T da = T(), list_node<T> *ne = NULL, list_node<T> *pr = NULL) : data(da), next(ne), prev(pr) {}
    ~list_node() {}
};

template <typename T> // 设置链表的迭代器的模版类
class list_iterator   // 一个普通的迭代器
{
private:
    typedef list_node<T> *lnode; // list_node<int> *
    typedef list_iterator<T> self;

public:
    lnode node;
    list_iterator(lnode n) : node(n) {}
    ~list_iterator() {}
    self &operator++() // 重构前置++
    {
        node = node->next;
        return *this;
    }
    self operator++(int) // 重构后置++
    {
        self t(*this);
        node = node->next;
        return t;
    }
    self &operator--() // 重构前置--
    {
        node = node->prev;
        return *this;
    }
    self operator--(int) // 重构后置--
    {
        self t(*this);
        node = node->prev;
        return t;
    }
    bool operator!=(const self &it) const // 重构!=
    {
        return node != it.node;
    }
    bool operator==(const self &it) const // 重构==
    {
        return node == it.node;
    }
    T &operator*() // 重构*
    {
        return node->data;
    }
    T *operator->() // 重构->
    {
        return &(node->data);
    }
};

template <typename T>
class mylist // 设置链表的模版类
{
public:
    typedef list_node<T> lnode;
    typedef list_iterator<T> iterator;

private:
    lnode *head;

public:
    mylist() // 默认构造函数
    {
        head = new lnode();
        head->next = head;
        head->prev = head;
    }
    iterator begin()
    {
        return iterator(head->next);
    }
    iterator end()
    {
        return iterator(head);
    }
    iterator insert(iterator pos, T x)
    {
        lnode *cur = pos.node;
        lnode *prev = cur->prev;
        lnode *newnode = new lnode(x);
        prev->next = newnode;
        newnode->prev = prev;
        newnode->next = cur;
        cur->prev = newnode;
        return iterator(newnode);
    }
    iterator erase(iterator pos)
    {
        if (pos == end()) // 用于判断链表是否为空，若为空则将退出程序
        {
            cout << "empty!" << endl;
            exit(-2);
        }
        lnode *prev = pos.node->prev;
        lnode *next = pos.node->next;
        delete pos.node;
        prev->next = next;
        next->prev = prev;
        return iterator(next);
    }
    void push_back(T x)
    {
        insert(end(), x);
    }
    void pop_back()
    {
        erase(--end());
    }
    void push_front(T x)
    {
        insert(begin(), x);
    }
    void pop_front()
    {
        erase(begin());
    }
    mylist(int n, const T &x = T())
    {
        head = new lnode;
        head->next = head;
        head->prev = head;
        for (int i = 0; i < n; i++)
        {
            push_back(x);
        }
    }
    mylist(const mylist<T> &t)
    {
        head = new lnode();
        head->next = head;
        head->prev = head;
        for (iterator ita(t.head->next); ita != t.head; ++ita)
        {
            push_back(*ita);
        }
    }
    void clear()
    {
        iterator ita = begin(), ite = end();
        while (ita != ite)
        {
            iterator d = ita;
            ++ita;
            delete d.node;
        }

        head->next = head;
        head->prev = head;
    }
    ~mylist()
    {
        clear();
        delete head;
        head = NULL;
    }
    int size()
    {
        int cnt = 0;
        iterator it = begin();
        while (it != end())
        {
            cnt++;
            it++;
        }
        return cnt;
    }
    bool empty()
    {
        if (head->next == head)
            return true;
        return false;
    }
    void sort()
    {
        int len = size();
        iterator ita = begin(), itb = end(), minit = begin();
        for (; ita != itb; ++ita)
        {
            minit = ita;
            for (iterator it = ita; it != itb; ++it)
            {
                if ((it.node)->data < (minit.node)->data)
                {
                    minit = it;
                }
            }
            if (minit != ita)
            {
                if ((ita.node)->next != minit.node)
                {
                    iterator ita_next = (ita.node)->next, ita_prev = (ita.node)->prev;
                    iterator minit_next = (minit.node)->next, minit_prev = (minit.node)->prev;
                    (ita_next.node)->prev = minit.node;
                    (ita_prev.node)->next = minit.node;
                    (minit_next.node)->prev = ita.node;
                    (minit_prev.node)->next = ita.node;
                    (minit.node)->prev = ita_prev.node;
                    (minit.node)->next = ita_next.node;
                    (ita.node)->prev = minit_prev.node;
                    (ita.node)->next = minit_next.node;
                }
                else
                {
                    iterator ita_prev = (ita.node)->prev;
                    iterator minit_next = (minit.node)->next;
                    (ita_prev.node)->next = minit.node;
                    (minit_next.node)->prev = ita.node;
                    (minit.node)->prev = ita_prev.node;
                    (minit.node)->next = ita.node;
                    (ita.node)->prev = minit.node;
                    (ita.node)->next = minit_next.node;
                }
                ita = minit;
            }
        }
    }
    mylist<T> &operator=(const mylist<T> a)
    {
        std::swap(head, a.head);
        return *this;
    }
};
//test

// int main()
// {
//     mylist<int> l(1, 2);
//     l.push_back(1);
//     l.push_front(3);
//     l.push_back(2);
//     mylist<int> l1 = l;
//     l.pop_back();
//     l.pop_front();
//     l.pop_back();
//     l.pop_front();
//     cout << l.empty() << endl;
//     mylist<int>::iterator ita = l1.begin();
//     for (; ita != l1.end(); ++ita)
//     {
//         cout << *ita << ' ';
//     }
//     cout << endl;
//     l1.sort();
//     ita = l1.begin();
//     for (; ita != l1.end(); ++ita)
//     {
//         cout << *ita << ' ';
//     }
//     cout << endl;
//     cout << l.size() << endl;
//     l1.clear();
//     cout << l1.size() << endl;
//     return 0;
// }
