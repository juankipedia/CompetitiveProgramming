#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

vector<lli> d;
lli N;
void divisors(lli n){  
    for(lli i = 1; i * i <= n; i++)
        if(n % i == 0)
            if(n / i == i) d.push_back(i); 
            else d.push_back(i), d.push_back(n / i);
}
int main(){
    io_boost;
    cin >> N;
    divisors(N);
    sort(d.begin(), d.end());
    vector<lli> ans;
    for(lli e: d)
        if(N % (e * 2) == 0) ans.push_back(e);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}