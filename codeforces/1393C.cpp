#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, ai, cnt[100001], cnti[100001], a[100001];

bool check(int d){
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++){
        if(cnt[i]){
            s.insert({cnt[i], i});
            cnti[i] = cnt[i];
        }
        a[i] = -1;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != -1)
            s.insert({cnti[a[i]], a[i]});
        if(s.empty()) return false;
        auto l = s.end(); l--;
        cnti[l->second]--;
        if(cnti[l->second]){
            if((d + i) >= n)return false;
            a[i + d] = l->second;
        }
        s.erase(l);
    }
    return true;
}

int f(){
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1)/2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo - 1;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++){
            cin >> ai; ai--;
            cnt[ai]++;
        }
        cout << f() << endl;
    
    }
    return 0;
}