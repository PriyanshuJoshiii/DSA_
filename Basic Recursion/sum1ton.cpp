#include <iostream>
using namespace std;
/*int add(int i, int sum)
{
    if (i < 1)
    {
        return sum;
    }
    return add(i - 1, sum + i);
}
int main()
{
    int n;
    cin >> n;
    cout << add(n, 0) << endl;
    return 0;
}*/
int sumation(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sumation(n - 1);
}
int main()
{
    int n;
    cin >> n;
    cout << sumation(n) << endl;
    return 0;
}