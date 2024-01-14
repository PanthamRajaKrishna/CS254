// Time Complexity: O(N * W)  N is number of weights/values.
// Auxiliary Space: O(W)      W is maximum weight allowed.

#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{

    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {

            if (wt[i - 1] <= w)

                dp[w] = max(dp[w],
                            dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    return dp[W];
}

int main()
{
    freopen("input_Q2.txt","r",stdin);
    freopen("output_Q2.txt","w",stdout);
    int t;cin>>t;
    while(t--){
    int n;
    cin >> n;
    int W;
    cin >> W;
    int value[n];
    int weight[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    cout << knapSack(W, weight, value, n)<<'\n';
   }
}
