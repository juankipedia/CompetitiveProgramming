# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

lli N;

int main(){
    cin >> N;
    lli cnt = 0;
    string s = "1";
    while(true){
        string aux = s + s;
        if(stoll(aux) > N) break;
        cnt++;
        lli v = stoll(s);
        v++;
        s = to_string(v);
    }
    cout << cnt << endl;
    return 0;
}