#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <cstring>

namespace Algorithm {
    //���������ڵ���ֵ֮��
    template<class Iterator, class T>
    T accumulate(Iterator _first, Iterator _last, T init) {
        for (; _first != _last; ++_first)
            init += *_first;
        return init;
    }
    //����ǰ׺�� �������ڵ�ǰ׺�͸����������
    template<class Iterator, class T>
    Iterator partial_sum(Iterator _first, Iterator _last, Iterator _result, T*) {
        if (_first == _last) return _result;
        *_result = *_first;
        T value = *_first;
        while (++_first != _last) {
            value += *_first;
            *(++_result) = value;
        }
        return _result;
    }
    /* ============================ max & min ============================ */
    template<class T>
    T& max(T& a, T& b) {
        return a > b ? a : b;
    }
    template<class T, class Cmp>
    T& max(T& a, T& b) {
        return Cmp(a, b) ? a : b;
    }
    template<class T>
    T& min(T& a, T& b) {
        return a < b ? a : b;
    }
    template<class T, class Cmp>
    T& min(T& a, T& b) {
        return !Cmp(a, b) ? a : b;
    }
    //�������ڵ����ֵ
    template<class Iterator>
    Iterator max_element(Iterator _first, Iterator _last) {
        if (_first == _last) return _first;
        Iterator _result = _first;
        for (; _first != _last; ++_first)
            if (*_first > *_result) _result = _first;
        return _result;
    }
    //�������ڵ���Сֵ
    template<class Iterator>
    Iterator min_element(Iterator _first, Iterator _last) {
        if (_first == _last) return _first;
        Iterator _result = _first;
        for (; _first != _last; ++_first)
            if (*_first < *_result) _result = _first;
        return _result;
    }
    /* ============================ swap ============================ */
    template<class T>
    void swap(T& a, T& b) {
        T t = a;
        a = b;
        b = t;
    }
    template<class Iterator, class T>
    void iter_swap(Iterator it_l, Iterator it_r, T*) {
        T t = *it_l;
        *it_l = *it_r;
        *it_r = t;
    }
    /* ============================ copy ============================ */
    //�����俽�����������
    template<class Iterator>
    Iterator copy(Iterator _first, Iterator _last, Iterator _result) {
        return _copy(_first, _last, _result);
    }
    template<class Iterator>
    Iterator _copy(Iterator _first, Iterator _last, Iterator _result) {
        for (; _first != _last; ++_result, ++_first)
            *_result = *_first;
        return _result;
    }
    template<class Iterator, class Distance>
    Iterator _copy(Iterator _first, Iterator _last, Iterator _result, Distance*) {
        for (Distance n = _last - _first; n > 0; --n, ++_result, ++_first)
            *_result = *_first;
        return _result;
    }
    /* ============================ count ============================ */
    //�ۼ�������ĳһԪ�صĸ���
    template<class Iterator, class T>
    int count(Iterator _first, Iterator _last, T value) {
        int n = 0;
        for (; _first != _last; ++_first)
            if (*_first == value) ++n;
        return n;
    }
    //�ۼ�������ĳһ����ָ��Ҫ���Ԫ�ظ���
    template<class Iterator, class Predicate>
    int count_if(Iterator _first, Iterator _last, Predicate is) {
        int n = 0;
        for (; _first != _last; ++_first)
            if (is(*_first)) ++n;
        return n;
    }
    /* ============================ find ============================ */
    //���������ڵ�һ������ָ��ָ��λ��
    template<class Iterator, class T>
    Iterator find(Iterator _first, Iterator _last, T value) {
        for (; _first != _last; ++_first)
            if (*_first == value) return _first;
        return _last;
    }
    //���������ڵ�һ������ָ��Ҫ���Ԫ��λ��
    template<class Iterator, class Predicate>
    Iterator find_if(Iterator _first, Iterator _last, Predicate is) {
        for (; _first != _last; ++_first)
            if (is(*_first)) return _first;
        return _last;
    }
    /* ============================ replace ============================ */
    //�滻������ĳһԪ��Ϊָ��Ԫ��
    template<class Iterator, class T>
    void repalce(Iterator _first, Iterator _last, T old_value, T new_value) {
        for (; _first != _last; ++_first) {
            if (*_first == old_value) *_first == new_value;
        }
    }
    //��������ĳһԪ���滻Ϊָ��Ԫ�غ����������
    template<class Iterator, class T>
    void repalce_copy(Iterator _first, Iterator _last, Iterator _result, T old_value, T new_value) {
        for (; _first != _last; ++_first, ++_result) {
            if (*_first == old_value) *_result == new_value;
            else *_result == *_first;
        }
    }
    //�滻������ĳһ����������Ԫ��Ϊָ��Ԫ��
    template<class Iterator, class Predicate, class T>
    void repalce_if(Iterator _first, Iterator _last, Predicate is, T new_value) {
        for (; _first != _last; ++_first) {
            if (is(*_first)) *_first == new_value;
        }
    }
    //���滻������ĳһ����������Ԫ��Ϊָ��Ԫ�غ����������
    template<class Iterator, class Predicate, class T>
    void repalce_if_copy(Iterator _first, Iterator _last, Iterator _result, Predicate is, T new_value) {
        for (; _first != _last; ++_first, ++_result) {
            if (is(*_first)) *_result == new_value;
            else *_result == *_first;
        }
    }
    /* ============================ reverse ============================ */
    //��ָ����������
    template<class Iterator>
    void reverse(Iterator _first, Iterator _last) {
        for (;;) {
            if (_first == _last || _first == --_last) return;
            else iter_swap(_first++, _last);
        }
    }
    /*
    template<class Iterator>
    void _reverse(Iterator _first, Iterator _last) {
        while (_first < _last) swap(_first ++, -- _last);
    }
    */
    //��ָ��������������������
    template<class Iterator>
    Iterator reverse_copy(Iterator _first, Iterator _last, Iterator _result) {
        while (_first != _last) {
            --_last;
            *_result = *_last;
            ++_result;
        }
        return _result;
    }
    /* ============================ fill ============================ */
    //���������Ԫ��Ϊָ��Ԫ��
    template<class Iterator, class Size, class T>
    Iterator fill_n(Iterator _first, Size n, T value) {
        for (; n > 0; --n, ++_first)
            *_first = value;
        return _first;
    }
    //ƫ�ػ��汾
    template<class Size>
    char* fill_n(char* _first, Size n, char value) {
        memset(_first, value, n * sizeof(char));
        return _first + n;
    }
    template<class Size>
    wchar_t* fill_n(wchar_t* _first, Size n, wchar_t value) {
        memset(_first, value, n * sizeof(wchar_t));
        return _first + n;
    }
    /* ============================ sort ============================ */
    //��������
    template<class Iterator>
    void quick_sort(Iterator _first, Iterator _last) {
        if (_first == _last) return;
        auto x = _first + (_last - _first) / 2;
        auto val = *x;
        auto i = _first, j = _last - 1;
        while (i < j) {
            while (i < j && *i < val) {
                ++i;
            }
            while (i < j && *j > val) {
                --j;
            }
            if (i < j) iter_swap(i, j);
        }
        quick_sort(_first, j);
        quick_sort(j + 1, _last);
    }
    //ѡ������
    template<class Iterator, class Predicate>
    void selection_sort(Iterator _first, Iterator _last, Predicate is) {
        if (_first == _last) return;
        for (; _first != _last; ++_first) {
            Iterator minVal = _first;
            Iterator curr = _first;
            for (; curr != _last; ++curr)
                if (is(*curr, *minVal)) minVal = curr;
            if (minVal != _first) swap(*minVal, *_first);
        }
    }
    //ð������
    template<class Iterator, class Predicate>
    void bubble_sort(Iterator _first, Iterator _last, Predicate is) {
        if (_first == _last) return;
        while (_first != _last) {
            Iterator curr = _first;
            Iterator next = _first;
            for (; next != _last; ++next) {
                if (is(*next, *curr)) swap(*next, *curr);
                curr = next;
            }
            _last = curr;
        }
    }
    //��������
    template<class Iterator, class Predicate>
    void insertion_sort(Iterator _first, Iterator _last, Predicate is) {
        if (_first == _last) return;
        Iterator it = _first;
        for (; it != _last; ++it) {
            auto value = *it;
            Iterator curr = it;
            Iterator prev = curr;
            --prev;
            for (; curr != _first && is(*prev, value); --curr, --prev)
                *curr = *prev;
            *curr = value;
        }
    }
}

#endif