#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    if (!s.length())
        return 0;
    int maxLen = 1;
    unordered_map<char, int> mp;
    int i = 0;
    int j = i;
    while (j < s.length())
    {
        mp[s[j]]++;
        while (mp[s[j]] > 1)
        {
            mp[s[i]]--;
            i++;
        }
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}

int main()
{
    // string s = "abcabcbb";
    // string s = "bbbb";
    // string s = "abcdefgh";
    string s = "a";
    cout << lengthOfLongestSubstring(s);
    return 0;
}