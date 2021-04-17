# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int t, n;
string s[3];

void cnt(int i, int o[], int z[]){
    for(int j = 0; j < 2 * n; j++){
        if(s[i][j] == '1') o[i]++;
        else z[i]++;
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s[0] >> s[1] >> s[2];
        int o[3] = {0}, z[3] = {0};
        cnt(0, o, z);
        cnt(1, o, z);
        cnt(2, o, z);
        bool f = false;
        for(int i = 0; i < 2; i++){
            for(int j = i + 1; j < 3; j++){
                char lcs = 'x';
                if(o[i] >= n && o[j] >= n) lcs = '1';
                else if(z[i] >= n && z[j] >= n) lcs = '0';
                if(lcs != 'x'){
                    f = true;
                    //cout << lcs << " " <<   i  << " " << j << "-------" << endl;
                    int l = 0, k = 0, c = n;
                    while(l < 2 * n || k < 2 * n){
                        while(l < 2 * n && (s[i][l] != lcs || c == 0)) cout << s[i][l], l++;
                        while(k < 2 * n && (s[j][k] != lcs || c == 0)) cout << s[j][k], k++;
                        if(c){
                            cout << lcs;
                            c--;
                            l++;
                            k++;
                        }
                    }
                    cout << endl;
                    break;
                }
            }
            if(f) break;
        }       
    }   
    return 0;
}