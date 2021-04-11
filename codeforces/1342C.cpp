# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, q;
ulli l, r, a, b, sum[40050], len;
ulli query(ulli l){
    ulli  cnt = l / len;
    return sum[len] * cnt + sum[l % len];
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> a >> b >> q;
        len = a * b;
        sum[0] = 0;
        int idx = 1;
        while(idx <= len){
            sum[idx] = sum[idx - 1];
            if((idx % a) % b != (idx % b) % a) sum[idx]++;
            idx++;
        }

        while(q--){
            cin >> l >> r;
            cout << query(r) - query(l - 1) << " ";
        }
        cout << endl;
        
    }
    return 0;
}