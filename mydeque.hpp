#ifndef _DEQUE_HPP_
#define _DEQUE_HPP_

//������
template<class T, class Ref, class Ptr>
class Deque_Iterator {
public:
    typedef Deque_Iterator<T, Ref, Ptr> it;
    T* _curr;
    Deque_Iterator(T* __curr = nullptr) : _curr(__curr) {}
    //����*�����
    T operator *() {
        if (_curr == nullptr) exit(0);
        return *_curr;
    }
    //����->�����
    Ptr operator ->() {
        return _curr;
    }
    bool operator !=(it& t) {
        return _curr != t._curr;
    }
    bool operator ==(it& t) {
        return _curr == t._curr;
    }
    //����ǰ��++�����
    it& operator ++() {
        ++_curr;
        return *this;
    }
    //���غ���++�����
    it& operator ++(int) {
        it& old = *this;
        ++_curr;
        return old;
    }
    //����ǰ��--�����
    it& operator --() {
        --_curr;
        return *this;
    }
    //���غ���--�����
    it& operator --(int) {
        it& old = *this;
        --_curr;
        return old;
    }
};

template<class T>
class Deque {
private:
    //��������ƴ������ ģ��˫�˶���
    T* left, * right; //�󲿷��������Ҳ�������
    int head, tail; //˫�˶��е�ͷ��β
    int l_size, r_size; //���Ҳ�������ĳ���
public:
    typedef Deque_Iterator<T, T*, T&> iterator;
    //��ʼ��
    Deque() {
        l_size = r_size = 10;
        left = new T[l_size];
        right = new T[r_size];
        head = tail = 0;
    }
    //�������ÿռ䣨��������ҵĿռ䣩
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
