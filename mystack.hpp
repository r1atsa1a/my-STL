#pragma once
// #include <iostream>
// using namespace std;
#include "mylist.hpp"

template <typename T>
class mystack
{
private:
    // 用list作为底层实现stack
    mylist<T> container;

public:
    typedef list_iterator<T> iterator;
    mystack() {}
    mystack(int n, const T &x = T())
    {
        for (int i = 0; i < n; i++)
        {
            container.push_back(x);
        }
    }
    ~mystack()
    {
        container.clear();
    }
    T top()
    {
        T x = container.end().node->prev->data;
        return x;
    }
    void push(T e)
    {
        container.push_back(e);
    }
    void pop()
    {
        container.pop_back();
    }
    bool empty()
    {
        return container.empty();
    }
    int size()
    {
        return container.size();
    }
    iterator begin()
    {
        return container.begin();
    }
    iterator end()
    {
        return container.end();
    }
};

//test

// int main()
// {
//     mystack<int> s;
//     cout << s.empty() << endl;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.pop();
//     cout << s.top() << endl;
//     cout << s.size() << endl;
// }
