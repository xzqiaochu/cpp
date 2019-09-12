## 基数排序

> 是对 `桶排序` 的优化，桶排序不具备 `稳定性`

#### 类桶排序

![2.jpg](./images/sort_base/2.jpg)

#### 对于数字的排序

![1.jpg](./images/sort_base/1.jpg)

依次从 `底位到高位` 进行排序

#### 基数排序

![3.jpg](./images/sort_base/3.jpg)

![4.jpg](./images/sort_base/4.jpg)

#### Code

![5.jpg](./images/sort_base/5.jpg)

#### 时间复杂度及适用范围

时间复杂度 $O(N)$
当 $N >> M$ 时，$M$ 为数据范围
