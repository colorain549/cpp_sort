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

vector<int> quickSort(vector<int> &ivec)
{
    if (ivec.size() <= 1)
    {
        return ivec;
    }
    int pivot = ivec[0];
    vector<int> less;
    vector<int> greater;
    for (int i = 1; i < ivec.size(); i++)
    {
        // if (ivec[i] >= pivot)
        if (ivec[i] >= pivot)
        {
            less.push_back(ivec[i]);
        }
        else
        {
            greater.push_back(ivec[i]);
        }
    }
    auto sorted_less = quickSort(less);
    auto sorted_greater = quickSort(greater);
    sorted_less.push_back(pivot);
    sorted_less.insert(sorted_less.end(), sorted_greater.begin(), sorted_greater.end());
    return sorted_less;
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
    ivec = quickSort(ivec);
    // 打印
    printVec(ivec);
}