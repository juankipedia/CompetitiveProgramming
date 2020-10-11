#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const lli oo = numeric_limits<lli>::max();
int n, U, V;
string vs, us, in;
const int c_number = 9;
lli ans, m[10000][c_number + 1];

lli color(vector<int> g[], int v, int p, int pc){
    if(m[v][pc] != -1) return m[v][pc];
    lli ans = oo;
    for(int i = 1; i <= c_number; i++){
        if(pc == i) continue;
        lli sum = 0;
        sum += i;
        for(int u: g[v])
            if(u != p) sum += color(g, u, v, i);
        ans = min(ans, sum);
    }
    return m[v][pc] = ans;
}

int main(){
    io_boost;
    while(cin >> n && n != 0){
        vector<int> g[n];
        cin.get();
        for(int i = 0; i < n; i++){
            getline(cin, in, '\n');
            us = "";
            int l = 0;
            for(char c: in){
                if(c == ':'){
                    U = stoi(us);
                    break;
                }
                us += c;
                l++;
            }
            vs = "";
            l += 2;
            for(; l < in.size(); l++){
                if(in[l] == ' '){
                    V = stoi(vs);
                    g[U].push_back(V);
                    g[V].push_back(U);
                    vs = "";
                }
                else vs += in[l];
            }
            if(vs != ""){V = stoi(vs); g[U].push_back(V); g[V].push_back(U);}
        }
        ans = oo;
        memset(m, -1, sizeof(m));
        for(int i  = 1; i <= c_number; i++) ans = min(color(g, 0, -1, i), ans);
        cin.get();
        cout << ans << endl;
    }
    return 0;
}