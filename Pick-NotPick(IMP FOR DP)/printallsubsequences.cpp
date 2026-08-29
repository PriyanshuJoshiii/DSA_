#include <iostream>
using namespace std;
void printallsubsequence(int ind, vector<int> &arr, vector<int> &ds)
{
    if (ind >= arr.size())
    {
        if (ds.size() == 0)
        {
            cout << "{ }";
            return;
        }
        for (auto it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    printallsubsequence(ind + 1, arr, ds);
    ds.pop_back();
    printallsubsequence(ind + 1, arr, ds);
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
    vector<int> ds;
    printallsubsequence(0, arr, ds);
}
