# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        int cnt[10] = {0}, color[n], first = -1;
        for(int i = 0; i < n; i++) cnt[s[i] - '0']++;
        for(int i = 0; i < n; i++){
            bool f = false;
            for(int j = 0; j <= 9; j++)
                if((first != -1 && first < (s[i] - '0')) || cnt[j] && j < (s[i] - '0')) f = true;
            if(f){
                color[i] = 2;
                if(first == -1) first = s[i] - '0';
            }
            else color[i] = 1;
            //cout << color[i] << endl;
            cnt[s[i] - '0']--;
        }
        vector<int> o, t, r;
        for(int i = 0; i < n; i++){
            if(color[i] == 1) o.push_back(s[i] - '0');
            else t.push_back(s[i] - '0');
        }
        for(int e : o) r.push_back(e);
        for(int e : t) r.push_back(e);
        bool ok = true;
        for(int i = 0; i < n - 1; i++)
            if(r[i] > r[i + 1]) ok = false;
        if(ok){
            for(int i = 0; i < n; i++) cout << color[i];
            cout << endl;
        }
        else cout << "-" << endl;
    }
    return 0;
}