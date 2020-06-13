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

int n, a[200000], b[200000], m[200001], c[200001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> b[i];
        m[b[i]] = i;
    }

    for(int i = 0; i < n; i++){
        int pos = m[a[i]];
        if(pos > i) c[i + n - pos]++;
        else c[i - pos]++;
    }
    int maxi = 0;
    for(int i = 0; i <= n; i++)
        maxi = max(maxi, c[i]);
    cout << maxi << endl;
    return 0;
}