#include <iostream>
using namespace std;
void print(int a, int n)
{
    if (a < 1)
    {
        return;
    }
    print(a - 1, n);
    cout << a << endl;
    return;
}
int main()
{
    int n;
    cin >> n;
    print(n, n);
    return 0;
}