# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n;

int main(){
    cin >> n;
    vector<int> res;
    lli p = 1;
    for(int i = 1; i < n; i++)
        if(std::__gcd(n, i) == 1){
            res.push_back(i);
            p = p * i % n;
        }
    if(p != 1) res.pop_back();
    cout << res.size() << endl;
    for(int c: res) cout << c << " ";
    cout << endl;
    return 0;
}