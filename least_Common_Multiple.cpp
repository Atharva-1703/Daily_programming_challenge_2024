#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

long long int LCM(int a, int b)
{
    long long int g = gcd(a, b);
    return (a / g) * b;
}

int main()
{
    cout << LCM(4, 6) << endl;
    cout << LCM(1, 987654321) << endl;
    cout << LCM(123456, 789012) << endl;
    cout << LCM(4, 4) << endl;
    return 0;
}