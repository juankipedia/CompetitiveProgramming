# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t;
string a;
char c[2] = {'(', ')'};

int main(){
    cin >> t;
    while(t--){
        cin >> a;
        bool ans = false;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++){
                    string b = "";
                    for(int l = 0; l < a.size(); l++){
                        if(a[l] == 'A') b += c[i];
                        else if(a[l] == 'B') b+= c[j];
                        else b += c[k];
                    }
                    //cout << b << endl;
                    bool ok = true;
                    int open  = 0;
                    for(int l = 0; l < b.size(); l++){
                        if(b[l] == '(') open++;
                        else{
                            if(open) open--;
                            else{
                                ok = false;
                                break;
                            }
                        }
                    }
                    //cout << ok << " " << open << endl;
                    if(open) ok = false;
                    if(ok) ans = true;
                }
            }
        }
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}