#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &first, vector<int> &second)
{
    int i = first.size() - 1;
    int m = second.size();
    int temp;
    int j = 0;
    while (i >= 0 && j < m)
    {
        if (first[i] > second[j])
        {
            temp = first[i];
            first[i] = second[j];
            second[j] = temp;
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
}

int main()
{
    vector<int> num1 = {10, 12, 14};
    vector<int> num2 = {1, 3, 5};
    merge(num1, num2);
    for (int i = 0; i < num1.size(); i++)
    {
        cout << num1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < num2.size(); i++)
    {
        cout << num2[i] << " ";
    }
    cout << endl;

    return 0;
}