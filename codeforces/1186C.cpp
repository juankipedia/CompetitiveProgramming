# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

string a, b;

int main(){
    cin >> a >> b;
    int sum[a.size() + 1] = {0};
    for(int i = 0; i < a.size(); i++){
        sum[i + 1] = sum[i];
        if(a[i] == '1') sum[i + 1]++;
    }
    int cntb = 0;
    for(int i = 0; i < b.size(); i++)
        if(b[i] == '1') cntb++;

    int ans = 0;
    for(int i = b.size(); i <= a.size(); i++){
        int cnta = sum[i] - sum[i - b.size()];
        if((cnta % 2) == (cntb % 2)) ans++;
    }
    cout << ans << endl;
    return 0;
}