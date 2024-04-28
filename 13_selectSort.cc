// 输入: 2 6 2 1 3
// 输出: 6 3 2 2 1
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

void selectSort(vector<int> &ivec)
{
    int index;
    for (int i = 0; i < ivec.size(); i++)
    {
        index = i;
        for (int j = i + 1; j < ivec.size(); j++)
        {
            // if (ivec[index] < ivec[j])
            if (ivec[index] < ivec[j])
            {
                index = j;
            }
        }
        swap(ivec[i], ivec[index]);
    }
}

int main()
{
    // 构建数组
    vector<int> ivec;
    ivec.reserve(5);
    int item;
    for (int i = 0; i < LEN; i++)
    {
        cin >> item;
        ivec.push_back(item);
    }
    // 排序
    selectSort(ivec);
    // 打印
    printVec(ivec);
}