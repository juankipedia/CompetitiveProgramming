# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, a[200000];
map<int, pair<int, int>> m;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int sum = a[i] + a[j];
            if(m.count(sum) && m[sum].second  != i && m[sum].second != j && m[sum].first != i){
                cout << "YES" << endl;
                cout << i + 1 << " " << j + 1 << " " << m[sum].first + 1 << " " << m[sum].second + 1 << endl;
                return 0;
            }
            else m[sum] = {i, j};
        }
    }
    cout << "NO" << endl;
    return 0;
}