#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
multiset<int> A[1000], B[1000];
int a[1000], b[1000];
bool ab[1000], bb[1000];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
        int res = 1e9 + 5;
        for(int j = 0; j < n; j++) res = min(res, abs(a[i]-b[j]));
        ans = max(res, ans);
    }
    cout << ans << endl;
    return 0;
}