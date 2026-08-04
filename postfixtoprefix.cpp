#include <iostream>
using namespace std;
string postfixtoprefix(string s)
{
    string ans;
    int i = 0;
    stack<string> st;
    while (i < s.length())
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
            string c = s[i] + b + a;
            st.push(c);
        }
        i++;
    }
    return st.top();
}
int main()
{
    string s;
    cin >> s;
    string ans = postfixtoprefix(s);
    cout << ans << endl;
    return 0;
}