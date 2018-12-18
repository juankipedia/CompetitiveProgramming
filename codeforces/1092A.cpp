#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main() {
    ui t, n, k;
    
    string s;
    cin >> t;
    while(t--){
        cin >> n >> k;
        s = "";
        for (ui i = 0; i < n; i += k){
            char c = 'a';
            for (ui i = 0; i < k; ++i)
                s += c + i;
            if(n - s.length() < k){
                c = 'a';
                ui r = (n - s.length());
                for (int i = 0; i < r; i++){
                    s += c + i;
                }
                break;
            }
        }
        cout << s << endl;
    }
    return 0;
}