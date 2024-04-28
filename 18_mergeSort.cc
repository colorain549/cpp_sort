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

vector<int> merge(vector<int> &left, vector<int> &right)
{
    vector<int> result;
    int left_index = 0;
    int right_index = 0;
    while (left_index < left.size() && right_index < right.size())
    {
        // left[left_index] >= right[right_index]
        if (left[left_index] >= right[right_index])
        {
            result.push_back(left[left_index]);
            left_index++;
        }
        else
        {
            result.push_back(right[right_index]);
            right_index++;
        }
    }
    result.insert(result.end(), left.begin() + left_index, left.end());
    result.insert(result.end(), right.begin() + right_index, right.end());
    return result;
}
vector<int> mergeSort(vector<int> &ivec)
{
    if (ivec.size() <= 1)
    {
        return ivec;
    }
    int mid = ivec.size() / 2;
    vector<int> left(ivec.begin(), ivec.begin() + mid);
    vector<int> right(ivec.begin() + mid, ivec.end());
    auto sorted_left = mergeSort(left);
    auto sorted_right = mergeSort(right);
    auto result = merge(sorted_left, sorted_right);
    return result;
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
    ivec = mergeSort(ivec);
    // 打印
    printVec(ivec);
}