#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;
pair<int, int> f[3];
string s, r;

int main(){
    cin >> n;
    while (n--){
        cin >> s;
        r = "";
        f[0].second = 0; f[1].second = 1; f[2].second = 2;
        f[0].first = 0; f[1].first = 0; f[2].first = 0;
        for(const char &c: s){
            if(c == 'R') f[0].first++;
            else if(c == 'P') f[1].first++;
            else f[2].first++;
        }
        sort(f, f + 3, std::greater<pair<int,int>>());
        for(int i = 0; i < s.size(); i++)
            if(f[0].second == 0) r += 'P';
            else if(f[0].second == 1) r += 'S';
            else r += 'R';
        cout << r << endl;
    }
    
    return 0;
}