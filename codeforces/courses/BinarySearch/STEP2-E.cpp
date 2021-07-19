# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

long double c;

int main(){

    cin >> c;

    long double lo = 0, hi = 1e10 + 5;
    for(int i = 0; i < 100; i++){
        long double mid = (lo + hi) / 2;
        if((mid * mid + sqrt(mid)) > c) hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(10) << lo << endl; 
    return 0;
}