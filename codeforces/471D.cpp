#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, w;
lli txt[200000], p[200000], a[200000], b[200000];
int lps[200000];

void LPS(){
    int j = 1, i = 0;
    while(j < w){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if( i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

int main(){
    io_boost;
    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < w; i++) cin >> b[i];
    for(int i = 1; i < w; i++) p[i - 1] = b[i] - b[i - 1];
    for(int i = 1; i < n; i++) txt[i - 1] = a[i] - a[i - 1];
    n--; w--;
    if(n == 0 && w == 0){
        cout << 1 << endl;
        return 0;
    }
    else if(w == 0){
        cout << n + 1 << endl;
        return 0;
    }
    else if(n == 0){
        cout << 0 << endl;
    }
    LPS();
    int ans = 0;
    int i = 0, j = 0;
    lli offset = 0;
    while(i < n){
        if(txt[i] == p[j]){j++; i++;}
        if(j == w){
            ans++;
            j = lps[j - 1];
        }
        else if(i < n && p[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    cout << ans << endl;
    return 0;
}