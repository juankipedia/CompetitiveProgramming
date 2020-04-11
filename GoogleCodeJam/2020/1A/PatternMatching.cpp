#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int n, ti, t, pos, pos2;
string p, s, l, r, lr, rr;

int main() {
    io_boost;
    cin >> t;
    for(int ti = 1; ti <= t; ti++){
        cin >> n;
        rr = lr = "";
        while(n--){
            cin >> s;
            if(rr == "*" || lr == "*") continue;
            bool R = false;
            r = l = "";
            for(const char &c: s){
                if(c == '*'){
                    R = true;
                    continue;
                }
                if(R) r += c;
                else l += c;
            }
            //cout << l << " " << r << endl;
            pos = rr.rfind(r);
            pos2 = r.rfind(rr);
            if(rr == "") rr = r;
            else if(pos != std::string::npos && pos + r.size() == rr.size()) rr = rr;
            else if(pos2 != std::string::npos && pos2 + rr.size() == r.size()) rr = r;
            else rr = "*";
            
            pos = lr.find(l);
            pos2 = l.find(lr);
            if(lr == "") lr = l;
            else if(pos != std::string::npos && pos == 0) lr = lr;
            else if(pos2 != std::string::npos && pos2 == 0) lr = l;
            else lr = "*";
        }

        if(rr == "*" || lr == "*") cout << "Case #" << ti << ": " << "*" << endl;
        else cout << "Case #" << ti << ": " << lr + rr << endl;
    }
    return 0;
}