#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;

int t, N, M, m[50][50];

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> N >> M;
        bool r[N] = {false}, c[M] = {false};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> m[i][j];
                if(m[i][j] == 1)
                    r[i] = c[j] = true;
            }
        }
        
        int looser = -1;
        bool turn = true;
        while(looser == -1){
            bool moved = false;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(m[i][j] == 0 && !r[i] && !c[j]){
                        r[i] = c[j] = true;
                        m[i][j] = 1;
                        moved = true;
                        break;
                    }
                }
                if(moved) break;
            }

            if(!moved){
                if(turn) looser = 0;
                else looser = 1;
                
            }
            turn = !turn;
        }
        if(looser == 0)
            cout << "Vivek" << endl;
        else cout << "Ashish" << endl;
    }
    return 0;
}