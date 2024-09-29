#include <bits/stdc++.h>
using namespace std;

void reverseInsert(stack<int> &s, int element)
{
    if (s.empty())
    {
        s.push(element);
        return;
    }
    int topElement = s.top();
    s.pop();
    reverseInsert(s, element);
    s.push(topElement);
}

void reverseStack(stack<int> &stk)
{
    if (stk.empty())
        return;
    int topElement = stk.top();
    stk.pop();
    reverseStack(stk);
    reverseInsert(stk, topElement);
}
void printStack(stack<int> stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(-2);
    stk.push(-15);
    stk.push(-10);
    printStack(stk);
    reverseStack(stk);
    printStack(stk);

    return 0;
}