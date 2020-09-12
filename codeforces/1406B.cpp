#include <bits/stdc++.h>
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
        set<pair<lli, int>, std::greater<pair<lli, int>>> po, ne;
        set<pair<lli, int>> po2, ne2;
        cin >> n;
        bool z = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0){
                po.insert({a[i], i});
                po2.insert({a[i], i});
            }
            else if(a[i] < 0){
                ne.insert({abs(a[i]), i});
                ne2.insert({abs(a[i]), i});
            }
            else z = true;
        }

        lli ans = numeric_limits<lli>::min();
        for(int i = 0; i < n; i++){

            if(a[i] == 0) continue;

            vector<lli> pov, nev, pov2, nev2;
            lli ansi = numeric_limits<lli>::min();
            po.erase({a[i], i});
            ne.erase({abs(a[i]), i});
            po2.erase({a[i], i});
            ne2.erase({abs(a[i]), i});


            int j = 0;
            for(const auto &e: po){
                if(j == 4) break;
                pov.push_back(e.first);
                j++;
            }

            j = 0;
            for(const auto &e: ne){
                if(j == 4) break;
                nev.push_back(e.first);
                j++;
            }


            j = 0;
            for(const auto &e: po2){
                if(j == 4) break;
                pov2.push_back(e.first);
                j++;
            }

            j = 0;
            for(const auto &e: ne2){
                if(j == 4) break;
                nev2.push_back(e.first);
                j++;
            }


            if(pov.size() == 4)
                ansi = max(ansi, a[i] * pov[0] * pov[1] * pov[2] * pov[3]);
            if(nev.size() == 4)
                ansi = max(ansi, a[i] * nev[0] * nev[1] * nev[2] * nev[3]);
            if(pov.size() >= 3 && nev.size() >= 1)
                ansi = max(ansi, a[i] * pov[0] * pov[1] * pov[2] * nev[0] * (-1));
            if(nev.size() >= 3 && pov.size() >= 1)
                ansi = max(ansi, a[i] * nev[0] * nev[1] * nev[2] * pov[0] * (-1));
            if(pov.size() >= 2 && nev.size() >= 2)
                ansi = max(ansi, a[i] * nev[0] * nev[1] * pov[0] * pov[1]);


            if(pov2.size() == 4)
                ansi = max(ansi, a[i] * pov2[0] * pov2[1] * pov2[2] * pov2[3]);
            if(nev2.size() == 4)
                ansi = max(ansi, a[i] * nev2[0] * nev2[1] * nev2[2] * nev2[3]);
            if(pov2.size() >= 3 && nev2.size() >= 1)
                ansi = max(ansi, a[i] * pov2[0] * pov2[1] * pov2[2] * nev2[0] * (-1));
            if(nev2.size() >= 3 && pov2.size() >= 1)
                ansi = max(ansi, a[i] * nev2[0] * nev2[1] * nev2[2] * pov2[0] * (-1));
            if(pov2.size() >= 2 && nev2.size() >= 2)
                ansi = max(ansi, a[i] * nev2[0] * nev2[1] * pov2[0] * pov2[1]);



            if(pov.size() >= 3 && nev.size() >= 1)
                ansi = max(ansi, a[i] * pov2[0] * pov2[1] * pov2[2] * nev[0] * (-1));
            if(pov.size() >= 3 && nev.size() >= 1)
                ansi = max(ansi, a[i] * pov[0] * pov[1] * pov[2] * nev2[0] * (-1));
            if(nev2.size() >= 3 && pov2.size() >= 1)
                ansi = max(ansi, a[i] * nev2[0] * nev2[1] * nev2[2] * pov[0] * (-1));
            if(nev2.size() >= 3 && pov2.size() >= 1)
                ansi = max(ansi, a[i] * nev[0] * nev[1] * nev[2] * pov2[0] * (-1));    
            if(pov2.size() >= 2 && nev2.size() >= 2)
                ansi = max(ansi, a[i] * nev2[0] * nev2[1] * pov[0] * pov[1]);
            if(pov2.size() >= 2 && nev2.size() >= 2)
                ansi = max(ansi, a[i] * nev[0] * nev[1] * pov2[0] * pov2[1]);    


            ans = max(ans, ansi);
        }

        cout << ((z) ? max(ans, 0ll) : ans) << endl;

    }
    
    return 0;
}