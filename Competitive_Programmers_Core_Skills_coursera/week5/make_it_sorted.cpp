#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int m = * max_element(a.begin(), a.end());
    vector<vector<int>> d_p(n + 1, vector<int>(m + 1));
    d_p[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int bb = 1e9;
        for (int j = 0; j <= m; ++j) {
            bb = min(bb, d_p[i][j]);
            d_p[i + 1][j] = bb + abs(a[i] - j);
        }
    }
    cout << *min_element(d_p[n].begin(), d_p[n].end()) << '\n';
    return 0;
}

