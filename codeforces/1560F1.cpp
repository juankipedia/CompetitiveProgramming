
//fi + 1 = 2 * i  -  1 + fi;


# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, k;
lli n;

int main(){
    io_boost;
    set<lli> two, one;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int s = 1; s <= 10; s++){
                for(int l = 0; l < (1 << s); l++){
                    string num = "";
                    for(int w = 0; w < s; w++){
                        if(l & (1 << w)) num += i + '0';
                        else num += j + '0';
                        if(i == j) one.insert(stoll(num));
                        two.insert(stoll(num));
                    }
                }
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k == 1) cout << *one.lower_bound(n) << endl;
        else cout << *two.lower_bound(n) << endl;
    }
    return 0;
}
