#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int count = 0;
    int n = strs.size();
    string first = strs[0];
    string last = strs[n - 1];
    if (!first.compare(last))
        return first;
    for (int i = 0; i < first.size(); i++)
    {
        if (first.at(i) == last.at(i))
        {
            count++;
        }
        else
        {
            return first.substr(0, count);
        }
    }
    return first.substr(0, count);
}

int main()
{
    // vector<string> strs = {"flower", "flow", "flight"};
    // vector<string> strs = {"dog", "racecar", "car"};
    // vector<string> strs = {"apple", "ape", "april"};
    // vector<string> strs = {""};
    vector<string> strs = {"alone"};
    cout << longestCommonPrefix(strs);

    return 0;
}