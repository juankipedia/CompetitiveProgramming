#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli N, X;
pair<lli, lli> a[1000 + 5];
int main(){
    cin >> N >> X;
    X *= 100;
    for(int i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    int i = 0;
    lli c = 0;
    for(; i < N; i++){
        c += a[i].first * a[i].second;
        if(c > X){
            cout << i + 1 << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
}