# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli t, n;

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        vector<lli> c[n];
        vector<pair<lli, lli>> co;
        for(lli i = 0; i < n; i++){
            lli k;
            cin >> k;
            c[i].assign(k, 0);
            for(lli j = 0; j < k; j++) cin >> c[i][j];
            lli acc = 0, p = 0;
            for(lli j = 0; j < k; j++)
                if(acc <= c[i][j]){
                    //assert((c[i][j] + 1 - j) >= p);
                    p = c[i][j] + 1 - j;
                    acc = p + 1 + j;
                }
                else acc++;
            co.push_back({p, i});
        }

        sort(co.begin(), co.end());

        lli lo = 0, hi = 1e10;
        while(lo < hi){
            lli mid = (lo + hi) / 2;
            bool check = true;

            lli acc = mid;
            for(auto &[p, idx] : co){
                if(acc < p){
                    check = false;
                    break;
                }
                else acc += c[idx].size();
            }

            if(check) hi = mid;
            else lo = mid + 1;
        }

        cout << lo << endl;
    }
    return 0;
}