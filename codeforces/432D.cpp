#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
const int TRIE_LEN = 100005;

int t;
string s;
int lps[TRIE_LEN], freq[TRIE_LEN];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = s.size(), j = 1, i = 0;
    while(j < n){
        if(s[j] == s[i]) lps[j++] = ++i;
        else if( i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
    for(int i = 0; i < n; i++) freq[lps[i]]++;
    for(int i = n - 1; i > 0; i--) freq[lps[i - 1]] += freq[i];
    for(int i = 0; i < n; i++) freq[i]++;
    vector<int> ans;
    int cur = lps[n - 1];
    while(cur > 0){
        ans.push_back(cur);
        cur = lps[cur - 1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() + 1 << endl;
    for(int ps: ans) cout << ps << " " << freq[ps] << endl;
    cout << s.size() << " " << 1 << endl;
}

int main(){
    io_boost;
    cin >> s;
    LPS();
    return 0;
}