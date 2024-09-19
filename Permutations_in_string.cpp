#include <bits/stdc++.h>
using namespace std;

void rev(string &str, int i, int j)
{
    int temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
void nextPermutation(string &str)
{
    int n = str.size();
    int ind = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (str[i] < str[i + 1])
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
    {
        rev(str, 0, n - 1);
        return;
    }
    for (int i = n - 1; i > ind; i--)
    {
        if (str[i] > str[ind])
        {
            swap(str[i], str[ind]);
            break;
        }
    }
    rev(str, ind + 1, n - 1);
}
vector<string> permuteString(string &str)
{
    vector<string> ans;
    set<string> sst;
    sst.insert(str);
    ans.push_back(str);
    long long fact = 1;
    for (int i = 1; i <= str.size(); i++)
    {
        fact *= i;
    }

    for (int i = 0; i < fact - 1; i++)
    {
        nextPermutation(str);
        if (sst.find(str) == sst.end())
        {
            sst.insert(str);
            ans.push_back(str);
        }
    }
    return ans;
}

int main()
{
    // string str = "abc";
    // string str = "aab";
    string str = "aaaaa";
    vector<string> v = permuteString(str);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}