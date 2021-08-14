# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, n;
string s;


int main(){
    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        int ans1 = -1, ans2 = -1, F = 0, S = 0, TF = 0, TS = 0, tf = 0, ts = 0;
        for(int i = 0; i < n; i++) if(i % 2) TS++; else TF++;
        tf = TF;
        ts = TS;
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                if(i % 2 == 0) F++;
            }
            else if(s[i] == '1' && i % 2) S++;
            else if(s[i] == '1') F++;
            if(i % 2) TS--;
            else TF--;
            if(F > (TS + S) || S > (TF + F)){ ans1 = i + 1; break; }
        }
        
        if(ans1 == -1) ans1 = n;
        TF = tf; TS = ts;
        F = 0; S = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '?'){
                if(i % 2) S++;
            }
            else if(s[i] == '1' && i % 2) S++;
            else if(s[i] == '1') F++;
            if(i % 2) TS--;
            else TF--;
            if(F > (TS + S) || S > (TF + F)){ ans2 = i + 1; break; }
        }
        
        if(ans2 == -1) ans2 = n;
        cout << min(ans1, ans2) << endl;
    }
    return 0;
}
// 1122334455
// 1111111111
// 0112233445