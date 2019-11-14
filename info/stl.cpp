/* STL性能测试 - 线性容器：vector、queue、deque、stack
结果：不开O2的话，STL非常慢，能不用就不用 */
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
using namespace std;
const int SZ = 1e8;

int st, ed, tmp;
int arr[SZ];
vector<int> vec;
queue<int> q;
deque<int> dq;
stack<int> s;

int main()
{
    // array
    printf("array\n");
    st = clock();
    for (register int i = 0; i < SZ; i++)
        arr[i] = i;
    ed = clock();
    printf("write: %dms\n", ed - st);

    st = clock();
    for (register int i = 0; i < SZ; i++)
        tmp = arr[i];
    ed = clock();
    printf("read: %dms\n\n", ed - st);
    
    // vector
    printf("vector\n");
    st = clock();
    for (register int i = 1; i <= SZ; i++)
        vec.push_back(i);
    ed = clock();
    printf("write: %dms\n", ed - st);

    st = clock();
    for (register int i = 1; i <= SZ; i++)
        tmp = vec[i];
    ed = clock();
    printf("read: %dms\n\n", ed - st);

    // queue
    printf("queue\n");
    st = clock();
    for (register int i = 1; i <= SZ; i++)
        q.push(i);
    ed = clock();
    printf("write: %dms\n", ed - st);

    st = clock();
    for (register int i = 1; i <= SZ; i++) {
        tmp = q.front();
        q.pop();
    }
    ed = clock();
    printf("read: %dms\n\n", ed - st);

    // deque
    printf("deque\n");
    st = clock();
    for (register int i = 1; i <= SZ; i++)
        dq.push_front(i);
    ed = clock();
    printf("write-front: %dms\n", ed - st);

    st = clock();
    for (register int i = 1; i <= SZ; i++)
        dq.push_back(i);
    ed = clock();
    printf("write-back: %dms\n", ed - st);

    st = clock();
    for (register int i = 1; i <= SZ*2; i+=2)
        tmp = dq[i];
    ed = clock();
    printf("read: %dms\n\n", ed - st);

    // stack
    printf("stack\n");
    st = clock();
    for (register int i = 1; i <= SZ; i++)
        s.push(i);
    ed = clock();
    printf("write: %dms\n", ed - st);

    st = clock();
    for (register int i = 1; i <= SZ; i++) {
        tmp = s.top();
        s.pop();
    }
    ed = clock();
    printf("read: %dms\n", ed - st);

    return 0;
}

/* 括号里为开O2后的结果
array
write: 188ms(160ms)
read: 67ms(35ms)

vector
write: 1014ms(452ms)
read: 156ms(55ms)

queue
write: 896ms(306ms)
read: 1329ms(192ms)

deque
write-front: 697ms(298ms)
write-back: 685ms(302ms)
read: 5253ms(179ms)

stack
write: 808ms(299ms)
read: 1501ms(259ms)
*/