#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <ctime>

using namespace std;

int st, ed, temp;

int main()
{
    int * arr = new int[10000000];
    cout << "array: " << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        arr[i] = i;
    ed = clock();
    cout << "write: " << ed - st << "ms" << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        temp = arr[i];
    ed = clock();
    cout << "read: " << ed - st << "ms" << endl;
    delete(arr);
    cout << endl;
    
    vector <int> v;
    cout << "vector: " << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        v.push_back(i);
    ed = clock();
    cout << "write: " << ed - st << "ms" << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        temp = v[i];
    ed = clock();
    cout << "read: " << ed - st << "ms" << endl;
    while(v.size())
        v.erase(v.end() - 1);
    cout << endl;

    queue <int> q;
    cout << "queue: " << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        q.push(i);
    ed = clock();
    cout << "write: " << ed - st << "ms" << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
    {
        temp = q.front();
        q.pop();
    }
    ed = clock();
    cout << "read: " << ed - st << "ms" << endl;
    cout << endl;

    deque <int> dq;
    cout << "deque: " << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        dq.push_front(i);
    ed = clock();
    cout << "write-front: " << ed - st << "ms " << endl;
    dq.clear();
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        dq.push_back(i);
    ed = clock();
    cout << "write-back: " << ed - st << "ms" << endl;
    st = clock();
    for (int i = 1; i <= 10000000; i++)
        temp = dq[i];
    ed = clock();
    cout << "read: " << ed - st << "ms" << endl;
    dq.clear();

    return 0;
}

/* 测试结果：

不开O2：
array:
write: 34ms
read: 19ms

vector:
write: 98ms
read: 32ms

queue:
write: 84ms
read: 120ms

deque:
write-front: 76ms
write-back: 77ms
read: 538ms


开启O2：
array:
write: 18ms
read: 6ms

vector:
write: 60ms
read: 4ms

queue:
write: 39ms
read: 22ms

deque:
write-front: 33ms
write-back: 35ms
read: 17ms */