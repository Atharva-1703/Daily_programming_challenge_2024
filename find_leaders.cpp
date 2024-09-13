#include <bits/stdc++.h>
using namespace std;

vector<int> findLeader(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
    {
        return arr;
    }

    vector<int> ans;
    stack<int> stk;
    stk.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > stk.top())
        {
            stk.push(arr[i]);
        }
    }
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 4, 3, 2, 1};
    vector<int> lead = findLeader(nums);
    for (int i = 0; i < lead.size(); i++)
    {
        cout << lead[i] << " ";
    }

    return 0;
}