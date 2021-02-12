#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int n;
pair<int, string> p[3005];
int h[3005];
int main(){
    cin >> n;
    string name;
    for(int i = 0; i < n; i++){
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    bool ok = true;
    for(int i = 0; i < n; i++) h[i] = 1;
    for(int i = n - 1; i >= 0; i--){
        if(i - p[i].first < 0){
            ok = false;
            break;
        }
        for(int j = i - 1; j >= 0; j--){
            if(p[i].first > p[j].first){
                h[j]++;
                p[i].first--;
            }
        }
    }
    if(!ok) cout << -1 << endl;
    else{
        for(int i = 0; i < n; i++) cout << p[i].second << " " << h[i] << endl;
    }
    return 0;
}