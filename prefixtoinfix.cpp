#include <iostream>
using namespace std;
string prefixtoinfix(string s)
{
    int i = s.length() - 1;
    stack<string> st;
    while (i >= 0)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string k = "(" + a + string(1, s[i]) + b + ")";
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
    string ans = prefixtoinfix(s);
    cout << ans << endl;
    return 0;
}