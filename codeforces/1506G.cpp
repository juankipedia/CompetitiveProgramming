# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string s;

string filter(const string &s, char c){
    bool f = false;
    string r = "";
    for(char cc : s){
        if(cc  != c && f) r += cc;
        else if(cc == c) f = true;
    }
    return r;
}

int cnt(const string &s){
    bool chars[26] = {false};
    for(char c : s) chars[c - 'a'] = true;
    int ans = 0;
    for(int i = 0; i < 26; i++)
        if(chars[i]) ans++;
    return ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        set<int> ss;
        for(int i = 0; i < s.size(); i++) ss.insert(s[i]);
        int m = ss.size();
        string ans = "";
        while(m > 0){
            char max_c = 0;
            for(char c: ss)
                if(cnt(filter(s, c)) == m - 1) max_c = c;
            ans += max_c;
            s = filter(s, max_c);
            ss.erase(max_c);
            m--;
        }

        cout << ans << endl;
    }
    return 0;
}