#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
lli m[500][500];

int main(){
    cin >> n;
    int ii, jj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m[i][j];
            if(m[i][j] == 0){
                ii = i;
                jj = j;
            }
        }
    }

    if(n == 1){
        cout << 1 << endl;
        return 0;
    }

    lli sumr = 0, sumc = 0, sumrp = 0, sumcp = 0;
    for(int i = 0; i < n; i++){
        if(i == ii) continue;
        for(int j = 0; j < n; j++){
            sumr += m[i][j];
        }
        if(sumr != 0) break;
    }

    for(int i = 0; i < n; i++){
        if(i == jj) continue;
        for(int j = 0; j < n; j++){
            sumc += m[j][i];
        }
        if(sumc != 0) break;
    }

    for(int i = 0; i < n; i++){
        if(i == ii){
            for(int j = 0; j < n; j++){
                sumrp += m[i][j];
            }
            break;
        }
    }

    for(int i = 0; i < n; i++){
        if(i == jj){
            for(int j = 0; j < n; j++){
                sumcp += m[j][i];
            }
            break;
        }
    }

    if(sumrp >= sumr) cout << -1 << endl;
    else if(sumcp >= sumc) cout << -1 << endl;
    else if((sumr - sumrp) != (sumc - sumcp)) cout << -1 << endl;
    else{
        lli ans = sumr - sumrp;
        m[ii][jj] = ans;
        sumrp += ans;
        sumcp += ans;
        bool f = true;
        for(int i = 0; i < n; i++){
            sumr = 0;
            for(int j = 0; j < n; j++){
                sumr += m[i][j];
            }
            if(sumr != sumrp){
                f = false;
                break;
            }
        }
        for(int i = 0; i < n; i++){
            sumr = 0;
            for(int j = 0; j < n; j++){
                sumr += m[j][i];
            }
            if(sumr != sumcp){
                f = false;
                break;
            }
        }
        sumr = 0; sumc = 0;
        for(int i = 0; i < n; i++){
            sumr += m[i][i];
            sumc += m[i][n - i - 1];
        }
        if(sumr != sumc) f = false;
        if(f){
            if(sumrp != sumr) cout << -1 << endl;
            else cout << ans << endl;
        }
        else cout << -1 << endl;
        
    }
    return 0;
}