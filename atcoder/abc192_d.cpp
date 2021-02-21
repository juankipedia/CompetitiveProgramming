#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string X;
ulli M;

int main(){
    io_boost;
    cin >> X >> M;
    ulli d = 0, pos;
    reverse(X.begin(), X.end());
    for(int i = 0; i < X.size(); i++){
        d = max(d, ulli(X[i] - '0'));
        if(X[i] != '0') pos = i;
    }
    d++;
    if(X.size() == 1){
        if((X[X.size() - 1] - '0') > M) cout << 0 << endl;
        else cout << 1 << endl;
        return 0;
    }

    if(X[X.size() - 1] - '0' > M){
        cout << 0 <<endl;
        return 0;
    }


    ulli lo = 0, hi = M + 1;
    while(lo < hi){
        ulli mid = (lo + hi) / 2;
        ulli d = mid;
        ulli sum = 0;
        bool ok = true;
        ulli p = 1;
        for(int i = 0; i < X.size(); i++){
            sum += p * ulli(X[i] - '0');
            if(i < X.size() - 1){
                if(p > M / d){
                    ok = false;
                    break;
                }
            }
            if(p > M){
                ok = false;
                break;
            }
            if(sum > M){
                ok = false;
                break;
            }
            p *= d;
        }
        if(ok) lo = mid + 1;
        else hi = mid;
    }
    if(lo >= d + 1) cout << lo - d << endl;
    else cout << 0 << endl;
    return 0;
}