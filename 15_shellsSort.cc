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

void shellsSort(vector<int> &ivec)
{
    for (int gap = ivec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < ivec.size(); i+=gap)
        {
            int j;
            int insertVal = ivec[i];
            // ivec[j] < insertVal
            for (j = i - gap; j >= 0 && ivec[j] < insertVal; j-=gap)
            {
                ivec[j + gap] = ivec[j];
            }
            ivec[j + gap] = insertVal;
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
    shellsSort(ivec);
    // 打印
    printVec(ivec);
}