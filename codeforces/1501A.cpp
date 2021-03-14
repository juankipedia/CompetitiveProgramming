# include <bits/stdc++.h>
using namespace std;
# define endl "\n"
int T, N;

vector<int> a, b, t;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        a.resize(N); b.resize(N); t.resize(N);
        for(int i = 0; i < N; i++){
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < N; i++){
            cin >> t[i];
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(i == 0) ans = t[i] + a[i];
            else ans += a[i] - b[i - 1] + t[i];
            
            if(i == N - 1) break;
            
            ans += (b[i] - a[i] + 1) / 2;
            ans = max(ans, b[i]);
        }
        cout << ans << endl;
    }
    return 0;
}