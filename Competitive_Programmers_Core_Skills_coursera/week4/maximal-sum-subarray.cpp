#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> ar(n); for (int i = 0; i < n; ++i) cin >> ar[i];
    vector<long long> p_ar(n + 1), s_ar(n + 1);
    for (int i = 0; i < n; ++i) p_ar[i + 1] = p_ar[i] + ar[i];
    for (int i = n - 1; i >= 0; --i) s_ar[i] = s_ar[i + 1] + ar[i];
    long long sum = p_ar[n];
    for (int i = 0; i < n; ++i) p_ar[i + 1] = min(p_ar[i + 1], p_ar[i]);
    for (int i = n - 1; i >= 0; --i) s_ar[i] = min(s_ar[i + 1], s_ar[i]);
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << sum - p_ar[i] - s_ar[i + 1] << endl;
    }
    cout << endl;
    return 0;
}