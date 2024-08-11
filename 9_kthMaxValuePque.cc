// 输入: [2 6 2 1 3][5]
// 输出: [1]
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
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

int pqueSort(vector<int> &ivec, int k)
{
    priority_queue<int, vector<int>, std::greater<int>> pque;
    for (int i = 0; i < ivec.size(); i++)
    {
        pque.push(ivec[i]);
        if (pque.size() > k)
        {
            pque.pop();
        }
    }
    return pque.top();
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
    int k;
    cin >> k;
    // 排序
    int result = pqueSort(ivec, k);

    // 打印
    // printVec(ivec);

    cout << result << endl;
}