#include <iostream>
using namespace std;
string postfixtoinfix(string s)
{
    int i = 0;
    stack<string> st;
    while (i < s.length())
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string k = "(" + b + string(1, s[i]) + a + ")";
            st.push(k);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    string ans = postfixtoinfix(s);
    cout << ans << endl;
    return 0;
}