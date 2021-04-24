# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, q, t, a ,b;
string s;

int main(){
    cin >> N;
    cin >> s;
    cin >> q;
    int c = 0;
    while(q--){
        cin >> t >> a >> b;
        if(t == 1){
            if(c % 2){
                if(a <= N) a += N;
                else a -= N;
                if(b <= N) b += N;
                else b -= N;
            }
            swap(s[a - 1], s[b - 1]);
        }
        else c++;
    }
    if(c % 2) cout << s.substr(N, N) << s.substr(0, N) << endl;
    else cout << s << endl;
    return 0;
}