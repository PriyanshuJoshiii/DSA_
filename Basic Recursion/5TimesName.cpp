#include <iostream>
using namespace std;
int c = 1;
void print(string s)
{
    if (c > 5)
        return;
    cout << c << ".)" << s << endl;
    c++;
    print(s);
    return;
}
int main()
{
    print("Priyanshu");
    return 0;
}
