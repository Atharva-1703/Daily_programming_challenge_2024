#include <bits/stdc++.h>
using namespace std;

int evaluate(string s)
{
    int i = 0, j = 0;
    stack<int> stk;
    int n = s.length();
    while (j <= n)
    {
        while (s[j] != ' ')
            j++;
        string ch = s.substr(i, j - i);
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "^")
        {
            char c = ch[0];
            int val2 = stk.top();
            stk.pop();
            int val1 = stk.top();
            stk.pop();
            switch (c)
            {
            case '+':
                stk.push(val1 + val2);
                break;
            case '-':
                stk.push(val1 - val2);
                break;
            case '*':
                stk.push(val1 * val2);
                break;
            case '/':
                stk.push(val1 / val2);
                break;
            case '^':
                stk.push(pow(val1, val2));
                break;
            }
        }
        else
        {
            stk.push(stoi(ch));
        }
        i = j + 1;
        j = i;
    }
    return stk.top();
}

int main()
{
    // string s = "2 1 + 3 *";
    // string s = "3 4 2 * 1 5 - 2 3 ^ ^ / +";
    string s = "-5 6 -";
    // string s = "5";
    cout << evaluate(s);
    return 0;
}