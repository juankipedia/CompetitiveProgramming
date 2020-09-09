#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[1000], ans[1000];
bool m[1000];

int GCD(int a, int b){
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        int gcd = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            m[i] = false;
            if(gcd < a[i]){
                maxi = i;
                gcd = a[i];
            }
        }
        int i = 1;
        m[maxi] = true;
        ans[0] = a[maxi];
        while(i < n){
            int gcdi = 0;
            maxi = 0;
            for(int j = 0; j < n; j++){
                if(!m[j]){
                    int gcdj = GCD(gcd, a[j]);
                    if(gcdj > gcdi){
                        maxi = j;
                        gcdi = gcdj;
                    }
                }
            }
            ans[i] = a[maxi];
            m[maxi] = true;
            gcd = gcdi;
            i++;
        }
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}