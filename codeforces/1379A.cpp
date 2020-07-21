#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const string t = "abacaba";
int q, n;
string s;


int cnt(string &s){ 
    int res = 0; 
    for(int i = 0; i <= n - 7; i++){
        int j; 
        for(j = 0; j < 7; j++) 
            if(s[i+j] != t[j]) break;
        if(j == 7){ 
           res++; 
           j = 0; 
        } 
    } 
    return res; 
}


int main(){
    io_boost;
    cin >> q;
    while(q--){
        cin >> n;
        cin >> s;
        int c = cnt(s);
        if(c == 1){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) 
                if(s[i] == '?') cout << 'z';
                else cout << s[i];
            cout << endl;
        }
        else if(c > 1) cout << "NO" << endl;
        else{
            vector<int> vi, vj;
            for(int i = 0, j = 6; j < n; i++, j++){
                bool ok = true;
                for(int l = 0; l < 7; l++)
                    if(s[i + l] != t[l] && s[i + l] != '?')
                        ok = false;
                if(ok){vi.push_back(i); vj.push_back(j);}
            }
            if(vi.size()){
                int i, j;
                string r;
                bool f = false;
                for(int l = 0; l < vi.size(); l++){
                    i = vi[l]; j = vj[l]; r = "";
                    for(int ii = 0; ii < i; ii++)
                        if(s[ii] == '?') r += "z";
                        else r += s[ii];
                    r += t;
                    for(int ii = j + 1; ii < n; ii++)
                        if(s[ii] == '?') r += "z";
                        else r += s[ii];
                    if(cnt(r) == 1){
                        f = true;
                        break;
                    }
                }
                if(f) cout << "YES\n" << r << endl;
                else
                    cout << "NO" << endl;
            }
            else cout << "NO" << endl;
        }
    }
    
    return 0;
}