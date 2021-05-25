# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, b[505][505], a[505][505], g[505][505];


int main(){
    io_boost;
    cin >> N;
    for(int i = 0; i < N; i++){
        string sa;
        cin >> sa;
        for(int j = 0; j < N; j++) a[i][j] = sa[j] - '0';
    }
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            string s = to_string(b[i][j] + 1);
            if(a[i][j] == s[s.size() - 1] - '0'){
                g[i][j] = 1;
                b[i][j]++;
                for(int k = 0; k < N; k++) b[i][k] += a[j][k];
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cout << g[i][j];
        cout << endl;
    }
    return 0;
}