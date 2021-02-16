#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int t, n;
pair<lli, int> a[200005];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
        sort(a, a + n);
        int ans = 0;
        lli sum = 0;
        for(int i = 0; i < n;){
            sum += a[i].first;
            int j = i + 1;
            for(; j < n; j++){
                if(sum >= a[j].first) sum += a[j].first;
                else break;
            }
            if(j == n){
                ans = i;
                break;
            }
            else i = j;
        }
        bool r[n] = {false};
        int l = 0;
        for(int i = ans; i < n; i++){
            r[a[i].second] = true;
            l++;
        }
        cout << l << endl;
        for(int i = 0; i < n; i++)
            if(r[i]) cout << i + 1 << " ";
        cout << endl;
    }
    return 0;
}