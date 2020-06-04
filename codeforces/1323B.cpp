#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;
int n, m, a[40000], b[40000], sa[40001], sb[40001];
lli k;

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> b[i];

    int i = 0;
    while(i < n){
        if(a[i] == 0){ i++; continue; }
        int j = i;
        while (j < n && a[j] == 1) j ++;
        for(int size = 1; size <= (j - i); size++)
            sa[size] += (j - i) - size + 1;
        i = j;
    }

    i = 0;
    while(i < m){
        if(b[i] == 0){ i++; continue; }
        int j = i;
        while (j < m && b[j] == 1) j ++;
        for(int size = 1; size <= (j - i); size++)
            sb[size] += (j - i) - size + 1;
        i = j;
    }
    lli ans = 0;
    for(int i = 1; i <= (n + 1); i++)
        if(k % i == 0 && k / i <= m)
            ans += sa[i] * sb[k / i];
    cout << ans << endl;
    return 0;
}