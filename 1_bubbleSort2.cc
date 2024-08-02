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
    bubbleSort(ivec);
    // 打印
    printVec(ivec);
}