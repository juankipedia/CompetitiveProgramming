# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, a[200005][2];
bool in[200005];

int main(){
    cin >> n;
    vector<int> ans;
    for(int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
    int i = 1;
    while(!in[a[i][0]] || !in[a[i][1]]){
        ans.push_back(i);
        in[i] = true;
        if(a[a[i][0]][0] == a[i][1] || a[a[i][0]][1] == a[i][1]){
            ans.push_back(a[i][0]);
            in[a[i][0]] = true;
            i = a[i][1];
        }
        else{
            ans.push_back(a[i][1]);
            in[a[i][1]] = true;
            i = a[i][0];
        }
    }
    if(!in[i]) ans.push_back(i);
    for(int p: ans) cout << p << " ";
    cout << endl;
    return 0;
}