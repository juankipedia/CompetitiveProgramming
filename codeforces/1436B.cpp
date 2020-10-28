#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, t;
bool prime[10000000+5];
lli m[100][100];

int main(){
    cin >> t;
    while(t--){
        cin >> N;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                m[i][j] = 0;
        if(N < 4){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++)
                    cout << 1 << " ";
                cout << endl;
            }
            continue;
        }

        for(int i = 0; i < N; i++) m[i][i] = m[i][N - i - 1] = 1;
        if(N % 2) m[0][N / 2] = m[N / 2][0] = 1;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << m[i][j] << " ";
            cout << endl;
        }

    }
    return 0;
}