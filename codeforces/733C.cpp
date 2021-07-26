# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int n, b[505], a[505], k, s[505];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> k;
    for(int i = 0; i < k; i++) cin >> b[i];
    s[0] = a[0];
    for(int i = 1; i < n; i++) s[i] = s[i - 1] + a[i];
    int l = 0;
    vector<int> P, d;
    for(int i = 0; i < k; i++){
        if(l == n){ cout << "NO" << endl; return 0; };
        int p = lower_bound(s + l, s + n, b[i]) - s;
        set<int> freq;
        if(p == n || s[p] > b[i]){ cout << "NO" << endl; return 0; }
        for(int j = l; j <= p; j++) freq.insert(a[j]);
        if(freq.size() == 1 && l != p ){cout << "NO" << endl; return 0; };
        
        int pos = -1, maxi = *freq.rbegin();
        vector<int> L, R;
        for(int j = l + 1; j < p; j++){
            if(a[j] == maxi && (a[j] != a[j + 1] || a[j] != a[j - 1])){
                pos = j;
                break;
            }
        }
        if(a[l] == maxi && pos == -1) pos = l;
        else if(a[p] == maxi && pos == -1) pos = p;
        for(int j = l; j <= p; j++)
            if(j < pos) L.push_back(a[j]);
            else if(j > pos) R.push_back(a[j]);
        for(int j = 0; j < (p - l); j++){
            if(!L.empty() && (*L.rbegin()) < a[pos]){
                a[pos] += (*L.rbegin());
                P.push_back(L.size() + 1 + i);
                d.push_back(0);
                L.pop_back();
            }
            if(!R.empty() && (*R.begin()) < a[pos]){
                a[pos] += (*R.begin());
                P.push_back(L.size() + 1 + i);
                d.push_back(1);
                R.erase(R.begin());
            }
        }
        l = p + 1;
        b[i + 1] += b[i];
    }
    if(l != n){ cout << "NO" << endl; return 0;}
    cout << "YES" << endl;
    for(int w = 0; w < P.size(); w++) cout << P[w] << " " << (d[w] == 1? "R" : "L") << endl;
    return 0;
}