# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[100000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        lli m = 0, c;
        bool e = true;
        set<lli> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            m = max(a[i], m);
            if(i > 0) s.insert(a[i] - a[i - 1]);
        }

        if(s.size() > 2){
            cout << -1 << endl;
            continue;
        }
        if(s.size() == 1 || n == 1){
            cout << 0 << endl;
            continue;
        }

        if(abs(*s.begin() - *s.rbegin()) <= m){
            cout << -1 << endl;
            continue;
        }

        m = abs(*s.begin() - *s.rbegin());

        c = (m - (a[0] - a[1])) % m;
        
        for(int i = 2; i < n; i++){
            if((a[i - 1] + c) % m == a[i]) continue;
            else{
                e = false;
                break;
            }
        }
        
        if(e) cout << m << " " << c << endl;
        else cout << -1 << endl;
        
    }
    return 0;
}