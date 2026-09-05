// approach 1
#include <iostream>
using namespace std;
void permu(vector<int> &arr, vector<int> &hash, vector<vector<int>> &ans, vector<int> &vec)
{
    if (vec.size() == arr.size())
    {
        ans.push_back(vec);
        return;
    }
    for (int i = 0; i < hash.size(); i++)
    {
        if (hash[i] == -1)
        {
            vec.push_back(arr[i]);
            hash[i]++;
            permu(arr, hash, ans, vec);
            vec.pop_back();
            hash[i]--;
        }
    }
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
    vector<int> vec;
    vector<int> hash(n, -1);
    vector<vector<int>> ans;
    permu(arr, hash, ans, vec);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
