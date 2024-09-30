#include <bits/stdc++.h>
using namespace std;

int repeatKTimes(vector<int> arr, int k)
{
    unordered_map<int, int> mpp;
    for (auto it : arr)
    {
        mpp[it]++;
    }
    for (auto it : mpp)
    {
        if (it.second == k)
            return it.first;
    }
    return -1;
}

int main()
{
    vector<int> v = {1};
    cout << repeatKTimes(v, 1);
    return 0;
}