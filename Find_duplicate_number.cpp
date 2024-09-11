#include <bits/stdc++.h>
using namespace std;

int duplicateNumber(vector<int> &nums)
{
    int n = nums.size() - 1;
    int res = 0;
    for (int i = 0; i < n + 1; i++)
    {
        res ^= i;
        res ^= nums[i];
    }

    return res;
}

int main()
{
    vector<int> nums = {3, 1, 3, 4, 2};
    cout << duplicateNumber(nums) << endl;
    return 0;
}