// 输入: [2 6 2 1 3][4]
// 输出: [1]
#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::set;
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
    int k;
    cin >> k;

    set<int> iset(ivec.begin(), ivec.end());
    auto it = iset.begin();
    for (int i = 1; i < iset.size() - k + 1; ++i)
    {
        ++it;
    }
    cout << *it << endl;

    // 打印
    // printVec(ivec);
}