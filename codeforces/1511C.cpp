# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;


int main(){
    int n, q;
    cin >> n >> q;
    int pos[55];
    for(int i = 1; i <= 50; i++) pos[i] = -1;
    for(int i = 0, ai; i < n; i++){
        cin >> ai;
        if(pos[ai] == -1) pos[ai] = i + 1;
        else pos[ai] = min(i + 1, pos[ai]);
    }
    for(int i = 0, ti; i < q; i++){
        cin >> ti;
        cout << pos[ti] << " ";
        for(int j = 1; j <= 50; j++){
            if(pos[j] == -1) continue;
            if(pos[j] < pos[ti]) pos[j]++;
        }
        pos[ti] = 1;
    }
    cout << endl;

    return 0;
}