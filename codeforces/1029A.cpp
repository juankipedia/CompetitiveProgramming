#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, K;
string s, t;
int main(){
    cin >> n >> K;
    cin >> t;
    int i = 1, k = -1;
    for(; i < n; i++){
        if(t[0] == t[i]){
            int j = i;
            k = 0;
            while(k < n && j < n && t[k] == t[j]) j++, k++;
            if(j == n) break;
            else k = -1;
        }
    }
    s = "";
    s += t;
    K--;
    if(k != -1) t = t.substr(k, n - k);

    while(K--){s += t;};
    cout << s << endl;
    return 0;
}