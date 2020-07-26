#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int T, N;
char M[50][50];
string I, O;

bool travel(int i, int j){
    
    while(i != j){
        if(i > j && I[i - 1] == 'Y' && O[i] == 'Y') i--;
        else if(i < j && I[i + 1] == 'Y' && O[i] == 'Y') i++;
        else break;
    }
    return i == j;
}

int main(){
    io_boost;
    cin >> T;
    for(int ti = 1; ti <= T; ti++){
        cin >> N;
        cin >> I;
        cin >> O;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j ++){
                if(i == j)
                    M[i][j] = 'Y';
                else if(travel(i, j))
                    M[i][j] = 'Y';
                else 
                    M[i][j] = 'N';
            }
        }
        cout << "Case #" << ti << ":" << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                cout << M[i][j];
            cout << endl;
        }
        
    }
    return 0;
}