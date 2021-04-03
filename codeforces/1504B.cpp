# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, N;
string a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        cin >> a >> b;
        int o[N] = {0}, z[N] = {0};

        if(a[0] == '1') o[0] = 1;
        else z[0] = 1;

        for(int i = 1; i < N; i++){
            if(a[i] == '1') o[i]++;
            else z[i]++;
            o[i] += o[i - 1];
            z[i] += z[i - 1];
        }

        int c = 0;
        bool ok = true;
        for(int i = N - 1; i >= 0; i--){
            if(c % 2){
                if(a[i] == '1') a[i] = '0';
                else a[i] = '1';
            }
            if(a[i] == b[i]) continue;
            else{
                if(o[i] == z[i]) c++;
                else{
                    ok = false;
                    break;
                }
            }
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    return 0;
}