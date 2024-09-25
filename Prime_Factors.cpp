#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactors(int num)
{
    vector<int> ans;
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            ans.push_back(i);
            num /= i;
        }
    }
    return ans;
}

int main()
{
    // int num = 18;
    // int num = 30;
    // int num = 49;
    int num = 123456;
    vector<int> ans = primeFactors(num);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}