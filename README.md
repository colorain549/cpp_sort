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
```
// 冒泡排序(相邻两数)
void bubbleSort(vector<int> &ivec)
{
    // 循环 n次
    for (int i = 0; i < ivec.size(); i++)
    {
        // 比较 n-1次
        for (int j = 0; j < ivec.size() - 1; j++)
        {
            if (ivec[j] > ivec[j + 1])
            {
                swap(ivec[j], ivec[j + 1]);
            }
        }
    }
}
```
## 1冒泡排序(不相邻两数)(升序)
1. 说明
* 内层循环: 比较i和i+1后的每一个元素，若符合条件, 则交换元素
2. 时间复杂度
* 外层循环n次, 内层循环(n-1)+(n-2)+...+1次, 循环比较次数n*(n-1)/2, 即O(n^2)
```
void bubbleSort(vector<int> &ivec)
{
    // 循环 n次
    for (int i = 0; i < ivec.size(); i++)
    {
        // 比较(n-1)+(n-2)+...+1次
        for (int j = i + 1; j < ivec.size(); j++)
        {
            if (ivec[i] > ivec[j])
            {
                swap(ivec[i], ivec[j]);
            }
        }
    }
}
```
## 2选择排序(升序)
1. 说明
* 内层循环: 比较i和i+1后的每一个元素，若符合条件, 则交换指针, 内循环完整遍历一轮后才交换元素
2. 时间复杂度
* 外层循环n次, 内层循环(n-1)+(n-2)+...+1次, 循环比较次数n*(n-1)/2, 即O(n^2)
3. 补充
* 外层控制有多少轮
* 内层控制该轮元素的比较
* 空间复杂度O(1)
```
void selectSort(vector<int> &ivec)
{
    // 循环 n次
    for (int i = 0; i < ivec.size(); i++)
    {
        int index = i;
        // 比较(n-1)+(n-2)+...+1次
        for (int j = i + 1; j < ivec.size(); j++)
        {
            if (ivec[index] > ivec[j])
            {
                index = j;
            }
        }
        swap(ivec[i], ivec[index]);
    }
}
```
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
```
void insertSort(vector<int> &ivec)
{
    // 循环 n-1次
    for (int i = 1; i < ivec.size(); i++)
    {
        int j;
        int insertVal = ivec[i];
        for (j = i - 1; j >= 0 && ivec[j] > insertVal; j--)
        {
            ivec[j + 1] = ivec[j];
        }
        ivec[j+1] = insertVal;
    }
}
```
## 4希尔排序(升序)(适用于6k以内)
1. 说明
* 插入排序的改进，增加一次循环
2. 时间复杂度
* O(n^1.3)
3. 使用
* 6000多以内时比快速排序和堆排序快
4. 补充
* 空间复杂度O(1)
```
void shellsSort(vector<int> &ivec)
{
    for (int gap = ivec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < ivec.size(); i+=gap)
        {
            int j;
            int insertVal = ivec[i];
            for (j = i - gap; j >= 0 && ivec[j] > insertVal; j-=gap)
            {
                ivec[j + gap] = ivec[j];
            }
            ivec[j + gap] = insertVal;
        }
    }
}
```
## 5快速排序(注意:当数组长度为0或1时)(升序)
1. 说明
* 分治思想，设置基准值, 分为左边和右边，不断递归
2. 时间复杂度
* n=>n/2=>...=>1
* O(nlog2n)
3. 补充 
* 空间复杂度O(n)
```
vector<int> quickSort(vector<int> &ivec)
{
    if (ivec.size() <= 1)
    {
        return ivec;
    }
    int pivot = ivec[0];
    vector<int> less;
    vector<int> greater;
    for (int i = 1; i < ivec.size(); i++)
    {
        if (ivec[i] <= pivot)
        {
            less.push_back(ivec[i]);
        }
        else
        {
            greater.push_back(ivec[i]);
        }
    }
    auto sorted_less = quickSort(less);
    auto sorted_greater = quickSort(greater);
    sorted_less.push_back(pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    return sorted_less;
}
```
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
```
// 大顶堆
void adjustMaxHeap(vector<int> &ivec, int adjustPos, int arrLen)
{
    int dad = adjustPos;
    int son = 2 * dad + 1;
    while (son < arrLen)
    {
        if (son + 1 < arrLen && ivec[son + 1] > ivec[son])
        {
            son++;
        }
        if (ivec[dad] < ivec[son])
        {
            swap(ivec[dad], ivec[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            break;
        }
    }
}
// 堆排序
void heapSort(vector<int> &ivec)
{
    for (int i = ivec.size() / 2 - 1; i >= 0; i--)
    {
        adjustMaxHeap(ivec, i, LEN);
    }
    swap(ivec[0], ivec[LEN - 1]);
    for (int i = ivec.size() - 1; i > 0; i--)
    {
        adjustMaxHeap(ivec, 0, i);
        swap(ivec[0], ivec[i - 1]);
    }
}
```
## 7归并排序(注意:当数组长度为0或1时)(升序)
1. 说明
* 先拆分再合并
2. 时间复杂度
* 平均时间复杂符(O(nlog2n))
3. 补充
* 空间复杂度O(n)
```
vector<int> merge(vector<int> &left, vector<int> &right)
{
    vector<int> result;
    int leftIndex = 0;
    int rightIndex = 0;
    while (leftIndex < left.size() && rightIndex < right.size())
    {
        if (left[leftIndex] <= right[rightIndex])
        {
            result.push_back(left[leftIndex]);
            leftIndex++;
        }
        else
        {
            result.push_back(right[rightIndex]);
            // 注意这里
            rightIndex++;
        }
    }
    result.insert(result.end(), left.begin() + leftIndex, left.end());
    result.insert(result.end(), right.begin() + rightIndex, right.end());
    return result;
}
vector<int> mergeSort(vector<int> &ivec)
{
    if (ivec.size() <= 1)
    {
        return ivec;
    }
    int mid = ivec.size() / 2;
    vector<int> left(ivec.begin(), ivec.begin() + mid);
    vector<int> right(ivec.begin() + mid, ivec.end());
    auto sortedLeft = mergeSort(left);
    auto sortedRight = mergeSort(right);
    auto result = merge(sortedLeft, sortedRight);
    return result;
}
```
## 8计数排序(升序)(要求元素不重复)(需给定范围)
1. 说明
* 先遍历一次整个数组, 统计每个元素出现的次数, 用一个新的数组保存
* 将出现过的元素, 覆盖原来的数组
2. 时间复杂度
* 平均时间复杂符(O(n+m))
* n为元素个数
* m为元素的最大值, 即代码中的index
3. 补充
* 空间复杂度(O(n))
4. 实现
* 统计频率
* 外层循环，实现升序或降序
* 内层循环，填充到某数组，获得结果 
```
void countSort(vector<int> &ivec)
{
    // 初始数组下标是0到9(只能输入0到9的元素)
    int index = 10;
    vector<int> count(index);
    // count[]统计元素频率
    for (int i = 0; i < ivec.size(); i++)
    {
        count[ivec[i]]++;
    }
    // 结果数组下标
    int newIndex = 0;
    // !!!0-9 为升序!!!
    for (int i = 0; i < index; i++)
    {
        // 遇到频率大于0的元素
        for (int j = 0; j < count[i]; j++)
        {
            // 就填充到结果数组
            ivec[newIndex] = i;
            newIndex++;
        }
    }
}
```
## 🌟9第k大元素(可重复)(9_kthMaxValue.cc)(堆排序)
```
void heapSort(vector<int> &ivec, int k)
{
    for (int i = k / 2 - 1; i >= 0; i--)
    {
        adjustMinHeap(ivec, i, k);
    }
}

// 第k大元素
int kth;
cin >> kth;
// 堆排序
heapSort(ivec, kth);
// 若第kth号后的元素大于根元素
// 交换并重新堆排序
for (int i = kth; i < ivec.size(); i++)
{
    if (ivec[i] > ivec[0])
    {
        swap(ivec[i], ivec[0]);
        heapSort(ivec, kth);
    }
}
```
## 🌟9第k大元素(可重复)(9_kthMaxValuePque.cc)
```
int pqueSort(vector<int>&ivec, int k){
    priority<int, vector<int>, std::greater<int>> pque;
    for(int i=0; i<ivec.size(); i++){
        pque.push(ivec[i]);
        if(pque.size() > k){
            pque.pop();
        }
    }
    return pque.top();
}
```
## 🌟10第k大元素(可重复但内存不足k)
```
// (n = 8)
// (k = 5)
// (n-k+1 = 4)
// (4 < 5)
// 输入: [2 6 2 1 3 8 9 8][5]
// 输出: [3]

// 大顶堆
void adjustMaxHeap(vector<int> &ivec, int adjustPos, int arrLen)
{
    int dad = adjustPos;
    int son = 2 * dad + 1;
    while (son < arrLen)
    {
        if (son + 1 < arrLen && ivec[son + 1] > ivec[son])
        {
            son++;
        }
        if (ivec[dad] < ivec[son])
        {
            swap(ivec[dad], ivec[son]);
            dad = son;
            son = 2 * dad + 1;
        }
        else
        {
            break;
        }
    }
}

// 堆排序
void heapSort(vector<int> &ivec, int k)
{
    for (int i = k / 2 - 1; i >= 0; i--)
    {
        adjustMaxHeap(ivec, i, k);
    }
    // swap(ivec[0], ivec[LEN - 1]);
    // for (int i = ivec.size() - 1; i > 0; i--)
    // {
    //     adjustMaxHeap(ivec, 0, i);
    //     swap(ivec[0], ivec[i - 1]);
    // }
}

int main()
{
    // 构建数组
    vector<int> ivec;
    int item;
    for (int i = 0; i < LEN; i++)
    {
        cin >> item;
        ivec.push_back(item);
    }
    // 第kth大元素
    int kth;
    cin >> kth;
    // n-k+1个元素建小顶堆并排序
    heapSort(ivec, LEN - kth + 1);
    // 若n-k+1号后的元素比根元素小
    // 交换元素并重新堆排序
    for (int i = LEN - kth + 1; i < ivec.size(); i++)
    {
        if (ivec[i] < ivec[0])
        {
            swap(ivec[i], ivec[0]);
            heapSort(ivec, LEN - kth + 1);
        }
    }
    // 打印
    // printVec(ivec);
    cout << ivec[0] << endl;
}
```
## 🌟11第k大元素(不重复)(set)(11_kthMaxValueSet.cc)
1. 第k大元素相当于 第len-k+1大元素
```
set<int> iset(ivec.begin(), ivec.end());
auto it = iset.begin();
for (int i = 1; i < iset.size() - k + 1; ++i)
{
    ++it;
}
cout << *it << endl;
```
## 11第k大元素(不重复)(array 或 vector)(不推荐, 基于计数排序, 需给定范围)
## 12冒泡排序(相邻两数)(降序)
## 12冒泡排序(不相邻两数)(降序)
## 13选择排序(降序)
## 14插入排序(降序)
## 15希尔排序(降序)
## 16快速排序(注意:当数组长度为0或1时)(降序)
## 17堆排序(降序)
## 18归并排序(注意:当数组长度为0或1时)(降序)
## 19计数排序(降序)
