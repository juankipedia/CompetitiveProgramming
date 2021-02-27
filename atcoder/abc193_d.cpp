#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int k;
string s, t;

int main(){
    cin >> k >> s >> t;
    long double cs[10] = {0}, ct[10] = {0}, c[10] = {0};
    lli ss = 0, st = 0;
    for(int i = 0; i < 4; i++) cs[s[i] - '0']++, ct[t[i] - '0']++;
    for(int i = 1; i <= 9; i++){
        c[i] = cs[i] + ct[i];
        ss += i * pow(10, cs[i]);
        st += i * pow(10, ct[i]);
    }
    
    for(int i = 0; i < 10; i++) c[i] = k - c[i];
    long double N = k * 9 - 8, cnt = 0;
    for(int i = 1; i <= 9; i++){
        if(c[i] == 0) continue;
        for(int j = 1; j <= 9; j++){
            if(c[j] == 0) continue;
            if(i == j && c[i] == 1) continue;
            
            ss -= i * pow(10, cs[i]);
            st -= j * pow(10, ct[j]);


            if((ss + i * pow(10, cs[i] + 1)) > (st + j * pow(10, ct[j] + 1))){
                //cout << i << " " << j << " ";
                
                if(i == j){
                    cnt += c[i] * (c[i] - 1);
                    //cout << c[i] * (c[i] - 1) / 2 << endl;
                }
                else{
                    cnt += c[i] * c[j];
                    //cout << c[i] * c[j] << endl;
                }
                
            }

            ss += i * pow(10, cs[i]);
            st += j * pow(10, ct[j]);
        }
    }

    long double w = cnt, total = N * (N - 1);
    //cout << w << " " << total << endl;
    cout << std::fixed << setprecision(15) << w / total << endl;
    return 0;
}