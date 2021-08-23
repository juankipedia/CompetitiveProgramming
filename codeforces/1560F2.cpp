# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, k;
string n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> k;
        int ps = 0;
        while(ps < n.size()){
            bool m[10] = {false};
            int c = 0, i = 0;
            for(; i < n.size(); i++){
                if(!m[n[i] - '0']) c++, m[n[i] - '0'] = true;
                if(c > k) break;
            }
            ps = i;
            if(ps == n.size()) break;
            i--;
            lli nn = stoll(n.substr(0, ps + 1));
            nn++;
            string a = to_string(nn);
            n = a + string(n.size() - a.size(), '0');
            //cout << n << endl;
        }
        cout << n << endl;
    }

    return 0;
}
