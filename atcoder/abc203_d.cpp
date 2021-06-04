# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, K, m[805][805], bm[805][805], s[805][805];


int query(int a, int b, int c, int d){
    int res = s[c][d];
    if(a > 0) res -= s[a - 1][d];
    if(b > 0) res -= s[c][b - 1];
    if(a > 0 && b > 0) res += s[a - 1][b - 1];
    return res;
}

int get_sum(int mid){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(m[i][j] <= mid) bm[i][j] = 1;
            else bm[i][j] = 0;
            if(i == 0) s[i][j] = bm[i][j];
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 1; j < N; j++)
            s[j][i] = s[j - 1][i] + bm[j][i];
    for(int i = 1; i < N; i++)
        for(int j = 0; j < N; j++)
            s[j][i] += s[j][i - 1];
    int maxi = 0;
    for(int i = 0; i + K - 1 < N; i++)
        for(int j = 0; j + K - 1 < N; j++){
            //cout << query(i, j, i + K - 1, j + K - 1) << endl;
            maxi = max(query(i, j, i + K - 1, j + K - 1), maxi);
        }
    return maxi;
}

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> m[i][j];
    get_sum(0);
    int lo = 0, hi = 1e9 + 5;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        int sum = get_sum(mid);
        //cout << mid << " " << sum << endl;
        if(sum < (K * K + 1) / 2) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << endl;
    return 0;
}