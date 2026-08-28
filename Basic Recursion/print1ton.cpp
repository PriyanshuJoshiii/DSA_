#include <iostream>
using namespace std;
void print(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    i++;
    print(i, n);
    return;
}
int main()
{
    int n;
    cin >> n;
    print(1, n);
    return 0;
}