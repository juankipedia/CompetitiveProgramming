#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
string s;
vector<int> p, a;

bool go(int peckman, int l, int r, int t){
    if(r < peckman) return (peckman - l) <= t;
    if(peckman < l) return (r - peckman) <= t;
    return (min(r - peckman, peckman - l) + r - l) <= t;
}

bool check(int t){
    int r = 0;
    for(int peckman: p){
        if(r == a.size()) return true;
        int l = r;
        while(r < a.size() && go(peckman, a[l], a[r], t)) r++;
    }
    return r == a.size();
}


int main(){
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
        if(s[i] == 'P') p.push_back(i);
        else if(s[i] == '*') a.push_back(i);
    int lo = 0, hi = 4 * n;
    while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;   
    }
    cout << lo << endl;
    return 0;
}