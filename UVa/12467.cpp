#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, np;
string s, w;
int lps[3000000];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int j = np + 1, i = 0;
    while(j < n){
        if(s[i] == s[j]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }



    int maxi = 0, pos = n;
    for(int k = np + 1; k < n; k++)
        if(lps[k] > maxi) pos = k, maxi = lps[k];

    for(int k = pos, w = 0; w < maxi; k--, w++) cout << s[k];
    cout << endl;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> s;
        w = "";
        np = s.size();
        for(int i = np - 1; i >= 0; i--) w += s[i];
        s += "#" + w;
        n = s.size();
        LPS();
    }
    
    return 0;
}