#include <iostream>
using namespace std;
int check(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return -1;
}
string infixtoprefix(string s)
{
    reverse(s.begin(), s.end());
    for (char &ch : s)
    {
        if (ch == ')')
        {
            ch = '(';
        }
        else if (ch == '(')
        {
            ch = ')';
        }
    }
    int i = 0;
    stack<char> st;
    string ans;
    while (i < s.length())
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                   (check(s[i]) < check(st.top()) ||
                    (check(s[i]) == check(st.top()) && s[i] == '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = infixtoprefix(s);
    cout << ans << endl;
    return 0;
}