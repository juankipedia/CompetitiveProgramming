# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long double a[10005]; 
int n, k;

bool f(long double x){
    int s = 0;
    for(int i = 0; i < n; i++) s += int(a[i] / x); 
    return s >= k;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    long double lo = 0, hi = 1e7 + 5;
    for(int i = 0; i < 100; i++){
        long double mid = (lo + hi) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << fixed << setprecision(9) << lo << endl; 
    return 0;
}