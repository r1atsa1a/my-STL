#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

//迭代器
template<class T, class Ref, class Ptr>
class Deque_Iterator {
public:
    typedef Deque_Iterator<T, Ref, Ptr> it;
    T* _curr;
    Deque_Iterator(T* __curr = nullptr) : _curr(__curr) {}
    //重载*运算符
    T operator *() {
        if (_curr == nullptr) exit(0);
        return *_curr;
    }
    //重载->运算符
    Ptr operator ->() {
        return _curr;
    }
    bool operator !=(it& t) {
        return _curr != t._curr;
    }
    bool operator ==(it& t) {
        return _curr == t._curr;
    }
    //重载前置++运算符
    it& operator ++() {
        ++_curr;
        return *this;
    }
    //重载后置++运算符
    it& operator ++(int) {
        it& old = *this;
        ++_curr;
        return old;
    }
    //重载前置--运算符
    it& operator --() {
        --_curr;
        return *this;
    }
    //重载后置--运算符
    it& operator --(int) {
        it& old = *this;
        --_curr;
        return old;
    }
};

template<class T>
class Deque {
private:
    //将两数组拼接起来 模拟双端队列
    T* left, * right; //左部分数组与右部分数组
    int head, tail; //双端队列的头与尾
    int l_size, r_size; //左、右部分数组的长度
public:
    typedef Deque_Iterator<T, T*, T&> iterator;
    //初始化
    Deque() {
        l_size = r_size = 10;
        left = new T[l_size];
        right = new T[r_size];
        head = tail = 0;
    }
    //重新配置空间（增大左或右的空间）
    void reserve(T* _curr, int side) {
        T* t;
        int t_size;
        if (side == 1) t_size = r_size * 2;
        t = new T[t_size];
        if (side == 1) {
            for (int i = 0; i < r_size; i++)
                t[i] = right[i];
            delete[] right;
            right = t;
            r_size = t_size;
        }
        else {
            for (int i = 0; i < l_size; i++)
                t[i] = left[i];
            delete[] left;
            left = t;
            l_size = t_size;
        }
    }
    T back() {
        if (tail <= 0) return left[-tail];
        return right[tail - 1];
    }
    T front() {
        if (head <= 0) return right[-head];
        return left[head - 1];
    }
    void push_back(T e) {
        if (tail >= 0) {
            if (tail >= r_size) reserve(right, 1);
            right[tail++] = e;
        }
        else {
            left[(-tail) - 1] = e;
            tail++;
        }
    }
    void push_front(T e) {
        if (head >= 0) {
            if (head >= l_size) reserve(left, 0);
            left[head++] = e;
        }
        else {
            right[(-head) - 1] = e;
            head++;
        }
    }
    void pop_back() {
        tail--;
    }
    void pop_front() {
        head--;
    }
    iterator begin() {
        if (head > 0) return iterator(&left[head - 1]);
        else return iterator(&right[-head]);
    }
    iterator end() {
        if (tail > 0) return iterator(&right[tail - 1]);
        else return iterator(&left[-tail]);
    }
    void clear() {
        head = tail = 0;
    }
    bool empty() {
        return head + tail > 0;
    }
    int size() {
        return head + tail;
    }
    int max_size() {
        return l_size + r_size;
    }
};

#endif
