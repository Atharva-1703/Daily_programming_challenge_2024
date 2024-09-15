#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> &height)
{
    int l = 0, r = height.size() - 1;
    int res = 0;
    int leftmax = 0, rightmax = 0;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= leftmax)
            {
                leftmax = height[l];
            }
            else
            {
                res += leftmax - height[l];
            }
            l++;
        }
        else
        {
            if (height[r] >= rightmax)
            {
                rightmax = height[r];
            }
            else
            {
                res += rightmax - height[r];
            }
            r--;
        }
    }
    return res;
}

int main()
{
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // vector<int> height = {4, 2, 0, 3, 2, 5};
    // vector<int> height = {1, 1, 1};
    // vector<int> height = {5};
    // vector<int> height = {2, 0, 2};
    // vector<int> height = {1, 2, 3, 4, 5, 6};
    vector<int> height = {6, 5, 4, 3, 2, 1};
    cout << trapWater(height);
    return 0;
}