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

int t, n, k,  w[200000];
lli a[200000];


int main() {
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < k; i++) cin >> w[i];
        sort(a, a + n);
        sort(w, w + k);
        int j = 0;
        lli ans = 0;

        for(int i = 0; i < k && w[i] == 1; i++){
            ans += 2 * a[n - 1];
            n--;
        }

        int l = j, r = n  - 1;
        reverse(w + j, w + k);
        while(l <= r && j < k){
            lli maxi = a[r];
            lli mini = a[l];
            r --;
            for(int i = 0; i < (w[j] - 1); i ++) l++;
            ans += maxi + mini;
            j++;
        }
        cout << ans << endl;
    }
    return 0;
}