#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;


string s[9];
int t, l;
int iv[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
int jv[9] = {0, 4, 8, 1, 5, 6, 2, 3, 7};

int main() {
    io_boost;
    cin >> t;
    while(t--){
        for(int i = 0; i < 9; i++)cin >> s[i];
        l = 0;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(iv[l] == i && jv[l] == j){
                    if(s[i][j] == '1') s[i][j] = '2';
                    else s[i][j] = '1';
                    l++;
                }
                cout << s[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}