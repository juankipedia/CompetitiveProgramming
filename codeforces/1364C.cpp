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

int n, a[100001], b[100001], e[100001];

int main() {
    cin >> n;
    memset(b, -1, sizeof(b));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != a[i - 1]){
            b[i] = a[i - 1];
            e[b[i]] = 1;
        }
    }

    e[a[n]] = 1;
    int m = 0;
    for(int i = 1; i <= n; i++){
        while(e[m]) m++;
        if(b[i] == -1){
            b[i] = m;
            e[m] = 1;
        }
        cout << b[i] <<  " ";
    }

    return 0;
}