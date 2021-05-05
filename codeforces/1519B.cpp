# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, m, k;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> k;

        if(n > m) swap(n , m);

        int i = 1, j = m - n + 1, c = m - n;
        bool d = true;
        while(!(i == n && j == m)){
            if(d) c += j, i++;
            else c += i, j++;
            d = !d;
        }
        if(c == k){
            cout << "YES" << endl;
            continue;
        }

        i = 1; j = m - n + 1; c = m - n;
        d = false;
        while(!(i == n && j == m)){
            if(d) j++, c += i;
            else i++, c += j;
            d = !d;
        }
        if(c == k){
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }
    return 0;
}