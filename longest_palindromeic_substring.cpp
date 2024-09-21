#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans;
    int maxLen = 0;

    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (diff == 1 && s[i] == s[j])
            {
                dp[i][j] = 2;
            }
            else
            {
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = j - i + 1;
                }
            }
            if (dp[i][j] > maxLen)
            {
                maxLen = max(maxLen, dp[i][j]);
                ans = s.substr(i, maxLen);
            }
        }
    }
    return ans;
}

int main()
{
    // string str = "babad";
    // string str = "cbbd";
    // string str = "bb";
    // string str = "a";
    string str = "abc";
    cout << longestPalindrome(str);
    return 0;
}