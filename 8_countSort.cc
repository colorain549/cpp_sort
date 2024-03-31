// 输入: 2 6 2 1 3
// 输出: 1 2 2 3 6
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
    printVec(ivec);
}