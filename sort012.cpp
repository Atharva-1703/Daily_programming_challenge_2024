#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &nums)
{
    int low, mid, high;
    low = 0;
    mid = 0;
    high = nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if (nums[mid] == 2)
        {
            int temp = nums[high];
            nums[high] = nums[mid];
            nums[mid] = temp;
            high--;
        }
    }
}

int main()
{
    vector<int> v = {0, 1, 2, 1, 0, 2, 1, 0};
    sort012(v);
    for (int i : v)
    {
        cout << i << " ";
    }

    return 0;
}