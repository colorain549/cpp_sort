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

// 冒泡排序(相邻两数)
void bubbleSort(vector<int> &ivec)
{
    for (int i = 0; i < ivec.size(); i++)
    {
        for (int j = 0; j < ivec.size() - 1; j++)
        {
            if (ivec[j] > ivec[j + 1])
            {
                swap(ivec[j], ivec[j + 1]);
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