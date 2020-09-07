#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, s, sum;
string n;
ulli ans = 0;

ulli pow(ulli e){
    ulli n = 10;
    ulli res { 1 };
    while(e > ulli(0)){
      if (e & 1)
        res = res * n;
      e >>= 1;
      n = n * n;
    }
    return res;
}

void update_n(int in){
    for(int i = in; i >= 0; i--){
        if(i == 0){
            if(n[i] - '0' + 1 == 10){
                sum = 1;
                return;
            }
            else n[i]++;

            break;
        }
        if(n[i] - '0' + 1 == 10) n[i] = '0';
        else{
            n[i]++;
            break;
        }
    }

    sum = 0;
    for(int i = 0; i < n.size(); i++) sum += n[i] - '0';

}


int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> s;
        ans = 0;
        sum = 0;
        for(int i = 0; i < n.size(); i++) sum += n[i] - '0';
        if(sum <= s){
            cout << 0 << endl;
            continue;
        }
        for(int i = (n.size() - 1); i >= 0; i--){
                ulli d = n[i] - '0';
                if(d == 0) continue;
                ans += (10 - d) * pow(n.size() - i - 1);
                n[i] = '0';
                update_n(i - 1);
                //cout << sum << endl;
                //cout << n << endl;
                if(sum <= s) break;
        }
        cout << ans << endl;
    }
    return 0;
}