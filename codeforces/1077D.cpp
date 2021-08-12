# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

const int MAXN = 200005;
int n, k, s[MAXN], f[MAXN];
bool inserted[MAXN];
vector<pair<int, int>> a;

bool check(int mid){
    int ki = 0, i = 0;
    while(ki < k){
        if(mid > a[i].first) return false;
        ki += a[i].first / mid;
        i++;
        if(i == n){
            if(ki < k) return false;
            else return true;
        }
    }
    return true;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> s[i], f[s[i]]++;
    for(int i = 0; i < n; i++) 
        if(!inserted[s[i]])
            a.push_back({f[s[i]], s[i]}),
            inserted[s[i]] = true;
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    int lo = 0, hi = 200005;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid)) lo = mid;
        else hi = mid - 1;
    }
    //cout << lo << endl;
    int ki = 0, i = 0;
    while(ki < k){
        int c = min(a[i].first / lo, k - ki);
        ki += c;
        for(int j = 0; j < c; j++) cout << a[i].second << " ";
        i++;
    }
    cout << endl;
    return 0;
}