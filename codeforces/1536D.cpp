# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int oo = 1e9 + 5;
int t, n, b[200005];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> b[i];
        bool ok = true;
        multiset<int> s;
        s.insert(b[0]);
        s.insert({-oo, oo});
        int median = b[0];
        for(int i = 1; i < n; i++){
            auto x = s.lower_bound(median);
            x--;
            auto y = s.upper_bound(median);
            //cout << *x << " " << median << " " << *y << endl;
            if(*x <= b[i] && b[i] <= *y){
                if(median == b[i]) s.insert({-oo, oo});
                else if(b[i] < median){
                    if(*x < b[i]) s.insert({b[i], -oo});
                    else s.insert({-oo, -oo});
                }
                else{
                    if(*y > b[i]) s.insert({b[i], oo});
                    else s.insert({oo, oo});
                }

                median = b[i];
            }
            else{
                ok = false;
                break;
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}