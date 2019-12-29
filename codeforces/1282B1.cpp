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

int tst, n, k, r;
lli p, a[200001], t[200001];


int main() {
    io_boost;
    cin >> tst;
    while(tst--){
        cin >> n >> p >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        r = 0;
        for (int i = 1; i <= n; i++){
            if(i >= k) t[i] = t[i - k] + a[i];
            else t[i] = a[i] + t[i - 1];
            if(p >= t[i]) r = i;
        }
        cout << r << endl;
    }
    return 0;
}