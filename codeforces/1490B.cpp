#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n, a[30000];

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int c[3] = {0};

        for(int i = 0; i < n; i++){
            cin >> a[i];
            c[a[i] % 3]++;
        }
        int N = n / 3;
        int ans = 0;
        for(int i = 2; i >= 0; i--){
            if(c[i] == N) continue;
            if(c[i] > N){
                c[(i + 1) % 3] += c[i] - N;
                ans += c[i] - N;
            }
            if(c[i] < N){
                if(i == 0){
                    c[2] -= N - c[i];
                    ans += N - c[i];
                    c[i] = N;
                }
                else{
                    c[i - 1] -= N - c[i];
                    ans += N - c[i];
                    c[i] = N;
                }
            }
        }
        cout << ans << endl;


    }
    return 0;
}