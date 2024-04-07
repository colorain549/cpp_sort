// 输入: [2 6 2 1 3][5]
// 输出: [1]
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

#define LEN 5

void printVec(vector<int> &ivec)
{
    for (auto &elem : ivec)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

// 小顶堆
void adjustMinHeap(vector<int> &ivec, int adjustPos, int arrLen)
{
    int dad = adjustPos;
    int son = 2 * dad + 1;
    while (son < arrLen)
    {
        if (son + 1 < arrLen && ivec[son + 1] < ivec[son])
        {
            son++;
        }
        if (ivec[dad] > ivec[son])
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
        adjustMinHeap(ivec, i, k);
    }
    // swap(ivec[0], ivec[LEN - 1]);
    // for (int i = ivec.size() - 1; i > 0; i--)
    // {
    //     adjustMinHeap(ivec, 0, i);
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

    // 打印
    // printVec(ivec);
    cout << ivec[0] << endl;
}