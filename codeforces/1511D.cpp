# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k;

int main(){
    cin >> n >> k;
    if(n == 1){
        cout << "a" << endl;
        return 0;
    }
    string s = "a";
    int j = 0, w = 1, c = 0;
    int len = 1;
    while(len < n){
        if(j == k && c == k){
            j = 0; w = 1; c = 0;
            s += "a";
            len++;
        }
        if(w == k){
            w = c + 1;
            c++;
            j++;
        }
        if(j != k && len < n) s += j + 'a', len++;
        if(w != j && len < n) s += w + 'a', len++;
        w++;
    }
    cout << s << endl;
    return 0;
}