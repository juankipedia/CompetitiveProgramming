# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int N;

int main(){
    cin >> N;
    if(N >= 1 && N <= 125) cout << 4 << endl;
    else if(N >= 126 && N <= 211) cout << 6 << endl;
    else cout << 8 << endl;
    return 0;
}