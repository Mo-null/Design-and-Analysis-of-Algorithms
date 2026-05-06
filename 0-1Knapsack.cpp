#include <iostream>

using namespace std;

int maxValue(int a, int b)
{
    if(a > b)
    {
        return a;
    }

    return b;
}

int knapsack(int capacity, int weight[], int value[], int n)
{
    int dp[n + 1][capacity + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int w = 0; w <= capacity; w++)
        {
            if(i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int w = 1; w <= capacity; w++)
        {
            if(weight[i - 1] <= w)
            {
                dp[i][w] = maxValue(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Selected Items:\n";

    int w = capacity;

    for(int i = n; i > 0; i--)
    {
        if(dp[i][w] != dp[i - 1][w])
        {
            cout << "Item " << i
                 << " (Weight = " << weight[i - 1]
                 << ", Value = " << value[i - 1] << ")\n";

            w = w - weight[i - 1];
        }
    }

    return dp[n][capacity];
}

int main()
{
    int value[] = {60, 100, 120};
    int weight[] = {10, 20, 30};

    int capacity = 50;

    int n = 3;

    int result = knapsack(capacity, weight, value, n);

    cout << "\nMaximum Profit: " << result << endl;

    return 0;
}