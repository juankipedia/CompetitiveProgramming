# include <bits/stdc++.h>
using namespace std;

int main(){ 
    string s;
    cin >> s;
    int n = s.length(), q, l, r;
    scanf("%d", &q);
    vector<int> f[n];
    f[0] = vector<int>(26, 0);
    f[0][s[0] - 'a']++;
    for (int i = 1; i < n; ++i){
        f[i] = f[i - 1];
        f[i][s[i] - 'a']++;
    }

    while(q--){
        scanf("%d %d", &l, &r);
        if(l == r){
            cout << s[l - 1] << endl;
        }
        else if(l == 1){
            int i = 0, m = f[r - 1][0];
            for (int j = 1; j < 26; ++j){
                if(f[r - 1][j] >= m){
                    m = f[r - 1][j];
                    i = j;
                }
            }
            cout << static_cast<char>(i + 'a') << endl;
        }
        else{
            int i = 0, m = f[r - 1][0] - f[l - 2][0];
            for (int j = 1; j < 26; ++j){
                if(f[r - 1][j] - f[l - 2][j] >= m){
                    m = f[r - 1][j] - f[l - 2][j];
                    i = j;
                }
            }
            cout << static_cast<char>(i + 'a') << endl;
        }
    }
    return 0; 
}