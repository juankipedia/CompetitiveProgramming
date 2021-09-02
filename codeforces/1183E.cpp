# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

lli n, k, ans;
string s;

void bfs(){
    set<string> visited;
    queue<string> q;
    q.push(s);
    lli cnt = 0, sum = 0;
    string v;
    while(!q.empty()){
        string t = q.front();
        q.pop();
        cnt++;
        sum += t.size();
        if(cnt == k){
            ans = n * k - sum;
            return;
        }
        for(int i = 0; i < t.size(); i++){
            v = t.substr(0, i);
            if((i + 1) < n) v += t.substr(i + 1, t.size() - i - 1);
            if(!visited.count(v)) visited.insert(v), q.push(v);
        }
    }
    ans = -1;
}

int main(){
    io_boost;
    cin >> n >> k >> s;
    bfs();
    cout << ans << endl;
    return 0;
}