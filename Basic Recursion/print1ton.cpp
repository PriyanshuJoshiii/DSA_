#include <iostream>
using namespace std;
int c = 1;
void print(int n)
{
    if (c > n)
        return;
    cout << c << endl;
    c++;
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