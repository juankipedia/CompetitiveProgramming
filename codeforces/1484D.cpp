# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[100005];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        int prv[n], nxt[n];
        for(int i = 0, j = -1, k = 1; i < n; i++, j++, k++) prv[i] = j, nxt[i] = k;
        nxt[n - 1] = 0;
        prv[0] = n - 1;
        set<int> s;
        for(int i = 0; i < n; i++)
            if(gcd(a[prv[i]], a[i]) == 1) s.insert(i);

        vector<int> ans;
        for(int i = 0; i < n && !s.empty(); ){
            auto it = s.upper_bound(i);
            if(it == s.end()) it = s.begin();
            int j = *it;
            ans.push_back(j);
            s.erase(j);
            int next = nxt[j], prev = prv[j];
            if(next == j) break;
            s.erase(next);
            nxt[prev] = next;
            prv[next] = prev;
            if(gcd(a[prev], a[next]) == 1) s.insert(next);


            i = next;
        }
        cout << ans.size() << " ";
        for(int e: ans) cout << e + 1 << " ";
        cout << endl;

    }
    return 0;
}