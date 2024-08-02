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
    insertSort(ivec);
    // 打印
    printVec(ivec);
}