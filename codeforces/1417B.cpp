#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli T, a[100000], e[100000];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> T;

        for(int i = 0; i < n; i++){ cin >> a[i]; e[i] = a[i];};
        sort(a, a + n);
        set<lli> s, c, d;

        for (int i = 0; i < n; i++){
            lli temp = T - a[i];
            if (s.find(temp) != s.end()){
                c.insert(a[i]); d.insert(temp);
            }
            s.insert(a[i]);
        }
        
        int b[n];
        for(int i = 0; i < n; i++){
            if(c.find(e[i]) != c.end() && d.find(e[i]) == d.end()) b[i] = 0;
            else if(c.find(e[i]) == c.end() && d.find(e[i]) != d.end()) b[i] = 1;
            else if(c.find(e[i]) != c.end() && d.find(e[i]) != d.end()) b[i] = -1;
            else b[i] = 0;
        }
        bool w = true;
        for(int i = 0; i < n; i++){
            if(b[i] == -1 && w){ b[i] = 0; w = false; }
            else if(b[i] == -1 && !w){ b[i] = 1; w = true; }
        }
        for(int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}