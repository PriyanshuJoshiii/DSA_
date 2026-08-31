#include <iostream>
using namespace std;
int countwheresumisk(int idx, int curr_sum, int sum, vector<int> &arr)
{
    if (idx == arr.size())
    {
        if (curr_sum == sum)
        {
            return 1;
        }
        else
            return 0;
    }
    int left = countwheresumisk(idx + 1, curr_sum + arr[idx], sum, arr);
    int right = countwheresumisk(idx + 1, curr_sum - arr[idx], sum, arr);
    return left + right;
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
    int count = countwheresumisk(0, 0, sum, arr);
    cout << count << endl;
    return 0;
}