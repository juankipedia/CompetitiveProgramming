#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int n;
string s;
int main() {
    cin >> n;
    cin >> s;
    stack<int> st;
    int cnt = 0;
    bool ok = true;
    int ans = 0, j = 0;
    for(int i = 0; i < n; i++){
        if(cnt == 0 and !ok){
            ans += i - j;
            j = i;
            ok = true;
        }
        else if(cnt == 0) j = i;
        if(s[i] == '(') cnt ++;
        else if(cnt == 0){ok = false; cnt --;}
        else cnt--;
    }
    if(cnt == 0 and ok)
        cout << ans << endl;
    else if(cnt == 0 and !ok)
        cout << ans + n - j << endl;
    else cout << -1 << endl;
    return 0;
}