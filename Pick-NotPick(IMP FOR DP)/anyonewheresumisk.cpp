#include <iostream>
using namespace std;
bool anyonewheresumisk(int idx, int sum, int curr_sum, vector<int> &ds, vector<int> &vec)
{
    if (idx == vec.size())
    {
        if (curr_sum == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
            return false;
    }
    if (curr_sum > sum)
        return false;
    ds.push_back(vec[idx]);
    if (anyonewheresumisk(idx + 1, sum, curr_sum + vec[idx], ds, vec))
    {
        return true;
    }
    ds.pop_back();
    if (anyonewheresumisk(idx + 1, sum, curr_sum, ds, vec))
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int k;
    cin >> k;
    vector<int> ds;
    anyonewheresumisk(0, k, 0, ds, vec);
    return 0;
}
