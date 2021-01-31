#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int n, m;
ulli k;
int A[100], B[100], C[100], D[100];

int main(){
    io_boost;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> C[i] >> D[i];
        C[i]--; D[i]--;
    }
    int ans = 0;
    for(ulli i = 0; i < (1ULL << k); i++){
        bool dish[n] = {false};
        for(ulli j = 0; j < k; j++){
            if(i & (1ULL << j)) dish[D[j]] = true;
            else dish[C[j]] = true;
        }
        int cur = 0;
        for(int l = 0; l < m; l++)
            if(dish[A[l]] && dish[B[l]]) cur++;
        ans = max(ans, cur);
    }
    cout << ans << endl;
    return 0;
}