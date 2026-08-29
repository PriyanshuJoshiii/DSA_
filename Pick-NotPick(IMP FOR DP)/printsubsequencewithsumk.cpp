#include <iostream>
using namespace std;
void wheresumissum(int ind, vector<int> &arr, int curr_sum, int sum, vector<int> &ds)
{
    if (ind == (int)arr.size())
    {
        if (curr_sum == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ds.push_back(arr[ind]);
    wheresumissum(ind + 1, arr, curr_sum + arr[ind], sum, ds);
    ds.pop_back();
    wheresumissum(ind + 1, arr, curr_sum, sum, ds);
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
    int sum;
    cin >> sum;
    vector<int> ds;
    wheresumissum(0, arr, 0, sum, ds);
    return 0;
}