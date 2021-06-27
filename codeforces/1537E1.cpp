# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, k;
string s;

int main(){
    cin >> n >> k >> s;
    n = 2 * n;
    s = s + s;
    int p = n, l = 0;
    for(int i = 1; i < n; i++){
        if(s[l] < s[i]){
            if(l != 0) p = i - l;
            else p = i;
            break;
        }
        else if(s[l] == s[i]) l++;
        else l = 0;
    }
    s = s.substr(0, p);
    while(s.size() < k) s += s;
    cout << s.substr(0, k) << endl;
    return 0;
}