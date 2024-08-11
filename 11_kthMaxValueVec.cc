// 输入: [2 6 2 1 3][4]
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

// 计数排序
void countSort(vector<int> &ivec)
{
    int max = 10;
    vector<int> count(max);
    for (int i = 0; i < max; i++)
    {
        count[ivec[i]]++;
    }
    int index = 0;
    for (int i = max - 1; i > 0; i--)
    {
        if (count[i])
        {
            ivec[index++] = i;
        }
    }
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
    // 排序
    countSort(ivec);
    // 打印
    // printVec(ivec);
    // 第kth大
    int kth;
    cin >> kth;
    cout << ivec[kth - 1] << endl;
    return 0;
}