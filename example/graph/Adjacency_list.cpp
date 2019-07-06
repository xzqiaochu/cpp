/* 链式前向星（邻接表）
出处：算法竞赛-基本数据结构-链表与邻接表 0x13 P61
最后修改时间：2019-06-08 */
#include <cstdio>

const int MAXN = 100; //n个节点的图，最多有n * (n - 1)条边

int tot = 1, head[MAXN], ver[MAXN], edge[MAXN], next[MAXN];
//tot边号，head[起点] = 边号，edge[边号] = 边权值，ver[边号] = 终点，next[当前边号] = 下一边号

//加入有向边(x, y), 权值为z
void add(int x, int y, int z)
{
    ver[++tot] = y, edge[tot] = z; //真实数据
    next[tot] = head[x], head[x] = tot; //在表头x处插入
}

int main()
{
    add(1, 2, 1);
    add(1, 3, 2);
    add(3, 4, 3);
    add(3, 5, 4);
    int x = 1;
    //访问从x出发的所有边
    for (int i = head[x]; i; i = next[i])
    {
        int y = ver[i], z = edge[i];
        //找到了一条向边(x, y), 权值为z
        printf("%d %d\n", y, z);
    }
    return 0;
}