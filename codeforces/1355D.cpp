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

int n, s, a[1000000];
bool sa[1000001];

int main() {
    cin >> n >> s;
    int j = 0;
    for(int i = 1; i < n; i++){
        j ++;
        sa[j] = true;
    }
    for(int i = s - (n - 1); i < s; i++)
        sa[i] = true;

    bool r = false;
    int ans;
    for(int i = 1; i < s; i ++){
        if(!sa[i]) {r = true; ans = i; break;}
    }
    if(r){
        cout << "YES" << endl;
        for(int i = 0; i < n - 1; i++) cout << 1 << " ";
        cout << s - (n - 1) << endl;
        cout << ans << endl; 
    }
    else cout << "NO" << endl;
    return 0;
}