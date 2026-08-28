#include <iostream>
using namespace std;
void print(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    n--;
    print(n);
    return;
}
int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}