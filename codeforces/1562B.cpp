# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, k;

bool is_prime(int n){
    if (n == 1) return false;
    int i = 2;
    while(i * i <= n){
        if(n % i == 0) return false;
        i += 1;
    }
    return true;
}

int main(){
    cin >> t;
    while(t--){
        string n;
        cin >> k;
        cin >> n;
        
        bool m[10] = {false};
        string ans = "";
        for(int i = 0; i < k; i++){
            if(n[i] == '1' || n[i] == '4' ||
               n[i] == '6' || n[i] == '8' ||
               n[i] == '9'){
                ans += n[i];
                break;
            }
        }
        if(ans == ""){
            for(int i = 0; i < k; i++)
                for(int j = i + 1; j < k; j++){
                    string c = "";
                    c += n[i];
                    c += n[j];
                    if(!is_prime(stoi(c))){
                        ans = c;
                        break;
                    }
                }
        }
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    return 0;
}