#include "Headerfile.h"
int knapsack(vector<int> val, vector<int> weight, int num, int max_weight)
{
    vector<vector<int>> dp;
    for (int i = 0; i <= num; i++)
    {
        for (int w = 0; w <= max_weight; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i-1] <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i-1]] + val[i-1]);

            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[num][max_weight];
}

int main()
{
    int n = 3;
    vector<int>val = {10,15,40};
    vector<int> weight = {1,2,3};

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i].first << arr[i].second;
    // }
    int max_weight = 6;

    int ans = knapsack(val,weight, n, max_weight);

    cout << ans << endl;
    return 0;
}