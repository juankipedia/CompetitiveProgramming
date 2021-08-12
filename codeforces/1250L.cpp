# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, ABC[3];

bool check(int mid, int i, int j){
    int abc[] = {ABC[0], ABC[1], ABC[2]};
    int mini = min(mid, abc[i]), m = mid;
    abc[i] -= mini;
    mid -= mini;
    mini = min(mid, abc[1]);
    if(mid) mid -= mini, abc[1] -= mini;
    if(abc[i] > m) return false;
    mini = min(abc[1], m - abc[i]);
    abc[i] += mini;
    abc[1] -= mini;
    abc[j] += abc[1];
    return max({m - mid, abc[i], abc[j]}) <= m;
}

int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> ABC[0] >> ABC[1] >> ABC[2];
        int mid = 0;
        for(; mid < 1e5; mid++)
            if(check(mid, 0, 2) || check(mid, 2, 0)) break;
        cout << mid << endl;
    }
    return 0;
}