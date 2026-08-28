#include <iostream>
using namespace std;
string prefixtopostfix(string s)
{
    int i = s.length() - 1;
    stack<string> st;
    while (i >= 0)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string k = a + b + s[i];
            st.push(k);
        }
        i--;
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    string ans = prefixtopostfix(s);
    cout << ans << endl;
    return 0;
}