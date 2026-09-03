#include <iostream>
using namespace std;
void subsetsum(int index, vector<int> &arr, int sum, vector<int> &ans)
{
    if (index == (int)arr.size())
    {
        ans.push_back(sum);
        return;
    }
    subsetsum(index + 1, arr, sum + arr[index], ans);
    subsetsum(index + 1, arr, sum, ans);
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    subsetsum(0, arr, 0, ans);
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
