# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

const int MAXN = 1e5 + 5;
int N, p[MAXN],  hl[MAXN], hr[MAXN];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 1, j = N - 2; i < N; i++, j--){
        if(p[i] > p[i - 1]) hl[i] = hl[i - 1] + 1;
        if(p[j] > p[j + 1]) hr[j] = hr[j + 1] + 1;
    }

    int maxi = 0;
    for(int i = 0; i < N; i++)
        maxi = max({maxi, hl[i], hr[i]});

    int cnt = 0;
    for(int i = 0; i < N; i++)
        if(hl[i] == maxi || hr[i] == maxi) cnt++;
    
    if(cnt != 1){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 1; i < N - 1; i++)
        if(p[i] > p[i - 1] && p[i] > p[i + 1]){
            if((hl[i] == maxi && hr[i] == maxi) && maxi % 2 == 0)
                ans++;
        }
    cout << ans << endl;

    return 0;
}