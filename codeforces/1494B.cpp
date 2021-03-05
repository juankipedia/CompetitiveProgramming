# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N, U, R, D, L;

bool check(int u, int d, int r, int l) {
    if(u == N){
        if(d == N){
            if(!(r >= 2 && l >= 2)) return false;
        }
        else if(d == N - 1){
            if(!((r >= 1 && l >= 2) || (r >= 2 && l >= 1))) return false;
        }else{
            if(!(r >= 1 && l >= 1)) return false;
        }
    }
    else if(u == N - 1){
        if(d == N){
            if(!((r >= 1 && l >= 2) || (r >= 2 && l >= 1))) return false;
        }else if(d == N - 1){
            if(!((r >= 1 && l >= 1) || r >= 2 || l >= 2)) return false;
        }else{
            if(!(r >= 1 || l >= 1)) return false;
        }
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        cin >> N >> U >> R >> D >> L;
        if(check(U, D, R, L) && check(D, U, R, L) && check(R, L, U, D) && check(L, R, U, D)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}