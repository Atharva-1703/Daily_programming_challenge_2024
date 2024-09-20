#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> stk;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (stk.empty())
            stk.push(c);
        else if (c == '(' || c == '[' || c == '{')
        {
            stk.push(c);
        }
        else if (c - stk.top() == 1 || c - stk.top() == 2)
        {
            stk.pop();
        }
        else
        {
            stk.push(c);
        }
    }
    return stk.empty();
}

int main()
{
    // string s = "()";
    // string s = "([)]";
    // string s = "";
    string s = "[{()}]";
    cout << isValid(s) << endl;
    return 0;
}