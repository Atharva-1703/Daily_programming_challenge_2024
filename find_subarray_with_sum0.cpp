#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findSumZero(vector<int> nums)
{
    unordered_map<int, vector<int>> mpp;
    vector<vector<int>> ans;
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum == 0)
            ans.push_back({0, i});
        if (mpp.find(sum) != mpp.end())
        {
            vector<int> v = mpp[sum];
            for (auto it : v)
            {
                ans.push_back({it + 1, i});
            }
        }
        mpp[sum].push_back(i);
    }
    return ans;
}

int main()
{
    // vector<int> num = {4, -1, -3, 1, 2, -1};
    // vector<int> num = {1, 2, 3, 4};
    vector<int> num = {0, 0, 0};
    vector<vector<int>> ans = findSumZero(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "," << ans[i][1] << endl;
    }
    return 0;
}