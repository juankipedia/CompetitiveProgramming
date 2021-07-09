# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
 
vector<int> build(string const& s){
    int n = s.size();
    const int alphabet = 256;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for(int i = 0; i < n; i++) cnt[s[i]]++;
    for(int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i < n; i++) p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for(int h = 0; (1 << h) < n; h++){
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << h);
            if(pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for(int i = 0; i < n; i++) cnt[c[pn[i]]]++;
        for(int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for(int i = n-1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for(int i = 1; i < n; i++){
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if(cur != prev)
                classes++;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

// WARNING STRING IS MODIFIED
vector<int> get_suffix_array(string &s){
    s += "$";
    vector<int> sorted_shifts = build(s);
    return sorted_shifts;
}

vector<int> lcp_build(string const &s, vector<int> const &p){
    int n = s.size();
    vector<int> rank(n, 0);
    for(int i = 0; i < n; i++) rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n - 1, 0);
    for(int i = 0; i < n; i++){
        if(rank[i] == n - 1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

int main(){
    io_boost;
    string s, t;
    cin >> s;
    lli n = s.size();
    auto sa = get_suffix_array(s);
    auto lcp = lcp_build(s, sa);
    int N = lcp.size();
    stack<int> st;
    int mini[N];
    mini[N - 1] = N - 1;
    st.push(N - 1);
    for(int i = N - 2; i >= 0; i--){
        while(!st.empty()){
            if(lcp[st.top()] < lcp[i]){
                mini[i] = st.top();
                st.push(i);
                break;
            }
            st.pop();
        }
        if(st.empty()) mini[i] = i, st.push(i);
    }
    lli dp[N];
    dp[N - 1] = lcp[N - 1];
    for(lli i = N - 2; i >= 0; i--){
        if(mini[i] == i) dp[i] = (N - i) * lcp[i];
        else dp[i] = (mini[i] - i) * lcp[i] + dp[mini[i]];
    }
    lli ans = 0;
    for(lli i = 0; i < N; i++) ans += dp[i];
    cout << ans + (n * (n + 1) / 2) << endl;
    return 0;
}
