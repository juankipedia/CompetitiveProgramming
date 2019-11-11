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

ulli n;
pair<ulli, ulli> a[100000];
int main() {
    cin >> n;
    for(ulli i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    ulli p = 0, c = 0;
    for(ulli i = 0; i < n; i++){
        while(a[i].first > p and c > 1){
            c = (c + 3) / 4; 
            p++;
        }
        p = a[i].first + 1;
        a[i].second  = max(a[i].second, c);
        c = (a[i].second + 3)/4;
    }
    if(c == 1){cout << p << endl; return 0;}
    while(c != 1){
        p++;
        c = (c + 3) / 4;
    }
    cout << p << endl;
    return 0;
}