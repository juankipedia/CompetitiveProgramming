# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m, a[40];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> l, r;

    for(int i = 0; i < (1 << (n / 2)); i++){
        int sum = 0;
        for(int j = 0; j < n / 2; j++)
            if(i & (1 << j)) sum = (sum + a[j]) % m;
        l.push_back(sum);
    }
    int c = n - (n / 2);
    for(int i = 0; i < (1 << c); i++){
        int sum = 0;
        for(int j = n / 2; j < n; j++)
            if(i & (1 << (j - n / 2))) sum = (sum + a[j]) % m;
        r.push_back(sum);
    }
    sort(r.begin(), r.end());
    int ans = 0;
    for(int s : l){
        int c = m - s;
        int p = lower_bound(r.begin(), r.end(), c) - r.begin();
        p--;
        ans = max({ans, s, (s + r[p]) % m}); 
    }
    cout << max(ans, *max_element(r.begin(), r.end())) << endl;
    return 0;
}