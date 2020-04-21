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
bool p;
int t, n;
lli a[200000], sum, maxi;
int main() {
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> a[i];
        p = a[0] > 0;
        sum = 0;
        maxi = a[0];
        for(int i = 0; i < n - 1; i++){
            if((p && a[i] > 0) || (!p && a[i] < 0)) maxi = max(a[i], maxi);
            else if((p && a[i] < 0) || (!p && a[i]) > 0){
                sum += maxi;
                maxi = a[i];
                p = !p;
            }
        }

        if(p && a[n - 1] > 0 || !p && a[n - 1] < 0){
            maxi = max(a[n - 1], maxi); sum += maxi;
        }
        else if(p && a[n - 1] < 0 || !p && a[n - 1] > 0){
            sum += maxi;
            sum += a[n - 1];
        }

        cout << sum << endl;
    }
    return 0;
}