#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
char lv[26], num[10];
string w[15];
bool l[26];

struct Node{
    char c;
    int num;
    bool f;
} c[15];
int nodes = 0;

bool visited[10];

bool check(){
    lli s = 0;
    for(int i = 0; i < n - 1; i++){
        lli si = 0;
        for(int j = 0; j < w[i].size(); j++)
            si = si * 10 + lv[w[i][j] - 'A'];
        s += si;
    }
    lli si = 0;
    for(int j = 0; j < w[n - 1].size(); j++) si = si * 10 + lv[w[n - 1][j] - 'A'];
    return si == s;
}

lli go(int pos){
    if(pos == nodes) return check();
    lli ans = 0;
    for(int i = 0; i <= 9; i++){
        if(c[pos].f && i == 0) continue;
        if(visited[i]) continue;
        c[pos].num = i;
        visited[i] = true;
        lv[c[pos].c - 'A'] = i;
        ans += go(pos + 1);
        visited[i] = false;
    }
    return ans;
}

int main(){
    io_boost;
    while(cin >> n){
        memset(l, false, sizeof(l));
        nodes = 0;
        for(int i = 0; i < 15; i++) c[i].f = false;
        for(int i = 0; i < n; i++){
            cin >> w[i];
            for(int j = 0; j < w[i].size(); j++){
                int cc = w[i][j] - 'A';
                if(!l[cc]) c[nodes++].c = w[i][j];
                l[cc] = true;
            }
            for(int j = 0; j < nodes; j++)
                if(c[j].c == w[i][0]) c[j].f = true;
        }
        // for(int i = 0; i < nodes; i++) cout << c[i].c << " ";
        // cout << endl;
        cout << go(0) << endl;
    }


    return 0;
}