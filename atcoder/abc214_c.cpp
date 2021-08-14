# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int N;
lli S[200005], T[200005];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++) cin >> T[i];
    lli mini = 1e10;
    int pos = 0;
    for(int i = 0; i < N; i++)
        if(T[i] < mini){
            mini = T[i];
            pos = i;
        }
    int ans[N];
    int j = pos;
    do{
        ans[j] = T[j];
        if(T[(j + 1) % N] > (T[j] + S[j])) T[(j + 1) % N] = T[j] + S[j];
        j = (j + 1) % N;
    }while(j != pos);
    for(int i = 0; i < N; i++) cout << ans[i] << endl;

    return 0;
}