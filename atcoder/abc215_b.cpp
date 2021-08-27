# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

ulli n;

int main(){
    cin >> n;
    ulli k = 0;
    while((1ULL << k) <= n) k++;
    cout << k - 1 << endl;
    return 0;
}