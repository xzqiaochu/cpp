# Some Errors & Warnings

## Errors

### 1. 无向图边数

无向图边数要开到两倍

- 例如：$n$ 个城市间共有 $m$ 条道路，则有 $2*m$ 条边

### 2. 修改dfs名称

修改dfs名称时，一定要把递归调用的名称也修改掉

### 3. 链式前行星添加无向边时

`addEdge(x, y)`
`addEdge(y, x)`
不要写重了或者漏写

## Warnings

### 1. next数组

库文件里有同名 `next` 变量，导致主程序声明 `next` 变量报错

有以下三种解决方法：

- 写在结构体里面
- `#define next Next`
- 不用 `using namespace std`，用什么using::什么
