## 后缀树

### 1 可以解决的问题

- 精确匹配
- LCS（最长公共子序列）
- LRS（最长重复字串）
- LCP（最长公共字串）
- 回文

### 2 算法

![2.jpg](./images/suffix_tree/2.jpg)

![1.jpg](./images/suffix_tree/1.jpg)

#### 2.1 解决一个小bug

在字符串末尾加一个 `$`

#### 2.2 构建方法

##### 2.2.1 一般算法

时间复杂度 $O(m^2)$

![3.jpg](./images/suffix_tree/3.jpg)

![4.jpg](./images/suffix_tree/4.jpg)

##### 2.2.2 Ukk算法

时间复杂度 $O(m)$

> 隐后缀树：去除 `$`，去除 `空边`，去除 `孩子数量为1的内部节点`

![5.jpg](./images/suffix_tree/5.jpg)

![6.jpg](./images/suffix_tree/6.jpg)

上图为优化前算法，复杂度 $O(m^3)$，两层循环，外加一个 `匹配`

![7.jpg](./images/suffix_tree/7.jpg)

> 后缀链

![8.jpg](./images/suffix_tree/8.jpg)

利用 `跳过/计数` 策略，加速到 $O(m^2)$

![9.jpg](./images/suffix_tree/9.jpg)

“终结者"加速：

![10.jpg](./images/suffix_tree/10.jpg)

![11.jpg](./images/suffix_tree/11.jpg)
