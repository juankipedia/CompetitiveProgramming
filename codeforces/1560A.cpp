# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/



int main(){
    io_boost;
    int t, k;
    cin >> t;
    while(t--){
        cin >> k;
        int i = -1, j;

        for(i = 1, j = 0; j < k;){
            auto s = to_string(i);
            if(i % 3 == 0 || s[s.size() - 1] == '3');
            else j++;
            if(j >= k) break;
            i++;
        }
        cout << i << endl;

    }
    return 0;
}