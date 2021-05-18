# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
lli a[50], b1[50], b2[50];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        lli s = 0, s1 = 0, s2 = 0;
        for(int i = 0, ai; i < n; i++) cin >> a[i], s += a[i];
        for(int i = 0; i < n; i++)
            if(i % 2) b2[i] = a[i], b1[i] = 1;
            else b1[i] = a[i], b2[i] = 1;
        for(int i = 0; i < n; i++) s1 += abs(a[i] - b1[i]), s2 += abs(a[i] - b2[i]);
        if(s1 < s2) for(int i = 0; i < n; i++) cout << b1[i] << " ";
        else for(int i = 0; i < n; i++) cout << b2[i] << " ";
        cout << endl;
    }
    return 0;
}