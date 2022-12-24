#pragma once
// #include <iostream>
// using namespace std;
#include "mylist.hpp"

template <class T>
class myqueue
{
private:
    // 用list作为底层实现queue
    mylist<T> container;

public:
    typedef list_iterator<T> iterator;
    myqueue() {}
    myqueue(int n, const T &x = T())
    {
        for (int i = 0; i < n; i++)
        {
            container.push_back(x);
        }
    }
    ~myqueue()
    {
        container.clear();
    }
    T front()
    {
        return *container.begin();
    }
    T back()
    {
        return container.end().node->prev->data;
    }
    void push(T e)
    {
        container.push_back(e);
    }
    void pop()
    {
        container.pop_front();
    }
    bool empty()
    {
        return container.empty();
    }
    int size()
    {
        return container.size();
    }
};

//test

// int main()
// {
//     myqueue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);
//     q.push(5);
//     q.pop();
//     cout << q.size() << endl;
//     cout << q.front() << endl;
//     cout << q.back() << endl;
//     return 0;
// }
