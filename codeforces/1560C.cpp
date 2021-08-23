
//fi + 1 = 2 * i  -  1 + fi;


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
    int t;
    lli k;
    cin >> t;
    while(t--){
        cin >> k;
        lli val = 1;
        lli r = 1, c = 1;
        while(k > val){
            r++;
            val = 2 * r  - 1 + val;
        }
        bool f = false;
        for(int i = 0; i < r; i++){
            if(val == k){f = true; break;}
            val--;
            c++;
        }

        if(f) cout << r << " " << c << endl;
        else{
            c--;
            r--;
            int R = r;
            for(int i = 0; i < R; i++){
               
                if(val == k) break;
                r--;
                val --;
            }
            cout << r << " " << c << endl;
        }
    }
    return 0;
    //000000000
}