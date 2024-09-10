#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int a = 0;
    int b = 0;
    int n = nums.size();
    int res = n;
    for (int i = 0; i < n; i++)
    {
        res ^= i;
        res ^= nums[i];
    }
    res ^= n + 1;
    return res;
}

int main()
{
    vector<int> nums = {1, 2, 4, 5};
    cout << missingNumber(nums) << endl;
    return 0;
}