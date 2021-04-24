# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, m[500][500], d[500];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> m[i][i];
    for(int i = 0; i < N; i++){
        int ii = i, jj = i;
        for(int j = 0; j < m[i][i]; j++){
            m[ii][jj] = m[i][i];
            if(jj > 0 && m[ii][jj - 1] == 0) jj--;
            else ii++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(m[i][j] != 0) cout << m[i][j] << " ";
            else break;
        cout << endl;
    }
    return 0;
}