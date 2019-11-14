/* inline优化测试
结果：影响不大，有时inline还会慢一些（不论函数中是否有循环） */
#include <cstdio>
#include <ctime>
const int VSZ = 1e7, ESZ = VSZ*2;

int head[VSZ];
struct Edge {
    int to, weight, next;
} edge[ESZ];

inline void addEdge(int x, int y, int z) {
    static int tot;
    edge[++tot].to = y, edge[tot].weight = z;
    edge[tot].next = head[x], head[x] = tot;
}

int main() {
    int st = clock();
    for (register int i = 1; i < VSZ; i++)
        addEdge(i, i + 1, 1);
    int ed = clock();
    printf("%dms", ed - st);
    return 0;
}

/* none: 95ms | inline: 93ms */