#include <iostream>
using namespace std;
void print(int i,string s)
{
    if (i > 5)
        return;
    cout << i << ".)" << s << endl;
    i++;
    print(i,s);
    return;
}
int main()
{
    print(1,"Priyanshu");
    return 0;
}
