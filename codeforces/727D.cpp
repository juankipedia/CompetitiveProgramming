# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;

int cnt[6], n;
map<string, int> m = {{"S", 0}, {"M", 1}, {"L", 2}, {"XL", 3}, {"XXL", 4}, {"XXXL", 5}};

int main(){
    for(int i = 0; i < 6; i++) cin >> cnt[i];
    cin >> n;
    string s, t;
    bool ok = true;
    vector<int> p[5];
    int b[n];
    memset(b, -1, sizeof(b));
    for(int i = 0; i < n; i++){
        cin >> s;
        t = "";
        for(int j = 0; j < s.size(); j++)
            if(s[j] == ',') 
                t = s.substr(j + 1, s.size() - 1 - j),
                s = s.substr(0, j);
        if(t == ""){
            if(cnt[m[s]] == 0) ok = false;
            else cnt[m[s]]--;
            b[i] = m[s];
        }
        else{
            if(s == "S" || t == "S") p[0].push_back(i);
            else if(s == "M" || t == "M") p[1].push_back(i);
            else if(s == "L" || t == "L") p[2].push_back(i);
            else if(s == "XL" || t == "XL") p[3].push_back(i);
            else if(s == "XXL" || t == "XXL") p[4].push_back(i);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int pos : p[i]){
            if(cnt[i]) b[pos] = i, cnt[i]--;
            else if(cnt[i + 1]) b[pos] = i + 1, cnt[i + 1]--;
            else ok = false;
        }
    }
    if(!ok){ cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++){
        switch(b[i]){
            case 0:{ cout << "S" << endl; break; }
            case 1:{ cout << "M" << endl; break; }
            case 2:{ cout << "L" << endl; break; }
            case 3:{ cout << "XL" << endl; break; }
            case 4:{ cout << "XXL" << endl; break; }
            case 5:{ cout << "XXXL" << endl; break; }
            default: break;
        }
    }
    return 0;
}