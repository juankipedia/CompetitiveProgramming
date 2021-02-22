#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5 + 5;
int n, k, a[MAXN];

bool check(int median){
    int s[n] = {0}, b[n];
    for(int i = 0; i < n; i++) if(a[i] >= median) b[i] = 1; else b[i] = -1;
    s[0] = b[0];
    for(int i = 1; i < n; i++) s[i] = s[i - 1] + b[i];
    int maxi = s[k - 1];
    int mini = 0;
    for(int i = k; i < n; i++){
        mini = min(mini, s[i - k]);
        maxi = max(s[i] - mini, maxi);
    }
    return maxi > 0;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    int lo = 1, hi = n + 1;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}