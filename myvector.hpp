#pragma once
 #include <iostream>
 using namespace std;
template <typename T>
class myvector
{
public:
    typedef T *iterator;

    // 构造一个大小为max（s,16)的动态数组
    myvector(int s = 0)
    {
        if (s < 0)
        {
            cout << "error" << endl;
            exit(-1);
        }
        v_size = s < 16 ? 16 : s;
        data = new T[v_size];
        pos = 0;
    }

    myvector(int s, T d)
    {
        if (s < 0)
        {
            cout << "error" << endl;
            exit(-1);
        }
        v_size = s < 16 ? 16 : s;
        data = new T[v_size];
        for (int i = 0; i < s; ++i)
        {
            data[i] = d;
        }
        pos = s;
    }

    myvector(myvector<T> &v)
    {
        v_size = v.v_size;
        data = new T[v_size];
        pos = v.pos;
        for (int i = 0; i < pos; ++i)
        {
            data[i] = v.data[i];
        }
    }

    myvector(iterator beg, iterator end)
    {
        v_size = end - beg;
        data = new T[v_size];
        pos = v_size;
        for (int i = 0; i < pos; ++i)
        {
            data[i] = *(beg + i);
        }
    }

    ~myvector()
    {
        if (data != NULL)
        {
            delete[] data;
            data = NULL;
        }
    }

    void assign(iterator beg, iterator end)
    {
        v_size = end - beg;
        data = new T[v_size];
        pos = v_size;
        for (int i = 0; i < pos; ++i)
        {
            data[i] = *(beg + i);
        }
    }

    void assign(int s, T d)
    {
        if (s <= 0)
        {
            cout << "error" << endl;
            exit(-1);
        }
        v_size = s < 16 ? 16 : s;
        data = new T[v_size];
        for (int i = 0; i < s; ++i)
        {
            data[i] = d;
        }
        pos = s;
    }

    T back()
    {
        return data[0];
    }

    T froat()
    {
        if (pos == 0)
        {
            return data[0];
        }
        return data[pos - 1];
    }

    T &operator[](int index)
    {
        if (index >= 0 || index < pos)
            return data[index];
        cout << "find error" << endl;
        return data[0];
    }

    T at(int index)
    {
        if (index >= 0 || index < pos)
            return data[index];
        cout << "find error" << endl;
        return data[0];
    }

    // 判断容器是否为空
    bool empty()
    {
        return pos == 0;
    }

    // 返回容器大小
    int size()
    {
        return pos;
    }

    int capacity()
    {
        return v_size;
    }

    // 清空容器
    void clear()
    {
        delete[] data;
        data = new T[v_size];
        pos = 0;
    }

    // 在数组下标为index的地方插入d
    void insert(int index, T d)
    {
        if (index < 0 || index >= pos)
        {
            cout << "finderror" << endl;
            return;
        }

        if (pos == v_size)
        {
            int newsize = v_size * 2;
            T *newdata = new T[newsize];
            for (int i = 0; i < v_size; i++)
            {
                newdata[i] = data[i];
            }
            data = newdata;
            v_size = newsize;
        }
        for (int i = pos - 1; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = d;
        pos++;
    }

    // 删除下标为index的数
    void remove(int index)
    {
        if (index < 0 || index >= pos)
        {
            cout << "finderror" << endl;
            return;
        }
        erease(data + index - 1, data + index);
    }

    void erease(iterator beg, iterator end)
    {
        int k = end - beg;
        int d = this->end() - end;
        // cout << k << d;

        if (d < 0)
        {
            k = this->end() - beg;
        }

        if (k == 0)
        {
            return;
        }

        for (iterator i = beg; i + k != this->end(); ++i)
        {
            *i = *(i + k);
        }
        pos -= k;
    }

    // 在数组尾部插入元素
    void push_back(T d)
    {
        if (pos == v_size)
        {
            int newsize = v_size * 2;
            T *newdata = new T[newsize];
            for (int i = 0; i < v_size; i++)
            {
                newdata[i] = data[i];
            }
            data = newdata;
            v_size = newsize;
        }
        data[pos++] = d;
    }

    // 删除尾部元素
    void pop_back()
    {
        if (pos <= 0)
        {
            cout << "Empty" << endl;
            return;
        }
        pos--;
    }

    // 返回头指针
    iterator begin()
    {
        return data;
    }

    // 返回尾指针
    iterator end()
    {
        return data + pos;
    }

protected:
    // 数组指针
    iterator data;
    // 数组存储元素的个数
    int pos;
    // 数组的大小
    int v_size;
};
//test

// int main()
// {
//     myvector<int> a;
//     a.push_back(2);
//     myvector<int>::iterator ita = a.begin();
//     for (; ita != a.end(); ++ita)
//     {
//         cout << *ita << ' '; 
//     }
//     cout << endl;
//     a.assign(4, 3);
//     cout << a.size() << endl;
//     cout << a.capacity() << endl;
//     myvector<int> b(a);
//     a.pop_back();
//     cout << b.size() << endl;
//     a.clear();
//     b.remove(2);
//     cout << b.size() << endl;
//     cout << a.empty() << endl;
    

//     return 0;
// }