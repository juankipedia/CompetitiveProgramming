# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 2e5 + 5;
int t, n, m;
lli a[MAXN], b[MAXN];

int solve(vector<lli> &A, vector<lli> &B){
    int cnt = 0;
    set<lli> s;
    for(lli e: B) s.insert(e);
    for(lli e: A) if(s.count(e)) cnt++;
    A.push_back(1e9 + 5);
    //B.push_back(1e9 + 5);
    int ap = 0, bp = 0, sz = 0;
    int n = A.size(), m = B.size();
    lli pos = A[0];
    lli ans = cnt;
    while(ap < n && bp < m){
        while(bp < m && B[bp] <= pos) bp++;
        if(B[bp] >= A[ap]){
            pos = A[ap];
            while(pos == A[ap]){
                if(s.count(A[ap])) cnt--;
                pos++;
                ap++;
                sz++;
            }
        }
        else{
            pos = B[bp];
            bp++;
        }
        lli r = pos, l = pos - sz + 1;
        l = lower_bound(B.begin(), B.end(), l) - B.begin();
        if(B[l] <= pos){
            r = upper_bound(B.begin(), B.end(), r) - B.begin();
            r--;
            ans = max(ans, cnt + r - l + 1);
        }
    }
    return ans;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        
        for(int i = 0; i < m; i++) cin >> b[i];
        int ipa = upper_bound(a, a + n, 0) - a, ipb = upper_bound(b, b + m, 0) - b;
        vector<lli> A, B;
        int ans = 0;
        for(int i = ipa; i < n; i++) A.push_back(a[i]);
        for(int i = ipb; i < m; i++) B.push_back(b[i]);

        ans = solve(A, B);
        A.clear(); B.clear();
        for(int i = ipa - 1; i >= 0; i--) A.push_back(a[i] * -1);
        for(int i = ipb - 1; i >= 0; i--) B.push_back(b[i] * -1);
        ans += solve(A, B);

        cout << ans << endl;
    }
    return 0;
}