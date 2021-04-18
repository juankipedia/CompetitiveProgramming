# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main(){
    io_boost;
    int t, a, b, c;
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        string as = "1";
        string bs = "1";
        for(int i = 1; i < a; i++) as += '0';
        for(int i = 1; i < b; i++) bs += '0';
        if(c < min(a, b)){
            if(a > b) as[a - c] = '1';
            else bs[b - c] = '1';
        }
        cout << as << " " << bs << endl;
    }
    

    return 0;
}