#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    int n = strs.size();
    string temp;
    for (int i = 0; i < n; i++)
    {
        temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(temp);
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{
    // vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // vector<string> strs = {""};
    // vector<string> strs = {"a"};
    // vector<string> strs = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<string> strs = {"abc", "def", "ghi"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}