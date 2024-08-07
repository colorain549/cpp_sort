# cpp_sort
## 模版
## 冒泡 排序
## 1冒泡排序(相邻两数)(升序)
1. 说明
* 内层循环: 比较相邻的两数, 若符合条件, 则交换元素
2. 时间复杂度
* 外层循环n次, 内层循环n-1次, 循环比较次数n*(n-1), 即O(n^2)
3. 补充
* 外层控制有多少轮
* 内层控制该轮元素的比较
* 空间复杂度O(1)
## 1冒泡排序(不相邻两数)(升序)
1. 说明
* 内层循环: 比较i和i+1后的每一个元素，若符合条件, 则交换元素
2. 时间复杂度
* 外层循环n次, 内层循环(n-1)+(n-2)+...+1次, 循环比较次数n*(n-1)/2, 即O(n^2)
## 2选择排序(升序)
1. 说明
* 内层循环: 比较i和i+1后的每一个元素，若符合条件, 则交换指针, 内循环完整遍历一轮后才交换元素
2. 时间复杂度
* 外层循环n次, 内层循环(n-1)+(n-2)+...+1次, 循环比较次数n*(n-1)/2, 即O(n^2)
3. 补充
* 外层控制有多少轮
* 内层控制该轮元素的比较
* 空间复杂度O(1)
## 3插入排序(升序)(适用于部分有序的场景)
1. 说明
* 序列只有一个数, 该序列有序
* 将第一个数看作有序序列, 然后将后面的数看作要插入的序列
* 内层循环:覆盖是往后覆盖的; 最后一步是j指向插入位置的前一个位置;
2. 时间复杂度
* 外层循环n-1次
* 内层循环随着序列的增长平均要比较(1+2+...(n-2))/2次
* 因此,时间复杂度为O(n-1)*((1+2+...(n-2))/2)，即O(n^2)
3. 补充
* 空间复杂度O(1)
## 4希尔排序(升序)(适用于6k以内)
1. 说明
* 插入排序的改进，增加一次循环
2. 时间复杂度
* O(n^1.3)
3. 使用
* 6000多以内时比快速排序和堆排序快
4. 补充
* 空间复杂度O(1)
## 5快速排序(注意:当数组长度为0或1时)(升序)
1. 说明
* 分治思想，设置基准值, 分为左边和右边，不断递归
2. 时间复杂度
* n=>n/2=>...=>1
* O(nlog2n)
3. 补充 
* 空间复杂度O(n)
## 6堆排序(升序)(适用于数据上亿时10million)
1. 说明
* 先用n个元素建立大顶堆
* 然后将堆顶元素与序列最后一个元素交换
* 接着用前面n-1个元素建立大顶堆
* 然后将堆顶元素与序列最后一个元素交换
* ...
* 接着用前面n-(n-1)个元素建立大顶堆
* 然后将堆顶元素与序列最后一个元素交换
* 最后序列为升序排序
2. 时间复杂度
* 建堆的时间复杂度O(n)
* 调整堆的时间复杂度O(logn), 每次调整都是沿着根节点到叶子节点的路径(即树的高度)进行的
* 最坏/平均时间复杂符(O(nlog2n))
3. 补充
* 空间复杂度O(1)
## 7归并排序(注意:当数组长度为0或1时)(升序)
1. 说明
* 先拆分再合并
2. 时间复杂度
* 平均时间复杂符(O(nlog2n))
3. 补充
* 空间复杂度O(n)
## 8计数排序(升序)
1. 说明
* 先遍历一次整个数组, 统计每个元素出现的次数, 用一个新的数组保存
* 将出现过的元素, 覆盖原来的数组
2. 时间复杂度
* 平均时间复杂符(O(n+m))
* n为元素个数
* m为元素的最大值, 即代码中的index
3. 补充
* 空间复杂度(O(n))
## 9第k大元素(可重复)
## 10第k大元素(可重复但内存不足k)
## 11第k大元素(不重复)
## 12冒泡排序(相邻两数)(降序)
## 12冒泡排序(不相邻两数)(降序)
## 13选择排序(降序)
## 14插入排序(降序)
## 15希尔排序(降序)
## 16快速排序(注意:当数组长度为0或1时)(降序)
## 17堆排序(降序)
## 18归并排序(注意:当数组长度为0或1时)(降序)
## 19计数排序(降序)