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
const lli INF = numeric_limits<lli>::max();
int t, n;
lli a[100000], mini, maxi, k;

int main() {
    cin >> t;
    while(t--){
        cin >> n;
        mini = INF; maxi = -1;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++){
            if(a[i + 1] != -1 && a[i] == -1){
                mini = min(mini, a[i + 1]);
                maxi = max(maxi, a[i + 1]);
            }
        }
        for(int i = 1; i < n; i++){
            if(a[i - 1] != -1 && a[i] == -1){
                mini = min(mini, a[i - 1]);
                maxi = max(maxi, a[i - 1]);
            }
        }
        if(maxi == -1){
            maxi = 0;
            for(int i = 0; i < n - 1; i++)
                maxi = max(maxi, abs(a[i] - a[i + 1]));
            
            cout << maxi << " " << 0 << endl;
            continue;
        }

        k = (maxi - mini) / 2  + mini;
        maxi = 0;
        
        for(int i = 0; i < n - 1; i++){
            if(a[i] == -1) a[i] = k;
            if(a[i + 1] == -1) a[i + 1] = k;
            maxi = max(maxi, abs(a[i] - a[i + 1]));
        }
        cout << maxi << " " << k << endl;
    }
    return 0;
}