# include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n;
 
string p = "haha";
int lps[10];
 
void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}
 
lli find_pattern(const string &txt){
    LPS();
    lli ans = 0;
    int i = 0, j = 0;
    while(i < txt.size()){
        if(txt[i] == p[j]){j++; i++;}
        if(j == p.size()){
            ans++;
            j = lps[j - 1];
        }
        else if(i < txt.size() && p[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return ans;
}

struct Value{
    string b, e;
    lli cnt = 0;
    Value(string s = ""){
        cnt = find_pattern(s);
        b = e = s;
        cut();
    }
    void cut(){
        if(b.size() > 3) b = b.substr(0, 3);
        if(e.size() > 3) e = e.substr(e.size() - 3);
    }
};

void set_value(Value &v1, Value &v2, Value &v){
    v.cnt = v1.cnt + v2.cnt;
    v.cnt += find_pattern(v1.e + v2.b);
    v.b = v1.b + v2.b;
    v.e = v1.e + v2.e;
    v.cut();
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        string var, op, var1, var2, val;
        map<string, Value> m;
        for(int si = 0; si < n; si++){
            cin >> var >> op;
            if(op == ":="){
                cin >> val;
                m[var] = Value(val);
            }
            else{
                cin >> var1  >> op >> var2;
                set_value(m[var1], m[var2], m[var]);
            }
        }
        
        cout << m[var].cnt << endl;
    }
    return 0;
}