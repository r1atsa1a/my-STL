#include <iostream>
#include <utility>
#include <vector>
#include "myalgorithm.hpp"
#include "myvector.hpp"
#include "mylist.hpp"
#include "mydeque.hpp"
#include "mystack.hpp"
#include "myqueue.hpp"
#include "myset.hpp"
#include "mymap.hpp"

using namespace Algorithm;
using namespace std;

int main() {

    // /* 
    //  *
    //  *   @author : shympo 
    //  *
    //  */

    // cout << "=========vector=========" << endl;
    // myvector<int> a;
    // a.push_back(2);
    // myvector<int>::iterator ita = a.begin();
    // for (; ita != a.end(); ++ita)
    //     cout << *ita << ' ';
    // cout << endl;
    // a.assign(4, 3);
    // cout << a.size() << endl;
    // cout << a.capacity() << endl;
    // myvector<int> b(a);
    // a.pop_back();
    // cout << b.size() << endl;
    // a.clear();
    // b.remove(2);
    // cout << b.size() << endl;
    // cout << a.empty() << endl;
    // cout << "=========list=========" << endl;
    // mylist<int> l(1, 2);
    // l.push_back(1);
    // l.push_front(3);
    // l.push_back(2);
    // mylist<int> l1 = l;
    // l.pop_back();
    // l.pop_front();
    // l.pop_back();
    // l.pop_front();
    // cout << l.empty() << endl;
    // mylist<int>::iterator ita1 = l1.begin();
    // for (; ita1 != l1.end(); ++ita1)
    //     cout << *ita1 << ' ';
    // cout << endl;
    // l1.sort();
    // ita1 = l1.begin();
    // for (; ita1 != l1.end(); ++ita1)
    //     cout << *ita1 << ' ';
    // cout << endl;
    // cout << l.size() << endl;
    // l1.clear();
    // cout << l1.size() << endl;
    // cout << "=========queue=========" << endl;
    // myqueue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.pop();
    // cout << q.size() << endl;
    // cout << q.front() << endl;
    // cout << q.back() << endl;
    // cout << "=========stack=========" << endl;
    // mystack<int> s;
    // cout << s.empty() << endl;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.pop();
    // cout << s.top() << endl;
    // cout << s.size() << endl;

    // /* 
    //  *
    //  *   @author : Jie0355 
    //  *
    //  */

    // /* ==================== Algorithm ==================== */

    // cout << "========== Algorithm Test ==========" << '\n';

    // int ans = 0;
    // vector<int> v1(5, 1), v2(5);
    // vector<int>::iterator it_1;

    // cout << "容器内的全部元素：";
    // for (it_1 = v1.begin(); it_1 != v1.end(); ++it_1)
    //     cout << *it_1 << " \n"[it_1 == v1.end() - 1];

    // ans = accumulate(v1.begin(), v1.end(), ans);
    // cout << "区间内的数值之和：" << ans << '\n';

    // it_1 = partial_sum(v1.begin(), v1.end(), v2.begin(), &ans);
    // cout << "区间前缀和：";
    // for (it_1 = v2.begin(); it_1 != v2.end(); ++it_1)
    //     cout << *it_1 << " \n"[it_1 == v2.end() - 1];

    // it_1 = max_element(v2.begin(), v2.end());
    // cout << "区间内的最大值：" << *it_1 << '\n';

    // it_1 = min_element(v2.begin(), v2.end());
    // cout << "区间内的最小值：" << *it_1 << '\n';

    // ans = Algorithm::count(v1.begin(), v1.end(), 1);
    // cout << "区间内等于1的元素个数：" << ans << '\n';

    // it_1 = Algorithm::find(v2.begin(), v2.end(), 3);
    // cout << "区间内元素等于3的位置：" << it_1 - v2.begin() + 1 << '\n';

    // Algorithm::reverse(v2.begin(), v2.end());
    // cout << "逆序后容器内的全部元素：";
    // for (it_1 = v2.begin(); it_1 != v2.end(); ++it_1)
    //     cout << *it_1 << " \n"[it_1 == v2.end() - 1];

    // quick_sort(v2.begin(), v2.end());
    // cout << "排序（升序）后容器内的全部元素：";
    // for (it_1 = v2.begin(); it_1 != v2.end(); ++it_1)
    //     cout << *it_1 << " \n"[it_1 == v2.end() - 1];

    // /* ==================== Deque ==================== */

    // cout << "========== Deque Test ==========" << '\n';

    // Deque<int> idq;
    // Deque<int>::iterator it;

    // for (int i = 5; i >= 1; i--)
    //     idq.push_front(i);
    // for (int i = 6; i <= 10; i++)
    //     idq.push_back(i);

    // cout << "Deque容器中的全部元素：";
    // for (int i = 1; i <= 10; i++)
    //     cout << i << " \n"[i == 10];

    // cout << "Deque的队首元素：" << idq.front() << '\n';

    // it = idq.begin();
    // cout << "(迭代器版)Deque的队首元素：" << *it << '\n';

    // cout << "Deque的队尾元素：" << idq.back() << '\n';

    // it = idq.end();
    // cout << "(迭代器版)Deque的队尾元素：" << *it << '\n';

    // idq.pop_front();
    // cout << "弹出队首元素后，Deque的新队首元素：" << idq.front() << '\n';

    // idq.pop_back();
    // cout << "弹出队尾元素后，Deque的新队尾元素：" << idq.back() << '\n';

    // cout << "Deque是否为空？";
    // if (idq.empty())
    //     cout << "NO" << '\n';
    // else
    //     cout << "YES" << '\n';

    // cout << "Deque的实际大小：" << idq.size() << '\n';

    // cout << "Deque的存储大小：" << idq.max_size() << '\n';

    // for (int i = 10; i <= 20; i++)
    //     idq.push_back(i);
    // cout << "Deque存储大小不够使用时，扩充容量，扩充后的存储大小：";
    // cout << idq.max_size() << '\n';

    // idq.clear();
    // cout << "执行清空操作后，Deque是否为空？";
    // if (idq.empty())
    //     cout << "NO" << '\n';
    // else
    //     cout << "YES" << '\n';

    // /* 
    //  *
    //  *   @author : xianyu321 
    //  *
    //  */
    
    // cout << "====== multiset======" << endl;
    // mymultiset<int> ms;
    // if (ms.empty())
    // {
    //     cout << "empty" << endl;
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     ms.insert(i);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     ms.insert(i);
    // }
    // if (ms.find(1) != ms.end())
    // {
    //     cout << "YES" << endl;
    // }

    // cout << "大于等于3的第一个数";
    // cout << *(ms.upper_bound(3)) << endl;
    // cout << "大于3的第一个数";
    // cout << *(ms.lower_bound(3)) << endl;
    // ms.erease(ms.upper_bound(3), ms.lower_bound(7));

    // for (auto i = ms.begin(); i != ms.end(); ++i)
    // {
    //     cout << *i << ' ';
    // }
    // cout << endl;

    // cout << "======set======" << endl;
    // myset<int> s;
    // for (int i = 0; i < 10; i++)
    // {
    //     s.insert(i);
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     s.insert(i);
    // }
    // for (auto i = s.begin(); i != s.end(); ++i)
    // {
    //     cout << *i << ' ';
    // }
    // cout << endl;
    // s.erease(++s.begin(), s.end());
    // for (auto i = s.begin(); i != s.end(); ++i)
    // {
    //     cout << *i << ' ';
    // }

    // cout << "======multimap======" << endl;
    // mymultimap<int, int> mmp;
    // for (int i = 0; i < 5; i++)
    // {
    //     mmp.insert({i, i + 10});
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     mmp.insert({i, i + 20});
    // }

    // for (mymultimap<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
    // {
    //     cout << it->first << ' ' << it->second << endl;
    // }

    // cout << "查找大于3的第一个数";
    // cout << mmp.upper_bound(3)->first << ' ' << mmp.upper_bound(3)->second << endl;
    // cout << "查找大于等于2的第一个数";
    // cout << mmp.lower_bound(2)->first << ' ' << mmp.lower_bound(2)->second << endl;
    // cout << "查找1的位置" << endl;
    // cout << mmp.find(1)->first << ' ' << mmp.find(1)->second << endl;

    // cout << "清除第二个数开始的后面所有数" << endl;
    // mmp.erease(++mmp.begin(), mmp.end());
    // for (mymultimap<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
    // {
    //     cout << it->first << ' ' << it->second << endl;
    // }

    // cout << "======map======" << endl;
    // mymap<int, int> mp;
    // mp[1] = 10;
    // mp[2] = 20;
    // mp[3] = 30;
    // mp.insert(make_pair(1, 1));
    // for (mymap<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    // {
    //     cout << it->first << ' ' << it->second << endl;
    // }
    // cout << "把下标为2的节点的值置为0" << endl;
    // mp[2] = 0;
    // for (mymap<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    // {
    //     cout << it->first << ' ' << it->second << endl;
    // }

    // return 0;
}