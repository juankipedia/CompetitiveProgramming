# include <bits/stdc++.h> 
using namespace std;

int main() {
    cin.sync_with_stdio(false); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int> > prefix_sum(n + 1, vector<int>(n + 1));
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int v;
            cin >> v;
            prefix_sum[i][j] = v + prefix_sum[i][j - 1] + prefix_sum[i - 1][j] - prefix_sum[i - 1][j - 1];
            if (i >= k && j >= k) res = max(res, prefix_sum[i][j] - prefix_sum[i][j - k] - prefix_sum[i - k][j] + prefix_sum[i - k][j - k]);
        }
    }

    cout << res << '\n';

    return 0;
}